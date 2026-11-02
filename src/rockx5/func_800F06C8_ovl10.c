#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_8002FB58(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004D4F4(s32 a0, void* a1, u8* a2);
extern s32 func_8004FD24(u8* a0);
extern void func_80054440(u8* a0, s32 a1);
extern u8 D_8009A197;
extern u8 D_800FB694_ovl10[];
extern void* D_800FB6D4_ovl10[];

s32 func_800F06C8_ovl10(u8* obj) {
    u8 f;
    s32 st;

    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        ((void (*)(u8*))D_800FB6D4_ovl10[*(s8*)(obj + 5)])(obj);
        func_80017248(obj);
    }
    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
        func_8004FD24(obj);
        *(s32*)(obj + 0x20) = 0;
        func_8004D4F4(7, D_800FB694_ovl10, obj);
        func_80054440(obj, 0xC);
        obj[4] = 2;
        return;
    }
    if (func_8002D938(obj, 0x40, 0x40) != 0) {
        obj[4] = 3;
        return;
    }
    func_8002D9EC(obj, 0x20, 0x20);
    f = obj[0x70];
    if ((f & 0xC) == 0xC || (f & 3) == 3) {
        func_8004FD24(obj);
        *(s32*)(obj + 0x20) = 0;
        st = func_8004D4F4(7, D_800FB694_ovl10, obj);
        obj[4] = 2;
        return st;
    }
    if (!(f & 8) && *(s8*)(obj + 5) != 5) {
        obj[0x67] = 1;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0x4200;
        obj[5] = 5;
    }
    return func_8002FB58(obj);
}
