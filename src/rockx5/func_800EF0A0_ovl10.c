#include "types.h"

extern u8 D_8009A0A0[];

void func_800EF0E4_ovl10(void* arg0, u8* arg1);
void func_800EF1D4_ovl10(void* arg0, u8* arg1);

void func_800EF0A0_ovl10(signed char* arg0) {
    u8* p = D_8009A0A0;

    if (arg0[4] == 0) {
        func_800EF0E4_ovl10(arg0, p);
    } else {
        func_800EF1D4_ovl10(arg0, p);
    }
}
