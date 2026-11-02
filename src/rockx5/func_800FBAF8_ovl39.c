#include "types.h"

extern u32 func_8002DF78(void);
extern u8 D_8009A0A0[];

void func_800FBAF8_ovl39(u8* arg0) {
    s16 e;
    s16 x;
    u8* g;
    u8* h;
    u8* q;
    u8* r;

    g = D_8009A0A0;
    if ((*(s16*)(g + 0xE) >= 0x7E0 && *(s16*)(arg0 + 0xE) >= 0x7E0) ||
        (*(s16*)(g + 0xE) < 0x7E0 && *(s16*)(arg0 + 0xE) < 0x7E0)) {
        h = D_8009A0A0;
        if (*(s16*)(h + 0xA) > *(s16*)(arg0 + 0xA)) {
            *(s32*)(arg0 + 0x28) = -0x2800;
            *(s32*)(arg0 + 0x2C) = 0;
        } else if (*(s16*)(arg0 + 0xA) != 0x11B8) {
            *(s32*)(arg0 + 0x28) = 0x2800;
            *(s32*)(arg0 + 0x2C) = 0;
        }
        x = *(s16*)(arg0 + 0xA);
        if ((x == 0x1268 && *(s32*)(arg0 + 0x28) == -0x2800) ||
            (x == 0x11B8 && *(s32*)(arg0 + 0x28) == 0x2800)) {
            e = *(s16*)(arg0 + 0xE);
            if (e == 0x808) {
                *(s32*)(arg0 + 0x2C) = -0x2800;
            } else if (e == 0x7B8) {
                *(s32*)(arg0 + 0x2C) = 0x2800;
            } else if (q = D_8009A0A0, e < *(s16*)(q + 0xE)) {
                *(s32*)(arg0 + 0x2C) = 0x2800;
            } else {
                *(s32*)(arg0 + 0x2C) = -0x2800;
            }
            *(s32*)(arg0 + 0x28) = 0;
        }
    } else if ((u8)(func_8002DF78() % 3) == 0) {
        if (*(s16*)(arg0 + 0xA) == 0x1268) {
            *(s32*)(arg0 + 0x28) = 0x2800;
        } else {
            *(s32*)(arg0 + 0x28) = -0x2800;
        }
        *(s32*)(arg0 + 0x2C) = 0;
    } else {
        e = *(s16*)(arg0 + 0xE);
        if (e == 0x808) {
            *(s32*)(arg0 + 0x2C) = -0x2800;
        } else if (e == 0x7B8) {
            *(s32*)(arg0 + 0x2C) = 0x2800;
        } else if (r = D_8009A0A0, e < *(s16*)(r + 0xE)) {
            *(s32*)(arg0 + 0x2C) = 0x2800;
        } else {
            *(s32*)(arg0 + 0x2C) = -0x2800;
        }
        *(s32*)(arg0 + 0x28) = 0;
    }
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x24) = 0;
    *(s16*)(arg0 + 0x8C) = 0x32;
    arg0[0x8E]++;
}
