#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_80091C44;
extern u8 D_800D1C00[];
extern u8 D_8009A1F8[];

void func_800FA38C_ovl28(u8* obj) {
    u8* p;
    u8* q;

    func_80017248(obj);
    func_8002D9EC(obj, 0x30, 0x30);
    if (D_80091C44 == 0) {
        p = D_800D1C00;
        q = D_8009A1F8;
        p[0xF] = 0x10;
        p[0x24] = 0;
        *(s32*)(p + 0x20) = 0;
        *(u16*)(q + 0x2A) = *(u16*)(q + 0xE);
    }
}
