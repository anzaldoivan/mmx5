#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D89C(u8*);
extern void func_8002DED4(u8* obj);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);

void func_800F67C8_ovl26(u8* p) {
    s32 a;
    s32 b;

    func_80017248(p);
    func_8002D89C(p);
    b = ((s8*)p)[2];
    if (b == 0) {
        b = ((s8*)p)[0x45];
        a = 1;
    } else {
        *(u16*)(p + 0x42) = *(u16*)(*(u8**)(p + 0x50) + 0x42);
        func_8002DED4(p);
        a = func_8002D938(p, 0x20, 0x20);
        b = 1;
    }
    if (a == b) {
        p[4] = 2;
    }
}
