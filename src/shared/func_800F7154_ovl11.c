#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern u8 D_800F9EEC_ovl11[][5];

#define G D_1F80004C.bytes
void func_800F7154_ovl11(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        if (D_800D1CA2 / 2 >= *(signed char*)(obj + 0x5C) && G[0x8E] < 4) {
            obj[5] = 7;
        } else {
            obj[5] = D_800F9EEC_ovl11[0][++G[0x8F] + G[0x8E] * 5];
        }
        obj[6] = 0;
    }
}
