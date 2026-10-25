#include "types.h"

extern void func_80055F60(u8* obj);
extern s32 D_8007D3E8[];
extern s8 D_800D1C00[];

void func_800560D8(u8* obj) {
    s32* tbl = D_8007D3E8;
    s8* g = D_800D1C00;

    obj[0x14] = 0;
    obj[4]++;
    *(s32*)(obj + 0x18) = tbl[g[0xC] * 2 + g[0xD]] + (obj[2] & 0x7F) * 16;
    func_80055F60(obj);
}
