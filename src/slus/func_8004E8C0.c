#include "types.h"

extern u8 D_800D1599;
extern void func_8002D89C(u8*);

void func_8004E8C0(u8* obj) {
    u8 v = D_800D1599;
    if (v != obj[0x54]) {
        obj[0x47] = v ? 10 : 11;
        obj[0x54] = D_800D1599;
    }
    func_8002D89C(obj);
}
