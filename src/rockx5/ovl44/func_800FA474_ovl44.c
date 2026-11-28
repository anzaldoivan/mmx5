#include "types.h"
#include "mmx5/globals.h"

void func_800FA474_ovl44(Ovl45State* arg0) {
    D_8009A1F8.w[0x5C / 4] += 0xAAAAA;
    arg0->unk4++;
    if (arg0->unk4 >= 30) {
        ((s16*)D_8009A1F8.w)[0x5E / 2] = 0x200;
        func_8002385C(0x11, 0xFF, 0);
        arg0->unk1++;
    }
}
