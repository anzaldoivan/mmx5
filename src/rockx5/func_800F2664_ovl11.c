#include "types.h"

extern u16 D_800C9320;
extern void (*D_800F9B20_ovl11[])();
extern s32 func_8002FB58(u8* obj);

void func_800F2664_ovl11(u8* obj) {
    if (D_800C9320 & 2) {
        D_800F9B20_ovl11[((s8*)obj)[4]](obj);
    } else {
        D_800F9B20_ovl11[((s8*)obj)[4]](obj);
    }
    func_8002FB58(obj);
}
