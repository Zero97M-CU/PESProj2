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
		printf("Enter valid sign.\n");
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
		if(new_size >= buff_size[buff_num])
		{
			printf("Resized value is bigger than buffer size.\n");
			printf("Use rembuff to remove the entire buffer.\n");
		  return EXIT_FAILURE;
		}

		//FLAW
		else
		{
			buff_size[buff_num] = buff_size[buff_num] - new_size;
			buff_char_count[buff_num] = 0;
			for(int i=0;i<buff_size[buff_num];i++)
			{
				if(*(base_addr[buff_num] + i) == '\0')
					continue;

				else
					buff_char_count[buff_num] += 1;
			}
			//bringing head and tail pointers to base address if any of them are floating outside new buffer size
			if(head[buff_num] > (base_addr[buff_num] + buff_size[buff_num] - 1) || tail[buff_num] > (base_addr[buff_num] + buff_size[buff_num] - 1))
			{
				printf("Head and Tail pointers are reset to base address.\n");
				head[buff_num] = base_addr[buff_num];
				tail[buff_num] = base_addr[buff_num];
			}
			printf("Buffer_%d has been resized to %d.\n", (buff_num + 1), buff_size[buff_num]);
			return EXIT_SUCCESS;
		}
	}
	return EXIT_SUCCESS;
}
