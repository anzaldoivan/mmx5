#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern void func_800FB418_ovl01(s32, void*, u8*, s32);
extern void func_8002A600(s32, s32, s32);
extern u8 D_800FD9CC_ovl01[];
extern signed char D_800D1C0C;

void func_800FAA0C_ovl01(u8* obj) {
    animate_object(obj);
    if (*(s16*)(obj + 0x7E) == 0x40) {
        play_sound(2, 0xC, obj);
        func_800FB418_ovl01(0xF, D_800FD9CC_ovl01, obj, 0);
        func_8002A600(0x14, 4, 2);
    }
    if (*(s16*)(obj + 0x7E) < 0x41) {
        obj[0x94] = 1;
    }
    if (--*(s16*)(obj + 0x7E) == 0) {
        obj[6] = 0;
        if (++obj[0x98] >= 3) {
            obj[5] = 7;
            obj[6] = 2;
            obj[0x94] = 0;
            obj[0x98] = 0;
            *(s16*)(obj + 0x7C) = 0x3C;
            if (D_800D1C0C == 0xC) {
                *(s16*)(obj + 0xE) = -0x30;
            } else {
                *(s16*)(obj + 0xE) = 0xB0;
            }
        }
    }
}
