#include "types.h"
#include "addr.h"

extern s32 func_800F2224_ovl04(u8* arg0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_800F2B0C_ovl04(u8* arg0);
extern u8 D_8009A0A0[];
extern u8 D_80101640_ovl04[];
extern void (*D_80101698_ovl04[])(u8*);

void func_800F2978_ovl04(u8* arg0) {
    if (func_800F2224_ovl04(arg0)) {
        arg0[0x62] = 0;
        D_1F80004C.bytes[0x84] = 0;
        D_8009A0A0[0xCA] = 0;
        if (D_8009A0A0[0x5C] & 0x7F) {
            D_8009A0A0[3] = 1;
        }
        func_8004D4F4(5, D_80101640_ovl04, arg0);
        arg0[3] = 0;
        *(s16*)(arg0 + 0x7C) = 0xF;
        *(s16*)(arg0 + 0x7E) = 5;
        arg0[4] = 6;
    } else {
        D_80101698_ovl04[((s8*)arg0)[6]](arg0);
        func_800F2B0C_ovl04(arg0);
    }
}
