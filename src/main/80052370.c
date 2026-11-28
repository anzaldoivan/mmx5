#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004C844.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/quads/quad_07_ready_line.c:ready_line_sweep, AGPL-3.0; proven shared with X6 by exact signature 5aa466ee5359 (see THIRD_PARTY.md). */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define FIXED(x) ((s32)((x) * 0x10000))
#define NULL ((void*)0)
extern u16 D_8007BABC[8];

void func_80052370(struct X4_QuadObj* arg0) {
    u16* verts;
    Ent3CC* temp_s1;
    X4_Obj* misc_obj;
    switch (M2C_FIELD(arg0, s8*, 0x5)) {
    case 0:
        M2C_FIELD(arg0, s8*, 0x5) = 1;
        // set position of blue line that goes left to right before
        // ready text appears
        M2C_FIELD(arg0, s16*, 0xA) = -320;
        M2C_FIELD(arg0, s16*, 0xE) = 112;
        verts = D_8007BABC;
        M2C_FIELD(arg0, s16*, 0x16) = *verts++;
        M2C_FIELD(arg0, s16*, 0x1A) = *verts++;
        M2C_FIELD(arg0, s16*, 0x1E) = *verts++;
        M2C_FIELD(arg0, s16*, 0x22) = *verts++;
        M2C_FIELD(arg0, s16*, 0x26) = *verts++;
        M2C_FIELD(arg0, s16*, 0x2A) = *verts++;
        M2C_FIELD(arg0, s16*, 0x2E) = *verts++;
        M2C_FIELD(arg0, s16*, 0x32) = *verts;
        M2C_FIELD(arg0, s32*, 0x38) = FIXED(32);
        M2C_FIELD(arg0, s32*, 0x3C) = 0;
        M2C_FIELD(arg0, s32*, 0x40) = 0;
        M2C_FIELD(arg0, s32*, 0x44) = 0;
        func_80052BA0(arg0);
        return;
    case 1:
        temp_s1 = M2C_FIELD(arg0, Ent3CC**, 0x58);
        // spawn "READY" text and shadow when blue line reaches center of screen
        if ((M2C_FIELD(arg0, s16*, 0xA) >= 0 &&
             M2C_FIELD(arg0, s16*, 0xA) <= 2) &&
            (temp_s1->unk15 == 0)) {
            misc_obj = func_8002D27C();
            if (misc_obj != NULL) {
                misc_obj->active = 1;
                misc_obj->id = 0x12;
                misc_obj->unk2 = 0;
                temp_s1->unk15 = 0;
                M2C_FIELD(misc_obj, Ent3CC**, 0x50) =
                    M2C_FIELD(arg0, Ent3CC**, 0x58);
            }
            misc_obj = func_8002D27C();
            if (misc_obj != NULL) {
                misc_obj->active = 1;
                misc_obj->id = 0x12;
                misc_obj->unk2 = 1;
                temp_s1->unk15 = 0;
                M2C_FIELD(misc_obj, Ent3CC**, 0x50) =
                    M2C_FIELD(arg0, Ent3CC**, 0x58);
            }
        }
        if (M2C_FIELD(arg0, s16*, 0xA) >= 320) {
            M2C_FIELD(arg0, s8*, 0x5) = 2;
            return;
        }
        func_80052BA0(arg0);
        return;
    case 2:
        temp_s1 = M2C_FIELD(arg0, Ent3CC**, 0x58);
        temp_s1->unk14 = 0;
        arg0->state = 2;
        M2C_FIELD(arg0, s8*, 0x5) = 0;
        return;
    }
}
#undef M2C_FIELD
#undef FIXED
#undef NULL

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004CA08.c, AGPL-3.0 (THIRD_PARTY.md). */

extern u16 D_8007BACC[];
extern u16 D_8007BAE0[][8];
extern u16 D_8007BB80[][8];
extern u16 D_8007BC50;
void func_80052BDC(u8*, u8, u8, u16*);

#define B(o) (*(s8*)(p + (o)))
#define UB(o) (*(u8*)(p + (o)))
#define H(o) (*(u16*)(p + (o)))

