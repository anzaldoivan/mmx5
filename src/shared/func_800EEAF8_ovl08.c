#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "mmx5/ovl08.h"
#include "mmx5/title.h"

/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800EA840.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8003157C(void*, s16, s16);

void func_800EEAF8_ovl08(X4_Obj* self) {
    s16 x;

    if (M2C_FIELD(self, s8*, 0x67) != 0) {
        return;
    }
    if (!(M2C_FIELD(self, u8*, 0x70) & 8)) {
        ((s32(*)())set_animation)(self, 3);
        self->unk5 = 2;
        M2C_FIELD(self, s32*, 0x2C) = 0x4200;
        self->unk6 = 0;
        M2C_FIELD(self, s32*, 0x24) = 0;
        M2C_FIELD(self, s32*, 0x28) = 0;
        M2C_FIELD(self, s8*, 0x67) = -1;
        return;
    }
    if (self->unk15 != 0) {
        u8* q = M2C_FIELD(self, u8**, 0x68);

        x = self->x_pos.i.hi + (s8)q[0] + q[2];
    } else {
        u8* q = M2C_FIELD(self, u8**, 0x68);

        x = (self->x_pos.i.hi - (s8)q[0]) - q[2];
    }
    if (func_8003157C(
            self, x,
            M2C_FIELD(self, u8**, 0x68)[3] +
                (self->y_pos.i.hi + (s8)M2C_FIELD(self, u8**, 0x68)[1]) + 8) &
        0xFF) {
        return;
    }
    if (self->unk2 == 1) {
        self->unk15 = (self->unk15 == 0) << 6;
        M2C_FIELD(self, s32*, 0x20) = -M2C_FIELD(self, s32*, 0x20);
        return;
    }
    if (!(M2C_FIELD(self, u8*, 0x70) & 3)) {
        s32 v;

        ((s32(*)())set_animation)(self, 2);
        self->unk5 = 5;
        self->unk6 = 0;
        M2C_FIELD(self, s32*, 0x24) = 0x38000;
        v = -0x10000;
        M2C_FIELD(self, s32*, 0x2C) = 0x4200;
        if (self->unk15 != 0) {
            v = 0x10000;
        }
        M2C_FIELD(self, s32*, 0x20) = v;
        M2C_FIELD(self, s8*, 0x67) = 1;
    }
}

extern Obj8002CC08 D_80098120[];

void func_800EEC98_ovl08(u8* o) {
    Obj8002CC08* p;

    if (*(s8*)(o + 0x67) != 0) {
        return;
    }
    if (o[0x80] & 1) {
        return;
    }
    if (o[0x82] != 0) {
        o[0x82]--;
        return;
    }
    for (p = D_80098120; p < D_80098120 + 32; p++) {
        if (p->active == 0) {
            continue;
        }
        if (((s8*)p)[1] != 0) {
            continue;
        }
        if (o[0x15] != 0) {
            if (g_Player[0x15] == 0 && *(s32*)(o + 8) < *(s32*)(g_Player + 8) &&
                ((*(s16*)((u8*)p + 0xE) - *(s16*)(o + 0xE)) < 0
                     ? (*(s16*)(o + 0xE) - *(s16*)((u8*)p + 0xE))
                     : (*(s16*)((u8*)p + 0xE) - *(s16*)(o + 0xE))) < 0x18 &&
                *(s16*)((u8*)p + 0xA) < *(s16*)(o + 0xA) + 0x80) {
                o[0x80] |= 1;
            }
        } else {
            if (g_Player[0x15] != 0 && *(s32*)(o + 8) > *(s32*)(g_Player + 8) &&
                ((*(s16*)((u8*)p + 0xE) - *(s16*)(o + 0xE)) < 0
                     ? (*(s16*)(o + 0xE) - *(s16*)((u8*)p + 0xE))
                     : (*(s16*)((u8*)p + 0xE) - *(s16*)(o + 0xE))) < 0x18 &&
                *(s16*)(o + 0xA) - 0x80 < *(s16*)((u8*)p + 0xA)) {
                o[0x80] |= 1;
            }
        }
        if (o[0x80] & 1) {
            o[5] = 3;
            o[6] = 0;
            set_animation(o, 5);
            return;
        }
    }
}

/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800EABCC.c, AGPL-3.0 (THIRD_PARTY.md). */
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_80074EE0;
extern M2C_UNK D_800750C0;
extern M2C_UNK D_800F39DC_ovl08;
extern M2C_UNK D_800F39E0_ovl08;
extern M2C_UNK D_800F39E4_ovl08;

