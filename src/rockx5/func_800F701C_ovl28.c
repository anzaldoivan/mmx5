#include "types.h"

extern void func_80016490(s32, s32, void*);
extern int func_8002D6FC();

void func_800F701C_ovl28(u8* obj) {
    if (*(s8*)(obj + 6) == 4) {
        func_80016490(2, 0x6C, obj);
    }
    func_8002D6FC(obj);
}
