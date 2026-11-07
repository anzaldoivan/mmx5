#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern u8 D_800D1C00[];

void func_800FFC98_ovl04(u8* obj) {
    u8* src;

    func_80017248(obj);
    src = *(u8**)(obj + 0x7C);
    if (*(s8*)(obj + 0x45) == 1) {
        func_800317B8(obj);
        *(s16*)(obj + 0xA) = *(s16*)(src + 0xA) + 0xF0;
        *(s16*)(obj + 0xE) = *(s16*)(src + 0xE);
    } else if (*(s8*)(obj + 0x45) ==
               2) { /* same body as else: keeps the li 2 in the bne slot */
        *(s16*)(obj + 0xA) = *(s16*)(src + 0xA) + 0xDA;
        *(s16*)(obj + 0xE) = *(s16*)(src + 0xE);
    } else {
        *(s16*)(obj + 0xA) = *(s16*)(src + 0xA) + 0xDA;
        *(s16*)(obj + 0xE) = *(s16*)(src + 0xE);
    }
    if (++*(s16*)(obj + 0x88) >= 0x78 || (D_800D1C00[0x2A] & 4)) {
        obj[4]++;
        D_800D1C00[0x2B] = 0;
    }
}
