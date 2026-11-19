#include "types.h"
#include "mmx5/globals.h"

extern u8 D_800E805C;
void func_80017E98(u8 vol);

void func_80017B5C(s32 arg0) {
    u8 vol = arg0;

    D_800E805C = vol;
    func_80017E98(vol);
}
