/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80048380.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32

M2C_UNK func_8002C338(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002DED4();
extern s8 D_800D1C1E;
extern u16 D_800E9568[];

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_8004E08C(void* arg0) {
    s32 a;
    register s32 b asm("$3"); // !FAKE: depin breaks match (64/70)

    if (F16(arg0, 0x56) != 0) {
        F16(arg0, 0x56)--;
        return;
    }
    if (--F16(arg0, 0x54) == 0) {
        if (F8(arg0, 6) == 0) {
            if (F8(arg0, 2) != 0) {
                a = -0x4000;
                b = 0x8000;
            } else {
                a = 0x4000;
                b = -0x8000;
            }
            do {
                F32(arg0, 0x20) = a;
                F32(arg0, 0x24) = b;
            } while (0);
            F8(arg0, 6) = 1;
            F16(arg0, 0x54) = 8;
            F16(arg0, 0x56) = 0x1E;
            return;
        }
        F8(arg0, 5) = 2;
        F8(arg0, 6) = 0;
        F16(arg0, 0x42) = 0x7801;
        if (F8(arg0, 2) != 0) {
            F32(arg0, 0x20) = 0xFFF00000;
            func_8002C338(0x10, (s32*)D_800E9568, 1);
        } else {
            F32(arg0, 0x20) = 0x100000;
        }
        F32(arg0, 0x24) = 0;
        F16(arg0, 0xA) = 0xA0;
        F16(arg0, 0xE) = 0x78;
        D_800D1C1E = 1;
        return;
    }
    func_8002DED4(arg0);
}
