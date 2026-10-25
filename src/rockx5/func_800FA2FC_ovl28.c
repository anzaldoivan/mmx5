#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8002385C(s32, s32, s32);
extern u16 D_800D50DE;

void func_800FA2FC_ovl28(u8* obj) {
    func_80017248(obj);
    func_8002D9EC(obj, 0x30, 0x30);
    if (((s8*)obj)[0x45] == 1 && D_800D50DE == 0) {
        if (((s8*)obj)[2] == 0) {
            func_8002385C(0x45, 0xFF, 0);
        } else {
            func_8002385C(0x47, 0xFF, 0);
        }
        obj[5] = 5;
    }
}
