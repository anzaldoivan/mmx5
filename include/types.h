/* types.h — the canonical type layer: widths and signedness from bytes, names
 * only with evidence (G62). Compiler: gcc 2.95.2-psx with -D__CHAR_UNSIGNED__,
 * so a signed byte must be spelled `signed char`. One definition per shape:
 * `make types-check` (tools/dedup/shapes.py) refuses dups and raw casts. */
#ifndef TYPES_H
#define TYPES_H

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

// from slus 80012D88
typedef struct {
    s16 state;
    u8 pad2[0xA];
    s32 work;
    s32 buf;
    u8 pad14[0x5C];
    u8 flag;
    u8 pad71[0xF];
} Slot; /* 0x80 */

// from slus 80012D88
typedef struct {
    u8 d[0xC0];
} Blk;

// from slus 80012D88
typedef struct {
    u8 pad[0x110];
    Blk* blk;
} LowMem; /* fixed low-RAM block at address 0 */

// from slus 800132F8
typedef struct {
    u8 pad0[4];
    s8 busy;
    s8 arg;
} Ctl;

// from rockx5 800F2448
typedef struct {
    u8 pad0[6];
    u8 step;
    u8 pad7[0x75];
    s16 timer;
} Obj;

// from rockx5 800F2688 (shared with 800EFE98)
typedef struct {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5[0x7C - 0x05];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ s16 unk7E;
} Obj800F2688;

// D_8009A1F8: union of the views from rockx5 800F7F84, 800FA244, 800FA66C, 800F5E5C, 800F8EF0
typedef struct {
    u8 pad0[0xA];
    u16 unkA;
    u8 padC[2];
    u16 unkE;
    u8 pad10[0x26 - 0x10];
    u16 unk26;
    u16 unk28;
    u16 unk2A;
    u8 pad2C[0x48 - 0x2C];
    u8 unk48;
    u8 pad49[0x57 - 0x49];
    u8 unk57;
    u8 pad58[6];
    s16 unk5E;
    u8 pad60[2];
    s16 unk62;
    u8 pad64[0x3C];
    u8 unkA0;
    u8 padA1[0x15];
    u16 unkB6;
    u8 padB8[0x3C];
    u8 unkF4;
} D_8009A1F8_t;

// from rockx5 800FA244 (shared with 800FA66C)
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3[7];
    s16 unkA;
    u8 padC[2];
    s16 unkE;
    u8 pad10[0x44];
    u8 unk54;
} UnkSpawn;

// from rockx5 800FA244 (shared with 800FA66C)
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 pad2[2];
    s16 unk4;
    s16 unk6;
} UnkObj;

// from rockx5 800FA5B4 (shared with 800FADE0)
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 pad2[2];
    s16 unk4;
} Ovl45State;

// from rockx5 800FA3C0 (shared with 800FAE80)
typedef struct {
    u8 pad0;
    u8 step;
} Actor50;

// from slus 800487F8 (shared with rockx5 800F14C8)
typedef struct {
    signed char a;
    signed char b;
    u8 c;
    u8 d;
} Unk800770CC;

// from rockx5 800FE04C (shared with rockx5 800FE2A4)
typedef struct Ent800FE04C {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[2];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[7];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[0x10];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[0x3F];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ u8 pad68[8];
    /* 0x70 */ u8 unk70;
    /* 0x71 */ u8 pad71[0x1C];
    /* 0x8D */ u8 unk8D;
    /* 0x8E */ u8 unk8E;
    /* 0x8F */ u8 pad8F[5];
    /* 0x94 */ u16 unk94;
} Ent800FE04C;

// from rockx5 800FDA54 (shared with rockx5 800FDBC0)
typedef struct Ovl07Ent {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ signed char unk6;
    /* 0x07 */ u8 pad7[0x19];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[0x54];
    /* 0x7C */ void *unk7C; /* an Ovl07Ent */
    /* 0x80 */ u8 pad80[0xE];
    /* 0x8E */ u8 unk8E;
} Ovl07Ent;

// from rockx5 800FA284 (shared with rockx5 800F9CF8)
typedef struct {
    u8 pad0[6];
    u8 step;
    u8 pad7[0x49];
    void* p50;
    void* p54;
    u8 pad58[0x18];
    u8 flags70;
    u8 pad71[0xB];
    s16 timer;
} ObjFA284;

// from rockx5 800FE130 (shared with rockx5 800FE388)
typedef struct ObjFE130 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[7];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[5];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x2F];
    /* 0x45 */ signed char unk45;
    /* 0x46 */ u8 pad46[0xA];
    /* 0x50 */ void *unk50;
    /* 0x54 */ void *unk54;
    /* 0x58 */ u8 pad58[0x10];
    /* 0x68 */ void *unk68;
    /* 0x6C */ u8 pad6C[0x1C];
    /* 0x88 */ s16 unk88;
    /* 0x8A */ u8 pad8A[2];
    /* 0x8C */ u8 unk8C;
    /* 0x8D */ u8 unk8D;
} ObjFE130;

// from rockx5 800F14C8 (shared with rockx5 800F228C)
typedef struct {
    u8 pad0[0x83];
    u8 flags83;
    Unk800770CC box;
    u16 cnt88;
} Scr4C;

// from rockx5 800F14C8 (shared with rockx5 800F228C)
typedef struct {
    u8 pad0[5];
    u8 state;
    u8 pad6[4];
    u16 x;
    u8 padC[2];
    u16 y;
    u8 pad10[5];
    u8 dir;
    u8 pad16[0xA];
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    u8 pad30[0x40];
    u8 flags70;
} Ent14C8;

// from rockx5 800EFA30 (shared with rockx5 800F78F4)
typedef struct {
    u8 pad0[0xA];
    s16 xA;
    u8 padC[2];
    s16 xE;
    u8 pad10[0x10];
    s32 x20;
    s32 x24;
    u8 pad28[0x4A];
    u8 x72;
    u8 pad73[0xD];
    s32 x80;
    u8 pad84;
    u8 x85;
} Obj800EFA30;

// from rockx5 800EFA30 (shared with rockx5 800F78F4)
typedef struct {
    s32 a;
    s32 b;
    u16 x;
    u16 y;
} Ent800F43E8;

// from rockx5 800FE1E8 (shared with rockx5 800FE440)
typedef struct Ent800FE1E8 {
    /* 0x00 */ u8 pad0[0x5];
    /* 0x05 */ s8 unk5;
    /* 0x06 */ s8 unk6;
    /* 0x07 */ u8 pad7[0x15 - 0x7];
    /* 0x15 */ s8 unk15;
    /* 0x16 */ u8 pad16[0x45 - 0x16];
    /* 0x45 */ s8 unk45;
    /* 0x46 */ u8 pad46[0x50 - 0x46];
    /* 0x50 */ void *unk50;
    /* 0x54 */ void *unk54;
    /* 0x58 */ u8 pad58[0x68 - 0x58];
    /* 0x68 */ void *unk68;
    /* 0x6C */ u8 pad6C[0x8C - 0x6C];
    /* 0x8C */ s8 unk8C;
    /* 0x8D */ s8 unk8D;
} Ent800FE1E8;

// from rockx5 800F3DD4 (shared with rockx5 800F40A8)
typedef struct Obj3DD4 {
    u8 pad0[6];
    u8 unk6;
    u8 pad7[3];
    s16 unkA;
    u8 padC[2];
    s16 unkE;
    u8 pad10[5];
    u8 unk15;
    u8 pad16[0xA];
    s32 unk20;
    s32 unk24;
    u8 pad28[0x54];
    s16 unk7C;
    s16 unk7E;
} Obj3DD4;

// from rockx5 800EFEF4 (shared with rockx5 800F9CF8)
typedef struct Ent {
    u8 pad0[6];
    u8 state;
    u8 pad7[3];
    s16 y;
    u8 padC[9];
    u8 flag15;
} Ent;

// from rockx5 800F08D8 (shared with rockx5 800F0EC8)
typedef struct Ent08D8 {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x20 - 7];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 pad30[0x67 - 0x30];
    u8 unk67;
    u8 pad68[0x70 - 0x68];
    u8 unk70;
} Ent08D8;

// from rockx5 800F02E4 (shared with rockx5 800F2BEC)
typedef struct Ob5 {
    u8 pad0[6];
    u8 b6;
    u8 pad7[0x45 - 7];
    s8 b45;
} Ob5;

// from rockx5 800FDC6C (shared with rockx5 800FDB00)
typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0xE - 7];
    u16 unkE;
    u8 pad10[0x68 - 0x10];
    u8 *unk68;
    u8 pad6C[0x8C - 0x6C];
    u8 unk8C;
} EntFDC6C;

// from rockx5 800F0F18 (shared with rockx5 800F0E04)
typedef struct Ctx0F18 {
    u8 pad0[0x80];
    signed char unk80;
} Ctx0F18;

// from rockx5 800EF5D8 (shared with rockx5 800EF714, 800EF81C): D_800F43AC_ovl02 entries
typedef struct {
    u8 pad0[8];
    u16 unk8;
    u8 padA[2];
} Ent43AC; /* 0xC */

// from rockx5 800F4FE0 (shared with rockx5 800F45E4)
typedef struct Obj4FE0 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[5];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
} Obj4FE0;

// from rockx5 800F06BC (shared with rockx5 800F07E0)
typedef struct {
    u8 pad0[5];
    u8 u5;
    u8 u6;
    u8 pad7[7];
    u16 uE;
    u8 pad10[0x10];
    s32 u20;
    s32 u24;
    s32 u28;
    s32 u2C;
    u8 pad30[0x37];
    u8 u67;
    u8 *u68;
} Ent06BC;

// from slus 80022FF0 (shared with rockx5 800F7360)
typedef struct {
    u8 pad0[0x18];
    s32 unk18;
    s32 unk1C;
} Unk80022FF0Src;

// from rockx5 800FE4F8 (shared with rockx5 800FE74C)
typedef struct EntFE4F8 {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[2];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[0x14];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[0x3F];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ u8 pad68[8];
    /* 0x70 */ u8 unk70;
    /* 0x71 */ u8 pad71[0x1C];
    /* 0x8D */ u8 unk8D;
    /* 0x8E */ u8 unk8E;
    /* 0x8F */ u8 pad8F[3];
    /* 0x92 */ u16 unk92;
} EntFE4F8;

// from rockx5 800F8EF0 (shared with rockx5 800F7858)
typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x5C - 7];
    signed char unk5C;
    u8 pad5D[0x7C - 0x5D];
    s16 unk7C;
    u8 pad7E[0x94 - 0x7E];
    u16 unk94;
} Ent8EF0;

// from rockx5 800F0900 (shared with rockx5 800F0A24)
typedef struct {
    u8 pad0[5];
    u8 u5;
    u8 u6;
    u8 pad7[3];
    u16 uA;
    u8 padC[0x14];
    s32 u20;
    s32 u24;
    s32 u28;
    s32 u2C;
    u8 pad30[0x37];
    u8 u67;
    u8 *u68;
} Ent0900;

// from rockx5 800F7360 (shared with rockx5 800FC2E8)
typedef struct {
    u8 pad0[0x9A];
    signed char unk9A;
} Unk800F7360Arg;

// from slus 8002D27C (shared with slus 8002D2DC, 8002D33C)
typedef struct Slot8002D27C {
    s8 active;
    u8 pad[0x5F];
} Slot8002D27C;

// from rockx5 800FAF38 (shared with rockx5 800F2194): spawned child copies the parent's position/state
typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[5];
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x1B];
    /* 0x30 */ s32 unk30;
    /* 0x34 */ u8 pad34[8];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0x38];
    /* 0x7C */ void *unk7C; /* the parent ObjFAF38 */
} ObjFAF38;

// from rockx5 800F6234 (shared with rockx5 800F6150)
typedef struct Ent6234 {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x7C - 7];
    s16 unk7C;
    u8 pad7E[0x96 - 0x7E];
    u8 unk96;
    u8 unk97;
} Ent6234;

// from rockx5 800F6B44 (shared with rockx5 800F6D08)
typedef struct Ent6B44 {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[0x14 - 6];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x20 - 0x17];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ void *unk30;
    /* 0x34 */ u8 pad34[0x3C - 0x34];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0x50 - 0x44];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 pad61[0x67 - 0x61];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x7C - 0x6C];
    /* 0x7C */ void *unk7C; /* an Ent6B44 */
} Ent6B44;

// from shared 800F0470_ovl12 (shared with rockx5 800F00FC_ovl12)
typedef struct Obj0470 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x3F];
    /* 0x46 */ s8 unk46;
    /* 0x47 */ u8 pad47[0x35];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ u8 pad7E[8];
    /* 0x86 */ u8 unk86;
    /* 0x87 */ u8 unk87;
} Obj0470;

// from slus 8002D0E4 (shared with slus 8002D43C)
typedef struct Slot8002D0E4 {
    s8 active;
    u8 pad[0x6F];
} Slot8002D0E4;

// from rockx5 800F5820: countdown timer at 0x7C reloads to 0x28, repeat count at 0x7E (shared with rockx5 800F5950)
typedef struct {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x7C - 0x07];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ s16 unk7E;
} Obj5820;

// from rockx5 800F2BF8 (shared with rockx5 800F2C70)
typedef struct Ent2BF8 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[4];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[0x20 - 0xC];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x70 - 0x24]; /* 0x24/0x2C stored by raw offset: a /s store lets D_8009A0AA float above */
    /* 0x70 */ u8 unk70;
} Ent2BF8;

// from rockx5 800F0B1C (shared with rockx5 800F0E88)
typedef struct Scr0B1C {
    /* 0x00 */ u8 pad0[0x80];
    /* 0x80 */ s8 unk80;
    /* 0x81 */ u8 pad81[4];
    /* 0x85 */ s8 unk85;
} Scr0B1C;

// from rockx5 800EF018 (shared with rockx5 800EF268, 800F0014)
typedef struct Ovl25State {
    u8 pad0[2];
    u8 unk2;
    u8 pad3;
    s16 unk4;
} Ovl25State;

// from slus 8002D144 (shared with slus 8002D69C)
typedef struct Slot8002D144 {
    s8 active;
    u8 pad[0x2F];
} Slot8002D144;

// from shared 800F657C (shared with rockx5 800F0C8C)
typedef struct Ent657C {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[0x42 - 6];
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0x61 - 0x44];
    /* 0x61 */ u8 unk61;
    /* 0x62 */ u8 pad62[0x7C - 0x62];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ s16 unk7E;
} Ent657C;

// from shared 800F9364 (shared with rockx5 800F8ADC)
typedef struct Ent9364 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x46 - 7];
    /* 0x46 */ s8 unk46;
    /* 0x47 */ u8 pad47[0x8D - 0x47];
    /* 0x8D */ u8 unk8D;
    /* 0x8E */ u8 unk8E;
} Ent9364;

// from rockx5 800EF4C4 (shape shared with 800EF47C, 800EF39C)
typedef struct Obj800EF4C4 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ signed char unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[2];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[0x54 - 0x10];
    /* 0x54 */ s16 unk54;
    /* 0x56 */ s16 unk56;
    /* 0x58 */ s16 unk58;
} Obj800EF4C4;

// from rockx5 800F170C (shared with rockx5 800F15FC)
typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0xE - 7];
    u16 unkE;
    u8 pad10[0x68 - 0x10];
    u8 *unk68;
    u8 pad6C[0x8F - 0x6C];
    u8 unk8F;
} Ent170C;

// from rockx5 800FA2E0 (shared with W10 draft 800FA1C0)
/* 0x200-byte block copied from the scratchpad buffer */
typedef struct {
    u8 d[0x200];
} Blk200;

// from rockx5 800F3EEC (shared with W10 draft 800F41BC)
typedef struct Obj3EEC {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u8 pad8[2];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x66];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ s16 unk7E;
    /* 0x80 */ u8 pad80[0x12];
    /* 0x92 */ u8 unk92;
    /* 0x93 */ u8 unk93;
} Obj3EEC;

// from rockx5 800F66A0 (shared with W10 draft 800F6EE4)
typedef struct Obj66A0 {
    u8 pad0[4];
    s8 unk4;
    s8 unk5;
    u8 pad6[4];
    s16 unkA;
    u8 padC[2];
    s16 unkE;
    u8 pad10[5];
    u8 unk15;
    u8 pad16[0xA];
    s32 unk20;
    s32 unk24;
    u8 pad28[0x1A];
    u16 unk42;
    u8 pad44[0x38];
    s16 unk7C;
    u8 pad7E[2];
    Ctl *unk80;
} Obj66A0;

// from rockx5 800F448C (shared with W10 draft 800F46B4)
typedef struct Ent448C {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ signed char unk4;
    /* 0x05 */ signed char unk5;
    /* 0x06 */ signed char unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[5];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x2F];
    /* 0x45 */ signed char unk45;
    /* 0x46 */ signed char unk46;
    /* 0x47 */ u8 pad47[9];
    /* 0x50 */ void *unk50;
    /* 0x54 */ u8 pad54[0x28];
    /* 0x7C */ void *unk7C; /* an Ent448C */
} Ent448C;

// from rockx5 800EF780 (shared with W10 draft 800F0408)
typedef struct Pl780 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[0x87 - 0x10];
    /* 0x87 */ u8 unk87;
    /* 0x88 */ u8 pad88[2];
    /* 0x8A */ s16 unk8A;
} Pl780;

