#include "types.h"

extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern u8* func_8002D1A4();
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern u8 D_800FE764_ovl28[];
extern u8 D_800FE768_ovl28[];

void func_800F86D4_ovl28(u8* obj) {
    s8 state;
    s8 v;
    u8* p;

    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
        func_8004FD24(obj);
        obj[4] = 2;
        return;
    }
    state = obj[5];
    switch (state) {
    case 0:
        if (--*(s32*)(obj + 0x90) == 0) {
            p = func_8002D1A4();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x24;
                p[2] = 6;
                *(s32*)(p + 0x7C) = *(s32*)(obj + 0x7C);
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA);
                *(s16*)(p + 0xE) = *(s16*)(obj + 0xE) + 0xC;
            }
            *(s32*)(obj + 0x90) = 0;
            obj[5]++;
        }
        break;
    case 1:
        if (++*(s32*)(obj + 0x90) == 4) {
            func_800171E8(obj, 0x10);
            *(u8**)(obj + 0x50) = D_800FE764_ovl28;
            *(u8**)(obj + 0x54) = D_800FE768_ovl28;
            *(s32*)(obj + 0x24) = 0x60000;
            obj[5]++;
        }
        break;
    case 2:
        if (*(s16*)(obj + 0xE) < 0x220) {
            obj[4] = state;
        }
        func_8002D9EC(obj, 0x20, 0x30);
        break;
    }
    v = (*(u8**)(obj + 0x7C))[4];
    if (v == 2) {
        obj[4] = v;
    }
    func_80017248(obj);
    func_8002DF54(obj);
}
