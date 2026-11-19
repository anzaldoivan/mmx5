#include "types.h"
#include "mmx5/globals.h"

void func_8004D174(u8* obj) {
    u8* p;

    if (*(s8*)(obj + 2) == -1) {
        p = D_8009A420;
        if (obj[0x54] != p[7]) {
            *(s16*)(obj + 0xE) = (*(u8**)(obj + 0x50))[p[7] * 2] + 8;
            obj[0x54] = p[7];
        }
        animate_object(obj);
    }
    func_8002D89C(obj);
}
