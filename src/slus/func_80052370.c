/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004C844.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/quads/quad_07_ready_line.c:ready_line_sweep, AGPL-3.0; proven shared with X6 by exact signature 5aa466ee5359 (see THIRD_PARTY.md). */
#include "types.h"
extern int func_80052BA0();
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define FIXED(x) ((s32)((x) * 0x10000))
#define NULL ((void*)0)
void* func_8002D27C();
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
