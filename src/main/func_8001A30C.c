#include "types.h"
#include "mmx5/globals.h"
#define D_800C931C_as_Pad800218E0 (*(Pad800218E0*)&g_pad1_buttons)

void func_8001A628(s32 arg0, s32 arg1);
void func_8001B268(u32 vol);
void func_8001B2E0(s32 stereo);
s32 func_8001B034(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
int VSync(int mode);
s32 PutDispEnv(void*);
s32 func_8001AAE8(s32, s32);
void func_8001B0E8(void);
void func_8001255C(void);
void SetDispMask(s32);
void ClearImage(Ovl50Pos*, s32, s32, s32);
s32 DrawSync(s32);
void func_8001B10C(void);

extern s32 D_800E80B8;
extern s32 D_800E80BC;
extern s32 D_800E80C0;
extern s32 D_800E80C4;
extern DbDispEnv D_800E80D0[];
extern u8 D_80070C34[];
extern s8 D_800E80AD;
extern s32 D_800E80B4;
extern u8 g_draw_info_buffers[];

void func_8001A30C(void) {
    Ovl50Pos rect = {0, 0, 0x1E0, 0xF0};
    s32 done;
    s32 y;
    s32 t;
    u8* p;
    u8* q;
    Pad800218E0* pad;

    D_800E80B8 = 0x80105000;
    D_800E80BC = 0x80109000;
    D_800E80C0 = 0x80117000;
    D_800E80C4 = 0x80125000;
    func_8001A628(0x140, 0xF0);
    func_8001B268(0x80);
    func_8001B2E0(1);
    D_800E80AD = 1;
    p = D_80070C34;
    done = func_8001B034(0xAC, 1, *(u16*)(p + 4), D_800E80C4, *(u16*)(p + 6),
                         D_800E80BC, D_800E80C0, D_800E80B8, 1, 1);
    D_800E80B4 = 0;
    while (done == 0) {
        y = 0;
        t = D_800E80B4 ^ 1;
        D_800E80B4 = t;
        if (t != 0) {
            y = 0xF0;
        }
        done = func_8001AAE8(0, y);
        func_8001B0E8();
        VSync(0);
        func_8001255C();
        pad = &D_800C931C_as_Pad800218E0;
        q = D_80070C34;
        if (pad->unk4 & *(u16*)(q + 0xA)) {
            done = 1;
        }
        PutDispEnv(g_draw_info_buffers + D_800E80B4 * 0xB0);
    }
    rect.unk0 = 0;
    rect.unk2 = 0;
    rect.unk4 = 0x1E0;
    rect.unk6 = 0x1E0;
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    func_8001B10C();
    SetDispMask(0);
    D_800C931C_as_Pad800218E0.unk4 = 0;
    *(DbDispEnv*)g_draw_info_buffers = D_800E80D0[0];
    *(u16*)&D_800C931C_as_Pad800218E0 = 0;
    *(DbDispEnv*)(g_draw_info_buffers + 0xB0) = D_800E80D0[1];
    D_800E80B4 ^= 1;
    PutDispEnv(g_draw_info_buffers + D_800E80B4 * 0xB0);
    DrawSync(0);
    VSync(0);
    DrawSync(0);
}
