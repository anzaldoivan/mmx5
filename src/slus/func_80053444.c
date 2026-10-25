#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void* D_8007BD60[];

void func_80053444(u8* obj) {
    s32 v = *(s32*)(obj + 0x80);
    s32 t = v;

    v--;
    *(s32*)(obj + 0x80) = v;
    if (t == 0) {
        func_800171E8(obj, 3);
        obj[4] = 2;
    } else {
        ((void (*)(u8*))D_8007BD60[*(s8*)(obj + 6)])(obj);
    }
}
