/* Shared body (DK-5), from the banked draft of func_800F637C_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80017248(Obj637C*);
extern void func_8002DF54(Obj637C*);
extern s16 D_8009A0AA;
extern Row5C8C D_8009A1F8[];
extern u8 D_800F9D10_ovl11[];
extern u8 D_800F9D14_ovl11[];
extern s16 D_800FA05A_ovl11;

void DEDUP_NAME(Obj637C* obj) {
    Scr2074* s;

    s = D_1F80004C.scr2074;
    if (s->unk93 != 0) {
        if (--s->unk93 == 0 && D_1F80004C.scr2074->unk92 == 5) {
            if (obj->unkA > D_800FA05A_ovl11) {
                obj->unk15 = 0;
                obj->unk20 = 0xFFFC0000;
                obj->unkA = (obj->unk14 + D_8009A1F8)->unkA + 0x1A0;
            } else {
                obj->unk15 = 0x40;
                obj->unk20 = 0x40000;
                obj->unkA = (obj->unk14 + D_8009A1F8)->unkA - 0x60;
            }
        }
    } else {
        if (obj->unkA > D_8009A0AA) {
            obj->unk15 = 0;
        } else {
            obj->unk15 = 0x40;
        }
        obj->unk54 = D_800F9D10_ovl11;
        obj->unk50 = D_800F9D14_ovl11;
        obj->unk3 = 1;
        obj->unk62 = 0;
        func_80017248(obj);
        func_8002DF54(obj);
        if (--obj->unk7C == 0) {
            obj->unk6++;
        }
    }
}
