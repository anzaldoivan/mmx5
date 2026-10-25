#include "types.h"

extern s32 func_800305EC(u8* obj);
extern void func_8003AF74(u8* obj);
extern s32 func_80030918(u8* obj);
extern void func_8003B040(u8* obj);

s32 func_80039C80(u8* obj) {
    if (*(s8*)(obj + 0xD3) != 0) {
        return 0;
    }
    if (obj[0x92] != 0) {
        return 0;
    }
    if ((*(u16*)(obj + 0x7C) & 4) && func_800305EC(obj) == 0x20) {
        func_8003AF74(obj);
        return 1;
    }
    if (*(u16*)(obj + 0x7C) & 8) {
        if (func_80030918(obj) == 0x21) {
            func_8003B040(obj);
            return 1;
        }
    }
    return 0;
}
