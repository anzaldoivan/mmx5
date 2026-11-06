#include "types.h"

extern s32 func_8002DF78(void);
extern void func_8003CF74(u8*, s32);
extern void func_8003D120(u8*);
extern void func_8003F294(u8* arg0, s32 arg1);
extern u8 D_8007482C[];

void func_8003A874(u8* obj) {
    obj[0x67] = 1;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = *(s32*)(obj + 0x108);
    *(s32*)(obj + 0x2C) = *(s32*)(obj + 0x144);
    if (((s8*)obj)[0x84] != 0 || (*(u16*)(obj + 0x7C) & 0x100)) {
        obj[0x84] = 1;
        obj[0x86] = 2;
        obj[0x8C] = 1;
    }
    obj[0x8B] = 10;
    func_8003F294(obj, 10);
    if (func_8002DF78() & 4) {
        func_8003CF74(obj,
                      D_8007482C[(func_8002DF78() & 3) + ((s8)obj[2] << 2)]);
    }
    func_8003D120(obj);
    obj[5] = 6;
    obj[6] = 0;
}
