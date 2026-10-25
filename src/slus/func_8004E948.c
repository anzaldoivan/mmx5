#include "types.h"

extern void func_8002D89C(u8*);
extern u8 D_8006FADC;

void func_8004E948(u8* obj) {
    obj[0x47] = D_8006FADC + 6;
    func_8002D89C(obj);
}
