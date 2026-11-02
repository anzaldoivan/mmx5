#include "types.h"

extern void func_8003D0A0(u8* obj);
extern void func_8003B33C(u8*, s32);
extern u8* func_8002D27C(void);
extern void func_80017248(u8* obj);
extern u8 D_800D1C00[];
extern s16 D_80100540_ovl07[][2];

void func_800EEA88_ovl07(u8* obj) {
    u8* g;
    u8* p;
    s32 c;

    if (*(s8*)(obj + 6) == 0) {
        g = D_800D1C00;
        if (*(s8*)(g + 0x26) == *(s8*)(obj + 7)) {
            g[0x27] |= 2;
            func_8003D0A0(obj);
            *(s8*)(obj + 0xD0) = -1;
            obj[5] = 0x14;
            return;
        }
        obj[7]++;
        obj[6]++;
        if (*(s8*)(obj + 2) == 0) {
            func_8003B33C(obj, 0x5B);
        } else {
            func_8003B33C(obj, 0x6E);
        }
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x3B;
            p[2] = 1;
            *(s16*)(p + 0xA) =
                *(s16*)(obj + 0xA) + D_80100540_ovl07[*(s8*)(obj + 2)][0];
            *(s16*)(p + 0xE) =
                *(s16*)(obj + 0xE) + D_80100540_ovl07[*(s8*)(obj + 2)][1];
            obj[0x45] &= 0x7F;
        }
    } else if (*(s8*)(obj + 6) == 1) {
        func_80017248(obj);
        if (*(s8*)(obj + 0x45) & 0x80) {
            obj[0x45] &= 0x7F;
            return;
        }
        if (*(s8*)(obj + 0x46) == 0) {
            func_8003D0A0(obj);
            obj[6]++;
        }
    } else {
        func_80017248(obj);
        obj[6]++;
        if (*(s8*)(obj + 2) == 0) {
            c = (s8)obj[6] < 0x29;
        } else {
            c = (s8)obj[6] < 0x1F;
        }
        if (!c) {
            obj[6] = 0;
        }
    }
}
