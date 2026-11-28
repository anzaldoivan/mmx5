#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_80100900_ovl07[];
extern u8 D_80100904_ovl07[];

void func_800F1484_ovl07(u8* obj) {
    obj[4] = 1;
    *(u8**)(obj + 0x68) = D_80100904_ovl07;
    obj[3] = 1;
    *(u8**)(obj + 0x50) = D_80100900_ovl07;
    obj[0x16] = 0;
    *(s32*)(obj + 0x54) = 0;
    obj[0x5C] = 1;
    obj[0x60] = 3;
    set_animation(obj, 12);
}

void func_800F14DC_ovl07(u8* obj) {
    u8* p = *(u8**)(obj + 0x7C);
    s8 v;

    if (((s8*)p)[4] < 2) {
        v = ((s8*)p)[5];
        if (v == 5 || v == 0) {
            obj[3] = 0;
            if (p[0x47] == 3) {
                *(s32*)(obj + 0x8) = *(s32*)(p + 0x8);
                *(s32*)(obj + 0xC) = *(s32*)(p + 0xC);
                animate_object(obj);
                func_8002D9EC(obj, 0x10, 0x10);
            }
            return;
        }
    }
    obj[4] = 2;
    obj[3] = 0;
}
