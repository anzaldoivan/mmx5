#include "types.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern void func_8002DF54(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F6D64_ovl28(u8* obj) {
    u8* p;

    if (func_8002D938(obj, 0xF0, 0x60) == 0) {
        func_80017248(obj);
        func_800317B8(obj);
        func_8002DF54(obj);
        func_8002D9EC(obj, 0xC0, 0x40);
    } else {
        if ((obj[2] >> 4) == 1) {
            p = *(u8**)(obj + 0x7C);
            p[0x8C]++;
        }
        obj[4]++;
    }
    if (*(signed char*)(*(u8**)(obj + 0x7C) + 4) == 2) {
        obj[4] = 2;
    }
}
