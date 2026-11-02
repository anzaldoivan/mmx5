#include "types.h"

extern void func_80028B18(s32, s32, s32, void*);
extern void func_80017768(void);
extern u8 D_800D1C00[];
extern s16 D_8009A0AE;
extern u8 D_8009A1F8[];
extern u8 D_8009A0A0[];
extern s16 D_8009A0AA;
extern s16 D_8009A206;
extern u8 D_800FAA78_ovl10[];

void func_800EECDC_ovl10(u8* arg0) {
    u8* p;
    u8* s;

    u8* o;
    s16 y;

    s = D_800D1C00;
    switch ((s8)s[0x1D]) {
    case 1:
    case 2:
        if (D_8009A0AE < 0x301) {
            u8* q = D_8009A1F8;
            *(s16*)(q + 0xE8) = 0x320;
            q[0xF4] = 1;
        } else {
            u8* q = D_8009A1F8;
            *(s16*)(q + 0xE8) = 0x4B0;
            q[0xF4] = 1;
        }
        break;
    case 3:
        o = D_8009A0A0;
        if (*(s16*)(o + 0xE) > 0x300) {
            if (*(s16*)(o + 0xA) > 0xF30) {
                u8* q = D_8009A1F8;
                *(s16*)(q + 0xE8) = 0x76C;
                q[0xF4] = 1;
            } else {
                u8* q = D_8009A1F8;
                *(s16*)(q + 0xE8) = 0x4B0;
                q[0xF4] = 1;
            }
        } else {
            u8* q = D_8009A1F8;
            *(s16*)(q + 0xE8) = 0x320;
            q[0xF4] = 1;
        }
        break;
    case 4:
    case 5:
        if (D_8009A0AA > 0xF30) {
            u8* q = D_8009A1F8;
            *(s16*)(q + 0xE8) = 0x76C;
            q[0xF4] = 1;
        } else {
            u8* q = D_8009A1F8;
            *(s16*)(q + 0xE8) = 0x4B0;
            q[0xF4] = 1;
        }
        break;
    }
    p = D_800D1C00;
    if (((s8*)arg0)[4] == 0 && ((s8*)p)[0x2F] == 0) {
        o = D_8009A0A0;
        if ((u16)(*(u16*)(o + 0xA) - 0x1040) < 0x190) {
            y = *(s16*)(o + 0xE);
            if (y >= 0x3E0) {
                if (y < 0x480) {
                    if (D_8009A206 == 0x3C0) {
                        func_80028B18(0, 0x10A0, 0x3B0, D_800FAA78_ovl10);
                        arg0[4] = 1;
                        func_80017768();
                        p[0x2F] = 1;
                    }
                }
            }
        }
    }
}
