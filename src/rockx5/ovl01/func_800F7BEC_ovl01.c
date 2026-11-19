#include "types.h"
#include "mmx5/ovl01.h"
#include "mmx5/title.h"
#include "mmx5/object.h"

extern void func_800F79C0_ovl01(u8* a0);
extern u8 D_8009A197;

void func_800F7BEC_ovl01(u8* a0) {
    if (*(*(u8**)(a0 + 0x20) + 0x87) >= 2) {
        clear_object_slot(a0);
    } else {
        if (is_off_screen(a0, D_800FD408_ovl01[*(s8*)(a0 + 2)][1],
                          D_800FD408_ovl01[*(s8*)(a0 + 2)][2]) == 0 &&
            D_8009A197 == 0 && !(*(u16*)(*(u8**)(a0 + 0x20) + 0x42) & 0x8000)) {
            func_800F79C0_ovl01(a0);
        }
    }
}
