/* --------------------------------------------
 * File: Add Characters
 * Authors: Mohit & Suman
 *
 * Adds characters to the existing circular buffers. 
 * --------------------------------------------
*/

#include "addchar.h"

int addchar(char param[30])
{
	//number of the buffer on which we have to work
	uint8_t buff_num;
	char c;			//character that needs to be stored
	uint8_t char_found_flag = 0;

	//separating buffer number and character
	sscanf(param, "%hhu %c", &buff_num, &c);

	buff_num -= 1;

	if(buff_count == 0)
	{
		printf("Please allocate a buffer before entering a character.\n\n");
		return EXIT_FAILURE;
	}

	if(buff_num < 0 || buff_num >= buff_count)
	{
		printf("Invalid buffer number.\n\n");
		return EXIT_FAILURE;
	}

	if(buff_char_count[buff_num] >= buff_size[buff_num])
	{
		printf("Buffer full. Values will be overwritten.\n");
		printf("Value thrown out: %c\n", *tail[buff_num]);
		tail[buff_num] = (tail[buff_num] + 1) >= (base_addr[buff_num] + buff_size[buff_num]) ? base_addr[buff_num] : (tail[buff_num] + 1);
	}

	*head[buff_num] = c;
	head[buff_num] = (head[buff_num] + 1) >= (base_addr[buff_num] + buff_size[buff_num]) ? base_addr[buff_num] : (head[buff_num] + 1);
	buff_char_count[buff_num] = (buff_char_count[buff_num] >= buff_size[buff_num]) ? buff_char_count[buff_num] : (buff_char_count[buff_num] + 1);

	for(int i=0;i<256;i++)
	{
		if(*(app_char[buff_num]+i) == c)
		{
			*(app_char_count[buff_num] + i) = *(app_char_count[buff_num] + i) + 1;
			char_found_flag = 1;
		}
	}

	if(char_found_flag == 0)
	{
		*(app_char[buff_num] + app_position[buff_num]) = c;		//app_position helps keep track of the number of elements in the app_char array if each buffer
	        *(app_char_count[buff_num] + app_position[buff_num]) = 1;	
	}


	printf("Character '%c' has been added to buffer_%d.\n\n", c, buff_num+1);

	return EXIT_SUCCESS;
}
