#include "types.h"
#include "mmx5/globals.h"

void func_800F5CB8_ovl26(u8* obj) {
    u8* sub = *(u8**)(obj + 0x7C);

    sub[7]++;
    animate_object(obj);
    obj[6]++;
}
