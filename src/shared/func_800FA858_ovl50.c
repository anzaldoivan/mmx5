#include "types.h"
#include "mmx5/globals.h"

void func_800FA858_ovl50(Ovl45State* arg0) {
    D_8009A1F8.u[0x4C] = 1;
    *(s32*)(D_8009A1F8.u + 0xC) += 0xC0000;
    arg0->unk4++;
    if (arg0->unk4 >= 10) {
        *(s32*)(D_8009A1F8.u + 0xC) = 0xF80000;
        func_8002385C(0x2A, 0xFF, 0);
        arg0->unk1++;
    }
}
