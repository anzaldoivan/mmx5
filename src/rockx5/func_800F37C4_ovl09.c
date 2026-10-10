#include "types.h"

extern s16 D_800FB620_ovl09;
extern s16 D_800FB622_ovl09;
extern s16 D_800FB624_ovl09;
extern s16 D_800FB62C_ovl09;
extern void func_800171E8(Obj4FE0*, s32);
extern s32 func_8002DFF8(Obj4FE0*, s32, s32);
extern void func_8002E0F8(s32*, s32*, u8);
extern void func_80017248(Obj4FE0*);
extern void func_8002DED4(Obj4FE0*);

void func_800F37C4_ovl09(Obj4FE0* o) {
    if (o->unkA < D_800FB62C_ovl09) {
        func_800171E8(o, 0);
        o->unk15 = 0x40;
        func_8002E0F8(
            &o->unk20, &o->unk24,
            func_8002DFF8(o, D_800FB620_ovl09 << 16, D_800FB624_ovl09 << 16));
        o->unk28 = 0;
        o->unk2C = 0;
        o->unk20 *= 3;
        o->unk24 *= 3;
        o->unk6++;
    } else {
        func_800171E8(o, 0);
        o->unk15 = 0;
        func_8002E0F8(
            &o->unk20, &o->unk24,
            func_8002DFF8(o, D_800FB622_ovl09 << 16, D_800FB624_ovl09 << 16));
        o->unk28 = 0;
        o->unk2C = 0;
        o->unk20 *= 3;
        o->unk24 *= 3;
        o->unk6++;
    }
    func_80017248(o);
    func_8002DED4(o);
}
