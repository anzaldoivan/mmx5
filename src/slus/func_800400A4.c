#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8003B33C(u8*, s32);
extern void func_8003D0A0(u8* obj);
extern void func_80040738(u8* obj);
extern D1C00 D_800D1C00;

void func_800400A4(u8* obj) {
    if (((s8*)obj)[2] == 0) {
        if (((s8*)obj)[0x8F] != 0) {
            func_80040738(obj);
            return;
        }
        if (((s8*)obj)[0x90] != 0) {
            func_8003D0A0(obj);
            return;
        }
    }
    if (obj[0x17] == 6 &&
        ((s8*)obj)[0x5C] >= (s8)(D_800D1C00.unk47[((s8*)obj)[2]] / 3)) {
        func_8003B33C(obj, 5);
        return;
    }
    func_80017248(obj);
}
