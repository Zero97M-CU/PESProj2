/*Header Files*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF 100

uint8_t buff_count, buff_size[MAX_BUFF], buff_char_count[MAX_BUFF], no_of_uniq_char[MAX_BUFF];
int32_t *base_addr[MAX_BUFF], *head[MAX_BUFF], *tail[MAX_BUFF], *app_char_addr[MAX_BUFF], *app_cnt_addr[MAX_BUFF];

/*Function prototype declaration*/
int stat(char[]);
