#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80074C78[];

void func_80040738(u8* a0) {
    func_8003B33C(a0, D_80074C78[((s8*)a0)[0x96]]);
}
