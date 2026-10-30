#include "types.h"
#include "addr.h"

extern s32 func_8002DF78(void);
extern void func_800FCA20_ovl07(u8* obj, s16 x, s16 y, u8 c);
extern u8 D_80101B9C_ovl07[][2];
extern u8 D_80101BBC_ovl07[][2];
extern u8 D_80101BDC_ovl07[][2];
extern s16 D_80101B78_ovl07[][2];
extern s16 D_80102014_ovl07;
extern s16 D_80102016_ovl07;

void func_800FAEC4_ovl07(u8* a0) {
    s32 r;
    s32 i;
    u32 n;
    u8 c;
    u8 u; // never set: the target stores an unset s2 to 0x94

    if (*(s8*)(a0 + 0x45) != 0) {
        D_1F80004C.bytes[0x8E] = 0;
        r = func_8002DF78();
        n = D_1F80004C.bytes[0x8A];
        if ((s32)(n * 2) / 3 < *(s8*)(a0 + 0x5C)) {
            i = r & 0xF;
            c = D_80101B9C_ovl07[i][0];
        } else if ((u8)(n / 3) < *(s8*)(a0 + 0x5C)) {
            i = func_8002DF78() & 0xF;
            c = D_80101BBC_ovl07[i][0];
        } else {
            i = func_8002DF78() & 0xF;
            c = D_80101BDC_ovl07[i][0];
        }
        D_1F80004C.bytes[0x93] = c;
        D_1F80004C.bytes[0x94] = u;
        func_800FCA20_ovl07(a0, D_80101B78_ovl07[c & 0xF][0] + D_80102014_ovl07,
                            D_80101B78_ovl07[c & 0xF][1] + D_80102016_ovl07, c);
        *(s16*)(a0 + 0x7C) = 2;
        a0[6]++;
    }
}
