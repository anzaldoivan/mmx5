#include "types.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D0E4(void);

void func_800F5E40_ovl28(u8* obj) {
    s8 kind;
    u8 dir;
    u8* p;

    func_80017248(obj);
    kind = *(s8*)(obj + 0x45);
    if (kind == 2) {
        p = func_8002D0E4();
        if (p != 0) {
            p[0] = 0x61;
            p[1] = 0xB;
            p[2] = kind;
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            dir = obj[0x15];
            p[0x15] = dir;
            if (dir == 0) {
                *(u16*)(p + 0xA) = *(u16*)(obj + 0xA) - 0x14;
            } else {
                *(u16*)(p + 0xA) = *(u16*)(obj + 0xA) + 0x14;
            }
            *(u16*)(p + 0xE) = *(u16*)(obj + 0xE);
            *(u8**)(p + 0x50) = obj;
        }
        obj[6]++;
    }
}
