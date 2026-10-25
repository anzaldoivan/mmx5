#include "types.h"
#include "addr.h"

extern u16 D_80091D58;
extern u8 D_800D1DBC;
extern u8 D_800D1DBD;

u8 func_80028FF0(s32 idx, u32 tx, u32 ty) {
    if (tx >= D_800D1DBC || ty >= D_800D1DBD) {
        return 0;
    }
    return *(D_1F800004 + idx * D_80091D58 + D_800D1DBC * ty + tx);
}
