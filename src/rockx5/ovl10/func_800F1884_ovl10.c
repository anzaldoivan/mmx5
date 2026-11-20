#include "types.h"
#include "mmx5/graphics.h"

extern u8 D_80075340[];

void func_800F1884_ovl10(Obj1884* arg0) {
    set_animation(arg0, 1);
    arg0->unk58 = D_80075340;
    arg0->unk6++;
}
