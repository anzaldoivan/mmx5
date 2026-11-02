#include "types.h"

extern void CdIntToPos(s32, void*);
extern void SsSetSerialAttr(s32, s32, s32);
extern s32 func_80015BA4(s32 arg0, s32* arg1);
extern void func_80017E98(u8 vol);
extern s32 D_800705DC[][4];
extern u8 D_800D1F3C;
extern u8 D_800E804C;
extern u8 D_800E805C;
extern s32 D_800E8060;
extern s32 D_800E8068;
extern s32 D_800E8070;
extern s32 D_800E8074;
extern u8 D_800E8098;
extern s32 D_800E80A4;
extern u8 D_800E80AC[];

void func_800177B0(u8 arg0) {
    s32 t;
    u8 vol;

    D_800E80AC[0] = 1;
    D_800E8070 = D_800705DC[arg0][0];
    D_800E8074 = D_800705DC[arg0][1];
    D_800E8098 = ((u8*)D_800705DC[arg0])[0xC];
    t = D_800705DC[arg0][2];
    D_800E80AC[1] = t;
    D_800E8070 += func_80015BA4(0xAE, &D_800E8068);
    D_800E8074 += func_80015BA4(0xAE, &D_800E8068);
    CdIntToPos(D_800E8070, &D_800E804C);
    SsSetSerialAttr(0, 0, 1);
    vol = 0x73;
    D_800E805C = vol;
    func_80017E98(vol);
    D_800E80A4 = 2;
    D_800D1F3C = 1;
    D_800E8060 = 7;
}
