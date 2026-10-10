#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern u8* func_8002D144(void);
extern void func_8002D9EC(u8* obj, s32 a, s32 b);

#define S16(p, o) (*(s16*)((p) + (o)))
#define U16(p, o) (*(u16*)((p) + (o)))
#define S8(p, o) (*(signed char*)((p) + (o)))
#define G (*(u8**)0x1F80004C)

void func_800F4F20_ovl28(u8* obj) {
    u8* child;
    s16 r;
    s32 v;

    func_80017248(obj);
    func_8002DED4(obj);
    if (!(obj[0x70] & 8)) {
        return;
    }
    if (--S16(obj, 0x7C) == 0) {
        obj[5] = 2;
        child = func_8002D144();
        if (child != 0) {
            child[0] = 1;
            child[1] = 0x1A;
            U16(child, 0xA) = U16(obj, 0xA);
            U16(child, 0xE) = U16(obj, 0xE);
            *(u8**)(G + 0x80) = child;
        }
    }
    func_8002D9EC(obj, 0x60, 0x60);
    if (S16(obj, 0x7E)-- != 0) {
        return;
    }
    U16(obj, 0x42) ^= 0x8000;
    S8(obj, 0x61) -= 5;
    if (S8(obj, 0x61) >= 0x1A) {
        S8(obj, 0x61) = 0;
    }
    v = S8(obj, 0x61);
    if (v >= 6) {
        r = v;
    } else {
        r = 5;
    }
    S16(obj, 0x7E) = r;
}
