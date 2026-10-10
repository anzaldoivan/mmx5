#include "types.h"

void func_80043B88(u8* arg0);
s32 func_80039ECC(u8* arg0);
s32 func_80039C80(u8* arg0);
s32 func_8003EF28(u8* arg0);
s32 func_800437FC(u8* arg0);
s32 func_8003952C(u8* arg0);
s32 func_8004387C(u8* arg0);
s32 func_80041A54(u8* arg0);
s32 func_800395E8(u8* arg0);
void func_80017248(u8* obj);
void func_8003A82C(u8* arg0);
void func_8002DF54(u8* a0);
void func_8003F2D8(u8* arg0, s32 arg1);
void func_8003A70C(u8* arg0);

void func_80036064(u8* arg0) {
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
    if (func_800395E8(arg0) != 0) {
        func_80017248(arg0);
        if (*(signed char*)(arg0 + 0x46) < 0) {
            func_8003A82C(arg0);
        } else {
            func_8002DF54(arg0);
            func_8003F2D8(arg0, 7);
        }
    } else {
        func_8003A70C(arg0);
    }
}
