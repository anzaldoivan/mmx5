#include "types.h"

extern void func_80024698(void);
extern s8 D_80070EA0;
extern void (*D_80070EA4[])(u8*);

void func_8001E788(u8* a0) {
    if (((s8*)a0)[1] == 0) {
        if (D_80070EA0 != 0) {
            a0[1] = 5;
        }
    }
    D_80070EA4[((s8*)a0)[1]](a0);
    if (((s8*)a0)[1] < 5) {
        func_80024698();
    }
}
