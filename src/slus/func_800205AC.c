#include "types.h"
#include "mmx5/globals.h"

extern void func_8001E6AC(void);
extern void func_80012EAC(void);
extern u8 D_800710F0[];
extern u8 D_800D1C27;
extern s8 D_800D1C00[];
extern s32 D_800E92F8;

void func_800205AC(u8* obj) {
    u8* g = g_Player;
    u32 i;
    u8 c;
    s32 t;
    u8 v;
    u8 f;

    *(s32*)(obj + 0xB0) += *(s32*)(g + 0x150);
    if (((s8*)obj)[0xF] != 0) {
        if (((s8*)obj)[0xF] > 0) {
            obj[0x1E] = 0;
            if (((s8*)obj)[0xC] == 0) {
                obj[0x79] = 1;
                obj[0xF] = 0;
                obj[0] = 0x13;
                obj[0x1D] = 1;
                obj[1] = 0;
                return;
            }
            if (((s8*)obj)[0xC] == 0x16) {
                func_8001E6AC();
                func_80012EAC();
                return;
            }
            if ((u8)(obj[0xC] - 1) < 8) {
                if (D_800710F0[((s8*)obj)[0xC]] != 0 || ((s8*)obj)[0xD] != 0) {
                    D_800D1C27 = 0;
                    obj[0] = 0xB;
                } else {
                    obj[0xD]++;
                    obj[0] = 8;
                }
                obj[1] = 0;
                obj[2] = 0;
                obj[3] = 0;
                obj[0xF] = 0;
                return;
            }
            if (((s8*)obj)[0xC] == 0x10) {
                obj[0x79] = 6;
            }
            if (((s8*)obj)[0xC] == 0x11) {
                obj[0x79] = 7;
            }
            if (((s8*)obj)[0xC] == 0x12) {
                obj[0x79] = 8;
            }
            c = obj[0xC];
            if ((u8)(c - 0x10) < 2 || (s8)c == 9 || (s8)c == 10) {
                D_800D1C27 = 0;
                obj[0] = 0xB;
                obj[1] = 0;
                obj[2] = 0;
                obj[3] = 0;
                obj[0xF] = 0;
                return;
            }
            if ((s8)c == 0x12) {
                s32 k;

                do {
                    v = obj[0xCB] & 0x80;
                    k = 0x13;
                } while (
                    0); // !FAKE: fence keeps 0x13 live across the test (C0294)
                obj[0] = k;
                if (v) {
                    v = 0xD;
                } else {
                    v = 0xE;
                }
                obj[0x1D] = v;
            } else if ((s8)c == 0xC) {
                u8* q = g_Player;

                obj[0] = 0x13;
                if (((s8*)q)[2] != 0) {
                    obj[0x1D] = 0x12;
                } else if (obj[0xCB] & 0x80) {
                    obj[0x1D] = 0x10;
                } else {
                    obj[0x1D] = 0x11;
                }
            }
        } else {
            s8* p;

            ((s8*)obj)[0x1E] = -1;
            obj[0x46] = g[0x5C];
            for (i = 0; i < 16; i++) {
                ((s16*)(obj + 0x56))[i] = ((s16*)(g + 0xA8))[i];
            }
            obj[0x7A] = g_Player[0x93];
            obj[0xC1] = g_Player[0xFB];
            p = D_800D1C00;
            if (p[0xC] == 6) {
                D_800E92F8 = 1;
            }
            if (p[0xC] != 0xC) {
                obj[0x43] = 1;
            }
            if (p[0xC] == 0xC && p[0x1D] == 10) {
                obj[0x7A] = 0;
            }
            obj[0] = 9;
        }
    } else {
        t = obj[0x45] - 1;
        obj[0x45] = t;
        if ((t << 24) < 0) {
            s32 c2 = ((s8*)obj)[0xC];

            if (c2 == 0x16) {
                func_8001E6AC();
                func_80012EAC();
                return;
            }
            obj[0] = 0xD;
            if (c2 != 0xC || ((s8*)obj)[0x1D] < 2) {
                v = 0;
            } else {
                v = ((s8*)obj)[0x1D] < 10;
            }
            if (v) {
                v = 1;
                obj[0x1D] = v;
            }
        } else {
            obj[0x1E] = 0;
            if (((s8*)obj)[0xC] != 0xC || ((s8*)obj)[0x1D] < 2) {
                f = 0;
            } else {
                f = ((s8*)obj)[0x1D] < 10;
            }
            if (f) {
                obj[0x1D] = 1;
            }
            obj[0] = 9;
        }
    }
    obj[1] = 0;
    obj[0xF] = 0;
}
