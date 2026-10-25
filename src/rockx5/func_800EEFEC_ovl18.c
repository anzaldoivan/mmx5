#include "types.h"

extern void (*D_800F6CE4_ovl18[])(u8*);
extern u16 D_800F6CD4_ovl18[][2];
extern D_8009A1F8_t D_8009A1F8;

void func_800EEFEC_ovl18(u8* arg0) {
    D_8009A1F8_t* d;

    D_800F6CE4_ovl18[*(signed char*)(arg0 + 6)](arg0);
    if (*(signed char*)(arg0 + 6) < 3 && (s16)(*(s16*)(arg0 + 0x14) % 6) == 0) {
        if (++*(s16*)(arg0 + 0x18) >= 4) {
            *(s16*)(arg0 + 0x18) = 0;
        }
        d = &D_8009A1F8;
        *(u16*)((u8*)d + 0xB2) = D_800F6CD4_ovl18[*(s16*)(arg0 + 0x18)][0];
        d->unkB6 = D_800F6CD4_ovl18[*(s16*)(arg0 + 0x18)][1];
        d->unkF4 = 1;
    }
}
