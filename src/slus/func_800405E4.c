#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8003AA4C(u8* arg0);
extern void (*D_80074D54[])(u8*);

void func_800405E4(u8* obj) {
    func_80017248(obj);
    D_80074D54[((s8*)obj)[6]](obj);
    if (((s8*)obj)[5] != 0x29 || ((s8*)obj)[0x93] != 8) {
        func_8003AA4C(obj);
    }
}
