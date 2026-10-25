/* Shared body (DK-5), from the banked draft of func_800F0A84_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(u8*, s32);
extern u8 D_800FA75C_ovl00[];
extern u8 D_800FA77C_ovl00[];

#define CTX (D_1F80004C.bytes)
#define CTX80 (*(u8**)(CTX + 0x80))

void DEDUP_NAME(u8* obj) {
    s8 t;

    if (CTX[0x90] == 0) {
        *(u16*)(obj + 0xA) = *(u16*)(CTX80 + 0xA);
        *(u16*)(obj + 0xE) = *(u16*)(CTX80 + 0xE);
        t = *(s8*)(CTX80 + 0x45);
        if (t == 2) {
            DEDUP_CALLEE(obj, 3);
        } else if (t == 1) {
            obj[5] = 2;
            obj[6] = 0;
            *(u8**)(obj + 0x54) = D_800FA75C_ovl00;
            *(u8**)(obj + 0x68) = D_800FA77C_ovl00;
        }
    }
}
