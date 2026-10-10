#include "types.h"

typedef struct {
    /* 0x00 */ u16 lo;
    /* 0x02 */ u16 hi;
} Ent3CC_Half;

typedef union {
    s32 w;
    Ent3CC_Half h;
} Ent3CC_Fix;

typedef struct {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ s32 x;
    /* 0x0C */ u8 padC[8];
    /* 0x14 */ u8 unk14;
} Ent3CC_Src;

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 pad1;
    /* 0x02 */ signed char unk2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ Ent3CC_Fix x;
    /* 0x0C */ Ent3CC_Fix y;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[9];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ void* unk30;
    /* 0x34 */ u8 pad34[8];
    /* 0x3C */ u8* unk3C;
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[3];
    /* 0x47 */ u8 unk47;
    /* 0x48 */ u8 pad48[0xC];
    /* 0x54 */ void* unk54;
    /* 0x58 */ void* unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 unk61;
    /* 0x62 */ u8 pad62[3];
    /* 0x65 */ u8 unk65;
    /* 0x66 */ u8 pad66[2];
    /* 0x68 */ void* unk68;
    /* 0x6C */ u8 pad6C[9];
    /* 0x75 */ u8 unk75;
    /* 0x76 */ u8 unk76;
    /* 0x77 */ u8 pad77[5];
    /* 0x7C */ u16 unk7C;
    /* 0x7E */ u16 unk7E;
    /* 0x80 */ u8 pad80[4];
    /* 0x84 */ u8 unk84;
    /* 0x85 */ u8 unk85;
    /* 0x86 */ u8 unk86;
    /* 0x87 */ u8 unk87;
    /* 0x88 */ u8 pad88;
    /* 0x89 */ u8 unk89;
    /* 0x8A */ u8 unk8A;
    /* 0x8B */ u8 pad8B[0x17];
    /* 0xA2 */ u8 unkA2;
} Ent3CC;

#define SCR20 (*(u32**)0x1F800020)

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

void func_800EF3CC_ovl26(Ent3CC* o) {
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
