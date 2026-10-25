#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern u8 D_80091C44;
extern u8* D_800FB960_ovl52;
extern u8 D_8009A1F8[];
extern s32 D_800FB964_ovl52;

void func_800FABB4_ovl52(u8* arg0) {
    if (D_80091C44 == 0) {
        D_800FB960_ovl52[0x36] = 0x21;
        D_8009A1F8[3] = 0;
        D_8009A1F8[0x4C] = 1;
        D_8009A1F8[0x57] = 1;
        *(s16*)(D_8009A1F8 + 0x5E) = 0x200;
        *(s16*)(D_8009A1F8 + 0x62) = 0x200;
        D_8009A1F8[0xA0] = 1;
        D_8009A1F8[0xAB] = 1;
        *(s16*)(D_8009A1F8 + 0xB2) = 0;
        *(s16*)(D_8009A1F8 + 0xB6) = 0x200;
        D_8009A1F8[0xF4] = 1;
        *(s16*)(arg0 + 4) = 0;
        D_800FB964_ovl52 = 0;
        func_80016490(2, 0x53, 0);
        arg0[1]++;
    }
}
