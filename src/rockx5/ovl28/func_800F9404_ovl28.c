#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void (*D_800FE6F0_ovl28[])(u8*);

void func_800F9404_ovl28(u8* arg0) {
    D_800FE6F0_ovl28[(signed char)arg0[6]](arg0);
    func_8002D9EC(arg0, 0x30, 0x30);
    animate_object(arg0);
    apply_object_motion(arg0);
}
