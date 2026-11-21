#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800F75FC_ovl18[])(u8*);

void func_800EF750_ovl18(u8* arg0) {
    D_800F75FC_ovl18[(signed char)arg0[6]](arg0);
    animate_object(arg0);
    func_8002D89C(arg0);
}
