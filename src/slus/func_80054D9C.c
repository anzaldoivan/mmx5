#include "types.h"

extern void func_8003CD08(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80016490(s32, s32, void*);
extern u8 D_8009A1F8[];
extern u8 D_800D1C28;
extern s32 D_800E92F8;

void func_80054D9C(u8* obj, s32 arg1, u8* other) {
    s8 t;
    u8* p;

    *(s32*)(other + 8) += *(s32*)(obj + 0x84);
    if (*(s8*)(obj + 2) == 1) {
        u8* q = D_8009A1F8;
        *(u16*)(q + 0x94) -= 4;
    }
    p = D_8009A1F8;
    if (*(s16*)(p + 0xA) == *(s16*)(p + 0x26)) {
        other[0xD4] = 0;
        func_8003CD08(other);
        obj[5] = 4;
        func_800171E8(obj, 1);
        func_80016490(0, 0x11, obj);
        t = *(s8*)(obj + 2);
        if (t == 6 || t == 10) {
            D_800E92F8 = 1;
        } else if (t == 9) {
            D_800D1C28 = 1;
        }
        {
            u8* r = D_8009A1F8;
            r[0x47] = obj[0x80];
        }
    }
}
