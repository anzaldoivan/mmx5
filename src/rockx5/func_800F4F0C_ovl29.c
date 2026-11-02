#include "types.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D1A4();
extern void func_80016490();
extern u8 D_800FA2E0_ovl29[][6];

void func_800F4F0C_ovl29(u8* obj) {
    u8* child;
    s16 x;

    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x29;
            child[2] = 3;
            *(u8**)(child + 0x7C) = obj;
            x = *(s16*)(obj + 0xA);
            *(s16*)(child + 0xA) = obj[0x15] != 0 ? x + 0x17 : x - 0x17;
            *(s16*)(child + 0xE) = *(s16*)(obj + 0xE);
            func_80016490(2, 0xAB, obj, child);
            func_80016490(2, 0xB0, obj);
        }
        obj[0x45] = 0;
    }
    if (*(s8*)(obj + 0x46) == 0) {
        obj[5] = D_800FA2E0_ovl29[obj[0x8D]][obj[0x8E]];
        obj[0x8E]++;
        obj[6] = 0;
    }
}