void func_800EEE84_ovl08(void* arg0) {
    switch (M2C_FIELD(arg0, s8*, 6)) {
    case 0:
        M2C_FIELD(arg0, s8*, 6)++;
        ((s32(*)())set_animation)(arg0, 5);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
    case 1:
        if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
            M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_80074EE0;
            M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F39E0_ovl08;
            M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F39E0_ovl08;
        }
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            M2C_FIELD(arg0, s8*, 6)++;
            ((s32(*)())set_animation)(arg0, 6);
        }
        break;
    case 2:
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            ((void (*)(void*, s32))set_animation)(arg0, 1);
            M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800750C0;
            M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F39E4_ovl08;
            M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F39DC_ovl08;
            M2C_FIELD(arg0, s8*, 5) = 1;
            M2C_FIELD(arg0, s8*, 6) = 0;
            {
                // !FAKE: pins l to $3; gcc 2.7.2 allocates another register without it (byte mismatch)
                register s32 l asm("$3") = M2C_FIELD(arg0, u8*, 0x80);
                M2C_FIELD(arg0, u8*, 0x82) = 0x78;
                M2C_FIELD(arg0, u8*, 0x80) = l & 0xFE;
            }
        }
        break;
    }
    animate_object(arg0);
}

/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800EAD08.c, AGPL-3.0 (THIRD_PARTY.md). */
#define g_Player_as_s32 (*(s32*)&g_Player)

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_800750C0;
extern M2C_UNK D_800F39D8_ovl08;
extern M2C_UNK D_800F39DC_ovl08;
extern M2C_UNK D_800F39E4_ovl08;
extern M2C_UNK D_800F3ADC_ovl08;

void func_800EEFC0_ovl08(void* arg0) {
    X4_Obj* self = arg0;
    s32 x;
    s32 f;
    s32 m;
    self->state++;
    self->unk5 = 1;
    x = self->x_pos.val;
    self->bg_offset = (*(X4_Obj*)&g_Player_as_s32).bg_offset;
    self->unk18.val = x;
    self->unk1C.val = self->y_pos.val;
    f = ((*(X4_Obj*)&g_Player_as_s32).x_pos.val >= x) << 6;
    self->animation_table = (u32**)&D_800F3ADC_ovl08;
    self->unk16 = 6;
    M2C_FIELD(arg0, M2C_UNK**, 0x68) = &D_800F39D8_ovl08;
    M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F39E4_ovl08;
    M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F39DC_ovl08;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800750C0;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x70) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 3;
    M2C_FIELD(arg0, u8*, 0x60) = 1;
    self->x_vel.val = 0;
    self->unk28 = 0;
    self->y_vel.val = 0;
    self->unk2C = 0;
    M2C_FIELD(arg0, u8*, 0x80) = 0;
    M2C_FIELD(arg0, u8*, 0x82) = 0;
    M2C_FIELD(arg0, u8*, 0x81) = 0;
    M2C_FIELD(arg0, u8*, 0x83) = 0;
    self->unk15 = f;
    if ((u32)(M2C_FIELD(arg0, u8*, 2) - 2) < 2U) {
        self->state = 3;
        M2C_FIELD(arg0, void**, 0x54) = 0;
        M2C_FIELD(arg0, void**, 0x50) = 0;
        m = -0x10;
        self->x_pos.u.hi = (self->x_pos.u.hi & m) + 8;
        self->y_pos.u.hi = (self->y_pos.u.hi & m) + 0x14;
        set_animation(arg0, 0);
    } else {
        set_animation(arg0, 1);
    }
}

extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80054440(u8* a0, s32 a1);
extern void func_800EE9BC_ovl08(u8* a0);
extern void func_800EEC98_ovl08(u8* a0);
extern u8 D_8009A197;
extern u8 D_800F3B14_ovl08[];
extern void* D_800F3B18_ovl08[];

void func_800EF100_ovl08(u8* a0) {
    s32 r;
    u8 f;

    if (D_8009A197 == 0) {
        *(s32*)(a0 + 0x18) = *(s32*)(a0 + 0x8);
        *(s32*)(a0 + 0x1C) = *(s32*)(a0 + 0xC);
        /* the definition takes a pointer, this call passes none */
        ((void (*)())func_800EEAF8_ovl08)();
        func_800EE9BC_ovl08(a0);
        func_800EEC98_ovl08(a0);
        ((void (*)(u8*))D_800F3B18_ovl08[*(s8*)(a0 + 5)])(a0);
    }
    func_800317B8(a0);
    r = func_80031DD0(a0);
    if (r < 0) {
        func_8004FD24(a0);
        func_8004D4F4(4, D_800F3B14_ovl08, a0);
        if (r != -0x38) {
            func_80054440(a0, 0x12);
        }
        a0[4]++;
        return;
    }
    if (is_off_screen(a0, 0x40, 0x40) != 0) {
        a0[4] = 4;
        return;
    }
    func_8002D9EC(a0, 0x25, 0x25);
    f = a0[0x70];
    if ((f & 0xC) == 0xC || (f & 3) == 3) {
        func_8004FD24(a0);
        func_8004D4F4(4, D_800F3B14_ovl08, a0);
        a0[3] = 0;
        a0[4]++;
        return;
    }
    func_8002FB58(a0);
}
