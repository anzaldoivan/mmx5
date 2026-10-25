#include "types.h"

extern void func_80012E6C(s32);
extern s8 D_800D1C00[];
extern void* D_8007108C[];

void func_80020904(void) {
    s32 state;

    while (1) {
        state = D_800D1C00[0];
        ((void (*)(s8*))D_8007108C[state])(D_800D1C00);
        func_80012E6C(1);
    }
}
