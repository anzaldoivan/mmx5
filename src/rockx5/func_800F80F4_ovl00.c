#include "types.h"

extern u8* func_8002D144(void);
extern signed char D_8009A0A5;

void func_800F80F4_ovl00(Obj3DD4* a) {
    u8* p;

    if (D_8009A0A5 == 0x14) {
        p = func_8002D144();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(s16*)(p + 0xA) = a->unkA;
            *(s16*)(p + 0xE) = a->unkE;
            *(u8**)((u8*)a + 0x80) = p;
        }
        a->unk6++;
    }
}
