#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern int func_8002D7A0();

void func_800F6538_ovl01(u8* a0) {
    s8 state = ((s8*)a0)[5];

    if (state == 0) {
        if (is_off_screen(a0, 0x30, 0x30) == 0) {
            func_8002D9EC(a0, 0x20, 0x20);
        } else {
            a0[5]++;
        }
    } else if (state == 1) {
        func_8002D7A0(a0);
    }
}
