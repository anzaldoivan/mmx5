/* Shared body (DK-5), from the banked draft of func_800F5454_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern u8 D_800FC1C8_ovl10[];

void DEDUP_NAME(u8* obj) {
    func_8002DED4(obj);
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 2 && *(s32*)(obj + 0x24) <= 0) {
        func_800171E8(obj, 3);
    }
    if ((obj[0x70] & 8) && *(s32*)(obj + 0x24) <= 0) {
        if (obj[0x88] == 0 && *(u16*)(obj + 0x92) == 0) {
            D_800FC1C8_ovl10[1] = 1;
            func_800171E8(obj, 0x20);
        } else {
            D_800FC1C8_ovl10[1] = 0;
            func_800171E8(obj, 0x10);
        }
        obj[6] = 2;
    }
}
