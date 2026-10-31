#include "types.h"

#define FIXED(x) ((s32)((x) * 0x10000))

extern struct X4_QuadMotionData D_8007B944[22];
extern u8 D_800E9598[0x10];

void func_800518B4(struct X4_QuadObj* arg0) {
    u8 integer = arg0->timer;

    if (integer == 0) {
        ((u8*)arg0)[5]++;
        if (arg0->unk2 == 0x15) {
            D_800E9598[0] = 1;
        }
    } else {
        struct X4_QuadMotionData* m;
        s32 id = arg0->unk2;

        arg0->timer = integer - 1;
        if (id == 0x15) {
            m = &D_8007B944[id];
            arg0->vertices[0].x.w += FIXED(m->speed[0]);
            arg0->vertices[1].x.w += FIXED(m->speed[0]);
            arg0->vertices[2].x.w += FIXED(m->speed[2]);
            arg0->vertices[3].x.w += FIXED(m->speed[2]);
        } else {
            struct X4_QuadMotionData* b = D_8007B944;
            struct X4_QuadMotionData* n;
            n = &b[id];
            arg0->vertices[2].x.h.hi += n->speed[0] * 2;
            arg0->vertices[3].x.h.hi += n->speed[2] * 2;
            arg0->vertices[2].y.h.hi += n->speed[1] * 2;
            arg0->vertices[3].y.h.hi += n->speed[3] * 2;
        }
    }
}
