#include "types.h"
#include "addr.h"

extern s32 func_8002C338(s32, void*, s32);

void func_8004E2BC(s32 arg0, s32 arg1) {
    func_8002C338(1, D_1F800024 + ((arg1 + 0x39) << 5), 1);
}
