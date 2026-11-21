#include "types.h"
#include "mmx5/globals.h"

void func_800F63CC_ovl26(u8* obj) {
    u8* sub;

    animate_object(obj);
    sub = *(u8**)(obj + 0x7C);
    sub[7]++;
    obj[6]++;
}
