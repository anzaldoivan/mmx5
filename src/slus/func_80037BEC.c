#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8003B33C(u8*, s32);
extern void func_8003CE64(u8* obj);
extern void func_8003D0A0(u8* obj);

void func_80037BEC(u8* obj) {
    if (((s8*)obj)[6] == 0) {
        func_80017248(obj);
        func_8002DED4(obj);
        if (*(s32*)(obj + 0x24) <= 0) {
            func_8003B33C(obj, 0xB);
            ((s8*)obj)[0x67] = -1;
            *(s32*)(obj + 0x24) = 0;
            obj[6]++;
        }
    } else if (obj[0x89] & 8) {
        func_8003CE64(obj);
        func_8003D0A0(obj);
        obj[0x67] = 0;
        ((s8*)obj)[0xD0] = -1;
        obj[5] = 0x14;
        obj[6] = 0;
    } else {
        func_80017248(obj);
        func_8002DED4(obj);
    }
}
