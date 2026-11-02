#include "types.h"

extern X4_BackgroundObj D_8009A1F8[3];
void func_80028CE4(s32 idx, s32 x, s32 y);

void func_800288B4(s32 arg0) {
    u32 i;
    u32 j;
    u32 k;
    s32 x;
    s32 y;

    for (i = 0; i < 3; i++) {
        y = D_8009A1F8[i].y_pos.i.hi / 16 + arg0;
        for (j = 0; j < 32; y++, j++) {
            if (y >= 0) {
                x = D_8009A1F8[i].x_pos.i.hi / 16 + arg0;
                for (k = 0; k < 32; k++, x++) {
                    if (x >= 0) {
                        func_80028CE4(i, x, y);
                    }
                }
            }
        }
    }
}
