#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8004F5CC(u8* obj, u8* other);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_8004F4E0(u8* obj, u8* other) {
    s32 hit;

    func_80017248(obj);
    hit = 0;
    if ((*(u32*)(other + 4) & 0xFFFF00) == 0xB00) {
        hit = 1;
    }
    if (*(s8*)(other + 5) == 0x34) {
        hit = 1;
    }
    if (hit) {
        func_8004F5CC(obj, other);
    } else {
        func_800171E8(obj, 4);
        obj[4]++;
    }
    func_8002D9EC(obj, 0x20, 0x20);
}
