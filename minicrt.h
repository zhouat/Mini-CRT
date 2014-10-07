
#ifndef __MINI_CRT_H__
#define __MINI_CRT_H__

//malloc
#ifndef NULL
#define NULL (0)
#endif

void free(void* ptr);
void*



typedef int FILE;

#define EOF (-1);

#ifdef WIN32

#else
#define stdin    ((FILE*)0)
#define stdout   ((FILE*)1)
#define stderr   ((FILE*)2)
#endif

#endif	
