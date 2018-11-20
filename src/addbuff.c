#include "addbuff.h"

int addbuff(char param[30])
{
	//quantity of buffers that needs to be created
	uint8_t local_buff_count = 0;

	//lengths of each buffer stored in string
	char lengths[30];

	//separating quantity from param string
	sscanf(param, "%hhu %[^\t\n]s", &local_buff_count, lengths);

	if(local_buff_count == 0)
	{
		printf("No buffers requested.\n");
		return EXIT_FAILURE;
	}

	//array to store length of each buffer
	uint8_t buff_len[local_buff_count];

	if(!(strcmp(lengths,"")))
	{
		printf("Provided lengths are not valid.\n");
		return EXIT_FAILURE;
	}

	for(uint8_t i=0; i<local_buff_count; i++)
	{
		sscanf(lengths, "%hhu %[^\t\n]s", &buff_len[i], lengths);
		buff_size[buff_count] = buff_len[i];
		base_addr[buff_count] = (int*) malloc((buff_len[i]+200) * sizeof(int));
		head[buff_count] = base_addr[buff_count];
		tail[buff_count] = base_addr[buff_count];

		buff_count += 1;
	}

	printf("\n%hhu buffer/s have been added of size/s -", local_buff_count);
	for(int i=0; i<local_buff_count; i++)
		printf(" %hhu", buff_len[i]);
	printf(".\n\n");

	return EXIT_SUCCESS;
}
