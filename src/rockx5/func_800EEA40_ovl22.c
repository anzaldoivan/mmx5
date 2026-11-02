#include "types.h"

extern void func_8002D89C(u8* obj);
extern s32 D_8009A420;
extern u8 D_800D1F28[];
extern u8 D_800EEBC4_ovl22;
extern u8 D_800EEBCA_ovl22;
extern u8 D_800EEBD0_ovl22;
extern u8 D_800EEBD6_ovl22;

void func_800EEA40_ovl22(u8* obj) {
    u8* p;

    if (((s8*)obj)[2] == 6) {
        p = D_800D1F28;
        obj[0x16] = 2;
        *(s16*)(obj + 0xE) = (s8)(((s8*)p)[2] % 4) * 16 + 0x86;
        switch (((s8*)p)[2]) {
        case 0:
            obj[0x47] = D_800EEBC4_ovl22;
            break;
        case 1:
            obj[0x47] = D_800EEBCA_ovl22;
            break;
        case 2:
            obj[0x47] = D_800EEBD0_ovl22;
            break;
        default:
            obj[0x47] = D_800EEBD6_ovl22;
            break;
        }
    }
    if ((u8)(obj[2] - 4) < 2) {
        obj[3] = 0;
        if (D_8009A420 & 0x10) {
            func_8002D89C(obj);
        }
    } else {
        obj[3] = 1;
        func_8002D89C(obj);
    }
}
