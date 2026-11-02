#include "types.h"

extern s32 PadInfoMode(s32, s32, s32, s32);
extern s32 PadGetState(s32);
extern void PadSetAct(s32, u8*, s32);
extern s32 PadSetActAlign(s32, u8*);
extern u8 D_8006FB18[];
extern u8 D_8006FB20[];
extern s32 D_8006FB24;
extern u16 D_800C931C[];
extern u16 D_800C9488[];
extern u8 D_800D50F0[];
extern u8 D_800D51A0[];

void func_8001255C(void) {
    u16 b;
    u16 m;
    u16 k;
    u16 old;
    s32 t;
    s32 state;
    s32 one;
    s32 mode;

    if (D_800D51A0[0] == 0xFF ||
        (t = D_800D51A0[1] & 0xF0, t != 0x40 && t != 0x70 && t != 0x50)) {
        b = 0;
    } else {
        {
            b = D_800D51A0[2] << 8;
            b = ~(b | D_800D51A0[3]);
            if (t == 0x50) {
                m = (b << 1) & 4;
                if (b & 0x80) {
                    m |= 2;
                }
                if (b & 4) {
                    m |= 0x80;
                }
                if (b & 8) {
                    m |= 0x10;
                }
                if (b & 0x10) {
                    m |= 8;
                }
                k = b & 0xFF61;
                b = k | m;
            }
            if ((b & 0xA000) == 0xA000) {
                b = D_800C931C[1];
            } else if ((b & 0x5000) == 0x5000) {
                b = D_800C931C[1];
            }
        }
    }
    old = D_800C931C[0];
    D_800C931C[0] = b;
    D_800C931C[1] = old;
    D_800C931C[2] = b & (b ^ old);

    if (D_800D50F0[0] == 0xFF ||
        (t = D_800D50F0[1] & 0xF0, t != 0x40 && t != 0x70 && t != 0x50)) {
        b = 0;
    } else {
        {
            b = D_800D50F0[2] << 8;
            b = ~(b | D_800D50F0[3]);
            if (t == 0x50) {
                m = (b << 1) & 4;
                if (b & 0x80) {
                    m |= 2;
                }
                if (b & 4) {
                    m |= 0x80;
                }
                if (b & 8) {
                    m |= 0x10;
                }
                if (b & 0x10) {
                    m |= 8;
                }
                k = b & 0xFF61;
                b = k | m;
            }
            if ((b & 0xA000) == 0xA000) {
                b = D_800C9488[1];
            } else if ((b & 0x5000) == 0x5000) {
                b = D_800C9488[1];
            }
        }
    }
    old = D_800C9488[0];
    D_800C9488[0] = b;
    D_800C9488[1] = old;
    D_800C9488[2] = b & (b ^ old);

    mode = PadInfoMode(0, 2, 0, b);
    state = PadGetState(0);
    one = 1;
    if (state == one) {
        D_8006FB24 = 0;
    }
    if (D_8006FB24 == 0) {
        PadSetAct(0, D_8006FB20, 2);
        if (state == 2) {
            D_8006FB24 = one;
        } else if (state == 6 && (mode == 4 || mode == 7) &&
                   PadSetActAlign(0, D_8006FB18) != 0) {
            D_8006FB24 = one;
        }
    }
}
