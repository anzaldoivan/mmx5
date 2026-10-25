/* Adapted from mmx6 @c1c892d src/shared/rock_02/func_800EC640.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "addr.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800171E8(void*, M2C_UNK);

void func_800F07E8_ovl28(void* arg0) {
    if (--((s8*)D_1F80004C.bytes)[0x80] == 0) {
        switch (((s8*)D_1F80004C.bytes)[0x85] & 0xFE) {
        case 2:
        case 4:
        case 6:
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        case 10:
        case 12:
        case 14:
            if (((s8*)D_1F80004C.bytes)[0x85] >= 10) {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
            func_800171E8(arg0, 4);
            break;
        case 8:
            func_800171E8(arg0, 2);
            break;
        case 18:
        case 20:
        case 22:
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        case 26:
        case 28:
        case 30:
            if (((s8*)D_1F80004C.bytes)[0x85] >= 26) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            }
            func_800171E8(arg0, 5);
            break;
        case 24:
            func_800171E8(arg0, 3);
            break;
        case 0:
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            break;
        case 16:
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            break;
        }
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
