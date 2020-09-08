#############################################################
#
# QAシステムの結果ファイルをローテーションする。
#
# 引数1：ローテーション対象のパス
# 引数2：世代数
#
############################################################

#!/bin/csh -f

# エラーレベル
set INFO="INFO"
set WARN="WARNING"
set ERR="ERROR"

# 日付
set nowDate=`date "+%b %e %H:%M:%S"`
# ホスト名
set hostName=`hostname -s`
# サービス名
set serviceName="QA_SYSTEM"
# メッセージ
set message=""
# 日付 ホスト名 サービス名: [エラーレベル][code]メッセージ
set baseLogFormat="${nowDate} ${hostName} ${serviceName}: [%s][%s]%s\n"

# ログの出力先
set logPath="/var/log/messages"

if ($#argv < 1) then
    # 引数不足エラー
    set message=`printf "$baseLogFormat" "$ERR" "100" "パスを指定してください。"`
    echo "$message" |& tee -a $logPath
    exit 100
else if ($#argv < 2) then
    # 引数不足エラー
    set message=`printf "$baseLogFormat" "$ERR" "101" "世代数を指定してください。"`
    echo "$message" |& tee -a $logPath
    exit 101
endif

# ファイルパスの存在確認
if (! -e $argv[1]) then
    # ファイルパスの存在確認エラー
    set message=`printf "$baseLogFormat" "$ERR" "102" "存在しないパスです。"`
    echo "$message" |& tee -a $logPath
    exit 102
endif

ls $argv[1]/*-*-*.txt >& /dev/null
if ($? != 0) then
    # ローテーション対象ファイルが存在しないので処理を終了
    set message=`printf "$baseLogFormat" "$INFO" "0" "圧縮対象ファイルが存在しないため処理を終了しました。"`
    echo "$message" |& tee -a $logPath
    exit 0
endif

# 既にzipファイルが存在する場合は世代数+1する
set lsrZipCmd="ls -v1r $argv[1]/*${serviceName}*.zip"
$lsrZipCmd >& /dev/null
if ($? == 0) then
    $lsrZipCmd | awk -F'-' '{printf "mv %s %s-%s-%d.zip\n", $0, $1, $2, $3+1}' | sh
endif

# zip形式に圧縮をする
set nowdate=`date "+%Y%m"`
zip $argv[1]/${nowdate}-QA_SYSTEM-1.zip $argv[1]/*-*-*.txt >& /dev/null
if ($? != 0) then
    # zipコマンドエラー
    set message=`printf "$baseLogFormat" "$ERR" "103" "zipコマンドの実行に失敗しました。"`
    echo "$message" |& tee -a $logPath
    # 世代数を戻す
    set lsZipCmd="ls -v1 $argv[1]/*${serviceName}*.zip"
    $lsZipCmd >& /dev/null
    if ($? == 0) then
        $lsZipCmd | awk -F'-' '{printf "mv %s %s-%s-%d.zip\n", $0, $1, $2, $3-1}' | sh
    endif
    exit 103
endif

# 圧縮したファイルは削除する
rm -f $argv[1]/*-*-*.txt >& /dev/null

# 指定した世代数を超えるものは削除する
foreach filename (`$lsrZipCmd`)
    set num=`echo $filename | sed -r 's/^.*[0-9]{6}-QA_SYSTEM-([1-9][0-9]*).zip$/\1/'`
    expr "${num} + 1" >& /dev/null
    if ($? < 2) then
        if ($argv[2] < $num) then
            rm -f $filename >& /dev/null
        endif
    endif
end

# 処理の終了
exit 0
