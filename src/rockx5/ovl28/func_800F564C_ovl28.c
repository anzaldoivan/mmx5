#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

s32 func_80044DE0();

void func_800F564C_ovl28(u8* self) {
    animate_object(self);
    if (*(s16*)(self + 0x7E) != 0) {
        if (func_80044DE0() != 0) {
            return;
        }
        *(s16*)(self + 0x7E) = 0;
    }
    func_8002C338(0x13C, D_1F800030 + 0x60, 1);
    func_8002C338(0x13D, D_1F800030 + 0x80, 1);
    *(s16*)(self + 0x42) = 0x7CCC;
    if (*(s8*)(self + 0x45) == 1) {
        set_animation(self, 1);
        *(s16*)(self + 0x7C) = 2;
        self[6]++;
    }
}
