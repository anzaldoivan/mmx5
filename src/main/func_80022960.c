#include "types.h"
#include "mmx5/globals.h"

extern int func_8002DAA0();
extern void* D_800712E0[];

static inline void func_80022960_run(void** t, s32 i, void* o) {
    ((void (*)(void*))t[i])(o);
}

void func_80022960(void) {

    if (D_800D1C10.s == 0) {
        if (D_800D1DC0.s[0] != 0) {
            void* fn = D_800712E0[D_800D1DC0.s[1]];
            ((void (*)(void*))fn)(D_800D1DC0.s);
        }
        if (D_800D1DC0.s[0xB0] != 0) {
            func_80022960_run(D_800712E0, D_800D1DC0.s[0xB1],
                              D_800D1DC0.s + 0xB0);
        }
    } else {
        if (D_800D1DC0.s[0] != 0) {
            if ((u8)D_800D1DC0.s[0] & 8) {
                void* fn = D_800712E0[D_800D1DC0.s[1]];
                ((void (*)(void*))fn)(D_800D1DC0.s);
            } else if (D_800D1DC0.s[3] != 0) {
                func_8002DAA0(D_800D1DC0.s);
            }
        }
        if (D_800D1DC0.s[0xB0] != 0) {
            if ((u8)D_800D1DC0.s[0xB0] & 8) {
                func_80022960_run(D_800712E0, D_800D1DC0.s[0xB1],
                                  D_800D1DC0.s + 0xB0);
            } else if (D_800D1DC0.s[0xB3] != 0) {
                func_8002DAA0(D_800D1DC0.s + 0xB0);
            }
        }
    }
}
