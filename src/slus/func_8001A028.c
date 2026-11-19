#include "types.h"
#include "mmx5/globals.h"
#define D_800C931C_as_Pad800218E0 (*(Pad800218E0*)&D_800C931C)

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
void DrawSyncCallback(void (*)(void));
extern void func_80012BB4(void);

extern s32 D_800D1F38;
extern s32 D_800E80B8;
extern s32 D_800E80BC;
extern s32 D_800E80C0;
extern s32 D_800E80C4;
extern u8 D_800D1599;
extern DbDispEnv D_800E80D0[];
extern u8 D_80070C34[];
extern s8 D_800E80AD;
extern s32 D_800E80B0;
extern u8 D_800C9328[];

void func_8001A028(u8 arg0) {
    Ovl50Pos rect;
    u8* q;
    s32 done;
    s32 y;
    s32 t;
    u8* p;

    D_800E80B8 = D_800D1F38;
    D_800E80BC = D_800E80B8 + 0x4000;
    D_800E80C0 = D_800E80BC + 0xE000;
    D_800E80C4 = D_800E80C0 + 0xE000;
    func_8001A628(0x140, 0xF0);
    func_8001B268(0x80);
    func_8001B2E0(D_800D1599);
    q = D_80070C34;
    do { // !FAKE: loop-depth fence raises p's weight for s1
        p = q + arg0 * 0xC;
        D_800E80AD = 1;
        done = func_8001B034(*(s32*)p, 1, *(u16*)(p + 4), D_800E80C4,
                             *(u16*)(p + 6), D_800E80BC, D_800E80C0, D_800E80B8,
                             1, 1);
    } while (0);
    D_800E80B0 = 0;
    while (done == 0) {
        {
            VSync(0);
            PutDispEnv(D_800C9328 + D_800E80B0 * 0xB0);
            y = 0;
            t = D_800E80B0 ^ 1;
            D_800E80B0 = t;
            if (t != 0) {
                y = 0xF0;
            }
            done = func_8001AAE8(0, y);
            func_8001B0E8();
            func_8001255C();
            if (D_800C931C_as_Pad800218E0.unk4 & *(u16*)(p + 0xA)) {
                done = 1;
            }
        }
    }
    SetDispMask(0);
    rect.unk0 = 0;
    rect.unk2 = 0;
    rect.unk4 = 0x1E0;
    rect.unk6 = 0x1E0;
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    func_8001B10C();
    *(DbDispEnv*)D_800C9328 = D_800E80D0[0];
    *(DbDispEnv*)(D_800C9328 + 0xB0) = D_800E80D0[1];
    D_800E80B0 ^= 1;
    PutDispEnv(D_800C9328 + D_800E80B0 * 0xB0);
    DrawSync(0);
    DrawSyncCallback(func_80012BB4);
}
