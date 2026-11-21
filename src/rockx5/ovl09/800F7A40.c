#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"

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

void func_800F7AB4_ovl09(u8* p) {
    if (((s8*)p)[0x54] != 0) {
        p[4]++;
    }
    if (((s8*)p)[2] == 0) {
        if ((p[3] ^= 1) != 0) {
            func_8002D89C(p);
        }
    } else {
        animate_object(p);
        func_8002D89C(p);
    }
}

void func_800F7B38_ovl09(u8* obj) {
    obj[0x54] = 0;
    clear_object_slot(obj);
}
