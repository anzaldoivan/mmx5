#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern void func_800F81F4_ovl11(u8* obj);

void func_800F7FE0_ovl11(u8* obj) {
    obj[0x60] = 4;
    obj[0x62] = 0;
    set_animation(obj, 0);
    func_800F81F4_ovl11(obj);
    animate_object(obj);
    *(s16*)(obj + 0x7C) = 0x3C;
    obj[6]++;
}

void func_800F8038_ovl11(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        animate_object();
        set_animation(obj, 5);
        obj[6]++;
    }
}

void func_800F8098_ovl11(u8* obj) {
    u8* p;

    animate_object(obj);
    if (*(s16*)(obj + 0x7C) == 0) {
        p = D_1F80004C.bytes;
        if ((s8)p[0x8D] != (s8)obj[0x5C]) {
            (*(u8**)(p + 0x80))[5] = 1;
            (*(u8**)(D_1F80004C.bytes + 0x80))[6] = 2;
        }
    } else {
        *(s16*)(obj + 0x7C) -= 1;
    }
    if (*(s8*)(obj + 7) == 0) {
        obj[6]++;
    }
}

extern u8 D_800F9EEC_ovl11[][5];

#define G D_1F80004C.bytes

void func_800F8134_ovl11(u8* obj) {
    if (D_800D1CA2 / 2 >= *(signed char*)(obj + 0x5C) && G[0x8E] < 4) {
        obj[5] = 7;
    } else {
        obj[5] = D_800F9EEC_ovl11[0][++G[0x8F] + G[0x8E] * 5];
    }
    obj[6] = 0;
    animate_object(obj);
}
