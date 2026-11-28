#include "types.h"
#include "mmx5/globals.h"

extern void func_800FA004_ovl44(u8* arg0);
extern signed char D_8009A424;
extern u8 D_800D1F3C;

void func_800FA180_ovl44(u8* arg0) {
    s32 i;
    u8* p;
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    if (D_800D1F3C == 0 && D_8009A424 == 0) {
        func_8001E668();
        D_8009A1F8.u[3] = 0;
        D_8009A1F8.u[0x57] = 0;
        D_8009A1F8.u[0xAB] = 0;
        func_8002C50C();
        i = 15;
        p = arg0 + 0x35;
        do {
            *p-- = 0;
        } while (--i >= 0);
        func_800FA004_ovl44(arg0);
        if (arg0[0xCB] & 0x80) {
            a = 5;
            b = 0xB;
            c = 0xFF;
            arg0[0x194] = a;
            arg0[0x195] = b;
            arg0[0x196] = c;
            arg0[0x1D] = a;
        } else {
            if (*(s32*)(arg0 + 0xAC) <= 0) {
                a = 6;
                b = 0xF;
                c = 0xFF;
                arg0[0x194] = a;
                arg0[0x195] = b;
                arg0[0x196] = c;
                arg0[0x1D] = a;
            } else {
                a = 6;
                d = 0xFF;
                arg0[0x195] = d;
                arg0[0x194] = a;
                arg0[0x1D] = a;
                d = 3;
                arg0[0x79] = d;
            }
        }
        arg0[0] = 0x13;
        arg0[1] = 0;
        arg0[2] = 0;
        arg0[3] = 0;
    }
}
