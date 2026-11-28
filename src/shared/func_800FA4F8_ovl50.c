#include "types.h"
#include "mmx5/globals.h"

void func_800FA4F8_ovl50(Ovl45State* s) {
    D_8009A1F8.t60.unk60 += 0x44444;
    if (++s->unk4 >= 30) {
        func_8002385C(0x26, 0xFF, 0);
        D_8009A1F8.t60.unk60 = 0x1000000;
        s->unk4 = 0;
        s->unk1++;
    }
}
