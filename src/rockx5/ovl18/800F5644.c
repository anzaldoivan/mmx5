#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern void set_animation_frame(u8* a0, s32 a1, s32 a2);

void func_800F5644_ovl18(u8* self) {
    u8* p = *(u8**)(self + 0x50);

    *(u16*)(self + 0x40) = *(u16*)(p + 0x40);
    *(u16*)(self + 0x42) = *(u16*)(p + 0x42) & 0x7FFF;
    *(s32*)(self + 0x30) = *(s32*)(p + 0x30);
    *(s32*)(self + 0x3C) = *(s32*)(p + 0x3C);
    self[0x14] = p[0x14];
    self[0x15] = 0;
    self[0x16] = 7;
    self[4]++;
    set_animation_frame(self, 2, ((s8*)self)[2]);
    self[7] = 10;
    func_8002D89C(self);
}

void func_800F56D8_ovl18(signed char* arg0) {
    if (--arg0[7] == 0) {
        clear_object_slot(arg0);
    } else {
        func_8002D89C(arg0);
    }
}
