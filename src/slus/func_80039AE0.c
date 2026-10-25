#include "types.h"

extern s32 func_80039B50(u8* arg0);
extern s32 func_80039BA8(u8* arg0);
extern void func_8003ACF0(u8* arg0);

s32 func_80039AE0(u8* arg0) {
    if (*(s8*)(arg0 + 0xD3) != 0) {
        return 0;
    }
    if ((arg0[0x89] & 3) == 0) {
        return 0;
    }
    if (func_80039B50(arg0) != 0) {
        return 1;
    }
    if (func_80039BA8(arg0) == 0) {
        return 0;
    }
    func_8003ACF0(arg0);
    return 1;
}
