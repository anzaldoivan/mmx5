#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D89C(u8*);
extern u8 D_8009A420[];

void func_8004D174(u8* obj) {
    u8* p;

    if (*(s8*)(obj + 2) == -1) {
        p = D_8009A420;
        if (obj[0x54] != p[7]) {
            *(s16*)(obj + 0xE) = (*(u8**)(obj + 0x50))[p[7] * 2] + 8;
            obj[0x54] = p[7];
        }
        func_80017248(obj);
    }
    func_8002D89C(obj);
}
