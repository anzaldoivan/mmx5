#include "types.h"

void clear_flash_palette(u8* a0) {
    a0[0xA1] = 0;
}
