/* Shared body (DK-5), from the banked draft of func_800F87F8_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* a0, s32 a1, s32 a2);
extern void (*D_800FB514_ovl00[])(u8*);
extern u8 D_800FB3DC_ovl00[];
extern u8 D_800FB3E0_ovl00[];
extern u8 D_800FB3E8_ovl00[];
extern u8 D_800FB3EC_ovl00[];
extern u8 D_80074EE0[];
extern u8 D_80075AC0[];

void DEDUP_NAME(u8* obj) {
    D_800FB514_ovl00[*(s8*)(obj + 6)](obj);
    DEDUP_CALLEE(obj, 0xFF, 0xFF);
    if (obj[0x47] == 6) {
        *(u8**)(obj + 0x50) = D_800FB3E0_ovl00;
        *(u8**)(obj + 0x54) = D_800FB3EC_ovl00;
        *(u8**)(obj + 0x58) = D_80075AC0;
    } else {
        *(u8**)(obj + 0x50) = D_800FB3DC_ovl00;
        *(u8**)(obj + 0x54) = D_800FB3E8_ovl00;
        *(u8**)(obj + 0x58) = D_80074EE0;
    }
}