// from rockx5 800EF780 (shared with W10 draft 800F0408)
typedef struct Scr780 {
    /* 0x00 */ u8 pad0[0x80];
    /* 0x80 */ Pl780 *unk80;
    /* 0x84 */ u8 pad84[0x90 - 0x84];
    /* 0x90 */ u8 unk90;
} Scr780;

// from rockx5 800EF780 (shared with W10 draft 800F0408)
typedef struct Self780 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[0x70 - 0x10];
    /* 0x70 */ u8 unk70;
} Self780;

// from rockx5 func_800F6BF4_ovl09 (shared with W11 draft)
typedef struct Ent6BF4 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ signed char unk4;
    /* 0x05 */ signed char unk5;
    /* 0x06 */ u8 pad6[0xA - 6];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[0x45 - 0x10];
    /* 0x45 */ signed char unk45;
    /* 0x46 */ signed char unk46;
    /* 0x47 */ u8 pad47[0x7C - 0x47];
    /* 0x7C */ void *unk7C; /* an Ent6BF4 */
} Ent6BF4;

// from slus func_800218E0 (shared with W11 draft)
/* 0x7 read as signed (lb) and as unsigned (lbu) */
typedef union {
    signed char s;
    u8 u;
} Byte800218E0;

// from slus func_800218E0 (shared with W11 draft)
typedef struct {
    u8 pad0[4];
    signed char unk4;
    u8 pad5[2];
    Byte800218E0 unk7;
} Sel800218E0;

// from slus func_800218E0 (shared with W11 draft)
typedef struct {
    u8 pad0[4];
    u16 unk4;
} Pad800218E0;

// from slus func_800218E0 (shared with W11 draft)
typedef struct {
    u8 pad0;
    u8 unk1;
    u8 pad2[6];
    s16 unk8;
} Arg800218E0;

// from slus func_80030820 (shared with W11 draft)
typedef struct {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ signed char unk14;
    /* 0x15 */ u8 pad15[0x68 - 0x15];
    /* 0x68 */ u8 *unk68;
} Obj80030820;

// from rockx5 func_800EF078_ovl05 (shared with W11 draft)
typedef struct Ent2 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
} Ent2;

// from rockx5 func_800F4EA0_ovl29 (shared with W11 draft)
typedef struct Obj4EA0 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x50 - 0x16];
    /* 0x50 */ void *unk50;
} Obj4EA0;

// from rockx5 func_800F5C8C_ovl11 (shared with W11 draft)
typedef struct Obj5C8C {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ signed char unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[0x38];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 pad61;
    /* 0x62 */ u8 unk62;
} Obj5C8C;

// from rockx5 func_800F5C8C_ovl11 (shared with W11 draft)
typedef struct Row5C8C {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[0x54 - 0xC];
} Row5C8C; /* 0x54 */

typedef struct Ent800FE23CParent {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
} Ent800FE23CParent;

typedef struct Ent800FE23C {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[4];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[0x70];
    /* 0x80 */ Ent800FE23CParent *unk80;
    /* 0x84 */ u8 pad84[4];
    /* 0x88 */ u16 unk88;
    /* 0x8A */ u16 unk8A;
    /* 0x8C */ u8 pad8C[2];
    /* 0x8E */ u8 unk8E;
} Ent800FE23C;

typedef struct Scr3594 {
    /* 0x00 */ u8 pad0[0x82];
    /* 0x82 */ s16 unk82;
    /* 0x84 */ u8 unk84;
} Scr3594;

typedef struct Gm1C00 {
    /* 0x00 */ u8 pad0[0x47];
    /* 0x47 */ u8 lim[0x2F];
    /* 0x76 */ u8 cnt[8];
    /* 0x7E */ u16 flags;
} Gm1C00;

/* lift: struct/union definitions lifted from src/ by tools/readability/lift.py */

/* src/rockx5/func_800EEBEC_ovl05.c */
typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ s8 unk4;
    /* 0x05 */ s8 unk5;
    /* 0x06 */ s8 unk6;
    /* 0x07 */ u8 pad7[0xD];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ s8 unk16;
    /* 0x17 */ u8 pad17[0x19];
    /* 0x30 */ void* unk30;
    /* 0x34 */ u8 pad34[0x1C];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ void* unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ s8 unk60;
    /* 0x61 */ u8 unk61;
    /* 0x62 */ u8 pad62[6];
    /* 0x68 */ void* unk68;
} ObjEEBEC;

/* src/rockx5/func_800EEE5C_ovl12.c */
typedef struct ObjEE5C {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x15];
    /* 0x45 */ s8 unk45;
    /* 0x46 */ s8 unk46;
    /* 0x47 */ u8 pad47[0x29];
    /* 0x70 */ u8 unk70;
    /* 0x71 */ u8 pad71[0xB];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ u8 pad7E[8];
    /* 0x86 */ u8 unk86;
    /* 0x87 */ u8 unk87;
} ObjEE5C;

/* src/rockx5/func_800EEE84_ovl05.c */
typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad3[2];
    /* 0x05 */ s8 unk5;
    /* 0x06 */ s8 unk6;
    /* 0x07 */ u8 pad7;
    /* 0x08 */ s32 x; /* 16.16, integer half at 0x0A */
    /* 0x0C */ s32 y; /* 16.16, integer half at 0x0E */
} ObjEEE84;

/* src/rockx5/func_800EEE84_ovl05.c */
typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[5];
    /* 0x08 */ s32 x; /* 16.16, integer half at 0x0A */
    /* 0x0C */ s32 y; /* 16.16, integer half at 0x0E */
    /* 0x10 */ u8 pad10[0x6C];
    /* 0x7C */ ObjEEE84* parent;
    /* 0x80 */ u8 pad80[4];
    /* 0x84 */ s32 unk84;
} SpawnEEE84;

/* src/rockx5/func_800EF078_ovl05.c */
typedef struct Scr80 {
    /* 0x00 */ u8 pad0[0x80];
    /* 0x80 */ s16 unk80;
    /* 0x82 */ s16 unk82;
    /* 0x84 */ u8 pad84[2];
    /* 0x86 */ s8 unk86;
} Scr80;

/* src/rockx5/func_800EF0C8_ovl02.c */
// from rockx5 800EF0C8_ovl02
typedef struct Obj0C8 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ signed char unk2;
    /* 0x03 */ u8 pad3[3];
    /* 0x06 */ signed char unk6;
    /* 0x07 */ u8 pad7[0x20 - 7];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[0x72 - 0x28];
    /* 0x72 */ u8 unk72;
    /* 0x73 */ u8 pad73[3];
    /* 0x76 */ signed char unk76;
    /* 0x77 */ u8 pad77[0x84 - 0x77];
    /* 0x84 */ u8 unk84;
    /* 0x85 */ u8 pad85[5];
    /* 0x8A */ u8 unk8A;
    /* 0x8B */ u8 unk8B;
} Obj0C8;

/* src/rockx5/func_800EF0C8_ovl02.c */
// from rockx5 800EF0C8_ovl02: D_8009A0A0 view
typedef struct Scr0C8 {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[0x24 - 0x10];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[0xF3 - 0x28];
    /* 0xF3 */ signed char unkF3;
    /* 0xF4 */ u8 padF4[4];
    /* 0xF8 */ u8 unkF8;
    /* 0xF9 */ u8 padF9;
    /* 0xFA */ u8 unkFA;
} Scr0C8;

/* src/rockx5/func_800EF2C8_ovl05.c */
typedef struct Scr85 {
    /* 0x00 */ u8 pad0[0x85];
    /* 0x85 */ s8 unk85;
    /* 0x86 */ s8 unk86;
} Scr85;

/* src/rockx5/func_800F1468_ovl26.c, func_800F1D84_ovl26.c: scratchpad 0x1F80004C pointee */
typedef struct Scr84 {
    /* 0x00 */ u8 pad0[0x80];
    /* 0x80 */ s32 unk80;
    /* 0x84 */ u8 unk84;
    /* 0x85 */ u8 unk85;
    /* 0x86 */ u8 unk86;
} Scr84;

/* src/rockx5/func_800F1468_ovl26.c */
typedef struct {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8* unk30;
    /* 0x34 */ u8 pad34[0x1C];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ u8* unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ s8 unk60;
    /* 0x61 */ u8 unk61;
    /* 0x62 */ u8 pad62[5];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ s32 unk68;
} Ent1468;

/* src/rockx5/func_800F1468_ovl26.c: player D_8009A0A0 view */
typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad3[0x11];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0xFC - 0x15];
    /* 0xFC */ u32 unkFC;
} Plr1468;

/* src/rockx5/func_800F1D84_ovl26.c */
typedef struct {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
} Ent1D84;

/* src/rockx5/func_800F3804_ovl26.c */
typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad3[3];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[0x14];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x70];
    /* 0x94 */ u8 unk94;
} Ent3804;

/* src/rockx5/func_800EF3CC_ovl26.c */
typedef struct {
    /* 0x00 */ u16 lo;
    /* 0x02 */ u16 hi;
} Ent3CC_Half;

/* src/rockx5/func_800EF3CC_ovl26.c */
typedef union {
    s32 w;
    Ent3CC_Half h;
} Ent3CC_Fix;

/* src/rockx5/func_800EF3CC_ovl26.c */
typedef struct {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ s32 x;
    /* 0x0C */ u8 padC[8];
    /* 0x14 */ u8 unk14;
} Ent3CC_Src;

/* src/rockx5/func_800EF3CC_ovl26.c */
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

/* src/rockx5/func_800EF424_ovl05.c */
typedef struct ObjF424 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 state;
    /* 0x05 */ u8 pad5[0x70 - 5];
    /* 0x70 */ u8 unk70;
    /* 0x71 */ u8 pad71[0x84 - 0x71];
    /* 0x84 */ s32 unk84;
} ObjF424;

/* src/rockx5/func_800EF5D8_ovl02.c */
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

/* src/rockx5/func_800EF608_ovl03.c */
typedef struct ObjEF608 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x20 - 0x7];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x50 - 0x24];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ u8 pad58[0x80 - 0x58];
    /* 0x80 */ s32 unk80;
} ObjEF608;

/* src/rockx5/func_800EF680_ovl05.c */
typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5[5];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[9];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ u8 pad34[8];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0xC];
    /* 0x50 */ void* unk50; /* same ObjEF680 shape */
} ObjEF680;

/* src/rockx5/func_800EF714_ovl02.c */
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

/* src/rockx5/func_800EF81C_ovl02.c */
// from rockx5 800EF81C
typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5[7];
    /* 0x0C */ s32 unkC; /* 16.16; hi half also stored as s16 at 0x0E */
    /* 0x10 */ u8 pad10[0x14];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[4];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x46];
    /* 0x76 */ s8 unk76;
    /* 0x77 */ u8 pad77[7];
    /* 0x7E */ s16 unk7E;
    /* 0x80 */ u8 pad80[4];
    /* 0x84 */ u8 unk84;
    /* 0x85 */ u8 unk85;
    /* 0x86 */ u8 unk86;
    /* 0x87 */ u8 unk87;
    /* 0x88 */ u8 unk88;
    /* 0x89 */ u8 unk89;
} Obj800EF81C;

/* src/rockx5/func_800EFC90_ovl12.c */
typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0xE - 7];
    u16 unkE;
    u8 pad10[0x5C - 0x10];
    signed char unk5C;
    u8 pad5D[0x7C - 0x5D];
    s16 unk7C;
    u8 pad7E[0x94 - 0x7E];
    u16 unk94;
} EntFC90;

/* src/rockx5/func_800EFE34_ovl12.c */
typedef struct Ovl12Obj {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x85 - 7];
    u8 unk85;
    u8 unk86;
    u8 unk87;
} Ovl12Obj;

/* src/rockx5/func_800F001C_ovl12.c */
typedef struct Obj001C {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x30];
    /* 0x46 */ s8 unk46;
    /* 0x47 */ u8 pad47[0x35];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ u8 pad7E[8];
    /* 0x86 */ u8 unk86;
    /* 0x87 */ u8 unk87;
} Obj001C;

/* src/rockx5/func_800F01A8_ovl28.c */
typedef struct Ent01A8 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ signed char unk2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[7];
    /* 0x0E */ u16 unkE;
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
    /* 0x34 */ u8 pad34[0x1C];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ void* unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 unk61;
    /* 0x62 */ u8 pad62[5];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x10];
    /* 0x7C */ u8 unk7C;
} Ent01A8;

/* src/rockx5/func_800F01A8_ovl28.c */
typedef struct Scr01A8 {
    /* 0x00 */ u8 pad0[0x81];
    /* 0x81 */ u8 unk81;
    /* 0x82 */ u8 pad82[7];
    /* 0x89 */ u8 unk89;
    /* 0x8A */ u8 unk8A;
    /* 0x8B */ u8 unk8B;
    /* 0x8C */ u8 pad8C[2];
    /* 0x8E */ u16 unk8E;
    /* 0x90 */ s32 unk90;
    /* 0x94 */ s32 unk94;
} Scr01A8;

/* src/rockx5/func_800F06BC_ovl04.c */
typedef struct {
    u8 b[8];
} D80101480_t;

/* src/rockx5/func_800F079C_ovl12.c */
typedef struct Obj079C {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x16];
    /* 0x46 */ s8 unk46;
    /* 0x47 */ u8 pad47[0x29];
    /* 0x70 */ u8 unk70;
    /* 0x71 */ u8 pad71[0xB];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ u8 pad7E[8];
    /* 0x86 */ u8 unk86;
    /* 0x87 */ u8 unk87;
} Obj079C;

/* src/rockx5/func_800F092C_ovl28.c */
// from rockx5 800F092C
typedef struct {
    u8 pad0[2];
    signed char unk2;
    u8 pad3[2];
    signed char unk5;
    u8 unk6;
    u8 pad7[3];
    s16 unkA;
    u8 padC[0x67 - 0xC];
    signed char unk67;
} Obj092C;

/* src/rockx5/func_800F092C_ovl28.c */
// from rockx5 800F092C
typedef struct {
    u8 pad0[0x81];
    signed char unk81;
    u8 pad82[0x89 - 0x82];
    u8 unk89;
} Scr092C;

/* src/rockx5/func_800F0B1C_ovl01.c */
typedef struct Obj0B1C {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad3[3];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
} Obj0B1C;

/* src/rockx5/func_800F0CA4_ovl10.c */
typedef struct {
    u8 pad0[0x82];
    u8 flags82;
    u8 pad83;
    Unk800770CC box;
} Scr82;

/* src/rockx5/func_800F0E88_ovl01.c */
typedef struct Obj0E88 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[14];
    /* 0x15 */ u8 unk15;
} Obj0E88;

/* src/rockx5/func_800F0E9C_ovl28.c */
typedef struct Obj0E9C {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[3];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0xE];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x37];
    /* 0x67 */ u8 unk67;
} Obj0E9C;

/* src/rockx5/func_800F1090_ovl01.c */
// from rockx5 800F1090
typedef struct Scr1090 {
    /* 0x00 */ u8 pad0[0x85];
    /* 0x85 */ signed char unk85;
    /* 0x86 */ u8 unk86;
    /* 0x87 */ u8 unk87;
    /* 0x88 */ u8 unk88;
} Scr1090;

/* src/rockx5/func_800F1344_ovl28.c */
// from rockx5 800F1344: scratchpad context, signed count at 0x82
typedef struct Scr1344 {
    /* 0x00 */ u8 pad0[0x82];
    /* 0x82 */ signed char unk82;
} Scr1344;

/* src/rockx5/func_800F1564_ovl04.c */
typedef struct Ent1564 {
    u8 pad0[5];
    u8 state; /* 0x05 */
    u8 sub;   /* 0x06 */
    u8 pad7[0x16 - 7];
    u8 field16; /* 0x16 */
    u8 pad17[0x7C - 0x17];
    s16 timer; /* 0x7C */
} Ent1564;

/* src/rockx5/func_800F15AC_ovl26.c */
typedef struct Ent15AC {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[0x14];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[0x54];
    /* 0x7C */ s16 unk7C;
} Ent15AC;

/* src/rockx5/func_800F1818_ovl09.c */
// from rockx5 800F1818
typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0xA - 7];
    u16 unkA;
    u8 padC[0x68 - 0xC];
    u8* unk68;
    u8 pad6C[0x8F - 0x6C];
    u8 unk8F;
} Ent1818;

/* src/rockx5/func_800F1884_ovl10.c */
typedef struct Obj1884 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x58 - 0x7];
    /* 0x58 */ void* unk58;
} Obj1884;

/* src/rockx5/func_800F1D74_ovl01.c */
typedef struct {
    signed char x;
    signed char y;
} OffF1D74;

/* src/rockx5/func_800F1D74_ovl01.c */
typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ signed char unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5[5];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[9];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ u8 pad34[8];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0xC];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ void* unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 pad61[6];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ void* unk68;
    /* 0x6C */ u8 pad6C[0x10];
    /* 0x7C */ void* unk7C; /* an EntF1D74 */
} EntF1D74;

/* src/rockx5/func_800F299C_ovl10.c */
// from rockx5 800F299C (twin of rockx5 800F1818)
typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0xA - 7];
    u16 unkA;
    u8 padC[0x68 - 0xC];
    u8* unk68;
    u8 pad6C[0x90 - 0x6C];
    u8 unk90;
} Ent299C;

