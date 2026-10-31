/* Shared body (DK-5), from the banked draft of func_800F4218_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

void func_800171E8(u8* obj, s32 state);
void func_80017248(u8* obj);
void func_8002DED4(u8* obj);
extern s16 D_800FB62E_ovl09;
extern s16 D_800FB630_ovl09;

void DEDUP_NAME(u8* obj) {
    s16 cur;
    s16 lim;
    s32 v;

    if (obj[0x15] == 0) {
        v = *(s32*)(obj + 0x20);
        if (v < 0) {
            if (*(s16*)(obj + 0xA) <= D_800FB630_ovl09) {
                *(s16*)(obj + 0xA) = D_800FB630_ovl09;
                goto clear0; // !FAKE: goto kept for the matching branch layout
            }
        } else if (v > 0 && *(s16*)(obj + 0xA) >= D_800FB630_ovl09) {
            *(s16*)(obj + 0xA) = D_800FB630_ovl09;
        clear0:
            *(s32*)(obj + 0x20) = 0;
        }
        cur = *(s16*)(obj + 0xA);
        lim = D_800FB630_ovl09;
    } else {
        v = *(s32*)(obj + 0x20);
        if (v < 0) {
            if (*(s16*)(obj + 0xA) <= D_800FB62E_ovl09) {
                *(s16*)(obj + 0xA) = D_800FB62E_ovl09;
                goto clear1; // !FAKE: goto kept for the matching branch layout
            }
        } else if (v > 0 && *(s16*)(obj + 0xA) >= D_800FB62E_ovl09) {
            *(s16*)(obj + 0xA) = D_800FB62E_ovl09;
        clear1:
            *(s32*)(obj + 0x20) = 0;
        }
        cur = *(s16*)(obj + 0xA);
        lim = D_800FB62E_ovl09;
    }
    if (cur == lim) {
        func_800171E8(obj, 8);
        *(s16*)(obj + 0x7C) = 0;
        obj[6]++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
