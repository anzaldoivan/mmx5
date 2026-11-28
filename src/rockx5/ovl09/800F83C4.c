#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern s16 D_8009A202;
extern u8 D_800FB47C_ovl09[];

void func_800F83C4_ovl09(u8* arg0) {
    u8* p = g_Player;

    if (*(s8*)(p + 5) == 0x14) {
        if (*(s16*)(p + 0xA) - D_8009A202 < 0xA0) {
            func_8003D29C(0x1D, 0x40);
        } else {
            func_8003D29C(0x1D, 0);
        }
        func_80028B18(0, 0x660, 0x870, D_800FB47C_ovl09);
        func_80028B18(0, 0x6B0, 0x870, D_800FB47C_ovl09 + 8);
        func_80028B18(0, 0x700, 0x870, D_800FB47C_ovl09 + 0x10);
        func_80028B18(0, 0x750, 0x870, D_800FB47C_ovl09 + 0x18);
        *(s16*)(arg0 + 0x7C) = 0xB4;
        g_playthrough_state.u[0x24] = 0;
        *(s32*)(g_playthrough_state.u + 0x20) = 0;
        arg0[5]++;
    }
}

extern s16 D_8009A202;

void func_800F84B8_ovl09(u8* a0) {
    u8* p = g_Player;

    if (p[0x15] == 0) {
        if (*(s16*)(p + 0xA) - D_8009A202 > 0xA0) {
            return;
        }
    } else {
        if (*(s16*)(p + 0xA) - D_8009A202 < 0xA0) {
            return;
        }
    }
    func_8003D29C(0x14, 0x40);
    D_1F80004C.bytes[0x86] = 1;
    *(s16*)(a0 + 0x7C) = 3;
    a0[5]++;
}

extern s8 D_800D1C26;

void func_800F8560_ovl09(u8* arg0) {
    u8* q;

    if (--*(s16*)(arg0 + 0x7C) == 0) {
        ((s32(*)())func_8003D2C4)();
        q = D_8009A1F8.u;
        D_800D1C26 = 0;
        *(u16*)(q + 0x26) = *(u16*)(D_1F80004C.bytes + 0x80);
        *(u16*)(q + 0x24) = *(u16*)(D_1F80004C.bytes + 0x82);
        func_8002D720(arg0);
    }
}
