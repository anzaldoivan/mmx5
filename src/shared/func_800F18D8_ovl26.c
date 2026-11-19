/* Shared body (DK-5), from the banked draft of func_800F18D8_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_8009A197;
extern void (*D_800F95CC_ovl26[])(u8* obj);

void DEDUP_NAME(u8* obj) {
    if (is_off_screen(obj, 0x40, 0x40) == 0) {
        func_8002D9EC(obj, 0x20, 0x20);
    } else {
        obj[4] = 3;
        return;
    }
    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        D_800F95CC_ovl26[(signed char)obj[5]](obj);
        animate_object(obj);
    }
    if (func_800317B8(obj) != 0) {
        obj[4] = 2;
    }
    if (D_1F80004C.bytes[0x85] != 0) {
        if (func_80031DD0(obj) < 0) {
            set_animation(obj, 2);
            obj[4] = 4;
        }
    }
}
