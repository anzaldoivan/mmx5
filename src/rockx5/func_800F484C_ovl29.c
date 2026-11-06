#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8* func_8002D1A4();
extern void func_80016490();
extern u8 D_800FA2DC_ovl29[];

void func_800F484C_ovl29(u8* obj) {
    s8 state;
    u8* spawn;

    func_80017248(obj);
    state = *(s8*)(obj + 0x45);
    if (state != 0) {
        if (state == 10) {
            *(s16*)(obj + 0x7C) = 0xF0;
            obj[6]++;
        }
        func_8004D4F4(4, D_800FA2DC_ovl29, obj);
        spawn = func_8002D1A4();
        if (spawn != 0) {
            spawn[0] = 0x41;
            spawn[1] = 0x29;
            spawn[2] = 1;
            *(u8**)(spawn + 0x7C) = obj;
            if (*(s8*)(obj + 0x45) == 10) {
                *(u8**)(obj + 0x80) = spawn;
                spawn[7] = 1;
            } else {
                spawn[7] = obj[0x45] - 1;
            }
        }
        if (obj[0x45] & 1) {
            func_80016490(2, 0xAE, spawn);
        } else {
            func_80016490(2, 0xAE);
        }
        obj[0x45] = 0;
    }
}
