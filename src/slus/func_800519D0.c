/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004BEC8.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/quads/quad_03_boss_warning_quad.c:boss_warning_quad_close, AGPL-3.0; proven shared with X6 by exact signature f3f6620a97d2 (see THIRD_PARTY.md). */
#include "types.h"

#define FIXED(x) ((s32)((x) * 0x10000))

extern struct X4_QuadMotionData D_8007B944[22];
extern u8 D_800E9598[0x10];

void func_800519D0(struct X4_QuadObj* arg0) {
    u8 integer = arg0->timer;

    if (integer == 0) {
        arg0->state++;
        if (arg0->unk2 == 0x15) {
            D_800E9598[0] = 0;
        }
    } else {
        struct X4_QuadMotionData* m;
        s32 id = arg0->unk2;

        arg0->timer = integer - 1;
        if (id == 0x15) {
            m = &D_8007B944[id];
            arg0->vertices[0].x.w += FIXED(m->speed[2]);
            arg0->vertices[1].x.w += FIXED(m->speed[2]);
            arg0->vertices[2].x.w += FIXED(m->speed[0]);
            arg0->vertices[3].x.w += FIXED(m->speed[0]);
        } else {
            struct X4_QuadMotionData* b = D_8007B944;
            struct X4_QuadMotionData* n;
            n = &b[id];
            arg0->vertices[1].x.h.hi += n->speed[0] * 2;
            arg0->vertices[0].x.h.hi += n->speed[2] * 2;
            arg0->vertices[1].y.h.hi += n->speed[1] * 2;
            arg0->vertices[0].y.h.hi += n->speed[3] * 2;
        }
    }
}
