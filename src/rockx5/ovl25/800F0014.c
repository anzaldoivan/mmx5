#include "types.h"
#include "mmx5/globals.h"

extern s16 D_800F0CE6_ovl25;
extern s16 D_800F0CE4_ovl25;

void func_800F0014_ovl25(Ovl25State* arg0) {
    D_8009A1F8.t.unkA0 = 1;
    *(s32*)((u8*)&D_8009A1F8.t + 0x5C) += D_800F0CE4_ovl25 << 15;
    if (D_8009A1F8.t.unk5E >= 0xE0) {
        D_800F0CE6_ovl25 = D_800F0CE4_ovl25;
        arg0->unk4 = 0;
        arg0->unk2++;
    }
}

extern s16 D_800F0CE6_ovl25;
extern s16 D_800F0CE4_ovl25;

void func_800F006C_ovl25(Ovl25State* arg0) {
    D_8009A1F8.t.unkA0 = 1;
    *(s32*)((u8*)&D_8009A1F8.t + 0x5C) += D_800F0CE4_ovl25 << 15;
    if (D_8009A1F8.t.unk5E >= 0x4C0) {
        D_800F0CE6_ovl25 = D_800F0CE4_ovl25;
        arg0->unk4 = 0;
        arg0->unk2++;
    }
}

extern s16 D_800F0CE6_ovl25;
extern s16 D_800F0CE4_ovl25;

void func_800F00C4_ovl25(Ovl25State* arg0) {
    D_8009A1F8.t.unkA0 = 1;
    *(s32*)((u8*)&D_8009A1F8.t + 0x5C) += D_800F0CE4_ovl25 << 15;
    if (D_8009A1F8.t.unk5E >= 0xD50) {
        D_800F0CE6_ovl25 = D_800F0CE4_ovl25;
        arg0->unk4 = 0;
        arg0->unk2++;
    }
}

extern s16 D_800F0CE6_ovl25;
extern s16 D_800F0CE4_ovl25;

void func_800F011C_ovl25(Ovl25State* arg0) {
    D_8009A1F8.t.unkA0 = 1;
    *(s32*)((u8*)&D_8009A1F8.t + 0x5C) += D_800F0CE4_ovl25 << 15;
    if (D_8009A1F8.t.unk5E >= 0x1380) {
        D_800F0CE6_ovl25 = D_800F0CE4_ovl25;
        arg0->unk4 = 0;
        arg0->unk2++;
    }
}

extern s16 D_800F0CE6_ovl25;
extern s16 D_800F0CE4_ovl25;

void func_800F0174_ovl25(Ovl25State* arg0) {
    D_8009A1F8.t.unkA0 = 1;
    *(s32*)((u8*)&D_8009A1F8.t + 0x5C) += D_800F0CE4_ovl25 << 15;
    if (D_8009A1F8.t.unk5E >= 0x1940) {
        D_800F0CE6_ovl25 = D_800F0CE4_ovl25;
        arg0->unk2++;
    }
}
