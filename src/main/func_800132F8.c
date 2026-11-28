#include "types.h"
#include "mmx5/globals.h"
#define D_8009A420_as_Ctl (*(Ctl*)&D_8009A420)

extern void create_task(s32, void (*)(void));
extern void func_8001303C(void);

void func_800132F8(s8 arg) {
    if (D_8009A420_as_Ctl.busy == 0) {
        D_8009A420_as_Ctl.busy = -1;
        D_8009A420_as_Ctl.arg = arg;
        create_task(2, func_8001303C);
    }
}
