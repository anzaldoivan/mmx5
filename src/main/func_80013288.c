#include "types.h"
#include "mmx5/globals.h"
#define D_8009A420_as_Ctl (*(Ctl*)&D_8009A420)

extern u8 g_draw_info_buffers[];
extern void create_task(s32, void (*)(void));
extern void func_8001303C(void);

void func_80013288(s8 arg) {
    u8* p = g_draw_info_buffers;

    p[0x2D] = 0;
    p[0x2E] = 0;
    p[0x2F] = 0;
    p[0xDD] = 0;
    p[0xDE] = 0;
    p[0xDF] = 0;
    if (D_8009A420_as_Ctl.busy == 0) {
        D_8009A420_as_Ctl.busy = 1;
        D_8009A420_as_Ctl.arg = arg;
        create_task(2, func_8001303C);
    }
}
