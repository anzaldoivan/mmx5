#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern s32 func_8004FC64(u8* a0);
extern void* D_800FDBA4_ovl27[];

void func_800FB3D0_ovl27(u8* o) {
    ((void (*)(u8*))D_800FDBA4_ovl27[*(s8*)(o + 6)])(o);
    func_800317B8(o);
    if (func_80031DD0(o) < 0) {
        func_8004FD24(o);
        goto inc; // !FAKE: goto kept for the matching branch layout
    }
    if (o[2] < 2) {
        if (*(s16*)(o + 0x88) == 0) {
            if (o[0x70] != 0 || (((s32(*)())func_8002F8FC)(o), o[0x70] != 0)) {
                func_8004FC64(o);
                o[4]++;
                return;
            }
        } else {
            *(s16*)(o + 0x88) = *(s16*)(o + 0x88) - 1;
        }
    }
    if (is_off_screen(o, 0x20, 0x20) == 1) {
    inc: // !FAKE: label kept for the matching branch layout
        o[4]++;
    }
}

#define D_800EEBA0_ovl00 func_800FB4D4_ovl27
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
