#include <sys/types.h>
#include <signal.h>
#include "daemon.h"

CCLID_STATUS
get_cclid_status(pid_t pid)
{
    if(0== kill(pid, 0))
    {
        return CCLID_RUN;
    }
    return CCLID_STOP;
}
