#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F6694_ovl28(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 7) == 2) {
        func_800171E8(obj, 10);
        *(s16*)(obj + 0x7C) = 0;
        *(s16*)(obj + 0x7E) = 5;
        obj[6]++;
    }
}
