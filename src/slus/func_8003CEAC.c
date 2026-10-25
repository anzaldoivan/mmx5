#include "types.h"
#include "addr.h"

extern s32 func_8002C338(s32, void*, s32);

void func_8003CEAC(s32 idx, s32 id, s32 n) {
    func_8002C338(id, D_1F800024 + idx * 32, n);
}
