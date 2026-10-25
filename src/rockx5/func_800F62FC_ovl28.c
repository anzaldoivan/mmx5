#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_8003CA44(u8* obj);

void func_800F62FC_ovl28(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        func_8003CA44(obj);
        obj[6]++;
    }
}
