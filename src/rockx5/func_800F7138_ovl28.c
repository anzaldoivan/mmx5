#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);

void func_800F7138_ovl28(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        func_8002DF54(obj);
    }
}
