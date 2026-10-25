#include "types.h"

extern void func_8002D89C(u8*);
extern u8 D_8009A427;
extern u8 D_80070C54;

void func_8004E848(u8* a0) {
    if (*(s16*)(a0 + 0xE) != 0x18) {
        if (*(s8*)(a0 + 7) == D_8009A427) {
            *(s16*)(a0 + 0x42) = 0x7803;
        } else if (*(s8*)(a0 + 2) == 0x1C && D_80070C54 == 0xFF) {
            *(s16*)(a0 + 0x42) = 0x7804;
        } else {
            *(s16*)(a0 + 0x42) = 0x7800;
        }
    }
    func_8002D89C(a0);
}
