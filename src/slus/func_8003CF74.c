#include "types.h"

extern void func_80016490(s32, s32, void*);

void func_8003CF74(u8* arg0, u8 arg1) {
    if (*(s8*)(arg0 + 0xEA) <= 0) {
        func_80016490(3, arg1, arg0);
    }
}
