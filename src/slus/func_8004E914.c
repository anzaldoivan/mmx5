#include "types.h"

extern void func_8002D89C(u8*);
extern u8 D_8006FADD;

void func_8004E914(u8* obj) {
    u8 v = D_8006FADD;
    obj[0x47] = v ? 9 : 7;
    func_8002D89C(obj);
}
