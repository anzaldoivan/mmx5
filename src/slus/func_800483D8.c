#include "types.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void* D_80077094[];

void func_800483D8(u8* obj) {
    if (func_8002D938(obj, 0x20, 0x20) == 0) {
        func_80017248(obj);
        ((void (*)(u8*))D_80077094[(s8)obj[5]])(obj);
    } else {
        obj[3] = 0;
        obj[4] = 2;
    }
}
