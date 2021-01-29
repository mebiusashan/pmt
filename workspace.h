#ifndef WORKSPACE_H_INCLUDED
#define WORKSPACE_H_INCLUDED


#include <sys/stat.h>

#define PMT_DIR ".pmt"
#define PMT_PID_NAME "pmt.pid"
#define PMT_DIR_PMODE 0664// (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH)

char*
get_workspace();

pid_t
get_cclid_pid();

#endif // WORKSPACE_H_INCLUDED
