/* Shared body (DK-5), from the banked draft of func_800EFF90_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* obj);
extern u8 func_80030AE4(u8*, s16, s16);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002DF78(void);
extern u8 D_8009A0A0[];

void DEDUP_NAME(u8* o) {
    u8* p;
    u8* d;
    s16 x;
    s16 y;
    s32 diff;

    func_8002DF54(o);
    func_80017248(o);
    p = *(u8**)(o + 0x68);
    x = *(s16*)(o + 0xA) + (s8)p[0];
    y = *(s16*)(o + 0xE) + (s8)p[1] + p[3] + 16;
    if (o[0x15] == 0) {
        x -= 16;
    } else {
        x += 16;
    }
    if (func_80030AE4(o, x, y) == 0) {
        goto kill; // !FAKE: goto kept for the matching branch layout
    }
    if (o[0x15] == 0) {
        u8* d = D_8009A0A0;
        if (*(s16*)(d + 0xA) - *(s16*)(o + 0xA) > 0x40) {
            o[0x15] = 0x40;
            *(s32*)(o + 0x20) = 0x1CCCC;
        } else if (o[0x70] & 2) {
            func_800171E8(o, 1);
            o[5] = 4;
            o[6] = 0;
        }
    } else {
        u8* d = D_8009A0A0;
        if (*(s16*)(o + 0xA) - *(s16*)(d + 0xA) > 0x40) {
            o[0x15] = 0;
            *(s32*)(o + 0x20) = -0x1CCCC;
        } else if (o[0x70] & 1) {
            func_800171E8(o, 1);
            o[5] = 4;
            o[6] = 0;
        }
    }
    if (--*(s16*)(o + 0x7C) == 0) {
        o[0x8C] = 1;
        d = D_8009A0A0;
        diff = *(s16*)(d + 0xE) - *(s16*)(o + 0xE);
        if (diff >= 0) {
            if (diff > 0x20) {
                goto two; // !FAKE: goto kept for the matching branch layout
            }
        } else {
            if (*(s16*)(o + 0xE) - *(s16*)(d + 0xE) <= 0x20) {
                goto rnd; // !FAKE: goto kept for the matching branch layout
            }
            goto two; // !FAKE: goto kept for the matching branch layout
        }
    rnd:
        if ((u32)(func_8002DF78() & 0xF) >= 3) {
        kill:
            func_800171E8(o, 1);
            o[5] = 4;
        } else {
        two:
            o[5] = 2;
        }
        o[6] = 0;
    }
}
