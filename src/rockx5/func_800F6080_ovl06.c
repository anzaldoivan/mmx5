#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D89C(u8* a0, s32 a1, s32 a2);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002DF54(u8* a0);
extern s32 func_8002F8FC(u8* a0);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);

void func_800F6080_ovl06(u8* obj) {
    s32 r;
    u8 t;
    u8* p;

    p = *(u8**)(obj + 0x7C);
    if (*(s8*)(obj + 2) != 0) {
        *(s32*)(obj + 8) = *(s32*)(p + 8);
        *(s32*)(obj + 0xC) = *(s32*)(p + 0xC);
        if (*(s16*)(obj + 0xA) >= 0xBD1) {
            obj[4] = 2;
        }
    } else {
        r = func_80031DD0(obj);
        if (*(s8*)(p + 4) == 2) {
            r = -1;
        }
        func_80017248(obj);
        func_8002DF54(obj);
        func_8002F8FC(obj);
        if (obj[0x70] != 0 || *(s8*)(p + 5) == 7) {
            r = -1;
        }
        if (r < 0) {
            func_8004FD24(obj);
            obj[4] = 2;
            return;
        }
        obj[0x8E] = 2;
    }
    t = obj[0x8E];
    if (t == 0) {
        *(u16*)(obj + 0x42) &= 0x7FFF;
    } else {
        obj[0x8E] = t - 1;
    }
    func_800317B8(obj);
    if (func_8002D938(obj, 0x80, 0x80) == 0) {
        func_8002D89C(obj, 0x10, 0x10);
    } else {
        obj[4] = 2;
    }
    if (*(s8*)(obj + 2) != 0) {
        obj[3] = 0;
    }
    *(u16*)(obj + 0x42) &= 0x7FFF;
    if (*(s8*)(*(u8**)(obj + 0x7C) + 4) == 2) {
        obj[4] = 2;
    }
}
