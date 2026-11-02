#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D1A4();
extern s16 D_8009A0AA;

void func_800F9864_ovl28(u8* obj) {
    u8* p;

    if (*(s8*)(obj + 0x45) == 1) {
        func_80016490(2, 0x91, obj);
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x24;
            p[2] = 3;
            *(u8**)(p + 0x7C) = obj;
        }
    }
    if (*(s8*)(obj + 0x46) == 0) {
        func_800171E8(obj, 2);
    }
    if (*(s8*)(obj + 7) == 2) {
        func_800171E8(obj, 4);
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        obj[6]++;
    }
}
