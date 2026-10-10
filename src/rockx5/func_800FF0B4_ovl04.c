/* T4 probe: u8 flag test, short-circuit and branchy tail (rockx5 ovl04). */
#include "types.h"

extern u8 D_800D1C2A;
extern s32 D_8009A420;

void func_800FF0B4_ovl04(u8* o) {
    if (D_800D1C2A & 1) {
        o[3] = 0;
    } else if (D_8009A420 & 1) {
        o[3] = 1;
    } else {
        o[3] = 0;
    }
}