/* src/rockx5/func_800F3594_ovl07.c */
typedef struct Ent3594 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[8];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[0x14];
    /* 0x24 */ s32 unk24;
} Ent3594;

/* src/rockx5/func_800F3620_ovl07.c */
typedef struct Ent3620 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[8];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[0x14];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[4];
    /* 0x2C */ s32 unk2C;
} Ent3620;

/* src/rockx5/func_800F36AC_ovl07.c */
typedef struct Scr36AC {
    /* 0x00 */ u8 pad0[0x80];
    /* 0x80 */ s16 unk80;
    /* 0x82 */ u8 pad82[2];
    /* 0x84 */ u8 unk84;
} Scr36AC;

/* src/rockx5/func_800F3700_ovl03.c */
typedef struct Obj3700 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[0x10];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
} Obj3700;

/* src/rockx5/func_800F4460_ovl29.c */
typedef struct Ovl29Obj {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x8D - 7];
    u8 unk8D;
    u8 unk8E;
    u8 unk8F;
} Ovl29Obj;

/* src/rockx5/func_800F57B4_ovl09.c */
typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x5C - 7];
    signed char unk5C;
    u8 pad5D[0x7C - 0x5D];
    s16 unk7C;
} Ent57B4;

/* src/rockx5/func_800F5954_ovl09.c */
typedef struct Ent5954 {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x95 - 7];
    u8 unk95;
    u8 unk96;
    u8 unk97;
} Ent5954;

/* src/rockx5/func_800F59B0_ovl09.c */
typedef struct {
    u8 pad0[6];
    signed char unk6;
    u8 pad7[0xA - 7];
    s16 unkA;
    u8 padC[0x15 - 0xC];
    u8 unk15;
} Ent59B0;

/* src/rockx5/func_800F5B3C_ovl09.c */
typedef struct Ent5B3C {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[7];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[0x14];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[4];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x96 - 0x30];
    /* 0x96 */ u8 unk96;
    /* 0x97 */ u8 unk97;
} Ent5B3C;

/* src/rockx5/func_800F5B40_ovl18.c */
typedef struct Obj5B40 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ signed char unk4;
    /* 0x05 */ u8 pad5[0x14 - 0x5];
    /* 0x14 */ void* unk14; /* an Obj5B40 */
} Obj5B40;

/* src/rockx5/func_800F5C8C_ovl11.c */
typedef struct Scr5C8C {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ signed char unk2;
    /* 0x03 */ u8 pad3[7];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[0xFA - 0x10];
    /* 0xFA */ u8 unkFA;
} Scr5C8C;

/* src/rockx5/func_800F5D4C_ovl03.c */
typedef struct Obj5D4C {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[3];
    s16 unkA;
    u8 padC[2];
    s16 unkE;
    u8 pad10[5];
    u8 unk15;
    u8 pad16[0xA];
    s32 unk20;
    s32 unk24;
    u8 pad28[0x68];
    u8 unk90;
} Obj5D4C;

/* src/rockx5/func_800F5E5C_ovl04.c */
typedef struct {
    u8 pad0[2];
    s8 unk2;
    u8 unk3;
    u8 unk4;
    u8 pad5[2];
    u8 unk7;
    u8 pad8[2];
    s16 unkA;
    u8 padC[2];
    s16 unkE;
    u8 pad10[6];
    u8 unk16;
    u8 pad17[9];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 pad30[0x17];
    u8 unk47;
} Obj5E5C;

/* src/rockx5/func_800F5F2C_ovl09.c */
typedef struct Ent5F2C {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[7];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[0x14];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[0x96 - 0x28];
    /* 0x96 */ u8 unk96;
    /* 0x97 */ u8 unk97;
} Ent5F2C;

/* src/rockx5/func_800F5F70_ovl11.c */
typedef struct Scr5F70 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ signed char unk2;
    /* 0x03 */ u8 pad3[0xB];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[0xFA - 0x10];
    /* 0xFA */ u8 unkFA;
} Scr5F70;

/* src/rockx5/func_800F62C8_ovl09.c */
typedef struct Ent62C8 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ signed char unk6;
    /* 0x07 */ u8 pad7[0x8D];
    /* 0x94 */ u8 unk94;
} Ent62C8;

/* src/rockx5/func_800F6E78_ovl04.c */
typedef struct Ob6E78 {
    /* 0x00 */ u8 x0;
    /* 0x01 */ u8 x1;
    /* 0x02 */ signed char x2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ u8 x4;
    /* 0x05 */ u8 x5;
    /* 0x06 */ u8 x6;
    /* 0x07 */ u8 pad7[0xE - 0x7];
    /* 0x0E */ u16 xE;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ u8 x14;
    /* 0x15 */ u8 x15;
    /* 0x16 */ u8 x16;
    /* 0x17 */ u8 pad17[0x24 - 0x17];
    /* 0x24 */ s32 x24;
    /* 0x28 */ u8 pad28[0x50 - 0x28];
    /* 0x50 */ void* x50;
    /* 0x54 */ void* x54;
    /* 0x58 */ void* x58;
    /* 0x5C */ u8 pad5C[0x60 - 0x5C];
    /* 0x60 */ u8 x60;
    /* 0x61 */ u8 x61;
    /* 0x62 */ u8 pad62[0x65 - 0x62];
    /* 0x65 */ u8 x65;
    /* 0x66 */ u8 x66;
    /* 0x67 */ u8 pad67;
    /* 0x68 */ void* x68;
    /* 0x6C */ u8 pad6C[0x75 - 0x6C];
    /* 0x75 */ u8 x75;
    /* 0x76 */ u8 pad76[0x7C - 0x76];
    /* 0x7C */ void* x7C; /* an Ob6E78 */
    /* 0x80 */ u8 pad80[0x82 - 0x80];
    /* 0x82 */ u8 x82;
    /* 0x83 */ u8 x83;
    /* 0x84 */ u8 pad84[0x90 - 0x84];
    /* 0x90 */ signed char x90;
    /* 0x91 */ u8 pad91[0xA2 - 0x91];
    /* 0xA2 */ u8 xA2;
} Ob6E78;

/* src/rockx5/func_800F6E78_ovl04.c */
typedef struct {
    u16 h;
    u16 pad;
    s32 v;
} Ent6E78;

/* src/rockx5/func_800F7360_ovl28.c */
typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 pad6[2];
    s32 unk8;
    s32 unkC;
    u8 pad10[0x44];
    s16 unk54;
    u8 pad56[6];
    Unk80022FF0Src* unk5C;
} Unk800F7360Obj;

/* src/rockx5/func_800F79F0_ovl03.c */
typedef struct Ent79F0 {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x91 - 7];
    u8 unk91;
    u8 unk92;
    u8 unk93;
} Ent79F0;

/* src/rockx5/func_800F7CB0_ovl03.c */
typedef struct Ent7CB0 {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x7C - 7];
    s16 unk7C;
    u8 pad7E[0x92 - 0x7E];
    u8 unk92;
    u8 unk93;
} Ent7CB0;

/* src/rockx5/func_800F8140_ovl03.c */
typedef struct Obj8140 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ signed char unk6;
    /* 0x07 */ u8 pad7[0x89];
    /* 0x90 */ u8 unk90;
} Obj8140;

/* src/rockx5/func_800F8AA8_ovl06.c */
typedef struct Obj8AA8 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x20];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
} Obj8AA8;

/* src/rockx5/func_800F8EF4_ovl00.c */
// from rockx5 800F8EF4: timer at 0x7C, table row 0x8D, column 0x8E
typedef struct Ent8EF4 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x7C - 0x07];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ u8 pad7E[0x8D - 0x7E];
    /* 0x8D */ u8 unk8D;
    /* 0x8E */ u8 unk8E;
} Ent8EF4;

/* src/rockx5/func_800FA154_ovl40.c */
/* D_8009A1F8 view: the word at 0xB0; its high half is also stored as the s16 at 0xB2 */
typedef struct {
    u8 pad0[0xB0];
    s32 unkB0;
} D_8009A1F8_B0_t;

/* src/rockx5/func_800FA678_ovl53.c */
/* D_8009A1F8 view: the word at 0x8; its high half is also stored as the s16 at 0xA */
typedef struct {
    u8 pad0[0x8];
    s32 unk8;
} D_8009A1F8_8_t;

/* src/rockx5/func_800FAE80_ovl50.c */
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Ovl50Pos;

/* src/rockx5/func_800FAF30_ovl28.c */
// from rockx5 800FAF30_ovl28
typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ s8 unk4;
    /* 0x05 */ s8 unk5;
    /* 0x06 */ u8 pad6[2];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[5];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[2];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 pad20[0x18];
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u8 pad40[7];
    /* 0x47 */ u8 unk47;
    /* 0x48 */ u8 pad48[8];
    /* 0x50 */ void* unk50;
    /* 0x54 */ s16 unk54;
    /* 0x56 */ s16 unk56;
    /* 0x58 */ s16 unk58;
    /* 0x5A */ u8 pad5A[0x40];
    /* 0x9A */ s8 unk9A;
} ObjFAF30;

/* src/rockx5/func_800FC038_ovl06.c */
typedef struct Obj800FC038 {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ s8 unk3;
    /* 0x04 */ s8 unk4;
    /* 0x05 */ s8 unk5;
    /* 0x06 */ u8 pad6[0x50 - 0x6];
    /* 0x50 */ void* unk50;
} Obj800FC038;

/* src/rockx5/func_800FC2E8_ovl06.c */
typedef struct {
    u8 pad0[6];
    u8 unk6;
    u8 pad7;
    s32 unk8;
    s32 unkC;
    u8 pad10[0x44];
    s16 unk54;
    u8 pad56[6];
    Unk80022FF0Src* unk5C;
} Unk800FC2E8Obj;

/* src/rockx5/func_800FE308_ovl34.c */
typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0xA - 7];
    u16 unkA;
    u8 padC[0x68 - 0xC];
    u8* unk68;
    u8 pad6C[0x8C - 0x6C];
    u8 unk8C;
} EntFE308;

/* src/shared/func_800EFCD8_ovl03.c */
typedef struct Ent800EFCD8 {
    u8 pad0[0x8];
    s32 x;
    u8 pad1[0x15 - 0xC];
    u8 unk15;
} Ent800EFCD8;

/* src/shared/func_800F0248_ovl11.c */
typedef struct Ent0248 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5[2];
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u8 pad8[0x68 - 0x8];
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x87 - 0x6C];
    /* 0x87 */ u8 unk87;
} Ent0248;

/* src/shared/func_800F0404_ovl05.c */
typedef struct Ent0404 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x45 - 0x7];
    /* 0x45 */ signed char unk45;
    /* 0x46 */ u8 pad46[0x67 - 0x46];
    /* 0x67 */ u8 unk67;
} Ent0404;

/* src/shared/func_800F0418_ovl00.c */
// from rockx5 800F0418: halves of the s32 at 0x88
typedef struct Half0418 {
    u16 lo;
    s16 hi;
} Half0418;

/* src/shared/func_800F0418_ovl00.c */
// from rockx5 800F0418: 0x88 read as s32 (lw) and its high half as s16 (lh 0x8A)
typedef union Fix0418 {
    s32 w;
    Half0418 h;
} Fix0418;

/* src/shared/func_800F0418_ovl00.c */
// from rockx5 800F0418
typedef struct Scr0418 {
    /* 0x00 */ u8 pad0[0x86];
    /* 0x86 */ u8 unk86;
    /* 0x87 */ u8 unk87;
    /* 0x88 */ Fix0418 unk88;
    /* 0x8C */ s32 unk8C;
} Scr0418;

/* src/shared/func_800F05DC_ovl12.c */
typedef struct Obj05DC {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[4];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x15];
    /* 0x45 */ signed char unk45;
} Obj05DC;

/* src/shared/func_800F0D1C_ovl28.c */
typedef struct Ent800F0D1C {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[4];
    /* 0x0A */ s16 y;
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
} Ent800F0D1C;

/* src/shared/func_800F0DA0_ovl28.c */
typedef struct Ent0DA0 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x15 - 7];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x20 - 0x16];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x67 - 0x30];
    /* 0x67 */ u8 unk67;
} Ent0DA0;

/* src/shared/func_800F0E04_ovl28.c */
typedef struct Ent0E04 {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
} Ent0E04;

/* src/shared/func_800F0F18_ovl28.c */
typedef struct Ent0F18 {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x67 - 7];
    signed char unk67;
} Ent0F18;

/* src/shared/func_800F0FC8_ovl28.c */
typedef struct Ent0FC8 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ signed char unk2;
    /* 0x03 */ u8 pad3[3];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x20 - 7];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
} Ent0FC8;

/* src/shared/func_800F1040_ovl28.c */
typedef struct Ctx1040 {
    u8 pad0[0x80];
    signed char unk80;
    u8 pad81;
    signed char unk82;
} Ctx1040;

/* src/shared/func_800F10C8_ovl28.c */
typedef struct Scr10C8 {
    /* 0x00 */ u8 pad0[0x80];
    /* 0x80 */ s8 unk80;
    /* 0x81 */ u8 pad81[2];
    /* 0x83 */ s8 unk83;
} Scr10C8;

/* src/shared/func_800F12BC_ovl04.c */
typedef struct Ent12BC {
    u8 pad0[5];
    u8 state; /* 0x05 */
    u8 sub;   /* 0x06 */
    u8 pad7[0x7C - 7];
    s16 timer; /* 0x7C */
} Ent12BC;

/* src/shared/func_800F150C_ovl28.c */
typedef struct {
    /* 0x00 */ Obj4FE0 b;
    /* 0x30 */ u8 pad30[0x7C - 0x30];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ s16 unk7E;
} Obj150C;

/* src/shared/func_800F2CE8_ovl02.c */
// rockx5 800F2CE8: child copies parent's 0x50/0x15/0xA/0xE, advances step
typedef struct Ent2CE8 {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5[5];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[5];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x50 - 0x16];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ u8 pad54[0x60 - 0x54];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 pad61[0x7C - 0x61];
    /* 0x7C */ void* unk7C; /* the parent Ent2CE8 */
} Ent2CE8;

/* src/shared/func_800F5C58_ovl27.c */
typedef struct Ent800F5C58 {
    u8 pad0[0xA];
    s16 unkA;
    u8 padC[0x15 - 0xC];
    u8 unk15;
} Ent800F5C58;

/* src/shared/func_800FA4F8_ovl50.c */
typedef struct {
    u8 pad0[0x60];
    s32 unk60;
} D_8009A1F8_60_t;

/* src/shared/func_800FAFFC_ovl06.c */
// from rockx5 800FAFFC: spawned child copies the parent's state, keeps the parent at 0x50
typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[5];
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x1A];
    /* 0x30 */ s32 unk30;
    /* 0x34 */ u8 pad34[8];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0xC];
    /* 0x50 */ void* unk50; /* the parent */
} ObjFAFFC;

/* src/shared/func_800FC308_ovl07.c */
typedef struct ObjFC308 {
    u8 pad0[0x7C];
    s16 timer; /* 0x7C */
} ObjFC308;

/* src/slus/func_80022FF0.c */
typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 pad6[2];
    s32 unk8;
    s32 unkC;
    u8 pad10[0x40];
    Unk80022FF0Src* unk50;
    s16 unk54;
} Unk80022FF0Obj;

/* src/slus/func_80022FF0.c */
typedef struct {
    u8 pad0[0x8C];
    signed char unk8C;
} Unk80022FF0Arg;

/* src/slus/func_80029E78.c */
typedef struct {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[6];
    /* 0x16 */ s16 unk16;
    /* 0x18 */ u8 pad18[2];
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ u8 pad1C[0x24];
    /* 0x40 */ u16 unk40;
} Obj29E78;

/* src/slus/func_8002CC08.c */
typedef struct {
    s8 active;
    u8 pad1[0x4F];
    s32 unk50;
    s32 unk54;
    u8 pad58[0x10];
    s32 unk68;
    u8 pad6C[0x30];
} Obj8002CC08;

/* src/slus/func_8002CD14.c */
typedef struct {
    s8 active;
    u8 pad1[0x4F];
    s32 unk50;
    s32 unk54;
    u8 pad58[0x10];
    s32 unk68;
    u8 pad6C[0x38];
} Obj8002CD14;

/* src/slus/func_80030A0C.c */
typedef struct {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ signed char unk14;
} Obj80030A0C;

/* src/slus/func_800487F8.c */
typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 pad6[4];
    s16 unkA;
    u8 padC[2];
    s16 unkE;
    u8 pad10[5];
    u8 unk15;
    u8 pad16[10];
    s32 unk20;
    s32 unk24;
    u8 pad28[0x1D];
    u8 unk45;
    u8 pad46[0xA];
    s32* unk50;
    u8 pad54[0x14];
    Unk800770CC* unk68;
    u8 pad6C[0x23];
    u8 unk8F;
    s16 unk90;
    s16 unk92;
    u8 unk94;
    u8 unk95;
} Ent487F8;

/* src/slus/func_8004A364.c */
typedef struct {
    u8 pad0[4];
    s8 state;
} Ent8004A364;

/* src/slus/func_80050880.c */
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 pad7;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    u8 pad10[5];
    u8 unk15;
    u8 pad16[0xA];
    s32 unk20;
    s32 unk24;
    u8 pad28[0x34];
    u8 unk5C;
} Obj80050880;

