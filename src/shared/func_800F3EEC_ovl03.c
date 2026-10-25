/* Shared body (DK-5), from the banked draft of func_800F3EEC_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8* func_8002C938();
extern void func_800171E8(Obj3EEC*, s32);
extern void func_80017248(Obj3EEC*);
extern void func_8002DED4(Obj3EEC*);
extern u8 D_8009A0A0[];
extern u8 D_800FA0BC_ovl03[][6];

void DEDUP_NAME(Obj3EEC* o) {
    u8* c;
    s32 i;

    o->unk7C++;
    if (o->unk7E == 0) {
        if (o->unk7C == 20) {
            o->unk7 = 0;
            for (i = 0; i < 6; i++) {
                c = func_8002C938();
                if (c != 0) {
                    c[0] = 0x61;
                    c[1] = 0x39;
                    c[2] = 2;
                    *(Obj3EEC**)(c + 0x80) = o;
                }
            }
            {
                Obj3EEC* p = (Obj3EEC*)D_8009A0A0;
                if (p->unkA > o->unkA) {
                    o->unk15 = 0x40;
                } else {
                    o->unk15 = 0;
                }
            }
            o->unk7C = 0;
            o->unk7E++;
        }
    } else if (o->unk7C == 120) {
        if (o->unk7E == 3) {
            func_800171E8(o, 1);
            o->unk5 = D_800FA0BC_ovl03[o->unk92][o->unk93++];
            o->unk6 = 0;
        } else {
            o->unk7 = 0;
            for (i = 0; i < 6; i++) {
                c = func_8002C938();
                if (c != 0) {
                    c[0] = 0x61;
                    c[1] = 0x39;
                    c[2] = 2;
                    *(Obj3EEC**)(c + 0x80) = o;
                }
            }
            {
                Obj3EEC* p = (Obj3EEC*)D_8009A0A0;
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
    func_80017248(o);
    func_8002DED4(o);
}
