/* Shared body (DK-5), from the banked draft of func_800F5940_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_8002DF78(void);
extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D1A4();
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern u8 D_8009A0A0[];
extern s16 D_800FA250_ovl03;
extern s16 D_800FA252_ovl03;

void DEDUP_NAME(u8* obj) {
    s32 i;
    u8* p;
    u8* d;

    if (*(s32*)(obj + 0x20) < 0) {
        if (*(s16*)(obj + 0xA) <= D_800FA250_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA250_ovl03;
            *(s32*)(obj + 0x20) = 0;
        }
    } else if (*(s32*)(obj + 0x20) > 0) {
        if (*(s16*)(obj + 0xA) >= D_800FA250_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA250_ovl03;
            *(s32*)(obj + 0x20) = 0;
        }
    }
    if (*(s32*)(obj + 0x24) < 0) {
        if (*(s16*)(obj + 0xE) >= D_800FA252_ovl03) {
            *(s16*)(obj + 0xE) = D_800FA252_ovl03;
            *(s32*)(obj + 0x24) = 0;
        }
    } else if (*(s32*)(obj + 0x24) > 0) {
        if (*(s16*)(obj + 0xE) <= D_800FA252_ovl03) {
            *(s16*)(obj + 0xE) = D_800FA252_ovl03;
            *(s32*)(obj + 0x24) = 0;
        }
    }
    if (*(s32*)(obj + 0x20) == 0 && *(s32*)(obj + 0x24) == 0) {
        if (func_8002DF78() & 1) {
            *(s16*)(obj + 0x7C) = 0;
            obj[6] += 1;
        } else {
            func_800171E8(obj, 8);
            for (i = 0; i < 3; i++) {
                p = func_8002D1A4();
                if (p != 0) {
                    p[0] = 0x61;
                    p[1] = 0x15;
                    p[2] = i;
                    *(u8**)(p + 0x7C) = obj;
                }
            }
            *(s16*)(obj + 0x7C) = 0;
            obj[6] += 2;
        }
    }
    d = D_8009A0A0;
    if (*(s16*)(d + 0xA) > *(s16*)(obj + 0xA)) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
