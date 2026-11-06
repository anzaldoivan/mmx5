#include "types.h"

extern s32 func_80039ECC(u8* arg0);
extern void func_8003B33C(u8*, s32);
extern void func_8003B4CC(u8* obj, s32 arg1, s32 arg2);
extern void func_8003CE10(u8*);
extern void func_8003D0A0(u8* obj);

void func_8003A70C(u8* arg0) {
    s32 var_a2;
    u8 temp_v0;
    u8 temp_v1;

    if (func_80039ECC(arg0) == 0) {
        if (*(s8*)(arg0 + 2) == 0) {
            func_8003CE10(arg0);
            if (func_80039ECC(arg0) == 0) {
                arg0[5] = 2;
                arg0[6] = 0;
                if (*(s8*)(arg0 + 2) == 0 && *(s8*)(arg0 + 0x8E) != 0) {
                    temp_v0 = arg0[0x91];
                    var_a2 = temp_v0 < 9U;
                    if (temp_v0 < 5U) {
                        var_a2 = 2;
                    }
                    func_8003B4CC(arg0, 0x5E, var_a2);
                    temp_v1 = arg0[0x91];
                    if (temp_v1 >= 9U) {
                        arg0[0x44] = temp_v1 - 8;
                    }
                } else {
                    func_8003D0A0(arg0);
                }
            }
        } else {
            func_8003B33C(arg0, 9);
            arg0[5] = 5;
            arg0[6] = 0;
        }
    }
}
