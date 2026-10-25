#include "types.h"

extern void func_80017248(u8* obj);
extern void (*D_80074D88[])(u8* obj);

void func_80043E78(u8* obj) {
    func_80017248(obj);
    if (((s8*)obj)[6] != 0) {
        obj[0x4F]++;
    }
    if (obj[0x4B] == 0xFF && !(*(u16*)(obj + 0x7C) & 0x10)) {
        obj[0x4B] = obj[0x4F];
    }
    D_80074D88[((s8*)obj)[6]](obj);
}
