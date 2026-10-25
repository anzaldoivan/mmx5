#include "types.h"

extern void* D_800F9C9C_ovl11[];
extern u8 D_8009A0A0[];
extern s16 D_8009A206;

void func_800F4A5C_ovl11(u8* arg0) {
    u8* p;

    ((void (*)(u8*))D_800F9C9C_ovl11[(s8)arg0[6]])(arg0);
    p = D_8009A0A0;
    if (*(s16*)(p + 0xE) < D_8009A206 + 4) {
        *(s16*)(p + 0xE) = D_8009A206 + 4;
    }
}
