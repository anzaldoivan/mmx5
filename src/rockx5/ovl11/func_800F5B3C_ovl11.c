#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "addr.h"

extern s16 D_800FA056_ovl11;
extern s16 D_800FA058_ovl11;

void func_800F5B3C_ovl11(u8* obj) {
    s32 v;
    s16 x;
    s16 y;
    u8 st;

    animate_object(obj);
    apply_object_motion(obj);
    x = *(s16*)(obj + 0xA);
    if (x <= D_800FA056_ovl11 - 0x18) {
        *(s16*)(obj + 0xA) = D_800FA056_ovl11 - 0x18;
    } else if (x >= D_800FA058_ovl11 + 0x18) {
        *(s16*)(obj + 0xA) = D_800FA058_ovl11 + 0x18;
    }
    if (obj[0x15] == 0) {
        y = *(s16*)(obj + 0xA);
        if (y < D_8009A0AA - 2 || y <= D_800FA056_ovl11 - 0x18 ||
            D_1F80004C.bytes[0x90] == 1) {
            st = obj[6];
            v = 0xFFFC0000;
            *(s32*)(obj + 0x20) = v;
            *(s32*)(obj + 0x24) = v;
            *(s32*)(obj + 0x28) = 0;
            *(s16*)(obj + 0x7C) = 0x14;
            obj[6] = st + 1;
        }
    } else {
        x = *(s16*)(obj + 0xA);
        if (x > D_8009A0AA + 2 || x >= D_800FA058_ovl11 + 0x18 ||
            D_1F80004C.bytes[0x90] == 1) {
            st = obj[6];
            v = 0x40000;
            *(s32*)(obj + 0x20) = v;
            v = 0xFFFC0000;
            *(s32*)(obj + 0x24) = v;
            *(s32*)(obj + 0x28) = 0;
            *(s16*)(obj + 0x7C) = 0x14;
            obj[6] = st + 1;
        }
    }
}
