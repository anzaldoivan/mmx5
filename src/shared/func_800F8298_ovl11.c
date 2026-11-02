/* Shared body (DK-5), from the banked draft of func_800F8298_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_80074EE0[];
extern u8 D_800F9D1C_ovl11[];
extern u8 D_800F9D20_ovl11[];
extern s32 D_800F9D24_ovl11[];
extern s32 D_800F9D3C_ovl11[];

void DEDUP_NAME(u8* obj) {
    obj[4] = 1;
    obj[6] = 0;
    *(s16*)(obj + 0x88) = 0;
    obj[0x16] = 5;
    if (*(s8*)(obj + 2) == 0) {
        func_80016490(2, 0x34, obj);
        obj[0x60] = 6;
        obj[5] = 0;
        func_800171E8(obj, 0xE);
        *(void**)(obj + 0x58) = D_80074EE0;
        *(void**)(obj + 0x54) = D_800F9D1C_ovl11;
        *(void**)(obj + 0x50) = D_800F9D20_ovl11;
        *(void**)(obj + 0x68) = 0;
        return;
    }
    obj[0x60] = 4;
    obj[5] = 3;
    func_800171E8(obj, 0xA);
    *(void**)(obj + 0x58) = 0;
    *(void**)(obj + 0x54) = 0;
    *(void**)(obj + 0x50) = &D_800F9D3C_ovl11[*(s8*)(obj + 0x45)];
    *(void**)(obj + 0x68) = &D_800F9D24_ovl11[*(s8*)(obj + 0x45)];
}
