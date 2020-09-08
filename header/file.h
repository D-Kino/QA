#ifdef __FILE_H__
#define __FILE_H__

void delete_file(const char *);
int existFile(const char *);
int existWinSCP();
int putFile(const char *, const char *);
int existIconv();
int iconvFile(const char *, const char *, const char *);

#endif
