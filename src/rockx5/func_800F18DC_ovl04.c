#include "types.h"

extern s32 func_80031DD0(u8* a0);
extern s32 func_800317B8(u8* a0);
extern s32 func_8002D800(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8009A197;
extern void* D_8010155C_ovl04[];

void func_800F18DC_ovl04(u8* obj) {
    u8 t;

    if (func_80031DD0(obj) != 0 && obj[0x80] == 0) {
        obj[0x80] = 0x3C;
    }
    if (D_8009A197 == 0) {
        t = obj[0x80];
        if (t == 0) {
            ((void (*)(u8*))D_8010155C_ovl04[((s8*)obj)[5]])(obj);
        } else {
            obj[0x80] = t - 1;
        }
    }
    func_800317B8(obj);
    if (func_8002D800(obj) == 0) {
        func_8002D9EC(obj, 0x40, 0x40);
    } else {
        obj[4] = 2;
    }
}
