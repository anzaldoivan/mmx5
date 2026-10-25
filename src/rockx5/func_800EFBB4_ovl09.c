#include "types.h"

extern s32 func_8002DF54(u8* a0);
extern void func_800171E8(u8* obj, s32 state);

void func_800EFBB4_ovl09(u8* obj) {
    if (*(s16*)(obj + 0x7E) != 0) {
        func_8002DF54(obj);
        *(s16*)(obj + 0x7E) -= 1;
    } else {
        func_800171E8(obj, 1);
        *(s16*)(obj + 0x7E) = 0x40;
        obj[6] += 1;
        *(s32*)(obj + 0x24) = -*(s32*)(obj + 0x24);
    }
}
