#include "types.h"

extern u8* func_8002D27C(void);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800FB7F8_ovl10[];

void func_800F4ED8_ovl10(u8* obj) {
    s16 t;
    s32 mask;
    u8* c;

    t = *(s16*)(obj + 0x7C);
    mask = 7;
    if (t < 0x28) {
        mask = 0x3F;
    }
    if (!(t & mask)) {
        c = func_8002D27C();
        if (c != 0) {
            c[0] = 0x41;
            c[1] = 0x23;
            c[2] = 0;
            *(s32*)(c + 0x3C) = *(s32*)(obj + 0x3C);
            *(s16*)(c + 0x40) = *(s16*)(obj + 0x40);
            *(s32*)(c + 0x30) = *(s32*)(obj + 0x30);
            *(s16*)(c + 0x42) = *(s16*)(obj + 0x42);
            c[0x15] = obj[0x15];
        }
    }
    if (*(s16*)(obj + 0x7C) != 0) {
        (*(s16*)(obj + 0x7C))--;
    }
    func_80017248(obj);
    func_8002DED4(obj);
    if (*(s32*)(obj + 0x24) < 0) {
        *(u8**)(obj + 0x68) = D_800FB7F8_ovl10;
    }
    if (obj[0x70] & 8) {
        func_800171E8(obj, 0x1A);
        obj[6] = 4;
    }
}
