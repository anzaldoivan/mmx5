#include "types.h"
#include "addr.h"

void func_80012FE4(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        ((Obj80012FE4*)g_cur_task_slot)->f60[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        *(g_cur_task_slot + i + 0x71) = 0;
    }
}
