#include "types.h"

extern void* D_8007C34C[];
extern u8 D_800D1C00[];
extern u8 D_8009A0A0[];

void func_80054BB8(u8* arg0) {
    u8* a1 = D_800D1C00;
    u8* a2 = D_8009A0A0;

    ((void (*)(u8*, u8*, u8*))D_8007C34C[((s8*)arg0)[5]])(arg0, a1, a2);
}
