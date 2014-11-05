// test file

#include "minicrt.h"

int main(int argc, char* argv[])
{
	int i,len,k=0;
	FILE *fp;
	char buf[2];
	char **v=malloc(argc*sizeof(char*));
	for(i=0; i<argc; i++){
	   v[i] = malloc(strlen(argv[i])+1);
	   strcpy(v[i],argv[i]);	

	}

	fp = fopen("test.txt","w");
	for(i=0; i<argc; i++){
	   int len = strlen(v[i]);
	
	   fwrite(v[i], 1, len, fp);
	   fwrite("\n",1,1,fp);
	}

	fclose(fp);
	
	
	fp = fopen("test.txt","r");
	memset(buf, 0 ,sizeof(buf));
	len = fread(buf, 1, 1, fp);

	while(len){   //when reach eof, len=0  
	
	  buf[1]=0;
	  printf("[%d  ]  ===>[%s]\n",k++,buf);
	  memset(buf, 0 ,sizeof(buf));
	  len = fread(buf, 1, 1, fp);
	}
	
	free(v[0]);
	fclose(fp);
}
