#include "types.h"

extern s32 func_80017E54(s32);
extern void func_800177B0(s32, s32);
extern u8 D_800D1F3C;

void func_8005589C(u8* obj) {
    if (((s8*)obj)[6] == 0) {
        if (((s8*)obj)[0x45] != 0) {
            func_80017E54(3);
            obj[0x45] = 0;
            obj[6]++;
        }
    } else if (D_800D1F3C == 0) {
        func_800177B0(0x13, 0x7F);
        obj[6] = 0;
        obj[5]++;
    }
}
