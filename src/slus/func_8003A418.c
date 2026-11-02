#include "types.h"

extern void func_8003CE64(u8* obj);
extern void func_8003D0A0(u8* obj);
extern void func_8003B33C(u8*, s32);
extern void func_80039F1C(u8* a0);
extern s32 func_8002DF78(void);
extern void func_8003CF74(u8*, s32);
extern void func_8003CD08(u8* obj);
extern void func_8003ED10(u8* obj);
extern u8 D_8007482C[];

void func_8003A418(u8* obj) {
    obj[6] = 0;
    obj[5] = obj[0xD1];
    func_8003CE64(obj);
    switch ((s8)obj[5]) {
    case 20:
        if ((u8)(obj[0x17] - 5) >= 2) {
            func_8003D0A0(obj);
        }
        *(s8*)(obj + 0xD0) = -1;
        obj[0x15] = obj[0xD2];
        break;
    case 73:
        if (obj[0x17] != 6) {
            func_8003B33C(obj, 6);
        }
        *(s8*)(obj + 0xD0) = -1;
        obj[0x15] = obj[0xD2];
        break;
    case 21:
        func_8003B33C(obj, 0x26);
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        if (obj[0xD2] == 0) {
            func_80039F1C(obj);
        } else {
            obj[0x15] = 0x40;
        }
        break;
    case 29:
        func_8003B33C(obj, 0x26);
        *(s8*)(obj + 0xD0) = -1;
        *(s32*)(obj + 0x20) = 0x10000;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[0x15] = obj[0xD2];
        if (obj[0x15] == 0) {
            *(s32*)(obj + 0x20) = 0xFFFF0000;
        }
        break;
    case 30:
        func_8003B33C(obj, 0x26);
        obj[0x67] = 1;
        *(s32*)(obj + 0x20) = 0x20000;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0x2E800;
        *(s32*)(obj + 0x2C) = 0x840;
        obj[6] = 0;
        func_8003CF74(obj,
                      D_8007482C[(func_8002DF78() & 3) + ((s8)obj[2]) * 4]);
        func_8003B33C(obj, 10);
        obj[0x15] = obj[0xD2];
        break;
    case 22:
        func_8003B33C(obj, 3);
        *(s8*)(obj + 0xD0) = -1;
        obj[0x15] = obj[0xD2];
        break;
    case 23:
        func_8003B33C(obj, 10);
        func_8003CD08(obj);
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        obj[0x67] = 1;
        *(s32*)(obj + 0x24) = *(s32*)(obj + 0x108);
        *(s32*)(obj + 0x2C) = *(s32*)(obj + 0x110);
        obj[0x15] = obj[0xD2];
        break;
    case 24:
        if (((s8*)obj)[2] != 0) {
            func_8003B33C(obj, 5);
        } else {
            func_8003B33C(obj, 0x6B);
        }
        func_8003ED10(obj);
        obj[0x15] = obj[0xD2];
        break;
    case 31:
        obj[7] = 0;
        obj[0x15] = obj[0xD2];
        break;
    }
}
