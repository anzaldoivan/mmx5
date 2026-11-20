#include "types.h"
#include "mmx5/globals.h"

void func_800F7AB4_ovl09(u8* p) {
    if (((s8*)p)[0x54] != 0) {
        p[4]++;
    }
    if (((s8*)p)[2] == 0) {
        if ((p[3] ^= 1) != 0) {
            func_8002D89C(p);
        }
    } else {
        animate_object(p);
        func_8002D89C(p);
    }
}
