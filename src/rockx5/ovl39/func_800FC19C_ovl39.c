#include "types.h"
#include "mmx5/object.h"

extern u8 D_8009A11A;
extern u8 D_800D1C00[];

void func_800FC19C_ovl39(void) {
    u8* p = D_800D1C00;

    p[0xF] = 0x10;
    p[0x24] = 0;
    *(s32*)(p + 0x20) = 0;
    D_8009A11A = 0;
    clear_object_slot();
}
