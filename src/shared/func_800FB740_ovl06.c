/* Shared body (DK-5), from the banked draft of func_800FB740_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_8002DED4(u8* obj);
extern s32 func_8002F8FC(u8* a0);
extern void func_800FBD10_ovl06(u8* obj, s32 x, s32 y, s32 n);
extern u8 D_800FF684_ovl06[];
extern u8 D_800FF688_ovl06[];

void DEDUP_NAME(u8* obj) {
    if (obj[0x47] == 11) {
        *(u8**)(obj + 0x50) = D_800FF684_ovl06;
        *(u8**)(obj + 0x54) = D_800FF688_ovl06;
    }
    func_8002DED4(obj);
    if (obj[0x70] == 0) {
        func_8002F8FC(obj);
        if (obj[0x70] == 0) {
            return;
        }
    }
    func_800FBD10_ovl06(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 2);
    func_800FBD10_ovl06(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 3);
    *(s16*)(obj + 0x88) = 60;
    obj[6]++;
}
