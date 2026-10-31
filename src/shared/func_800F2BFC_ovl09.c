/* Shared body (DK-5), from the banked draft of func_800F2BFC_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_8002DC14(void);
extern void func_8002385C(s32, s32, s32);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_800D1C00[];
extern s16 D_800FB61C_ovl09;
extern s16 D_800FB61E_ovl09;

void DEDUP_NAME(u8* obj) {
    if (*(s16*)(obj + 0xA) >= D_800FB61C_ovl09) {
        *(s16*)(obj + 0xA) = D_800FB61C_ovl09;
        *(s32*)(obj + 0x20) = 0;
    }
    if (*(s16*)(obj + 0xE) <= D_800FB61E_ovl09) {
        *(s16*)(obj + 0xE) = D_800FB61E_ovl09;
        *(s32*)(obj + 0x24) = 0;
    }
    if (*(s16*)(obj + 0xA) == D_800FB61C_ovl09 &&
        *(s16*)(obj + 0xE) == D_800FB61E_ovl09) {
        if ((s8)D_800D1C00[0xC] != 0xC) {
            if (func_8002DC14() == 0) {
                func_8002385C(0x31, 0xFF, (s8)D_800D1C00[0x2E]);
            } else if (func_8002DC14() == 1) {
                func_8002385C(0x63, 0xFF, (s8)D_800D1C00[0x2E]);
            } else {
                func_8002385C(0x63, 0xFF, (s8)D_800D1C00[0x2E]);
            }
            D_800D1C00[0x2E] = 1;
        }
        *(s16*)(obj + 0x7C) = 3;
        obj[6]++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}
