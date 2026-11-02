/* Shared body (DK-5), from the banked draft of func_800F6EEC_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8002DED4(u8* obj);

void DEDUP_NAME(u8* p) {
    switch ((s8)p[5]) {
    case 0:
        p[7]--;
        if ((s8)p[7] == -1) {
            p[7] = 0;
            p[5]++;
        }
        func_8002D9EC(p, 0x20, 0x20);
        break;
    case 1:
        p[7]++;
        if ((s8)p[7] == 0x14) {
            p[4] = 2;
        }
        if (p[7] & 1) {
            func_8002D9EC(p, 0x20, 0x20);
        }
        break;
    }
    func_80017248(p);
    func_8002DED4(p);
}
