/* Shared body (DK-5), from the banked draft of func_800F5154_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_8002DF78(void);
extern void func_8003D2C4(void);
extern u8 D_8009A240;

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    obj[0x91] = func_8002DF78() & 0xF;
    if (obj[0x91] < 5) {
        obj[0x91] = 0;
    } else if (obj[0x91] < 8) {
        obj[0x91] = 1;
    } else if (obj[0x91] < 11) {
        obj[0x91] = 2;
    } else {
        obj[0x91] = 3;
    }
    func_8003D2C4();
    ((s8*)obj)[0x90] = -1;
    obj[0x8D] = 0;
    obj[5] = 4;
    obj[6] = 0;
    obj[4]++;
    D_8009A240 = 2;
}
