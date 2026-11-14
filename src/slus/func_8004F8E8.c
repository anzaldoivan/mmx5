#include "types.h"

extern u8 D_8009A0A0[];
extern u8 D_8007B5E8[];
extern u16 D_8007B684[][2];
extern s32 D_8007B5FC[][2];
extern void func_8002D6FC(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_8004F8E8(u8* obj) {
    u8* g;
    s32 kill;
    s8 state;
    u8 b;

    g = D_8009A0A0;
    if (((s8*)g)[5] == 0x14) {
        func_8002D6FC(obj);
        return;
    }
    if (((s8*)obj)[2] == 0x10) {
        kill = ((s8*)g)[0x5C] == 0;
        if (((s8*)g)[0xD3] != 0) {
            kill = 1;
        }
        if (((s8*)g)[0xCF] != 0) {
            kill = 1;
        }
        if (((s8*)obj)[0x5C] != g[0x17]) {
            kill = 1;
        }
        if (obj[0x15] != g[0x15] && (u8)(obj[0x5D] - 0x18) < 3) {
            kill = 1;
        }
        if (((s8*)obj)[4] == 0) {
            func_800171E8(obj, D_8007B5E8[(s8)obj[2]]);
            obj[3] = 1;
            obj[4]++;
        }
        func_80017248(obj);
        if (((s8*)obj)[0x46] == 0) {
            kill = 1;
        }
        if (kill) {
            func_8002D6FC(obj);
            return;
        }
        b = g[0x15];
        obj[0x15] = b;
        if (b == 0) {
            *(u16*)(obj + 0xA) =
                *(u16*)(g + 0xA) - D_8007B684[((s8*)obj)[0x5D] - 0x18][0];
        } else {
            *(u16*)(obj + 0xA) =
                *(u16*)(g + 0xA) + D_8007B684[((s8*)obj)[0x5D] - 0x18][0];
        }
        *(u16*)(obj + 0xE) =
            *(u16*)(g + 0xE) + D_8007B684[((s8*)obj)[0x5D] - 0x18][1];
        return;
    }
    state = obj[4];
    switch (state) {
    case 0:
        obj[3] = 1;
        func_800171E8(obj, D_8007B5E8[((s8*)obj)[2]]);
        obj[4]++;
        if ((u8)(obj[2] - 8) < 2) {
            obj[0x16] = 0x11;
        }
        func_8002D9EC(obj, D_8007B5FC[((s8*)obj)[2]][0],
                      D_8007B5FC[((s8*)obj)[2]][1]);
        break;
    case 1:
        if (func_8002D938(obj, D_8007B5FC[((s8*)obj)[2]][0],
                          D_8007B5FC[((s8*)obj)[2]][1]) != 0) {
            obj[4] = 2;
        } else {
            func_80017248(obj);
            if (((s8*)obj)[2] == 9 && ((s8*)obj)[0x45] != 0) {
                obj[0x45] = 0;
                g[0xF2] = 0;
            }
            if (((s8*)obj)[2] == 0xE) {
                *(s32*)(obj + 8) = *(s32*)(g + 8);
                *(s32*)(obj + 0xC) = *(s32*)(g + 0xC);
                if (((s8*)g)[5] != 0x3E || (((s8*)g)[0x45] & 0x80)) {
                    obj[4] = 2;
                    obj[3] = 0;
                }
            } else if (((s8*)obj)[0x46] < 0) {
                obj[4] = 2;
            }
        }
        func_8002D9EC(obj, D_8007B5FC[((s8*)obj)[2]][0],
                      D_8007B5FC[((s8*)obj)[2]][1]);
        break;
    case 2:
        func_8002D6FC(obj);
        break;
    }
}
