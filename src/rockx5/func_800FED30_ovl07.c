#include "types.h"

extern s32 func_8002DF78(void);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002DF54(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern signed char D_800D1C0C;

void func_800FED30_ovl07(u8* o) {
    s8 st = o[6];
    u8 r;

    if (st == 0) {
        *(s32*)(o + 0x24) = -0xA0000;
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x28) = 0;
        *(s32*)(o + 0x2C) = 0;
        o[6]++;
    } else if (st == 1) {
        if (D_800D1C0C != 12) {
            if (*(s16*)(o + 0xE) < 0x519) {
                func_8002DF54(o);
            } else {
                r = func_8002DF78() & 7;
                o[0x54] = r;
                if (r == 0) {
                    o[0x54] = st;
                }
                o[6]++;
            }
        } else {
            if (*(s16*)(o + 0xE) < 0xD9) {
                func_8002DF54(o);
            } else {
                r = func_8002DF78() & 7;
                o[0x54] = r;
                if (r == 0) {
                    o[0x54] = st;
                }
                o[6]++;
            }
        }
    } else if (st == 2) {
        if (--((s8*)o)[0x54] == 0) {
            func_800171E8(o, 11);
            o[6]++;
        } else {
            func_8002DF54(o);
        }
    } else if (st == 3) {
        if (((s8*)o)[0x45] != 0) {
            o[4] = 2;
            o[3] = 0;
            return;
        }
    }
    func_8002D9EC(o, 0x20, 0x20);
    func_80017248(o);
}
