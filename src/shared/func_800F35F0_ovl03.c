/* Shared body (DK-5), from the banked draft of func_800F35F0_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_8002DC14(void);
extern void func_8002385C(s32, s32, s32);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_800D1C00[];

void DEDUP_NAME(u8* obj) {
    s8* p;

    if (*(s8*)(obj + 0x46) == 0) {
        p = (s8*)D_800D1C00;
        if (p[0xC] != 0xC) {
            if (func_8002DC14() == 0) {
                func_8002385C(0x6B, 0xFF, p[0x2E]);
            } else if (func_8002DC14() == 1) {
                func_8002385C(0x30, 0xFF, p[0x2E]);
            } else {
                func_8002385C(0x62, 0xFF, p[0x2E]);
            }
            D_800D1C00[0x2E] = 1;
        }
        func_800171E8(obj, 1);
        *(s32*)(obj + 0x24) = 0;
        *(s16*)(obj + 0x7C) = 3;
        obj[6]++;
    }
    if (*(s8*)(obj + 0x45) != 0 && *(s32*)(obj + 0x24) == 0) {
        *(s32*)(obj + 0x24) = 0xFFFF0000;
    }
    func_80017248(obj);
    func_8002DED4(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}
