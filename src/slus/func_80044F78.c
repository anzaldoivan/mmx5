/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800383F8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "addr.h"
#define M2C_UNK s32

M2C_UNK func_80016490(M2C_UNK, M2C_UNK, void*);
X4_Obj* func_8002D0E4(void);
extern u32* D_8007B2E8[];

#define F_PTR(p, o) (*(u8**)((u8*)(p) + (o)))

void func_80044F78(void* arg0) {
    X4_Obj* self = arg0;
    X4_Obj* obj;
    u8* tbl;
    u8* p;
    s32 off;

    if (self->id == 0x3A) {
        func_80016490(1, 9, self);
    } else if ((u8)(self->id - 0x38) >= 2) {
        func_80016490(1, 0xC, self);
    }
    obj = func_8002D0E4();
    if (obj != 0) {
        obj->active = 0x21;
        obj->id = 3;
        if (self->id == 0x12 || self->id == 0x14 || self->id == 0x2E) {
            obj->unk2 = 4;
        } else {
            obj->unk2 = 3;
        }
        obj->bg_offset = self->bg_offset;
        tbl = D_1F80001C.bytes;
        off = *(s32*)(tbl + 4);
        obj->animation_table = D_8007B2E8;
        obj->unk40 = 0;
        obj->unk42 = 0x7802;
        obj->unk16 = 0;
        obj->unk3C = tbl + off;
        obj->x_pos.i.hi = self->x_pos.i.hi;
        obj->y_pos.i.hi = self->y_pos.i.hi;
        obj->unk15 = self->unk15 ^ 0x40;
        if ((u8)(self->id - 0x38) < 2) {
            obj->unk2 = 0xC;
        }
        if (self->id == 0x3A) {
            obj->unk2 = 0xC;
            p = F_PTR(self, 0x68);
            if (p != 0) {
                if (self->unk15 != 0) {
                    obj->x_pos.i.hi -= (s8)*p;
                } else {
                    obj->x_pos.i.hi += (s8)*p;
                }
            }
        }
    }
}
