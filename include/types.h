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

#endif /* TYPES_H */
