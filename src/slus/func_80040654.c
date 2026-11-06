#include "types.h"

extern void func_8003B33C(u8*, s32);
extern void func_8002DED4(u8* obj);
extern void func_8003AA4C(u8* arg0);

void func_80040654(u8* obj) {
    if (*(s8*)(obj + 6) != 0) {
        if (obj[0x89] & 8) {
            *(s8*)(obj + 6) = 0;
            *(s32*)(obj + 0x24) = 0;
            *(s32*)(obj + 0x2C) = *(s32*)(obj + 0x110);
            if (obj[0x17] != 0x6C) {
                func_8003B33C(obj, 0x58);
            }
        } else {
            func_8002DED4(obj);
        }
    } else if (obj[0x89] & 8) {
        *(s8*)(obj + 6) = 1;
    }
    if (*(s8*)(obj + 7) != 0 || *(s8*)(obj + 0x93) != 6 ||
        *(s8*)(obj + 0x99) == 0 || *(s8*)(obj + 0x98) == 0) {
        func_8003AA4C(obj);
    }
}
