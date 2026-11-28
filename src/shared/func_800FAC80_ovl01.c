#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void func_80024548(s32);

void func_800FAC80_ovl01(u8* obj) {
    if (**(signed char**)(obj + 0x8C) == 0) {
        g_playthrough_state.u[0x24] = 1;
        g_playthrough_state.u[0x25] = 0;
        g_playthrough_state.u[0xA2] = 0x36;
        *(u8**)(g_playthrough_state.u + 0x20) = obj;
        if ((signed char)g_playthrough_state.u[0xC] == 0xC) {
            func_80024548(-1);
        } else {
            func_80024548(1);
        }
        *(s32*)(obj + 0x2C) = 0x8000;
        set_animation(obj, 0x11);
        obj[6] = 3;
    }
}
