#include "types.h"

extern X4_BackgroundObj D_8009A1F8[3];
void func_80028328(s32 arg0, s32 x, s32 y);
void func_80028608(s32 arg0, s32 x, s32 y);

void func_80028278(void) {
    X4_BackgroundObj* p;
    s32 x;
    s32 y;
    u32 i;

    i = 0;
    p = D_8009A1F8;
    for (; i < 3; i++, p++) {
        if (((s8*)p)[0x52] < 0) {
            x = p->x_pos.i.hi;
            y = p->y_pos.i.hi;
            func_80028328(i, x - 0x10, y - 0x10);
            func_80028328(i, x + 0x150, y - 0x10);
            func_80028608(i, x, y - 0x10);
            func_80028608(i, x, y + 0x100);
        }
    }
}
