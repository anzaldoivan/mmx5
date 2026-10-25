#include "types.h"

extern void func_8002DF54(u8* a0);
extern s32 func_80016490(s32, s32, void*);

void func_800F7060_ovl28(u8* a0) {
    func_8002DF54(a0);
    if (*(s16*)(a0 + 0xE) >= 0x2FE) {
        *(s16*)(a0 + 0xE) = 0x2FE;
        func_80016490(2, 0x6E, a0);
        a0[6]++;
        if (*(s8*)(a0 + 2) != 0) {
            (*(u8**)(a0 + 0x50))[7] = 1;
        }
    }
}
