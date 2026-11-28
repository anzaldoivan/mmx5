#include "types.h"

extern s8 D_800D1C0F;
extern void func_8003B1A8(u8* a0);
extern void func_8003A418(u8* a0);
extern void func_8003A670(u8* arg0);

void func_800444B4(u8* a0) {
    if (((s8*)a0)[0x46] == 0) {
        a0[0x8E] = 0;
        if (D_800D1C0F != 0) {
            func_8003B1A8(a0);
        } else if (((s8*)a0)[0xD0] != 0) {
            func_8003A418(a0);
        } else {
            func_8003A670(a0);
        }
    }
}
