/* Shared body (DK-5), from the banked draft of func_800F3DBC_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s32 func_8002DFF8(void* arg0, s32 arg1, s32 arg2);
extern void func_8002E0F8(s32* a0, s32* a1, u8 a2);
extern s16 D_8009A0AA;
extern s16 D_800FB62E_ovl09;
extern s16 D_800FB630_ovl09;
extern s16 D_800FB632_ovl09;
extern s16 D_800FB634_ovl09;

void DEDUP_NAME(u8* obj) {
    func_800171E8(obj, 0);
    if (D_8009A0AA <= D_800FB632_ovl09) {
        obj[0x15] = 0;
        func_8002E0F8(
            (s32*)(obj + 0x20), (s32*)(obj + 0x24),
            func_8002DFF8(obj, D_800FB630_ovl09 << 16, D_800FB634_ovl09 << 16));
    } else {
        obj[0x15] = 0x40;
        func_8002E0F8(
            (s32*)(obj + 0x20), (s32*)(obj + 0x24),
            func_8002DFF8(obj, D_800FB62E_ovl09 << 16, D_800FB634_ovl09 << 16));
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s32*)(obj + 0x20) = *(s32*)(obj + 0x20) * 3;
    *(s32*)(obj + 0x24) = *(s32*)(obj + 0x24) * 3;
    obj[6]++;
    func_80017248(obj);
    func_8002DED4(obj);
}
