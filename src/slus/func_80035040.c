#include "types.h"

extern int VSync(int mode);
extern u8 D_80074540[];
extern u8 D_80074590[];
extern void* D_800745E0[];
extern u8 D_8009A0A0[];
extern s32 D_8009A420;
extern u8 D_800C9318;
extern u8 D_800D1C00[];

void func_80035040(void) {
    u8* p = D_8009A0A0;
    u8* q = D_800D1C00;

    *(u8**)(q + 0x38) = p;
    if (*(s8*)(p + 0xCD) != 0) {
        p[0xCC] = 5;
        p[0xCD] = 0;
        return;
    }
    if (*(s8*)(p + 0xCC) != 0) {
        if (--*(s8*)(p + 0xCC) != 0) {
            return;
        }
    }
    *(s32*)(p + 0x18) = *(s32*)(p + 0x8);
    *(s32*)(p + 0x1C) = *(s32*)(p + 0xC);
    if (D_800C9318 != 0) {
        if (*(volatile u16*)(p + 0x7C) &
            2) { // !FAKE: volatile read keeps the per-test reload
            *(u16*)(p + 0xA) -= 8;
        }
        if (*(volatile u16*)(p + 0x7C) &
            1) { // !FAKE: volatile read keeps the per-test reload
            *(u16*)(p + 0xA) += 8;
        }
        if (*(volatile u16*)(p + 0x7C) &
            4) { // !FAKE: volatile read keeps the per-test reload
            *(u16*)(p + 0xE) -= 8;
        }
        if (*(volatile u16*)(p + 0x7C) &
            8) { // !FAKE: volatile read keeps the per-test reload
            *(u16*)(p + 0xE) += 8;
        }
        return;
    }
    if (D_80074540[p[5] & 0x3F] != 0) {
        if (q[0x7B] != 0) {
            if ((*(u16*)(q + 0xC) == 2 && *(s8*)(q + 0x26) != 0) ||
                (D_8009A420 & 1)) {
                VSync(0);
            }
        } else if (*(u16*)(q + 0xC) == 2) {
            if (*(s8*)(q + 0x26) != 0) {
                if (D_8009A420 & 1) {
                    VSync(0);
                }
            }
        }
    }
    if (D_80074590[p[5] & 0x3F] != 0) {
        u8* r = D_800D1C00;

        if (*(s8*)(r + 0xC) != 0) {
            s32 t = *(s32*)(r + 0xAC) - 1;
            *(s32*)(r + 0xAC) = t;
            if (t < 0) {
                *(s32*)(r + 0xAC) = 0;
            }
        }
        {
            u8* s = D_800D1C00;

            *(s32*)(p + 0x150) += 1;
            *(s32*)(s + 0x1B4) += 1;
        }
    }
    ((void (*)(u8*))D_800745E0[*(s8*)(p + 4)])(p);
}
