/**
 * Archivo: crc_fred.h
 * 
 *     Autor: Alfredo Orozco de la Paz
 *     e-mail: alfredoopa@gmail.com
 *     
 *  Librería para el cálculo de checksum con redundancia cíclica (CRC).
 *  
 *  Implementa varios estándares de cálculo de checksum. Es posible agregar otro algortimo fácilmente mediante 
 *  la definición de sus parámetros segun la tabla de algoritmos CRC.
 *  
 *  La licencia de esta librería es "BeerWare", es decir, que si te es de utilidad, invitale una cerveza como 
 *  agradecimiento al programador.
 *
 *                                          TABLA DE ALGORITMOS CRC
 *
 * Name                   Polynomial              Reversed?   Init-value          XOR-out                 Check
 * crc-8                   0x07                    False       0x00                0x00                0xF4
 * crc-8-darc              0x39                    True        0x00                0x00                0x15
 * crc-8-i-code            0x1D                    False       0xFD                0x00                0x7E
 * crc-8-itu               0x07                    False       0x55                0x55                0xA1
 * crc-8-maxim             0x131                   True        0x00                0x00                0xA1
 * crc-8-rohc              0x07                    True        0xFF                0x00                0xD0
 * crc-8-wcdma             0x9B                    True        0x00                0x00                0x25
 * crc-16                  0x8005                  True        0x0000              0x0000              0xBB3D
 * crc-16-buypass          0x8005                  False       0x0000              0x0000              0xFEE8
 * crc-16-dds-110          0x8005                  False       0x800D              0x0000              0x9ECF
 * crc-16-dect             0x0589                  False       0x0001              0x0001              0x007E
 * crc-16-dnp              0x3D65                  True        0xFFFF              0xFFFF              0xEA82
 * crc-16-en-13757         0x3D65                  False       0xFFFF              0xFFFF              0xC2B7
 * crc-16-genibus          0x1021                  False       0x0000              0xFFFF              0xD64E
 * crc-16-maxim            0x8005                  True        0xFFFF              0xFFFF              0x44C2
 * crc-16-mcrf4xx          0x1021                  True        0xFFFF              0x0000              0x6F91
 * crc-16-riello           0x1021                  True        0x554D              0x0000              0x63D0
 * crc-16-t10-dif          0x8BB7                  False       0x0000              0x0000              0xD0DB
 * crc-16-teledisk         0xA097                  False       0x0000              0x0000              0x0FB3
 * crc-16-usb              0x8005                  True        0x0000              0xFFFF              0xB4C8
 * x-25                    0x1021                  True        0x0000              0xFFFF              0x906E
 * xmodem                  0x1021                  False       0x0000              0x0000              0x31C3
 * modbus                  0x8005                  True        0xFFFF              0x0000              0x4B37
 * kermit [1]              0x1021                  True        0x0000              0x0000              0x2189
 * crc-ccitt-false [1]     0x1021                  False       0xFFFF              0x0000              0x29B1
 * crc-aug-ccitt [1]       0x1021                  False       0x1D0F              0x0000              0xE5CC
 * crc-24                  0x864CFB                False       0xB704CE            0x000000            0x21CF02
 * crc-24-flexray-a        0x5D6DCB                False       0xFEDCBA            0x000000            0x7979BD
 * crc-24-flexray-b        0x5D6DCB                False       0xABCDEF            0x000000            0x1F23B8
 * crc-32                  0x04C11DB7              True        0x00000000          0xFFFFFFFF          0xCBF43926
 * crc-32-bzip2            0x04C11DB7              False       0xFFFFFFFF          0x00000000          0xFC891918
 * crc-32c                 0x1EDC6F41              True        0x00000000          0xFFFFFFFF          0xE3069283
 * crc-32d                 0xA833982B              True        0x00000000          0xFFFFFFFF          0x87315576
 * crc-32-mpeg             0x04C11DB7              False       0xFFFFFFFF          0x00000000          0x0376E6E7
 * posix                   0x04C11DB7              False       0xFFFFFFFF          0xFFFFFFFF          0x765E7680
 * crc-32q                 0x814141AB              False       0x00000000          0x00000000          0x3010BF7F
 * jamcrc                  0x04C11DB7              True        0xFFFFFFFF          0x00000000          0x340BC6D9
 * xfer                    0x000000AF              False       0x00000000          0x00000000          0xBD0BE338
 * crc-64                  0x000000000000001B      True        0x0000000000000000  0x0000000000000000  0x46A5A9388A5BEFFE
 * crc-64-we               0x42F0E1EBA9EA3693      False       0x0000000000000000  0xFFFFFFFFFFFFFFFF  0x62EC59E3F1A4F00A
 * crc-64-jones            0xAD93D23594C935A9      True        0xFFFFFFFFFFFFFFFF  0x0000000000000000  0xCAA717168609F281
 *  
 * Valores sacados de la pagina http://crcmod.sourceforge.net/crcmod.predefined.html Es posible que alguno este mal.
 */

