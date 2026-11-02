#include "types.h"

extern void func_80013288(s32);
extern s32 func_8002002C(s32);
extern u8* func_8002D2DC(void);
extern u8 D_8006FADB;
extern u8 D_80073040[];
extern u8 D_80073064[];
extern u8 D_80073088[];
extern u8 D_8009A420[];
extern u8 D_800D1D10;
extern u8 D_800E9300;

void func_8002B6C0(void) {
    u8* o;
    u8* p;

    o = func_8002D2DC();
    if (o != 0) {
        o[0] = 1;
        o[1] = 0;
        o[2] = 0x20;
        o[0x47] = 0;
        *(s16*)(o + 0xE) = 0x18;
    }
    o = func_8002D2DC();
    if (o != 0) {
        o[0] = 1;
        o[1] = 0;
        ((s8*)o)[2] = -1;
        *(s16*)(o + 0xA) = 0x20;
        *(u8**)(o + 0x50) = D_80073088;
    }
    if (D_8009A420[8] != 0) {
        p = D_80073040;
    } else {
        p = D_80073064;
    }
    while (*p != 0xFF) {
        o = func_8002D2DC();
        if (o != 0) {
            o[0] = 1;
            o[1] = 0;
            o[2] = 0x10;
            o[0x47] = p[0];
            *(s16*)(o + 0xE) = p[1];
            o[7] = p[2];
        }
        p += 3;
    }
    for (p = D_80073088; *p != 0xFF; p += 2) {
        o = func_8002D2DC();
        if (o != 0) {
            o[0] = 1;
            o[1] = 0;
            o[2] = p[1];
            *(s16*)(o + 0xE) = p[0] + 8;
        }
        if (p[1] == 9) {
            break;
        }
    }
    o = func_8002D2DC();
    if (o != 0) {
        o[0] = 1;
        o[1] = 0;
        ((s8*)o)[2] = -2;
    }
    if (D_8009A420[8] == 0) {
        func_8002002C(0);
        if (D_8009A420[8] == 0) {
            D_8006FADB = D_800D1D10;
        }
    }
    D_8009A420[7] = 0;
    func_80013288(8);
    D_800E9300++;
}
