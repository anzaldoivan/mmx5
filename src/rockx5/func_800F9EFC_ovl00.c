#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F9EFC_ovl00(u8* obj) {
    if (*(s8*)(*(u8**)(obj + 0x7C) + 7) == 2) {
        obj[4]++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
    func_800317B8(obj);
    if (func_8002D938(obj, 0x20, 0x20) == 0) {
        func_8002D9EC(obj, 0x10, 0x10);
    } else {
        obj[4]++;
    }
}
