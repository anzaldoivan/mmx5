#include "types.h"

extern void func_8003CD08(u8* obj);
extern s8 D_800D1C1C;

void func_80041330(u8* obj) {
    if (*(s8*)(obj + 0x46) == 0) {
        if (*(s8*)(obj + 0xD0) == 0) {
            obj[0x7A] = 0;
            D_800D1C1C = 0;
        }
        obj[0xF3] = 0;
        func_8003CD08(obj);
        obj[6]++;
    }
}
