#include "types.h"

s32 get_tile_attr_origin(u8* obj);
void func_8003A94C(u8* obj);

s32 func_80039E7C(u8* self) {
    if (get_tile_attr_origin(self) == 0x20 &&
        (*(u16*)(self + 0x80) & 0x80) == 0) {
        return 0;
    }
    func_8003A94C(self);
    return 1;
}
