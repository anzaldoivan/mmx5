#include "types.h"
#include "addr.h"

extern s16 D_800FFE64_ovl34[];
extern s16 D_80100160_ovl34;
extern s16 D_80100162_ovl34;

void func_800FBCFC_ovl34(u8* arg0) {
    s16 x;
    s16 y;
    u8* p;
    u8* q;

    D_1F80004C.bytes[0x91] = 0;
    if (arg0[0x15] == 0) {
        x = *(u16*)(arg0 + 0xA) + *(s8*)*(u8**)(arg0 + 0x68);
    } else {
        x = *(u16*)(arg0 + 0xA) - *(s8*)*(u8**)(arg0 + 0x68);
    }
    p = *(u8**)(arg0 + 0x68);
    y = *(u16*)(arg0 + 0xE) + ((s8*)p)[1];
    if (x - p[2] <= D_800FFE64_ovl34[0] + D_80100160_ovl34) {
        *(u16*)(arg0 + 0xA) =
            *(u16*)(arg0 + 0xA) +
            ((u16)D_800FFE64_ovl34[0] + (u16)D_80100160_ovl34 - (x - p[2]));
        D_1F80004C.bytes[0x91] |= 2;
    } else if (x + p[2] >= D_800FFE64_ovl34[2] + D_80100160_ovl34) {
        *(u16*)(arg0 + 0xA) =
            *(u16*)(arg0 + 0xA) -
            ((p[2] + x) - ((u16)D_800FFE64_ovl34[2] + (u16)D_80100160_ovl34));
        D_1F80004C.bytes[0x91] |= 1;
    }
    q = *(u8**)(arg0 + 0x68);
    if (y - q[3] <= D_800FFE64_ovl34[1] + D_80100162_ovl34) {
        *(u16*)(arg0 + 0xE) =
            *(u16*)(arg0 + 0xE) +
            ((u16)D_800FFE64_ovl34[1] + (u16)D_80100162_ovl34 - (y - q[3]));
        D_1F80004C.bytes[0x91] |= 4;
    } else if (y + q[3] >= D_800FFE64_ovl34[3] + D_80100162_ovl34) {
        *(u16*)(arg0 + 0xE) =
            *(u16*)(arg0 + 0xE) -
            ((q[3] + y) - ((u16)D_800FFE64_ovl34[3] + (u16)D_80100162_ovl34));
        D_1F80004C.bytes[0x91] |= 8;
    }
}
