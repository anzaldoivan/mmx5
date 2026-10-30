#include "types.h"

extern void func_80017248(u8* obj);

void func_800F5F1C_ovl28(u8* obj) {
    func_80017248(obj);
    obj[6]++;
}
