#include "types.h"
#include "addr.h"

extern void ChangeTh(s32);

void task_yield(s16 arg0) {
    *(s16*)(D_801F8300 + 2) = arg0;
    *(s16*)D_801F8300 = 1;
    ChangeTh(0xFF000000);
}
