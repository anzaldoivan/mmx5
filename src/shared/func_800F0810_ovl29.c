#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"

void func_800F0810_ovl29(u8* self) {
    *(s32*)(self + 0x20) = 0;
    *(s32*)(self + 0x28) = 0;
    *(s32*)(self + 0x24) = 0;
    *(s32*)(self + 0x2C) = 0;
    set_animation(self, 0x14);
    self[6]++;
}

void func_800F0854_ovl29(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == -1) {
        arg0[6]++;
    }
}

void func_800F088C_ovl29(u8* arg0) {
    s16 x;
    s16 y;

    y = D_8009A0AA;
    x = *(s16*)(arg0 + 0xA);
    if (((y - x) < 0 ? (x - y) : (y - x)) < 0x80) {
        arg0[5] = 2;
        arg0[6] = 0;
    }
}

void func_800F08D8_ovl29(Ent08D8* e) {
    animate_object(e);
    if (e->unk70 & 8) {
        e->unk5 = 5;
        e->unk6 = 0;
        e->unk24 = 0;
        e->unk2C = 0;
        e->unk20 = 0;
        e->unk28 = 0;
        e->unk67 = 0;
    } else {
        apply_object_motion(e);
    }
}
