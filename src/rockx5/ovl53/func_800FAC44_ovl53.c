#include "types.h"

extern void func_800132F8(s8 arg);
extern s32 func_80017E54(s32);

void func_800FAC44_ovl53(u8* arg0) {
    if (++*(s16*)(arg0 + 4) >= 0x3D) {
        func_800132F8(8);
        func_80017E54(3);
        arg0[1]++;
    }
}
