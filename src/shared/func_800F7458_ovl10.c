/* Shared body (DK-5), from the banked draft of func_800F7458_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D89C(u8*);
extern int func_8002D6FC();

void DEDUP_NAME(u8* obj) {
    if (obj[0x47] == 0xAA || obj[0x47] == 0xAB) {
        obj[0x16] = 2;
    } else {
        obj[0x16] = 5;
    }
    func_80017248(obj);
    func_8002D89C(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        func_8002D6FC(obj);
    }
    if (*(s8*)(*(u8**)(obj + 0x7C) + 4) == 3) {
        func_8002D6FC(obj);
    }
}
