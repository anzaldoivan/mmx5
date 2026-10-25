#include "types.h"

extern s32 func_80040B6C(u8* self);
extern s32 func_80039AE0(void* self);
extern s32 func_8003979C(u8* self);
extern void func_8003ABD0(u8* self);
extern s32 func_80040BBC(void* self);
extern void func_80040C88(u8* self, s32 direction);
extern void func_8003F2D8(u8* arg0, s32 arg1);

void func_80040830(u8* self) {
    s32 dir;

    if (func_80040B6C(self) != 0) {
        return;
    }
    if (func_80039AE0(self) != 0) {
        return;
    }
    if (func_8003979C(self) != 0 && self[0x92] == 0) {
        func_8003ABD0(self);
        return;
    }
    dir = func_80040BBC(self);
    if (dir != 0) {
        self[0xE8] = 0x28;
        func_80040C88(self, dir);
    } else {
        func_8003F2D8(self, 0x15);
    }
}
