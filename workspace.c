#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "workspace.h"

char *dir = NULL;

void
create_workspace(char *dir)
{
    if(access(dir, F_OK)!=0){
        if(mkdir(dir, PMT_DIR_PMODE)!=0){
            printf("Failed to create folder. %s\n",dir);
            exit(1);   
        }
    }else{
            if(access(dir, R_OK|W_OK)!=0){
                printf("Directory is missing permissions. %s\n",dir);
                exit(1);   
            }
    }
}

char*
get_workspace()
{
    if(dir!=NULL){
        return dir;
    }
        uid_t uid = getuid();
        struct passwd *pw = getpwuid(uid);

        if (pw == NULL) {
                printf("Unable to get user directory\n");
                exit(1);
        }
        dir= (char *)malloc(sizeof(pw->pw_dir)+sizeof(PMT_DIR)+2);
        strcpy(dir, pw->pw_dir);
        strcat(dir, "/");
        strcat(dir, PMT_DIR);
        strcat(dir, "/");
        create_workspace(dir);
        return dir;
}

pid_t
get_cclid_pid()
{
    char *wdir = get_workspace();
    int len = strlen(wdir)+sizeof(PMT_PID_NAME);
    char *pid_file = malloc(len);
    strcpy(pid_file, wdir);
    strcat(pid_file, PMT_PID_NAME);
    if(access(pid_file, F_OK|R_OK)==0){
        FILE *fp = fopen(pid_file, "r");
        char buf[1024];
        fscanf(fp, "%s", buf);
        fclose(fp);
        free(pid_file);
        return (pid_t)atoi(buf);
    }
    free(pid_file);
    return 0;
}

int
set_cclid_pid(pid_t pid)
{
    char *wdir = get_workspace();
     int len = strlen(wdir)+sizeof(PMT_PID_NAME);
    char *pid_file = malloc(len);
    strcpy(pid_file, wdir);
    strcat(pid_file, PMT_PID_NAME);
    int fd = open(pid_file, O_WRONLY|O_CREAT, PMT_DIR_PMODE);
    if(fd == -1) {
         free(pid_file);
         return 1;
    }
    char pidstr[256];
    sprintf(pidstr, "%d", pid);
    write(fd, pidstr, strlen(pidstr));
    free(pid_file);
    close(fd);
    return 0;
}
