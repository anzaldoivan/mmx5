#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_80047B28(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        func_8002DED4(obj);
    }
    func_8002D9EC(obj, 0x40, 0x40);
    if (*(s8*)(obj + 3) == 0) {
        obj[4]++;
    }
}
