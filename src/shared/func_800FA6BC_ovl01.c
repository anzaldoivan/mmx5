/* Shared body (DK-5), from the banked draft of func_800FA6BC_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8001296C(s32);
extern void func_800FB418_ovl01(s32, void*, u8*, s32);
extern void func_80050650(s32, s16, s16, s16, s16, s32);
extern void func_80016490(s32, s32, void*);
extern void func_8002A600(s32, s32, s32);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800FD9CC_ovl01[];

void DEDUP_NAME(u8* obj) {
    u16 x;

    func_80017248(obj);
    func_8002DED4(obj);
    if (obj[0x70] & 8) {
        func_8001296C(5);
        *(s32*)(obj + 0x68) = 0;
        func_800FB418_ovl01(0x1E, D_800FD9CC_ovl01, obj, 2);
        x = *(u16*)(obj + 0xA);
        func_80050650(0x21, x - 0x50, *(s16*)(obj + 0xE), x + 0x50,
                      *(u16*)(obj + 0xE) + 0x80, 6);
        func_80016490(2, 0xC, obj);
        func_8002A600(0x28, 4, 2);
        func_800171E8(obj, 0xA);
        obj[6] = 5;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
    }
}
