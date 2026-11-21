#include "types.h"

extern void func_800132F8(s8 arg);
extern s32 func_80017E54(s32);
extern u8 D_80091C44;

void func_800FA2C0_ovl43(u8* arg0) {
    if (D_80091C44 == 0) {
        func_800132F8(8);
        func_80017E54(3);
        arg0[1]++;
    }
}
