#include "types.h"

extern u8 D_800D1F3C;
extern u8 D_8009A1F8[];
extern u8 D_800FB760_ovl52[];
extern u8 D_800FB560_ovl52[];
extern u8* D_800FB960_ovl52;
extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 func_8002C338(s32, void*, s32);
extern u8* func_8002D53C(void);

void func_800FA1EC_ovl52(u8* obj) {
    u8* g;
    u8* s;

    if (D_800D1F3C == 2) {
        g = D_8009A1F8;
        g[0x57] = 1;
        *(s16*)(g + 0x5E) = 0x200;
        *(s16*)(g + 0x62) = 0x80;
        g[0xA0] = 1;
        g[0xAB] = 1;
        *(s16*)(g + 0xB2) = 0;
        *(s16*)(g + 0xB6) = 0x200;
        g[0xF4] = 1;
        *(s16*)(obj + 4) = 0;
        func_8002C3CC(D_800FB760_ovl52, D_800FB560_ovl52, 0x100, 0x78, 0x78);
        func_8002C338(0x70, D_800FB760_ovl52, 0x10);
        s = func_8002D53C();
        if (s != 0) {
            s[0] = 1;
            s[1] = 0xA;
            s[0x36] = 0x11;
            s[2] = 0;
            D_800FB960_ovl52 = s;
        }
        obj[1]++;
    }
}
