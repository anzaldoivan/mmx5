#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

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
