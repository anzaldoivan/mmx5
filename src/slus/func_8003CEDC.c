#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

static inline void load_buffered_palette(s32 idx, s32 id, s32 n) {
    func_8002C338(id, D_1F800024 + idx * 32, n);
}

void func_8003CEDC(u8* a0, s32 a1) {
    if (((s8*)a0)[2] == 0) {
        if (((s8*)a0)[0xF0] == 0) {
            load_buffered_palette(a1, 0, 1);
            load_buffered_palette(a1 + 1, 0x13, 1);
        }
    } else {
        load_buffered_palette(a1, 0, 1);
    }
}
