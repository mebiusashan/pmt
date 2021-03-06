
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <time.h>
#include <syslog.h>
#include <fcntl.h>
#include "pmt.h"
 
int init_daemon(void) 
{ 
	int pid; 
	int i; 
 
	//忽略终端I/O信号，STOP信号
	signal(SIGTTOU,SIG_IGN);
	signal(SIGTTIN,SIG_IGN);
	signal(SIGTSTP,SIG_IGN);
	signal(SIGHUP,SIG_IGN);
	
	pid = fork();
	if(pid > 0) {
		exit(0); //结束父进程，使得子进程成为后台进程
	}
	else if(pid < 0) { 
		return -1;
	}
 
	//建立一个新的进程组,在这个新的进程组中,子进程成为这个进程组的首进程,以使该进程脱离所有终端
	setsid();
 
	//再次新建一个子进程，退出父进程，保证该进程不是进程组长，同时让该进程无法再打开一个新的终端
	pid=fork();
	if( pid > 0) {
		exit(0);
	}
	else if( pid< 0) {
		return -1;
	}
 
	//关闭所有从父进程继承的不再需要的文件描述符
	for(i=0;i< NOFILE;close(i++));
 
	//改变工作目录，使得进程不与任何文件系统联系
	chdir("/");
 
	//将文件当时创建屏蔽字设置为0
	umask(0);
 
	//忽略SIGCHLD信号
	signal(SIGCHLD,SIG_IGN); 
	
	return 0;
}
 int num = 0;
 int add(){
     return num++;
 }
#include "ccli/ccli.h"

int main(int argc, const char **argv )
{ 
    cmd_t root = set_root_cmd ( "pmt","PMT is a process manage tool.","PMT is a process manage tool.", "Use 'pmt [command] --help' for more information about a command.", NULL );
    cmd_t start = set_sub_cmd( root, "start","PMT is a process manage tool.","start and daemonize an app", "Use 'pmt [command] --help' for more information about a command.", NULL );
    cmd_t restart = set_sub_cmd( root, "restart","PMT is a process manage tool.","restart a process", "Use 'pmt [command] --help' for more information about a command.", NULL );
    cmd_t stop = set_sub_cmd( root, "stop","PMT is a process manage tool.","stop a process", "Use 'pmt [command] --help' for more information about a command.", NULL );
    cmd_t ls = set_sub_cmd( root, "ls","list all processes","list all processes", "Use 'pmt [command] --help' for more information about a command.", NULL );
    cmd_t monit = set_sub_cmd( root, "monit","PMT is a process manage tool.","launch termcaps monitoring", "Use 'pmt [command] --help' for more information about a command.", NULL );
    cmd_t examples = set_sub_cmd( root, "examples","PMT is a process manage tool.","display pmt usage examples", "Use 'pmt [command] --help' for more information about a command.", NULL );
    cmd_t version = set_sub_cmd( root, "version","PMT is a process manage tool.","print pmt version", "Use 'pmt [command] --help' for more information about a command.", NULL );


    ccli_r ( root, argc, argv );
    //printf("num is : %d\n", add());
    //printf("num is : %d\n", add());
    int rel = set_cclid_pid(1123);
    printf("%d  :: %d -- %d ,\n", rel , get_cclid_pid(), get_cclid_status((pid_t)9953));

    int curLen = 16*1;
        int add_g =(55+1 - 55%curLen )/16;
    printf("num is : %d\n", add_g);    
    int k = kill((pid_t)9953, 0);
    printf("process is : %d\n", k);    
    printf("io: %d \n", stderr->_fileno);
    return 0;
    
	time_t now;
	init_daemon();
	syslog(LOG_USER|LOG_INFO,"TestDaemonProcess! \n");
    
    printf("dddddfwf");
	while(1) { 
		sleep(8);
		time(&now); 
		syslog(LOG_USER|LOG_INFO,"SystemTime: \t%s\t\t\n",ctime(&now));
	} 
}
