#ifndef WORKSPACE_H_INCLUDED
#define WORKSPACE_H_INCLUDED


#include <sys/stat.h>

#define PMT_DIR ".pmt"
#define PMT_DIR_PMODE 0664// (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH)

char*
get_workspace();

#endif // WORKSPACE_H_INCLUDED
