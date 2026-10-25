#include "types.h"

extern s32 func_800317B8(u8* a0);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F6C3C_ovl28(u8* obj) {
    u8* p;

    if ((u16)(*(u16*)(obj + 0xA) - 0x18E1) < 0x18F) {
        func_800317B8(obj);
        func_80017248(obj);
        func_8002DF54(obj);
        func_8002D9EC(obj, 0x20, 0x14);
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
