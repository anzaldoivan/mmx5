#include "types.h"
#include "addr.h"

extern void func_8001296C(s32);
extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002A600(s32, s32, s32);
extern u8* func_8002C938();
extern void func_8002DED4(u8* obj);

void func_800F598C_ovl26(u8* obj) {
    u8* p;
    u8 b;
    u16 e;

    func_80017248(obj);
    func_8002DED4(obj);
    if (obj[0x70] & 8) {
        func_8001296C(5);
        func_80016490(2, 0x63, obj);
        p = func_8002C938();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x3A;
            p[2] = 2;
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(s16*)(p + 0x40) = *(s16*)(obj + 0x40);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(s16*)(p + 0x42) = *(s16*)(obj + 0x42) & 0x7FFF;
            p[0x5C] = obj[0x5C];
            b = obj[0x15];
            p[0x15] = b;
            if (b == 0) {
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) + 0xE;
            } else {
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) - 0xE;
            }
            e = *(u16*)(obj + 0xE);
            *(u8**)(p + 0x80) = obj;
            *(s16*)(p + 0xE) = e - 0x1E;
            D_1F80004C.bytes[0x92] = 1;
        }
        func_8002A600(0x32, 4, 1);
        obj[6]++;
        func_800171E8(obj, 0x14);
    }
}
