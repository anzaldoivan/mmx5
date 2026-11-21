#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8* func_8002C938();
extern u8 D_800FA78C_ovl00[];
extern s32 D_8009A0A8;

void func_800F01AC_ovl00(u8* obj) {
    u8* p;

    D_1F80004C.bytes[0x85] = 0;
    p = func_8002C938();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = obj[1];
        p[2] = 0x10;
        *(u16*)(p + 0xA) = *(u16*)(obj + 0xA);
        *(u16*)(p + 0xE) = *(u16*)(obj + 0xE);
        *(s32*)(p + 0x10) = 0;
        *(u8**)(p + 0x80) = obj;
        *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
        *(u16*)(p + 0x42) = *(u16*)(obj + 0x42);
        *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
        D_1F80004C.bytes[0x85] = 1;
        *(u8**)(D_1F80004C.bytes + 0x80) = p;
        (*(u8**)(D_1F80004C.bytes + 0x80))[0x84] = 1;
    }
    if (((s8*)obj)[2] == 0) {
        D_1F80004C.bytes[0x91] = 1;
        *(u8**)(obj + 0x54) = D_800FA78C_ovl00;
        obj[0x15] = (*(s32*)(obj + 8) <= D_8009A0A8) << 6;
        set_animation(obj, 0xE);
    }
    obj[6]++;
}

void func_800F02D0_ovl00(u8* obj) {
    u8* scr;
    s8 t;

    scr = D_1F80004C.bytes;
    if (scr[0x85] == 1) {
        *(s16*)(scr + 0x96) = 1;
    }
    switch ((s8)obj[2]) {
    case 0:
        t = obj[0x45];
        if (t == 3) {
            D_1F80004C.bytes[0x91] = 1;
            set_animation(obj, 0);
            obj[5] = t;
            obj[6] = 0;
        }
        break;
    case 1:
        D_1F80004C.bytes[0x86] = 20;
        obj[5] = 2;
        obj[6] = 0;
        break;
    case 2:
        D_1F80004C.bytes[0x86] = 20;
        obj[5] = 2;
        obj[6] = 0;
        break;
    case 3:
        D_1F80004C.bytes[0x86] = 20;
        obj[5] = 2;
        obj[6] = 0;
        break;
    }
}
