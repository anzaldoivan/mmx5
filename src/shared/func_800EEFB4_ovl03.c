#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800EEFB4_ovl03(Ent08D8* e) {
    animate_object(e);
    if (e->unk70 & 8) {
        e->unk5 = 2;
        e->unk6 = 0;
        e->unk24 = 0;
        e->unk2C = 0;
        e->unk67 = 0;
    } else {
        apply_object_motion(e);
    }
}

void func_800EF00C_ovl03(u8* arg0) {
    if (((s8*)arg0)[2] != 0 && arg0[0x70] == 0) {
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        arg0[5] = 2;
        arg0[6] = 0;
    }
}
