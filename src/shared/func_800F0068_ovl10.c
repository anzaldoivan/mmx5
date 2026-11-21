#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"

extern u8 D_800FB43C_ovl10[];
extern u8 D_800FB458_ovl10[];
extern u8 D_80074EE0[];

void func_800F0068_ovl10(u8* arg0) {
    arg0[4] = 1;
    arg0[5] = 2;
    arg0[0x5C] = 3;
    arg0[0x60] = 4;
    *(u8**)(arg0 + 0x30) = D_800FB43C_ovl10;
    *(u8**)(arg0 + 0x68) = D_800FB458_ovl10;
    *(u8**)(arg0 + 0x58) = D_80074EE0;
    arg0[6] = 0;
    *(s16*)(arg0 + 0x7C) = 0;
    *(s16*)(arg0 + 0x7E) = 0;
    arg0[0x14] = 0;
    arg0[0x61] = 0;
    arg0[0x15] = 0;
    arg0[0x67] = 0;
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x24) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    arg0[0x16] = 5;
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    set_animation(arg0, 0);
}

extern u8 D_8009A197;
extern void (*D_800FB474_ovl10[])(Ent0110*);
extern s32 D_800FB45C_ovl10[];

void func_800F0110_ovl10(Ent0110* self) {
    func_8002FB58(self);
    if (D_8009A197 == 0) {
        D_800FB474_ovl10[self->state](self);
    }
    self->animPtr = self->animBase = &D_800FB45C_ovl10[self->anim];
    func_80031DD0(self);
    func_800317B8(self);
    func_8002D89C(self);
}
