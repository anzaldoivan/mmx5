/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80051490.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32

M2C_UNK func_80016490(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017248();
M2C_UNK func_8002D6FC();
M2C_UNK func_8002D9EC(void*, M2C_UNK, M2C_UNK);
void func_80055E2C(void* arg0, void* arg1);
extern s8 D_8009A195;

#define P8(o) (*(s8*)((u8*)arg0 + (o)))
#define PU8(o) (*(u8*)((u8*)arg0 + (o)))
#define P16(o) (*(u16*)((u8*)arg0 + (o)))
#define P32(o) (*(void**)((u8*)arg0 + (o)))

void func_8005532C(void* arg0) {
    void* a1 = P32(0x50);
    s8 t;

    if (P8(4) == 0) {
        func_80055E2C(arg0, a1);
        t = P8(2);
        if (t == 0) {
            P16(0xE) = P16(0xE) - 0x6A;
        } else if (t == 1) {
            P16(0xA) = P16(0xA) - 0x58;
            P16(0xE) = P16(0xE) - 0x6A;
        } else if (t == 2) {
            PU8(0x15) = 0x40;
            P16(0xA) = P16(0xA) + 0x58;
            P16(0xE) = P16(0xE) - 0x6A;
        } else if (t == 3) {
            P16(0xE) = P16(0xE) + 8;
        }
        func_80016490(0, 0x25, 0);
    } else {
        if (P8(0x46) == 0) {
            ((void (*)())func_8002D6FC)(arg0, a1);
            return;
        }
        ((void (*)())func_80017248)(arg0, a1);
        if (P8(0x45) == 1) {
            D_8009A195 = 3;
        }
    }
    ((void (*)())func_8002D9EC)(arg0, 0x88, 0x88);
}
#undef P8
#undef PU8
#undef P16
#undef P32
