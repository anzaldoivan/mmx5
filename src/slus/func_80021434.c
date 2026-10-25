#include "types.h"

extern u8 D_8009A420[];
extern u16 D_800D1C7E;
extern u8 D_800D1C27;

void func_80021434(u8* arg0) {
    u8* p = D_8009A420;
    s32 v;

    if (((signed char*)p)[4] == 0) {
        v = p[7];
        if (v != 1) {
            if (v < 2) {
                if (v == 0) {
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
            }
        } else {
            D_800D1C27 = 1;
            arg0[0] = 0xB;
            arg0[1] = 0;
            arg0[2] = 0;
            arg0[3] = 0;
            return;
        }
        arg0[1] = 5;
    }
}
