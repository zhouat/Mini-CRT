#include "minicrt.h"

void print(char *buf, int len)
{
	int i=0;	
	for( ; i<len ;i++)
	{
		printf("[%d]\n",buf[i]);	 	
	}
	
}

void main(int argc, char**argv)
{
	char *str, buf[25];
	char dst[25],src[25]="origin data";
	int sc=0;
	sc = argc;
        printf("sc is :[%d]   argc:[%d]\n",sc,argc);

	if(sc==1){
	    //// test memset ////
	
	    print(buf,sizeof(buf));
 	    memset(buf,0,sizeof(buf));
	    print(buf,sizeof(buf));

	}else if(sc==2){
	    //// test strlen ////
	    printf("%d\n",strlen("hi,zat!"));		
	}else if(sc==3){
	    //// test itoa ////
	    memset(buf,0,25);
	    memset(dst,0,25);	
	    printf("%s  %s  %s\n","this is test data", itoa(0xabc,buf,16),itoa(-123,dst,10));
	}else if(sc==4){
	    ////  test strcmp ////
	    printf("zat  vs zhy  :[%d]\n",strcmp("zat","zhy"));
	    printf("zat  vs zat  :[%d]\n",strcmp("zat","zat"));
	    printf("zat1 vs zat  :[%d]\n",strcmp("zat1","zat"));
	    printf("zat  vs zat1 :[%d]\n",strcmp("zat","zat1"));	
 	}else if(sc==5){
	    //// test strcpy ////
	    memset(dst,0,25);
	    printf("orig:[%s]\n",src);
	    printf("spy :[%s]\n",strcpy(dst,src),dst);	
	}
	
}

