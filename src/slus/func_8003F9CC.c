#include "types.h"

extern void func_8003B33C(u8*, s32);
extern void func_80016490(s32, s32, void*);
extern u8* func_8003D3A8(s32, s32, s32, u8*);

void func_8003F9CC(u8* obj) {
    func_8003B33C(obj, 0x60);
    func_80016490(1, 0x19, obj);
    obj[0x67] = 1;
    obj[0x5] = 0x2B;
    obj[0x6] = 0;
    func_8003D3A8(1, 0xC, 0, 0);
    func_8003D3A8(1, 0xC, 1, 0);
    func_8003D3A8(1, 0xC, 2, 0);
    func_8003D3A8(1, 0xC, 3, 0);
    func_8003D3A8(1, 0xC, 4, 0);
    func_8003D3A8(1, 0xC, 5, 0);
    func_8003D3A8(1, 0xC, 6, 0);
    func_8003D3A8(1, 0xC, 7, 0);
    obj[0x98] += 8;
    obj[0x99] += 8;
}
