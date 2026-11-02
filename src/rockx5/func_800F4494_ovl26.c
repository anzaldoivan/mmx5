#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D1A4();
extern void func_800171E8(u8* obj, s32 state);
extern s8 D_800FA683_ovl26;

void func_800F4494_ovl26(u8* obj) {
    u8* child;

    func_80017248(obj);
    if (obj[0x47] == 0x31 && D_1F80004C.bytes[0x93] == 0) {
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x17;
            child[2] = 0x11;
            *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            if (D_1F80004C.bytes[0x96] == 0) {
                child[0x15] = 0;
                *(u16*)(child + 0xA) = 0xA10;
            } else {
                child[0x15] = 0x40;
                *(u16*)(child + 0xA) = 0x910;
            }
            *(s32*)(child + 0xC) = *(s32*)(obj + 0xC);
            *(u8**)(child + 0x7C) = obj;
        }
        D_1F80004C.bytes[0x93] = 1;
    }
    if (*(s8*)(obj + 0x45) == 1) {
        func_800171E8(obj, 7);
        *(s32*)(obj + 0x2C) = 0x4000;
        *(s32*)(obj + 0x24) = 0;
        obj[6]++;
        D_800FA683_ovl26 = 0;
    }
}
