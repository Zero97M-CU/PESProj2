/* --------------------------------------------
 * File: Resize exisiting buffers
 * Authors: Mohit & Suman
 *
 * Allows user to resize existing buffers to facilitate on-the-fly
 * change in buffer lengths
 *--------------------------------------------
*/

#include <resize.h>

int resize(char param[30])
{
	//new size is actually the size that has to be added or removed to the original size
	uint8_t new_size, buff_num;
	char c;

	sscanf(param, "%hhu %c %hhu", &buff_num, &c, &new_size);

	buff_num -= 1;

	if(buff_count == 0)
	{
		printf("Please allocate a buffer before resizing.\n");
		return EXIT_FAILURE;
	}

	if(buff_num < 0 || buff_num >= buff_count)
	{
		printf("Invalid buffer number.\n");
		return EXIT_FAILURE;
	}

	if(c != '+' && c != '-')
	{
		printf("Enter valid sign.");
		return EXIT_FAILURE;
	}

	if(c == '+')
	{
		buff_size[buff_num] = buff_size[buff_num] + new_size;
		printf("Buffer_%d has been resized to %d.\n", (buff_num + 1), buff_size[buff_num]);
		return EXIT_SUCCESS;
	}

	else if(c == '-')
	{
		//= NEEDS TO BE REMOVED. = MEANS THAT THE BUFFER NEEDS TO BE DELETED SO CAN COPY REMBUFF FOR THIS CASE.
		if(new_size >= buff_size[buff_num])
		{
			printf("Resized value is bigger than buffer size.\n");
		   return EXIT_FAILURE;
		}

		//FLAW
		else
		{
			buff_size[buff_num] = buff_size[buff_num] - new_size;
			if(buff_char_count[buff_num] > buff_size[buff_num])
			{
				buff_char_count[buff_num] = buff_char_count[buff_num] - new_size;
			}
			printf("Buffer_%d has been resized to %d", (buff_num + 1), buff_size[buff_num]);
			return EXIT_SUCCESS;
		}
	}
	return EXIT_SUCCESS;
}
