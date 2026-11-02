#include "types.h"

extern void* D_800FBFD4_ovl01[];
extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];

void func_800EF158_ovl01(u8* arg0) {
    ((void (*)(u8*))D_800FBFD4_ovl01[((s8*)arg0)[5]])(arg0);
    if (((s8*)arg0)[5] < 7) {
        u8* p = D_8009A0A0;
        if (p[0xF7] != 0) {
            u8* q = D_8009A1F8;
            *(s16*)(q + 0x5E) += *(s16*)(q + 0xA) - *(s16*)(q + 0x16);
        } else {
            u8* q = D_8009A1F8;
            *(s32*)(q + 0x5C) += *(s32*)(arg0 + 0x14);
        }
        {
            u8* q = D_8009A1F8;
            *(s16*)(q + 0x62) = *(s16*)(q + 0xE) + *(s16*)(q + 0xE) / 2 + 8;
            if (*(s16*)(q + 0x5E) < 0xE00) {
                if (*(s16*)(q + 0x5E) >= 0x400) {
                    *(s16*)(q + 0x5E) -= 0x400;
                    q[0xA0] = 1;
                } else if (*(s16*)(q + 0x5E) < 0) {
                    *(s16*)(q + 0x5E) += 0x400;
                    q[0xA0] = 1;
                }
            } else if (*(s16*)(q + 0x5E) >= 0x1200) {
                *(s16*)(q + 0x5E) -= 0x1200;
                q[0xA0] = 1;
            }
        }
        {
            u8* q = D_8009A1F8;
            q[0xA0] = 1;
        }
    } else {
        u8* q = D_8009A1F8;
        u8* p = D_8009A0A0;
        *(s32*)(q + 0x5C) += *(s32*)(p + 0x8) - *(s32*)(p + 0x18);
    }
    {
        u8* q = D_8009A1F8;
        if (arg0[0x1D] == 0 && *(s16*)(q + 0xA) >= 0xEC0) {
            arg0[0x1D] = 1;
        }
    }
    {
        u8* q = D_8009A1F8;
        if (arg0[0x1D] == 1 && *(s16*)(q + 0xB2) == 0x200) {
            arg0[0x1D] = 2;
            q[0xF6] = 5;
            q[0xF4] = 1;
        }
    }
    {
        if (arg0[0x1D] == 2) {
            u8* q = D_8009A1F8;
            if (*(s16*)(q + 0xB2) == 0x400) {
                arg0[0x1D] = 3;
                q[0xF5] = 4;
                q[0xF4] = 1;
            }
        }
    }
    {
        u8* p = D_8009A0A0;
        if (p[0xF7] != 0) {
            u8* q = D_8009A1F8;
            *(s32*)(q + 0xB0) += (*(s32*)(q + 0x8) - *(s32*)(q + 0x14)) / 4;
        } else {
            u8* q = D_8009A1F8;
            *(s32*)(q + 0xB0) += *(s32*)(arg0 + 0x14) >> 1;
        }
    }
}
