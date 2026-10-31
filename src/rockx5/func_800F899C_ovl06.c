#include "types.h"
#include "addr.h"

extern void func_800FAEF8_ovl06(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_80016490(s32, s32, void*);
extern s16 D_8009A0AA;
extern u8 D_800FF1D4_ovl06[];
extern u8 D_800FF1D8_ovl06[];
extern u8 D_80074EE0[];

void func_800F899C_ovl06(u8* obj) {
    s32 d;

    d = *(s16*)(obj + 0xA) - D_8009A0AA;
    if ((d >= 0) ? (d > 0x80) : (D_8009A0AA - *(s16*)(obj + 0xA) > 0x80)) {
        obj[5] = 8;
        obj[6] = 0;
        return;
    }
    func_800FAEF8_ovl06(obj);
    obj[0x60] = 8;
    func_800171E8(obj, 0xF);
    *(u8**)(obj + 0x50) = D_800FF1D4_ovl06;
    *(u8**)(obj + 0x54) = D_800FF1D8_ovl06;
    obj[0x62] = 5;
    *(u8**)(obj + 0x58) = D_80074EE0;
    if (obj[0x15] == 0) {
        *(s32*)(obj + 0x20) = -0x38000;
    } else {
        *(s32*)(obj + 0x20) = 0x38000;
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(u16*)(D_1F80004C.bytes + 0x8C) = *(u16*)(obj + 0xA);
    func_80016490(2, 0x21, obj);
    *(s16*)(obj + 0x7C) = 0x10;
    obj[6]++;
}
