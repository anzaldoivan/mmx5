/* Shared body (DK-5), from the banked draft of func_800F56E8_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_8009A1F8[];
extern s8 D_800D1C00[];
extern u8 D_800F9F14_ovl11[];
extern u8 D_800FA064_ovl11[];

void DEDUP_NAME(u8* obj) {
    u8* scr;

    if (((s8*)obj)[0x45] == 1) {
        set_animation(obj, 0);
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        play_sound(0, 0xE, 0);
        *(s16*)(obj + 0x7C) = 2;
    }
    if (D_800D1C00[0xC] != 0xC) {
        u8* a = D_8009A1F8;

        *(s16*)(a + 0x26) = 0x1040;
    } else {
        u8* b = D_8009A1F8;

        *(s16*)(b + 0x26) = 0xE40;
    }
    obj[0x5C]++;
    scr = D_1F80004C.bytes;
    if (((s8*)obj)[0x5C] == scr[0x8C]) {
        u8* q = D_8009A1F8;

        q[0x48] = D_800FA064_ovl11[2];
        scr[0x8B] = 1;
        ((s32(*)())func_8003D2C4)();
        obj[5] = 7;
        obj[6] = 0;
        if (D_800D1C00[0xC] != 0xC) {
            func_80028B18(0, 0x1080, 0xD0, D_800F9F14_ovl11);
        }
    }
    if (((s8*)obj)[0x5C] >= D_1F80004C.bytes[0x8C] - 20) {
        animate_object(obj);
    }
}
