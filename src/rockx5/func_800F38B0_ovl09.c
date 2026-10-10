#include "types.h"

extern s16 D_800FB620_ovl09;
extern s16 D_800FB622_ovl09;
extern s16 D_800FB624_ovl09;
extern ObjFAF38* func_8002D1A4();
extern s32 func_80016490(s32, s32, void*);
extern void func_800171E8(Obj3DD4*, s32);
extern void func_80017248(Obj3DD4*);
extern void func_8002DED4(Obj3DD4*);

void func_800F38B0_ovl09(Obj3DD4* o) {
    ObjFAF38* c;

    if (o->unk15 == 0) {
        if (o->unk20 < 0) {
            if (o->unkA <= D_800FB622_ovl09) {
                o->unkA = D_800FB622_ovl09;
                o->unk20 = 0;
            }
        } else if (o->unk20 > 0) {
            if (o->unkA >= D_800FB622_ovl09) {
                o->unkA = D_800FB622_ovl09;
                o->unk20 = 0;
            }
        }
    } else {
        if (o->unk20 < 0) {
            if (o->unkA <= D_800FB620_ovl09) {
                o->unkA = D_800FB620_ovl09;
                o->unk20 = 0;
            }
        } else if (o->unk20 > 0) {
            if (o->unkA >= D_800FB620_ovl09) {
                o->unkA = D_800FB620_ovl09;
                o->unk20 = 0;
            }
        }
    }
    if (o->unk24 > 0) {
        if (o->unkE <= D_800FB624_ovl09) {
            o->unkE = D_800FB624_ovl09;
            o->unk24 = 0;
        }
    } else if (o->unk24 < 0) {
        if (o->unkE >= D_800FB624_ovl09) {
            o->unkE = D_800FB624_ovl09;
            o->unk24 = 0;
        }
    }
    if ((o->unkA == D_800FB622_ovl09 && o->unk15 == 0) ||
        (o->unkA == D_800FB620_ovl09 && o->unk15 == 0x40)) {
        if (o->unkE == D_800FB624_ovl09) {
            c = func_8002D1A4();
            if (c != 0) {
                func_80016490(2, 0x26, o);
                c->unk0 = 0x41;
                c->unk1 = 0x10;
                c->unk2 = 4;
                c->unk7C = o;
            }
            func_800171E8(o, 6);
            o->unk7C = 0x35;
            o->unk6++;
        }
    }
    func_80017248(o);
    func_8002DED4(o);
}
