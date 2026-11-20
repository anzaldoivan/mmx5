#include "types.h"
#include "mmx5/object.h"

void func_800F33E4_ovl06(u8* obj) {
    u8* p = *(u8**)(obj + 0x7C);

    p[0x7F] ^= 1 << ((s8*)obj)[2];
    clear_object_slot(obj);
}
