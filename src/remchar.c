#include "remchar.h"

int remchar(char param[30])
{
	//number of the buffer on which we have to work
	uint8_t buff_num;

	//storing buffer number
	sscanf(param, "%hhu", &buff_num);

	buff_num -= 1;

	if(buff_count == 0)
	{
		printf("Error! Buffer not allocated.\n\n");
		return 1;
	}

	if(buff_num < 0 || buff_num >= buff_count)
	{
		printf("Invalid buffer number\n\n");
		return 1;
	}

	if(buff_char_count[buff_num] == 0)
	{
		printf("Error! No value in buffer to be removed.\n\n");
		return 1;
	}

	printf("Character '%c' from buffer_%d removed.\n\n", *tail[buff_num], buff_num + 1);
	*tail[buff_num] = '\0';
	tail[buff_num] = (tail[buff_num] + 1) >= (base_addr[buff_num] + buff_size[buff_num]) ? base_addr[buff_num] : (tail[buff_num] + 1);
	buff_char_count[buff_num]--; //decrementing number of characters in the buffer

	return 0;
}
