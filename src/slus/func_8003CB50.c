#include "types.h"
#include "addr.h"

X4_Obj* func_8002D0E4(void);
extern s32 func_80030AE4(X4_Obj*, s16, s16);
s32 func_8002B5B4(s32);
void func_80016490(s32, s32, void*);
extern u32* D_8007B2E8[];
extern u32* D_80098118;

void func_8003CB50(X4_Obj* self, s16 arg1) {
    X4_Obj* obj;
    s32* t;
    s32 a;
    s32 b;
    u8 g;
    u16 h;

    if (func_80030AE4(self, self->x_pos.i.hi, arg1) == 0x24 &&
        ((s8*)self)[0xF2] == 0) {
        ((s8*)self)[0xF2] = 1;
        obj = func_8002D0E4();
        if (obj != 0) {
            obj->active = 0x41;
            obj->id = 3;
            obj->unk2 = 9;
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
            obj->unk15 = self->unk15;
            h = self->x_pos.i.hi;
            obj->y_pos.i.hi = arg1 - 8;
            obj->x_pos.i.hi = h;
        }
        func_80016490(5, 0x20, self);
    }
}
