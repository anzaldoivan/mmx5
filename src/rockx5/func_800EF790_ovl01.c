#include "types.h"

extern u8 D_8009A1F8[];
extern u8 D_8009A197;
extern s32 func_8002A600(s32, s32, s32);

void func_800EF790_ovl01(u8* arg0) {
    u8* p = D_8009A1F8;

    if (*(s16*)(p + 0xA) == *(s16*)(p + 0x26)) {
        arg0[0x18] = 0;
        arg0[5]++;
    }
    if (D_8009A197 == 0) {
        if (*(s16*)(p + 0x2A) == *(s16*)(p + 0x28)) {
            if (--arg0[0x1C] == 0) {
                func_8002A600(0x30, 2, 1);
                arg0[0x1C] = 0xA0;
            }
        } else {
            *(s16*)(p + 0x34) = 0;
        }
    }
}
