/**
 * Archivo: crc_fred.h
 * 
 *     Autor: Alfredo Orozco de la Paz
 *     e-mail: alfredoopa@gmail.com
 *     
 * 
 *  Librería para el cálculo de checksum con redundancia cíclica (CRC).
 *  
 *  Implementa varios estándares de cálculo de checksum. Es posible 
 *  agregar otro estandar fácilmente mediante la definición de sus
 *  parámetros.
 *  
 *  La licencia de esta librería es BeerWare, es decir, que si te es de
 *  utilidad, invitale una cerveza como agradecimiento al programador.
 */

#include "crcfred.h"

static crc_t crc_reverse_data(crc_t data){   
   uint8_t i;
   crc_t reversed=0;

   for(i = 0; i < 8*sizeof(crc_t); ++i) {

        reversed >>= 1;

        if(data & CRC_MASK)
            reversed |= CRC_MASK;

        data <<= 1;
   }

   return reversed;

}

crc_t crc_calculate_byte(crc_t crc, uint8_t data_byte){

    uint8_t i;

    // Si se refleja el dato...
    #if (REVERSED == TRUE)
        data_byte = crc_reverse_data(data_byte);
    #endif
  
    // Se hace una XOR del dato con el valor del CRC
    crc ^= ((crc_t)data_byte) << ((8*sizeof(crc_t))-8);

    for (i = 0; i < 8; ++i)
    {
        if(crc & CRC_MASK)
            crc = (crc << 1) ^ POLINOMIAL;
        else
            crc <<= 1;
    }

    return crc;
}

crc_t crc_calculate_buffer(uint8_t* buffer, long long size){
    
    crc_t crc = VALOR_INICIAL;

    while(size--)
        crc = crc_calculate_byte(crc, *buffer++);

    #if (REVERSED == TRUE)
        crc = VALOR_XOR ^ crc_reverse_data(crc);
    #else
        crc ^= VALOR_XOR;
    #endif

    return crc;

}
