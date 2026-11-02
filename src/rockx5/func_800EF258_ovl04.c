#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_80028A20(s32, s32, s32, u8*);
extern u8* func_8002D144(void);
extern void func_8003D2C4(void);
extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];
extern u8 D_80100DBC_ovl04[];
extern s16 D_80102FD4_ovl04;
extern u8* D_80102FD8_ovl04;

void func_800EF258_ovl04(u8* obj) {
    u8* p;
    u8* g = D_8009A1F8;
    u8* q;
    s32 t;

    t = *(u16*)(g + 0x62) - 1;
    *(s16*)(g + 0x62) = t;
    D_80102FD4_ovl04++;
    if ((t << 16) <= 0) {
        func_80016490(5, 0x14, 0);
        func_8003D2C4();
        p = func_8002D144();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0xE;
            p[2] = 0xD;
            q = D_8009A0A0;
            *(s32*)(p + 8) = *(s32*)(q + 8);
            *(s32*)(p + 0xC) = *(s32*)(q + 0xC);
            D_80102FD8_ovl04 = p;
        }
        obj[6]++;
    }
    if (++obj[0x1C] >= 0x18) {
        obj[0x1C] = 0;
    }
    if (obj[0x1C] % 6 == 0) {
        func_80028A20(1, 0x370, 0xF0,
                      D_80100DBC_ovl04 + (u8)(obj[0x1C] / 6) * 8);
    }
}
