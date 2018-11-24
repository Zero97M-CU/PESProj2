/* ----------------------------------------------
 * File: Remove buffers
 * Authors: Mohit & Suman
 *
 * Removes existing circular buffers from the heap.
 *------------------------------------------------
*/

#include "rembuff.h"

int rembuff(char param[30])
{
	//number of the buffer on which we have to work
	uint8_t buff_num;
	char a;

	//storing buffer number
	sscanf(param, "%hhu", &buff_num);

	buff_num -= 1;

	if(buff_count == 0)
	{
		printf("No buffer to remove\n\n");
		return EXIT_FAILURE;
	}

	if(buff_num < 0 || buff_num >= buff_count)
	{
		printf("Invalid buffer number\n\n");
		return EXIT_FAILURE;
	}

	printf("WARNING!!!\nDo you want to remove the entire buffer?.\nPress 'y' to continue, 'n' to abort.\n");
	scanf("%c",&a);

	if(a == 'y' || a == 'Y')
	{
		//Shifts the circular buffers
		for(int i=buff_num; i<buff_count-1; i++)
		{
			base_addr[i] = base_addr[i+1];
			head[i] = head[i+1];
			tail[i] = tail[i+1];
			buff_size[i] = buff_size[i+1];
			buff_char_count[i] = buff_char_count[i+1];
		}

		//Allocating new memory location and copying it to last buffer
		int32_t* rem_ptr;
		rem_ptr = (int*) malloc(sizeof(int));
		base_addr[buff_count-1] = rem_ptr;
		head[buff_count-1] = rem_ptr;
		tail[buff_count-1] = rem_ptr;
		buff_size[buff_count-1] = 0;
		buff_char_count[buff_count-1] = 0;

		//Freeing the last buffer
		free(rem_ptr);
		buff_count--;
		free(app_char[buff_num]);
		free(app_char_count[buff_num]);

		printf("Circular Buffer_%d is deleted.\n\n", buff_num + 1);

		return EXIT_SUCCESS;
	}

	else if(a == 'n' || a == 'N')
	{
		return EXIT_SUCCESS;
	}

	else
	{
		printf("Invalid input.\n");
		return EXIT_FAILURE;
	}
}
