#include "types.h"

extern void func_8003A9AC(void);
extern void func_8002DED4(u8* obj);
extern s32 func_800439A8(u8* obj);
extern void func_8003B33C(u8*, s32);

void func_80044810(u8* arg0) {
    if (arg0[0x89] & 8) {
        func_8003A9AC();
        return;
    }
    func_8002DED4(arg0);
    if (func_800439A8(arg0) != 0) {
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        *(s8*)(arg0 + 0x67) = -1;
        arg0[0x84] = 0;
        *(s32*)(arg0 + 0x2C) = *(s32*)(arg0 + 0x110);
        return;
    }
    if (*(s8*)(arg0 + 0x46) < 0) {
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        *(s8*)(arg0 + 0x67) = -1;
        arg0[0x84] = 0;
        *(s8*)(arg0 + 0x8C) = -1;
        *(s32*)(arg0 + 0x2C) = *(s32*)(arg0 + 0x110);
        func_8003B33C(arg0, 0x13);
        arg0[6]++;
    }
}
