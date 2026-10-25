#include "types.h"
extern X4_BackgroundObj D_8009A1F8[3];
extern s8 D_8009A16C;
extern void (*D_800718E0[])(X4_BackgroundObj*);
void func_8002ABA4(X4_BackgroundObj* arg0);
void func_8002AC34(X4_BackgroundObj* arg0);
void func_8002A080(X4_BackgroundObj* arg0);

void func_8002A440(void) {
    X4_BackgroundObj* p = &D_8009A1F8[0];

    if (((s8*)p)[0x44] != 0 && D_8009A16C == 0) {
        D_800718E0[((s8*)p)[4]](p);
        if (p->unk34 & 0x10) {
            func_8002ABA4(p);
        }
        if (p->unk34 & 1) {
            func_8002AC34(p);
        }
        func_8002A080(p);
    }
}
