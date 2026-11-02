#include "types.h"

extern void func_80017248(Ent3804*);
extern void func_8002DF54(Ent3804*);
extern void func_800171E8(Ent3804*, s32);
extern X4_S16Pair D_800F9F24_ovl26[][16];

void func_800F3B10_ovl26(Ent3804* o) {
    func_80017248(o);
    func_8002DF54(o);
    if ((*(u8**)((u8*)o + 0x7C))[0x96] == 0) {
        if (o->unk20 < 0) {
            if (o->unkA <= D_800F9F24_ovl26[o->unk94][o->unk2].hi + 0x910) {
                o->unkA = D_800F9F24_ovl26[o->unk94][o->unk2].hi + 0x910;
                func_800171E8(o, 0);
                o->unk6++;
            }
        } else {
            if (o->unkA >= 0xA50 - D_800F9F24_ovl26[o->unk94][o->unk2].hi) {
                o->unkA = 0xA50 - D_800F9F24_ovl26[o->unk94][o->unk2].hi;
                func_800171E8(o, 0);
                o->unk6++;
            }
        }
    } else if (o->unk20 < 0) {
        if (o->unkA <= D_800F9F24_ovl26[o->unk94][o->unk2].hi + 0x8D0) {
            o->unkA = D_800F9F24_ovl26[o->unk94][o->unk2].hi + 0x8D0;
            func_800171E8(o, 0);
            o->unk6++;
        }
    } else {
        if (o->unkA >= 0xA10 - D_800F9F24_ovl26[o->unk94][o->unk2].hi) {
            o->unkA = 0xA10 - D_800F9F24_ovl26[o->unk94][o->unk2].hi;
            func_800171E8(o, 0);
            o->unk6++;
        }
    }
}
