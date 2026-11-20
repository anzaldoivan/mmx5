#include "types.h"
#include "mmx5/globals.h"

void func_800F71F8_ovl28(u8* p) {
    animate_object(p);
    if (*(s8*)(*(u8**)(p + 0x50) + 6) == 2) {
        p[4]++;
    }
}
