#include "types.h"
#include "addr.h"

extern void func_8002D720(u8* arg0);
extern u8** D_8007D694[];
extern u8* D_8007D5DC[];
extern u8 D_800C9310;
extern s8 D_800D1C00[];

void func_80056458(u8* obj) {
    s32* src;
    s32* dst;
    u32 n;
    u8* rec;
    u8* tbl;
    u8 i;

    i = obj[2];
    obj[0] = 1;
    *(u8**)(obj + 0x1C) = D_8007D694[D_800D1C00[0xC] * 2 + D_800D1C00[0xD]][i];
    if (*(u8**)(obj + 0x1C) == 0) {
        func_8002D720(obj);
        return;
    }
    tbl = D_8007D5DC[D_800D1C00[0xC] * 2 + D_800D1C00[0xD]];
    while (--i != 0xFF) {
        tbl += 2;
    }
    *(u8**)(obj + 0x18) = D_1F800028 + (tbl[0] << 5);
    rec = *(u8**)(obj + 0x1C);
    *(u8**)(obj + 0x14) = D_1F800030 + (rec[0] << 5);
    n = 0;
    obj[0x21] = rec[1];
    obj[0x20] = tbl[1];
    dst = *(s32**)(obj + 0x18);
    src = *(s32**)(obj + 0x14);
    for (; n < ((s8*)obj)[0x20] * 8; n++) {
        *dst++ = *src++;
    }
    D_800C9310 |= 1;
    obj[4]++;
}
