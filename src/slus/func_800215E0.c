#include "types.h"

extern u8 D_8009A420[];
extern u16 D_800D1C7E;

void func_800215E0(u8* arg0) {
    u8* p = D_8009A420;

    if (((signed char*)p)[4] == 0) {
        if (p[7] == 0) {
            arg0[0x1E] = 0;
            if (D_800D1C7E & 0x8000) {
                arg0[0x45] = 4;
            } else {
                arg0[0x45] = 2;
            }
            arg0[0] = 9;
            arg0[1] = 0;
            arg0[2] = 0;
            arg0[3] = 0;
            return;
        }
        arg0[1] = 5;
    }
}
