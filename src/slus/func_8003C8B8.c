#include "types.h"
#include "addr.h"

X4_Obj* func_8002D0E4(void);
s32 func_80030820();
s32 func_8002B5B4(s32);
extern s16 D_800748E8[];
extern u32* D_8007B2E8[];
extern u32* D_80098118;

void func_8003C8B8(void* arg0) {
    X4_Obj* self = arg0;
    X4_Obj* obj;
    s32* t;
    s32 a;
    s32 b;
    u8 f;
    u8 g;

    if (func_80030820() == 0x24) {
        obj = func_8002D0E4();
        if (obj != 0) {
            obj->active = 0x41;
            obj->id = 3;
            obj->unk2 = 8;
            g = self->bg_offset;
            obj->unk16 = 1;
            obj->animation_table = D_8007B2E8;
            obj->bg_offset = g;
            a = func_8002B5B4(0x9A);
            t = D_1F800020.s32s;
            obj->unk3C = (void*)((s8*)t + t[a]);
            obj->unk40 = D_80098118[func_8002B5B4(0x9A)] >> 7;
            a = func_8002B5B4(0x9A);
            b = func_8002B5B4(0x9A);
            obj->unk42 = ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
            f = self->unk15;
            obj->unk15 = f;
            if (f == 0) {
                obj->x_pos.i.hi = self->x_pos.i.hi + D_800748E8[self->unk2];
            } else {
                obj->x_pos.i.hi = self->x_pos.i.hi - D_800748E8[self->unk2];
            }
            obj->y_pos.i.hi = self->y_pos.i.hi;
        }
    }
}
