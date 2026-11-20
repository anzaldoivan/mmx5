/* Shared body (DK-5), from the banked draft of func_800FA5D8_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl07.h"
#include "mmx5/sound.h"
#include "addr.h"

extern void start_pad_vibration(s32);
extern void func_800FCAD8_ovl07(u8* obj, s16 x, s16 y, s32 kind, s32 arg4);
extern s16 D_80102014_ovl07;
extern s16 D_80102016_ovl07;

void DEDUP_NAME(u8* obj) {
    s16 x;
    s16 y;

    if (((s8*)obj)[0x45] == 2) {
        start_pad_vibration(7);
        play_sound(2, 0x23, obj);
        x = D_80102014_ovl07 + 0x2250;
        y = D_80102016_ovl07 + 0x570;
        func_800FCAD8_ovl07(obj, x, y, 4, 0);
        D_1F80004C.bytes[0x97] = 2;
        D_1F80004C.bytes[0x96] = D_80101C10_ovl07[D_1F80004C.s8s[0x97]][0];
        D_1F80004C.bytes[0x95] = D_80101C10_ovl07[D_1F80004C.s8s[0x97]][1];
    } else if (((s8*)obj)[0x45] == 1) {
        *(s16*)(obj + 0x7C) = 2;
        obj[6]++;
    }
}
