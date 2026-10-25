#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern u8 D_80091C44;

void func_800FA98C_ovl53(u8* arg0) {
    if (D_80091C44 == 0) {
        func_80016490(2, 0x55, 0);
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
