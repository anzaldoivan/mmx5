#include "types.h"

extern void func_8002D89C(u8*);
extern u8 D_8006FADB;
extern u8 D_8007301C[];

void func_8004D344(u8* obj) {
    if (D_8006FADB & D_8007301C[((s8*)obj)[2]]) {
        obj[0x47] = 11;
    } else {
        obj[0x47] = 12;
    }
    func_8002D89C(obj);
}
