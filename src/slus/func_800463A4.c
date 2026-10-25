#include "types.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void func_800454A8(u8* obj);
extern void func_80046420(u8* obj);

void func_800463A4(u8* obj) {
    if (func_8002D938(obj, 0x2A, 0x22) == 0) {
        func_80017248(obj);
        if (*(s8*)(obj + 1) == 0x14) {
            func_800454A8(obj);
        } else {
            func_80046420(obj);
        }
    } else {
        obj[3] = 0;
        obj[4] = 3;
        *(s32*)(obj + 0x50) = 0;
        *(s32*)(obj + 0x68) = 0;
    }
}