/* src/slus/func_80019C4C.c (adapted from sozud/mmx4 @29b62af, AGPL-3.0, THIRD_PARTY.md) */
struct X4_DrawInfo {
    u8 pad0[0x70];
    u32 ot; /* ordering_table.start */
};

/* src/slus/func_80019C4C.c */
typedef struct {
    u32 tag; /* addr : 24, len : 8 */
    u8 r0;
    u8 g0;
    u8 b0;
    u8 code;
} X4_P_TAG;

/* src/slus/func_8001EB84.c */
struct X4_GameInfo {
    u8 pad0[0x1];
    s8 mode;
    u8 pad2[0xE];
};

/* src/slus/func_800519D0.c */
struct X4_QuadVertex {
    Ent3CC_Fix x;
    Ent3CC_Fix y;
};

/* src/slus/func_800519D0.c */
struct X4_QuadObj {
    u8 pad0[0x2];
    s8 unk2;
    u8 pad3;
    s8 state;
    u8 pad5[0xF];
    struct X4_QuadVertex vertices[4];
    u8 pad34[0x9];
    u8 timer; /* 0x3D */
};

/* src/slus/func_800519D0.c */
struct X4_QuadMotionData {
    u8 pad0[0x8];
    s8 speed[4];
};

/* src/rockx5/func_800F01A0_ovl08.c */
typedef struct Obj01A0 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 state;
    /* 0x06 */ u8 substate;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 x;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 y;
    /* 0x10 */ u8 pad10[5];
    /* 0x15 */ u8 facing;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 vx;
    /* 0x24 */ s32 vy;
    /* 0x28 */ s32 ay;
    /* 0x2C */ u8 pad2C[0x44];
    /* 0x70 */ u8 hitFlags;
    /* 0x71 */ u8 pad71[0xB];
    /* 0x7C */ s16 timer7C;
    /* 0x7E */ u8 pad7E[4];
    /* 0x82 */ u8 timer82;
    /* 0x83 */ u8 pad83;
    /* 0x84 */ s32 posX;
    /* 0x88 */ u8 fast;
    /* 0x89 */ u8 timer89;
    /* 0x8A */ u8 pad8A[2];
    /* 0x8C */ s32 timer8C;
} Obj01A0;

/* src/rockx5/func_800F01A0_ovl08.c */
typedef struct Player01A0 {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ s32 posX;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 y;
} Player01A0;

/* src/rockx5/func_800F01A0_ovl08.c */
typedef struct PlayerA01A0 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ s16 x;
} PlayerA01A0;

/* src/rockx5/func_800F1A84_ovl26.c */
typedef struct {
    u8 pad0[3];
    u8 x3;
    u8 pad4[2];
    u8 x6;
    u8 pad7[3];
    s16 xA;
    u8 padC[2];
    s16 xE;
    u8 pad10[5];
    u8 x15;
    u8 pad16[0x3A];
    s32 x50;
    s32 x54;
} Obj1A84;

/* src/rockx5/func_800F20CC_ovl08.c */
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3[5];
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    u8 pad10[4];
    u8 unk14;
    u8 unk15;
    u8 pad16[0x30 - 0x16];
    s32 unk30;
    u8 pad34[0x3C - 0x34];
    s32 unk3C;
    u16 unk40;
    u16 unk42;
    u8 pad44[0x50 - 0x44];
    void* unk50;
} Obj800F20CC;

/* src/rockx5/func_800F3988_ovl03.c */
typedef struct Obj3988 {
    u8 pad0[6];
    u8 unk6;
    u8 pad7[3];
    s16 unkA;
    u8 padC[2];
    s16 unkE;
    u8 pad10[0x10];
    s32 unk20;
    s32 unk24;
    u8 pad28[0x54];
    s16 unk7C;
    u8 pad7E[6];
    s32 unk84;
    s32 unk88;
    u8 pad8C[3];
    u8 unk8F;
} Obj3988;

/* src/rockx5/func_800F637C_ovl11.c */
typedef struct Obj637C {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[2];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[8];
    /* 0x14 */ signed char unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x2C];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ u8 pad58[0xA];
    /* 0x62 */ u8 unk62;
    /* 0x63 */ u8 pad63[0x19];
    /* 0x7C */ s16 unk7C;
} Obj637C;

/* src/rockx5/func_800FA2FC_ovl07.c */
typedef struct {
    u8 pad0[0x6];
    u8 unk6;
    u8 pad7[0x3];
    s16 unkA;
    u8 padC[0x2];
    s16 unkE;
    u8 pad10[0x10];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 pad30[0x4C];
    s16 unk7C;
} Ent7C;

/* src/rockx5/func_800FAD8C_ovl49.c */
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2[2];
    s16 unk4;
    u16 unk6;
} Unk800FAD8C;

/* src/rockx5/func_800FD23C_ovl07.c */
typedef struct Obj800FD23C {
    /* 0x00 */ u8 pad00[2];
    /* 0x02 */ signed char state;
    /* 0x03 */ u8 unk03;
    /* 0x04 */ u8 unk04;
    /* 0x05 */ u8 unk05;
    /* 0x06 */ u8 unk06;
    /* 0x07 */ u8 unk07;
    /* 0x08 */ u8 pad08[0xD];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[9];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x12];
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0xC];
    /* 0x50 */ u8* unk50;
    /* 0x54 */ u8* unk54;
    /* 0x58 */ u8* unk58;
    /* 0x5C */ u8 pad5C[4];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 pad61[6];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ u8* unk68;
    /* 0x6C */ u8 pad6C[0x18];
    /* 0x84 */ s16* unk84;
    /* 0x88 */ u8 pad88[4];
    /* 0x8C */ u8 unk8C;
    /* 0x8D */ u8 unk8D;
    /* 0x8E */ u8 unk8E;
    /* 0x8F */ u8 pad8F;
    /* 0x90 */ s16 unk90;
} Obj800FD23C;

/* src/slus/func_80021650.c */
typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 pad2[6];
    /* 0x08 */ s16 unk8;
    /* 0x0A */ u8 padA[0x15];
    /* 0x1F */ u8 unk1F;
    /* 0x20 */ u8 pad20[4];
    /* 0x24 */ u8 unk24;
} Obj80021650;

/* src/slus/func_80023368.c */
// from slus 80023368
typedef struct {
    u8 pad0[2];
    s8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 pad6[2];
    s32 unk8;
    s32 unkC;
    u8 pad10[0x44];
    s16 unk54;
    s16 unk56;
    s16 unk58;
    u8 pad5A[0x32];
    s8 unk8C;
} Obj23368;

/* src/slus/func_80025A74.c */
typedef struct {
    u8 pad0[0x45];
    u8 unk45;
    u8 pad46;
    s8 unk47[1];
} D1C00;

/* src/slus/func_80025A74.c */
typedef struct {
    u8 pad0[0x93];
    s8 unk93;
    s8 unk94;
    u8 pad95[0x13];
    s16 unkA8[0x50];
    s16 unk148;
} HudObj;

/* src/slus/func_800371CC.c */
typedef struct Ent371CC {
    /* 0x00 */ u8 pad0[0x15];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x44 - 0x16];
    /* 0x44 */ s8 unk44;
    /* 0x45 */ s8 unk45;
    /* 0x46 */ u8 pad46[0x7C - 0x46];
    /* 0x7C */ u16 unk7C;
    /* 0x7E */ u8 pad7E[2];
    /* 0x80 */ u16 unk80;
} Ent371CC;

/* src/slus/func_800493F0.c */
typedef struct {
    u8 pad0[4];
    u8 unk4;
    u8 pad5[9];
    s16 unkE;
    u8 pad10[0x35];
    u8 unk45;
    u8 pad46[0xA];
    s32* unk50;
    u8 pad54[0x14];
    Unk800770CC* unk68;
    u8 pad6C[4];
    u8 unk70;
    u8 pad71[0x1E];
    u8 unk8F;
    s16 unk90;
    u8 pad92[3];
    u8 unk95;
} Ent493F0;

/* src/slus/func_8004E360.c */
typedef struct Obj8004E360 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ s8 unk3;
    /* 0x04 */ s8 pad4;
    /* 0x05 */ s8 unk5;
    /* 0x06 */ s8 unk6;
    /* 0x07 */ s8 pad7;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[0x35];
    /* 0x45 */ s8 unk45;
    /* 0x46 */ u8 pad46[0xA];
    /* 0x50 */ u8* unk50;
    /* 0x54 */ s8 unk54;
    /* 0x55 */ s8 unk55;
    /* 0x56 */ u16 unk56;
} Obj8004E360;

/* src/rockx5/func_800EF6DC_ovl29.c */
typedef struct Ent6DC {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x20 - 0x7];
    s32 unk20;
    u8 pad24[0x45 - 0x24];
    s8 unk45;
    u8 pad46[0x50 - 0x46];
    void* unk50;
    void* unk54;
    void* unk58;
    u8 pad5C[0x60 - 0x5C];
    u8 unk60;
    u8 pad61[0x7C - 0x61];
    s16 unk7C;
} Ent6DC;

/* src/rockx5/func_800EF920_ovl29.c */
typedef struct EntF920 {
    /* 0x00 */ u8 pad00[0x5];
    /* 0x05 */ u8 state;
    /* 0x06 */ u8 substate;
    /* 0x07 */ u8 pad07[0x15 - 0x7];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x20 - 0x16];
    /* 0x20 */ s32 velX;
    /* 0x24 */ u8 pad24[0x28 - 0x24];
    /* 0x28 */ s32 unk28;
    /* 0x2C */ u8 pad2C[0x60 - 0x2C];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 pad61[0x70 - 0x61];
    /* 0x70 */ u8 flags;
} EntF920;

/* src/rockx5/func_800EF9C8_ovl29.c */
typedef struct ObjEF9C8 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x19];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x28];
    /* 0x58 */ void* unk58;
    /* 0x5C */ u8 pad5C[4];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 pad61[6];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ u8 pad68[8];
    /* 0x70 */ u8 unk70;
    /* 0x71 */ u8 pad71[0xF];
    /* 0x80 */ s32 unk80;
} ObjEF9C8;

/* src/rockx5/func_800EFAE4_ovl29.c */
typedef struct ObjEFAE4 {
    /* 0x00 */ u8 pad0[0x5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x20 - 0x7];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x45 - 0x24];
    /* 0x45 */ signed char unk45;
    /* 0x46 */ u8 pad46[0x50 - 0x46];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ void* unk58;
} ObjEFAE4;

/* src/rockx5/func_800EFC68_ovl29.c */
typedef struct ObjEFC68 {
    u8 pad0[0x5];
    s8 unk5;
    s8 unk6;
    u8 pad7[0x20 - 0x7];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 pad30[0x67 - 0x30];
    s8 unk67;
    u8 pad68[0x70 - 0x68];
    u8 unk70;
} ObjEFC68;

/* src/rockx5/func_800EFD08_ovl03.c */
typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x8 - 0x3];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x30 - 0x17];
    /* 0x30 */ s32 unk30;
    /* 0x34 */ u8 pad34[0x3C - 0x34];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0x7C - 0x44];
    /* 0x7C */ void* unk7C;
} ObjEFD08;

/* src/rockx5/func_800F17EC_ovl26.c */
typedef struct Obj17EC {
    u8 pad0[0x6];
    u8 unk6;
    u8 pad7[0x3];
    s16 unkA;
    u8 padC[0x44];
    s32 unk50;
    s32 unk54;
    u8 pad58[0x24];
    s16 unk7C;
} Obj17EC;

/* src/rockx5/func_800F197C_ovl05.c */
typedef struct Obj197C {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 state;
    /* 0x03 */ u8 pad3[3];
    /* 0x06 */ u8 step;
    /* 0x07 */ u8 pad7[0x91 - 0x07];
    /* 0x91 */ u8 unk91;
    /* 0x92 */ u8 unk92;
} Obj197C;

/* src/rockx5/func_800F1A00_ovl05.c */
typedef struct {
    u8 pad0[2];
    s8 unk2;      /* 0x02 */
    u8 pad3[3];
    u8 unk6;      /* 0x06 */
    u8 pad7[0x3E];
    s8 unk45;     /* 0x45 */
    u8 pad46[0x42];
    s16 unk88;    /* 0x88 */
    u8 pad8A[3];
    s8 unk8D;     /* 0x8D */
    u8 pad8E;
    u8 unk8F;     /* 0x8F */
} Obj1A00;

/* src/rockx5/func_800F1C98_ovl26.c */
typedef struct {
    u8 pad0[0x6];
    u8 x6;
    u8 pad7[0x3];
    s16 xA;
    u8 padC[0x39];
    s8 x45;
    u8 pad46[0xA];
    void* x50;
    void* x54;
} Obj1C98;

/* src/rockx5/func_800F5524_ovl27.c */
typedef struct Obj5524 {
    u8 pad0[0x6];
    u8 state6; /* 0x06 */
    u8 pad7[0x7C - 0x7];
    s16 timer7C; /* 0x7C */
    s16 timer7E; /* 0x7E */
} Obj5524;

/* src/rockx5/func_800F5C0C_ovl09.c */
typedef struct Obj5C0C {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x4C];
    /* 0x7C */ s16 unk7C;
} Obj5C0C;

/* src/rockx5/func_800F5C30_ovl00.c */
typedef struct Obj5C30 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ s8 state;
} Obj5C30;

/* src/rockx5/func_800F6298_ovl01.c */
typedef struct Obj6298 {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ s8 unk3;
    /* 0x04 */ s8 state;
    /* 0x05 */ s8 unk5;
    /* 0x06 */ u8 pad6[2];
    /* 0x08 */ s32 x_pos;
    /* 0x0C */ s32 y_pos;
    /* 0x10 */ u8 pad10[8];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 pad20[0x5C];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ s16 unk7E;
} Obj6298;

/* src/rockx5/func_800FB59C_ovl49.c */
/* D_8009A1F8 view: the word at 0x60 and the flag byte at 0xA0 */
typedef struct {
    u8 pad0[0x60];
    s32 unk60;
    u8 pad64[0xA0 - 0x64];
    u8 unkA0;
} D_8009A1F8_60A0_t;

/* src/rockx5/func_800FBD40_ovl38.c */
typedef struct EntBD40 {
    /* 0x00 */ u8 pad0[0x6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x5C - 0x7];
    /* 0x5C */ s8 unk5C;
    /* 0x5D */ u8 pad5D[0x7C - 0x5D];
    /* 0x7C */ s16 unk7C;
} EntBD40;

/* src/rockx5/func_800FD048_ovl39.c */
typedef struct EntFD048 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad3[3];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
} EntFD048;

/* src/rockx5/func_800EF51C_ovl29.c */
typedef struct Obj800EF51C {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x88 - 7];
    s32 unk88;
    s32 unk8C;
} Obj800EF51C;

/* src/rockx5/func_800EF604_ovl29.c */
typedef struct ObjEF604 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x15 - 0x07];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x20 - 0x16];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[4];
    /* 0x28 */ s32 unk28;
    /* 0x2C */ u8 pad2C[0x45 - 0x2C];
    /* 0x45 */ s8 unk45;
    /* 0x46 */ u8 pad46[0x7C - 0x46];
    /* 0x7C */ s16 unk7C;
} ObjEF604;

/* src/rockx5/func_800EF7C0_ovl29.c */
typedef struct ObjEF7C0 {
    /* 0x00 */ u8 pad0[0x6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x15 - 0x7];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x20 - 0x16];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x7C - 0x24];
    /* 0x7C */ s16 unk7C;
} ObjEF7C0;

/* src/rockx5/func_800EFBF8_ovl29.c */
typedef struct EntFBF8 {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x15 - 7];
    u8 unk15;
    u8 pad16[0x20 - 0x16];
    s32 unk20;
    u8 pad24[0x7C - 0x24];
    s16 unk7C;
} EntFBF8;

/* src/rockx5/func_800F1D68_ovl05.c */
typedef struct {
    u8 pad0[2];
    s8 unk2;      /* 0x02 */
    u8 pad3[3];
    u8 unk6;      /* 0x06 */
    u8 pad7[0x3E];
    s8 unk45;     /* 0x45 */
    u8 pad46[0x42];
    s16 unk88;    /* 0x88 */
    u8 pad8A[2];
    s8 unk8C;     /* 0x8C */
    u8 pad8D;
    u8 unk8E;     /* 0x8E */
} Obj1D68;

/* src/rockx5/func_800F72D0_ovl28.c */
typedef struct {
    u8 pad0[2];
    s8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 pad6[2];
    s32 unk8;
    s32 unkC;
    u8 pad10[0x44];
    s16 unk54;
    s16 unk56;
    s16 unk58;
    u8 pad5A[0x40];
    s8 unk9A;
} Obj800F72D0;

/* src/rockx5/func_800F7734_ovl26.c */
typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x11];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x1A];
    /* 0x30 */ s32 unk30;
    /* 0x34 */ u8 pad34[0x8];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0xC];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ u8 pad58[0x24];
    /* 0x7C */ s32 unk7C;
} Obj800F7734;

