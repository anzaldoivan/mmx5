#include "types.h"

extern s32 func_800478F8(u8* a0);
extern void func_8004795C(u8* a0);
extern void func_8002DF54(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_80047718(u8* a0) {
    if (func_800478F8(a0) == 0) {
        if (a0[0x8C] & 8) {
            func_8004795C(a0);
        }
        func_8002DF54(a0);
        func_8002D9EC(a0, 0x2C, 0x20);
    }
}
