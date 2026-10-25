#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_8003CE10(u8*);
extern s32 func_80039ECC(u8* arg0);
extern s32 func_8003EF28(u8* arg0);
extern s32 func_800437FC(u8* arg0);
extern s32 func_800394B0(u8* arg0);
extern s32 func_8004387C(u8* arg0);
extern void func_8003F294(u8* arg0, s32 arg1);

void func_8003A9AC(u8* arg0) {
    func_80016490(1, 2, arg0);
    arg0[0x67] = 0;
    func_8003CE10(arg0);
    if (func_80039ECC(arg0) == 0 && func_8003EF28(arg0) == 0 &&
        func_800437FC(arg0) == 0 && func_800394B0(arg0) == 0 &&
        func_8004387C(arg0) == 0) {
        func_8003F294(arg0, 0xC);
        arg0[5] = 8;
        arg0[6] = 0;
    }
}
