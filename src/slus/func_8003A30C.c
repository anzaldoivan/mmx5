#include "types.h"

extern s32 func_8002DF78(void);
extern void func_8003CF74(u8*, s32);
extern void func_8003D120(u8*);
extern void func_8003F294();
extern u8 D_8007482C[];

void func_8003A30C(u8* obj) {
    s32 one;

    obj[0x84] = 1;
    obj[0x86] = 1;
    if (*(u16*)(obj + 0x80) & 0x80) {
        s32 u;
        s32 t = *(s32*)(obj + 0x108);
        obj[0x67] = 1;
        obj[0x86] = 2;
        one = 1;
        obj[0x8C] = one;
        u = *(s32*)(obj + 0x144);
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[0x8B] = 10;
        *(s32*)(obj + 0x24) = t;
        *(s32*)(obj + 0x2C) = u;
        func_8003F294(obj, 10, t);
        if (func_8002DF78() & 4) {
            func_8003CF74(
                obj, D_8007482C[(func_8002DF78() & 3) + ((s8)obj[2] << 2)]);
        }
        func_8003D120(obj);
        obj[5] = 6;
        obj[6] = 0;
    } else {
        func_8003F294(obj, 0x10);
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s32*)(obj + 0x28) = *(s32*)(obj + 0x11C);
        if (*(s32*)(obj + 0xFC) & 0x10) {
            obj[0x85] = 15;
        } else {
            obj[0x85] = 30;
        }
        obj[5] = 12;
        obj[6] = 0;
    }
}
