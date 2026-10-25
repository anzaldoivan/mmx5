#include "types.h"

extern u8* func_8002CA10(s32, s32);

void func_800F6BA0_ovl18(Obj800F6C58* arg0) {
    u8* p;

    p = func_8002CA10(0, 0);
    if (p != 0) {
        p[0] = 'A';
        p[1] = 'B';
        p[2] = 0;
    }
    arg0->unk14 = p;
    arg0->unk4++;
}
