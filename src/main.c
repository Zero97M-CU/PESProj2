#include "main.h"

typedef struct functions
{
	int (*fnptr)(char[]);
	char fnname[10];
} table;

int main()
{
	char input[IP_SIZE], cmd[CMD_SIZE], param[PARAM_SIZE];

	buff_count = 0;

	table func[] =
	{
		{help, "help"},
		{addbuff, "addbuff"},
		{rembuff, "rembuff"},
		{resize, "resize"},
		{addchar, "addchar"},
		{remchar, "remchar"},
		{stat, "stat"}
	};

	uint8_t no_of_functions = sizeof(func)/sizeof(func[0]);
	printf("\n\n\t\t\t********** Welcome to the Circular Buffer code **********\n\n");

	while(1)
	{
		uint8_t wrong_ip_flag = 1;
		printf("\n\n");
		printf(">>");

		//resetting input variable
		memset(input, 0, sizeof(input));

		//Scan input
		fgets(input, IP_SIZE, stdin);

		//Dissecting input
		sscanf(input, "%s %[^\t\n]s", cmd, param);

		if(strcmp(cmd, "exit") == 0)
			break;

		//Checking if the cmd portion matches valid function names
		for(uint8_t i=0; i<no_of_functions; i++)
		{
			if(strcmp(cmd, func[i].fnname) == 0)
			{
				//Calling the function
				(func[i].fnptr)(param);
				wrong_ip_flag = 0;
				break;
			}
		}

		if(wrong_ip_flag == 1)
			printf("Invalid Input. Type \"help\" for correct syntax.\n\n");
	}
	return EXIT_SUCCESS;
}
