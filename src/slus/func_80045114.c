#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 D_80076E24[];
extern s32 D_80076E44[];
extern s32 D_8009A19C;

void func_80045114(u8* obj) {
    obj[3] = 1;
    if (((s8*)obj)[1] == 9) {
        obj[2] = 0;
        if (!(D_8009A19C & 0x200)) {
            *(s32*)(obj + 0x20) = 0x80000;
        } else {
            *(s32*)(obj + 0x20) = 0xA0000;
        }
    } else {
        obj[2] = 1;
        if (!(D_8009A19C & 0x200)) {
            *(s32*)(obj + 0x20) = 0xA0000;
        } else {
            *(s32*)(obj + 0x20) = 0xC0000;
        }
    }
    *(s32**)(obj + 0x68) = &D_80076E44[((s8*)obj)[2]];
    *(s32**)(obj + 0x50) = &D_80076E24[((s8*)obj)[2]];
    if (obj[0x15] == 0) {
        *(s32*)(obj + 0x20) = -*(s32*)(obj + 0x20);
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    func_800171E8(obj, ((s8*)obj)[2] + 0x1A);
    obj[4]++;
    func_8002D9EC(obj, 0x20, 0x14);
}
