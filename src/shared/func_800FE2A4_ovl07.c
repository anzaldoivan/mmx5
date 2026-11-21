#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 func_800FD530_ovl07(Ent800FE04C*, s32);

void func_800FE2A4_ovl07(Ent800FE04C* o) {
    animate_object(o);
    move_object(o);
    if (func_800FD530_ovl07(o, 0) != 0) {
        o->unk3 = 0;
        o->unkE = o->unk94;
        if (o->unk8D == 0) {
            set_animation(o, 0xE);
        } else {
            set_animation(o, 0x18);
        }
        o->unk8E = 1;
        o->unk6 = 3;
        return;
    }
    ((s32(*)())func_8002FB58)(o);
    if (!(o->unk70 & 8)) {
        return;
    }
    if (o->unk8D == 0) {
        set_animation(o, 0xB);
    } else {
        set_animation(o, 0x18);
    }
    o->unk67 = 0;
    o->unk20 = 0;
    o->unk24 = 0;
    o->unk6++;
}

extern u8 D_80101DD0_ovl07[];
extern u8 D_80101DB8_ovl07[];
extern u8 D_80101DC4_ovl07[];

void func_800FE388_ovl07(ObjFE130* o) {
    s32 one = o->unk45;

    if (one == 1) {
        if (o->unk8D == 0) {
            o->unkE += 12;
            set_animation(o, 14);
        }
        o->unk68 = D_80101DD0_ovl07;
        o->unk50 = D_80101DB8_ovl07;
        o->unk54 = D_80101DC4_ovl07;
        o->unk8D = one;
        o->unk15 = 0;
        if (o->unk88 == 0) {
            o->unk8C = 0;
            o->unk5 = 2;
        } else {
            o->unk8C = one;
            o->unk5 = 3;
        }
        o->unk6 = 0;
    } else {
        animate_object(o);
    }
}

extern u8 D_80101DD0_ovl07[];
extern u8 D_80101DB8_ovl07[];
extern u8 D_80101DC4_ovl07[];

void func_800FE440_ovl07(Ent800FE1E8* o) {
    s32 v = o->unk45;

    if (v == 2) {
        o->unk68 = D_80101DD0_ovl07;
        o->unk50 = D_80101DB8_ovl07;
        o->unk54 = D_80101DC4_ovl07;
        o->unk8D = 1;
        o->unk15 = 0;
        o->unk8C = 0;
        o->unk5 = v;
        o->unk6 = 0;
    }
    animate_object(o);
}
