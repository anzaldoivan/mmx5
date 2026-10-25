#include "types.h"

s32 func_80030A0C(u8* obj);
void func_8003A94C(u8* obj);

s32 func_80039E7C(u8* self) {
    if (func_80030A0C(self) == 0x20 && (*(u16*)(self + 0x80) & 0x80) == 0) {
        return 0;
    }
    func_8003A94C(self);
    return 1;
}
