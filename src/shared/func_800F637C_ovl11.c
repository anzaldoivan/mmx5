#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"

extern u8 D_800F9D10_ovl11[];
extern u8 D_800F9D14_ovl11[];
extern s16 D_800FA05A_ovl11;

void func_800F637C_ovl11(Obj637C* obj) {
    Scr2074* s;

    s = D_1F80004C.scr2074;
    if (s->unk93 != 0) {
        if (--s->unk93 == 0 && D_1F80004C.scr2074->unk92 == 5) {
            if (obj->unkA > D_800FA05A_ovl11) {
                obj->unk15 = 0;
                obj->unk20 = 0xFFFC0000;
                obj->unkA = (obj->unk14 + D_8009A1F8.row)->unkA + 0x1A0;
            } else {
                obj->unk15 = 0x40;
                obj->unk20 = 0x40000;
                obj->unkA = (obj->unk14 + D_8009A1F8.row)->unkA - 0x60;
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
        animate_object(obj);
        move_object(obj);
        if (--obj->unk7C == 0) {
            obj->unk6++;
        }
    }
}
