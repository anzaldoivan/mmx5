#include "types.h"

extern s32 func_80041C80(u8* p);
extern s32 func_80044228(u8* p);
extern s32 func_80041B84(u8* p);

s32 func_800437FC(u8* p) {
    if (((s8*)p)[2] == 0) {
        return 0;
    }
    if (((s8*)p)[0xD3] != 0) {
        return 0;
    }
    p[0x156] = 1;
    if (func_80041C80(p) != 0) {
        return 1;
    }
    if (func_80044228(p) != 0) {
        return 1;
    }
    if (func_80041B84(p) != 0) {
        return 1;
    }
    p[0x156] = 0;
    return 0;
}
