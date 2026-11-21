#include "types.h"
#include "mmx5/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define D_800D1C28_as_u8 (*(u8*)&D_800D1C28)

void func_800F4A18_ovl24(void* arg0) {
    if (D_800D1C28_as_u8 == 0xFF) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    if ((M2C_FIELD(arg0, s8*, 6) == 0) &&
        ((s8)D_800D1C28_as_u8 >= (s32)M2C_FIELD(arg0, u8*, 0x54))) {
        M2C_FIELD(arg0, s8*, 3) = 1;
        M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
    }
}
#undef M2C_FIELD
#undef D_800D1C28_as_u8

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define D_800D1C28_as_u8 (*(u8*)&D_800D1C28)

void func_800F4A70_ovl24(void* arg0) {
    if (D_800D1C28_as_u8 == 0x7F) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    if ((M2C_FIELD(arg0, s8*, 6) == 0) &&
        ((s8)D_800D1C28_as_u8 >= (s32)M2C_FIELD(arg0, u8*, 0x54))) {
        M2C_FIELD(arg0, s8*, 3) = 1;
        M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
    }
}
#undef M2C_FIELD
#undef D_800D1C28_as_u8

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define D_800D1C28_as_u8 (*(u8*)&D_800D1C28)

void func_800F4AC8_ovl24(void* arg0) {
    if (D_800D1C28_as_u8 == 0x7F) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        if ((s8)D_800D1C28_as_u8 >= (s32)M2C_FIELD(arg0, u8*, 0x54)) {
            M2C_FIELD(arg0, s8*, 3) = 1;
            M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
        }
    } else if (M2C_FIELD(arg0, s8*, 6) == 1) {
        M2C_FIELD(arg0, s8*, 3) = 1;
    }
}
#undef M2C_FIELD
#undef D_800D1C28_as_u8

#include "shared/func_800F4B38_ovl24.c"

#define D_800F5A1C_ovl24 D_800F5A24_ovl24

#define func_800F4B38_ovl24 func_800F4BCC_ovl24
#include "shared/func_800F4B38_ovl24.c"
#undef func_800F4B38_ovl24
#undef D_800F5A1C_ovl24

#define D_800F5A1C_ovl24 D_800F5A30_ovl24

#define func_800F4B38_ovl24 func_800F4C60_ovl24
#include "shared/func_800F4B38_ovl24.c"
#undef func_800F4B38_ovl24
#undef D_800F5A1C_ovl24

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define D_800D1C28_as_u8 (*(u8*)&D_800D1C28)

void func_800F4CF4_ovl24(void* arg0) {
    if (D_800D1C28_as_u8 & 0x40) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        if ((s8)D_800D1C28_as_u8 >= (s32)M2C_FIELD(arg0, u8*, 0x54)) {
            M2C_FIELD(arg0, s8*, 3) = 1;
            M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
        }
    }
}
