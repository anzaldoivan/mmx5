#include "types.h"

extern u8* func_8002D53C(void);
extern s32 func_8002CE20(s32, s32);
extern s32 func_8004FD24(u8* a0);
extern void func_8002C218(void);
extern void func_80017D88(void);
extern void func_8001296C(s32);
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern u8 D_800D1C43;

void func_8005731C(u8* obj) {
    u8* p;
    u16 t;

    p = func_8002D53C();
    if (p != 0) {
        p[0] = 1;
        p[1] = 4;
        *(u16*)(p + 8) = *(u16*)(obj + 0x1C);
        *(u16*)(p + 0xA) = *(u16*)(obj + 0xA);
        *(u16*)(p + 0xE) = *(u16*)(obj + 0xE);
    }
    p = func_8002D53C();
    if (p != 0) {
        p[0] = 1;
        p[1] = 4;
        *(u16*)(p + 8) = (*(u16*)(obj + 0x1C) + 0x555) & 0xFFF;
        *(u16*)(p + 0xA) = *(u16*)(obj + 0xA);
        *(u16*)(p + 0xE) = *(u16*)(obj + 0xE);
    }
    p = func_8002D53C();
    if (p != 0) {
        p[0] = 1;
        p[1] = 4;
        *(u16*)(p + 8) = (*(u16*)(obj + 0x1C) + 0xAAA) & 0xFFF;
        *(u16*)(p + 0xA) = *(u16*)(obj + 0xA);
        *(u16*)(p + 0xE) = *(u16*)(obj + 0xE);
    }
    func_8002CE20(0x82, 0);
    t = *(u16*)(obj + 0x14);
    if (t != 0) {
        *(u16*)(obj + 0x14) = t - 1;
        func_8004FD24(obj);
        return;
    }
    *(u16*)(obj + 0x14) = 100;
    obj[4]++;
    D_800D50DC = 0;
    D_8009A42C = 0;
    D_80093E66 = 0;
    func_8002C218();
    func_80017D88();
    D_800D1C43 = 0;
    func_8001296C(10);
}
