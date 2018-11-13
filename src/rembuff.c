#include "rembuff.h"

#define MAX_BUFF 100
uint8_t buff_count, buff_size[MAX_BUFF], buff_char_count[MAX_BUFF];
int32_t *base_addr[MAX_BUFF], *head[MAX_BUFF], *tail[MAX_BUFF];

int rembuff(char param[30])
{
	//number of the buffer on which we have to work
	uint8_t buff_num;

	//storing buffer number
	sscanf(param, "%hhu", &buff_num);

	buff_num -= 1;

	if(buff_count == 0)
	{
		printf("No buffer to remove\n");
		return 1;
	}

	if(buff_num < 0 || buff_num >= buff_count)
	{
		printf("Invalid buffer number\n");
		return 1;
	}

	if(*base_addr[buff_num] == 1)
	{
		printf("This buffer has already been freed.\n");
		return 0;
	}

	free(base_addr[buff_num]);
	*base_addr[buff_num] = 1;
	printf("Circular Buffer_%d is deleted.\n", buff_num + 1);
	buff_count--;


	return 0;
}
