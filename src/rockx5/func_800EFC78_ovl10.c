#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80016490(s32, s32, void*);
extern u8 D_800FB364_ovl10[];
extern u8 D_800FB370_ovl10[];

void func_800EFC78_ovl10(u8* obj) {
    s8 ev;

    func_80017248(obj);
    ev = *(s8*)(obj + 0x45);
    if (ev == 1) {
        if (*(s8*)(obj + 2) != 0) {
            *(u8**)(obj + 0x68) = D_800FB364_ovl10;
            func_800171E8(obj, 4);
        } else {
            *(u8**)(obj + 0x68) = D_800FB370_ovl10;
            func_800171E8(obj, 1);
        }
        obj[6]++;
    } else if (ev == 10) {
        func_80016490(2, 0x5D, obj);
    } else if (ev == 20) {
        func_80016490(2, 0x5E, obj);
    }
}
