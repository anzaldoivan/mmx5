#include "types.h"
#include "mmx5/globals.h"

void func_800FA918_ovl53(Ovl45State* s) {
    D_8009A1F8.w[23] += 0x40000;
    if (++s->unk4 >= 0x38) {
        ((s16*)&D_8009A1F8.w[23])[1] = 0x2A0;
        s->unk1++;
        func_8002385C(0x52, 0xFF, 0);
    }
}
