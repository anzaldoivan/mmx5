#include "types.h"
#include "mmx5/object.h"

void func_8002CE20(s8 id, s8 arg1) {
    EffectSlot30* p;
    s8 i;

    if (id >= 0) {
        for (i = 0; i < 0x20; i++) {
            p = &g_class3_slots.eff[i];
            if (p->active != 0 && p->id == id && p->unk2 == arg1) {
                p->active = 0;
                p->id = 0;
                p->unk2 = 0;
                p->pad3[0] = 0;
                p->pad3[1] = 0;
                p->pad3[2] = 0;
                p->pad3[3] = 0;
                p->pad3[4] = 0;
            }
        }
    } else {
        id &= 0x7F;
        for (i = 0; i < 0x20; i++) {
            p = &g_class3_slots.eff[i];
            if (p->active != 0 && p->id == id) {
                p->active = 0;
                p->id = 0;
                p->unk2 = 0;
                p->pad3[0] = 0;
                p->pad3[1] = 0;
                p->pad3[2] = 0;
                p->pad3[3] = 0;
                p->pad3[4] = 0;
            }
        }
    }
}
