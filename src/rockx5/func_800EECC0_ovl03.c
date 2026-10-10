#include "types.h"

extern void (*D_800F9570_ovl03[])(u8*);
void func_8002FB58(u8*);

void func_800EECC0_ovl03(u8* arg0) {
    D_800F9570_ovl03[(signed char)arg0[4]](arg0);
    func_8002FB58(arg0);
}
