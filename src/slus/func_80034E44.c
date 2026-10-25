#include "types.h"

extern s8 D_8009A424;
void func_800272DC(void);
void func_800183E8(void);

void func_80034E44(u8* arg0) {
    if (D_8009A424 != 0) {
        func_800272DC();
    } else {
        func_800183E8();
        arg0[5] = 2;
    }
}
