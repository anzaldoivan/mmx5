#include "types.h"
#include "mmx5/globals.h"
extern s8 D_8009A16C;
extern void (*D_800718E0[])(X4_BackgroundObj*);
void update_screen_shake_x(X4_BackgroundObj* arg0);
void update_screen_shake_y(X4_BackgroundObj* arg0);

void func_8002A440(void) {
    X4_BackgroundObj* p = &D_8009A1F8.bg[0];

    if (((s8*)p)[0x44] != 0 && D_8009A16C == 0) {
        D_800718E0[((s8*)p)[4]](p);
        if (p->unk34 & 0x10) {
            update_screen_shake_x(p);
        }
        if (p->unk34 & 1) {
            update_screen_shake_y(p);
        }
        func_8002A080(p);
    }
}
