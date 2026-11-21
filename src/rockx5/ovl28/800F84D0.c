#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_80074E40[];

void func_800F84D0_ovl28(void* self) {
    void* parent;
    s16 dx;
    s32 idx;

    parent = M2C_FIELD(self, void**, 0x7C);
    M2C_FIELD(self, u16*, 0x40) = M2C_FIELD(parent, u16*, 0x40);
    M2C_FIELD(self, u16*, 0x42) = M2C_FIELD(parent, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(self, s32*, 0x30) = M2C_FIELD(parent, s32*, 0x30);
    M2C_FIELD(self, s32*, 0x3C) = M2C_FIELD(parent, s32*, 0x3C);
    M2C_FIELD(self, u8*, 0x16) = 1;
    M2C_FIELD(self, u8*, 0x14) = 0;
    M2C_FIELD(self, u8*, 0x15) = M2C_FIELD(parent, u8*, 0x15);
    M2C_FIELD(self, u8*, 0x67) = 0;
    M2C_FIELD(self, u8*, 0x3) = 0;
    M2C_FIELD(self, s32*, 0x68) = 0;
    M2C_FIELD(self, s32*, 0x50) = 0;
    M2C_FIELD(self, s32*, 0x54) = 0;
    M2C_FIELD(self, void**, 0x58) = D_80074E40;
    idx = (s8)M2C_FIELD(parent, u8*, 0x7)++;
    M2C_FIELD(self, s32*, 0x8C) = idx;
    dx = 0x18;
    if (M2C_FIELD(self, u8*, 0x15) == 0) {
        dx = -0x18;
    }
    switch (idx) {
    case 0:
        M2C_FIELD(self, s16*, 0xA) =
            M2C_FIELD(M2C_FIELD(self, void**, 0x7C), s16*, 0xA) + dx + 0x20;
        M2C_FIELD(self, s32*, 0x90) = 2;
        break;
    case 1:
        M2C_FIELD(self, s16*, 0xA) =
            M2C_FIELD(M2C_FIELD(self, void**, 0x7C), s16*, 0xA) + dx - 0x20;
        M2C_FIELD(self, s32*, 0x90) = 2;
        break;
    case 2:
        M2C_FIELD(self, s16*, 0xA) =
            M2C_FIELD(M2C_FIELD(self, void**, 0x7C), s16*, 0xA) + dx + 0x60;
        M2C_FIELD(self, s32*, 0x90) = 0xA;
        break;
    case 3:
        M2C_FIELD(self, s16*, 0xA) =
            M2C_FIELD(M2C_FIELD(self, void**, 0x7C), s16*, 0xA) + dx - 0x60;
        M2C_FIELD(self, s32*, 0x90) = 0xA;
        break;
    case 4:
        M2C_FIELD(self, s16*, 0xA) =
            M2C_FIELD(M2C_FIELD(self, void**, 0x7C), s16*, 0xA) + dx + 0xA0;
        M2C_FIELD(self, s32*, 0x90) = 0x12;
        break;
    case 5:
        M2C_FIELD(self, s16*, 0xA) =
            M2C_FIELD(M2C_FIELD(self, void**, 0x7C), s16*, 0xA) + dx - 0xA0;
        M2C_FIELD(self, s32*, 0x90) = 0x12;
        break;
    case 6:
        M2C_FIELD(self, s16*, 0xA) =
            M2C_FIELD(M2C_FIELD(self, void**, 0x7C), s16*, 0xA) + dx + 0xE0;
        M2C_FIELD(self, s32*, 0x90) = 0x1A;
        break;
    case 7:
        M2C_FIELD(self, s16*, 0xA) =
            M2C_FIELD(M2C_FIELD(self, void**, 0x7C), s16*, 0xA) + dx - 0xE0;
        M2C_FIELD(self, s32*, 0x90) = 0x1A;
        break;
    }
    M2C_FIELD(self, s16*, 0xE) =
        M2C_FIELD(M2C_FIELD(self, void**, 0x7C), s16*, 0xE) + 4;
    M2C_FIELD(self, s32*, 0x20) = 0;
    M2C_FIELD(self, s32*, 0x24) = 0;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0;
    M2C_FIELD(self, u8*, 0x5C) = 1;
    M2C_FIELD(self, u8*, 0x60) = 8;
    M2C_FIELD(self, u8*, 0x4)++;
    M2C_FIELD(self, u8*, 0x5) = 0;
}
#undef M2C_FIELD

extern u8 D_800FE764_ovl28[];
extern u8 D_800FE768_ovl28[];

void func_800F86D4_ovl28(u8* obj) {
    s8 state;
    s8 v;
    u8* p;

    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
        ((s32(*)())func_8004FD24)(obj);
        obj[4] = 2;
        return;
    }
    state = obj[5];
    switch (state) {
    case 0:
        if (--*(s32*)(obj + 0x90) == 0) {
            p = func_8002D1A4();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x24;
                p[2] = 6;
                *(s32*)(p + 0x7C) = *(s32*)(obj + 0x7C);
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA);
                *(s16*)(p + 0xE) = *(s16*)(obj + 0xE) + 0xC;
            }
            *(s32*)(obj + 0x90) = 0;
            obj[5]++;
        }
        break;
    case 1:
        if (++*(s32*)(obj + 0x90) == 4) {
            set_animation(obj, 0x10);
            *(u8**)(obj + 0x50) = D_800FE764_ovl28;
            *(u8**)(obj + 0x54) = D_800FE768_ovl28;
            *(s32*)(obj + 0x24) = 0x60000;
            obj[5]++;
        }
        break;
    case 2:
        if (*(s16*)(obj + 0xE) < 0x220) {
            obj[4] = state;
        }
        func_8002D9EC(obj, 0x20, 0x30);
        break;
    }
    v = (*(u8**)(obj + 0x7C))[4];
    if (v == 2) {
        obj[4] = v;
    }
    animate_object(obj);
    move_object(obj);
}
