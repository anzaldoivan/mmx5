/* Shared body (DK-5), from the banked draft of func_800F5AE0_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void func_800F6250_ovl10(void*);
extern u8 D_800FBE00_ovl10[];

void DEDUP_NAME(u8* obj) {
    u8 v;

    func_800F6250_ovl10(obj);
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0);
        if (*(signed char*)(obj + 2) != 0) {
            v = 6;
        } else if (obj[0x8E] != 0) {
            obj[0x8E] = 0;
            obj[0x88] = 0;
            obj[5] = D_800FBE00_ovl10[(obj[0x8A] * 2 + obj[0x89]) * 5];
            goto end;
        } else {
            v = D_800FBE00_ovl10[++obj[0x88] + (obj[0x8A] * 2 + obj[0x89]) * 5];
        }
        obj[5] = v;
    end:
        obj[6] = 0;
    }
}
