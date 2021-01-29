#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
        dir= (char *)malloc(sizeof(pw->pw_dir)+sizeof(PMT_DIR)+1);
        strcpy(dir, pw->pw_dir);
        strcat(dir, "/");
        strcat(dir, PMT_DIR);
        create_workspace(dir);
        return dir;
}