#ifndef CRCFRED_H
#define CRCFRED_H

#include <stdint.h>

/************************************************/
/********** Algoritmo CRC por default.***********/

#ifndef CRC_TYPE
#define CRC_TYPE    CRC_16_CCITT
#endif 

/************************************************/



#define TRUE    1
#define FALSE   0

// Definición de los tipos de algoritmos para el cálculo de CRC
#define CRC_8           1
#define CRC_8_MAXIM     2
#define CRC_8_WCDMA     3
#define CRC_16_CCITT_FALSE  4
#define CRC_16_CCITT    5
#define CRC_16_GENIBUS  6
#define CRC_16_MAXIM    7
#define CRC_XMODEM      8
#define CRC_MODBUS      9
#define CRC_32          10
#define CRC_32_BZIP2    11
#define CRC_POSIX       12

// Definiciones de los parámetros para algunos tipos algoritmos de checksum.
#if (CRC_TYPE == CRC_8)

typedef uint8_t crc_t;
#define POLINOMIAL      0x07
#define VALOR_INICIAL   0x00
#define VALOR_XOR       0x00
#define REVERSED        FALSE
#define CRC_MASK        0x80

#elif (CRC_TYPE == CRC_8_MAXIM )

typedef uint8_t crc_t;
#define POLINOMIAL      0x31
#define VALOR_INICIAL   0x00 
#define VALOR_XOR       0x00
#define REVERSED        TRUE
#define CRC_MASK        0x80

#elif (CRC_TYPE == CRC_8_WCDMA )

typedef uint8_t crc_t;
#define POLINOMIAL      0x9B
#define VALOR_INICIAL   0x00
#define VALOR_XOR       0x00
#define REVERSED        TRUE
#define CRC_MASK        0x80

#elif (CRC_TYPE == CRC_16_CCITT_FALSE )

typedef uint16_t crc_t;
#define POLINOMIAL      0x1021
#define VALOR_INICIAL   0xFFFF
#define VALOR_XOR       0x0000
#define REVERSED        FALSE
#define CRC_MASK        0x8000

#elif (CRC_TYPE == CRC_16_CCITT )

typedef uint16_t crc_t;
#define POLINOMIAL      0x1021
#define VALOR_INICIAL   0x1D0F
#define VALOR_XOR       0x0000
#define REVERSED        FALSE
#define CRC_MASK        0x8000

#elif (CRC_TYPE == CRC_16_GENIBUS )

typedef uint16_t crc_t;
#define POLINOMIAL      0x1021
#define VALOR_INICIAL   0xFFFF
#define VALOR_XOR       0xFFFF
#define REVERSED        FALSE
#define CRC_MASK        0x8000

#elif (CRC_TYPE == CRC_16_MAXIM )

typedef uint16_t crc_t;
#define POLINOMIAL      0x8005
#define VALOR_INICIAL   0x0000
#define VALOR_XOR       0xFFFF
#define REVERSED        TRUE
#define CRC_MASK        0x8000

#elif (CRC_TYPE == CRC_XMODEM )

typedef uint16_t crc_t;
#define POLINOMIAL      0x1021
#define VALOR_INICIAL   0x0000
#define VALOR_XOR       0x0000
#define REVERSED        FALSE
#define CRC_MASK        0x8000

#elif (CRC_TYPE == CRC_MODBUS )

typedef uint16_t crc_t;
#define POLINOMIAL      0x8005
#define VALOR_INICIAL   0xFFFF
#define VALOR_XOR       0x0000
#define REVERSED        TRUE
#define CRC_MASK        0x8000

#elif (CRC_TYPE == CRC_32 )

typedef uint32_t crc_t;
#define POLINOMIAL      0x04C11DB7
#define VALOR_INICIAL   0xFFFFFFFF
#define VALOR_XOR       0xFFFFFFFF
#define REVERSED        TRUE
#define CRC_MASK        0x80000000

#elif (CRC_TYPE == CRC_32_BZIP2 )

typedef uint32_t crc_t;
#define POLINOMIAL      0x04C11DB7
#define VALOR_INICIAL   0xFFFFFFFF
#define VALOR_XOR       0xFFFFFFFF
#define REVERSED        FALSE
#define CRC_MASK        0x80000000

#elif (CRC_TYPE == CRC_POSIX )

typedef uint32_t crc_t;
#define POLINOMIAL      0x04C11DB7
#define VALOR_INICIAL   0x00000000
#define VALOR_XOR       0xFFFFFFFF
#define REVERSED        FALSE
#define CRC_MASK        0x80000000
#else
    #error "Error en la definicion de CRC_TYPE: Tipo de CRC invalido."
#endif


crc_t crc_calculate_byte(crc_t crc, uint8_t data_byte);
crc_t crc_calculate_buffer(uint8_t* buffer, long long size);

#endif // CRCFRED_H
