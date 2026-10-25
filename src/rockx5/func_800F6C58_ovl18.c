#include "types.h"

extern s32 Ovl_Load3(void);
extern u8* func_8002CA10(s32, s32);

void func_800F6C58_ovl18(Obj800F6C58* arg0) {
    u8* p;

    if (Ovl_Load3() != 0) {
        p = func_8002CA10(0, 0);
        if (p != 0) {
            p[0] = 'A';
            p[1] = 'C';
            p[2] = 0;
        }
        arg0->unk14 = p;
        arg0->unk4++;
    }
}
