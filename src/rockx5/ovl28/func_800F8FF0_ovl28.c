#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s8 D_800D1C00[];
extern u8 D_800FE378_ovl28[];

void func_800F8FF0_ovl28(u8* obj) {
    if (*(s16*)(obj + 0xE) >= 0x2A0) {
        *(u8**)(obj + 0x68) = D_800FE378_ovl28;
    }
    if (*(s16*)(obj + 0xE) >= 0x2E0) {
        s8* g = D_800D1C00;
        s32 v = g[0x2E];
        if (v == 1) {
            obj[6] += 2;
        } else {
            func_8002385C(0x46, 0xFF, v);
            g[0x2E] = 1;
            *(s32*)(obj + 0x2C) = -0x2000;
            *(s16*)(obj + 0x7C) = 0;
            obj[6] += 1;
        }
    }
    animate_object(obj);
    move_object(obj);
    func_8002D9EC(obj, 0x30, 0x30);
}
