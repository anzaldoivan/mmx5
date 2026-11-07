#include "types.h"

extern u8* func_8002D1A4();
extern void func_8001296C(s32);
extern void func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void func_800F9520_ovl00(u8* obj) {
    u8* p;
    s32 t;
    s16 c;

    t = *(u16*)(obj + 0x7C) - 1;
    *(u16*)(obj + 0x7C) = t;
    if ((t << 16) == 0) {
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x61;
            p[1] = 3;
            p[2] = 3;
            *(u8**)(p + 0x7C) = obj;
            func_8001296C(2);
            func_80016490(2, 2, obj);
        }
        obj[7] = 0;
        obj[6]++;
    }
    c = *(s16*)(obj + 0x7C);
    if (c == 30) {
        *(s32*)(obj + 0x24) = 0x20000;
    } else if (c < 30 &&
               !(*(volatile u16*)(obj + 0x7C) &
                 1)) { // !FAKE: volatile keeps the lhu after the slti test
        *(s32*)(obj + 0x24) = -*(s32*)(obj + 0x24);
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
