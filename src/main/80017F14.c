#include "types.h"
#include "mmx5/globals.h"

extern s8 D_8009A418;
extern s32 D_800E80A4;
extern s32 D_800E8094;

void func_80017F14(void) {
    D_8009A418 = 0;
    D_800E80A4 = 0;
    D_800E8094 = 0;
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80018838.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32

s8 func_80066D58(M2C_UNK, u8*);
s32 CdControl(M2C_UNK, M2C_UNK, u8*);
extern s8 D_800D1F3C;
extern s32 D_800E8060;
extern u8 D_800E8088;

void func_80017F30(void) {
    s8 temp_v0;

    temp_v0 = func_80066D58(1, &D_800E8088);
    if ((temp_v0 == 2) && !(D_800E8088 & 0x40) &&
        (CdControl(0x1B, 0, &D_800E8088) != 0)) {
        D_800D1F3C = temp_v0;
        D_800E8060 = (s32)temp_v0;
    }
}
#undef M2C_UNK

s32 CdControl(s32, s32, u8*);
extern s16 D_800E8090;
extern u8 D_800A51A4;
extern u8 D_800E8088;
extern s32 D_800E8060;
extern s8 D_800E805E;

void func_80017FB4(void) {
    if (D_800E8090 & D_800A51A4) {
        while (CdControl(9, 0, &D_800E8088) == 5) {
        }
        D_800E8060 = 3;
        if (D_800E8088 & 0x10) {
            D_800E805E = 1;
        }
    }
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80018948.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32

s8 func_80066D58(M2C_UNK, u8*);
s32 CdControl(M2C_UNK, M2C_UNK, u8*);
extern u8 D_800A51A4;
extern s8 D_800E805E;
extern s32 D_800E8060;
extern u8 D_800E8088;
extern s16 D_800E8090;
extern s32 D_800E8094;

void func_80018040(void) {
    s32 temp_v0;

    temp_v0 = func_80066D58(1, 0);
    if ((temp_v0 == 2) && (D_800E8094 != 0) && (D_800A51A4 == 0) &&
        (CdControl(0x1B, 0, &D_800E8088) != 0)) {
        D_800E8090 = 0;
        D_800E8060 = temp_v0;
        if (D_800E8088 & 0x10) {
            D_800E805E = 1;
        }
    }
}
#undef M2C_UNK

#define M2C_UNK s32

s8 func_80066D58(M2C_UNK, u8*);
s32 CdControlB(M2C_UNK, M2C_UNK, u8*);
void SsSetSerialAttr(M2C_UNK, M2C_UNK, M2C_UNK);
void func_80017E98(u8 vol);
extern u8 D_800E805C;
extern s32 D_800E8060;
extern s32 D_800E8094;

void func_800180DC(void) {
    s32 temp_v0;

    temp_v0 = func_80066D58(1, 0);
    if (temp_v0 == 2) {
        if (D_800E8094 == temp_v0) {
            if (CdControlB(9, 0, 0) == 0) {
                return;
            }
            SsSetSerialAttr(0, 0, 0);
            D_800E805C = 0;
            func_80017E98(0);
            D_800E8094 = 0;
            D_800E8060 = 0;
        } else {
            SsSetSerialAttr(0, 0, 0);
            D_800E805C = 0;
            func_80017E98(0);
            D_800E8060 = 0;
        }
    }
}
#undef M2C_UNK

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80018A90.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32

s8 func_80066D58(M2C_UNK, u8*);
s32 CdControl(M2C_UNK, M2C_UNK, u8*);
s32 CdControlF(M2C_UNK, M2C_UNK*);
extern s32 D_800E8060;
extern s32 D_800E8094;
extern u8 D_800E80A8;

void func_80018188(void) {
    s32 var_v0;

    if (func_80066D58(1, 0) == 2) {
        if (D_800E80A8 == 0) {
            var_v0 = CdControl(0x15, &D_800E804C, 0);
        } else {
            var_v0 = CdControlF(0x15, &D_800E804C);
        }
        if (var_v0 != 0) {
            D_800E8060 = 1;
        }
        D_800E8094 = 2;
    }
}
#undef M2C_UNK

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80018B10.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32

s8 func_80066D58(M2C_UNK, u8*);
s32 CdControl(M2C_UNK, M2C_UNK, u8*);
extern s32 D_800E8060;
extern M2C_UNK D_800E80AC;

void func_80018208(void) {
    if ((func_80066D58(1, 0) == 2) && (CdControl(0xD, &D_800E80AC, 0) != 0)) {
        D_800E8060 = 5;
    }
}
#undef M2C_UNK

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80018B60.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/55C4.c:func_80016E84, AGPL-3.0; proven shared with X6 by exact signature adc4ba01bdcd (see THIRD_PARTY.md). */
int VSync(int mode);
extern u8 D_800E8088;
#define D_800E8088 (*(u8(*)[]) & D_800E8088)
extern s8 D_800E805E;
extern s32 D_800E8060;

#define M2C_UNK s32
s8 func_80066D58(M2C_UNK, u8*);
s32 CdControl(M2C_UNK, M2C_UNK, u8*);
void func_80018258(void) {

    u8 sp10;

    if (((int (*)())func_80066D58)(1, 0) == 0x02) {
        sp10 = 0x80 | 0x40 | 0x08;
        if (((int (*)())CdControl)(0x0e, &sp10, &D_800E8088) != 0) {
            VSync(3);
            D_800E8060 = 6;
            if (D_800E8088[0] & 0x10) {
                D_800E805E = 1;
            }
        }
    }
}
#undef D_800E8088
