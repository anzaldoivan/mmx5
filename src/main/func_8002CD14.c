#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern Obj8002CD14 D_800C926C[];

Obj8002CD14* func_8002CD14(Obj8002CD14* p, s32 backward) {
    u8* q;
    s32 i;

    if (backward == 0) {
        if (p == 0) {
            p = g_class4_slots.cd14;
        } else {
            p++;
        }
        for (; p < D_800C9310.cd14; p++) {
            if (p->active == 0) {
                q = (u8*)p;
                for (i = sizeof(Obj8002CD14) - 1; i != -1; i--) {
                    *q++ = 0;
                }
                p->unk50 = 0;
                p->unk54 = 0;
                p->unk68 = 0;
                return p;
            }
        }
    } else {
        if (p == 0) {
            p = D_800C926C;
        } else {
            if (p == g_class4_slots.cd14) {
                return 0;
            }
            p--;
        }
        for (; p >= g_class4_slots.cd14; p--) {
            if (p->active == 0) {
                q = (u8*)p;
                for (i = sizeof(Obj8002CD14) - 1; i != -1; i--) {
                    *q++ = 0;
                }
                p->unk50 = 0;
                p->unk54 = 0;
                p->unk68 = 0;
                return p;
            }
        }
    }
    return 0;
}
