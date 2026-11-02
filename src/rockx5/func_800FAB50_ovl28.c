#include "types.h"

void func_800171E8(u8* obj, s32 state);
void func_8002D9EC(u8* a0, s32 a1, s32 a2);
void func_80017248(u8* obj);
void func_8002DF54(u8* a0);

void func_800FAB50_ovl28(u8* o) {
    u8* p;
    u8* q;
    s8 t;
    s32 st;

    p = *(u8**)(o + 0x7C);
    o[0x15] = p[0x15];
    if (o[0x15] == 0) {
        *(u16*)(o + 0xA) = *(u16*)(p + 0xA) + 0x1E;
    } else {
        *(u16*)(o + 0xA) = *(u16*)(p + 0xA) - 0x1E;
    }
    q = *(u8**)(o + 0x7C);
    *(u16*)(o + 0xE) = *(u16*)(q + 0xE) + 8;
    st = (s8)o[5];
    switch (st) {
    case 0:
        if ((s8)q[0x45] == 9) {
            func_800171E8(o, 0x13);
            o[5]++;
        }
        break;
    case 1:
        if (__builtin_abs(*(s32*)(q + 0x20)) != 0x42000 ||
            ((s8*)o)[0x46] == 0) {
            o[5]--;
        }
        func_8002D9EC(o, 0x20, 0x20);
        func_80017248(o);
        func_8002DF54(o);
        break;
    }
    t = (*(u8**)(o + 0x7C))[4];
    if (t == 2) {
        o[4] = t;
    }
}
