#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/ovl54.h"

extern u16 D_800D50DE;
extern u16 D_80093E68;
extern u16 D_8009A42E;

void func_800FAA34_ovl54(u8* arg0) {
    u16 t;

    *(u16*)(arg0 + 6) += 1;
    t = *(u16*)(arg0 + 6);
    if (!(t & 3)) {
        if (D_800D50DE != 0x1F) {
            D_800D50DE++;
            D_8009A42E += 0x20;
            D_80093E68 += 0x400;
        }
    }
    if (D_800D50DE == 0x1F) {
        *(u16*)(arg0 + 4) = 0;
        arg0[1]++;
        func_8002385C(0x7A, 0xFF, 0);
    }
}

void func_800FAAD0_ovl54(Ovl45State* arg0) {
    if (arg0->unk4 == 0) {
        func_8002385C(0x58, 0xFF, 0);
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

#include "shared/func_800FAB1C_ovl54.c"

extern void func_800132F8(s8 arg);
extern s32 func_80017E54(s32);

void func_800FAC04_ovl54(u8* arg0) {
    if (++*(s16*)(arg0 + 4) > 60) {
        func_800132F8(8);
        arg0[1]++;
        func_80017E54(3);
    }
}

#include "shared/func_800FAC64_ovl54.c"
