/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8003C6A4.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "addr.h"

X4_Obj* func_8002D0E4(void);
s32 func_80030820();
void func_8003C8B8(void* arg0);
extern X4_S16Pair D_800748E0[];
extern u32* D_8007B2E8[];

void func_8003C784(void* arg0) {
    X4_Obj* self = arg0;
    X4_Obj* obj;
    u8 f;
    s32* t;
    s32 o;

    if (func_80030820() == 0x24) {
        func_8003C8B8(self);
        return;
    }
    obj = func_8002D0E4();
    if (obj != 0) {
        obj->active = 0x21;
        obj->id = 3;
        obj->unk2 = 2;
        obj->state = 0;
        obj->unk5 = 0;
        obj->unk6 = 0;
        obj->bg_offset = self->bg_offset;
        obj->unk38 = 0;
        t = D_1F80001C.s32s;
        o = t[1];
        obj->animation_table = D_8007B2E8;
        obj->unk40 = 0;
        obj->unk42 = 0x7804;
        obj->unk16 = 1;
        obj->unk3C = (void*)((s8*)t + o);
        f = self->unk15;
        obj->unk15 = f;
        if (f == 0) {
            obj->x_pos.i.hi = self->x_pos.i.hi + D_800748E0[self->unk2].lo;
        } else {
            obj->x_pos.i.hi = self->x_pos.i.hi - D_800748E0[self->unk2].lo;
        }
        obj->y_pos.i.hi = self->y_pos.i.hi + D_800748E0[self->unk2].hi;
    }
}
