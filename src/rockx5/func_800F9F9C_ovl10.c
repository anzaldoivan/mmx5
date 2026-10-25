#include "types.h"

extern void func_800F9E98_ovl10(u8* obj);
extern void func_80017248(u8* obj);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern int func_8002D7A0();

void func_800F9F9C_ovl10(u8* obj) {
    if (*(s8*)(obj + 4) == 0) {
        func_800F9E98_ovl10(obj);
    } else {
        func_80017248(obj);
        if (func_8002D938(obj, 0x80, 0x80) == 0) {
            func_8002D9EC(obj, 0x80, 0x80);
        } else {
            func_8002D7A0(obj);
        }
    }
}
