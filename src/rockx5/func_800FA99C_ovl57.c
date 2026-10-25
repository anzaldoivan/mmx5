#include "types.h"

extern u8 D_80091C44;
extern u8 D_8009A1F8[];
extern u8 D_800FAB94_ovl57[];
extern void func_80028B18(s32, s32, s32, void*);
extern void func_8002385C(s32, s32, s32);

void func_800FA99C_ovl57(u8* arg0) {
    if (D_80091C44 == 0) {
        func_80028B18(1, 0x10, 0x140, D_800FAB94_ovl57);
        D_8009A1F8[0xA0] = 1;
        *(s16*)(D_8009A1F8 + 0xB2) = 0;
        *(s16*)(D_8009A1F8 + 0xB6) = 0x200;
        D_8009A1F8[0xF4] = 1;
        func_8002385C(0x72, 0xFF, 0);
        arg0[1]++;
    }
}
