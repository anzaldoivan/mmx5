#include "types.h"

extern u8 D_80091C44;
extern void func_800132F8(s8 arg);
extern s32 func_80017E54(s32);

void func_800FAA88_ovl57(u8* o) {
    if (D_80091C44 == 0) {
        if (++*(s16*)(o + 4) >= 0x3D) {
            func_800132F8(8);
            func_80017E54(3);
            o[1]++;
        }
    }
}
