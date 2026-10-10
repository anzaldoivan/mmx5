#include "types.h"

typedef struct {
    u8 pad0[2];
    signed char unk2;
    u8 pad3[4];
    u8 unk7;
    u8 pad8[2];
    s16 unkA;
    u8 padC[0x14];
    s32 unk20;
    s32 unk24;
    u8 pad28[4];
    s32 unk2C;
    u8 pad30[0x4C];
    s16 unk7C;
    u8 pad7E[2];
    s32 unk80;
    u8 unk84;
    u8 pad85[5];
    u8 unk8A;
    u8 unk8B;
} Obj800EF5D8;

extern Ent43AC D_800F43AC_ovl02[];
extern void func_800171E8(Obj800EF5D8*, s32);

void func_800EF5D8_ovl02(Obj800EF5D8* o) {
    s32 v = o->unk20;

    o->unk24 = 0;
    o->unk2C = 0;
    o->unk80 = v;
    if (v > 0) {
        if (o->unkA >= o->unk7C + (D_800F43AC_ovl02 + o->unk2)->unk8) {
            o->unk20 = -v;
            o->unk8A = 0;
            o->unk8B = 3;
            func_800171E8(o, 3);
        }
    } else {
        if (o->unk7C - (D_800F43AC_ovl02 + o->unk2)->unk8 >= o->unkA) {
            o->unk20 = -v;
            o->unk8A = 0;
            o->unk8B = 4;
            func_800171E8(o, 4);
        }
    }
    if (o->unk20 != o->unk80 || o->unk7) {
        if (o->unk7) {
            o->unk20 = 0xFFFF0000;
            o->unk7 = 0;
            o->unk8A = 0;
            o->unk8B = 4;
            o->unk7C += 0x50;
        }
        o->unk84 = 0x3C;
        func_800171E8(o, 1);
    }
}
