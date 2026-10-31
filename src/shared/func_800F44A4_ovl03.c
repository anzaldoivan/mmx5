/* Shared body (DK-5), from the banked draft of func_800F44A4_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8* func_8002C938();
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern u8 D_800FA0BC_ovl03[][6];

void DEDUP_NAME(u8* o) {
    u8* c;

    if (--*(s16*)(o + 0x7C) == 0 || *(s32*)(o + 0x20) == 0) {
        c = func_8002C938();
        if (c != 0) {
            c[0] = 0x61;
            c[1] = 0x39;
            c[2] = 4;
            *(u8**)(c + 0x80) = o;
        }
        *(s16*)(o + 0x7C) = 0x16;
    }
    if (*(s32*)(o + 0x20) < 0) {
        if (*(s16*)(o + 0xA) <= D_800FA240_ovl03) {
            *(s16*)(o + 0xA) = D_800FA240_ovl03;
            *(s32*)(o + 0x20) = 0;
        }
    } else if (*(s32*)(o + 0x20) > 0) {
        if (*(s16*)(o + 0xA) >= D_800FA242_ovl03) {
            *(s16*)(o + 0xA) = D_800FA242_ovl03;
            *(s32*)(o + 0x20) = 0;
        }
    }
    if (*(s32*)(o + 0x20) == 0) {
        func_800171E8(o, 1);
        o[5] = D_800FA0BC_ovl03[o[0x92]][o[0x93]++];
        o[6] = 0;
    }
    func_80017248(o);
    func_8002DED4(o);
}
