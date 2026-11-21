#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern s32 func_8002DC14(void);
extern s8 D_800D1C00[];

void func_800FAE28_ovl01(u8* obj) {
    s8 st;
    s32 r;
    s32 a;
    s8* p;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 0x10) {
        play_sound(2, 9, obj);
    }
    st = *(s8*)(obj + 0x45);
    if (st == 1) {
        p = D_800D1C00;
        if (p[0xC] != 0xC) {
            r = func_8002DC14();
            a = 0x2B;
            if (r == 0 || (func_8002DC14() == st && (a = 0x5D, 1))) {
                func_8002385C(a, 0xFF, *(u8*)(p + 0x2E));
            } else {
                func_8002385C(0x5D, 0xFF, *(u8*)(p + 0x2E));
            }
            D_800D1C00[0x2E] = 1;
        }
        obj[6] = 6;
    }
}
