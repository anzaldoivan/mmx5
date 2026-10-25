/* Shared body (DK-5), from the banked draft of func_800F7DF0_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

#define SCR D_1F80004C.bytes
extern void (*D_800FF54C_ovl06[])(u8*);
extern u8 D_8009A11A;
extern u8 D_80074EE0[];
extern u8 D_80075FC0[];
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);

void DEDUP_NAME(u8* obj) {
    s32 r;
    u16 t;
    u8* p;

    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    D_800FF54C_ovl06[*(signed char*)(obj + 5)](obj);
    if (SCR[0x85] == 0) {
        return;
    }
    func_800317B8(obj);
    r = func_80031DD0(obj);
    if (r < 0) {
        D_8009A11A = 1;
        obj[4] = 2;
        obj[5] = 0;
        return;
    }
    if (r > 0 && r != 0x7F) {
        *(u8**)(obj + 0x58) = D_80074EE0;
        if ((u32)(r - 0x19) < 2) {
            *(s16*)(SCR + 0x8E) = 2;
        } else {
            *(s16*)(SCR + 0x8E) = 0x1E;
        }
        if (r == 9 || r == 0x12 || r == 0x2D) {
            *(s16*)(SCR + 0x8E) = 10000;
            obj[5] = 0xB;
            obj[6] = 0;
        }
    }
    p = SCR;
    t = *(u16*)(p + 0x8E);
    if (*(s16*)(p + 0x8E) != 0) {
        *(s16*)(p + 0x8E) = t - 1;
        if (t & 2) {
            *(u16*)(obj + 0x42) |= 0x8000;
        } else {
            *(u16*)(obj + 0x42) &= 0x7FFF;
        }
        if (*(s16*)(SCR + 0x8E) == 0) {
            *(u8**)(obj + 0x58) = D_80075FC0;
            *(u16*)(obj + 0x42) &= 0x7FFF;
        }
    }
}
