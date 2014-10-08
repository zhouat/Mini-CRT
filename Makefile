all:
	gcc -c -fno-builtin -nostdlib -fno-stack-protector entry.c malloc.c stdio.c string.c printf.c

	ar -rs minicrt.a malloc.o printf.o stdio.o string.o	

test:
	gcc -c -ggdb -fno-builtin -nostdlib -nostdlib -fno-stack-protector test.c
	ld -static -e mini_crt_entry entry.o test.o minicrt.a -o test

clean:
	rm -f *.o *.a test
