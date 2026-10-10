#include "types.h"

extern void func_80017248(u8* obj);
extern int func_8002D6FC();

void func_800F6E38_ovl04(u8* obj) {
    if (obj[0x8F] != 0) {
        obj[0x8F]--;
        func_80017248(obj);
    } else {
        func_8002D6FC(obj);
    }
}
