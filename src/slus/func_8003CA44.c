#include "types.h"
#include "addr.h"

X4_Obj* func_8002D0E4(void);
extern X4_S16Pair D_800748EC[];
extern u32* D_8007B2E8[];

void func_8003CA44(void* arg0) {
    X4_Obj* self = arg0;
    X4_Obj* obj;
    u8 f;
    s32* t;
    s32 o;

    obj = func_8002D0E4();
    if (obj != 0) {
        obj->active = 0x21;
        obj->id = 3;
        obj->unk2 = 1;
        obj->bg_offset = self->bg_offset;
        obj->state = 0;
        obj->unk5 = 0;
        obj->unk6 = 0;
        obj->unk38 = 0;
        t = D_1F80001C.s32s;
        o = t[1];
        obj->animation_table = D_8007B2E8;
        obj->unk40 = 0;
        obj->unk42 = 0x7802;
        obj->unk16 = 0;
        obj->unk3C = (void*)((s8*)t + o);
        f = self->unk15;
        obj->unk15 = f;
        if (f == 0) {
            obj->x_pos.i.hi = self->x_pos.i.hi + D_800748EC[self->unk2].lo;
        } else {
            obj->x_pos.i.hi = self->x_pos.i.hi - D_800748EC[self->unk2].lo;
        }
        obj->y_pos.i.hi = self->y_pos.i.hi + D_800748EC[self->unk2].hi;
    }
}
