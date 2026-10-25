#include "types.h"

extern u8 D_80091C44;
extern u8 D_8009A1F8[];

extern void func_80016490(s32, s32, void*);
extern void func_8002385C(s32, s32, s32);

void func_800FA608_ovl44(Ovl45State* arg0) {
    if (D_80091C44 == 0) {
        u8* p;
        func_80016490(2, 0x4B, 0);
        p = D_8009A1F8;
        p[0x3] = 0;
        p[0x57] = 0;
        *(s16*)(p + 0xB2) = 0x200;
        *(s16*)(p + 0xB6) = 0;
        p[0xAB] = 1;
        p[0xF4] = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
        func_8002385C(0x13, 0xFF, 0);
    }
}
