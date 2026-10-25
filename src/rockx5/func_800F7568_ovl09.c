#include "types.h"

extern void (*D_800FB29C_ovl09[])(u8* obj);
extern void func_80017248(u8* obj);
extern s32 func_8002D800(u8* obj);
extern void func_8002D89C(u8* obj);

void func_800F7568_ovl09(u8* obj) {
    D_800FB29C_ovl09[((s8*)obj)[5]](obj);
    func_80017248(obj);
    if (func_8002D800(obj) == 0) {
        func_8002D89C(obj);
    } else {
        obj[4] = 2;
    }
}
