#include "types.h"
#include "mmx5/globals.h"

extern void* D_800F9C9C_ovl11[];
extern s16 D_8009A206;

void func_800F4A5C_ovl11(u8* arg0) {
    u8* p;

    ((void (*)(u8*))D_800F9C9C_ovl11[(s8)arg0[6]])(arg0);
    p = g_Player;
    if (*(s16*)(p + 0xE) < D_8009A206 + 4) {
        *(s16*)(p + 0xE) = D_8009A206 + 4;
    }
}
