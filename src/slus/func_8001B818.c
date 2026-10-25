/* Adapted from mmx6 @c1c892d src/shared/rock_18/func_800EAFF0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

M2C_UNK func_800132F8(M2C_UNK);
M2C_UNK func_80016490(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8001D7E8(u8);
void func_8001B984(void);
void func_8001C904(void);
extern u8 D_8009A427;
extern u16 D_800C931C[];
extern X4_EngineObj D_800D1C00;
extern X4_Obj D_800E81D8;
extern void* D_800E81D4;

#define AB_B(p, o) (*(u8*)((u8*)(p) + (o)))

void func_8001B818(u8* arg0) {
    // !FAKE: pins self to $17; gcc 2.7.2 allocates another register without it (byte mismatch)
    register u8* self asm("$17") = arg0;
    s32 t;
    s32 f;
    u8* p;
    s32 n;

    arg0 = 0;
    if (D_800E81D8.x_pos.bytes[2] != 0) {
        D_800E81D8.x_pos.bytes[2]--;
        return;
    }
    t = func_8001D7E8((u8)D_800E81D8.unk6);
    if (t != 0) {
        // !FAKE: pins one to $4; gcc 2.7.2 allocates another register without it (byte mismatch)
        register s32 one asm("$4") = 1;
        // !FAKE: pins two to $3; gcc 2.7.2 allocates another register without it (byte mismatch)
        register s32 two asm("$3") = 2;
        if (t == one) {
            AB_B(self, 1) = 5;
            D_800E81D8.x_pos.bytes[0] = one;
        } else {
            AB_B(self, 1) = 5;
            D_800E81D8.x_pos.bytes[0] = two;
        }
        AB_B(self, 3) = one;
        do {
            D_8009A427 = 0;
        } while (0);
        f = 1;
    } else {
        f = 0;
    }
    if (f != 0) {
        return;
    }
    if (D_800C931C[2] & 0xA000) {
        func_80016490(0, 0xC, 0);
        D_800D1C00.unkA ^= 1;
    }
    if (D_800C931C[2] & 0x40) {
        func_80016490(0, 0x22, 0);
        p = D_800E81D4;
        n = 0x5F;
        do {
            *p++ = 0;
        } while (n--);
        if (D_800D1C00.unkA == 0) {
            AB_B(self, 1)++;
            func_8001C904();
            func_800132F8(8);
            return;
        }
        AB_B(self, 3) = 3;
        AB_B(self, 1)--;
        func_8001B984();
    }
}

#undef AB_B
