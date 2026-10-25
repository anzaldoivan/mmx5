#include "types.h"

extern void func_80017248(u8* obj);
extern int func_8002D6FC();
extern s8 D_8009A0A5;

void func_80046900(u8* obj) {
    u8* p = *(u8**)(obj + 0x50);

    *(u16*)(obj + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
    func_80017248(obj);
    if (*(s8*)p == 0 || *(s8*)(p + 4) >= 2 || D_8009A0A5 == 20) {
        func_8002D6FC(obj);
    }
}
