#include "types.h"
#include "addr.h"

extern X4_Obj* func_8002D0E4(void);
extern u8 D_8009A0B4;
extern u32* D_8007B2E8[];

void func_8004FC64(X4_Obj* arg0) {
    X4_Obj* obj;

    obj = func_8002D0E4();
    if (obj != 0) {
        obj->active = 0x21;
        obj->id = 3;
        obj->unk2 = 1;
        obj->bg_offset = D_8009A0B4;
        obj->state = 0;
        obj->unk5 = 0;
        obj->unk6 = 0;
        obj->unk38 = 0;
        obj->unk3C = (void*)((s8*)D_1F80001C.s32s + D_1F80001C.s32s[1]);
        obj->animation_table = &D_8007B2E8;
        obj->unk40 = 0;
        obj->unk42 = 0x7802;
        obj->unk16 = 0;
        obj->unk15 = 0;
        if (arg0->x_vel.val > 0) {
            obj->unk15 = 0x40;
        }
        obj->x_pos.i.hi = arg0->x_pos.i.hi;
        obj->y_pos.i.hi = arg0->y_pos.i.hi;
    }
}
