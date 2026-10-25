#include "types.h"
#include "addr.h"

extern Obj1334* func_8002D1A4();
extern u8 D_800F5550_ovl05[];

void func_800F1334_ovl05(Obj1334* parent, s16 x, s16 y, u8 kind) {
    Obj1334* child;

    D_1F80004C.scr1334->unk80 = 0;
    child = func_8002D1A4();
    if (child != 0) {
        child->unk0 = 0x41;
        child->unk1 = 0x14;
        child->unk7C = parent;
        child->unk2 = kind;
        child->unk15 = parent->unk15;
        child->unkA = x;
        child->unk8 = 0;
        child->unkE = y;
        child->unkC = 0;
        child->unk42 = parent->unk42 & 0x7FFF;
        child->unk30 = D_800F5550_ovl05;
        child->unk3C = parent->unk3C;
        child->unk40 = parent->unk40;
        child->unk14 = parent->unk14;
        child->unk91 = 1;
        D_1F80004C.scr1334->unk80 = child;
    }
}
