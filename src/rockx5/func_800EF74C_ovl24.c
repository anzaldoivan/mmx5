#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern u8 D_8009A420[];
extern u8 D_8009A427;
extern u16 D_800C931C[];

void func_800EF74C_ovl24(u8* arg0) {
    s32 two = 2;
    u8* p;
    u8 v;

    if (D_800C931C[2] & 0x1000) {
        func_80016490(0, 0xC, 0);
        p = D_8009A420;
        v = p[7];
        if (v == 0) {
            p[7] = two;
        } else {
            p[7] = v - 1;
        }
    } else if (D_800C931C[2] & 0x4000) {
        func_80016490(0, 0xC, 0);
        p = D_8009A420;
        v = p[7];
        if (v == two) {
            p[7] = 0;
        } else {
            p[7] = v + 1;
        }
    }
    if (D_800C931C[2] & 0x40) {
        func_80016490(0, 0x22, 0);
        switch (D_8009A427) {
        case 0:
            arg0[1] = 6;
            arg0[2] = 0;
            break;
        case 1:
            arg0[1] = 7;
            arg0[2] = 0;
            break;
        case 2:
            arg0[1] = 9;
            arg0[2] = 0;
            break;
        }
    }
}
