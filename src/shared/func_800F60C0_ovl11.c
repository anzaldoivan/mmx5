/* Shared body (DK-5), from the banked draft of func_800F60C0_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u16 D_800FA05C_ovl11[];

void DEDUP_NAME(u8* obj) {
    u32 r;
    s32 t;
    s32 o;
    u16 d;

    move_object(obj);
    animate_object(obj);
    func_8002D9EC(obj, 0x40, 0x40);
    if (*(s8*)(obj + 3) == 0) {
        *(s8*)(obj + 0x9A) = 0;
    } else {
        *(s8*)(obj + 0x9A) = 1;
    }
    *(s8*)(obj + 3) = 1;
    if (*(s8*)(obj + 0x9A) == 0) {
        *(s32*)(obj + 0x54) = 0;
        *(s32*)(obj + 0x50) = 0;
        *(s8*)(obj + 0x9A) = 0;
        *(s8*)(obj + 3) = 0;
        D_1F80004C.bytes[0x92] = 5;
        if (*(s16*)(obj + 0x7E) == 0) {
            set_animation(obj, 1);
            r = random_byte();
            d = D_800FA05C_ovl11[0];
            o = (u8)(r % 3) * 16 - 0x70;
            *(s16*)(obj + 0xE) = d + o;
            t = (u8)((u32)random_byte() % 80);
            *(s16*)(obj + 0x7C) = (t + 0x50) / 4;
            *(s32*)(obj + 0x24) = 0;
            *(s8*)(obj + 6) = 9;
            D_1F80004C.bytes[0x93] = 0x3C;
            return;
        }
        *(s8*)(obj + 6) = 2;
        *(s16*)(obj + 0x7C) = 0x1E;
    }
}
