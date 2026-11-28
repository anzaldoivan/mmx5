#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

void func_80057080(u8* a0) {
    u8* p;

    if (*(u16*)(a0 + 0x18) == 0) {
        p = alloc_class6_slot();
        if (p != 0) {
            *(s8*)p = -0x7D;
            p[1] = 3;
            p[2] = a0[0x1B];
            D_800E95A8[a0[0x1B]] = p;
            *(u16*)(a0 + 0x18) = 2;
            a0[0x1B]++;
            if (a0[0x1B] == 22) {
                a0[0x1B] = 0;
                *(u16*)(a0 + 0x18) = 180;
                a0[5]++;
            }
        }
    } else {
        *(u16*)(a0 + 0x18) -= 1;
    }
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800536D0.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/effects/effect_24_boss_warning.c:boss_warning_wait, AGPL-3.0; proven shared with X6 by exact signature ec91c859e783 (see THIRD_PARTY.md). */

void func_80057130(X4_Obj* self) {
    if (--self->unk18.u.lo == 0) {
        self->unk5++;
    }
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80053704.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/effects/effect_24_boss_warning.c:boss_warning_wait_tiles, AGPL-3.0; proven shared with X6 by exact signature f64138f8e32d (see THIRD_PARTY.md). */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80057164(X4_Obj* self) {
    X4_Obj* spawned;
    X4_Obj** entry;
    u32 index;
    s32 count;
    s32 expected;

    spawned = M2C_FIELD(self, X4_Obj**, 0x14);
    if (spawned->id != 4 || *(u16*)spawned == 0x400) {
        index = 0;
        count = 0;
        expected = 1;
        entry = (X4_Obj**)D_800E95A8;
        do {
            if ((*entry)->unk5 == expected) {
                count++;
            }
            index++;
            entry++;
        } while (index < 0x16U);
        if (count == 0x16) {
            self->unk18.bytes[3] = 0;
            self->unk5++;
        }
    }
}
#undef M2C_FIELD

void func_800571EC(u8* a0) {
    D_800E95A8[a0[0x1B]][5]++;
    a0[0x1B]++;
    if (a0[0x1B] == 22) {
        *(u16*)(a0 + 0x18) = 60;
        a0[5]++;
    }
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800537F0.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/effects/effect_24_boss_warning.c:boss_warning_finish, AGPL-3.0; proven shared with X6 by exact signature 7ccb25922a7c (see THIRD_PARTY.md). */

void func_80057250(X4_Obj* self) {
    self->unk18.bytes[2] = 0xA;
    if (--self->unk18.u.lo == 0) {
        self->state++;
    }
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80053828.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/effects/effect_24_boss_warning.c:boss_warning_main, AGPL-3.0; proven shared with X6 by exact signature f335fb55e436 (see THIRD_PARTY.md). */
extern void (*D_8007D9E0[])(X4_Obj*);

void func_80057288(X4_Obj* self) {
    D_8007D9E0[self->unk5](self);
    if (self->unk18.bytes[2] == 0) {
        play_sound(0, 0x13, 0);
        self->unk18.bytes[2] = 0x3C;
    } else {
        self->unk18.bytes[2]--;
    }
}