/* src/rockx5/func_800F8B54_ovl00.c */
typedef struct Obj8B54 {
    /* 0x00 */ u8 pad0[0x6];
    /* 0x06 */ u8 state;
    /* 0x07 */ u8 pad7[0x46 - 0x7];
    /* 0x46 */ signed char flag46;
    /* 0x47 */ u8 pad47[0x7C - 0x47];
    /* 0x7C */ s16 timer;
    /* 0x7E */ s16 count;
} Obj8B54;

/* src/rockx5/func_800FE004_ovl39.c */
typedef struct EntFE004 {
    /* 0x00 */ u8 pad0[0x5];
    /* 0x05 */ u8 state;
    /* 0x06 */ u8 pad6[0x70 - 0x6];
    /* 0x70 */ u8 flags;
    /* 0x71 */ u8 pad71[0x8C - 0x71];
    /* 0x8C */ u16 timer;
} EntFE004;

/* src/rockx5/func_800EFBC4_ovl29.c */
typedef struct {
    u8 pad0[0x6];
    u8 unk6;
    u8 pad7[0x15 - 0x7];
    u8 unk15;
    u8 pad16[0x20 - 0x16];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 pad30[0x7C - 0x30];
    s16 unk7C;
} Obj800EFBC4;

/* src/rockx5/func_800F0D10_ovl08.c */
typedef struct Ent0D10 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xE];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ u8 pad2C[0x50];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ u8 pad7E[0xB];
    /* 0x89 */ u8 unk89;
    /* 0x8A */ u8 unk8A;
    /* 0x8B */ u8 pad8B;
    /* 0x8C */ s32 unk8C;
} Ent0D10;

/* src/rockx5/func_800F1148_ovl11.c */
typedef struct Obj1148 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x11];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[0x19];
    /* 0x30 */ void* unk30;
    /* 0x34 */ u8 pad34[0x8];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0x38];
    /* 0x7C */ void* unk7C;
} Obj1148;

/* src/rockx5/func_800F1B80_ovl26.c */
typedef struct {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x45 - 0x7];
    /* 0x45 */ s8 unk45;
} Obj800F1B80;

/* src/rockx5/func_800F5864_ovl04.c */
typedef struct Obj5864 {
    u8 pad0[6];
    u8 unk6;
    u8 pad7[7];
    s16 unkE;
    u8 pad10[0x6C];
    s16 unk7C;
} Obj5864;

/* src/rockx5/func_800F73D4_ovl11.c */
typedef struct Obj73D4 {
    u8 pad0[6];
    u8 state;       /* 0x06 */
    u8 pad7[3];
    s16 x;          /* 0x0A */
    u8 padC[9];
    u8 facing;      /* 0x15 */
    u8 pad16[0xA];
    s32 vx;         /* 0x20 */
    s32 unk24;      /* 0x24 */
    s32 vy;         /* 0x28 */
    s32 unk2C;      /* 0x2C */
    u8 pad30[0x40];
    u8 flags;       /* 0x70 */
    u8 pad71[0xB];
    s16 timer;      /* 0x7C */
} Obj73D4;

/* src/rockx5/func_800F7724_ovl11.c */
typedef struct {
    u8 pad0[6];
    u8 unk6;
    u8 pad7[3];
    s16 unkA;
    u8 padC[9];
    u8 unk15;
    u8 pad16[0x66];
    s16 unk7C;
    s16 unk7E;
} Ent7724;

/* src/rockx5/func_800F88E0_ovl00.c */
typedef struct Obj88E0 {
    /* 0x00 */ u8 pad0[0x6];
    /* 0x06 */ u8 state;
    /* 0x07 */ u8 pad7[0x28 - 0x7];
    /* 0x28 */ s32 unk28;
    /* 0x2C */ u8 pad2C[0x46 - 0x2C];
    /* 0x46 */ signed char flag46;
    /* 0x47 */ u8 pad47[0x7C - 0x47];
    /* 0x7C */ s16 timer;
} Obj88E0;

/* src/rockx5/func_800FB4BC_ovl06.c */
typedef struct {
    s32 x;
    s32 y;
} PairFB4BC;

/* src/rockx5/func_800FB4BC_ovl06.c */
typedef struct {
    u8 pad0[2];
    signed char b2;
    u8 pad3;
    signed char b4;
    signed char b5;
    u8 pad6[2];
    PairFB4BC pos;
    u8 pad10[8];
    PairFB4BC prev;
    u8 pad20[0x5C];
    Ent8004A364* parent;
} ObjFB4BC;

/* src/rockx5/func_800EF44C_ovl09.c */
typedef struct Obj800EF44C {
    u8 pad0[0x6];
    u8 unk6;
    u8 pad7[0x15 - 0x7];
    u8 unk15;
    u8 pad16[0x20 - 0x16];
    s32 unk20;
    s32 unk24;
    u8 pad28[0x7C - 0x28];
    s16 unk7C;
} Obj800EF44C;

/* src/rockx5/func_800F01BC_ovl10.c */
typedef struct Obj01BC {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ signed char f2;
    /* 0x03 */ u8 pad3[2];
    /* 0x05 */ u8 state;
    /* 0x06 */ u8 sub;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 x;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 y;
    /* 0x10 */ u8 pad10[0x10];
    /* 0x20 */ s32 f20;
    /* 0x24 */ s32 f24;
    /* 0x28 */ s32 f28;
    /* 0x2C */ s32 f2C;
    /* 0x30 */ u8 pad30[0x4C];
    /* 0x7C */ s16 f7C;
} Obj01BC;

/* src/rockx5/func_800F0640_ovl29.c */
typedef struct Ent0640 {
    u8 pad00[0x6];
    u8 unk06;
    u8 pad07[0x15 - 0x7];
    u8 unk15;
    u8 pad16[0x20 - 0x16];
    s32 unk20;
    s32 unk24;
    u8 pad28[0x2C - 0x28];
    s32 unk2C;
    u8 pad30[0x45 - 0x30];
    signed char unk45;
    u8 pad46[0x80 - 0x46];
    u8 unk80;
    u8 pad81[0x8C - 0x81];
    u8 unk8C;
} Ent0640;

/* src/rockx5/func_800F0E50_ovl00.c */
typedef struct {
    u8 pad0[2];
    signed char state; /* 0x02 */
    u8 pad3;
    u8 u4;   /* 0x04 */
    u8 u5;   /* 0x05 */
    u8 pad6[0xF];
    u8 u15;  /* 0x15 */
    u8 u16;  /* 0x16 */
    u8 pad17[9];
    s32 u20; /* 0x20 */
    s32 u24; /* 0x24 */
    s32 u28; /* 0x28 */
    s32 u2C; /* 0x2C */
} Obj0E50;

/* src/rockx5/func_800F0F0C_ovl00.c */
typedef struct Sub50 {
    u8 pad0[0x4];
    s8 unk4;
    u8 pad5[0x96 - 0x5];
    u16 unk96;
} Sub50;

/* src/rockx5/func_800F0F0C_ovl00.c */
typedef struct Ent50 {
    u8 pad0[0x3];
    u8 unk3;
    u8 pad4;
    s8 unk5;
    u8 pad6[0x8 - 0x6];
    s32 unk8;
    s32 unkC;
    u8 pad10[0x18 - 0x10];
    s32 unk18;
    s32 unk1C;
    u8 pad20[0x50 - 0x20];
    Sub50 *unk50;
} Ent50;

/* src/rockx5/func_800F103C_ovl05.c */
typedef struct {
    u8 pad0[0xA];
    u16 unkA;
    u8 padC[0x15 - 0xC];
    u8 unk15;
    u8 pad16[0x8C - 0x16];
    u8 unk8C;
} Obj800F103C;

/* src/rockx5/func_800F53A4_ovl09.c */
typedef struct {
    u8 pad0[2];
    signed char f2;
    signed char f3;
    signed char f4;
    u8 pad5[3];
    s32 f8;
    s32 fC;
    u8 pad10[8];
    s32 f18;
    s32 f1C;
} Obj53A4;

/* src/rockx5/func_800F6BD4_ovl00.c */
typedef struct Obj6BD4 {
    u8 pad0[4];
    s8 state;
    u8 pad5[3];
    s32 x;
    s32 y;
    u8 pad10[8];
    s32 prevX;
    s32 prevY;
} Obj6BD4;

/* src/rockx5/func_800F6D44_ovl04.c */
typedef struct Obj6D44 {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[5];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[0x40];
    /* 0x68 */ void* unk68;
    /* 0x6C */ u8 pad6C[0x1C];
    /* 0x88 */ s16 unk88;
    /* 0x8A */ u8 pad8A[2];
    /* 0x8C */ u16 unk8C;
    /* 0x8E */ u8 pad8E;
    /* 0x8F */ u8 unk8F;
    /* 0x90 */ u8 pad90;
    /* 0x91 */ u8 unk91;
} Obj6D44;

/* src/rockx5/func_800F8084_ovl03.c */
typedef struct Obj8084 {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x54 - 0x7];
    void* unk54;
    u8 pad58[0x7C - 0x58];
    u16 unk7C;
    u8 pad7E[0x92 - 0x7E];
    u8 unk92;
    u8 unk93;
} Obj8084;

/* src/rockx5/func_800F9D50_ovl00.c */
typedef struct {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 state;
    /* 0x05 */ u8 substate;
    /* 0x06 */ u8 pad6[4];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
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
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0xC];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 pad61[6];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x10];
    /* 0x7C */ void* parent; /* Obj9D50* */
} Obj9D50;

/* src/rockx5/func_800FA5B0_ovl50.c */
typedef struct {
    u8 pad0[3];
    u8 unk3;
    u8 pad4[4];
    s32 unk8;
    s32 unkC;
    u8 pad10[0x36 - 0x10];
    u8 unk36;
    u8 pad37[0x4C - 0x37];
    u8 unk4C;
    u8 pad4D[0x57 - 0x4D];
    u8 unk57;
    u8 pad58[0xAB - 0x58];
    u8 unkAB;
    u8 padAC[4];
    s32 unkB0;
    s32 unkB4;
    u8 padB8[0xF4 - 0xB8];
    u8 unkF4;
} D_8009A1F8_AB_t;

/* src/rockx5/func_800FB5A4_ovl06.c */
typedef struct {
    u8 pad0[3];
    u8 b3;
    u8 b4;
    u8 pad5[2];
    signed char b7;
    u8 pad8[0x7C - 0x8];
    Ent8004A364* parent;
    u8 pad80[0x88 - 0x80];
    s16 timer;
} ObjFB5A4;

/* src/rockx5/func_800FBB70_ovl06.c */
typedef struct ObjBB70 {
    /* 0x00 */ u8 pad00[0x4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad05;
    /* 0x06 */ u8 state;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u8 pad08[0xD];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x31];
    /* 0x47 */ u8 unk47;
    /* 0x48 */ u8 pad48[0x8];
    /* 0x50 */ u8* unk50;
    /* 0x54 */ u8* unk54;
    /* 0x58 */ u8 pad58[0x10];
    /* 0x68 */ u8* unk68;
    /* 0x6C */ u8 pad6C[0x4];
    /* 0x70 */ u8 unk70;
} ObjBB70;

/* src/rockx5/func_800FCAD8_ovl07.c */
typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[0x7];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[0x2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[0x4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x1B];
    /* 0x30 */ void* unk30;
    /* 0x34 */ u8 pad34[0x8];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0x38];
    /* 0x7C */ void* unk7C; /* the parent ObjCAD8 */
    /* 0x80 */ u8 pad80[0x8];
    /* 0x88 */ s16 unk88;
} ObjCAD8;

/* src/rockx5/func_800FD404_ovl39.c */
typedef struct EntFD404Parent {
    u8 pad0[0x7];
    s8 unk7;
    u8 pad8[0x89 - 0x8];
    u8 unk89;
} EntFD404Parent;

/* src/rockx5/func_800FD404_ovl39.c */
typedef struct EntFD404 {
    u8 pad0[0x5];
    s8 unk5;
    u8 unk6;
    u8 pad7[0x45 - 0x7];
    s8 unk45;
    u8 pad46[0x7C - 0x46];
    EntFD404Parent* unk7C;
    u8 pad80[0x82 - 0x80];
    s16 unk82;
    u8 pad84[0x87 - 0x84];
    u8 unk87;
    u8 unk88;
} EntFD404;

/* src/rockx5/func_800FE070_ovl39.c */
typedef struct EntFE070 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 state;
    /* 0x06 */ u8 pad6[4];
    /* 0x0A */ s16 x;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 y;
    /* 0x10 */ u8 pad10[0x10];
    /* 0x20 */ s32 vx;
    /* 0x24 */ s32 vy;
    /* 0x28 */ u8 pad28[0x64];
    /* 0x8C */ u16 timer;
} EntFE070;

/* src/rockx5/func_800FE250_ovl39.c */
typedef struct EntFE250 {
    /* 0x00 */ u8 pad0[0x5];
    /* 0x05 */ u8 state;
    /* 0x06 */ u8 pad6[0x58 - 0x6];
    /* 0x58 */ s32 unk58;
    /* 0x5C */ u8 pad5C[0x70 - 0x5C];
    /* 0x70 */ u8 flags;
    /* 0x71 */ u8 pad71[0x8C - 0x71];
    /* 0x8C */ u16 timer;
} EntFE250;

/* src/rockx5/func_800FEAC0_ovl04.c */
typedef struct {
    u8 pad0[2];
    s8 unk2;
    u8 pad3[2];
    u8 unk5;
    u8 pad6[0x3C];
    u16 unk42;
    u8 pad44[0x3C];
    void* unk80;
} EntFEAC0;

/* src/rockx5/func_800EFE60_ovl00.c */
typedef struct Ent85 {
    u8 pad0[0x2];
    signed char unk2;
    u8 pad3[0x2];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x4D];
    void *unk54;
} Ent85;

/* src/rockx5/func_800EFE60_ovl00.c */
typedef struct Scr {
    u8 pad0[0x86];
    u8 unk86;
    u8 pad87[0xA];
    u8 unk91;
} Scr;

/* src/rockx5/func_800F0138_ovl05.c */
typedef struct {
    u8 pad0[0x5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0xE - 0x7];
    s16 unkE;
    u8 pad10[0x2C - 0x10];
    s32 unk2C;
    u8 pad30[0x68 - 0x30];
    void* unk68;
    u8 pad6C[0x70 - 0x6C];
    u8 unk70;
} Obj0138;

/* src/rockx5/func_800F03EC_ovl01.c */
typedef struct Ent03EC {
    u8 pad0[0x6];
    u8 x6;
    u8 pad7[0x15 - 0x7];
    u8 x15;
    u8 pad16[0x20 - 0x16];
    s32 x20;
    u8 pad24[0x45 - 0x24];
    signed char x45;
    u8 pad46[0x7E - 0x46];
    s16 x7E;
    u8 pad80[0x84 - 0x80];
    s32 x84;
} Ent03EC;

/* src/rockx5/func_800F08B4_ovl08.c */
typedef struct Obj08B4 {
    /* 0x00 */ u8 pad0[0x6];
    /* 0x06 */ u8 state;
    /* 0x07 */ u8 pad7[0x3];
    /* 0x0A */ u16 x;
    /* 0x0C */ u8 padC[0x9];
    /* 0x15 */ u8 flip;
    /* 0x16 */ u8 pad16[0x68];
    /* 0x7E */ s16 timer;
    /* 0x80 */ u8 pad80;
    /* 0x81 */ s8 hit;
} Obj08B4;

/* src/rockx5/func_800F0D34_ovl00.c */
// from rockx5 800F0D34: source and spawned object share this layout
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3;
    u8 unk4;
    u8 pad5[3];
    s32 unk8;
    s32 unkC;
    u8 pad10[4];
    u8 unk14;
    u8 pad15[0x1B];
    s32 unk30;
    u8 pad34[8];
    s32 unk3C;
    u16 unk40;
    u16 unk42;
    u8 pad44[0xC];
    void* unk50;
} Obj800F0D34;

/* src/rockx5/func_800F13BC_ovl12.c */
typedef struct Ent13BC {
    u8 pad0[4];
    s8 state;               /* 0x04 */
    s8 sub;                 /* 0x05 */
    u8 pad6[0x76];
    void* parent;           /* 0x7C: the parent Ent13BC */
    u8 pad80[0xC];
    s32 timer;              /* 0x8C */
} Ent13BC;

/* src/rockx5/func_800F3560_ovl00.c */
typedef struct Obj3560 {
    u8 pad0[4];
    u8 unk4;
    u8 pad5[2];
    s8 unk7;
    u8 pad8[0x45 - 8];
    s8 unk45;
    s8 unk46;
    u8 pad47[0x50 - 0x47];
    s32 unk50;
} Obj3560;

/* src/rockx5/func_800F5298_ovl10.c */
typedef struct {
    u8 pad0[0xA];
    s16 unkA;
    u8 padC[0x54 - 0xC];
} Ent9A1F8;

/* src/rockx5/func_800F5298_ovl10.c */
typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[3];
    s16 unkA;
    u8 padC[9];
    u8 unk15;
    u8 pad16[0x7C - 0x16];
    s16 unk7C;
    u8 pad7E[7];
    u8 unk85;
} Obj5298;

/* src/rockx5/func_800F56AC_ovl09.c */
typedef struct Obj56AC {
    u8 pad0[0x6];
    u8 state;           /* 0x06 */
    u8 pad7[0x46 - 0x7];
    signed char flag46; /* 0x46 */
    u8 pad47[0x7C - 0x47];
    s16 timer;          /* 0x7C */
} Obj56AC;

