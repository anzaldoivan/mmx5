#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8002DF54(u8* a0);
extern u8* func_8003D3A8(s32, s32, s32, u8*);

void func_8004815C(u8* obj) {
    s8 v;
    s32 t;
    u8* p;

    func_80017248(obj);
    if (!(obj[2] & 0x3F)) {
        if (func_8002D938(obj, 0xA0, 0xA0) == 0) {
            func_8002DF54(obj);
            func_8002D9EC(obj, 0x20, 0x20);
        } else {
            obj[3] = 0;
            obj[4] = 2;
        }
    } else {
        p = *(u8**)(obj + 0x7C);
        v = ((s8*)p)[4];
        if (v == 2) {
            obj[3] = 0;
            obj[4] = v;
        } else {
            func_8002DF54(obj);
        }
        func_8002D9EC(obj, 0x20, 0x20);
    }
    if (obj[0x8D] != 0) {
        obj[0x8D]--;
    }
    if (obj[0x8C] == 0 && obj[0x8D] == 0) {
        t = obj[2];
        obj[0x8C] = 1;
        if ((t & 0x3F) < 4) {
            p = func_8003D3A8(((s8*)obj)[0], ((s8*)obj)[1], (s8)(t + 1), obj);
            if (p != 0) {
                *(s32*)(p + 8) = *(s32*)(obj + 8);
                *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
                p[0x15] = obj[0x15];
            }
        }
    }
}
