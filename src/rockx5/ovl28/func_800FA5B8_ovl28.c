#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_80074E40[];

void func_800FA5B8_ovl28(void* self) {
    void* parent;
    void* owner;
    s32 t;
    s32 e;
    s32 c;
    u8 dir;

    parent = M2C_FIELD(self, void**, 0x7C);
    M2C_FIELD(self, u16*, 0x40) = M2C_FIELD(parent, u16*, 0x40);
    M2C_FIELD(self, u16*, 0x42) = M2C_FIELD(parent, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(self, s32*, 0x30) = M2C_FIELD(parent, s32*, 0x30);
    t = M2C_FIELD(parent, s32*, 0x3C);
    M2C_FIELD(self, u8*, 0x16) = 1;
    M2C_FIELD(self, u8*, 0x14) = 0;
    M2C_FIELD(self, s32*, 0x3C) = t;
    dir = M2C_FIELD(parent, u8*, 0x15);
    M2C_FIELD(self, u8*, 0x67) = 0;
    M2C_FIELD(self, u8*, 0x3) = 0;
    M2C_FIELD(self, s32*, 0x68) = 0;
    M2C_FIELD(self, s32*, 0x50) = 0;
    M2C_FIELD(self, s32*, 0x54) = 0;
    M2C_FIELD(self, void**, 0x58) = D_80074E40;
    M2C_FIELD(self, u8*, 0x15) = dir;
    if (dir == 0) {
        M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(parent, u16*, 0xA) - 0x1E;
    } else {
        M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(parent, u16*, 0xA) + 0x1E;
    }
    owner = M2C_FIELD(self, void**, 0x7C);
    c = M2C_FIELD(self, u8*, 0x4) + 1;
    e = M2C_FIELD(owner, u16*, 0xE);
    M2C_FIELD(self, s32*, 0x20) = 0;
    M2C_FIELD(self, s32*, 0x24) = 0;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0;
    M2C_FIELD(self, u8*, 0x5C) = 1;
    M2C_FIELD(self, u8*, 0x60) = 8;
    M2C_FIELD(self, s32*, 0x8C) = 0;
    M2C_FIELD(self, u8*, 0x4) = c;
    M2C_FIELD(self, u8*, 0x5) = 0;
    M2C_FIELD(self, u16*, 0xE) = e - 0xA;
}
