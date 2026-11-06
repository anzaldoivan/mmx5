#include "types.h"

extern s32 func_800317B8(u8* a0);
extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* obj);
extern void func_80016490(s32, s32, void*);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s16 D_8009A206;

void func_800F746C_ovl29(u8* p) {
    s32 t;

    func_800317B8(p);
    func_8002DF54(p);
    func_80017248(p);
    if (*(s16*)(p + 0xE) - D_8009A206 < 0x78) {
        *(s32*)(p + 0x24) = 0;
    }
    t = *(u16*)(p + 0x88) - 1;
    *(u16*)(p + 0x88) = t;
    if ((t << 16) == 0) {
        *(s32*)(p + 0x68) = 0;
        *(s32*)(p + 0x24) = 0xFFFC0000;
        p[6]++;
    }
    if (*(s8*)(p + 0x45) == 1) {
        func_80016490(2, 0xAE, p);
    }
    if (*(s8*)(p + 0x45) == 2) {
        func_80016490(2, 0xAE, p);
    }
    func_8002D9EC(p, 0x30, 0x80);
}
