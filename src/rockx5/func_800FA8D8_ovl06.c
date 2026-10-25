#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_80016490(s32, s32, void*);

void func_800FA8D8_ovl06(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        func_80016490(2, 0x20, obj);
        obj[6]++;
    }
}
