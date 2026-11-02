#include "types.h"

extern void func_8003763C(u8* arg0);
extern void func_8003D344(void* arg0);
extern void func_8003A670(u8* arg0);
extern void func_8003B33C(u8*, s32);
extern void func_8003A94C(u8* obj);
extern void func_8003CFA8(u8* arg0);

void func_800373D0(u8* obj) {
    func_8003763C(obj);
    func_8003D344(obj);
    if (*(s8*)(obj + 6) == 0) {
        obj[6] = obj[6] + 1;
        return;
    }
    if (*(s8*)(obj + 0x67) != 0 && (obj[0x89] & 8)) {
        obj[0x67] = 0;
        if (obj[0x15] != 0) {
            *(s32*)(obj + 0x20) = -0x8000;
        } else {
            *(s32*)(obj + 0x20) = 0x8000;
        }
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
    }
    if (*(s8*)(obj + 0x61) == 0x3C) {
        if (obj[0x89] & 8) {
            obj[0x67] = 0;
            func_8003A670(obj);
        } else if (*(s32*)(obj + 0x2C) != 0) {
            func_8003B33C(obj, 0xB);
            *(s8*)(obj + 0x67) = -1;
            obj[5] = 7;
            obj[6] = 0;
        } else {
            func_8003A94C(obj);
        }
        if (*(s8*)(obj + 0xD3) != 0) {
            obj[0xA4] = 0;
            obj[0x61] = 0;
            return;
        }
        func_8003CFA8(obj);
        *(s8*)(obj + 0xA4) = -1;
    }
}
