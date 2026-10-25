/* Shared body (DK-5), from the banked draft of func_800EF3CC_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

#define SCR20 D_1F800020.u32s
extern s32 func_8002B5B4(s32);
extern s32 func_8002DF78(void);
extern void func_800171E8(Ent3CC*, s32);
extern void func_800F0318_ovl26(Ent3CC*);
extern Ent3CC_Src D_8009A0A0;
extern u32* D_80098118;
extern u8 D_800F923C_ovl26[];
extern u8 D_800F9238_ovl26[];
extern u8 D_800767E0[];
extern u8 D_800F9214_ovl26[];
extern Ent800F43E8 D_800F9240_ovl26[];
extern Ent800F43E8 D_800F927C_ovl26[];

void DEDUP_NAME(Ent3CC* o) {
    Ent3CC_Src* src;
    u32* t;
    s32 a;
    s32 b;
    signed char k;

    if (o->unk2 == 4) {
        o->unk7 = 1;
        o->unk2 = 1;
    } else {
        o->unk7 = 0;
    }
    o->unk5 = 2;
    o->unk0 = 0x41;
    o->unk4++;
    o->unk6 = o->unk2;
    src = &D_8009A0A0;
    o->unk14 = src->unk14;
    o->unk40 = D_80098118[func_8002B5B4(0x80)] >> 7;
    a = func_8002B5B4(0x80);
    t = SCR20;
    o->unk3C = (u8*)t + t[a];
    a = func_8002B5B4(0x80);
    b = func_8002B5B4(0x80);
    o->unk42 = ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
    o->unk16 = 7;
    o->unk47 = 0;
    o->unk68 = D_800F923C_ovl26;
    o->unk5C = 0;
    o->unk54 = D_800F9238_ovl26;
    o->unk58 = D_800767E0;
    o->unk61 = 0;
    o->unk15 = 0;
    o->unk65 = 0;
    o->unk30 = D_800F9214_ovl26;
    o->unk20 = D_800F9240_ovl26[o->unk2].a;
    o->unk24 = 0x10000;
    o->unk28 = 0;
    o->unk2C = 0;
    o->unk75 = 1;
    o->unk76 = 0;
    o->unk60 = 10;
    o->unk84 = 0;
    o->unk85 = 0;
    o->unk7C = o->x.h.hi;
    o->unk7E = o->y.h.hi;
    o->unk86 = func_8002DF78() & 0x7F;
    o->unk87 = func_8002DF78() & 0x1F;
    o->unk89 = (func_8002DF78() & 0x7E) + 1;
    o->unk8A = 1;
    o->unkA2 = 1;
    if (src->x < o->x.w) {
        o->unk20 = -o->unk20;
    }
    if (o->unk2 != 0) {
        func_800171E8(o, 0);
    } else {
        func_800171E8(o, 1);
    }
    k = o->unk2;
    if (k == 5) {
        o->unk85 = (k >> 4) & 0xF;
        o->x.h.hi = D_800F927C_ovl26[o->unk85].x;
        o->y.h.hi = D_800F927C_ovl26[o->unk85].y;
        func_800F0318_ovl26(o);
    }
}
