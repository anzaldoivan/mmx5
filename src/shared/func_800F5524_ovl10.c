/* Shared body (DK-5), from the banked draft of func_800F5524_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800F6250_ovl10(void*);
extern void func_80017248(u8* obj);
extern u8 D_800FB7E8_ovl10[];
extern u8 D_800FB7EC_ovl10[];
extern u8 D_800FB7F0_ovl10[];
extern u8 D_800FB7F4_ovl10[];

void DEDUP_NAME(u8* obj) {
    func_800F6250_ovl10(obj);
    func_80017248(obj);
    if ((u8)(obj[0x47] - 0x43) < 6) {
        *(u8**)(obj + 0x50) = D_800FB7EC_ovl10;
        *(u8**)(obj + 0x54) = D_800FB7F4_ovl10;
    } else {
        *(u8**)(obj + 0x50) = D_800FB7E8_ovl10;
        *(u8**)(obj + 0x54) = D_800FB7F0_ovl10;
    }
    if (*(signed char*)(obj + 0x45) == 1) {
        obj[6] = 3;
    }
}
