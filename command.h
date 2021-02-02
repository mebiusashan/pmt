
#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

int
cmd_root( int argc, const char **argv );

int
cmd_start( int argc, const char **argv );

int
cmd_stop( int argc, const char **argv );

int
cmd_restart( int argc, const char **argv );

int
cmd_ls( int argc, const char **argv );

int
cmd_monit( int argc, const char **argv );

int
cmd_examples( int argc, const char **argv );

int
cmd_version( int argc, const char **argv );

#endif 
