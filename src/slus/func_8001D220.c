/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001C024.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

s32 OpenEvent(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK EnableEvent(s32);                          /* extern */
M2C_UNK func_8006C3B8();                           /* extern */
M2C_UNK func_8006C3C8();                           /* extern */
extern s32 D_800E81B8;
extern s32 D_800E81BC;
extern s32 D_800E81C0;
extern s32 D_800E81C4;
extern s32 D_800E81C8;
extern s32 D_800E81CC;
extern s32 D_800E81D0;

void func_8001D220(void) {
    func_8006C3B8();
    D_800E81B8 = OpenEvent(0xF4000001, 4, 0x2000, 0);
    D_800E81BC = OpenEvent(0xF4000001, 0x100, 0x2000, 0);
    D_800E81C0 = OpenEvent(0xF4000001, 0x2000, 0x2000, 0);
    D_800E81C4 = OpenEvent(0xF4000001, 0x8000, 0x2000, 0);
    D_800E81C8 = OpenEvent(0xF0000011, 4, 0x2000, 0);
    D_800E81CC = OpenEvent(0xF0000011, 0x100, 0x2000, 0);
    D_800E81D0 = OpenEvent(0xF0000011, 0x8000, 0x2000, 0);
    func_8006C3C8();
    EnableEvent(D_800E81B8);
    EnableEvent(D_800E81BC);
    EnableEvent(D_800E81C0);
    EnableEvent(D_800E81C4);
    EnableEvent(D_800E81C8);
    EnableEvent(D_800E81CC);
    EnableEvent(D_800E81D0);
}
