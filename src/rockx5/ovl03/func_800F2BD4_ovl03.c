#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800F9DDC_ovl03[])(u8*);
extern s8 D_800FA238_ovl03;
extern u8 D_8009A1F8[];

void func_800F2BD4_ovl03(u8* obj) {
    u8* p;

    D_800F9DDC_ovl03[(s8)obj[5]](obj);
    if (D_800FA238_ovl03 != 0) {
        if (obj[0x47] == 14) {
            animate_object(obj);
        }
    } else {
        animate_object(obj);
    }
    ((s32(*)())func_8002D89C)(obj);
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
