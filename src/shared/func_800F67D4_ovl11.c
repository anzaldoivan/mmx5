/* Shared body (DK-5), from the banked draft of func_800F67D4_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern s32 func_8002E804(u8*, u8*);
extern u8 D_8009A0A0[];
extern s32 D_800F9D24_ovl11[];
extern s32 D_800F9D3C_ovl11[];
extern s16 D_800FA056_ovl11;
extern s16 D_800FA058_ovl11;

void DEDUP_NAME(u8* obj) {
    u8* p;
    s16 x;
    s32 i;

    i = *(s8*)(obj + 0x45);
    p = D_8009A0A0;
    *(s32**)(obj + 0x50) = &D_800F9D3C_ovl11[i];
    *(s32**)(obj + 0x68) = &D_800F9D24_ovl11[i];
    func_80017248(obj);
    func_8002DF54(obj);
    if (func_8002E804(obj, p) == 1) {
        if (*(s8*)(*(u8**)(obj + 0x7C) + 4) != 2) {
            if (*(s32*)(obj + 0x20) < 0) {
                *(s32*)(p + 8) += -0x20000;
            } else {
                *(s32*)(p + 8) += 0x20000;
            }
        } else {
            *(s32*)(obj + 0x54) = 0;
            *(s32*)(obj + 0x50) = 0;
        }
    }
    x = *(s16*)(obj + 0xA);
    if (x < D_800FA056_ovl11 - 0x50 || D_800FA058_ovl11 + 0x50 < x ||
        --*(u8*)(obj + 0x95) == 0) {
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = -0x4000;
        *(s32*)(obj + 0x68) = 0;
        *(u8*)(obj + 0x6) += 1;
    }
}
