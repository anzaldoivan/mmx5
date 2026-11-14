/* Adapted from mmx6 @a8f96d1 src/shared/SLUS_013.95/func_8001AE44.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
void DecDCTReset(s32 mode);
void DecDCToutCallback(void* func);
s32 CdReset(s32);
int VSync(int mode);
s32 CdControl(s32, u8*, u8*);
s32 CdControlB(s32, s32, u8*);
s32 StGetNext(u32** addr, StHdr8130** hdr);
void StFreeRing(u32* base);
void StSetRing(u32* base, s32 size);
void StSetStream(s32 mode, s32 start, s32 end, void* func1, void* func2);
s32 CdRead2(s32 mode);
void DecDCTvlc(u32* bs, u32* buf);

void func_8001AE84(void);
void func_8001AF60(void);
void func_8001B25C(s32 arg0);
void func_8001B268(u32 arg0);
int CdPosToInt(void* p);
void CdIntToPos(s32, u8*);
s8 func_80066D58(s32, u8*);
void func_8001AD8C(void);
void func_8001B360(void);
extern s32 D_80070C4C;
extern s32 D_800E80AC;
extern s32 D_800E80F8;
extern s32 D_800E8108[];
extern s32 D_800E8110;
extern s32 D_800E8114;
extern s32 D_800E8118;
extern s32 D_800E811C;
extern s32 D_800E8120;
extern s32 D_800E8130[];
extern s32 D_800E8150;
extern volatile s32 D_800E8174;
extern u8 D_800E8188;
extern u8 D_800E818D;
extern s32 D_800E8190;
extern u8 D_800E81A0;

s32 func_8001A7A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                  s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    s32 sp18;
    s32* sp1C;
    s32 sp20;
    s32 y;
    u32 i;

    sp20 = 0x148;
    D_800E8108[0] = arg5;
    D_800E8108[1] = arg6;
    D_800E8114 = arg2;
    D_800E80F8 = 0;
    D_800E8174 = 0;
    D_800E8120 = 0;
    D_800E8150 = 0;
    D_800E8110 = arg7;
    D_800E8118 = arg9;
    D_800E811C = arg9;
    D_80070C4C = arg8;
    func_8001B25C(0);
    DecDCTReset(0);
    DecDCToutCallback(func_8001AD8C);
    StSetRing((u32*)arg3, arg4);
    StSetStream(D_800E8118, arg1, 0x0FFFFFFF, func_8001B360, 0);
    func_8001AF60();
    *(u8*)&D_800E80AC = 1;
    func_8001B268(0x7F);
    CdIntToPos(arg0, &D_800E81A0);
    D_800E8190 = arg0;
    if (D_80070C4C != 0) {
        sp20 = 0x1C8;
    }
    for (;;) {
        while (func_80066D58(0, 0) != 2) {
            do {
            } while (CdReset(0) == 0);
            VSync(3);
        }
        if (CdControl(0xD, (u8*)&D_800E80AC, 0) != 0) {
            VSync(3);
            if (CdControlB(0x15, (u8*)&D_800E81A0, 0) != 0 &&
                CdRead2(sp20) != 0) {
                VSync(3);
                while (CdControl(0x11, 0, &D_800E8188) == 0) {
                }
                break;
            }
        }
    }
    arg0 = CdPosToInt((void*)&D_800E818D);
    if ((u32)arg0 < (u32)(D_800E8190 - 0x14)) {
        return 1;
    }
    if ((u32)(D_800E8190 + 5) < (u32)arg0) {
        return 1;
    }
    i = 0;
    func_8001AE84();
    while (StGetNext((u32**)&sp18, (StHdr8130**)&sp1C) != 0) {
        VSync(0);
        i++;
        if (i >= 0x259) {
            return 1;
        }
    }
    D_800E8130[0] = sp1C[0];
    D_800E8130[1] = sp1C[1];
    D_800E8130[2] = sp1C[2];
    D_800E8130[3] = sp1C[3];
    D_800E8130[4] = sp1C[4];
    D_800E8130[5] = sp1C[5];
    D_800E8150--;
    D_800E8130[6] = sp1C[6];
    D_800E8130[7] = sp1C[7];
    ((u16*)D_800E8130)[8] = (((u16*)D_800E8130)[8] + 8) / 16 * 16;
    y = ((u16*)D_800E8130)[9] + 8;
    if (y < 0) {
        y = ((u16*)D_800E8130)[9] + 0x17;
    }
    ((u16*)D_800E8130)[9] = y & 0xFFF0;
    DecDCTvlc((u32*)sp18, (u32*)D_800E8108[D_800E8120]);
    StFreeRing((u32*)sp18);
    return 0;
}
