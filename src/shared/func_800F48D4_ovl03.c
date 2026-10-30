/* Shared body (DK-5), from the banked draft of func_800F48D4_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;
extern u8 D_8009A0A0[];

void DEDUP_NAME(u8* obj) {
    u8* p;
    u8* q;
    u8* r;
    u8* t;
    s16 d;

    if (*(s32*)(obj + 0x24) > 0 && *(s16*)(obj + 0x7E) == 0) {
        if (obj[0x15] == 0) {
            d = D_800FA240_ovl03 - *(s16*)(obj + 0xA);
        } else {
            d = D_800FA242_ovl03 - *(s16*)(obj + 0xA);
        }
        *(s16*)(obj + 0x7E) = 1;
        *(s32*)(obj + 0x20) = (d << 16) / 40;
    }
    if (*(s8*)(obj + 0x45) == 1) {
        func_80016490(2, 0x11, obj);
    }
    if (*(s32*)(obj + 0x24) > 0x10000) {
        func_800171E8(obj, 4);
        obj[0x62] = 0;
        obj[6]++;
    }
    if (obj[0x8D] == 0xFF) {
        p = D_8009A0A0;
        if (((s8*)p)[2] == 0) {
            func_800171E8(obj, 6);
        } else {
            func_800171E8(obj, 7);
        }
        obj[0x16] = 0;
        obj[0x62] = 0;
        q = D_8009A0A0;
        if (((s8*)q)[2] == 0) {
            q[0x15] = obj[0x15];
        } else if (obj[0x15] == 0) {
            q[0x15] = 0x40;
        } else {
            q[0x15] = 0;
        }
        r = D_8009A0A0;
        if (*(s16*)(r + 0xA) < D_800FA240_ovl03 ||
            D_800FA242_ovl03 < *(s16*)(r + 0xA)) {
            *(s16*)(r + 0xA) = *(s16*)(obj + 0xA);
        } else {
            *(s16*)(obj + 0xA) = *(s16*)(r + 0xA);
        }
        t = D_8009A0A0;
        if (*(s16*)(t + 0xE) < D_800FA244_ovl03) {
            *(s16*)(t + 0xE) = *(s16*)(obj + 0xE);
        } else {
            *(s16*)(obj + 0xE) = *(s16*)(t + 0xE);
        }
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s16*)(obj + 0x7C) = 0;
        *(s16*)(obj + 0x7E) = 0;
        obj[6] += 2;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
