#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern s32 get_launch_variant(void);
extern s16 D_800FB61C_ovl09;
extern s16 D_800FB61E_ovl09;

void func_800F2BFC_ovl09(u8* obj) {
    if (*(s16*)(obj + 0xA) >= D_800FB61C_ovl09) {
        *(s16*)(obj + 0xA) = D_800FB61C_ovl09;
        *(s32*)(obj + 0x20) = 0;
    }
    if (*(s16*)(obj + 0xE) <= D_800FB61E_ovl09) {
        *(s16*)(obj + 0xE) = D_800FB61E_ovl09;
        *(s32*)(obj + 0x24) = 0;
    }
    if (*(s16*)(obj + 0xA) == D_800FB61C_ovl09 &&
        *(s16*)(obj + 0xE) == D_800FB61E_ovl09) {
        if ((s8)g_playthrough_state.u[0xC] != 0xC) {
            if (get_launch_variant() == 0) {
                func_8002385C(0x31, 0xFF, (s8)g_playthrough_state.u[0x2E]);
            } else if (get_launch_variant() == 1) {
                func_8002385C(0x63, 0xFF, (s8)g_playthrough_state.u[0x2E]);
            } else {
                func_8002385C(0x63, 0xFF, (s8)g_playthrough_state.u[0x2E]);
            }
            g_playthrough_state.u[0x2E] = 1;
        }
        *(s16*)(obj + 0x7C) = 3;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}
