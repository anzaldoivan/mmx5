#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_80016490(s32, s32, void*);

void func_800F2EA8_ovl07(u8* obj) {
    if (*(u16*)(*(u8**)(obj + 0x7C) + 0x88) == 0) {
        if (*(s8*)(obj + 0x66) > 0) {
            func_800171E8(obj, 0xD);
        } else {
            func_800171E8(obj, 0xE);
        }
        func_80016490(0, 0x11, obj);
        obj[6]++;
    }
}
