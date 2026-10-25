#include "types.h"
extern s8 D_8009A424;
extern void func_800132F8(s8 arg);
extern void func_8001E668(void);

void func_800F0AD0_ovl24(u8* arg0) {
    s8 state = ((s8*)arg0)[2];

    if (state == 0) {
        func_800132F8(8);
        arg0[2]++;
    } else if (state == 1) {
        if (D_8009A424 == 0) {
            func_8001E668();
            arg0[2]++;
        }
    } else if (state == 2) {
        arg0[1] = 8;
        arg0[2] = 0;
    }
}
