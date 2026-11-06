#include "types.h"
#include "addr.h"

extern void func_80016490(s32, s32, void*);
extern void func_8002D6FC(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8009A0A0[];

void func_80051104(u8* obj) {
    u8* g;
    u8* sp;
    u8 st;
    s32 off;

    g = D_8009A0A0;
    if (((s8*)g)[5] != 0x23) {
        func_8002D6FC(obj);
        return;
    }
    st = obj[4];
    if (((s8*)obj)[4] == 0) {
        sp = D_1F80001C.bytes;
        off = *(s32*)(sp + 0x1C);
        *(s16*)(obj + 0x40) = 0x500;
        *(s16*)(obj + 0x42) = 0x7802;
        obj[0x16] = 3;
        obj[0x5C] = 0;
        obj[4] = st + 1;
        *(u8**)(obj + 0x3C) = sp + off;
    }
    obj[0x47] = g[0x47] - 0x2F;
    obj[0x15] = g[0x15];
    *(s32*)(obj + 8) = *(s32*)(g + 8);
    *(s32*)(obj + 0xC) = *(s32*)(g + 0xC);
    if (((s8*)obj)[0x5C] == 0) {
        obj[0x5C] = 8;
        func_80016490(0, 0x1F, obj);
    } else {
        obj[0x5C]--;
    }
    func_8002D9EC(obj, 0x28, 0x28);
}
