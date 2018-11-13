#include "main.h"

#define MAX_BUFF 100
extern uint8_t buff_count, buff_size[MAX_BUFF], buff_char_count[MAX_BUFF];
extern int32_t *base_addr[MAX_BUFF], *head[MAX_BUFF], *tail[MAX_BUFF];

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
		{addchar, "addchar"},
		{remchar, "remchar"},
		{stat, "stat"},
		{NULL, " "}
	};

	//Welcome screen - edit later
	printf("-------------Welcome--------------\n\n");

	while(1)
	{
		uint8_t wrong_ip_flag = 1;

		printf(">>");

		//resetting input variable
		memset(input, 0, sizeof(input));

		//Scan input
		fgets(input, IP_SIZE, stdin);

		//Dissecting input
		sscanf(input, "%s %[^\t\n]s", cmd, param);

		//Checking if the cmd portion matches valid function names
		for(uint8_t i=0; func[i].fnname!=NULL; i++)
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
			printf("You have entered invalid command\nPlease type \"help\" for help\n");

		if(strcmp(cmd, "exit") == 0)
			break;
	}

	return 0;
}
