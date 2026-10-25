/* Shared body (DK-5), from the banked draft of func_800F3988_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;
extern s16 D_800FA246_ovl03;
extern void func_80017248(Obj3988*);
extern void func_8002DED4(Obj3988*);

void DEDUP_NAME(Obj3988* o) {
    o->unk20 += o->unk84;
    o->unk24 += o->unk88;
    if ((o->unk20 < 0 ? -o->unk20 : o->unk20) > 0x30000) {
        o->unk84 = 0;
    }
    if ((o->unk24 < 0 ? -o->unk24 : o->unk24) > 0x30000) {
        o->unk88 = 0;
    }
    if (o->unk20 < 0) {
        if (o->unkA <= D_800FA240_ovl03) {
            o->unkA = D_800FA240_ovl03;
            goto clr_x; // !FAKE: clamp branches share the target's zeroing tail
        }
    } else if (o->unk20 > 0) {
        if (o->unkA >= D_800FA242_ovl03) {
            o->unkA = D_800FA242_ovl03;
        clr_x:
            o->unk20 = 0;
            o->unk84 = 0;
        }
    }
    if (o->unk24 > 0) {
        if (o->unkE <= D_800FA244_ovl03) {
            o->unkE = D_800FA244_ovl03;
            goto clr_y; // !FAKE: clamp branches share the target's zeroing tail
        }
    } else if (o->unk24 < 0) {
        if (o->unkE >= D_800FA246_ovl03) {
            o->unkE = D_800FA246_ovl03;
        clr_y:
            o->unk24 = 0;
            o->unk88 = 0;
        }
    }
    if (o->unk20 == 0 && o->unk24 == 0) {
        o->unk7C = 0;
        o->unk8F++;
        o->unk6--;
    }
    func_80017248(o);
    func_8002DED4(o);
}
