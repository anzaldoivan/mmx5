/* Shared body (DK-5), from the banked draft of func_800FB214_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl01.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FD57C_ovl01[];
extern u8 D_800FD578_ovl01[];
extern u8 D_80074EE0[];

void DEDUP_NAME(u8* obj) {
    (*(u16*)(obj + 0x7C))++;
    animate_object(obj);
    if (*(s16*)(obj + 0x7C) > 40) {
        if (obj[0x80] & 1) {
            obj[0x80] = 0x3C;
        } else {
            obj[0x80] = 0x3B;
        }
        func_800FB308_ovl01(obj);
        set_animation(obj, 0);
        obj[5] = 3;
        obj[6] = 0;
        obj[0x91] = 5;
        if (*(s8*)(obj + 0x5C) < (s8)(D_800D1CA2 / 3)) {
            obj[0x93] = 1;
        }
        *(u8**)(obj + 0x50) = D_800FD57C_ovl01;
        *(u8**)(obj + 0x54) = D_800FD578_ovl01;
        *(u8**)(obj + 0x58) = D_80074EE0;
    }
}
