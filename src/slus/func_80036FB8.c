#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8003CD08(u8* obj);
extern void func_8003A70C(u8* obj);

void func_80036FB8(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) & 0x80) {
        *(s8*)(obj + 0x45) = 0;
        *(s16*)(obj + 0xE) -= 0x10;
        *(s16*)(obj + 0x1E) = *(s16*)(obj + 0xE) - 0x10;
        func_8003CD08(obj);
    }
    if (*(s8*)(obj + 0x46) < 0) {
        obj[0x67] = 0;
        func_8003A70C(obj);
    }
}
