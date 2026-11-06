#include "types.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800EF970_ovl18(u8* obj) {
    s8 state = ((s8*)obj)[2];

    if (state == 0) {
        if (((s8*)*(u8**)(obj + 0x50))[2] == 10) {
            func_800171E8(obj, 7);
        } else {
            func_800171E8(obj, 0);
        }
        obj[5] = 0;
    } else if (state == 1) {
        func_800171E8(obj, 2);
        obj[5] = 3;
    } else if (state == 2) {
        if (((s8*)*(u8**)(obj + 0x50))[2] == 10) {
            func_800171E8(obj, 8);
        } else {
            func_800171E8(obj, 1);
        }
        obj[5] = 0;
    } else if (state == 3) {
        func_800171E8(obj, 6);
        obj[5] = 3;
    }
    obj[4]++;
}
