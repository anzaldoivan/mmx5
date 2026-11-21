#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern s16 func_8001FF18(void*, s32);
extern u8 D_80070F8C[];
extern u8 D_8009A427;

void func_800F364C_ovl24(u8* arg0) {
    *(s16*)(arg0 + 8) = func_8001FF18(D_80070F8C, 1);
    D_8009A427 = 0;
    arg0[2]++;
}

extern void func_800211C4(void*, s32);
extern s32 func_800132F8(s8 arg);
extern s16 func_8001FF18(void*, s32);
extern u16 D_800C9320;
extern u8 D_80070F5C[];

void func_800F3694_ovl24(u8* arg0) {
    func_800211C4(&D_8009A420[7], *(s16*)(arg0 + 8));
    if (D_800C9320 & 0x40) {
        play_sound(0, 0x22, 0);
        if (D_8009A420[7] == 0) {
            func_800132F8(8);
            arg0[2] = 3;
            arg0[3] = 0;
        } else {
            func_8002C50C();
            *(s16*)(arg0 + 8) = func_8001FF18(D_80070F5C, 1);
            D_8009A420[7] = 1;
            arg0[2]++;
        }
    }
}

extern void func_800211C4(void*, s32);
extern s32 func_800132F8(s8 arg);
extern u16 D_800C9320;

void func_800F3754_ovl24(u8* arg0) {
    func_800211C4(&D_8009A420[7], *(s16*)(arg0 + 8));
    if (D_800C9320 & 0x40) {
        play_sound(0, 0x22, 0);
        if (D_8009A420[7] == 0) {
            func_800132F8(8);
            arg0[2] = 3;
            arg0[3] = 1;
        } else {
            func_8002C50C();
            arg0[2] = 0;
        }
    }
}

extern s8 D_8009A424;
void func_8001E6AC(void);
void func_80012EAC(void);

void func_800F37EC_ovl24(u8* a0) {
    s32 i;
    u8* p;
    u8 v;

    if (D_8009A424 == 0) {
        if (((s8*)a0)[3] == 0) {
            v = a0[0x194];
            if (v == 0xFF) {
                a0[0] = 3;
            } else {
                a0[0] = 0x13;
                a0[0x1D] = v;
            }
            a0[1] = 0;
            a0[2] = 0;
            a0[3] = 0;
        } else {
            func_8001E6AC();
            func_80012EAC();
        }
        i = 15;
        p = a0 + 0x35;
        for (; i >= 0; i--) {
            *p-- = 0;
        }
    }
}
