/* Shared body (DK-5), from the banked draft of func_800F41BC_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl03.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8* func_8002C938();

void DEDUP_NAME(Obj3EEC* o) {
    u8* c;
    s32 i;

    o->unk7C++;
    if (o->unk7E == 0) {
        if (o->unk7C == 20) {
            o->unk7 = 0;
            for (i = 0; i < 3; i++) {
                c = func_8002C938();
                if (c != 0) {
                    c[0] = 0x61;
                    c[1] = 0x39;
                    c[2] = 3;
                    *(Obj3EEC**)(c + 0x80) = o;
                }
            }
            {
                Obj3EEC* p = (Obj3EEC*)g_Player;
                if (p->unkA > o->unkA) {
                    o->unk15 = 0x40;
                } else {
                    o->unk15 = 0;
                }
            }
            o->unk7C = 0;
            o->unk7E++;
        }
    } else if (o->unk7C == 20) {
        if (o->unk7E == 6) {
            set_animation(o, 1);
            o->unk5 = D_800FA0BC_ovl03[o->unk92][o->unk93++];
            o->unk6 = 0;
        } else {
            o->unk7 = 0;
            for (i = 0; i < 3; i++) {
                c = func_8002C938();
                if (c != 0) {
                    c[0] = 0x61;
                    c[1] = 0x39;
                    c[2] = 3;
                    *(Obj3EEC**)(c + 0x80) = o;
                }
            }
            {
                Obj3EEC* p = (Obj3EEC*)g_Player;
                if (p->unkA > o->unkA) {
                    o->unk15 = 0x40;
                } else {
                    o->unk15 = 0;
                }
            }
            o->unk7C = 0;
            o->unk7E++;
        }
    }
    animate_object(o);
    apply_object_motion(o);
}
