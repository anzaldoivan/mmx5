/* Shared body (DK-5), from the banked draft of func_800F866C_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 DEDUP_CALLEE(u8* obj);
extern void* D_800FA1E8_ovl03[];
extern void* D_800FA1F4_ovl03[];
extern void* D_800FA200_ovl03[];
extern void* D_800FA20C_ovl03[];

void DEDUP_NAME(u8* o) {
    *(s32*)(o + 0x18) = *(s32*)(o + 0x8);
    *(s32*)(o + 0x1C) = *(s32*)(o + 0xC);
    o[3] = 0;
    switch (*(s8*)(o + 2)) {
    case 1:
        ((void (*)(u8*))D_800FA1E8_ovl03[*(s8*)(o + 4)])(o);
        break;
    case 2:
        ((void (*)(u8*))D_800FA1F4_ovl03[*(s8*)(o + 4)])(o);
        break;
    case 3:
        ((void (*)(u8*))D_800FA200_ovl03[*(s8*)(o + 4)])(o);
        break;
    case 4:
        ((void (*)(u8*))D_800FA20C_ovl03[*(s8*)(o + 4)])(o);
        break;
    }
    DEDUP_CALLEE(o);
}
