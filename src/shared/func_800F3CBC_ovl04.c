/* Shared body (DK-5), from the banked draft of func_800F3CBC_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8003D29C(s32, s32);
extern u8 D_80075CA0[];
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern u8 D_8009A1F8[];
extern s8 D_800D1C00[];
extern u8 D_801017E8_ovl04[];
extern u8 D_801017EC_ovl04[];
extern u16 D_801017F8_ovl04[][20];
extern u8 D_80101B38_ovl04[];
extern u16 D_80102FEC_ovl04[][20];

void DEDUP_NAME(u8* obj) {
    u8* p;
    s32 off;
    s32 add;
    s32 i;
    s32 j;

    func_8003D29C(0x14, 0x40);
    *(u8**)(obj + 0x54) = D_801017EC_ovl04;
    *(u8**)(obj + 0x50) = D_801017E8_ovl04;
    obj[5]++;
    *(s32*)(obj + 0x68) = 0;
    *(u8**)(obj + 0x58) = D_80075CA0;
    obj[0x14] = D_8009A0B4;
    if (D_800D1C00[0xC] != 0xC) {
        *(s16*)(obj + 0x40) = (*D_80098118 >> 7) + 0x210;
    } else {
        *(s16*)(obj + 0x40) = (*D_80098118 >> 7) + 0x210;
        p = D_1F80009C;
        off = *(s32*)p;
        *(s16*)(obj + 0x42) = 0x7CCC;
        *(u8**)(obj + 0x3C) = p + off;
    }
    *(u8**)(obj + 0x30) = D_80101B38_ovl04;
    obj[0x16] = 4;
    obj[0x15] = 0;
    obj[0x5C] = 0;
    obj[0x60] = 5;
    add = 0;
    if (D_800D1C00[0xC] != 0xC) {
        *(s16*)(obj + 0xA) = 0x1700;
        *(s16*)(obj + 0xE) = 0xB0;
    } else {
        add = 0x10;
        *(s16*)(obj + 0xA) = 0x5F0;
        *(s16*)(obj + 0xE) = 0xC0;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 20; j++) {
            D_80102FEC_ovl04[i][j] = D_801017F8_ovl04[i][j] + add;
        }
    }
    obj[0x63] = 2;
    obj[0x62] = 0;
    *(s32*)(obj + 0x80) = 0;
    *(s32*)(obj + 0x84) = 0;
    obj[0x8F] = 0;
    *(s32*)(obj + 0x98) = 0;
    obj[0x92] = 0;
    *(s16*)(obj + 0x7E) = 0;
    obj[7] = 0;
    D_8009A1F8[0x48] = 1;
    func_800171E8(obj, 3);
}
