#include "types.h"

extern void func_8002DED4(u8* obj);
extern s32 func_8002FB58(u8* obj);
extern u8 D_800FB74C_ovl10[];
extern u8 D_800FB750_ovl10[];
extern s32 D_8009A0A8;

void func_800F2BA0_ovl10(u8* o) {
    func_8002DED4(o);
    func_8002FB58(o);
    if (o[0x70] & 8) {
        *(u8**)(o + 0x50) = D_800FB74C_ovl10;
        *(u8**)(o + 0x54) = D_800FB750_ovl10;
        *(s32*)(o + 0x24) = 0;
        *(s32*)(o + 0x2C) = 0;
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x28) = 0;
        o[0x67] = 0;
        if (D_8009A0A8 <= *(s32*)(o + 8)) {
            o[0x90] = 0;
            o[0x15] = 0;
            o[5] = 4;
        } else {
            o[0x90] = 1;
            o[0x15] = 0x40;
            o[5] = 5;
        }
        o[6] = 0;
    }
}
