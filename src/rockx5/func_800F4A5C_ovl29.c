#include "types.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D1A4();
extern void func_800171E8(u8* obj, s32 state, s32 row);
extern u8 D_800FA2E0_ovl29[][6];

void func_800F4A5C_ovl29(u8* obj) {
    u8* child;
    s32 row;

    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x30;
            child[1] = 0x29;
            child[2] = 2;
            *(u8**)(child + 0x7C) = obj;
        }
        *(u8**)(obj + 0x80) = child;
        obj[0x45] = 0;
    }
    if (*(s8*)(obj + 0x45) == 2) {
        (*(u8**)(obj + 0x80))[6]++;
        obj[0x45] = 0;
    }
    if (*(s8*)(obj + 0x46) == 0) {
        row = obj[0x8D];
        obj[5] = D_800FA2E0_ovl29[row][obj[0x8E]];
        obj[0x8E]++;
        obj[6] = 0;
        func_800171E8(obj, 0, row);
    }
}
