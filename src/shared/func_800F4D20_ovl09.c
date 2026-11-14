/* Shared body (DK-5), from the banked draft of func_800F4D20_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DF54(u8* a0);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern s32 func_80016490(s32, s32, void*);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s16 D_800FB67A_ovl09;

void DEDUP_NAME(u8* o) {
    s32 v;
    s16 ang;
    s32 dx;

    func_8002DF54(o);
    switch (((s8*)o)[5]) {
    case 0:
        if ((*(s8**)(o + 0x7C))[5] == 0xB || (*(s8**)(o + 0x7C))[4] == 2) {
            *(s32*)(o + 0x20) = 0;
            *(s32*)(o + 0x24) = 0;
            *(s32*)(o + 0x50) = 0;
            o[6] = 0;
            o[5] = 3;
        }
        v = *(s32*)(o + 0x20);
        if (v < 0) {
            if (*(s16*)(o + 0xA) < *(u32*)(o + 0x8C)) {
                *(s16*)(o + 0xA) = *(s32*)(o + 0x8C);
                *(s32*)(o + 0x20) = 0;
            }
        } else if (v > 0) {
            if (*(u32*)(o + 0x8C) < *(s16*)(o + 0xA)) {
                *(s16*)(o + 0xA) = *(s32*)(o + 0x8C);
                *(s32*)(o + 0x20) = 0;
            }
        }
        if (*(s16*)(o + 0xE) >= D_800FB67A_ovl09) {
            *(s16*)(o + 0xE) = D_800FB67A_ovl09;
            *(s32*)(o + 0x20) = 0;
            *(s32*)(o + 0x24) = 0;
            o[5]++;
        }
        func_8002D9EC(o, 0x20, 0x20);
        break;
    case 1:
        if ((*(s8**)(o + 0x7C))[5] == 0xB || (*(s8**)(o + 0x7C))[4] == 2) {
            *(s32*)(o + 0x20) = 0;
            *(s32*)(o + 0x24) = 0;
            *(s32*)(o + 0x50) = 0;
            o[6] = 0;
            o[5] = 3;
        }
        if (--*(s32*)(o + 0x84) == 0) {
            if ((*(u8**)(o + 0x7C))[0x15] == 0) {
                dx = *(s16*)(*(u8**)(o + 0x7C) + 0xE) - *(s16*)(o + 0xE);
                ang = ratan2(dx, -(*(s16*)(o + 0xA) + 0x1C) +
                                     *(s16*)(*(u8**)(o + 0x7C) + 0xA));
                *(s32*)(o + 0x8C) = *(s16*)(*(u8**)(o + 0x7C) + 0xA) - 0x1C;
            } else {
                dx = *(s16*)(*(u8**)(o + 0x7C) + 0xE) - *(s16*)(o + 0xE);
                ang = ratan2(dx, -(*(s16*)(o + 0xA) + -0x1C) +
                                     *(s16*)(*(u8**)(o + 0x7C) + 0xA));
                *(s32*)(o + 0x8C) = *(s16*)(*(u8**)(o + 0x7C) + 0xA) + 0x1C;
            }
            *(s32*)(o + 0x20) = rcos(ang) * 0xC0;
            *(s32*)(o + 0x24) = -rsin(ang) * 0xC0;
            func_80016490(2, 0x82, o);
            o[5]++;
        }
        func_8002D9EC(o, 0x20, 0x20);
        break;
    case 2:
        if ((*(s8**)(o + 0x7C))[5] == 0xB || (*(s8**)(o + 0x7C))[4] == 2) {
            *(s32*)(o + 0x20) = 0;
            *(s32*)(o + 0x24) = 0;
            *(s32*)(o + 0x50) = 0;
            o[6] = 0;
            o[5] = 3;
        }
        v = *(s32*)(o + 0x20);
        if (v < 0) {
            if (*(s16*)(o + 0xA) < *(u32*)(o + 0x8C)) {
                *(s16*)(o + 0xA) = *(s32*)(o + 0x8C);
                *(s32*)(o + 0x20) = 0;
            }
        } else if (v > 0) {
            if (*(u32*)(o + 0x8C) < *(s16*)(o + 0xA)) {
                *(s16*)(o + 0xA) = *(s32*)(o + 0x8C);
                *(s32*)(o + 0x20) = 0;
            }
        }
        if (*(s16*)(o + 0xE) <= *(s16*)(*(u8**)(o + 0x7C) + 0xE)) {
            *(s16*)(o + 0xE) = *(s16*)(*(u8**)(o + 0x7C) + 0xE);
            o[4]++;
        }
        func_8002D9EC(o, 0x20, 0x20);
        break;
    case 3:
        if ((s8)++o[6] == 0x10) {
            o[4]++;
        }
        if (o[6] & 1) {
            func_8002D9EC(o, 0x20, 0x20);
        }
        break;
    }
    func_80017248(o);
    func_800317B8(o);
}
