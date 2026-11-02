#include "types.h"

extern s8 D_8009A424;

void func_800EEF14_ovl20(u8* p) {
    u8 bits;
    u8 t;
    s32 i;
    s32 n;

    if (D_8009A424 == 0) {
        if (p[0x10F] == 1) {
            bits = p[0x4C];
            i = 0;
            n = 0;
            for (; i < 8; i++) {
                if ((bits >> i) & 1) {
                    n++;
                }
            }
            if (n == 2) {
                p[0x10F] = n;
                p[1] = 0xC;
                p[2] = 0;
                return;
            }
        }
        if (p[0x10F] == 3) {
            bits = p[0x4C];
            i = 0;
            n = 0;
            for (; i < 8; i++) {
                if ((bits >> i) & 1) {
                    n++;
                }
            }
            if (n == 6) {
                p[0x10F] = 4;
                p[1] = 0xE;
                p[2] = 0;
                return;
            }
        }
        t = p[0x79];
        if (t == 1) {
            p[1] = 0xB;
        } else if (t == 8) {
            p[1] = 0x11;
            p[2] = 0;
            p[0x79] = 9;
            return;
        } else if (t == 3 && p[0x10F] != 4) {
            p[1] = 0xD;
        } else {
            switch (p[0x194]) {
            case 0xB:
                p[1] = 0xF;
                p[2] = 0;
                p[0x194] = 0xFF;
                return;
            case 0xC:
                p[1] = 0x10;
                p[2] = 0;
                p[0x194] = 0xFF;
                return;
            }
            p[1] = 3;
        }
        p[2] = 0;
    }
}
