
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "checksum.h"


uint8_t *buffer;

int main(int argc, char *argv[])
{

    uint8_t chks8;
    uint16_t chks16;
    uint32_t chks32;
    FILE* file_in;
    int file_size;

    if(argc>1)
    {
        file_in = fopen(argv[1],"rb");

        if (file_in)
        {
            fseek(file_in, 0L, SEEK_END);
            file_size = ftell(file_in);
            fseek(file_in, 0L, SEEK_SET);
            buffer = (uint8_t*) malloc(file_size*sizeof(uint8_t));
            fread(buffer,sizeof(uint8_t),file_size,file_in);
            printf("Tamaño del archivo: %d Bytes - %d KBytes\n", file_size, file_size/1024);
            chks8=Checksum8(buffer,file_size);
            chks16=Checksum16(buffer,file_size);
            chks32=Checksum32(buffer,file_size);
            printf("Checksum 8  bits:    [%d] = [0x%02X]    --    [%d] = [0x%02X]\n",chks8,chks8, -chks8, (uint8_t)-chks8);
            printf("Checksum 16 bits:  [%zu] = [0x%04X]  --  [%zd] = [0x%04X]\n",chks16, chks16,-chks16,(uint16_t)-chks16);
            printf("Checksum 32 bits: [%zu] = [0x%08X] -- [%zd] = [0x%08X]\n",chks32, chks32, -chks32,(uint16_t)-chks32);
            chks8=ChecksumBSD8(buffer,file_size);
            chks16=ChecksumBSD16(buffer,file_size);
            chks32=ChecksumBSD32(buffer,file_size);
            printf("\nCheckSum BSD:\n");
            printf("Checksum 8  bits:    [%d] = [0x%02X]    --    [%d] = [0x%02X]\n",chks8,chks8, -chks8, (uint8_t)-chks8);
            printf("Checksum 16 bits:  [%zu] = [0x%04X]  --  [%zd] = [0x%04X]\n",chks16, chks16,-chks16,(uint16_t)-chks16);
            printf("Checksum 32 bits: [%zu] = [0x%08X] -- [%zd] = [0x%08X]\n",chks32, chks32, -chks32,(uint16_t)-chks32);
        }
        else
            printf("Error, no se pudo encontrar el archivo %s\n",argv[1]);
    }
    else
    {
        printf("No se especifico el archivo de entrada.\n");
        return 0;
    }

    
    return 0;
}