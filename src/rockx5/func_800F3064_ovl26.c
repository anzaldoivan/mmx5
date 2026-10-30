#include "types.h"
#include "addr.h"

extern s32 func_8002DF78(void);
extern signed char D_800D1CA2;

void func_800F3064_ovl26(u8* obj) {
    u32 r;

    r = func_8002DF78() & 0xF;
    if (D_800D1CA2 / 2 < ((s8*)obj)[0x5C]) {
        if (r < 7) {
            D_1F80004C.bytes[0x90] = 0;
        } else if (r < 12) {
            D_1F80004C.bytes[0x90] = 1;
        } else if (r < 14) {
            D_1F80004C.bytes[0x90] = 2;
        } else {
            D_1F80004C.bytes[0x90] = 3;
        }
    } else {
        if (r < 8) {
            D_1F80004C.bytes[0x90] = 4;
        } else if (r < 11) {
            D_1F80004C.bytes[0x90] = 5;
        } else if (r < 14) {
            D_1F80004C.bytes[0x90] = 6;
        } else {
            D_1F80004C.bytes[0x90] = 7;
        }
    }
    D_1F80004C.bytes[0x91] = 0;
    obj[5] = 3;
    obj[6] = 0;
}
