#include "types.h"
#include "mmx5/globals.h"

extern s8 D_800D1C0F;

void func_800F26C8_ovl08(u8* arg0) {
    if (D_8009A0AA >= 0xEB1) {
        D_800D1C0F = 0x40;
        func_8002D720(arg0);
    }
}
