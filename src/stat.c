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

	for(int i=0;i<buff_count;i++)
	{
		 app_char[i] = (char*) malloc(256 * sizeof(int));               //keep track of characters in the buffer
                 app_char_count[i] = (int*) malloc(256 * sizeof(int));          //keep track of character count in the buffer
	}

	for(int i=0;i<buff_count;i++)
	{
		for(int j=0;j<buff_char_count[i];j++)
		{
			for(int k=0;k<255;k++)
			{
				if(*(base_addr[i] + j) == *(app_char[i] + k))
				{
					*(app_char_count[i] + k) = *(app_char_count[i] + k ) + 1;
					break;
				}
				
				else
				{
					*(app_char[i] + app_position[i]) = *(base_addr[i] + j);
					*(app_char_count[i] + app_position[i]) = 1;
					app_position[i] = app_position[i] + 1;
					break;
				}
			}
		}
	}
	
	for(int i=0;i<buff_count;i++)
	{
		printf("\nBuffer_%d\n",i+1);
		printf("CHARACTER\t\tCOUNT\n---------\t\t-----\n");

		for(int j=0;j<app_position[i];j++)
		{
			if(*(app_char_count[i] + j) == 0)
			{
				continue;
			}

			else
				printf("%c\t\t\t%d\n",*(app_char[i] + j), *(app_char_count[i] + j));
		}
	}

	//for(int i=0;i<buff_count;i++)
	//{
	//	free(app_char[i]);
	//	free(app_char_count[i]);
	//}

	return EXIT_SUCCESS;
}
