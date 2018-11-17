/*Header Files*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "help.h"
#include "addbuff.h"
#include "rembuff.h"
#include "addchar.h"
#include "remchar.h"
#include "stat.h"
#include "resize.h"

#define IP_SIZE 40
#define CMD_SIZE 10
#define PARAM_SIZE 30
#define MAX_BUFF 100 

extern uint8_t buff_count, buff_size[MAX_BUFF], buff_char_count[MAX_BUFF];
extern int32_t *base_addr[MAX_BUFF], *head[MAX_BUFF], *tail[MAX_BUFF];