void func_80052534(u8* p) {
    u8* q;
    u32 i;
    s32 c;
    u16 d;
    u16 x;
    u16* t;

    switch (B(5)) {
    case 0:
        B(5) = 1;
        H(0xA) = 0;
        H(0x16) = D_8007BACC[B(7)];
        H(0x2E) = D_8007BACC[B(7)];
        H(0x1E) = D_8007BACC[B(7)] + 0x3F;
        H(0x26) = D_8007BACC[B(7)] + 0x3F;
        H(0xE) = 0;
        if (B(7) < 5) {
            H(0x1A) = 0;
            H(0x22) = 0;
            H(0x2A) = 0;
            H(0x32) = 0;
        } else {
            H(0x1A) = 0xF0;
            H(0x22) = 0xF0;
            H(0x2A) = 0xF0;
            H(0x32) = 0xF0;
        }
        B(0x55) = 1;
        B(0x54) = 1;
        B(0x4C) = 0;
        B(0x4D) = 0;
        B(0x4E) = 0;
        B(0x4F) = 0;
        H(0x50) = 8;
        break;
    case 1:
        i = 0;
        q = p + 0x38;
        for (; i < 4; i++) {
            func_80052BDC(p, UB(7), i, &D_8007BAE0[B(7)][i * 2]);
        }
        c = H(0x50) - 1;
        *(u16*)(q + 0x18) = c;
        if (!(c & 0xFFFF)) {
            t = D_8007BAE0[B(7)];
            H(0x16) = *t++;
            H(0x1A) = *t++;
            H(0x1E) = *t++;
            H(0x22) = *t++;
            H(0x26) = *t++;
            H(0x2A) = *t++;
            H(0x2E) = *t++;
            H(0x32) = *t++;
            B(5) = 2;
            B(0x55) = 1;
            B(0x54) = 1;
            B(0x4C) = 0;
            B(0x4D) = 0;
            B(0x4E) = 0;
            B(0x4F) = 0;
            H(0x50) = 8;
        }
        break;
    case 2:
        i = 0;
        q = p + 0x38;
        for (; i < 4; i++) {
            func_80052BDC(p, UB(7), i, &D_8007BB80[B(7)][i * 2]);
        }
        c = H(0x50) - 1;
        *(u16*)(q + 0x18) = c;
        if (!(c & 0xFFFF)) {
            t = D_8007BB80[B(7)];
            H(0x16) = *t++;
            H(0x1A) = *t++;
            H(0x1E) = *t++;
            H(0x22) = *t++;
            H(0x26) = *t++;
            H(0x2A) = *t++;
            H(0x2E) = *t++;
            x = *t;
            B(5) = 3;
            B(0x55) = 1;
            B(0x54) = 1;
            B(0x4C) = 0;
            B(0x4D) = 0;
            B(0x4E) = 0;
            B(0x4F) = 0;
            d = D_8007BC50;
            H(0x50) = 0x10;
            H(0x32) = x;
            if (d != 0) {
                D_8007BC50 = d - 1;
            }
        }
        break;
    case 3:
        *(u8*)(*(u8**)(p + 0x58) + 0x14) = 0;
        B(4) = 2;
        B(5) = 0;
        break;
    }
}

#undef B
#undef UB
#undef H

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004CD3C.c, AGPL-3.0 (THIRD_PARTY.md). */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_8007BC20[];
extern u8 D_8007BC6C[];

void func_80052868(struct X4_QuadObj* arg0) {
    u16* p;
    s32 n;
    u8* t;

    switch (M2C_FIELD(arg0, s8*, 0x5)) {
    case 0:
        t = D_8007BC6C;
        M2C_FIELD(arg0, s8*, 0x5) = 1;
        p = &D_8007BC20[t[random_byte() & 0xF] * 8];
        arg0->vertices[0].x.h.hi = *p++;
        arg0->vertices[0].y.h.hi = *p++;
        arg0->vertices[1].x.h.hi = *p++;
        arg0->vertices[1].y.h.hi = *p++;
        arg0->vertices[2].x.h.hi = *p++;
        arg0->vertices[2].y.h.hi = *p++;
        arg0->vertices[3].x.h.hi = *p++;
        arg0->vertices[3].y.h.hi = *p++;
        n = 1;
        if (random_byte() & 1) {
            n = 2;
        }
        if (random_byte() & 1) {
            M2C_FIELD(arg0, s16*, 0xA) = -0xB0;
            M2C_FIELD(arg0, s32*, 0x38) = n * 0x180000;
            M2C_FIELD(arg0, s32*, 0x3C) = 0;
            M2C_FIELD(arg0, s32*, 0x40) = 0;
            M2C_FIELD(arg0, s32*, 0x44) = 0;
            M2C_FIELD(arg0, u8*, 0x48) = 0;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = 0x1F0;
            M2C_FIELD(arg0, s32*, 0x38) = -(n * 0x180000);
            M2C_FIELD(arg0, s32*, 0x3C) = 0;
            M2C_FIELD(arg0, s32*, 0x40) = 0;
            M2C_FIELD(arg0, s32*, 0x44) = 0;
            M2C_FIELD(arg0, u8*, 0x48) = 1;
        }
        M2C_FIELD(arg0, s16*, 0xE) = (random_byte() & 7) * 4 + 0x68;
        M2C_FIELD(arg0, s16*, 0x52) = M2C_FIELD(arg0, s8*, 0x7) << 3;
        break;
    case 1:
        if (*(u16*)&M2C_FIELD(arg0, s16*, 0x52) != 0) {
            (*(u16*)&M2C_FIELD(arg0, s16*, 0x52))--;
            break;
        }
        if (M2C_FIELD(arg0, u8*, 0x48) == 0) {
            if (M2C_FIELD(arg0, s16*, 0xA) >= 0x140) {
                goto set2; // !FAKE: control flow kept from the mmx6 twin
            }
            goto call; // !FAKE: control flow kept from the mmx6 twin
        }
        if (M2C_FIELD(arg0, s16*, 0xA) < -0xB0) {
        set2:
            M2C_FIELD(arg0, s8*, 0x5) = 2;
            break;
        }
    call:
        func_80052BA0(arg0);
        break;
    case 2:
        ((u8*)M2C_FIELD(arg0, void**, 0x58))[0x14]--;
        arg0->state = 2;
        M2C_FIELD(arg0, s8*, 0x5) = 0;
        break;
    }
}
