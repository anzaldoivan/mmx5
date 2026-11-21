#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s32 rsin(s32);

void func_800FAC90_ovl28(u8* obj) {
    u8* p;

    if (*(u32*)(obj + 0x94) >= 4) {
        func_800317B8(obj);
    }
    if (*(s8*)(obj + 2) == 9) {
        *(s16*)(obj + 0xE) =
            *(u16*)(obj + 0x90) +
            (rsin((*(s16*)(obj + 0xA) - *(s32*)(obj + 0x8C)) * 16) >> 6);
    } else {
        *(s16*)(obj + 0xE) =
            *(u16*)(obj + 0x90) -
            (rsin((*(s16*)(obj + 0xA) - *(s32*)(obj + 0x8C)) * 16) >> 6);
    }
    func_8002D9EC(obj, 0x20, 0x80);
    if (*(s8*)(obj + 3) == 0) {
        if (*(s8*)(obj + 2) == 9) {
            p = *(u8**)(obj + 0x7C);
            *(u16*)(p + 0x7E) |= 2;
        }
        obj[4] = 2;
    }
    animate_object(obj);
    if (++*(u32*)(obj + 0x94) >= 7) {
        move_object(obj);
    }
}

#define D_800EEBA0_ovl00 func_800FADA8_ovl28
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
