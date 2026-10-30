#include "types.h"

extern void (*D_800FC534_ovl27[])(u8*);
extern u16 D_800FC4F4_ovl27[][2];
extern D_8009A1F8_t D_8009A1F8;

void func_800EF9CC_ovl27(u8* arg0) {
    D_8009A1F8_t* d;

    D_800FC534_ovl27[*(signed char*)(arg0 + 6)](arg0);
    if (*(signed char*)(arg0 + 6) < 4 && (s16)(*(s16*)(arg0 + 0x14) % 5) == 0) {
        if (++*(s16*)(arg0 + 0x18) >= 0x10) {
            *(s16*)(arg0 + 0x18) = 0;
        }
        d = &D_8009A1F8;
        *(u16*)((u8*)d + 0xB2) = D_800FC4F4_ovl27[*(s16*)(arg0 + 0x18)][0];
        d->unkB6 = D_800FC4F4_ovl27[*(s16*)(arg0 + 0x18)][1];
        d->unkF4 = 1;
    }
}
