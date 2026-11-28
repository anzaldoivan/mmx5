#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_8010000C_ovl04(u8* p) {
    func_8002C218();
    D_800D50DE = 0;
    D_8009A42E = 0;
    D_80093E68 = 0;
    p[0x1A] = 0;
    p[0x18] = 0x28;
    p[0x19] = 4;
    p[4]++;
}

extern void (*D_80102F30_ovl04[])(u8*);

void func_80100068_ovl04(u8* p) {
    if (p[0x1B] != 0) {
        D_80102F30_ovl04[p[0x1A]](p);
    } else {
        p[0x18]--;
        if (p[0x18] == 0) {
            p[0x1B] = 1;
        }
    }
}

#define animate_object func_8002C1C8
#define move_object clear_object_slot

#define func_800EF574_ovl09 func_801000D8_ovl04
#include "shared/func_800EF574_ovl09.c"
#undef func_800EF574_ovl09
