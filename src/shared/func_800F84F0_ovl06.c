/* Shared body (DK-5), from the banked draft of func_800F84F0_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800FF1E4_ovl06[];
extern u8 D_800FF1E8_ovl06[];
extern s16 D_800FF4F4_ovl06[][2];
extern s16 D_800FF94C_ovl06;
extern s16 D_800FF94E_ovl06;

void DEDUP_NAME(u8* obj) {
    s32 i;
    s32 c;
    s32 d;

    func_80017248(obj);
    func_8002DF54(obj);
    i = obj[0x15] == 0;
    c = D_800FF4F4_ovl06[i][0] + D_800FF94C_ovl06;
    if (*(s16*)(obj + 0xA) >= c - 4 && c + 4 >= *(s16*)(obj + 0xA)) {
        d = D_800FF4F4_ovl06[i][1] + D_800FF94E_ovl06;
        if (*(s16*)(obj + 0xE) >= d - 4 && d + 4 >= *(s16*)(obj + 0xE)) {
            func_800171E8(obj, 0xD);
            *(u8**)(obj + 0x50) = D_800FF1E4_ovl06;
            *(u8**)(obj + 0x54) = D_800FF1E8_ovl06;
            *(s16*)(obj + 0x7C) = 0x28;
            obj[6]++;
        }
    }
}
