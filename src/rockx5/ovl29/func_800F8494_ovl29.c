#include "types.h"
#include "mmx5/globals.h"

void func_800F8494_ovl29(u8* obj) {
    animate_object(obj);
    func_8002D89C(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        obj[4]++;
    }
}
