#include "types.h"

extern s32 func_8003E6FC(void*, s8);
extern void func_8003CE10(u8*);
extern void func_8003B33C(u8*, s32);
extern void func_8003CF74(u8*, s32);
extern void func_8003C5D8(u8* obj);
extern void func_80043678(u8* obj);

s32 func_80041C80(u8* obj) {
    u16 flags;
    s32 go;
    s32 t;
    s32 m;

    if (!(obj[0xC9] & 0x20)) {
        return 0;
    }
    if (*(s8*)(obj + 0xA6) == 0) {
        t = func_8003E6FC(obj, 2);
        if (*(s16*)(obj + 0xAC) < t) {
            return 0;
        }
        if (*(s8*)(obj + 0x8E) != 0) {
            return 0;
        }
        flags = *(u16*)(obj + 0x80);
        m = flags & 0x40;
        go = m != 0;
        if (*(s8*)(obj + 0x93) == 2 && (flags & 0x20)) {
            go = 1;
        }
        if (go != 0) {
            obj[0x93] = 2;
            obj[0x156] = 1;
            obj[0x8E] = 1;
            obj[0xCB] = 0;
            obj[0x8C] = 0;
            func_8003CE10(obj);
            func_8003B33C(obj, 0x67);
            func_8003CF74(obj, 7);
            obj[0x61] = 0;
            obj[0xA4] = 0;
            func_8003C5D8(obj);
            obj[0x67] = 1;
            obj[0x7A] = 1;
            *(s16*)(obj + 0xAC) = *(u16*)(obj + 0xAC) - func_8003E6FC(obj, 2);
            obj[0x5] = 0x3A;
            obj[0x6] = 0;
            func_80043678(obj);
            return 1;
        }
    }
    return 0;
}
