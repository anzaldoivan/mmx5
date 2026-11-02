#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D6FC(u8* obj);
extern void func_8002D7A0(u8* obj);
extern s32 func_8002D800(u8* a0);
extern void func_8002D89C(u8* obj);
extern void func_8002DED4();
extern void func_80054000(u8* obj);
extern s32 D_8009A420;

void func_8005388C(u8* obj) {
    s32 v;
    s32 t;

    if (obj[0x85] == 0) {
        if (*(s8*)(obj + 0x67) != 0) {
            if (obj[0x70] & 8) {
                if (*(s8*)(obj + 0x6) == 0) {
                    v = *(s32*)(obj + 0x24);
                    obj[0x6] = 1;
                    *(s32*)(obj + 0x2C) = 0x8000;
                    *(s32*)(obj + 0x24) = __builtin_abs(v) >> 1;
                    func_8002DED4();
                } else {
                    obj[0x6] = 0;
                    obj[0x67] = 0;
                }
            } else {
                func_8002DED4(obj);
            }
        } else {
            if (!(obj[0x70] & 8)) {
                obj[0x6] = 0;
                *(s32*)(obj + 0x24) = 0;
                *(s32*)(obj + 0x2C) = 0x8000;
                obj[0x67] = 1;
            }
            func_80017248(obj);
        }
    } else {
        func_80017248(obj);
    }
    if (*(s32*)(obj + 0x10) == 0) {
        t = *(u16*)(obj + 0x80) - 1;
        *(u16*)(obj + 0x80) = t;
        if ((t & 0xFFFF) == 0) {
            obj[0x4] = 3;
            return;
        }
    }
    func_80054000(obj);
    if (func_8002D800(obj) != 0) {
        if (*(s32*)(obj + 0x10) != 0) {
            if (*(s8*)(obj + 0x2) == 0x29) {
                func_8002D6FC(obj);
                return;
            }
            func_8002D7A0(obj);
            return;
        }
        obj[0x4] = 3;
        obj[0x5] = 0;
        return;
    }
    obj[0x3] = 0;
    if (*(u16*)(obj + 0x80) >= 0x3C || !(D_8009A420 & 1)) {
        func_8002D89C(obj);
    }
}