/* src/rockx5/func_800F5A88_ovl09.c */
typedef struct Obj5A88 {
    /* 0x00 */ u8 pad0[0x6];
    /* 0x06 */ u8 state;
    /* 0x07 */ u8 pad7[0x7C - 0x7];
    /* 0x7C */ s16 timer;
    /* 0x7E */ u8 pad7E[0x84 - 0x7E];
    /* 0x84 */ s32 unk84;
    /* 0x88 */ s32 unk88;
    /* 0x8C */ u8 pad8C[0x92 - 0x8C];
    /* 0x92 */ u8 unk92;
} Obj5A88;

/* src/rockx5/func_800F6C0C_ovl04.c */
typedef struct Obj6C0C {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x3];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[0x9];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[0x28];
    /* 0x50 */ void* unk50;
    /* 0x54 */ u8 pad54[0x13];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ void* unk68;
    /* 0x6C */ u8 pad6C[0x25];
    /* 0x91 */ u8 unk91;
    /* 0x92 */ u8 pad92;
    /* 0x93 */ u8 unk93;
} Obj6C0C;

/* src/rockx5/func_800F6C2C_ovl00.c */
typedef struct Obj6C2C {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad3[3];
    /* 0x06 */ s8 state;
} Obj6C2C;

/* src/rockx5/func_800FA5C0_ovl06.c */
typedef struct {
    u8 pad0[0x6];
    u8 state;           /* 0x06 */
    u8 pad7[0x3];
    s16 x;              /* 0x0A */
    u8 padC[0x2];
    s16 y;              /* 0x0E */
    u8 pad10[0x35];
    signed char mode;   /* 0x45 */
    u8 pad46[0x36];
    s16 timer;          /* 0x7C */
    s16 count;          /* 0x7E */
} EntFA5C0;

/* src/rockx5/func_800FC1C0_ovl06.c */
typedef struct EntFC1C0 {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5;
    /* 0x06 */ s8 state;
    /* 0x07 */ u8 pad7[0x45 - 0x07];
    /* 0x45 */ s8 unk45;
    /* 0x46 */ u8 pad46[0x54 - 0x46];
    /* 0x54 */ s16 timer;
} EntFC1C0;

/* src/rockx5/func_800FC254_ovl07.c */
typedef struct EntFC254 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ s8 kind;
    /* 0x06 */ u8 step;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 x;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 y;
    /* 0x10 */ u8 pad10[0x6C];
    /* 0x7C */ s16 timer;
} EntFC254;

/* src/slus/func_800376EC.c */
typedef struct Obj76EC {
    u8 pad0[0x15];
    u8 unk15;
    u8 pad16[0x20 - 0x16];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    u8 pad2C[0x89 - 0x2C];
    u8 unk89;
    u8 pad8A[0xD4 - 0x8A];
    signed char unkD4;
} Obj76EC;

/* src/rockx5/func_800F04D0_ovl29.c */
typedef struct Ent04D0 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ signed char unk2;
    /* 0x03 */ u8 pad3[2];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x19];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[8];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x4C];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ u8 pad7E[2];
    /* 0x80 */ u8 unk80;
    /* 0x81 */ u8 pad81[0xB];
    /* 0x8C */ u8 unk8C;
} Ent04D0;

/* src/rockx5/func_800F06F4_ovl08.c */
typedef struct Obj06F4 {
    /* 0x00 */ u8 pad0[0x5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0xE];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x21];
    /* 0x45 */ s8 unk45;
    /* 0x46 */ u8 pad46[0x36];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ u8 pad7E[0xC];
    /* 0x8A */ u8 unk8A;
} Obj06F4;

/* src/rockx5/func_800F078C_ovl08.c */
typedef struct Obj078C {
    /* 0x00 */ u8 pad0[0x5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0xE];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x58];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ u8 pad7E[0x2];
    /* 0x80 */ u8 unk80;
    /* 0x81 */ u8 pad81[0x7];
    /* 0x88 */ u8 unk88;
    /* 0x89 */ u8 unk89;
} Obj078C;

/* src/rockx5/func_800F09D8_ovl12.c */
typedef struct Obj09D8 {
    /* 0x00 */ u8 pad0[0x6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x20 - 0x7];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[0x4];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x46 - 0x30];
    /* 0x46 */ signed char unk46;
    /* 0x47 */ u8 pad47[0x70 - 0x47];
    /* 0x70 */ u8 unk70;
} Obj09D8;

/* src/rockx5/func_800F09F4_ovl00.c */
typedef struct {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[5];
    /* 0x15 */ u8 unk15;
} Src09F4;

/* src/rockx5/func_800F09F4_ovl00.c */
typedef struct {
    /* 0x00 */ u8 pad0[0x80];
    /* 0x80 */ Src09F4* unk80;
    /* 0x84 */ u8 pad84[0xC];
    /* 0x90 */ u8 unk90;
} Scr09F4;

/* src/rockx5/func_800F09F4_ovl00.c */
typedef struct {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[5];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x3E];
    /* 0x54 */ s32 unk54;
    /* 0x58 */ u8 pad58[0x10];
    /* 0x68 */ s32 unk68;
} Ent09F4;

/* src/rockx5/func_800F5734_ovl04.c */
typedef struct Obj5734 {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x7C - 0x7];
    s16 timer;
    u8 pad7E[0x8F - 0x7E];
    u8 unk8F;
    u8 pad90;
    u8 unk91;
    u8 unk92;
} Obj5734;

/* src/rockx5/func_800F72C0_ovl10.c */
typedef struct Obj72C0 {
    u8 pad0[3];
    u8 b3;                  /* 0x3 */
    u8 b4;                  /* 0x4 */
    u8 pad5[0x16 - 0x5];
    u8 b16;                 /* 0x16 */
    u8 pad17[0x50 - 0x17];
    s32 w50;                /* 0x50 */
    s32 w54;                /* 0x54 */
    u8 pad58[0x68 - 0x58];
    s32 w68;                /* 0x68 */
    u8 pad6C[0x7C - 0x6C];
    Ent8004A364* parent;    /* 0x7C */
} Obj72C0;

/* src/rockx5/func_800F7334_ovl11.c */
typedef struct Ent7334 {
    u8 pad0[6];
    u8 state; /* 0x06 */
    u8 pad7[3];
    s16 x; /* 0x0A */
    u8 padC[0x70];
    s16 timer; /* 0x7C */
} Ent7334;

/* src/rockx5/func_800F7EB0_ovl03.c */
typedef struct {
    u8 b[12];
} Tbl7EB0;

/* src/rockx5/func_800F7EB0_ovl03.c */
typedef struct {
    u8 pad0[6];
    u8 unk6;
    signed char unk7;
    u8 pad8[0x1C];
    s32 unk24;
} Ent7EB0;

/* src/rockx5/func_800FB6A0_ovl06.c */
typedef struct {
    u8 pad0[6];
    u8 x6;
    u8 pad7[3];
    s16 xA;
    u8 padC[9];
    u8 x15;
    u8 pad16[0xA];
    s32 x20;
    s32 x24;
    s32 x28;
    s32 x2C;
} Obj800FB6A0;

/* src/rockx5/func_800FD9C0_ovl07.c */
typedef struct {
    u8 pad0[3];
    u8 unk3;
    u8 unk4;
    u8 pad5[2];
    s8 unk7;
    u8 pad8[0x88];
    s16 unk90;
} EntFD9C0;

/* src/rockx5/func_800EF3C4_ovl09.c */
typedef struct {
    u8 pad0[0x5];
    u8 unk5;
    u8 state6;
    u8 pad7[0x3];
    s16 x;
    u8 padC[0x9];
    u8 flags15;
    u8 pad16[0xA];
    s32 vx;
    u8 pad24[0x58];
    s16 timer;
} Obj3C4;

/* src/rockx5/func_800EFF4C_ovl05.c */
typedef struct ObjEFF4C {
    u8 pad0[0x6];
    u8 unk6;
    u8 pad7[0x54 - 0x7];
    void* unk54;
    u8 pad58[0x7C - 0x58];
    s16 unk7C;
} ObjEFF4C;

/* src/rockx5/func_800EFF50_ovl12.c */
typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[3];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u8 pad8[0x45 - 0x08];
    /* 0x45 */ signed char unk45;
    /* 0x46 */ u8 pad46[0x7C - 0x46];
    /* 0x7C */ void* unk7C;
} ObjEFF50;

/* src/rockx5/func_800F0110_ovl10.c */
typedef struct Ent0110 {
    u8 pad0[5];
    signed char state; /* 0x05 */
    u8 pad6[0x45 - 6];
    signed char anim; /* 0x45 */
    u8 pad46[0x50 - 0x46];
    s32* animPtr; /* 0x50 */
    s32* animBase; /* 0x54 */
} Ent0110;

/* src/rockx5/func_800F01DC_ovl05.c */
typedef struct Obj01DC {
    /* 0x00 */ u8 pad0[0x5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x20 - 0x7];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x45 - 0x30];
    /* 0x45 */ signed char unk45;
    /* 0x46 */ u8 pad46[0x67 - 0x46];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ u8* unk68;
} Obj01DC;

/* src/rockx5/func_800F0364_ovl01.c */
typedef struct Obj0364 {
    u8 pad0[0x6];
    u8 state;           /* 0x06 */
    u8 pad7[0x45 - 0x7];
    signed char mode;   /* 0x45 */
    u8 pad46[0x50 - 0x46];
    void* p50;          /* 0x50 */
    void* p54;          /* 0x54 */
    u8 pad58[0x7C - 0x58];
    s16 timer;          /* 0x7C */
    s16 h7E;            /* 0x7E */
} Obj0364;

/* src/rockx5/func_800F06F8_ovl29.c */
typedef struct Ent06F8 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 state;
    /* 0x06 */ u8 substate;
    /* 0x07 */ u8 pad7[0x24 - 0x7];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[4];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x70 - 0x30];
    /* 0x70 */ u8 flags70;
    /* 0x71 */ u8 pad71[0x8C - 0x71];
    /* 0x8C */ u8 unk8C;
} Ent06F8;

/* src/rockx5/func_800F1E04_ovl11.c */
typedef struct Ent1E04 {
    /* 0x00 */ s8 active;
    /* 0x01 */ u8 pad01[3];
    /* 0x04 */ u8 state;
    /* 0x05 */ u8 pad05[5];
    /* 0x0A */ u16 x;
    /* 0x0C */ u8 pad0C[2];
    /* 0x0E */ u16 y;
    /* 0x10 */ u8 pad10[0x40];
    /* 0x50 */ void* parent;
    /* 0x54 */ u8 pad54[0x38];
    /* 0x8C */ s32 link;
} Ent1E04;

/* src/rockx5/func_800F4808_ovl11.c */
typedef struct Obj4808 {
    u8 pad0[5];
    signed char state;
} Obj4808;

/* src/rockx5/func_800FBA68_ovl06.c */
typedef struct Sub7C {
    u8 pad0[0x8B];
    u8 unk8B;
} Sub7C;

/* src/rockx5/func_800FBA68_ovl06.c */
typedef struct Obj800FBA68 {
    u8 pad0[0x2];
    u8 unk2;
    u8 pad3;
    u8 unk4;
    u8 pad5[0x45 - 0x5];
    signed char unk45;
    u8 pad46;
    u8 unk47;
    u8 pad48[0x50 - 0x48];
    void *unk50;
    u8 pad54[0x7C - 0x54];
    Sub7C *unk7C;
} Obj800FBA68;

/* src/rockx5/func_800FC3F8_ovl38.c */
typedef struct ObjFC3F8 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x45 - 0x7];
    /* 0x45 */ s8 unk45;
    /* 0x46 */ u8 pad46[0x7C - 0x46];
    /* 0x7C */ s16 unk7C;
} ObjFC3F8;

/* src/rockx5/func_800FEFEC_ovl07.c */
typedef struct ParentFEFEC {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ signed char unk4;
    /* 0x05 */ u8 pad5[5];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[5];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x7C];
    /* 0x92 */ u8 unk92;
} ParentFEFEC;

/* src/rockx5/func_800FEFEC_ovl07.c */
typedef struct EntFEFEC {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5[5];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[5];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x3A];
    /* 0x50 */ ParentFEFEC* parent;
} EntFEFEC;

/* src/slus/func_800440A8.c */
typedef struct Obj440A8 {
    u8 pad0[5];
    s8 unk5;
    s8 state;
    u8 pad7[0x7A - 7];
    s8 unk7A;
    u8 pad7B[0xD3 - 0x7B];
    s8 unkD3;
    u8 padD4[0x14B - 0xD4];
    s8 unk14B;
} Obj440A8;

/* src/rockx5/func_800EF068_ovl16.c, func_800EEFEC_ovl16.c */
typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5[0x14 - 0x05];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 pad34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 pad3C;
    /* 0x40 */ s32 unk40;
    /* 0x44 */ s32 unk44;
} Ovl16Obj;

/* src/rockx5/func_800EFCD8_ovl00.c */
typedef struct {
    u8 pad0[0x93];
    u8 unk93;
    u16 unk94;
} Ctx800EFCD8;

/* src/rockx5/func_800F038C_ovl05.c */
typedef struct Obj038C {
    u8 pad0[0x6];
    u8 state;           /* 0x06 */
    u8 pad7[0x20 - 0x7];
    s32 unk20;          /* 0x20 */
    s32 unk24;          /* 0x24 */
    s32 unk28;          /* 0x28 */
    s32 unk2C;          /* 0x2C */
    u8 pad30[0x54 - 0x30];
    void* unk54;        /* 0x54 */
    u8 pad58[0x70 - 0x58];
    u8 flags70;         /* 0x70 */
} Obj038C;

/* src/rockx5/func_800F5CF0_ovl09.c */
typedef struct Obj5CF0 {
    /* 0x00 */ u8 pad0[0x6];
    /* 0x06 */ u8 state;
    /* 0x07 */ u8 pad7[0x19];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x4C];
    /* 0x7C */ s16 unk7C;
} Obj5CF0;

/* src/rockx5/func_800F77E8_ovl11.c */
typedef struct Obj77E8 {
    u8 pad0[0x6];
    u8 state; /* 0x06 */
    u8 pad7[0x3];
    s16 x; /* 0x0A */
    u8 padC[0x9];
    u8 flip; /* 0x15 */
    u8 pad16[0x66];
    s16 timer; /* 0x7C */
} Obj77E8;

/* src/rockx5/func_800F7D8C_ovl03.c */
typedef struct {
    /* 0x00 */ u8 pad0[0x6];
    /* 0x06 */ u8 step;
    /* 0x07 */ u8 pad7[0x19];
    /* 0x20 */ s32 vel;
    /* 0x24 */ u8 pad24[0x58];
    /* 0x7C */ s16 timer;
    /* 0x7E */ u8 pad7E[0x10];
    /* 0x8E */ u8 kind;
} Obj7D8C;

/* src/rockx5/func_800F84BC_ovl11.c */
typedef struct {
    u8 pad0[6];
    u8 unk6;
    u8 pad7;
    s32 unk8;
    u8 padC[0x80];
    s32 unk8C;
    s32 unk90;
    u8 pad94;
    u8 unk95;
} Obj800F84BC;

/* src/rockx5/func_800FC26C_ovl06.c */
typedef struct Fc26cObj {
    u8 pad0[0x6];
    s8 unk6;
    u8 pad7[0xA - 0x7];
    u16 unkA;
    u8 padC[0xE - 0xC];
    u16 unkE;
    u8 pad10[0x15 - 0x10];
    u8 unk15;
    u8 pad16[0x42 - 0x16];
    u16 unk42;
    u8 pad44[0x50 - 0x44];
    void *unk50; // parent Fc26cObj (shapes.py has no self-referential struct)
} Fc26cObj;

/* src/rockx5/func_800FE9A0_ovl07.c */
typedef struct EntFE9A0 {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ u8 state;
    /* 0x05 */ u8 pad5[0x5];
    /* 0x0A */ s16 x;
    /* 0x0C */ u8 padC[0x2];
    /* 0x0E */ s16 y;
    /* 0x10 */ u8 pad10[0x80];
    /* 0x90 */ s16 timer;
} EntFE9A0;

/* src/rockx5/func_800FEAC8_ovl07.c */
typedef struct SubFEAC8 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0xE];
    /* 0x15 */ u8 unk15;
} SubFEAC8;

/* src/rockx5/func_800FEAC8_ovl07.c */
typedef struct EntFEAC8 {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5[2];
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u8 pad8[0xD];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x66];
    /* 0x7C */ SubFEAC8* unk7C;
} EntFEAC8;

/* src/rockx5/func_800EF140_ovl09.c */
typedef struct {
    u8 pad0[0x2];
    s8 unk2;
    u8 unk3;
    u8 pad4[0x4C];
    s32 unk50;
    s32 unk54;
    s32 unk58;
    u8 pad5C[0x24];
    u8* unk80;
    u8 pad84[0xF];
    s8 unk93;
    u8 pad94;
    s8 unk95;
} Ovl09Obj800EF140;

