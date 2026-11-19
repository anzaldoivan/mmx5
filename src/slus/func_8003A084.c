#include "types.h"

extern u8 func_800306E0(u8*);
extern void func_8003A94C(u8* obj);
extern void func_8003A874(u8*);

s32 func_8003A084(u8* obj) {
    u8 t;

    if (*(s8*)(obj + 0xD0) > 0) {
        func_8003A94C(obj);
        return 1;
    }
    t = func_800306E0(obj) - 0x25;
    if (t >= 0xB) {
        obj[0xF6] = 4;
        func_8003A94C(obj);
        return 1;
    }
    if (*(u16*)(obj + 0x80) & 0x80) {
        if (*(u16*)(obj + 0x7C) & 8) {
            func_8003A94C(obj);
        } else {
            func_8003A874(obj);
        }
        obj[0xF6] = 4;
        return 1;
    }
    return 0;
}
