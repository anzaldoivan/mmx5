#include "types.h"

extern signed char D_8009A424;
extern void func_800177B0(s32, s32);

void func_800EECC8_ovl21(Ovl45State* s) {
    if (D_8009A424 == 0) {
        s->unk4 = 0;
        s->unk1++;
        func_800177B0(0x18, 0x7F);
    }
}
