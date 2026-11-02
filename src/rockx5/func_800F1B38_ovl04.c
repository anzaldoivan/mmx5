#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002B5B4(s32);
extern s32 func_8002DF78(void);
extern u8 D_800750C0[];
extern u32* D_80098118;
extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];
extern u8 D_80101568_ovl04[];
extern u8 D_8010156C_ovl04[];
extern u8 D_80101570_ovl04[];
extern u8 D_80101610_ovl04[];

void func_800F1B38_ovl04(u8* obj) {
    s32 a;
    s32 b;
    s32 d;
    u8* p;
    u8* q;

    obj[0x5C] = 0xF;
    obj[0x60] = 4;
    *(u8**)(obj + 0x58) = D_800750C0;
    obj[0x61] = 0;
    obj[0x14] = D_8009A0A0[0x14];
    *(u8**)(obj + 0x30) = D_80101610_ovl04;
    obj[0x16] = 2;
    *(u8**)(obj + 0x68) = D_80101570_ovl04;
    *(u8**)(obj + 0x54) = D_8010156C_ovl04;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x67] = 0;
    *(u8**)(obj + 0x50) = D_80101568_ovl04;
    obj[0x62] = 0;
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    func_800171E8(obj, 1);
    *(s16*)(D_1F80004C.bytes + 0x80) = 0;
    D_1F80004C.bytes[0x84] = 0;
    *(s16*)(D_1F80004C.bytes + 0x82) = 0x20;
    if (((s8*)obj)[2] >= 2) {
        *(s32*)(obj + 0x10) = 0;
        *(s16*)(obj + 0x40) = D_80098118[func_8002B5B4(((s8*)obj)[1])] >> 7;
        a = func_8002B5B4(((s8*)obj)[1]);
        b = func_8002B5B4(((s8*)obj)[1]);
        *(s16*)(obj + 0x42) =
            ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
        *(s32*)(obj + 0x3C) = (s32)D_1F800020.u32s +
                              D_1F800020.u32s[func_8002B5B4(((s8*)obj)[1])];
        p = D_8009A1F8;
        if (*(s16*)(D_8009A0A0 + 0xA) - *(s16*)(p + 0xA) >= 0xA1) {
            d = (func_8002DF78() & 0xF) + 0x38;
            *(s16*)(obj + 0xA) = *(u16*)(p + 0xA) - d;
        } else {
            d = (func_8002DF78() & 0xF) + 0x178;
            *(s16*)(obj + 0xA) = *(u16*)(p + 0xA) + d;
        }
        if (((s8*)obj)[2] == 2) {
            u8* q2 = D_8009A1F8;
            *(s16*)(obj + 0xE) = *(u16*)(q2 + 0xE) + 0x14;
        } else if (((s8*)obj)[2] == 3) {
            q = D_8009A1F8;
            *(s16*)(obj + 0xE) = *(u16*)(q + 0xE) + 0xDC;
        }
    }
    obj[4] = 1;
    obj[5] = 2;
    obj[6] = 0;
}
