/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80016D34.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

s32 SpuGetKeyStatus(s32);
void SsUtGetVagAtr(s32, s16, s16, u8*);
s32 SsUtKeyOnV(s32, s32, s16, s16, s32, s32, s32, s32);
extern X4_BackgroundObj D_8009A1F8[3];
extern u8* D_800E6B84;
extern s8 D_800E8028[];

s32 func_8001657C(u8 arg0, u8 arg1, X4_Obj* arg2) {
    u8 buf[0x20];
    s8 fp;
    s16 x;
    s8 bg;
    u8 a, b, c;
    s16 col;
    s16 row;
    u8 slot;
    s32 pri;
    u32 flag;
    s8 n;
    s16 lo;
    s16 hi;
    u8 p26;
    u8 p25;

    if (arg2 != 0) {
        if (arg0 & 0x80) {
            fp = arg2->unk2;
        } else {
            bg = arg2->bg_offset;
            x = arg2->x_pos.i.hi;
            if (bg >= 0) {
                x -= D_8009A1F8[bg].x_pos.i.hi;
            }
            fp = x / 10;
            if (fp < 5) {
                fp = 5;
            }
            if (fp >= 0x1C) {
                fp = 0x1B;
            }
        }
    }
    a = D_800E6B84[2];
    b = D_800E6B84[1];
    c = D_800E6B84[3];
    col = a >> 4;
    row = b & 0x7F;
    n = (c & 0x60) >> 5;
    slot = c & 0x1F;
    flag = b >> 7;
    pri = a & 0xF;
    for (; n >= 0; n--, slot++) {
        SsUtGetVagAtr(arg1, row, col, buf);
        lo = buf[2];
        hi = lo;
        if (flag == 0 && arg2 != 0) {
            if (fp < 0x10) {
                lo = (lo >> 4) * fp;
            } else if (fp > 0x10) {
                hi = (lo >> 4) * (0x20 - fp);
            }
        }
        p26 = buf[6];
        p25 = buf[5];
        if (SpuGetKeyStatus(1 << slot) == 0) {
            SsUtKeyOnV(slot, arg1, row, col, p26, p25, hi, lo);
            D_800E8028[slot] = pri;
        } else {
            if (pri < D_800E8028[slot]) {
                return -4;
            }
            SsUtKeyOnV(slot, arg1, row, col, p26, p25, hi, lo);
            D_800E8028[slot] = pri;
        }
        col++;
        if (col >= 0x10) {
            row++;
            col = 0;
        }
    }
    return 0;
}
