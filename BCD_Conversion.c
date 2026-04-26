#include "BCD_Conversion.h"

#ifdef Better_Speed
inline static uint8_t BCD2BIN(uint8_t data) {
    if (data <= 0x99U)
        return (BDC2BIN_Lookup[data]);
    else
        return 0U;
}

inline static uint8_t BIN2BCD(uint8_t data) {
    if (data < 100U)
        return (BIN2BDC_Lookup[(data)]);
    else
        return 0U;
}

#elif defined(Better_Memory)

inline static uint8_t BCD2BIN(uint8_t data) {
    uint8_t ones = (data & 0x0FU), tens = (data >> 4U);
    if ((ones < 10U) && (tens < 10U))
        return ((BDC2BIN_tens_lookup[tens]) + (BDC2BIN_ones_lookup[ones]));
    else
        return 0U;
}

inline static uint8_t BIN2BCD(uint8_t data) {
    if (data < 100U)
        return (BIN2BDC_Lookup[(data)]);
    else
        return 0U;
}

#else
    #error "Must define either Better_Speed or Better_Memory"
#endif