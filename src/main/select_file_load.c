#include "types.h"
#include "mmx5/globals.h"

extern void setup_file_load(s32, s32, s32);
extern void wait_for_file_load(s32, s32);
extern void func_80013E14(void);
extern void load_stage_entry_file(void);
extern s32 D_800D1F38;
extern s32 D_8009E790;
extern s32 D_800C9314;

void select_file_load(void) {
    u8* p = g_playthrough_state.u;
    u8 t;

    if (((s8*)p)[0x44] == 0) {
        t = p[0x49];
        if (t == 4) {
            setup_file_load(0x5D, 0, 0);
        } else if (t == 2) {
            setup_file_load(0x5E, 0, 0);
        } else if (t == 3) {
            setup_file_load(0x5F, 0, 0);
        } else {
            if (t == 1) {
                setup_file_load(0x5C, 0, 0);
            } else {
                setup_file_load(0x58, 0, 0);
            }
        }
    } else {
        setup_file_load(0x5A, 0, 0);
    }
    wait_for_file_load(0, 0);
    func_80013E14();
    D_800D1F38 = D_800BE9A8.w;
    D_800C9314 = D_8009E790;
    load_stage_entry_file();
}
