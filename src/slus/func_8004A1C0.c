#include "types.h"

extern u8 D_8009A0A0[];
extern void func_80016D54(s32, s32);
extern int func_8002D6FC();

void func_8004A1C0(u8* obj) {
    u8* p;

    func_80016D54(1, 0x18);
    p = D_8009A0A0;
    p[0x98]--;
    p[0x99]--;
    func_8002D6FC(obj);
}
