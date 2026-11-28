#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

void func_800EFC34_ovl04(u8* arg0) {
    u8* p = g_Player;

    if ((s8)p[5] == 0x14) {
        u8* q = D_8009A1F8.u;
        u16 v = *(u16*)(q + 0xA);
        *(s16*)(q + 0x26) = v;
        *(s16*)(q + 0x1E) = v;
        arg0[6]++;
    } else if (*(s16*)(p + 0xA) >= 0xBD0) {
        func_8003D29C(0x14, 0x40);
    }
}

extern u8* func_8002C938();
extern s8 D_800D1C26;

void func_800EFCAC_ovl04(u8* arg0) {
    u8* p = D_8009A1F8.u;
    u8* q;

    if (*(s16*)(p + 0xA) >= 0xB40) {
        *(s16*)(p + 0xA) = 0xB40;
        *(s16*)(p + 0x26) = 0xB40;
        *(s16*)(p + 0x1E) = 0xB40;
        q = func_8002C938();
        if (q != 0) {
            q[0] = 1;
            q[1] = 0x1E;
            q[2] = 9;
        }
        D_800D1C26 = 0;
        arg0[6]++;
    } else {
        *(s16*)(p + 0xA) += 2;
        *(s16*)(p + 0x1E) += 2;
        *(s16*)(p + 0x26) += 2;
    }
}

#include "shared/func_800EFD54_ovl04.c"

extern s8 D_800D1C26;
extern s32 D_800E92F8;

void func_800EFD94_ovl04(u8* arg0) {
    u8* p;

    if (D_800D1C26 & 4) {
        D_800E92F8 = 1;
        p = D_8009A1F8.u;
        *(s16*)(p + 0x24) = 0xC80;
        ((s32(*)())func_8003D2C4)();
        arg0[6]++;
        *(s8*)(p + 0xA6) = -1;
        *(s16*)(p + 0x5E) = 0x370;
        *(s16*)(p + 0x62) = 0x100;
        p[0xA0] = 1;
        arg0[0x1C] = 0;
    }
}

extern s16 D_8009A21E;

void func_800EFE20_ovl04(u8* arg0) {
    if (D_8009A0AA >= 0xCBD) {
        func_8003D29C(0x14, 0x40);
        D_8009A21E = 0xC80;
        arg0[6]++;
    }
}

extern s8 D_8009A0A5;
extern s16 D_8009A202;

void func_800EFE78_ovl04(u8* a0) {
    if (D_8009A0A5 == 20 && D_8009A202 == 0xC80) {
        play_sound(5, 10, 0);
        a0[6]++;
    }
}

extern s8* D_80102FD8_ovl04;
extern s8 D_800D1C1D;
extern void func_8003B65C(void*);

void func_800EFED8_ovl04(u8* a0) {
    u8* p;

    if (*D_80102FD8_ovl04 == 0) {
        D_800D1C1D = 4;
        func_8003B65C(g_Player);
        p = D_8009A1F8.u;
        *(s16*)(p + 0x2A) = 0x2D0;
        *(s16*)(p + 0x22) = 0x2D0;
        a0[6] = 0;
        a0[5]++;
    }
}
