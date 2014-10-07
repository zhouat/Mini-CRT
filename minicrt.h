typedef int FILE;

#define EOF (-1);

#ifdef WIN32

#else
#define stdin    ((FILE*)0)
#define stdout   ((FILE*)1)
#define stderr   ((FILE*)2)
#endif
	
