#include "types.h"

/* D_8009A1F8 view: the word at 0xB0; its high half is also stored as the s16 at 0xB2 */
typedef struct {
    u8 pad0[0xB0];
    s32 unkB0;
} D_8009A1F8_B0_t;

extern D_8009A1F8_B0_t D_8009A1F8;
void func_8002385C(s32, s32, s32);

void func_800FA154_ovl40(Ovl45State* s) {
    D_8009A1F8.unkB0 += 0x10000;
    if (++s->unk4 >= 0xC0) {
        func_8002385C(0, 0xFF, 0);
        ((s16*)&D_8009A1F8.unkB0)[1] = 0xC0;
        s->unk4 = 0;
        s->unk1++;
    }
}
