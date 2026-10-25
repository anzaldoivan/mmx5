#include "types.h"

extern void func_800132F8(s8 arg);
extern s32 func_80017E54(s32);
extern u8 D_80091C44;
extern s32 D_8009A420;
extern u16 D_80093E68;
extern u16 D_800D50DE;
extern u16 D_8009A42E;

void func_800FB7E8_ovl56(u8* arg0) {
    if (D_80091C44 == 0) {
        if (!(D_8009A420 & 1)) {
            D_80093E68 += 0x400;
            D_800D50DE++;
            D_8009A42E += 0x20;
        }
        if (D_80093E68 >= 0x7C00) {
            func_800132F8(8);
            func_80017E54(3);
            arg0[1]++;
        }
    }
}
