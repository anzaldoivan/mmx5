#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"

#define D_800F4844_ovl05 D_800FE340_ovl28

#define func_800EEA80_ovl05 func_800F6F28_ovl28
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

extern void (*D_800FE34C_ovl28[])(u8*);

void func_800F6F64_ovl28(u8* obj) {
    u8* p;

    p = *(u8**)(obj + 0x50);
    D_800FE34C_ovl28[((signed char*)obj)[6]](obj);
    if (is_off_screen(obj, 0x60, 0x60) == 0) {
        if (((signed char*)obj)[3] != 0) {
            func_8002D9EC(obj, 0x20, 0x20);
        }
    } else {
        obj[4]++;
    }
    if (((signed char*)p)[4] == 2) {
        obj[4]++;
    }
}

void func_800F701C_ovl28(u8* obj) {
    if (*(s8*)(obj + 6) == 4) {
        play_sound(2, 0x6C, obj);
    }
    clear_object_slot(obj);
}
