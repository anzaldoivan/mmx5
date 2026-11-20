#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8* func_8004FF94(s32 arg0, s16 x, s16 y, s32 arg3);
extern u8 D_800D1C24;
extern s16 D_800FE4E4_ovl06[][2];
extern u8 D_800FE5EC_ovl06[];

void func_800F3DF4_ovl06(u8* arg0) {
    s32 flag;
    s16 x;

    arg0[0x8D] = 1;
    *(s32*)(arg0 + 0x68) = 0;
    *(s32*)(arg0 + 0x50) = 0;
    *(s32*)(arg0 + 0x54) = 0;
    switch (((s8*)arg0)[6]) {
    case 0:
        arg0[6]++;
        D_800D1C24 = 0;
        *(s32*)(arg0 + 0x50) = 0;
        *(s32*)(arg0 + 0x54) = 0;
        arg0[0x89] = 0xB4;
        set_animation(arg0, 7);
    case 1:
        if (arg0[0x89] == 0) {
            func_8004D4F4(6, D_800FE5EC_ovl06, arg0);
            ((s32(*)())func_8004FD90)(arg0, 1, 0x10, 0x10);
            arg0[4] = 2;
            *(u16*)(arg0 + 0x7C) = 0x78;
            arg0[3] = 0;
        } else {
            arg0[0x89]--;
            if (!(arg0[0x89] & 3)) {
                *(u16*)(arg0 + 0x42) |= 0x8000;
            } else {
                *(u16*)(arg0 + 0x42) &= 0x7FFF;
            }
        }
        break;
    }
    if ((u8)(((u32(*)())random_byte)() % 7) == 0) {
        flag = (D_8009A420_as_s32 ^ 1) & 1;
        x = *(s16*)(arg0 + 0xA) +
            D_800FE4E4_ovl06[((u32(*)())random_byte)() & 7][1];
        func_8004FF94(0, x,
                      *(s16*)(arg0 + 0xE) +
                          D_800FE4E4_ovl06[((u32(*)())random_byte)() & 7][1],
                      flag)[0x16] = 5;
    }
}
