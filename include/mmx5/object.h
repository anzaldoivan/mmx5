#ifndef MMX5_OBJECT_H
#define MMX5_OBJECT_H

#include "types.h"

// Object slot structs: one row per member in config/types/fields.tsv; notes checked by tools/readability/objfields.py.

// +0x54 of Obj8002CC08: cleared as one s32 (sw), counted down as two s16 (lh/sh)
typedef union {
    s32 w;
    s16 h[2];
} Word8002CC08;

// 0x9C slot of D_80092090 (48), D_80098120 (32), g_projectiles (32)
typedef struct Obj8002CC08 {
    s8 active;          // +0x00 read by func_8002CC08
    s8 id;              // +0x01 read by func_8004B378; X4_Obj +0x01 id, compared with ids 0x2C, 0x18..0x1A
    u8 pad2;            // +0x02 read by func_80023058
    s8 on_screen;       // +0x03 written by func_80023108; X4_Obj +0x03 on_screen
    u8 pad4[0x4C];      // +0x04 read by func_80019FD0
    s32 unk50;          // +0x50 written by func_8002CC08
    Word8002CC08 unk54; // +0x54 written by func_8002CC08
    u8 pad58[0x10];     // +0x58 written by func_80023058
    s32 unk68;          // +0x68 written by func_8002CC08
    u8 pad6C[0x30];     // +0x6C read by func_80045A18
} Obj8002CC08;

// 0xA4 slot of g_class4_slots (64)
typedef struct Obj8002CD14 {
    s8 active;      // +0x00 read by func_8002CD14
    u8 pad1[0x4F];  // +0x01 read by func_80055450
    s32 unk50;      // +0x50 written by func_8002CD14
    s32 unk54;      // +0x54 written by func_8002CD14
    u8 pad58[0x10]; // +0x58 written by func_80055450
    s32 unk68;      // +0x68 written by func_8002CD14
    u8 pad6C[0x38]; // +0x6C read by func_8002DCD8
} Obj8002CD14;

// 0x70 slot of D_80094398 (96)
typedef struct Slot8002D0E4 {
    s8 active;    // +0x00 read by find_free_visual_obj
    u8 pad[0x6F]; // +0x01 read by func_80046900
} Slot8002D0E4;

// 0x60 slot of D_800D1F40 (128), D_8009F9A0 (64)
typedef struct Slot8002D27C {
    s8 active;    // +0x00 read by alloc_class6_slot
    u8 pad[0x5F]; // +0x01 read by func_8004E2F4
} Slot8002D27C;

// 0x30 slot of g_class3_slots (96) (X4_Obj is 0x90 in X5)
typedef struct EffectSlot30 {
    s8 active;     // +0x00 read by func_8002CE20
    s8 id;         // +0x01 read by func_8002CE20
    s8 unk2;       // +0x02 read by func_8002CE20
    u8 pad3[0x2D]; // +0x03 written by func_8002CE20
} EffectSlot30;

// 0x30 slot of g_class3_slots (96) and g_class7_slots (4)
typedef struct Slot8002D144 {
    s8 active;    // +0x00 read by alloc_class3_slot
    u8 pad[0x2F]; // +0x01 unreferenced
} Slot8002D144;

// Pool homes (docs/memory-map.md, Object pools): one member per element type its readers use (cookbook C0463).
// A member of extent 1 marks a pool end: its readers only compare against the address.
extern u8 D_80092090[];
extern union {
    u8 u[0x1380];
    Obj8002CC08 cc08[32];
} D_80098120;
extern union {
    u8 u[0x1380];
    u8 r[32][0x9C];
    Obj8002CC08 cc08[32];
    Slot8002D0E4 d0e4[1];
} g_projectiles;
extern union {
    u8 u[0x2A00];
    Slot8002D0E4 d0e4[96];
} D_80094398;
extern union {
    u8 u[0x1200];
    EffectSlot30 eff[96];
    Slot8002D144 d144[96];
    X4_Obj x4[0x20];
} g_class3_slots;
extern union {
    u8 u[0x3000];
    s8 s[0x3000];
    Slot8002D27C d27c[128];
} D_800D1F40;
extern union {
    u8 u[0x2900];
    Obj8002CD14 cd14[64];
} g_class4_slots;
extern union {
    u8 u[0x1800];
    u8 r[64][0x60];
    Slot8002D27C d27c[64];
} D_8009F9A0;
extern union {
    u8 u[0xC00];
    s8 s[0xC00];
    Slot8002D27C d27c[32];
    Obj8002CC08 cc08[1];
} D_800994A0;
extern union {
    u8 u[0xC0];
    Slot8002D144 d144[4];
} g_class7_slots;
extern union {
    u8 u[0x19C];
    Slot8002D27C d27c[1];
} D_800D4F40;
extern union {
    u8 b;
    Obj8002CD14 cd14[1];
} D_800C9310;
extern union {
    u16 h[0x2000];
    Slot8002D27C d27c[1];
} D_800A11A0;

void clear_object_slot();
void move_object();
Slot8002D27C* alloc_class6_slot();

#endif
