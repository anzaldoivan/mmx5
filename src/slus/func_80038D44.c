#include "types.h"

extern void func_8003CD08(u8* obj);
extern void func_8001296C(s32);
extern s32 func_8002DF78(void);
extern void func_80016490(s32, s32, void*);
extern void func_8003CE30(u8*);
extern void func_8003CEA4(u8* obj);
extern void func_8003B33C(u8*, s32);
extern u8 D_8007476C[];
extern s32 D_80074778[][4];
extern u8 D_80074818[];
extern u8 D_800D1C4A;

void func_80038D44(u8* obj) {
    s8 kind;
    s32 hit;

    func_8003CD08(obj);
    obj[0x5C] &= 0x7F;
    func_8001296C(1);
    func_80016490(3, (func_8002DF78() & 1) ^ 1, obj);
    if (*(s8*)(obj + 5) != 0x11) {
        obj[0xA4] = 1;
        obj[0xCF] = 1;
        obj[0x84] = 0;
        obj[0x8C] = 0;
        func_8003CE30(obj);
        func_8003CEA4(obj);
        kind = *(s8*)(obj + 0x63);
        obj[0x15] = obj[0xA5];
        func_8003B33C(obj, D_8007476C[kind]);
        *(s32*)(obj + 0x20) = D_80074778[kind][0];
        *(s32*)(obj + 0x28) = D_80074778[kind][1];
        *(s32*)(obj + 0x24) = D_80074778[kind][2];
        *(s32*)(obj + 0x2C) = D_80074778[kind][3];
        hit = 0;
        if ((*(s32*)(obj + 0xFC) & 0x20000) ||
            (*(s8*)(obj + 2) != 0 && (D_800D1C4A & 0x10))) {
            hit = 1;
        }
        if (hit != 0 && ((u32)(kind - 1) < 2 || kind == 4)) {
            *(s32*)(obj + 0x28) = 0;
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x2C) = 0;
            *(s32*)(obj + 0x24) = 0;
        }
        if (obj[0x15] != 0) {
            *(s32*)(obj + 0x20) = -*(s32*)(obj + 0x20);
        }
        obj[0x61] = D_80074818[kind];
        if ((u32)(kind - 2) < 2 || kind == 5 || kind == 6 || kind == 7 ||
            kind == 8 || kind == 9) {
            obj[0x67] = 1;
        }
        obj[5] = 0x11;
        obj[6] = 0;
    }
}
