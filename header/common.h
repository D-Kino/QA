#ifdef __COMMON_H__
#define __COMMON_H__

char *ltrim(const char*);
char *rtrim(const char*);
char *trim(const char*);
int sjlen(const char *);
int executePowerShell (char *);
int registerEvent (char *, int, char *);
char *getsn(char *, int);
int isEmpty(char *);

#endif
