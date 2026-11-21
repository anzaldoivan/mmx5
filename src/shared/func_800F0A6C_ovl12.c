#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void (*D_800F2094_ovl12[])(u8*);

void func_800F0A6C_ovl12(u8* arg0) {
    D_800F2094_ovl12[(signed char)arg0[6]](arg0);
    func_8002D9EC(arg0, 0x64, 0x64);
    animate_object(arg0);
    apply_object_motion(arg0);
}
