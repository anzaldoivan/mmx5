#include "types.h"

extern s32 func_80017E54(s32);
extern s32 D_8009A420;
extern u16 D_800D50DE;
extern u16 D_80093E68;
extern u16 D_8009A42E;

s32 func_800FA714_ovl57(u8* arg0) {
    s32 r;

    if (!(D_8009A420 & 1)) {
        D_80093E68 -= 0x400;
        D_800D50DE--;
        D_8009A42E -= 0x20;
    }
    if (D_80093E68 == 0) {
        r = func_80017E54(3);
        arg0[1]++;
        return r;
    }
}
