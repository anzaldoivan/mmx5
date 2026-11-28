#include "types.h"
#include "mmx5/globals.h"

extern s32 get_launch_variant(void);

void func_800F4FDC_ovl10(u8* obj) {
    s32 kind;

    animate_object(obj);
    kind = ((signed char*)obj)[0x45];
    if (kind == 1) {
        obj[6] = 5;
        if (g_playthrough_state.s[0xC] != 0xC) {
            if (get_launch_variant() == 0) {
                func_8002385C(0x6A, 0xFF, (u8)g_playthrough_state.s[0x2E]);
            } else if (get_launch_variant() == kind) {
                func_8002385C(0x2F, 0xFF, (u8)g_playthrough_state.s[0x2E]);
            } else {
                func_8002385C(0x61, 0xFF, (u8)g_playthrough_state.s[0x2E]);
            }
            g_playthrough_state.s[0x2E] = 1;
        }
    }
}
