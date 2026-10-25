#include "types.h"

extern u8* func_8002D144(void);
extern signed char D_8009A0A5;
extern s16 D_8009A1F8[];

void func_800F406C_ovl29(Obj3DD4* a) {
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
        a->unk15 = 0;
        a->unk6++;
        D_8009A1F8[0x13] = 0xC80;
        D_8009A1F8[0x12] = 0xC80;
    }
}
