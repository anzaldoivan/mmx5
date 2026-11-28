#ifndef MMX5_GLOBALS_H
#define MMX5_GLOBALS_H

#include "types.h"

extern u8 g_Player[];
extern s16 D_8009A0AA;
extern union {
    u8 u[0xFC];
    s16 h[0x7E];
    s32 w[0x3F];
    s32 w21[3][21];
    X4_BackgroundObj bg[3];
    Row5C8C row[3];
    Ent9A1F8 ent[3];
    D_8009A1F8_t t;
    D_8009A1F8_5C_t t5C;
    D_8009A1F8_5E_t t5E;
    D_8009A1F8_60_t t60;
    D_8009A1F8_60A0_t t60A0;
    D_8009A1F8_8_t t8;
    D_8009A1F8_99C_t t99C;
    D_8009A1F8_AB_t tAB;
    D_8009A1F8_AD10_t tAD10;
    D_8009A1F8_B0_t tB0;
    Bg800F3EA0 bg3EA0;
} D_8009A1F8;
extern u8 D_8009A420[];
extern u16 g_pad1_buttons[];
extern union {
    u8 u[0x1BC];
    s8 s[0x1BC];
} g_playthrough_state;
extern s8 D_800D1C28[];
extern s8 D_800D1CA2;
extern u8 D_800E81D8[];
extern u8* D_800E95A8[];
// Sign pairs: one member per type its readers use (cookbook C0463).
extern union {
    u8 u;
    s8 s;
} D_8006FC28;
extern union {
    u8 u[9][3];
    s8 s[9][3];
} D_800770E8;
extern u16 D_80093E68;
extern union {
    u8 u;
    s8 s;
} D_8009A0FC;
extern union {
    u16 u;
    s16 s;
} D_8009A206;
extern union {
    u8 u;
    s8 s;
} D_8009A298;
extern u16 D_8009A42E;
extern union {
    s32 w;
    u8* p;
    s32* pw;
} D_800BE9A8;
extern union {
    u8 u;
    s8 s;
} D_800D1C10;
extern union {
    u8 u;
    s8 s;
} D_800D1C30;
extern union {
    u8 u;
    s8 s;
} D_800D1C32;
extern u16 D_800D50DE;
extern union {
    u16 u;
    s16 s;
} D_800E5A46;
extern union {
    s32 w[2];
    u32* p[2];
} D_800E8108;
extern union {
    u8 u;
    s8 s;
} D_800E9300;
extern union {
    u16 u;
    s16 s;
} D_800E9560;
// Width pairs: one member per element type its readers use (cookbook C0463).
extern union {
    u8 u[4];
    s16 h[2];
} D_8006FAE0;
extern union {
    u8 u[0x1C];
    s32 w[7];
} D_800770B0;
extern union {
    u8 u[0xF0];
    u32* p[0x3C];
} g_visual_animation_tables;
extern union {
    u8 u[0x4000];
    u16 h[0x2000];
} D_8009A790;
extern union {
    u16 h;
    u8 u;
} D_800C9320;
extern union {
    u8 u[0x40];
    u16 h[0x20];
} D_800E8540;
extern union {
    s8 s;
    u16 h;
} D_800D1C0C;
extern u8 D_800E804C;
// Shape pairs: a flat member beside each row-array or struct member its readers use (cookbook C0463).
extern union {
    u8 u[0x120];
    u8 r[3][0x60];
} D_8009A2F8;
extern union {
    u8 u[0xF0];
    u8 r[3][0x50];
} D_800942A8;
extern union {
    u8 u[0x10000];
    u8 r[0x20][0x800];
} D_800D5208;
extern union {
    s16 h[0xA8];
    s16 r[0x2A][4];
} D_800E9328;
extern union {
    u8 b;
    u8 u[2];
} D_800D1CA0;
extern union {
    u8 u[0x1C];
    Unk800770CC e[7];
} D_800770CC;
extern union {
    u8 u[0xB0];
    s8 s[0xB0];
    u8 r[1][0xB0];
} D_800D1DC0;
extern union {
    s32 w[8];
    StHdr8130 hdr;
} D_800E8130;
extern union {
    PairFB4BC e[0x3B];
    s32 w[0x3B][2];
} g_rock_bin_toc;

void animate_object();
void func_8002D9EC();
void func_8003D29C();
void func_8002FB58();
s32 func_800317B8();
struct Obj8002CC08* func_8002D1A4();
void func_8002D89C();
void func_8002F8FC();
s32 func_80031DD0();
void func_8002C50C();
struct Obj8002CD14* func_8002CD14();
struct Slot8002D27C* func_8002D27C();
void func_8004FD24();
void func_8004FD90();
s8 func_80014464();
void func_80017B5C();
void func_8001E668();
void func_8002385C();
void func_800272DC();
void func_80028B18();
void func_8002A080();
void func_8002BBF8();
void func_8002C218();
void load_palette();
void func_8002D720();
void func_8002D760();
s32 func_8003049C();
s32 func_80033024();
s32 player_check_script();
void func_8003B33C();
void func_8003D2C4();
void player_update_animation_shooting();
s32 func_80040B6C();
s32 func_80043B88();
void func_8004F5CC();
void func_80052BA0();
void player_hover_set_direction();

#endif
