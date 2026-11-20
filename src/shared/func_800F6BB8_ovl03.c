/* Shared body (DK-5), from the banked draft of func_800F6BB8_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);

void DEDUP_NAME(u8* arg0) {
    s16 angle;
    u8* base;
    u8* base2;

    func_800317B8(arg0);
    *(u16*)(arg0 + 0x42) &= 0x7FFF;
    if (func_80031DD0(arg0) < 0) {
        func_8004FD24(arg0);
        arg0[4]++;
        func_8002D9EC(arg0, 0x16, 0x16);
        return;
    }
    switch (*(s8*)(arg0 + 5)) {
    case 0:
        if (!(*(u16*)(arg0 + 0x7C) & 3)) {
            *(s32*)(arg0 + 0x24) = -*(s32*)(arg0 + 0x24);
        }
        if (++*(s16*)(arg0 + 0x7C) == 0x14) {
            base = g_Player;
            if (*(s16*)(base + 0xA) > *(s16*)(arg0 + 0xA)) {
                arg0[0x15] = 0x40;
            } else {
                arg0[0x15] = 0;
            }
            base2 = g_Player;
            angle = ratan2(*(s16*)(base2 + 0xE) - *(s16*)(arg0 + 0xE),
                           *(s16*)(base2 + 0xA) - *(s16*)(arg0 + 0xA));
            *(s32*)(arg0 + 0x20) = rcos(angle) << 5;
            *(s32*)(arg0 + 0x24) = -rsin(angle) << 5;
            *(s16*)(arg0 + 0x7C) = 0;
            arg0[5]++;
        }
        break;
    case 1:
        if (++*(s16*)(arg0 + 0x7C) == 0xC8) {
            arg0[4] = 2;
        }
        break;
    }
    if (*(s8*)(*(u8**)(arg0 + 0x80) + 4) == 2) {
        func_8004FD24(arg0);
        arg0[4] = 2;
    }
    if (*(s8*)(*(u8**)(arg0 + 0x80) + 5) == 0xA) {
        arg0[4] = 2;
    }
    func_8002D9EC(arg0, 0x10, 0x10);
    animate_object(arg0);
    apply_object_motion(arg0);
}
