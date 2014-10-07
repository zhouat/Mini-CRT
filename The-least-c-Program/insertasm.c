int input,output;

void test()
{
	int input=100;
	printf("%x\n",output);
	asm(
	"mov %1 ,%0"
	:"=r"(output)
	:"r"(input)
	);
	printf("%x\n",output);
}

void main()
{
	test();
}
