#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

/* Adapted from mmx6 @c1c892d src/shared/rock_22/func_800F461C.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F1B3C_ovl11(void*);

extern M2C_UNK D_80074F80;
extern u8 D_800F9924_ovl11[];
extern u8 D_800F992C_ovl11[];

void func_800F17F0_ovl11(X4_Obj* self) {
    X4_Obj* parent;
    s8 kind;

    self->state++;
    self->on_screen = 1;
    self->hp = 1;
    self->unk60 = 6;
    self->unk50 = D_800F9924_ovl11;
    self->unk58 = &D_80074F80;
    self->unk68 = (void*)D_800F992C_ovl11;
    self->unk54 = D_800F9924_ovl11;
    kind = self->unk2;
    self->x_vel.val = 0;
    self->unk28 = 0;
    self->y_vel.val = 0;
    self->unk2C = 0;
    self->unk42 &= 0x7FFF;
    parent = M2C_FIELD(self, X4_Obj**, 0x7C);
    if (kind == 0) {
        if (self->unk15 == 0) {
            self->x_pos.i.hi = parent->x_pos.i.hi - 0x20;
        } else {
            self->x_pos.i.hi = parent->x_pos.i.hi + 0x20;
        }
        self->y_pos.i.hi = parent->y_pos.i.hi - 8;
    } else if (kind == 1) {
        if (self->unk15 == 0) {
            self->x_pos.i.hi = parent->x_pos.i.hi - 0x1D;
        } else {
            self->x_pos.i.hi = parent->x_pos.i.hi + 0x1D;
        }
        self->y_pos.i.hi = parent->y_pos.i.hi + 0xE;
    } else {
        if (self->unk15 == 0) {
            self->x_pos.i.hi = parent->x_pos.i.hi - 0xC;
        } else {
            self->x_pos.i.hi = parent->x_pos.i.hi + 0xC;
        }
        self->y_pos.i.hi = parent->y_pos.i.hi + 0x12;
    }
    set_animation(self, 3);
    func_800F1B3C_ovl11(self);
    M2C_FIELD(self, s32*, 0x84) = 0x10;
    M2C_FIELD(self, s32*, 0x8C) = 0;
}

extern u8 D_8009A197;
extern s32 D_800F9934_ovl11[];

void func_800F1958_ovl11(u8* obj) {
    s32 flag;
    s32 v;
    s32 x;
    s32 st;

    if (D_8009A197 == 0) {
        animate_object(obj);
        apply_object_motion(obj);
        if (--*(s32*)(obj + 0x84) == 0 && obj[0x17] != 4) {
            flag = obj[0x15] & 0x40;
            v = D_800F9934_ovl11[flag != 0];
            x = *(s16*)(obj + 0xA);
            *(s32*)(obj + 0x28) = 0x600;
            *(s32*)(obj + 0x20) = v;
            if (flag != 0) {
                *(s16*)(obj + 0xA) = x + 0x10;
            } else {
                *(s16*)(obj + 0xA) = x - 0x10;
            }
            set_animation(obj, 4);
        }
    }
    if (__builtin_abs(*(s32*)(obj + 0x20)) > 0x30000) {
        *(s32*)(obj + 0x28) = 0;
    }
    if (func_80031DD0(obj) < 0) {
        func_8004FD24(obj);
        *(s32*)(obj + 0x8C) = 1;
        st = obj[4] + 1;
        obj[4] = st;
        return;
    } else {
        func_800317B8(obj);
        if ((st = obj[0x70]) != 0 ||
            (func_8002F8FC(obj), (st = obj[0x70]) != 0)) {
            func_8004FD24(obj);
            st = 2;
            obj[4] = st;
            return;
        } else {
            if (is_off_screen(obj, 0x20, 0x20) == 0) {
                func_8002D9EC(obj, 0x20, 0x20);
                return;
            }
            obj[4]++;
            *(s32*)(obj + 0x8C) = 1;
            return;
        }
    }
}
