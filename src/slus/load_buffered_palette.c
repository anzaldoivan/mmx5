#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

void load_buffered_palette(s32 idx, s32 id, s32 n) {
    func_8002C338(id, D_1F800024 + idx * 32, n);
}
