#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_800F94B0_ovl09(u8* obj) {
    if ((*(u8**)(obj + 0x50))[0x86] == 1) {
        clear_object_slot(obj);
    } else {
        (*(u16*)(obj + 0x54))++;
        if ((*(u16*)(obj + 0x54) & 7) == 0) {
            func_8004FD90(obj, 1, 3, 0x3F);
        }
    }
}

void func_800F9520_ovl09(u8* obj) {
    s8* s = (s8*)obj;
    s32 st = s[2];

    if (st == 1 && s[5] == 0) {
        if (--*(s16*)(obj + 0x56) == 0) {
            s[3] = st;
            ((volatile s8*)obj)
                [5]++; // !FAKE: volatile forces the reload of byte 5 the target does after the sh
        }
    }
    if (((s8*)*(u8**)(obj + 0x50))[4] != 3 || --*(s16*)(obj + 0x54) == 0) {
        s[4] = 4;
        s[5] = 0;
        s[3] = 0;
    } else {
        animate_object(obj);
    }
}

#define D_800EEBA0_ovl00 func_800F95D4_ovl09
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
