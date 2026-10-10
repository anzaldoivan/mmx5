#include "types.h"

void func_8003CD08(u8* arg0);
void func_80043B88(u8* arg0);
s32 func_80039ECC(u8* arg0);
s32 func_80039C80(u8* arg0);
s32 func_8003EF28(u8* arg0);
s32 func_800437FC(u8* arg0);
s32 func_8003952C(u8* arg0);
s32 func_8004387C(u8* arg0);
s32 func_80041A54(u8* arg0);
s32 func_80039588(u8* arg0);
s32 func_800395E8(u8* arg0);
void func_8003A7E4(u8* arg0);
void func_800400A4(u8* arg0);

void func_80035F90(u8* arg0) {
    func_8003CD08(arg0);
    func_80043B88(arg0);
    if (func_80039ECC(arg0) != 0) {
        return;
    }
    if (func_80039C80(arg0) != 0) {
        return;
    }
    if (func_8003EF28(arg0) != 0) {
        return;
    }
    if (func_800437FC(arg0) != 0) {
        return;
    }
    if (func_8003952C(arg0) != 0) {
        return;
    }
    if (func_8004387C(arg0) != 0) {
        return;
    }
    if (func_80041A54(arg0) != 0) {
        return;
    }
    if (func_80039588(arg0) != 0) {
        return;
    }
    if (func_800395E8(arg0) != 0) {
        func_8003A7E4(arg0);
    } else {
        func_800400A4(arg0);
    }
}
