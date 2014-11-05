all:
	@make clean
	gcc -g -c -fno-builtin -nostdlib -fno-stack-protector\
		entry.c  malloc.c stdio.c string.c printf.c
	ar -rs minicrt.a malloc.o stdio.o string.o printf.o	
	gcc -g -c -ggdb -fno-builtin -nostdlib -fno-stack-protector test.c
	ld -static -e mini_crt_entry entry.o test.o minicrt.a -o test

clean:
	@rm -fr *.o *.a test *.txt
