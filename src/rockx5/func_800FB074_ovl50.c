#include "types.h"

extern s32 func_8002DF78(void);
extern void func_80016490(s32, s32, void*);
extern u8 D_80091C44;
extern s32 D_80093DE8;
extern u8 D_80093E66;
extern u16 D_80093E68;
extern u8 D_8009A1F8[];
extern u8 D_8009A42C;
extern u16 D_8009A42E;
extern u8 D_800D50DC;
extern u16 D_800D50DE;

void func_800FB074_ovl50(u8* arg0) {
    if (*(u16*)(arg0 + 4) & 1) {
        u8* p1 = D_8009A1F8;
        *(s16*)(p1 + 0xB6) = func_8002DF78() % 5 + 0x404;
    } else {
        u8* p2 = D_8009A1F8;
        *(s16*)(p2 + 0xB6) = 0x400;
    }
    *(u16*)(arg0 + 4) += 1;
    if (D_80091C44 == 0) {
        u8* p = D_8009A1F8;
        *(s16*)(p + 0xB6) = 0x400;
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        D_80093E68 = 0;
        D_8009A42E = 0;
        D_800D50DE = 0;
        D_80093DE8 = 0xFFFF;
        *(u16*)(arg0 + 4) = 0;
        arg0[1]++;
        func_80016490(2, 0x56, 0);
    }
}
