#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"

/* Adapted from mmx6 @c1c892d src/shared/rock_15/func_800EBAAC.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_80074DA0;
extern s32 D_800F98E8_ovl11;
extern s32 D_800F98EC_ovl11;

void func_800F1210_ovl11(void* arg0) {
    void* temp_v1;

    M2C_FIELD(arg0, u8*, 3) = 1;
    M2C_FIELD(arg0, u8*, 0x60) = 5;
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, void**, 0x50) = &D_800F98E8_ovl11;
    M2C_FIELD(arg0, void**, 0x58) = &D_80074DA0;
    M2C_FIELD(arg0, void**, 0x68) = &D_800F98EC_ovl11;
    M2C_FIELD(arg0, void**, 0x54) = &D_800F98E8_ovl11;
    M2C_FIELD(arg0, u8*, 4)++;
    M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    temp_v1 = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(temp_v1, s16*, 0xA) + 0x1A;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(temp_v1, s16*, 0xA) - 0x1A;
        }
        M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(temp_v1, s16*, 0xE) - 0x23;
    } else {
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(temp_v1, s16*, 0xA) + 0x1A;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(temp_v1, s16*, 0xA) - 0x1A;
        }
        M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(temp_v1, s16*, 0xE) - 0x10;
    }
    set_animation(arg0, 7);
    M2C_FIELD(arg0, u8*, 5) = 0;
    M2C_FIELD(arg0, u8*, 0x8F) = 0x20;
    M2C_FIELD(arg0, u8*, 0x8D) = 0;
    M2C_FIELD(arg0, u8*, 0x8E) = 0;
    M2C_FIELD(arg0, u8*, 0x92) = 0;
    M2C_FIELD(arg0, u8*, 0x90) = 2;
    M2C_FIELD(arg0, u8*, 0x91) = 0;
    M2C_FIELD(arg0, u8*, 0x93) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 1;
    M2C_FIELD(arg0, s8*, 0x8C) = M2C_FIELD(arg0, s8*, 2) * 0x14 + 0x1E;
}

extern u8 D_8009A197;
extern void (*D_800F9918_ovl11[])(u8*);

void func_800F136C_ovl11(u8* a0) {
    *(s32*)(a0 + 0x18) = *(s32*)(a0 + 0x8);
    *(s32*)(a0 + 0x1C) = *(s32*)(a0 + 0xC);
    if (D_8009A197 == 0) {
        D_800F9918_ovl11[*(s8*)(a0 + 5)](a0);
        animate_object(a0);
        apply_object_motion(a0);
    }
    func_800317B8(a0);
    if (func_80031DD0(a0) < 0 ||
        ((*(u8*)(a0 + 0x70) != 0 ||
          (((s32(*)())func_8002FB58)(a0), *(u8*)(a0 + 0x70) != 0)) &&
         *(u8*)(a0 + 0x93) == 1)) {
        ((s32(*)())func_8004FD24)(a0);
        *(u8*)(a0 + 4) += 1;
        return;
    }
    *(u8*)(a0 + 0x70) = 0;
    if (__builtin_abs(*(s32*)(a0 + 0x20)) > 0x40000) {
        *(s32*)(a0 + 0x28) = 0;
    }
    if (is_off_screen(a0, 0x40, 0x20) == 0) {
        func_8002D9EC(a0, 0x20, 0x20);
        return;
    }
    *(u8*)(a0 + 4) += 1;
}

void func_800F14AC_ovl11(u8* p) {
    u8* q;
    u8* b;
    u8* c;
    s32 y;
    s32 d;
    u16 e;

    if (p[0x8D] != 0) {
        if (p[0x8D] == 0x21) {
            p[0x93] = 1;
        }
        p[0x8D]--;
        y = *(s16*)(p + 0xE) + 8;
        b = g_Player;
        d = *(s16*)(b + 0xE) - y;
        if (d >= 0) {
            if (d < 3) {
                *(s32*)(p + 0x24) = 0;
            } else {
                goto cmp; // !FAKE: goto kept for the matching branch layout
            }
        } else if (y - *(s16*)(b + 0xE) >= 3) {
        cmp:
            c = g_Player;
            if (*(s16*)(c + 0xE) - 8 >= *(s16*)(p + 0xE)) {
                *(s32*)(p + 0x24) = -0x20000;
            } else {
                *(s32*)(p + 0x24) = 0x20000;
            }
        } else {
            *(s32*)(p + 0x24) = 0;
        }
    } else {
        *(s32*)(p + 0x24) = 0;
    }
    if (p[0x8E] != 0) {
        p[0x8E]--;
    } else if (p[0x91] != 0) {
        q = func_8002D27C();
        if (q != 0) {
            q[0] = 0x21;
            q[1] = 0x17;
            q[2] = 0;
            q[0x15] = random_byte() & 0x40;
            q[0x54] = 0;
            if (p[0x15] == 0) {
                *(s16*)(q + 0xA) = *(s16*)(p + 0xA) + 0x10;
            } else {
                *(s16*)(q + 0xA) = *(s16*)(p + 0xA) - 0x10;
            }
            e = *(u16*)(p + 0xE);
            *(s32*)(q + 0x20) = 0;
            *(s32*)(q + 0x24) = 0;
            q[7] = 1;
            q[0x16] = 7;
            *(s16*)(q + 0xE) = e;
        }
        p[0x8E] = 1;
    }
}
