#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_8002D89C(u8* obj);
extern void (*D_800F9DDC_ovl03[])(u8*);
extern s8 D_800FA238_ovl03;
extern s16 D_8009A0AA;
extern u8 D_8009A1F8[];

void func_800F2BD4_ovl03(u8* obj) {
    u8* p;

    D_800F9DDC_ovl03[(s8)obj[5]](obj);
    if (D_800FA238_ovl03 != 0) {
        if (obj[0x47] == 14) {
            func_80017248(obj);
        }
    } else {
        func_80017248(obj);
    }
    func_8002D89C(obj);
    if (((s8*)obj)[2] != 0) {
        return;
    }
    if (D_8009A0AA < 0x1081) {
        return;
    }
    p = D_8009A1F8;
    if ((s8)p[0xAC] != 2) {
        p[0xAC] = 2;
        p[0xF4] = 1;
        p[0x57] = 0;
    }
}