/* src/rockx5/func_800EF8CC_ovl05.c */
typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s8 state;
    /* 0x05 */ s8 pad5[3];
    /* 0x08 */ s32 x;
    /* 0x0C */ s32 y;
    /* 0x10 */ s32 pad10[2];
    /* 0x18 */ s32 prevX;
    /* 0x1C */ s32 prevY;
    /* 0x20 */ s32 pad20[12];
    /* 0x50 */ s8 *unk50;
} Entity800EF8CC;

/* src/rockx5/func_800F3950_ovl05.c */
/* 0x7C is a frame counter whose low byte is reread as a blink mask. */
typedef union Ctr3950 {
    u32 w;
    u8 b;
} Ctr3950;

/* src/rockx5/func_800F3950_ovl05.c */
typedef struct Obj3950 {
    u8 pad0[3];
    u8 unk3;
    u8 unk4;
    u8 pad5[0x7C - 5];
    Ctr3950 unk7C;
} Obj3950;

/* src/rockx5/func_800F4D08_ovl29.c */
typedef struct Ent4D08 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x46 - 0x07];
    /* 0x46 */ signed char unk46;
    /* 0x47 */ u8 pad47[0x50 - 0x47];
    /* 0x50 */ void* unk50;
    /* 0x54 */ u8 pad54[0x8D - 0x54];
    /* 0x8D */ u8 unk8D;
    /* 0x8E */ u8 unk8E;
} Ent4D08;

/* src/rockx5/func_800F5D00_ovl26.c */
typedef struct Obj5D00 {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x20 - 7];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 pad30[0x68 - 0x30];
    void* unk68;
    u8 pad6C[0x7C - 0x6C];
    signed char* unk7C;
} Obj5D00;

/* src/rockx5/func_800F6AF0_ovl11.c */
typedef struct Ent6AF0 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[0x42 - 6];
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0x47 - 0x44];
    /* 0x47 */ u8 unk47;
    /* 0x48 */ u8 pad48[0x61 - 0x48];
    /* 0x61 */ u8 unk61;
    /* 0x62 */ u8 pad62[0x7C - 0x62];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ s16 unk7E;
} Ent6AF0;

/* src/rockx5/func_800F6EFC_ovl10.c */
typedef struct Actor7CLink {
    /* 0x00 */ s32 pad0;
    /* 0x04 */ signed char state;
} Actor7CLink;

/* src/rockx5/func_800F6EFC_ovl10.c */
typedef struct Actor7C {
    /* 0x00 */ s32 pad0;
    /* 0x04 */ signed char state;
    /* 0x05 */ u8 pad5[3];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 pad10[2];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 pad20[23];
    /* 0x7C */ Actor7CLink* unk7C;
} Actor7C;

/* src/rockx5/func_800F6F70_ovl10.c */
typedef struct Obj6F70 {
    u8 pad0[3];
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 pad6[0x10];
    u8 unk16;
    u8 pad17[9];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 pad30[0x20];
    s32 unk50;
    s32 unk54;
    s32 unk58;
    u8 unk5C;
    u8 pad5D[3];
    u8 unk60;
    u8 unk61;
    u8 pad62[6];
    s32 unk68;
    u8 pad6C[0x18];
    s32 unk84;
    u8 pad88[8];
    s16 unk90;
    u8 pad92[2];
    u8 unk94;
} Obj6F70;

/* src/rockx5/func_800F7998_ovl11.c */
typedef struct Ob7998 {
    u8 pad0[0x6];
    u8 state;
    u8 pad7[0x20 - 0x7];
    s32 vx;
    s32 vy;
    u8 pad28[0x2C - 0x28];
    s32 unk2C;
    u8 pad30[0x7C - 0x30];
    s16 timer;
    s16 count;
} Ob7998;

/* src/rockx5/func_800FA798_ovl28.c */
typedef struct ObjFA798 {
    u8 pad0[4];
    s8 f4;
    u8 pad5[0x41];
    s8 f46;
    u8 pad47[0x35];
    Ent8004A364* parent;
} ObjFA798;

/* src/rockx5/func_800EF064_ovl28.c */
typedef struct Obj800EF064 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ signed char state;
    /* 0x06 */ u8 pad6[0xE];
    /* 0x14 */ u16 timer;
} Obj800EF064;

/* src/rockx5/func_800F0328_ovl05.c */
typedef struct Obj0328 {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[3];
    s16 unkA;
    u8 padC[0x18];
    s32 unk24;
    u8 pad28[4];
    s32 unk2C;
} Obj0328;

/* src/rockx5/func_800F074C_ovl01.c */
typedef struct Obj074C {
    u8 pad0[5];
    u8 state5; /* 0x05 */
    u8 state6; /* 0x06 */
    u8 pad7[0x60 - 0x07];
    u8 unk60; /* 0x60 */
    u8 pad61[0x80 - 0x61];
    s32 unk80; /* 0x80 */
    s32 unk84; /* 0x84 */
    s32 unk88; /* 0x88 */
    s32 unk8C; /* 0x8C */
} Obj074C;

/* src/rockx5/func_800F0980_ovl24.c */
typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[5];
    /* 0x08 */ s16 unk8;
    /* 0x0A */ u8 padA[0x15];
    /* 0x1F */ u8 unk1F;
    /* 0x20 */ u8 pad20[4];
    /* 0x24 */ u8 unk24;
} Obj800F0980;

/* src/rockx5/func_800F4FD4_ovl04.c */
typedef struct Obj4FD4 {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4;
    /* 0x05 */ u8 state;
    /* 0x06 */ u8 pad6[0x7C - 0x6];
    /* 0x7C */ s16 timer;
} Obj4FD4;

/* src/rockx5/func_800FAD10_ovl58.c */
typedef struct {
    u8 pad0[0xAB];
    u8 unkAB;
    u8 padAC[0xB2 - 0xAC];
    s16 unkB2;
    u8 padB4[2];
    s16 unkB6;
    u8 padB8[0xF4 - 0xB8];
    u8 unkF4;
} D_8009A1F8_AD10_t;

/* src/rockx5/func_800FB930_ovl06.c */
typedef struct ObjFB930 {
    u8 pad0[4];
    u8 state; /* 0x04 */
    u8 pad5[0x47 - 5];
    u8 kind; /* 0x47 */
    u8 pad48[0x50 - 0x48];
    void* p50; /* 0x50 */
    void* p54; /* 0x54 */
} ObjFB930;

/* src/rockx5/func_800FBA04_ovl06.c */
typedef struct ObjFBA04 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 state;
    /* 0x07 */ u8 pad7[0x59];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 pad61[0x27];
    /* 0x88 */ s16 timer;
} ObjFBA04;

/* src/rockx5/func_800FCE88_ovl39.c */
typedef struct {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 state;
    /* 0x05 */ u8 pad5[3];
    /* 0x08 */ s32 x;
    /* 0x0C */ s32 y;
    /* 0x10 */ u8 pad10[8];
    /* 0x18 */ s32 old_x;
    /* 0x1C */ s32 old_y;
    /* 0x20 */ u8 pad20[0x5C];
    /* 0x7C */ void* parent; /* Obj800FCE88* (shapes.py has no incomplete types) */
    /* 0x80 */ u8 pad80[4];
    /* 0x84 */ u8 unk84;
} Obj800FCE88;

/* src/rockx5/func_800F2C6C_ovl00.c */
typedef struct Obj2C6C {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 state;
    /* 0x07 */ u8 pad7[0x19];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x37];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ u8 pad68[8];
    /* 0x70 */ u8 flags70;
} Obj2C6C;

/* src/rockx5/func_800F649C_ovl04.c */
typedef struct Obj649C {
    u8 pad0[4];
    s8 unk4;
    u8 pad5[2];
    s8 unk7;
} Obj649C;

/* src/rockx5/func_800F6C58_ovl18.c */
typedef struct {
    u8 pad0[4];
    u8 unk4;
    u8 pad5[0xF];
    u8 *unk14;
} Obj800F6C58;

/* src/rockx5/func_800FC928_ovl07.c */
typedef struct {
    u8 pad0[6];
    u8 state;
    u8 pad7[0x50 - 7];
    void* p50;
    void* p54;
    u8 pad58[0x7C - 0x58];
    s16 timer;
} ObjFC928;

/* src/rockx5/func_800FD9BC_ovl39.c */
typedef struct {
    u8 pad0[0x6];
    u8 unk6;
    u8 pad7[0x3];
    s16 unkA;
    u8 padC[0x14];
    s32 unk20;
    u8 pad24[0x5E];
    s16 unk82;
    s8 unk84;
    s8 unk85;
} Obj800FD9BC;

/* src/slus/func_8003CD08.c */
typedef struct {
    u8 pad0[0x2];
    s8 unk2;
    u8 pad3[0x68 - 0x3];
    s32* unk68;
    u8 pad6C[0xD5 - 0x6C];
    s8 unkD5;
    u8 padD6[0xF8 - 0xD6];
    u8 unkF8;
} Obj8003CD08;

/* src/rockx5/func_800F0658_ovl01.c */
typedef struct Obj0658 {
    /* 0x00 */ u8 pad0[0x6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0xE];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
} Obj0658;

/* src/rockx5/func_800F5928_ovl04.c */
typedef struct Obj5928 {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ u8 state;
    /* 0x06 */ u8 sub;
    /* 0x07 */ u8 pad7[0x7C - 0x07];
    /* 0x7C */ s16 timer;
    /* 0x7E */ u8 pad7E[0x98 - 0x7E];
    /* 0x98 */ s32 unk98;
} Obj5928;

/* src/rockx5/func_800F846C_ovl11.c */
typedef struct Ent846C {
    u8 pad0[0x6];
    u8 unk6;
    u8 pad7[0x8 - 0x7];
    s32 unk8;
    u8 padC[0x50 - 0xC];
    s32 unk50;
    s32 unk54;
    u8 pad58[0x8C - 0x58];
    s32 unk8C;
    s32 unk90;
    u8 pad94;
    u8 unk95;
} Ent846C;

/* src/rockx5/func_800F9AD8_ovl06.c */
typedef struct Obj9AD8 {
    /* 0x00 */ u8 pad0[0x6];
    /* 0x06 */ u8 state;
    /* 0x07 */ u8 pad7[0x49];
    /* 0x50 */ u8* unk50;
    /* 0x54 */ u8* unk54;
    /* 0x58 */ u8 pad58[0x24];
    /* 0x7C */ s16 timer;
} Obj9AD8;

/* src/rockx5/func_800F0F2C_ovl04.c */
typedef struct {
    u8 pad0[6];
    u8 unk6;
    u8 pad7[0x15 - 0x7];
    u8 unk15;
    u8 pad16[0x7C - 0x16];
    s16 unk7C;
} Obj800F0F2C;

/* src/rockx5/func_800F5254_ovl04.c */
typedef struct Obj5254 {
    u8 pad0[6];
    u8 unk6;
    u8 pad7[0x20 - 7];
    s32 unk20;
    u8 pad24[0x7C - 0x24];
    s16 unk7C;
} Obj5254;

/* src/rockx5/func_800F81F4_ovl11.c */
typedef struct {
    u8 pad0[0xA];
    s16 unkA;
    u8 padC[0x15 - 0xC];
    u8 unk15;
    u8 pad16[0x20 - 0x16];
    s32 unk20;
} Obj800F81F4;

/* src/rockx5/func_800FA8D8_ovl01.c */
typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x7C - 7];
    s16 unk7C;
    u8 pad7E[0x93 - 0x7E];
    s8 unk93;
    u8 unk94;
} Obj800FA8D8;

/* src/slus/func_80023788.c */
typedef struct {
    s32 w[0x6F];
} Blk1BC;

/* src/slus/func_80044BD8.c */
typedef struct {
    void* fn[7];
} FnTbl7;

/* src/slus/func_80019DF0.c */
typedef struct {
    u8 pad[0x1B8];
    s8 f1B8[1];
} D1C00_80019DF0;

/* src/slus/func_8003FCC0.c */
typedef struct {
    u8 pad0[0x94];
    /* 0x94 */ s8 unk94[7];
    /* 0x9B */ s8 unk9B[6];
    /* 0xA1 */ u8 unkA1;
} Obj8003FCC0;

/* src/slus/func_80012FE4.c */
typedef struct {
    u8 pad[0x60];
    s16 f60[8];
} Obj80012FE4;

/* src/rockx5/func_800F2230_ovl08.c */
typedef struct {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5[5];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[0x40];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ u8 pad54[0xC];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 pad61[0x1B];
    /* 0x7C */ void* unk7C; /* an Obj2230 */
} Obj2230;

/* src/rockx5/func_800F3EA0_ovl04.c */
typedef struct {
    u8 pad0[0xC];
    s8 unkC;
    u8 padD[2];
    s8 unkF;
    u8 pad10[0x10];
    void* unk20;
    s8 unk24;
    s8 unk25;
    u8 pad26[0xA2 - 0x26];
    s8 unkA2;
} Glb800F3EA0;

/* src/rockx5/func_800F3EA0_ovl04.c */
typedef struct {
    u8 pad0[0x24];
    s16 unk24;
    s16 unk26;
    u8 pad28[0x57 - 0x28];
    s8 unk57;
    u8 pad58[0xAB - 0x58];
    s8 unkAB;
} Bg800F3EA0;

/* src/rockx5/func_800F8128_ovl07.c */
/* 0xA4-byte object image copied whole */
typedef struct {
    s32 d[0x29];
} Blk0A4;

/* src/rockx5/func_800F8128_ovl07.c */
/* 4-byte unaligned record */
typedef struct {
    u8 d[4];
} Blk4;

/* src/rockx5/func_800F26B4_ovl10.c */
typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0xE - 7];
    u16 unkE;
    u8 pad10[0x68 - 0x10];
    u8* unk68;
    u8 pad6C[0x90 - 0x6C];
    u8 unk90;
} Ent26B4;

/* src/rockx5/func_800F306C_ovl11.c */
typedef struct {
    s8 f0;
    u8 f1[1];
} Tbl9B8C;

/* src/rockx5/func_800F306C_ovl11.c */
typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5[5];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[5];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[9];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x20];
    /* 0x50 */ u8* unk50;
    /* 0x54 */ u8* unk54;
    /* 0x58 */ u8 pad58[8];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 pad61[6];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ u8* unk68;
} Obj306C;

/* src/rockx5/func_800F69FC_ovl03.c */
typedef struct {
    u16 v[3];
} Tbl800EEB44;

/* src/rockx5/func_800EE974_ovl20.c */
typedef struct {
    u8 pad[0xC6];
    s8 c6[4];
    s8 ca;
} D_800D1C00_t;

/* src/slus/func_8003EC00.c */
typedef struct {
    u8 b;
} QByte;

/* src/rockx5/func_800EEE24_ovl27.c */
/* 0x80-byte block copied from the scratchpad buffer */
typedef struct {
    u8 d[0x80];
} Blk80;

/* src/rockx5/func_800EEE24_ovl27.c */
/* 0x20-byte block copied from the scratchpad buffer */
typedef struct {
    u8 d[0x20];
} Blk20;

/* src/rockx5/func_800F2970_ovl24.c */
typedef struct {
    s32 w[86];
} Blk158;

/* src/rockx5/func_800F2970_ovl24.c */
typedef struct {
    u8 pad0[0x26];
    u16 a26[16];
    u8 pad46[5];
    u8 u4B[7];
    u8 u52[6];
    u8 pad58[8];
    s32 a60[32];
    u8 padE0[8];
    u8 uE8[4];
    u8 uEC[4];
    u8 padF0[2];
    u8 uF2[32];
    u8 u112[32];
    u8 u132[32];
    u8 u152[2];
    s16 sum;
} Rec2970;

/* src/slus/func_8001AAE8.c */
typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
} StHdr8130; /* 0x20 */

/* src/slus/func_80014DEC.c, src/slus/func_80015068.c */
typedef struct Rec5A58 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 pad2[2];
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u16 unk8;
    /* 0x0A */ u8 padA[2];
} Rec5A58;

/* src/rockx5/func_800F38F4_ovl26.c */
typedef struct {
    u8 b[3][16];
} Tbl800EE9A8;

/* src/rockx5/func_800F39A8_ovl28.c */
typedef struct {
    u8 b[3][3];
} Tbl39A8;

/* src/rockx5/func_800EEF88_ovl07.c */
typedef struct {
    u8 pad[0x5C];
    s8 f5C;
} V5C;

/* src/rockx5/func_800F24C4_ovl07.c */
typedef struct {
    u8 pad[4];
    u16 f4[1];
} D1030;

/* src/slus/func_8003C20C.c */
typedef struct {
    u8 pad[0x88];
    s32 f88[1];
} D_800D1C00_f88_t;

/* src/slus/func_8001D580.c */
typedef struct {
    u8 b[18];
} Str18;

/* src/slus/func_8001D580.c */
typedef struct {
    Str18 s;
    u8 pad[2];
} Name20;

/* src/rockx5/func_800EF9D0_ovl24.c */
typedef struct {
    u8 pad[0x114];
    s32 w[1];
} Obj114;

/* src/rockx5/func_800F3444_ovl29.c */
typedef struct {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[4];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[9];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8* unk30;
    /* 0x34 */ u8 pad34[0xC];
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u8 pad42[0xE];
    /* 0x50 */ u8* unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ u8* unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 unk61;
    /* 0x62 */ u8 unk62;
    /* 0x63 */ u8 pad63[4];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x1E];
    /* 0x8A */ u8 unk8A;
} ObjF3444;
/* lift: end */

