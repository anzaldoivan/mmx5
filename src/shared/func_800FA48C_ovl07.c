/* Shared body (DK-5), from the banked draft of func_800FA48C_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern s32 func_80016490(s32, s32, void*);
extern void func_800FCAD8_ovl07(u8* obj, s16 x, s16 y, s32 kind, s32 arg4);
extern u8 D_80101C10_ovl07[];

void DEDUP_NAME(u8* o) {
    if (((s8*)o)[0x45] != 0) {
        D_1F80004C.bytes[0x97] = 0;
        D_1F80004C.bytes[0x96] = D_80101C10_ovl07[D_1F80004C.s8s[0x97] * 2];
        D_1F80004C.bytes[0x95] =
            (&D_80101C10_ovl07[D_1F80004C.s8s[0x97] * 2])[1];
        func_80016490(2, 0x24, o);
        if (o[0x15] == 0) {
            func_800FCAD8_ovl07(o, *(s16*)(o + 0xA), *(s16*)(o + 0xE), 1, 0);
            func_800FCAD8_ovl07(o, *(s16*)(o + 0xA), *(s16*)(o + 0xE), 3, 0);
            func_800FCAD8_ovl07(o, *(s16*)(o + 0xA), *(s16*)(o + 0xE), 2, 0);
        } else {
            func_800FCAD8_ovl07(o, *(s16*)(o + 0xA), *(s16*)(o + 0xE), 1, 1);
            func_800FCAD8_ovl07(o, *(s16*)(o + 0xA), *(s16*)(o + 0xE), 3, 1);
            func_800FCAD8_ovl07(o, *(s16*)(o + 0xA), *(s16*)(o + 0xE), 0, 1);
        }
        *(s16*)(o + 0x7C) = 0x14;
        o[0x6]++;
    }
}
