#include "types.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D720(u8* arg0);

void func_80055DEC(u8* arg0) {
    if (func_8002D938(arg0, 0x88, 0x88) == 1) {
        func_8002D720(arg0);
    }
}
