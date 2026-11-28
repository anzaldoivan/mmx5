#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern s16 D_8009A21E;
extern s32 func_8002A600(s32, s32, s32);

void func_800EF6E0_ovl01(u8* arg0) {
    u8* p = g_Player;
    u8* q;

    if (((s8*)p)[5] == 0x14) {
        D_8009A21E = 0x1CC0;
        arg0[5]++;
    }
    if (p[0xF7] == 0) {
        q = D_8009A1F8.u;
        if (*(s16*)(q + 0x2A) == *(s16*)(q + 0x28)) {
            if (--arg0[0x1C] == 0) {
                func_8002A600(0x30, 2, 1);
                arg0[0x1C] = 0xA0;
            }
        } else {
            *(s16*)(q + 0x34) = 0;
        }
    }
}

extern u8 D_8009A197;
extern s32 func_8002A600(s32, s32, s32);

void func_800EF790_ovl01(u8* arg0) {
    u8* p = D_8009A1F8.u;

    if (*(s16*)(p + 0xA) == *(s16*)(p + 0x26)) {
        arg0[0x18] = 0;
        arg0[5]++;
    }
    if (D_8009A197 == 0) {
        if (*(s16*)(p + 0x2A) == *(s16*)(p + 0x28)) {
            if (--arg0[0x1C] == 0) {
                func_8002A600(0x30, 2, 1);
                arg0[0x1C] = 0xA0;
            }
        } else {
            *(s16*)(p + 0x34) = 0;
        }
    }
}

extern s32 func_8002A600(s32, s32, s32);
extern u8 D_8009A197;

void func_800EF838_ovl01(u8* arg0) {
    u8* p = D_8009A1F8.u;
    s32 t;
    s32 u;
    u8* q;

    if (*(s16*)(p + 0x5E) < *(s16*)(arg0 + 0x16)) {
        t = arg0[0x18] + 1;
        arg0[0x18] = t;
        if ((s8)t >= 2) {
            p[0xA0] = 1;
            *(s16*)(p + 0x5E) += 0xE00;
            arg0[5]++;
        }
    }
    if (D_8009A197 == 0) {
        q = D_8009A1F8.u;
        if (*(s16*)(q + 0x2A) == *(s16*)(q + 0x28)) {
            u = arg0[0x1C] - 1;
            arg0[0x1C] = u;
            if ((u & 0xFF) == 0) {
                func_8002A600(0x30, 2, 1);
                arg0[0x1C] = 0xA0;
            }
        } else {
            *(s16*)(q + 0x34) = 0;
        }
    }
}

extern s16 D_8009A256;
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern u8* alloc_class3_slot(void);

void func_800EF920_ovl01(u8* arg0) {
    u8* p;
    u8 t;

    if (D_8009A256 >= 0xFD0) {
        play_sound(0, 5, 0);
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 8;
        }
        ((s32(*)())func_8003D29C)(0x1E, 0x40);
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C218();
        t = arg0[5];
        arg0[0x19] = 4;
        arg0[0x1A] = 2;
        arg0[0x1B] = 0;
        arg0[5] = t + 1;
    }
}

void func_800EF9C8_ovl01(u8* arg0) {
    u8* p = g_Player;

    *(s16*)(p + 0xE) = 0x100;
    *(s16*)(p + 0xA) = 0x2080;
    if (--arg0[0x19] == 0) {
        *(s32*)(p + 0x20) = 0x40000;
        *(s32*)(p + 0x28) = 0;
        *(s32*)(p + 0x24) = 0x4200;
        *(s32*)(p + 0x2C) = 0x699;
        arg0[5]++;
    }
}

void func_800EFA2C_ovl01(u8* p) {
    p[0x19]++;
    if ((u8)(p[0x19] % 5) == 0) {
        D_800D50DE -= 4;
        D_8009A42E -= 0x80;
        D_80093E68 -= 0x1000;
        if (D_800D50DE == 0) {
            ((s32(*)())func_8003D29C)(0x14, 0x40);
            p[5]++;
        }
    }
}

extern s8 D_8009A0A5;
extern s16 D_8009A21E;

void func_800EFAD8_ovl01(u8* arg0) {
    if (D_8009A0A5 == 0x14) {
        D_8009A21E = 0x2200;
        arg0[5]++;
    }
}

void func_800EFB10_ovl01(u8* arg0) {
    if (D_8009A1F8.h[5] == D_8009A1F8.h[0x13]) {
        ((s32(*)())func_8003D2C4)();
        arg0[4]++;
    }
}
