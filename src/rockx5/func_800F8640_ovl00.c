#include "types.h"

extern void (*D_800FB50C_ovl00[])(u8*);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F8640_ovl00(u8* arg0) {
    D_800FB50C_ovl00[(signed char)arg0[6]](arg0);
    func_8002D9EC(arg0, 0xFF, 0xFF);
}
