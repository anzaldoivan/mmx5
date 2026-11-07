#include "types.h"

extern s32 func_8002DF78(void);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D89C(u8*);
extern s32 D_8007B4A8[];
extern s32 D_8007B4C8[];
extern u8 D_8009A0B4;

void func_8004D818(u8* obj) {
    u8* p;

    obj[3] = 1;
    if (*(s8*)(obj + 2) == 0) {
        p = *(u8**)(obj + 0x54);
        *(s32*)(obj + 0x3C) = *(s32*)(p + 0x3C);
        *(s32*)(obj + 0x30) = *(s32*)(p + 0x30);
        *(u16*)(obj + 0x40) = *(u16*)(p + 0x40);
        *(u16*)(obj + 0x42) = *(u16*)(p + 0x42) & 0x7FFF;
    }
    obj[0x16] = 1;
    obj[0x14] = D_8009A0B4;
    *(s32*)(obj + 0x2C) = 0x5000;
    *(s32*)(obj + 0x20) = D_8007B4A8[func_8002DF78() & 7] +
                          *(s32*)(*(u8**)(obj + 0x54) + 0x20) / 2;
    *(s32*)(obj + 0x24) = D_8007B4C8[func_8002DF78() & 7];
    func_800171E8(obj, obj[0x58]);
    obj[4]++;
    func_8002D89C(obj);
}
