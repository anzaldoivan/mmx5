#include "types.h"

extern void func_80017248(u8* obj);

void func_800F9520_ovl09(u8* obj) {
    s8* s = (s8*)obj;
    s32 st = s[2];

    if (st == 1 && s[5] == 0) {
        if (--*(s16*)(obj + 0x56) == 0) {
            s[3] = st;
            ((volatile s8*)obj)
                [5]++; // !FAKE: volatile forces the reload of byte 5 the target does after the sh
        }
    }
    if (((s8*)*(u8**)(obj + 0x50))[4] != 3 || --*(s16*)(obj + 0x54) == 0) {
        s[4] = 4;
        s[5] = 0;
        s[3] = 0;
    } else {
        func_80017248(obj);
    }
}