/* X4 object views shared by the W15 X6 ports (adapted from mmx6 x4.h, AGPL-3.0, THIRD_PARTY.md); fields only where
 * a draft touches them (T3.c3). */
typedef struct {
    s16 lo;
    s16 hi;
} X4_S16Pair;

typedef union {
    s32 val;
    X4_S16Pair i;
    Ent3CC_Half u;
    u8 bytes[4];
} X4_f32; /* 16.16 fixed */

/* src/rockx5/func_800FA99C_ovl52.c (after X4_f32) */
typedef struct {
    u8 pad0[0x5E];
    s16 unk5E;
    X4_f32 unk60;
    u8 pad64[0xA0 - 0x64];
    u8 unkA0;
} D_8009A1F8_99C_t;

/* the object header shared by player, main, weapon, visual and misc objects */
typedef struct X4_Obj {
    /* 0x00 */ s8 active;
    /* 0x01 */ s8 id;
    /* 0x02 */ s8 unk2;
    /* 0x03 */ s8 on_screen;
    /* 0x04 */ s8 state;
    /* 0x05 */ s8 unk5;
    /* 0x06 */ s8 unk6;
    /* 0x07 */ s8 unk7;
    /* 0x08 */ X4_f32 x_pos;
    /* 0x0C */ X4_f32 y_pos;
    /* 0x10 */ void* backref;
    /* 0x14 */ s8 bg_offset;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ X4_f32 unk18;
    /* 0x1C */ X4_f32 unk1C;
    /* 0x20 */ X4_f32 x_vel;
    /* 0x24 */ X4_f32 y_vel;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u32** animation_table;
    /* 0x34 */ u32* animation_cursor;
    /* 0x38 */ void* unk38;
    /* 0x3C */ void* unk3C;
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0xC];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ void* unk58;
    /* 0x5C */ s8 hp;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ s8 unk60;
    /* 0x61 */ u8 pad61[3];
    /* 0x64 */ s8 unk64;
    /* 0x65 */ u8 pad65[3];
    /* 0x68 */ Unk800770CC* unk68; /* x4.h X4_Unk_unk68 */
    /* 0x6C */ u8 pad6C[4];
    /* 0x70 */ u8 unk70;
    /* 0x71 */ s8 unk71;
    /* 0x72 */ u8 pad72[0xA];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ u8 pad7E[2];
    /* 0x80 */ u32 unk80;
    /* 0x84 */ u8 pad84[4];
    /* 0x88 */ s32 unk88;
    /* 0x8C */ s8 afterimage; /* player */
} X4_Obj;

/* src/rockx5/func_800F0DAC_ovl02.c (after X4_f32; X4_Obj differs in field types) */
typedef struct Obj0DAC {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ signed char unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7;
    /* 0x08 */ X4_f32 x;
    /* 0x0C */ X4_f32 y;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 f20;
    /* 0x24 */ s32 f24;
    /* 0x28 */ s32 f28;
    /* 0x2C */ s32 f2C;
    /* 0x30 */ void* unk30;
    /* 0x34 */ u8 pad34[0x1C];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ void* unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 unk61;
    /* 0x62 */ u8 pad62[5];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ void* unk68;
    /* 0x6C */ u8 pad6C[4];
    /* 0x70 */ u8 unk70;
} Obj0DAC;

/* D_800D1C00 / D_8009A420 */
typedef struct X4_EngineObj {
    /* 0x00 */ u8 pad0[7];
    /* 0x07 */ s8 unk7;
    /* 0x08 */ u8 pad8[2];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s8 stage;
    /* 0x0D */ s8 substage;
    /* 0x0E */ u8 padE[6];
    /* 0x14 */ s8 unk14;
    /* 0x15 */ u8 pad15[3];
    /* 0x18 */ s8 unk18;
    /* 0x19 */ u8 pad19[4];
    /* 0x1D */ s8 checkpoint;
} X4_EngineObj; /* 0x1E; was 0x1A before checkpoint */

/* D_8009A1F8[3] as background layers */
typedef struct X4_BackgroundObj {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ s8 unk3;
    /* 0x04 */ u8 pad4[4];
    /* 0x08 */ X4_f32 x_pos;
    /* 0x0C */ X4_f32 y_pos;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ X4_f32 unk14;
    /* 0x18 */ X4_f32 unk18;
    /* 0x1C */ u8 pad1C[2];
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 unk22;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ s16 unk26;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ s16 unk2C;
    /* 0x2E */ s16 unk2E;
    /* 0x30 */ s16 unk30;
    /* 0x32 */ s16 unk32;
    /* 0x34 */ u16 unk34;
    /* 0x36 */ s8 unk36;
    /* 0x37 */ s8 unk37;
    /* 0x38 */ u8 pad38[2];
    /* 0x3A */ s8 unk3A;
    /* 0x3B */ u8 pad3B;
    /* 0x3C */ s8 unk3C;
    /* 0x3D */ u8 pad3D;
    /* 0x3E */ s8 unk3E[2];
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44;
    /* 0x45 */ s8 unk45;
    /* 0x46 */ u8 pad46[4];
    /* 0x4A */ s8 unk4A;
    /* 0x4B */ s8 unk4B;
    /* 0x4C */ u8 pad4C[8];
} X4_BackgroundObj; /* 0x54 */

// from slus 8001A628: the 0x14-byte display env copied out of the double buffer (2-aligned: lwl/lwr)
typedef struct {
    /* 0x00 */ Ovl50Pos disp;
    /* 0x08 */ Ovl50Pos screen;
    /* 0x10 */ u8 pad10[4];
} DbDispEnv; /* 0x14 */

// from slus 8001728C (X6 X4_RectPtrPair): 0xC-byte rect + pointer pair
typedef struct {
    /* 0x00 */ Ovl50Pos rect;
    /* 0x08 */ void* ptr;
} RectPtrPair; /* 0x0C */

// from slus 8002DB3C: 0x30-byte effect slot table entry (X4_Obj is 0x90 in X5)
typedef struct EffectSlot30 {
    /* 0x00 */ s8 active;
    /* 0x01 */ s8 id;
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad3[0x2D];
} EffectSlot30; /* 0x30 */

// from rockx5 800EECF8_ovl29 (shared with 800EEF84_ovl29): X4_Obj-like, 0x61/0x67 bytes, 0x8C s32
typedef struct ObjEECF8 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ s8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7;
    /* 0x08 */ X4_f32 x;
    /* 0x0C */ X4_f32 y;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ void* unk30;
    /* 0x34 */ u8 pad34[0x1C];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ void* unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 unk61;
    /* 0x62 */ u8 pad62[5];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ Unk800770CC* unk68;
    /* 0x6C */ u8 pad6C[4];
    /* 0x70 */ u8 unk70;
    /* 0x71 */ u8 pad71[0xB];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ u8 pad7E[2];
    /* 0x80 */ s32 unk80;
    /* 0x84 */ u8 pad84[4];
    /* 0x88 */ s32 unk88;
    /* 0x8C */ s32 unk8C;
} ObjEECF8;

/* src/rockx5/func_800F5308_ovl27.c, func_800F50BC_ovl27.c */
typedef struct Scr5308 {
    /* 0x00 */ u8 pad0[0x80];
    /* 0x80 */ s32 unk80;
    /* 0x84 */ s16 unk84;
    /* 0x86 */ u8 unk86;
    /* 0x87 */ u8 unk87;
    /* 0x88 */ u8 unk88;
    /* 0x89 */ u8 unk89;
} Scr5308;

/* src/rockx5/func_800EF094_ovl03.c, func_800EF220_ovl03.c */
typedef struct ObjEF094 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 pad1;
    /* 0x02 */ signed char unk2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ signed char unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ void* unk30;
    /* 0x34 */ u8 pad34[0x1C];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ void* unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 unk61;
    /* 0x62 */ u8 pad62[5];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x14];
    /* 0x80 */ s32 unk80;
    /* 0x84 */ s32 unk84;
    /* 0x88 */ s32 unk88;
    /* 0x8C */ s32 unk8C;
    /* 0x90 */ s32 unk90;
    /* 0x94 */ s32 unk94;
} ObjEF094;

// from rockx5 800F1334_ovl05: scratchpad slot holding the last spawned child
typedef struct Scr1334 {
    /* 0x00 */ u8 pad0[0x80];
    /* 0x80 */ void *unk80;
} Scr1334;

// from rockx5 800F1334_ovl05: spawned child copies the parent's 0x14/0x15/0x3C/0x40/0x42
typedef struct Obj1334 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[5];
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x1A];
    /* 0x30 */ u8 *unk30;
    /* 0x34 */ u8 pad34[8];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0x38];
    /* 0x7C */ void *unk7C; /* the parent Obj1334 */
    /* 0x80 */ u8 pad80[0x11];
    /* 0x91 */ u8 unk91;
} Obj1334;

// from rockx5 800F1B8C_ovl05
typedef struct Obj1B8C {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad3[2];
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x3E];
    /* 0x45 */ s8 unk45;
    /* 0x46 */ u8 pad46[0x42];
    /* 0x88 */ u16 unk88;
    /* 0x8A */ u16 unk8A;
    /* 0x8C */ u8 pad8C;
    /* 0x8D */ u8 unk8D;
    /* 0x8E */ u8 pad8E;
    /* 0x8F */ u8 unk8F;
    /* 0x90 */ u8 unk90;
    /* 0x91 */ u8 unk91;
    /* 0x92 */ s8 unk92;
} Obj1B8C;

// from rockx5 800F24D4_ovl02: scratchpad slot 0x1F80004C view
typedef struct Scr24D4 {
    /* 0x00 */ u8 pad0[0x88];
    /* 0x88 */ s16 unk88;
} Scr24D4;

/* src/rockx5/func_800EF82C_ovl29.c */
typedef struct ObjEF82C {
    /* 0x00 */ u8 pad0[5];
    /* 0x05 */ s8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7;
    /* 0x08 */ s32 x; /* 16.16 */
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[4];
    /* 0x28 */ s32 unk28;
    /* 0x2C */ u8 pad2C[0x34];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 pad61[0xF];
    /* 0x70 */ u8 unk70;
    /* 0x71 */ u8 pad71[0x13];
    /* 0x84 */ s32 unk84;
} ObjEF82C;


// from rockx5 800F5B44: spawned child placed beside its parent, facing-dependent offset
typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[5];
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0x1A];
    /* 0x30 */ s32 unk30;
    /* 0x34 */ u8 pad34[8];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0x38];
    /* 0x7C */ void* unk7C; /* the parent ObjF5B44 */
} ObjF5B44;

// from rockx5 800F5CA0: init state of an object whose variant (unk2) picks animation and velocity
typedef struct ObjF5CA0 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u8 pad8[0xD];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[9];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x20];
    /* 0x50 */ void* unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ u8 pad58[4];
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 pad61[6];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ void* unk68;
} ObjF5CA0;

/* src/rockx5/func_800F50BC_ovl27.c */
typedef struct Ent50BC {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ s8 unk5;
    /* 0x06 */ u8 pad6[2];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[8];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 pad20[0x30];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ void* unk58;
    /* 0x5C */ u8 pad5C[0x20];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ s16 unk7E;
} Ent50BC;

/* src/rockx5/func_800F5308_ovl27.c */
typedef struct Ent5308 {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ void* unk30;
    /* 0x34 */ u8 pad34[0x1C];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ void* unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 unk61;
    /* 0x62 */ u8 pad62[5];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ s32 unk68;
} Ent5308;

// memory-card path "buXY:" head, copied by value (slus 8001D6BC, 8001D8B4; X6/X4 X4_MemcardPath)
typedef struct MemcardPath {
    u8 path[6];
} MemcardPath;

// from rockx5 800F2074_ovl26: pointee of scratchpad view Scr2074.unk80
typedef struct Sub2074 {
    /* 0x00 */ u8 pad0[0x88];
    /* 0x88 */ s32 unk88;
    /* 0x8C */ u8 pad8C[0x3];
    /* 0x8F */ u8 unk8F;
    /* 0x90 */ u8 pad90[0x2];
    /* 0x92 */ u8 unk92;
} Sub2074;

// from rockx5 800F2074_ovl26: scratchpad slot 0x1F80004C view
typedef struct Scr2074 {
    /* 0x00 */ u8 pad0[0x80];
    /* 0x80 */ Sub2074* unk80;
    /* 0x84 */ u8 pad84[0x4];
    /* 0x88 */ s32 unk88;
    /* 0x8C */ u8 pad8C;
    /* 0x8D */ u8 unk8D;
    /* 0x8E */ u8 pad8E;
    /* 0x8F */ u8 unk8F;
    /* 0x90 */ u8 unk90;
    /* 0x91 */ u8 unk91;
    /* 0x92 */ u8 unk92;
    /* 0x93 */ u8 unk93;
    /* 0x94 */ u8 unk94;
    /* 0x95 */ u8 pad95;
    /* 0x96 */ u8 unk96;
    /* 0x97 */ u8 unk97;
} Scr2074;

// from rockx5 800F6864_ovl26 (W22 hoist, T10.c13)
typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7;
    /* 0x08 */ Fix0418 unk8;
    /* 0x0C */ Fix0418 unkC;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8* unk30;
    /* 0x34 */ u8 pad34[0x1C];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 unk61;
    /* 0x62 */ u8 pad62[5];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ s32 unk68;
} Ent6864;

// from rockx5 800F6A48_ovl26 (W22 hoist, T10.c13)
typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ Fix0418 unk8;
    /* 0x0C */ Fix0418 unkC;
    /* 0x10 */ u8 pad10[6];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[9];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x20];
    /* 0x50 */ u8* unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ u8 pad58[4];
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 pad61[6];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ u8* unk68;
} Ent6A48;

// from rockx5 800F48B0_ovl09 (shared with func_800FCDBC_ovl35) (W22 hoist, T10.c13)
typedef struct Ent48B0 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[4];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ s16 unkE;
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
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0xC];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ void* unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 pad61[6];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x10];
    /* 0x7C */ void* unk7C; /* Ent48B0* (self pointer; shapes.py has no incomplete types) */
    /* 0x80 */ u8 pad80[4];
    /* 0x84 */ s32 unk84;
    /* 0x88 */ u8 pad88[4];
    /* 0x8C */ s32 unk8C;
} Ent48B0;

// from rockx5 800F7240_ovl03 (shared with func_800FE22C_ovl31) (W22 hoist, T10.c13)
typedef struct Ent7240 {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 pad6[4];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17[9];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ u8 pad34[8];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
    /* 0x44 */ u8 pad44[0xC];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ void* unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[3];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 pad61[6];
    /* 0x67 */ u8 unk67;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ u8 pad6C[0x10];
    /* 0x7C */ void* unk7C; /* Ent7240* (self pointer; shapes.py has no incomplete types) */
    /* 0x80 */ u8 pad80[4];
    /* 0x84 */ s32 unk84;
} Ent7240;

// from rockx5 800F3160_ovl09 (shared with func_800FB66C_ovl35) (W22 hoist, T10.c13)
typedef struct Ent3160 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[3];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[9];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[0xA];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ u8 pad2C[0x1B];
    /* 0x47 */ u8 unk47;
    /* 0x48 */ u8 pad48[0xC];
    /* 0x54 */ s32 unk54;
    /* 0x58 */ u8 pad58[0x24];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ s16 unk7E;
    /* 0x80 */ u8 pad80[4];
    /* 0x84 */ s32 unk84;
    /* 0x88 */ s32 unk88;
    /* 0x8C */ u8 pad8C[4];
    /* 0x90 */ u8 unk90;
    /* 0x91 */ u8 unk91;
} Ent3160;

// from rockx5 800EFDDC_ovl09 (W22 hoist, T10.c13)
typedef struct {
    u8 pad0[0x2];
    s8 unk2;
    u8 pad3[0x1];
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 pad7[0x1];
    s32 unk8;
    s32 unkC;
    u8 pad10[0x4];
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 pad17[0x1];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    u8 pad34[0x1C];
    s32 unk50;
    s32 unk54;
    s32 unk58;
    u8 unk5C;
    u8 pad5D[0x3];
    u8 unk60;
    u8 unk61;
    u8 pad62[0x5];
    u8 unk67;
    s32 unk68;
    u8 pad6C[0x4];
    u8 unk70;
    u8 pad71[0x9];
    u8 unk7A;
    u8 pad7B[0x5];
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
} ObjEFDDC;

// from rockx5 800F2074_ovl26 (W22 hoist, T10.c13)
typedef struct {
    /* 0x00 */ u8 pad0[0x2];
    /* 0x02 */ signed char unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u8 pad8[0x2];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 padC[0x2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ u8 pad10[0x4];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32* unk30;
    /* 0x34 */ u8 pad34[0xC];
    /* 0x40 */ s16 unk40;
    /* 0x42 */ u8 pad42[0xE];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32* unk54;
    /* 0x58 */ s32* unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ u8 pad5D[0x3];
    /* 0x60 */ u8 unk60;
    /* 0x61 */ u8 unk61;
    /* 0x62 */ u8 unk62;
    /* 0x63 */ u8 pad63[0x5];
    /* 0x68 */ s32 unk68;
} Ent2074;

// from rockx5 800F6E48_ovl26 (W22 hoist, T10.c13)
typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0xE];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
} Ent6E48;

#endif /* TYPES_H */
