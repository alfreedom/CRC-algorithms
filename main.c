#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CRC_TYPE CRC_POSIX
#include "crcfred.h"

int main(){

    crc_t crc_buffer_1, crc_buffer_2;
    char buffer_1[50] = "Alfredo Orozco";
    char buffer_2[50] = "Alfredo Orozco";

    crc_buffer_1 = crc_calculate_buffer((uint8_t*)buffer_1,strlen(buffer_1));
    crc_buffer_2 = crc_calculate_buffer((uint8_t*)buffer_2,strlen(buffer_2));
    
    printf("CRC Buffer 1: \"%s\" = 0x%X\n",buffer_1, crc_buffer_1 );
    printf("CRC Buffer 2: \"%s\" = 0x%X\n",buffer_2, crc_buffer_2 );
    printf("CRC Check = %s\n", (!(~crc_buffer_1 & crc_buffer_2) ? "OK":"ERROR"));
    return 0;
}