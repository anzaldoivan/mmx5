#include "types.h"

extern void func_8003A94C(u8* obj);
extern s32 func_8003EFE0(u8* arg0);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8003D344(void* arg0);
extern void func_8003F2D8(u8* arg0, s32 arg1);

void func_800365F0(u8* obj) {
    s32 hit;
    s32 m;
    s32 b;
    u8 f;

    if (((s8*)obj)[0xD3] != 0) {
        func_8003A94C(obj);
        return;
    }
    if (func_8003EFE0(obj) != 0) {
        return;
    }
    f = obj[0x89];
    b = f & 4;
    hit = b != 0;
    if (obj[0x15] != 0) {
        m = f & 2;
    } else {
        m = f & 1;
    }
    if (m != 0) {
        hit = 1;
    }
    if (hit != 0) {
        func_8003A94C(obj);
        return;
    }
    func_80017248(obj);
    func_8002DED4(obj);
    func_8003D344(obj);
    if (--((s8*)obj)[0x8A] == 0) {
        *(s32*)(obj + 0x20) = 0;
        obj[6]++;
        return;
    }
    func_8003F2D8(obj, 0xE);
}
