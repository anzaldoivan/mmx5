#include "types.h"

#define G (*(u8**)0x1F80004C)

extern u8 D_800F4FC0_ovl05[];
extern s8 D_800D1C44;
extern s16 D_8009A0AA;

void func_800EF390_ovl05(s8* s) {
    s32 d;
    s32 lim;
    s32 x;
    s32 c;

    if (((s8*)G)[0x84] != 0) {
        ((s8*)G)[0x84]--;
        return;
    }
    if (s[5] == 3) {
        return;
    }
    lim = D_800F4FC0_ovl05[D_800D1C44];
    c = D_8009A0AA;
    x = *(s16*)(s + 0xA);
    d = c - x;
    if (d >= 0) {
        if (lim >= d) {
            goto set;
        }
        return;
    } else if (lim < x - c) {
        return;
    }
set:
    s[5] = 3;
    s[6] = 0;
}
