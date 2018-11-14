#include "stat.h"

int stat(char param[30])
{
	if(buff_count == 0)
	{
		printf("No stats to display.\n\n");
		return 1;
	}

	printf("\n");
	printf("Current Stats\n-------------\n\n");
	printf("Number of Circular Buffers:\t%d\n\n", buff_count);
	printf("Buffer #\t\t Buffer Size\t\t No. of Char in Buffer\t\tBuffer Start Add \t\t Buffer End Add\n");
	printf("--------\t\t -----------\t\t ---------------------\t\t---------------- \t\t --------------\n");
	for(int i=0;i<buff_count;i++)
	{
		printf("%d \t\t\t\t %d \t\t\t %d \t\t\t %p \t\t %p\n", i+1, buff_size[i], buff_char_count[i], base_addr[i], (base_addr[i] + buff_size[i]));
	}

	for(int i=0;i<buff_count;i++)
	{
		printf("\nCircular Buffer %d contents\n", i+1);

		//points head
		printf("\t ");
		for(int j=0; j<head[i]-base_addr[i]; j++)
			printf("    ");
		printf(" H\n");

		printf("\t ");
		for(int j=0; j<head[i]-base_addr[i]; j++)
			printf("    ");
		printf(" |\n");

		//shows actually buffer
		printf("\t+");
		for(int j=0; j<buff_size[i]; j++)
			printf("---+");
		printf("\n\t|");
		for(int j=0; j<buff_size[i]; j++)
		{
			if(*(base_addr[i]+j) == '\0')
				printf("   |");
			else
				printf(" %c |", *(base_addr[i]+j));
		}
		printf("\n\t+");
		for(int j=0; j<buff_size[i]; j++)
			printf("---+");
		printf("\n");

		//points tail
		printf("\t ");
		for(int j=0; j<tail[i]-base_addr[i]; j++)
			printf("    ");
		printf(" |\n");

		printf("\t ");
		for(int j=0; j<tail[i]-base_addr[i]; j++)
			printf("    ");
		printf(" T\n\n");
	}

	return 0;
}
