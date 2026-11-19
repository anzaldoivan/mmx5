#include "types.h"
#include "mmx5/system.h"

extern s32 func_80017E54(s32);
extern s16 D_8009A2AE;

void func_800FAD8C_ovl49(Unk800FAD8C* arg0) {
    if (++arg0->unk6 & 1) {
        D_8009A2AE = (random_byte() % 5) + 0x104;
    } else {
        D_8009A2AE = 0x100;
    }
    if (arg0->unk4 < 0x1E) {
        arg0->unk4++;
    } else {
        func_80017E54(3);
        arg0->unk1++;
    }
}
