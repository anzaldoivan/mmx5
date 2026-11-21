#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define D_800F4844_ovl05 D_800FB778_ovl10

#define func_800EEA80_ovl05 func_800F2448_ovl10
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

extern u8 D_8009A197;
extern u8 D_800FB758_ovl10[];
extern void (*D_800FB790_ovl10[])(u8*);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);

void func_800F2484_ovl10(u8* obj) {
    s32 t;
    s32 v;

    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        D_800FB790_ovl10[*(signed char*)(obj + 5)](obj);
        animate_object(obj);
    }
    func_800317B8(obj);
    if (func_80031DD0(obj) < 0 || (v = *(s32*)(obj + 0x8C), t = v, v--,
                                   *(s32*)(obj + 0x8C) = v, t == 0)) {
        func_8004D4F4(3, D_800FB758_ovl10, obj);
        ((s32(*)())func_8004FD24)(obj);
        obj[4] = 3;
        return;
    }
    if (is_off_screen(obj, 0x20, 0x20) == 0) {
        func_8002D9EC(obj, 0x10, 0x10);
    } else {
        obj[4] = 3;
    }
}

#define D_800EEBA0_ovl00 func_800F2578_ovl10
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

void func_800F2598_ovl10(u8* arg0) {
    *(s32*)(arg0 + 0x84) = 0x3C;
    arg0[4] = 5;
}

void func_800F25AC_ovl10(u8* obj) {
    s32 v;
    s32 t;

    if (*(s32*)(obj + 0x84) & 1) {
        obj[3] ^= 1;
    }
    v = *(s32*)(obj + 0x84);
    t = v;
    v--;
    *(s32*)(obj + 0x84) = v;
    if (t == 0) {
        clear_object_slot();
    }
}
