#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F7A40_ovl09(u8* obj) {
    s32 n = (s8)obj[2];

    switch (n) {
    case 1:
    case 2:
        set_animation(obj, n + 1);
        break;
    case 3:
        func_8002D89C(obj);
        break;
    }
    obj[0x54] = 0;
    obj[4]++;
}
