#include "types.h"
#include "addr.h"

extern void func_8002C50C(void);
extern u8* func_8002D27C(void);
extern void LoadImage(void*, void*);
extern void func_80013288(int);
extern u8 D_80070FE8[];
extern u8 D_8009A427;
extern u8 D_8009A1F8[];
extern u8 D_80071040;

void func_8001F378(u8* arg0) {
    u8* o;
    u8* obj;
    u8* p;
    u8 i;
    s32 one;

    func_8002C50C();
    o = func_8002D27C();
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x1F;
        *(s8*)(o + 2) = -0x40;
        *(s16*)(o + 0xA) = 0xF0;
        *(s16*)(o + 0xE) = 0x90;
    }
    o = func_8002D27C();
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x1F;
        *(s8*)(o + 2) = -0x3E;
        *(s16*)(o + 0xA) = 0xF0;
        *(s16*)(o + 0xE) = 0x50;
    }
    o = func_8002D27C();
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x1F;
        *(s8*)(o + 2) = -0x3F;
        *(s16*)(o + 0xA) = 0xF0;
        *(s16*)(o + 0xE) = 0x30;
    }
    o = func_8002D27C();
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x1F;
        *(s8*)(o + 2) = -0x3D;
        *(s16*)(o + 0xA) = 0xE8;
        *(s16*)(o + 0xE) = 0xB0;
    }
    o = func_8002D27C();
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x1F;
        *(s8*)(o + 2) = -0x3C;
        *(s16*)(o + 0xA) = 0xF8;
        *(s16*)(o + 0xE) = 0xB0;
    }
    p = D_80070FE8;
    i = 0;
    arg0[3] = 0;
    D_8009A427 = 0;
    one = 1;
    if (*p != 0) {
        obj = func_8002D27C();
        if (obj != 0) {
            obj[0] = one;
            obj[1] = 0x20;
            *(u8**)(obj + 0x50) = p;
            *(u16*)(obj + 0xA) = *p++;
            obj[0x55] = one;
        }
    } else {
        p++;
    }
    while (*p != 0xFF) {
        obj = func_8002D27C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x1F;
            obj[2] = *p++;
            obj[7] = i++;
            *(u16*)(obj + 0xE) = *p++;
            *(u16*)(obj + 0xA) = *p++;
            obj[0x55] = one;
        }
    }
    *(u16*)(arg0 + 8) = p[1];
    D_8009A1F8[3] = 0;
    D_8009A1F8[0x57] = 0;
    D_8009A1F8[0xAB] = 0;
    LoadImage(&D_80071040, D_801F3000 + D_801F3004);
    func_80013288(8);
    arg0[1] = arg0[1] + 1;
}
