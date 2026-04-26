#ifndef __BCD_CONVERSION_H
#define __BCD_CONVERSION_H

#include <stdint.h>

#define Better_Memory

#ifdef Better_Speed
static const uint8_t BDC2BIN_Lookup[154] = {
    0U,  1U,  2U,  3U,  4U,  5U,  6U,  7U,  8U,  9U,  0U,  0U,  0U,  0U,  0U,  0U,  10U, 11U, 12U, 13U, 14U, 15U, 16U, 17U, 18U, 19U,
    0U,  0U,  0U,  0U,  0U,  0U,  20U, 21U, 22U, 23U, 24U, 25U, 26U, 27U, 28U, 29U, 0U,  0U,  0U,  0U,  0U,  0U,  30U, 31U, 32U, 33U,
    34U, 35U, 36U, 37U, 38U, 39U, 0U,  0U,  0U,  0U,  0U,  0U,  40U, 41U, 42U, 43U, 44U, 45U, 46U, 47U, 48U, 49U, 0U,  0U,  0U,  0U,
    0U,  0U,  50U, 51U, 52U, 53U, 54U, 55U, 56U, 57U, 58U, 59U, 0U,  0U,  0U,  0U,  0U,  0U,  60U, 61U, 62U, 63U, 64U, 65U, 66U, 67U,
    68U, 69U, 0U,  0U,  0U,  0U,  0U,  0U,  70U, 71U, 72U, 73U, 74U, 75U, 76U, 77U, 78U, 79U, 0U,  0U,  0U,  0U,  0U,  0U,  80U, 81U,
    82U, 83U, 84U, 85U, 86U, 87U, 88U, 89U, 0U,  0U,  0U,  0U,  0U,  0U,  90U, 91U, 92U, 93U, 94U, 95U, 96U, 97U, 98U, 99U};

#elif defined(Better_Memory)
static const uint8_t BDC2BIN_tens_lookup[10] = {0U, 10U, 20U, 30U, 40U, 50U, 60U, 70U, 80U, 90U};
static const uint8_t BDC2BIN_ones_lookup[10] = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U};

#else
    #error "Must define either Better_Speed or Better_Memory"
#endif

static const uint8_t BIN2BDC_Lookup[100] = {
    0x00U, 0x01U, 0x02U, 0x03U, 0x04U, 0x05U, 0x06U, 0x07U, 0x08U, 0x09U, 0x10U, 0x11U, 0x12U, 0x13U, 0x14U, 0x15U, 0x16U, 0x17U, 0x18U, 0x19U,
    0x20U, 0x21U, 0x22U, 0x23U, 0x24U, 0x25U, 0x26U, 0x27U, 0x28U, 0x29U, 0x30U, 0x31U, 0x32U, 0x33U, 0x34U, 0x35U, 0x36U, 0x37U, 0x38U, 0x39U,
    0x40U, 0x41U, 0x42U, 0x43U, 0x44U, 0x45U, 0x46U, 0x47U, 0x48U, 0x49U, 0x50U, 0x51U, 0x52U, 0x53U, 0x54U, 0x55U, 0x56U, 0x57U, 0x58U, 0x59U,
    0x60U, 0x61U, 0x62U, 0x63U, 0x64U, 0x65U, 0x66U, 0x67U, 0x68U, 0x69U, 0x70U, 0x71U, 0x72U, 0x73U, 0x74U, 0x75U, 0x76U, 0x77U, 0x78U, 0x79U,
    0x80U, 0x81U, 0x82U, 0x83U, 0x84U, 0x85U, 0x86U, 0x87U, 0x88U, 0x89U, 0x90U, 0x91U, 0x92U, 0x93U, 0x94U, 0x95U, 0x96U, 0x97U, 0x98U, 0x99U};

inline static uint8_t BCD2BIN(uint8_t data);
inline static uint8_t BIN2BCD(uint8_t data);

#endif