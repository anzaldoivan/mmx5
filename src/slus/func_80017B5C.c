#include "types.h"

extern u8 D_800E805C;
void func_80017E98(u8 vol);

void func_80017B5C(u8 vol) {
    D_800E805C = vol;
    func_80017E98(vol);
}
