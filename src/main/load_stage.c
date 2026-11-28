#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"

extern void read_rock_bin_member(s32, s32);
extern void wait_rock_bin_read(void);
extern s32 get_launch_variant(void);
extern void setup_file_load(s32, s32, s32);
extern void wait_for_file_load(s32, s32);
extern void copy_palette_buffers(void);
extern s32 g_ovl_base;
extern u8 g_ovl_idx_stage_c[];
extern u8 g_ovl_idx_stage_sub[];
extern void* D_8006FD94[][2];
extern void* D_8006FE4C[][2];
extern void* D_8006FF04[][2];
extern void* D_8006FFBC[][2];
extern void* D_8007012C[][2];
extern void* D_80070074[][2];
extern void* D_800701E4[][2];
extern u8 D_8006FC64[];
extern u8 D_8006FC94[];
extern u8 D_8006FCB0[];
extern u8 D_8006FD30[];
extern u8 D_8006FCEB;
extern u8 D_8006FD1B;
extern u8 D_8006FC98[];
extern u8 D_8006FC9C[];
extern u8 D_8006FCA0[];
extern u8 D_8006FCA4[];
extern u8 D_8006FCA8[];
extern u8 D_8006FCAC[];
extern u8 D_8006FCD0[];
extern u8 D_8006FD00[];
extern u8 D_8006FCBC[];
extern u8 D_8006FD3C[];
extern u8 D_8006FCE6;
extern u8 D_8006FD16;
extern u16* D_800A51A0;
extern u8 D_800D1DBC;
extern u8 D_800D1DBD;
extern u8 D_800EF37C_ovl23[];
extern u8 D_80077614[];
extern u16 g_tilemap_layer_stride;

void load_stage(void) {
    s8* p = g_playthrough_state.s;
    s32 c;
    s32 d;
    s32 e;
    u8 t;
    u8 s;
    s32 k;
    s32 i;
    s32 j;

    if (p[0xC] == 0xB) {
        read_rock_bin_member(g_ovl_idx_stage_c[p[0x1D]], 0x800FA000);
        wait_rock_bin_read();
    }
    read_rock_bin_member(g_ovl_idx_stage_sub[p[0xD] + p[0xC] * 2], g_ovl_base);
    wait_rock_bin_read();
    d = p[0xD];
    c = p[0xC];
    D_1F800080 = D_8006FD94[c][d];
    D_1F800084 = D_8006FE4C[c][d];
    D_1F800088 = D_8006FF04[c][d];
    D_1F80008C = D_8006FFBC[c][d];
    D_1F800090 = D_8007012C[c][d];
    D_1F800094 = D_80070074[c][d];
    D_1F800098 = D_800701E4[c][d];
    D_8006FC64[0x1E] = D_8006FC94[p[0x44]];
    if (c == 0xD && d != 0) {
        D_8006FC64[0x1B] = D_8006FCB0[((u8*)p)[0x41] - 1];
        D_8006FCEB = D_8006FD30[((u8*)p)[0x41] - 1];
        D_8006FD1B = D_8006FD30[((u8*)p)[0x41] - 1];
    }
    if (p[0xC] == 9) {
        D_8006FC64[p[0xC] * 2] = D_8006FC98[get_launch_variant()];
        D_8006FCD0[p[0xC] * 2] = D_8006FC9C[get_launch_variant()];
        D_8006FD00[p[0xC] * 2] = D_8006FCA0[get_launch_variant()];
    }
    if (p[0xC] == 10) {
        D_8006FC64[p[0xC] * 2] = D_8006FCA4[get_launch_variant()];
        D_8006FCD0[p[0xC] * 2] = D_8006FCA8[get_launch_variant()];
        D_8006FD00[p[0xC] * 2] = D_8006FCAC[get_launch_variant()];
    }
    if (p[0xC] == 0xB) {
        e = p[0x1D];
        D_8006FC64[0x16] = D_8006FCBC[e];
        t = D_8006FD3C[e];
        D_8006FCE6 = t;
        D_8006FD16 = t;
    }
    s = p[0xC];
    if ((u8)(s - 0xD) < 3 || (s8)s == 0xB) {
        setup_file_load(D_8006FC64[p[0xD] + (s8)s * 2], 0, 0);
    } else {
        setup_file_load(D_8006FC64[p[0xD] + (s8)s * 2], 3, 0);
    }
    wait_for_file_load(0, 0);
    if (p[0x44] == 0) {
        setup_file_load(D_8006FCD0[p[0xD] + p[0xC] * 2], 1, 0);
    } else {
        setup_file_load(D_8006FD00[p[0xD] + p[0xC] * 2], 1, 0);
    }
    wait_for_file_load(0, 1);
    D_800A51A0 = (u16*)D_800BE9A8.w;
    {
        u16* src = (u16*)D_1F800008;
        u16* dst = D_800A51A0;
        i = (u32)(D_1F80000C - D_1F800008) >> 1;

        while (i > 0) {
            *dst++ = *src++;
            i--;
        }
        D_800BE9A8.w = (s32)dst;
    }
    k = p[0xC];
    if (k == 0xB) {
        j = p[0x1D] * 2;
        D_800D1DBC = D_800EF37C_ovl23[j];
        D_800D1DBD = D_800EF37C_ovl23[j + 1];
    } else {
        i = k * 4 + p[0xD] * 2;
        D_800D1DBC = D_80077614[i];
        D_800D1DBD = D_80077614[i + 1];
    }
    g_tilemap_layer_stride = D_800D1DBC * D_800D1DBD;
    copy_palette_buffers();
    D_800C9310.b |= 1;
}
