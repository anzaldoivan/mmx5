#include "types.h"
#include "mmx5/object.h"

void func_800F1414_ovl07(u8* arg0) {
    u8* p;

    p = *(u8**)(arg0 + 0x7C);
    p[0x98]--;
    clear_object_slot();
}
