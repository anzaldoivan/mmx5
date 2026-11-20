#include "types.h"
#include "mmx5/object.h"

extern void (*D_800F582C_ovl20[])(u8*);
extern s8 D_800D1C01;

void func_800F3CD8_ovl20(u8* arg0) {
    D_800F582C_ovl20[(s8)arg0[4]](arg0);
    if (D_800D1C01 != 6) {
        clear_object_slot(arg0);
    }
}
