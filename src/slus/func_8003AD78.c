#include "types.h"

extern void func_8003F294(u8* arg0, s32 arg1);
extern void func_80016490(s32, s32, void*);
extern void func_8003CF74(u8*, s32);
extern void func_8003CE10(u8*);
extern void func_8003CA44(u8* obj);

void func_8003AD78(u8* arg0) {
    func_8003F294(arg0, 0xE);
    func_80016490(1, 3, arg0);
    func_8003CF74(arg0, 2);
    arg0[0x67] = 1;
    if (*(u16*)(arg0 + 0x7C) & 0x100) {
        arg0[0x84] = 1;
        arg0[0x86] = 1;
        arg0[0x8C] = 1;
    } else {
        func_8003CE10(arg0);
    }
    if (arg0[0x89] & 1) {
        arg0[0x15] = 0x40;
        if (*(s8*)(arg0 + 0x84) != 0) {
            *(s32*)(arg0 + 0x20) = -*(s32*)(arg0 + 0x118);
        } else {
            *(s32*)(arg0 + 0x20) = -*(s32*)(arg0 + 0x104);
        }
    } else {
        arg0[0x15] = 0;
        if (*(s8*)(arg0 + 0x84) != 0) {
            *(s32*)(arg0 + 0x20) = *(s32*)(arg0 + 0x118);
        } else {
            *(s32*)(arg0 + 0x20) = *(s32*)(arg0 + 0x104);
        }
    }
    *(s32*)(arg0 + 0x28) = 0;
    arg0[0x8A] = 0xA;
    *(s32*)(arg0 + 0x24) = *(s32*)(arg0 + 0x124);
    *(s32*)(arg0 + 0x2C) = *(s32*)(arg0 + 0x144);
    func_8003CA44(arg0);
    arg0[0x5] = 0xA;
    arg0[0x6] = 0;
}
