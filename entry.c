//entry.c

#include "minicrt.h"

#ifndef DEBUG
#define DEBUG 0
#endif

extern int main(int argc,char*argv[]);
void exit(int);

static void crt_fatal_error(const char*msg)
{
	printf("fatal error : %s\n",msg);
	exit(1);
}

void mini_crt_entry(void)
{
	int ret;
	int argc;
	char **argv;
	char *ebp_reg=0;
	int k=0;

	asm(
	"movl %%ebp,%0 \n"
	:"=r"(ebp_reg)
	);
	
	argc=*((int*)(ebp_reg+4));
	argv=(char**)(ebp_reg+8);

	if(DEBUG){
	   printf("argc:[%d]\n", argc);
	   while(k<argc)
		printf("argv[%d]: [%s]\n", k, argv[k++]);
	}	
	if(!mini_crt_heap_init())
	{
		crt_fatal_error("heap init failed!\n");	
	}
	
	if(!mini_crt_io_init())
	{	
		crt_fatal_error("io init failed!\n");
	}
	
	ret=main(argc,argv);
	exit(ret);
}

void exit(int exitcode)
{
	asm(
	"movl %0,%%ebx \n\t"
	"movl $1,%%eax \n\t"
	"int $0x80     \n\t"
	"hlt           \n\t"
	::"m"(exitcode)
	);
}

