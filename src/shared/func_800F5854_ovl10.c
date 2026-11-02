/* Shared body (DK-5), from the banked draft of func_800F5854_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern u32 func_8002DF78(void);
extern u8 D_800FBE00_ovl10[];

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    obj[0x88] = 0;
    switch (obj[0x8A]) {
    case 0:
        if ((func_8002DF78() & 0xF) < 6) {
            obj[0x89] = 0;
        } else {
            obj[0x89] = 1;
        }
        break;
    case 1:
        if ((func_8002DF78() & 0xF) < 12) {
            obj[0x89] = 0;
        } else {
            obj[0x89] = 1;
        }
        break;
    case 2:
        if ((func_8002DF78() & 0xF) < 10) {
            obj[0x89] = 0;
        } else {
            obj[0x89] = 1;
        }
        break;
    }
    obj[5] = D_800FBE00_ovl10[obj[0x88] + (obj[0x8A] * 2 + obj[0x89]) * 5];
    obj[6] = 0;
}
