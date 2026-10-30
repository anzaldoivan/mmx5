/* Shared body (DK-5), from the banked draft of func_800F3B18_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern u8 D_8009A0A0[];
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;
extern s16 D_800FA246_ovl03;
extern s16 D_800FA248_ovl03;
extern s16 D_800FA24A_ovl03;

void DEDUP_NAME(u8* obj) {
    s32 e1;
    s32 e2;
    s32 d1;
    s32 d2;
    s16 x;
    s16 a;
    u8* p;
    u8* q;
    s32 e;

    func_800171E8(obj, 1);
    p = D_8009A0A0;
    if (*(s16*)(p + 0xA) > *(s16*)(obj + 0xA)) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    if (*(s16*)(obj + 0xE) < D_800FA24A_ovl03) {
        if (*(s16*)(obj + 0xA) < D_800FA248_ovl03) {
            x = D_800FA240_ovl03 - 1;
        } else {
            x = D_800FA242_ovl03 + 1;
        }
        d1 = D_800FA244_ovl03;
        e1 = *(s16*)(obj + 0xE) + 1;
        a = ratan2(d1 - e1, x - *(s16*)(obj + 0xA));
        *(s32*)(obj + 0x20) = rcos(a) * 48;
        *(s32*)(obj + 0x24) = -rsin(a) * 48;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[6] += 1;
    } else if (q = D_8009A0A0, ((s8*)q)[2] == 0) {
        if (*(s16*)(obj + 0xA) < D_800FA248_ovl03) {
            x = D_800FA240_ovl03 - 1;
        } else {
            x = D_800FA242_ovl03 + 1;
        }
        d2 = D_800FA246_ovl03;
        e2 = *(s16*)(obj + 0xE) - 1;
        a = ratan2(d2 - e2, x - *(s16*)(obj + 0xA));
        *(s32*)(obj + 0x20) = rcos(a) * 48;
        *(s32*)(obj + 0x24) = -rsin(a) * 48;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[6] += 3;
    } else {
        if (*(s16*)(obj + 0xA) < D_800FA248_ovl03) {
            x = D_800FA240_ovl03 - 1;
            obj[0x8E] = 2;
        } else {
            x = D_800FA242_ovl03 + 1;
            obj[0x8E] = 3;
        }
        e = *(s16*)(obj + 0xE) - 1;
        a = ratan2(D_800FA246_ovl03 - e, x - *(s16*)(obj + 0xA));
        *(s32*)(obj + 0x20) = rcos(a) * 48;
        *(s32*)(obj + 0x24) = -rsin(a) * 48;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[6] += 5;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
