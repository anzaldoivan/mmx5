#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_80016490(s32, s32, void*);

void func_800F6CFC_ovl28(u8* obj) {
    func_80017248(obj);
    func_800317B8(obj);
    func_8002D9EC(obj, 0xC0, 0x40);
    if (*(s8*)(obj + 0x45) == 1) {
        func_80016490(2, 0x77, obj);
        obj[5]++;
    }
}
