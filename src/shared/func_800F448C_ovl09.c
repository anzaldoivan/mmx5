/* Shared body (DK-5), from the banked draft of func_800F448C_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(Ent448C*, s32);
extern void func_8004FF94(s32, s32, s32, s32);
extern void func_8002D9EC(Ent448C*, s32, s32);
extern void func_80017248(Ent448C*);
extern void func_8002DED4(Ent448C*);
extern s32 func_800317B8(Ent448C*);
extern u8 D_800FAE84_ovl09[];
extern s16 D_800FB664_ovl09;
extern s16 D_800FB666_ovl09;

void DEDUP_NAME(Ent448C* o) {
    Ent448C* p;

    if (o->unk15 == 0) {
        o->unkA = ((Ent448C*)o->unk7C)->unkA - 0x90;
    } else {
        o->unkA = ((Ent448C*)o->unk7C)->unkA + 0x90;
    }
    o->unkE = ((Ent448C*)o->unk7C)->unkE + 0xC;
    switch (o->unk5) {
    case 0:
        if (o->unk45 == 1) {
            o->unk50 = D_800FAE84_ovl09;
        }
        p = o->unk7C;
        if (p->unk6 == 4) {
            func_800171E8(o, 3);
            o->unk50 = 0;
            o->unk5 += 1;
        } else if (p->unk5 == 11 || p->unk4 == 2) {
            o->unk50 = 0;
            o->unk6 = 0;
            o->unk5 += 2;
        }
        if ((++o->unk6 & 7) == 0) {
            if (o->unk15 == 0) {
                func_8004FF94(0, D_800FB664_ovl09, o->unkE, 0);
            } else {
                func_8004FF94(0, D_800FB666_ovl09, o->unkE, 0);
            }
        }
        func_8002D9EC(o, 0xC8, 0x20);
        break;
    case 1:
        if (o->unk46 == 0) {
            o->unk4++;
        }
        func_8002D9EC(o, 0xC8, 0x20);
        break;
    case 2:
        if (++o->unk6 == 10) {
            o->unk4++;
        }
        if (o->unk6 & 1) {
            func_8002D9EC(o, 0xC8, 0x20);
        }
        break;
    }
    func_80017248(o);
    func_8002DED4(o);
    func_800317B8(o);
}
