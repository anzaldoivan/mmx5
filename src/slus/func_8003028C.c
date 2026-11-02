#include "types.h"

extern u8 func_80030BB4(u8* arg0, s16 x, s16 y);
extern s32 func_800310E4(u8* p, s16 a, s16 b, s32 c);
extern u8 D_800E9309;
extern u16 D_800E931C;

s32 func_8003028C(u8* obj, u8 code, s16 x, s16 y) {
    s32 flag = 0;
    s16 v;
    s16 r;

    if (code == 0x10) {
        flag = 1;
        *(u16*)(obj + 0xE) -= 16;
        code = func_80030BB4(obj, x, y - 16);
    }
    switch (code) {
    case 9:
    case 10:
    case 11:
    case 12:
    case 25:
    case 26:
    case 27:
    case 28:
        code &= 0xF;
        v = x & 0xF;
        if (code == 10) {
            v |= 0x10;
        }
        if (code == 12) {
            v += 16;
        }
        if (code >= 11) {
            r = v / 2;
        } else {
            r = 15 - v / 2;
        }
        return func_800310E4(obj, y, r, flag);
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
        code &= 0xF;
        v = x & 0xF;
        if (code == 2) {
            v |= 0x10;
        }
        if (code == 6) {
            v += 16;
        }
        if (code == 3) {
            v += 32;
        }
        if (code == 7) {
            v += 32;
        }
        if (code == 4) {
            v += 48;
        }
        if (code == 8) {
            v += 48;
        }
        if (code >= 5) {
            r = v / 4;
        } else {
            r = 15 - v / 4;
        }
        return func_800310E4(obj, y, r, flag);
    case 33:
    case 34:
    case 56:
    case 57:
    case 58:
    case 60:
    case 62:
    case 63:
        D_800E9309 |= 8;
        D_800E931C = -*(u16*)(obj + 0x6E);
        return -1;
    case 0:
    default:
        return 0;
    }
}
