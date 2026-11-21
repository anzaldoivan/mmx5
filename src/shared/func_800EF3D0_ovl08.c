#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"

/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800EB10C.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_800750C0;

void func_800EF3D0_ovl08(void* arg0) {
    ((M2C_UNK(*)())animate_object)();
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800750C0;
        ((s32(*)())apply_object_motion)(arg0);
        if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
            ((s32(*)())set_animation)(arg0, 4);
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
        }
    } else if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        ((s32(*)())set_animation)(arg0, 1);
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s8*, 0x67) = 0;
    }
}

void func_800EF478_ovl08(u8* obj) {
    u8* p;

    ((s32(*)())animate_object)(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        *(s8*)(obj + 0x45) = 0;
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 8;
            *(s32*)(p + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(p + 0x42) = *(u16*)(obj + 0x42);
            p[0x14] = obj[0x14];
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            p[0x15] = obj[0x15];
        }
    }
    if (*(s8*)(obj + 0x46) == 0) {
        obj[5] = 1;
        obj[6] = 0;
        ((s32(*)())set_animation)(obj, 1);
        obj[0x83] = 0x78;
        obj[0x80] &= 0xFD;
    }
}

/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800EB2B8.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_800750C0;
extern M2C_UNK D_800F39DC_ovl08;
extern M2C_UNK D_800F39E4_ovl08;

void func_800EF564_ovl08(void* arg0) {
    s32 var_v0;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800750C0;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F39E4_ovl08;
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F39DC_ovl08;
        M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
        ((s32(*)())set_animation)(arg0, 1);
        var_v0 = -0x6000;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            var_v0 = 0x6000;
        }
        M2C_FIELD(arg0, s32*, 0x20) = var_v0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
    }
    animate_object(arg0);
    ((s32(*)())move_object)(arg0);
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        if (M2C_FIELD(arg0, u8*, 0x70) & 1) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x20);
        }
    } else if (M2C_FIELD(arg0, u8*, 0x70) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x20);
    }
}

extern int func_8002D7A0();

void func_800EF64C_ovl08(signed char* arg0) {
    if (arg0[4] == 4) {
        func_8002D7A0(arg0);
    } else {
        func_8002D760(arg0);
    }
}
