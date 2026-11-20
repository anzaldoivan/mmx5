#include "types.h"
#include "mmx5/globals.h"

void func_800EF0E4_ovl10(void* arg0, u8* arg1);
void func_800EF1D4_ovl10(void* arg0, u8* arg1);

void func_800EF0A0_ovl10(signed char* arg0) {
    u8* p = g_Player;

    if (arg0[4] == 0) {
        func_800EF0E4_ovl10(arg0, p);
    } else {
        func_800EF1D4_ovl10(arg0, p);
    }
}
