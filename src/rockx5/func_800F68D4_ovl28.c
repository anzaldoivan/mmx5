#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800F68D4_ovl28(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if (*(s32*)(obj + 0x24) <= 0) {
        obj[7] = 3;
        func_800171E8(obj, 9);
        *(s16*)(obj + 0x7C) = 0;
        *(s16*)(obj + 0x7E) = 0;
        obj[6]++;
    }
}
