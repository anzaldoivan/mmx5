#include "types.h"
#include "mmx5/globals.h"

extern s32 get_launch_variant(void);

void func_800F5038_ovl04(u8* obj) {
    u8* d;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        d = g_playthrough_state.u;
        if (*(s8*)(d + 0xC) != 0xC) {
            if (get_launch_variant() == 0) {
                func_8002385C(0x2E, 0xFF, *(s8*)(d + 0x2E));
            } else if (get_launch_variant() == 1) {
                func_8002385C(0x60, 0xFF, *(s8*)(d + 0x2E));
            } else {
                func_8002385C(0x60, 0xFF, *(s8*)(d + 0x2E));
            }
            g_playthrough_state.u[0x2E] = 1;
        }
        obj[5]++;
    }
}
