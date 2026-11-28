#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

void func_8004E2BC(s32 arg0, s32 arg1) {
    load_palette(1, D_1F800024 + ((arg1 + 0x39) << 5), 1);
}
