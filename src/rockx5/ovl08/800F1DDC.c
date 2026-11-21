#include "types.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"

void func_800F1DDC_ovl08(Ent800FE04C* e) {
    e->unk6++;
    e->unk20 = 0;
    e->unk24 = -0x30000;
}

extern void start_pad_vibration(s32);

void func_800F1DF8_ovl08(u8* a0) {
    move_object(a0);
    if (*(s16*)(a0 + 0xE) >= *(s16*)(a0 + 0x7E) + *(s16*)(a0 + 0x80)) {
        if (((s8*)a0)[3] != 0) {
            start_pad_vibration(5);
            play_sound(5, 0x15, a0);
        }
        *(s16*)(a0 + 0x7C) = 0x78;
        *(s16*)(a0 + 0xE) = *(s16*)(a0 + 0x7E) + *(s16*)(a0 + 0x80);
        a0[6]++;
    }
}

void func_800F1E84_ovl08(u8* p) {
    s32 t;

    t = *(u16*)(p + 0x7C) - 1;
    *(u16*)(p + 0x7C) = t;
    if ((s16)t >= 0x3D) {
        if (t & 1) {
            *(s16*)(p + 0xE) -= 1;
        } else {
            *(s16*)(p + 0xE) += 1;
        }
        return;
    }
    *(s16*)(p + 0xE) = *(s16*)(p + 0x7E) + *(s16*)(p + 0x80);
    p[6]++;
}

/* Adapted from mmx6 @c1c892d src/shared/rock_05/func_800E9E80.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_56_jet_stingray.c:jet_stingray_vortex_finish, AGPL-3.0; proven shared with X6 by exact signature 5870cc71888c (see THIRD_PARTY.md). */

void func_800F1EFC_ovl08(X4_Obj* self) {
    if (--self->unk7C == 0) {
        self->unk5 = 2;
        self->unk6 = 0;
    }
}
