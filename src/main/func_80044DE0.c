#include "types.h"
#include "mmx5/globals.h"

extern void func_80017BF4(void);
extern u8 D_800D1F3C;

u8 func_80044DE0(void) {
    if (D_800D1F3C == 0) {
        g_playthrough_state.u[0x40] = 0;
        func_80017BF4();
    }
    return g_playthrough_state.u[0x40];
}
