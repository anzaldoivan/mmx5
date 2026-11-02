/* Shared body (DK-5), from the banked draft of func_8001D7E8 by tools/wave/gate.py rescan. */
#include "types.h"

s32 TestEvent(s32);
s32 _card_info(s32);
void func_8001D90C(s32);
s32 func_8001DA18(void);
extern s32 D_800E81B8;
extern s32 D_800E81BC;
extern s32 D_800E81C0;
extern s32 D_800E81C4;

s32 DEDUP_NAME(s32 arg0) {
    s32 ret;
    s32 i;
    s32 prev;

    TestEvent(D_800E81B8);
    i = 3;
    TestEvent(D_800E81BC);
    prev = 0xFF;
    TestEvent(D_800E81C0);
    TestEvent(D_800E81C4);
    do {
        if (_card_info(arg0 << 4) != 0) {
            ret = func_8001DA18();
            if (!(ret & 1) && ret == prev) {
                break;
            }
            prev = ret;
        }
    } while (--i != 0);
    if (ret == 2) {
        func_8001D90C(arg0);
        ret = 0;
    }
    return ret;
}
