#include "help.h"

int help(char param[30])
{
	printf("\n");
	printf("--------------------------------------------This is help section------------------------------------------------\n");
	printf("----------------------------------------------------------------------------------------------------------------\n");
	printf("Command\t\t\t\tArguments\t\t\t\t\tDescription\n");
	printf("-------\t\t\t\t---------\t\t\t\t\t-----------\n");
	printf("addbuff\t\t\t<number_of_buffers> <buffer_size/s>\t\tAllocate one or multiple circular buffer/s.\n");
	printf("rembuff\t\t\t<buffer_number>\t\t\t\t\tRemove an existing buffer.\n");
	printf("addchar\t\t\t<buffer_number> <Character>\t\t\tAdd a character to existing buffer.\n");
	printf("remchar\t\t\t<buffer_number>\t\t\t\t\tRemove oldest character in a buffer.\n");
	printf("resize\t\t\t<buffer_number> <+/-> <# Memory locations>\tResize existing buffer.\n");
	printf("stat\t\t\t<none>\t\t\t\t\t\tGet current statistic on the circular buffers.\n");
	printf("exit\t\t\t<none>\t\t\t\t\t\tExit the program.\n");


	printf("\n\n**Warning!!! <rembuff> will remove the entire buffer. All values in the buffer will be lost.**\n");
	printf("----------------------------------------------------------------------------------------------------------------\n\n");
	return 0;
}
