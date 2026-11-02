#include "types.h"

extern u8* func_8002D27C(void);
extern void func_8002DED4(u8* obj);
extern s32 func_80038850(u8* self);
extern s32 func_80039AE0(void* self);
extern s32 func_80039D2C(u8* obj);
extern void func_8003B33C(u8* obj, s32 arg1);
extern void func_8003D344(void* arg0);

void func_80043344(u8* obj) {
    u8* child;

    if (obj[0x89] & 8) {
        func_8003B33C(obj, 0x63);
        obj[0x67] = 0;
        obj[0x84] = 0;
        obj[0x86] = 0;
        obj[0x8C] = 0;
        if (*(s8*)(obj + 0xD3) == 0) {
            child = func_8002D27C();
            if (child != 0) {
                child[0] = 1;
                child[1] = 0x3F;
                child[2] = 0;
                child[0x14] = obj[0x14];
                if (obj[0x15] == 0) {
                    *(s16*)(child + 0xA) = *(s16*)(obj + 0xA) - 8;
                } else {
                    *(s16*)(child + 0xA) = *(s16*)(obj + 0xA) + 8;
                }
                *(s16*)(child + 0xE) = *(s16*)(obj + 0xE) + 0x18;
            }
        }
        obj[6]++;
        return;
    }
    obj[0x8E] = 0;
    if (func_80039D2C(obj) == 0 && func_80039AE0(obj) == 0 &&
        func_80038850(obj) == 0) {
        obj[0x8E] = 1;
        *(s32*)(obj + 0x20) = 0;
        if (*(s8*)(obj + 0xD3) == 0) {
            if (*(u16*)(obj + 0x7C) & 2) {
                *(s32*)(obj + 0x20) = 0xFFFE8000;
            }
            if (*(u16*)(obj + 0x7C) & 1) {
                *(s32*)(obj + 0x20) = 0x18000;
            }
        }
        func_8002DED4(obj);
        func_8003D344(obj);
    }
}
