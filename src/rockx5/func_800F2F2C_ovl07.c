#include "types.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D078();
extern u8 D_80101028_ovl07[];
extern u8 D_8009A0B4;

void func_800F2F2C_ovl07(u8* obj) {
    u8* child;

    func_80017248(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        *(u8**)(obj + 0x50) = D_80101028_ovl07;
        child = func_8002D078();
        if (child != 0) {
            child[0] = 1;
            child[1] = 0x37;
            if (*(s8*)(obj + 0x66) > 0) {
                child[2] = 1;
            } else {
                child[2] = 2;
            }
            child[0x14] = D_8009A0B4;
            *(u8**)(child + 0x7C) = obj;
            *(u16*)(child + 0xA) = *(u16*)(obj + 0xA);
            *(u16*)(child + 0xE) = *(u16*)(obj + 0xE);
        }
        obj[6] = 0;
    }
}
