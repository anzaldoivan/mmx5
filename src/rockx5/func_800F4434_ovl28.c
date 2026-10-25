#include "types.h"
#include "addr.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800171E8(void*, s32);
void func_80016490(s32, s32, void*);
s32 func_8002C338(s32, void*, s32);
extern u8 D_8009A0B4;
extern u32* D_8007B2E8[];

void func_800F4434_ovl28(void* self) {
    u8* p;

    M2C_FIELD(self, u8*, 4) = 1;
    M2C_FIELD(self, u8*, 5) = 2;
    M2C_FIELD(self, u8*, 0x14) = D_8009A0B4;
    M2C_FIELD(self, u8*, 3) = 1;
    switch (M2C_FIELD(self, s8*, 2)) {
    case 0:
    case 1:
        M2C_FIELD(self, u8*, 0x16) = 5;
        M2C_FIELD(self, s32*, 0x20) = 0;
        M2C_FIELD(self, s32*, 0x24) = 0xFFF80000;
        func_800171E8(self, 0x14);
        func_80016490(2, 0x75, self);
        M2C_FIELD(self, u8*, 6) = 0;
        break;
    case 2:
        func_8002C338(0x13E, D_1F800030 + 0x200, 1);
        func_8002C338(0x13F, D_1F800030 + 0x200, 1);
        M2C_FIELD(self, u8*, 0x16) = 2;
        func_800171E8(self, 0xD);
        M2C_FIELD(self, u8*, 6) = 3;
        break;
    case 3:
        M2C_FIELD(self, u8*, 0x15) = 0;
        M2C_FIELD(self, u8*, 0x5C) = 0;
        M2C_FIELD(self, u8*, 0x60) = 0;
        M2C_FIELD(self, u8*, 3) = 0;
        M2C_FIELD(self, u8*, 0x16) = 1;
        func_800171E8(self, 0xE);
        M2C_FIELD(self, u8*, 6) = 4;
        func_80016490(2, 0x73, self);
        break;
    case 4:
        M2C_FIELD(self, u8*, 0x15) = 0;
        M2C_FIELD(self, u8*, 0x16) = 1;
        func_800171E8(self, 0x1E);
        M2C_FIELD(self, u8*, 6) = 4;
        break;
    case 5:
        func_800171E8(self, 0x20);
        M2C_FIELD(self, u8*, 6) = 5;
        break;
    case 6:
        M2C_FIELD(self, s32*, 0x38) = 0;
        p = D_1F80001C.bytes;
        M2C_FIELD(self, u8**, 0x3C) = p + M2C_FIELD(p, s32*, 4);
        M2C_FIELD(self, void**, 0x30) = D_8007B2E8;
        M2C_FIELD(self, u8*, 0x16) = 1;
        M2C_FIELD(self, u16*, 0x42) = 0x7804;
        M2C_FIELD(self, u16*, 0x40) = 0;
        if (M2C_FIELD(self, u8*, 0x15) == 0x40) {
            M2C_FIELD(self, u16*, 0xA) += 0xA;
        } else {
            M2C_FIELD(self, u16*, 0xA) -= 0xA;
        }
        M2C_FIELD(self, u16*, 0xE) += 0x11;
        func_800171E8(self, 3);
        M2C_FIELD(self, u8*, 6) = 6;
        break;
    case 7:
        func_800171E8(self, 0x23);
        M2C_FIELD(self, u8*, 6) = 7;
        break;
    }
}
