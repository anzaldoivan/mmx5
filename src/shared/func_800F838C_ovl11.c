#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F838C_ovl11(u8* a0) {
    if (*(s32*)(a0 + 0x20) < 0) {
        if (D_8009A0AA > *(s16*)(a0 + 0xA)) {
            a0[6]++;
        }
    } else if (D_8009A0AA < *(s16*)(a0 + 0xA)) {
        a0[6]++;
    }
    if (*(signed char*)(*(u8**)(a0 + 0x7C) + 4) == 2) {
        a0[6]++;
    }
    move_object(a0);
}
