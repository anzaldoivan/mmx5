#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_80049DC4(u8* obj) {
    u8* src;
    s8 s;
    s8 o;
    u8 c;
    u32 v;

    func_80017248(obj);
    src = *(u8**)(obj + 0x7C);
    if (*(s8*)(src + 4) == 3 || *(s8*)(src + 0) == 0 ||
        *(s8*)(src + 1) != *(s8*)(obj + 1)) {
        obj[4] = 3;
        obj[3] = 0;
        return;
    }
    *(u16*)(obj + 0xA) = *(u16*)(src + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(src + 0xE);
    c = src[0x15];
    o = *(s8*)(obj + 6);
    obj[0x15] = c;
    s = *(s8*)(src + 6);
    v = src[6];
    if (o != s) {
        obj[6] = v;
        v--;
        if ((u8)v < 2) {
            func_800171E8(obj, 4);
        } else if (s == 4) {
            func_800171E8(obj, 5);
        } else if (s == 8) {
            func_800171E8(obj, 6);
        }
    }
    func_8002D9EC(obj, 0x20, 0x20);
}
