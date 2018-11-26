/* --------------------------------------------
 * File: Current program statistics
 * Authors: Mohit & Suman
 *
 * Gives information on the current states of circular buffers,
 * head and tail pointers, number of characters, etc
 *--------------------------------------------
*/

#include "stat.h"

int stat(char param[30])
{
	if(buff_count == 0)
	{
		printf("No stats to display.\n\n");
		return EXIT_FAILURE;
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

	/*---------Showing actual buffers----------*/
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

	/*---------PART 5----------*/
	for(int i=0;i<buff_count;i++)
	{
		 app_char_addr[i] = (int*) malloc(256 * sizeof(int));		//keep track of characters in the buffer
		 app_cnt_addr[i] = (int*) malloc(256 * sizeof(int));    //keep track of character count in the buffer
	}

	for(int i=0;i<buff_count;i++)
	{
		for(int j=0;j<buff_char_count[i];j++)
		{
			for(int k=0;k<255;k++)
			{
				//increase count of unique char which already occured earlier
				if(*(base_addr[i] + j) == *(app_char_addr[i] + k))
				{
					*(app_cnt_addr[i] + k) = *(app_cnt_addr[i] + k) + 1;
					break;
				}

				//else add that unique char
				else
				{
					*(app_char_addr[i] + no_of_uniq_char[i]) = *(base_addr[i] + j);
					*(app_cnt_addr[i] + no_of_uniq_char[i]) = 1;
					no_of_uniq_char[i] = no_of_uniq_char[i] + 1;
					break;
				}
			}
		}
	}

	for(int i=0;i<buff_count;i++)
	{
		printf("\nBuffer_%d\n",i+1);
		printf("CHARACTER\t\tCOUNT\n---------\t\t-----\n");

		for(int j=0;j<no_of_uniq_char[i];j++)
		{
			/*
			if(*(app_cnt_addr[i] + j) == 0)
			{
				continue;
			}
			*/

			//else
				printf("    %c\t\t\t  %d\n",*(app_char_addr[i] + j), *(app_cnt_addr[i] + j));
		}
	}

	int32_t* rem_ptr;
	rem_ptr = (int*) malloc(sizeof(int));
	for(int i=0;i<buff_count;i++)
	{
		app_char_addr[i] = rem_ptr;
		app_cnt_addr[i] = rem_ptr;
		no_of_uniq_char[i] = 0;
	}

	return EXIT_SUCCESS;
}
