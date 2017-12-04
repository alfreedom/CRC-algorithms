#ifndef CHECKSUM_H
#define CHECKSUM_H

#include <stdint.h>

uint8_t Checksum8(uint8_t* buffer, int size);
uint16_t Checksum16(uint8_t* buffer, int size);
uint32_t Checksum32(uint8_t* buffer, int size);
uint8_t ChecksumBSD8(uint8_t* buffer, int size);
uint16_t ChecksumBSD16(uint8_t* buffer, int size);
uint32_t ChecksumBSD32(uint8_t* buffer, int size);

uint8_t Checksum8(uint8_t* buffer, int size)
{
    uint8_t checksum=0;

    if(!buffer)
        return 0;

    while(size--)
        checksum += *buffer++;

    return checksum;

}

uint16_t Checksum16(uint8_t* buffer, int size)
{
    uint16_t checksum=0;

    if(!buffer)
        return 0;

    while(size--)
        checksum += *buffer++;

    return checksum;
}

uint32_t Checksum32(uint8_t* buffer, int size)
{
    uint32_t checksum=0;

    if(!buffer)
        return 0;

    while(size--)
        checksum += *buffer++;

    return checksum;
}



uint8_t ChecksumBSD8(uint8_t* buffer, int size)
{
    uint8_t checksum=0;

    if(!buffer)
        return 0;

    while(size--)
    {
        checksum =  (checksum >> 1) + ((checksum & 0x01)<<7);
        checksum += *buffer++;
    }

    return checksum;
}

uint16_t ChecksumBSD16(uint8_t* buffer, int size)
{
    uint16_t checksum=0;

    if(!buffer)
        return 0;

    while(size--)
    {
        checksum =  (checksum >> 1) + ((checksum & 0x0001)<<15);
        checksum += *buffer++;
    }

    return checksum;
}

uint32_t ChecksumBSD32(uint8_t* buffer, int size)
{
    uint32_t checksum=0;

    if(!buffer)
        return 0;

    while(size--)
    {
        checksum =  (checksum >> 1) + ((checksum & 0x00000001)<<31);
        checksum += *buffer++;
    }

    return checksum;
}
#endif // CHECKSUM_H
