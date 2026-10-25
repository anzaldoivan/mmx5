#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern int func_8002D6FC();

void func_80046568(u8* obj) {
    func_80017248(obj);
    if (((s8*)obj)[1] == 0x2D) {
        func_8002D9EC(obj, 0x20, 0x20);
    } else {
        func_8002D9EC(obj, 0x40, 0x40);
    }
    if (((s8*)obj)[0x46] == 0) {
        func_8002D6FC(obj);
    }
}
