#include "types.h"
#include "mmx5/globals.h"

void func_800FB59C_ovl49(Ovl45State* s) {
    D_8009A1F8.t60A0.unk60 += 0x44444;
    if (++s->unk4 >= 30) {
        func_8002385C(0x37, 0xFF, 0);
        D_8009A1F8.t60A0.unk60 = 0x4000000;
        D_8009A1F8.t60A0.unkA0 = 1;
        s->unk1++;
    }
}
