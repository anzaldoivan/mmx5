/* Shared body (DK-5), from the banked draft of func_800F55B4_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_8003D29C(s32, s32);
extern void func_80024548(s32);
extern u8 D_8009A1F8[];
extern Glb800F3EA0 D_800D1C00;
extern u8 D_800FA064_ovl11[];

void DEDUP_NAME(u8* obj) {
    s16 t;

    t = --*(s16*)(obj + 0x7C);
    if (t == 0) {
        func_8003D29C(0x14, 0x40);
    } else if (t == 0xA0) {
        u8* a = D_8009A1F8;

        *(u16*)D_800FA064_ovl11 = *(u16*)(a + 0x26);
        *(u16*)(a + 0x24) -= 0x10;
        *(u16*)(a + 0x26) = *(u16*)(a + 0x24) - 0x30;
    }
    if (*(s8*)*(u8**)(D_1F80004C.bytes + 0x84) == 0) {
        D_800D1C00.unk24 = 1;
        D_800D1C00.unk25 = 0;
        D_800D1C00.unk20 = obj;
        D_800D1C00.unkA2 = 0x38;
        if (D_800D1C00.unkC == 0xC) {
            func_80024548(-1);
        } else {
            func_80024548(1);
        }
        D_1F80004C.bytes[0x8C] = D_800D1C00.unkA2;
        obj[0x15] = 0;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0xFFFE8000;
        *(s32*)(obj + 0x2C) = 0;
        obj[3] = 1;
        obj[6]++;
    }
}
