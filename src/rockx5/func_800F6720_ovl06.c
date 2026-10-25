#include "types.h"

extern void func_80032F70(u8* a0);
extern s32 func_80033024(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_800326BC(u8* a0);
extern s32 func_8003240C(u8* a0);
extern void func_8003258C(u8* a0);

void func_800F6720_ovl06(u8* a0) {
    s32 r;
    u16 v;
    s16 id;

    func_80032F70(a0);
    r = func_80033024(a0);
    v = *(u16*)(a0 + 0x42) & 0x7FFF;
    *(u16*)(a0 + 0x42) = v;
    if (r != 0) {
        id = *(s16*)(a0 + 0xA);
        if (id != 0x278 && id != 0x5A8) {
            *(u16*)(a0 + 0x42) = v | 0x8000;
            a0[0x5C]--;
        }
    }
    if (*(s8*)(a0 + 0x5C) == 0) {
        a0[4] = 3;
    }
    func_8002D9EC(a0, 0x30, 0x20);
    func_800326BC(a0);
    func_8003240C(a0);
    func_8003258C(a0);
}
