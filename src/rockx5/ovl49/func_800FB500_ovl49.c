#include "types.h"
#include "mmx5/ovl49.h"

extern void func_8002C1C8(void);
extern u8 D_80091C44;
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern D_8009A1F8_5C_t D_8009A1F8;

void func_800FB500_ovl49(u8* arg) {
    u8* p;
    D_8009A1F8_5C_t* b;
    s32 one;

    if (D_80091C44 == 0) {
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C1C8();
        b = &D_8009A1F8;
        do { // !FAKE: fence spaces the constant 1 from the next hi
            one = 1;
        } while (0);
        p = D_800FC1C4_ovl49;
        b->unk3 = 0;
        b->unk57 = one;
        b->unkA0 = one;
        b->unkAB = 0;
        b->unk5C = 0;
        b->unk60 = 0x3800000;
        p[0x36] = 0x22;
        D_800FC1C4_ovl49[0x3] = one;
        arg[1]++;
        *(s16*)(arg + 4) = 0;
    }
}
