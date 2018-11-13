#include "stat.h"

#define MAX_BUFF 100
uint8_t buff_count, buff_size[MAX_BUFF], buff_char_count[MAX_BUFF];
int32_t *base_addr[MAX_BUFF], *head[MAX_BUFF], *tail[MAX_BUFF];

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
		printf("%d \t\t\t\t %d \t\t\t %d \t\t\t %p \t\t\t %p\n", i+1, buff_size[i], buff_char_count[i], base_addr[i], (base_addr[i] + buff_size[i]));
	}

	for(int i=0;i<buff_count;i++)
	{
		printf("\nCircular Buffer %d contents\n", i+1);
		printf("\t+");
		for(int j=0; j<buff_size[i]; j++)
			printf("---+");
		printf("\n\t|");
		for(int j=0; j<buff_size[i]; j++)
			printf(" %c |", *(base_addr[i]+j));
		printf("\n\t+");
		for(int j=0; j<buff_size[i]; j++)
			printf("---+");
		printf("\n\n");
	}

	return 0;
}
