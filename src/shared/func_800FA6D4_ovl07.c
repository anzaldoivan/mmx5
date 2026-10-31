/* Shared body (DK-5), from the banked draft of func_800FA6D4_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_800FCB98_ovl07(u8* obj, s32 x, s32 y, s32 mode);
extern u32 func_8002DF78(void);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern s16 D_80102016_ovl07;
extern s16 D_80101BFC_ovl07[][2];
extern s16 D_80102014_ovl07;
extern s16 D_8009A202;

void DEDUP_NAME(u8* arg0) {
    u8 idx;
    s32 angle;

    func_800171E8(arg0, 2);
    D_1F80004C.bytes[0x92] = 1;
    func_800FCB98_ovl07(arg0, *(s16*)(arg0 + 0xA), *(s16*)(arg0 + 0xE), 2);
    idx = func_8002DF78() % 3;
    D_1F80004C.bytes[0x90] = idx;
    angle = ratan2(
        *(s16*)(arg0 + 0xE) - (D_80101BFC_ovl07[idx][1] + D_80102016_ovl07),
        (D_80101BFC_ovl07[idx][0] + D_80102014_ovl07) - *(s16*)(arg0 + 0xA));
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    *(s32*)(arg0 + 0x20) = rcos(angle) << 6;
    *(s32*)(arg0 + 0x24) = rsin(angle) << 6;
    switch (D_1F80004C.bytes[0x90]) {
    case 0:
        arg0[0x15] = 0x40;
        break;
    case 1:
        arg0[0x15] = 0;
        break;
    case 2:
        if (*(s16*)(arg0 + 0xA) - D_8009A202 >= 0xA1) {
            arg0[0x15] = 0;
        } else {
            arg0[0x15] = 0x40;
        }
        break;
    }
    arg0[6]++;
}
