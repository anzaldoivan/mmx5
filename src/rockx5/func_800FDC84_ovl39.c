#include "types.h"

extern void func_8002DF54(u8* a0);
extern u8 D_800FEB3C_ovl39[][4];

void func_800FDC84_ovl39(u8* a0) {
    s8 t;

    func_8002DF54(a0);
    t = *(s8*)(a0 + 2);
    if ((t == 0 && *(s16*)(a0 + 0xA) < 0x1291) ||
        (t == 1 && *(s16*)(a0 + 0xA) >= 0x1190)) {
        if (*(s8*)(*(u8**)(a0 + 0x7C) + 7) != 0x11) {
            *(s8*)(a0 + 5) = 7;
        } else {
            a0[0x88]++;
            *(s8*)(a0 + 5) = D_800FEB3C_ovl39[a0[0x87]][a0[0x88]];
        }
        a0[6] = 0;
        if (*(s8*)(a0 + 5) == 2) {
            *(s16*)(a0 + 0x82) = 180;
        }
    }
}
