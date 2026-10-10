#include "types.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Ovl50Pos;

extern u8 D_80091C44;
extern Ovl50Pos D_800FB3C8_ovl50;
extern u8 D_800FB3E0_ovl50[];
extern u8 D_8009A298;

void func_80028B18(s32, s32, s32, void*);
void func_8002385C(s32, s32, s32);

void func_800FAE80_ovl50(Actor50* arg0) {
    if (D_80091C44 == 0) {
        func_80028B18(1, D_800FB3C8_ovl50.unk4, D_800FB3C8_ovl50.unk6,
                      D_800FB3E0_ovl50);
        D_8009A298 = 1;
        func_8002385C(0x3D, 0xFF, 0);
        arg0->step++;
    }
}
