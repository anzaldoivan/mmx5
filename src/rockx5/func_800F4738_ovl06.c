#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_80016490(s32, s32, void*);
extern s32 D_8009A420;
extern u8 D_80075660[];
extern u8 D_800FE4D8_ovl06[];

void func_800F4738_ovl06(u8* obj) {
    s32 t;
    s32 n;

    if (*(s8*)(obj + 0x45) == 7) {
        func_800171E8(obj, 0);
    }
    if (*(s16*)(obj + 0xA) < 0xBA0) {
        *(u16*)(obj + 0xA) += 3;
        return;
    }
    t = *(u16*)(obj + 0x7E) - 1;
    *(u16*)(obj + 0x7E) = t;
    if ((t << 16) == 0) {
        func_80016490(0, 0xE, 0);
        *(s16*)(obj + 0x7E) = 3;
    }
    if (!(D_8009A420 & 1)) {
        n = obj[0x5C] + 1;
        obj[0x5C] = n;
        if ((s8)n == 0x30) {
            *(u8**)(obj + 0x58) = D_80075660;
            *(u8**)(obj + 0x68) = D_800FE4D8_ovl06;
            obj[6]++;
        }
    }
}
