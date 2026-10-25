/* Shared body (DK-5), from the banked draft of func_800F9EE8_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);
extern u8 D_800FD580_ovl01[];
extern u8 D_800FD584_ovl01[];
extern u8 D_800FD588_ovl01[];
extern u8 D_800FD58C_ovl01[];
extern u8 D_800FD590_ovl01[];
extern u8 D_800FD594_ovl01[];

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    switch (obj[0x47]) {
    case 0xE:
    case 0xF:
        *(u8**)(obj + 0x50) = D_800FD580_ovl01;
        *(u8**)(obj + 0x54) = D_800FD584_ovl01;
        break;
    case 0x10:
        *(u8**)(obj + 0x50) = D_800FD588_ovl01;
        *(u8**)(obj + 0x54) = D_800FD58C_ovl01;
        break;
    case 0x11:
        *(u8**)(obj + 0x50) = D_800FD590_ovl01;
        *(u8**)(obj + 0x54) = D_800FD594_ovl01;
        obj[6] = 1;
        *(s16*)(obj + 0x7C) = 0;
        break;
    }
}
