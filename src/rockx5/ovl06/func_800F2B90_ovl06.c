/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800F2588.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#define g_Player_as_s32 (*(s32*)&g_Player)

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

X4_Obj* find_free_visual_obj(void);
void func_800F0C8C_ovl06(void* arg0);
void func_800F0EB4_ovl06(void* arg0);

void func_800F2B90_ovl06(void* arg0) {
    void* o;

    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        M2C_FIELD(arg0, u8*, 6) = 1;
        ((void (*)(void*, s32))set_animation)(arg0, 0xC);
        if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            u8* p = (u8*)&g_Player_as_s32;
            M2C_FIELD(p, u8*, 0xD8) = 0x34;
            M2C_FIELD(p, u8*, 6) = 0;
        }
        func_800F0C8C_ovl06(arg0);
        return;
    }
    M2C_FIELD(arg0, u8*, 6) = 4;
    o = find_free_visual_obj();
    if (o != 0) {
        M2C_FIELD(o, u8*, 0) = 0x41;
        M2C_FIELD(o, u8*, 1) = 0x16;
        M2C_FIELD(o, u8*, 2) = 0x10;
        M2C_FIELD(o, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(o, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(o, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(o, u8*, 0x16) = M2C_FIELD(arg0, u8*, 0x16);
        M2C_FIELD(o, void**, 0x50) = arg0;
        M2C_FIELD(o, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
    }
    ((void (*)(void*, s32))set_animation)(arg0, 0xE);
    if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
        u8* p = (u8*)&g_Player_as_s32;
        M2C_FIELD(p, u8*, 0xD8) = 0x40;
        M2C_FIELD(p, u8*, 6) = 0;
    }
    M2C_FIELD(arg0, u8*, 0x7E) = 8;
    func_800F0EB4_ovl06(arg0);
}
