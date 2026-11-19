#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s8 D_800D1C0F;
extern void func_8003B1A8(u8* a0);
extern void func_80039F1C(u8* a0);

void func_80037AA0(u8* a0) {
    if (D_800D1C0F != 0) {
        func_8003B1A8(a0);
        return;
    }
    if (*(s8*)(a0 + 0x45) == 0) {
        *(s32*)(a0 + 0x20) = *(s32*)(a0 + 0x100);
    } else {
        *(s32*)(a0 + 0x20) = *(s32*)(a0 + 0x104);
    }
    if (a0[0x15] == 0) {
        *(s32*)(a0 + 0x20) = -*(s32*)(a0 + 0x20);
    }
    move_object(a0);
    animate_object(a0);
    if (a0[0xD2] == 0) {
        func_80039F1C(a0);
    }
}
