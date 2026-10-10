#include "types.h"

extern void func_800171E8(Ent448C*, s32);
extern void func_8004FF94(s32, s32, s32, s32);
extern void func_8002D9EC(Ent448C*, s32, s32);
extern void func_80017248(Ent448C*);
extern void func_8002DED4(Ent448C*);
extern s32 func_800317B8(Ent448C*);
extern u8 D_800FAE88_ovl09[];
extern s16 D_800FB668_ovl09;

void func_800F46B4_ovl09(Ent448C* o) {
    Ent448C* p;

    if (o->unk15 == 0) {
        o->unkA = ((Ent448C*)o->unk7C)->unkA + 4;
    } else {
        o->unkA = ((Ent448C*)o->unk7C)->unkA - 4;
    }
    o->unkE = ((Ent448C*)o->unk7C)->unkE + 0x78;
    switch (o->unk5) {
    case 0:
        if (o->unk45 == 1) {
            o->unk50 = D_800FAE88_ovl09;
        }
        p = o->unk7C;
        if (p->unk6 == 4) {
            func_800171E8(o, 5);
            o->unk50 = 0;
            o->unk5 += 1;
        } else if (p->unk5 == 11 || p->unk4 == 2) {
            o->unk50 = 0;
            o->unk6 = 0;
            o->unk5 += 2;
        }
        if ((++o->unk6 & 7) == 0) {
            func_8004FF94(0, o->unkA, D_800FB668_ovl09, 0);
        }
        func_8002D9EC(o, 0x20, 0xC8);
        break;
    case 1:
        if (o->unk46 == 0) {
            o->unk4++;
        }
        func_8002D9EC(o, 0x20, 0xC8);
        break;
    case 2:
        if (++o->unk6 == 10) {
            o->unk4++;
        }
        if (o->unk6 & 1) {
            func_8002D9EC(o, 0x20, 0xC8);
        }
        break;
    }
    func_80017248(o);
    func_8002DED4(o);
    func_800317B8(o);
}
