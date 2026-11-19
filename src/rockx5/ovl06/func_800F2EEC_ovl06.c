#include "types.h"
#include "mmx5/object.h"

void func_800F2EEC_ovl06(u8* arg0) {
    u8* p;
    u8 n;

    p = *(u8**)(arg0 + 0x7C);
    n = p[0x86];
    if (n != 0) {
        p[0x86] = n - 1;
    }
    clear_object_slot();
}
