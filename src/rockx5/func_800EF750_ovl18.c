#include "types.h"

extern void (*D_800F75FC_ovl18[])(u8*);
void func_80017248(u8*);
void func_8002D89C(u8*);

void func_800EF750_ovl18(u8* arg0) {
    D_800F75FC_ovl18[(signed char)arg0[6]](arg0);
    func_80017248(arg0);
    func_8002D89C(arg0);
}
