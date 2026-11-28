#include "types.h"

void func_8003F944(u8* p, s32 arg1);
void func_8003F8EC(u8* p, s32 arg1);
void func_8003F9CC(u8* p, s32 arg1);
void func_8003FAD0(u8* p, s32 arg1);
void func_8003FB4C(u8* p, s32 arg1);
void func_8003FC90(u8* p, s32 arg1);
void func_8003FBD0(u8* p, s32 arg1);

void func_8003F548(u8* p, s32 arg1) {
    switch ((s8)p[0x96]) {
    case 10:
        func_8003F944(p, arg1);
        break;
    case 2:
    case 11:
        func_8003F8EC(p, arg1);
        break;
    case 12:
        func_8003F9CC(p, arg1);
        break;
    case 13:
        func_8003FAD0(p, arg1);
        break;
    case 14:
        func_8003FB4C(p, arg1);
        break;
    case 6:
        func_8003FC90(p, arg1);
        break;
    case 8:
    case 17:
        func_8003FBD0(p, arg1);
        break;
    }
}
