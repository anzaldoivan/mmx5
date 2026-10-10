#include "types.h"

/* D_8009A1F8 view: the word at 0x8; its high half is also stored as the s16 at 0xA */
typedef struct {
    u8 pad0[0x8];
    s32 unk8;
} D_8009A1F8_8_t;

extern D_8009A1F8_8_t D_8009A1F8;
void func_8002385C(s32, s32, s32);

void func_800FA678_ovl53(Ovl45State* s) {
    D_8009A1F8.unk8 += 0x20000;
    if (++s->unk4 >= 0x60) {
        func_8002385C(0x50, 0xFF, 0);
        ((s16*)&D_8009A1F8.unk8)[1] = 0x2C0;
        s->unk1++;
    }
}
