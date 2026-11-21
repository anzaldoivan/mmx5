#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s32 func_800478F8(u8* a0);
extern void func_8004795C(u8* a0);

void func_80047718(u8* a0) {
    if (func_800478F8(a0) == 0) {
        if (a0[0x8C] & 8) {
            func_8004795C(a0);
        }
        move_object(a0);
        func_8002D9EC(a0, 0x2C, 0x20);
    }
}

extern void func_800479B0(u8* a0);
extern s32 func_800478F8(u8* a0);

void func_80047778(u8* a0) {
    if (!(a0[0x8C] & 8)) {
        func_800479B0(a0);
    } else if (func_800478F8(a0) != 0) {
        return;
    }
    move_object(a0);
    func_8002D9EC(a0, 0x2C, 0x20);
}

extern void func_800479F4(u8* a0);
extern void func_8004795C(u8* a0);

void func_800477E4(u8* a0) {
    s32 mask;
    u8 flags;

    mask = 2;
    if (a0[0x15] != 0) {
        mask = 1;
    }
    flags = a0[0x8C];
    if (flags & 8) {
        if (flags & mask) {
            func_800479F4(a0);
        } else {
            func_8004795C(a0);
        }
    }
    move_object(a0);
    func_8002D9EC(a0, 0x2C, 0x20);
}
