
#ifndef DAEMON_H_INCLUDED
#define DAEMON_H_INCLUDED

#include <sys/types.h>

#define CCLID_RUN 0
#define CCLID_STOP -1

typedef  int CCLID_STATUS;

CCLID_STATUS
get_cclid_status(pid_t pid);

#endif 
