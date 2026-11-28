#include "types.h"
#include "addr.h"

extern void ChangeTh(s32);

void task_yield(s16 arg0) {
    *(s16*)(g_cur_task_slot + 2) = arg0;
    *(s16*)g_cur_task_slot = 1;
    ChangeTh(0xFF000000);
}
