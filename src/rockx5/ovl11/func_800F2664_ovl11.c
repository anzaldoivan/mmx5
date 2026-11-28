#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800F9B20_ovl11[])();

void func_800F2664_ovl11(u8* obj) {
    if (D_800C9320.h & 2) {
        D_800F9B20_ovl11[((s8*)obj)[4]](obj);
    } else {
        D_800F9B20_ovl11[((s8*)obj)[4]](obj);
    }
    func_8002FB58(obj);
}
