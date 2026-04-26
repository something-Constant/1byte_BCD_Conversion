# One-Byte BCD Conversion
A lightweight, high-performance C library for converting **Binary-Coded Decimal (BCD)** to binary and vice versa. This implementation is designed specifically for embedded systems (like the Raspberry Pi Pico, STM32, or CH32V307) where low-level control and minimal memory footprint are critical.
## Overview
In many real-time clock (RTC) modules like the DS3231 or legacy industrial protocols, data is stored in BCD format. This library provides optimized functions to handle these conversions using bitwise operations rather than heavy library dependencies.
 * **Zero Dependencies:** Standard C only.
 * **Embedded Friendly:** Minimal stack usage and no dynamic memory allocation.
 * **Fast:** Uses bit-shifting and masking to separate the tens and units nibbles.
 * **Adoption** Can switch between Better_Memory & Better_Speed 
## Logic
The conversion relies on the fact that a single byte in BCD stores two digits:
 * The **high nibble** (bits 4-7) represents the tens place.
 * The **low nibble** (bits 0-3) represents the ones place.
## Example Usage
### 1. BCD to Binary
Useful for reading hours, minutes, or seconds from an RTC.
```c
#include "bcd_conversion.h"
#include <stdio.h>
#include <stdint.h>

int main() {
    // Example: 0x25 in BCD represents the decimal number 25
    uint8_t bcd_val = 0;
    uint8_t binary_val = 0;
    
    binary_val = BCD2BIN(0x25);
    bcd_val = BIN2BCD(binary_val);

    // Output: BCD Conversion: 25 <=> 0x25.  \n
    printf("BCD Conversion: %d <=> %x. \n", binary_val, bcd_val);


    return 0;
}

```
### 2. Binary to BCD Useage
Useful for writing configuration or time settings back to a peripheral.
```c
#include "bcd_conversion.h"
#include <stdint.h>

void set_rtc_minute(uint8_t minute) {
    uint8_t bcd_minute = BIN2BCD(minute);
    // Now send bcd_minute over I2C to your device
    I2C_Write(RTC_ADDR, REG_MIN, bcd_minute);
}

```
## Implementation Details
The core logic uses efficient bit masking:
 * **To Binary:** ((bcd & 0xF0) >> 4) * 10 + (bcd & 0x0F)
 * **To BCD:** ((bin / 10) << 4) | (bin % 10)

