#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern void func_800171E8(u8* obj, s32 state);
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern s8 D_800D1C26;
extern u8 D_801010CC_ovl07;
extern u8 D_801010D4_ovl07;

void func_800F30AC_ovl07(u8* o) {
    u32* t;
    s32 a;
    s32 b;
    QByte v; // !FAKE: one-byte struct keeps the QImode zero test (C0279)

    o[0] = 0x41;
    o[4]++;
    o[0x14] = D_8009A0B4;
    *(s16*)(o + 0x40) = D_80098118[func_8002B5B4(0x8C)] >> 7;
    a = func_8002B5B4(0x8C);
    t = D_1F800020.u32s;
    *(s32*)(o + 0x3C) = (s32)t + t[a];
    a = func_8002B5B4(0x8C);
    b = func_8002B5B4(0x8C);
    *(s16*)(o + 0x42) = ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
    o[0x15] = 0;
    o[0x5C] = 0;
    o[0x61] = 0;
    o[0x60] = 0;
    o[0x16] = 6;
    *(u8**)(o + 0x68) = &D_801010D4_ovl07;
    *(u8**)(o + 0x30) = &D_801010CC_ovl07;
    v.b = o[2];
    o[0x47] = v.b;
    if ((s8)v.b == 0) {
        D_800D1C26 = 0;
    }
    func_800171E8(o, 0);
}
