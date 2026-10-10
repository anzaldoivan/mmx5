#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad3[0xB];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[0x10];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ u8 pad2C[0x52];
    /* 0x7E */ s16 unk7E;
    /* 0x80 */ s32 unk80;
    /* 0x84 */ u8 unk84;
    /* 0x85 */ u8 pad85[5];
    /* 0x8A */ u8 unk8A;
    /* 0x8B */ u8 unk8B;
} Obj800EF714;

extern Ent43AC D_800F43AC_ovl02[];
extern void func_800171E8(Obj800EF714*, s32);

void func_800EF714_ovl02(Obj800EF714* o) {
    s32 v;

    v = o->unk24;
    o->unk20 = 0;
    o->unk28 = 0;
    o->unk80 = v;
    if (v > 0) {
        if (o->unk7E -
                ((Ent43AC*)((u8*)D_800F43AC_ovl02 + o->unk2 * 12))->unk8 >=
            o->unkE) {
            o->unk24 = -v;
            o->unk8A = 0;
            o->unk8B = 2;
            func_800171E8(o, 2);
        }
    } else {
        if (o->unkE >=
            o->unk7E +
                ((Ent43AC*)((u8*)D_800F43AC_ovl02 + o->unk2 * 12))->unk8) {
            o->unk24 = -v;
            o->unk8A = 0;
            o->unk8B = 1;
            func_800171E8(o, 1);
        }
    }
    if (o->unk24 != o->unk80) {
        o->unk84 = 0x3C;
        func_800171E8(o, 1);
    }
}
