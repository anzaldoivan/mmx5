/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80035144.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8003A670(void* arg0); /* extern */
M2C_UNK func_8003CD08();        /* extern */
void func_8003D344(void* arg0); /* extern */
M2C_UNK func_8003B65C(void*);   /* extern */
M2C_UNK func_8003D5E0(void*);   /* extern */
extern X4_BackgroundObj D_8009A1F8[3];
extern s8 D_800D1C1C;

void update_stage_entry(void* arg0) {
    X4_BackgroundObj* bg;

    ((void (*)())animate_object)();
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        if (M2C_FIELD(arg0, s8*, 0xCE) != 0) {
            if (--M2C_FIELD(arg0, s8*, 0xCE) == 0) {
                func_8003CD08(arg0);
            }
            move_object(arg0);
            return;
        }
        if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
            func_8003B33C(arg0, 2);
            M2C_FIELD(arg0, s8*, 0x67) = 0;
            bg = D_8009A1F8;
            M2C_FIELD(&bg[0], s8*, 0x44) = 1;
            M2C_FIELD(&bg[1], s8*, 0x44) = 1;
            M2C_FIELD(&bg[2], s8*, 0x44) = 1;
            M2C_FIELD(arg0, s8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
            return;
        }
        move_object(arg0);
        func_8003D344(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        func_8003D5E0(arg0);
        func_8003B65C(arg0);
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        D_800D1C1C = 0;
        if (M2C_FIELD(arg0, s8*, 2) != 0) {
            func_8003D5E0(arg0);
            func_8003B65C(arg0);
        }
        func_8003A670(arg0);
    }
}
