#include "types.h"

extern void func_80017248(u8* obj);
extern u8 D_800F9EEC_ovl11[][5];

#define G (*(u8**)0x1F80004C)

void func_800F7AE8_ovl11(u8* obj) {
    func_80017248(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[5] = D_800F9EEC_ovl11[0][++G[0x8F] + G[0x8E] * 5];
        obj[6] = 0;
    }
}
