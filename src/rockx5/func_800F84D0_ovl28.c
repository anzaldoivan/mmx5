#include "types.h"

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
