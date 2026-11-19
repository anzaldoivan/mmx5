#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

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
