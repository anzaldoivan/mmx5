/* Shared body (DK-5), from the banked draft of func_800EF7EC_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s16 D_8009A0AE;

void DEDUP_NAME(u8* arg0) {
    u8* p;
    u8* o;

    func_800317B8(arg0);
    switch (*(s8*)(arg0 + 5)) {
    case 0:
        if (*(s16*)(arg0 + 0xE) >= D_8009A0AE - 0x12) {
            p = func_8002D1A4();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x18;
                p[2] = 2;
                *(u8**)(p + 0x7C) = arg0;
            }
            p = func_8002D1A4();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x18;
                p[2] = 3;
                *(u8**)(p + 0x7C) = arg0;
            }
            *(s32*)(arg0 + 0x50) = 0;
            set_animation(arg0, 0xF);
            *(s32*)(arg0 + 0x24) = 0;
            arg0[5]++;
        }
        break;
    case 1:
        if (*(s8*)(arg0 + 0x46) == 0) {
            arg0[4] = 2;
        }
        break;
    }
    o = *(u8**)(arg0 + 0x7C);
    if (*(s8*)(o + 4) == 2 || *(s8*)(o + 5) == 9) {
        arg0[4] = 2;
    }
    func_8002D9EC(arg0, 0x10, 0x10);
    animate_object(arg0);
    move_object(arg0);
}
