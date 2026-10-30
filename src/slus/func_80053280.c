#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_8002D760();

void func_80053280(u8* obj) {
    func_80017248(obj);
    *(u16*)(obj + 0x42) &= 0x7FFF;
    if (*(s8*)(obj + 0x45) != 0) {
        func_8002D760(obj);
    }
}
