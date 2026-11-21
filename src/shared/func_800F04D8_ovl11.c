#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F04D8_ovl11(u8* a0) {
    u8* p;

    if (*(signed char*)(a0 + 7) != *(signed char*)(*(u8**)(a0 + 0x50) + 7)) {
        set_animation(a0, 2);
    }
    p = *(u8**)(a0 + 0x50);
    a0[7] = p[7];
    *(s32*)(a0 + 8) = *(s32*)(p + 8);
    *(s16*)(a0 + 0xE) = *(s16*)(p + 0xE) - 0x20;
    if (p[0x47] == 10) {
        clear_object_slot(a0);
        return;
    }
    animate_object(a0);
    a0[0x54] = (signed char)(a0[0x54] + 1) % 90;
    if (*(signed char*)(a0 + 7) == 0 && (signed char)a0[0x54] < 30) {
        a0[3] = 0;
        return;
    }
    func_8002D89C(a0);
}
