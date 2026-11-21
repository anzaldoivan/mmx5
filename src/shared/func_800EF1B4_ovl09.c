#include "types.h"
#include "mmx5/globals.h"

void func_800EF1B4_ovl09(signed char* arg0) {
    if (arg0[0x45] == 1) {
        *(s16*)(arg0 + 0x7C) = 0x5E;
        *(s16*)(arg0 + 0x8A) = *(s16*)(arg0 + 0xA);
        *(s16*)(arg0 + 0x8E) = *(s16*)(arg0 + 0xE);
        ((u8*)arg0)[6]++;
        if (*(s16*)(arg0 + 0xA) < D_8009A0AA) {
            arg0[0x15] = 0x40;
        } else {
            arg0[0x15] = 0;
        }
    }
}
