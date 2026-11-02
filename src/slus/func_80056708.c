#include "types.h"

extern s32 func_80014684(s32, s32, s32);
extern void* func_80066D98(void* func);
extern s32 CdReset(s32);
extern s32 CdControlB(s32, u8*, u8*);
extern int VSync(int mode);

extern u8 D_8007D758[];
extern u8 D_8007D764;
extern u8 D_8007D76A;
extern u8 D_80091D50;
extern u8 D_8009811C;
extern s8 D_8009A0A2;
extern s32 D_8009A758;
extern s32 D_800BE9A8;
extern u8 D_800D1598;
extern u8 D_800D1C00[];
extern s8 D_800D1C0C;
extern u8 D_800D1F3C;
extern u32 D_800E95A0;
extern s32 D_800E95A4;

void func_80056708(u8* arg0) {
    u8 param[8];
    u8* p;
    u8* q;
    u8* r;
    u8 c;

    param[0] = 0xA0;
    switch (((s8*)arg0)[5]) {
    case 0:
        if (D_800D1F3C != 0) {
            break;
        }
        p = D_800D1C00;
        c = p[0xC];
        if ((u32)(c - 9) < 2) {
            arg0[5] = 3;
            break;
        }
        if ((s8)c == 0xC && ((s8*)p)[0x1D] == 0x15) {
            if (((s8*)p)[0x31] == ((s8*)p)[0x32]) {
                arg0[5] = 3;
                break;
            }
            if (((s8*)p)[0x31] == 1) {
                D_8007D764 = 0x88;
            } else {
                D_8007D764 = 0x89;
            }
            D_800D1C00[0x32] = D_800D1C00[0x31];
            D_800D1598 = 0;
        }
        if (D_800D1598 == 0) {
            arg0[5]++;
        } else {
            arg0[5] = 3;
        }
        q = D_800D1C00;
        if (((s8*)q)[0xC] == 0x12) {
            if (D_8009A0A2 == 0) {
                D_8007D76A = 0x8D;
            } else {
                D_8007D76A = 0x8C;
            }
        }
        break;
    case 1:
        D_800E95A4 = D_800BE9A8;
        func_80014684(D_8007D758[D_800D1C0C], 4, D_8009A758);
        D_800E95A0 = 0;
        arg0[5]++;
        break;
    case 2:
        if (D_8009811C == 2 && D_80091D50 == 0) {
            D_800D1598 = 1;
            arg0[5]++;
            r = D_800D1C00;
            if (((s8*)r)[0xC] == 0xC && ((s8*)r)[0x1D] == 0x15) {
                D_800BE9A8 = D_800E95A4;
            }
        } else if (D_8009811C & 0xC0) {
            func_80014684(D_8007D758[D_800D1C0C], 4, D_8009A758);
            D_800E95A0 = 0;
        } else if (++D_800E95A0 >= 0x259) {
            func_80066D98(0);
            while (CdReset(0) == 0) {
            }
            while (CdControlB(0xE, param, 0) == 0) {
            }
            VSync(3);
            D_8009811C = 0xC0;
        }
        break;
    case 3:
        arg0[4]++;
        break;
    }
}
