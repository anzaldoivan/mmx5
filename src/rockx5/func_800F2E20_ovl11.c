#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D1A4();

void func_800F2E20_ovl11(u8* obj) {
    u8* p;

    func_80017248(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        obj[6]++;
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x19;
            p[2] = D_1F80004C.bytes[0x82];
            *(s32*)(p + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            p[0x14] = obj[0x14];
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            p[0x15] = obj[0x15];
        }
    }
}
