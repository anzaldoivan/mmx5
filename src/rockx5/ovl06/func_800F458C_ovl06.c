#include "types.h"
#include "mmx5/object.h"

extern s16 D_8009A202;
extern void (*D_800FE634_ovl06[])(u8*);

void func_800F458C_ovl06(u8* a0) {
    move_object(a0);
    if (*(s16*)(a0 + 0xA) - D_8009A202 >= 0x51) {
        *(s32*)(a0 + 0x8) = *(s32*)(a0 + 0x18);
    }
    D_800FE634_ovl06[*(s8*)(a0 + 0x6)](a0);
}
