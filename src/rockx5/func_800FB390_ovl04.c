#include "types.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D1A4(s32);
extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_800D1C00[];

void func_800FB390_ovl04(u8* obj) {
    s8 flag;
    s8 state;
    u8* spawn;
    u8* p;

    func_80017248(obj);
    flag = obj[0x45];
    if (flag & 0x80) {
        obj[0x45] &= 0x7F;
        spawn = func_8002D1A4(flag);
        if (spawn != 0) {
            spawn[0] = 0x41;
            spawn[1] = 0xB;
            *(u8**)(spawn + 0x7C) = obj;
            spawn[2] = 2;
        }
        func_80016490(2, 0x14, obj);
    } else if (flag == 1) {
        state = obj[2];
        if (state == 12) {
            func_800171E8(obj, 0xD);
        } else if (state == 13) {
            func_800171E8(obj, 0xE);
        } else if (state == 14) {
            func_800171E8(obj, 0xF);
        } else if (state == 15) {
            func_800171E8(obj, 0x10);
        }
        p = D_800D1C00;
        p[0x28] &= obj[0x95];
        p[0x29] &= obj[0x96];
        obj[5]--;
    }
    func_8002D9EC(obj, 0x10, 0x10);
}
