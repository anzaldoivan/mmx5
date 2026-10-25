#include "types.h"

extern void Ovl_Load(s32, s32);
extern u8 D_800D1C31;

void func_800F6BF8_ovl18(Obj800F6C58* arg0) {
    if (*(s8*)arg0->unk14 == 0) {
        D_800D1C31 = 2;
        Ovl_Load(0x27, 0x800FA000);
        arg0->unk4++;
    }
}
