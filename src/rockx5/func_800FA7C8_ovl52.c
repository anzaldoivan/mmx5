#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern X4_BackgroundObj D_8009A24C[3];

void func_800FA7C8_ovl52(Ovl45State* arg0) {
    if (arg0->unk4 == 0) {
        D_8009A24C[0].unk3 = 1;
        func_8002385C(0x46, 0xFF, 0);
        arg0->unk1++;
    }
}
