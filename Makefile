all:
	gcc -c -fno-builtin -nostdlib -fno-stack-protector entry.c malloc.c stdio.c string.c print.c

	ar -rs minicrt.a malloc.o print.o stdio.o string.o	

clean:
	rm  *.o
