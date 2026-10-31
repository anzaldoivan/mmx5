#include "types.h"
#include "addr.h"

extern u32 func_8002DF78(void);
extern u8 D_800F9D10_ovl11[];
extern u8 D_800F9D14_ovl11[];

void func_800F7CDC_ovl11(u8* obj) {
    u8 r;

    if (--*(s16*)(obj + 0x7C) == 0) {
        *(u8**)(obj + 0x54) = D_800F9D10_ovl11;
        *(u8**)(obj + 0x50) = D_800F9D14_ovl11;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s16*)(obj + 0x7E) -= 1;
        r = func_8002DF78() % 3;
        if (r == 0) {
            obj[6] = 3;
            if (D_1F80004C.bytes[0x92] == 3) {
                obj[6] = 7;
            }
        } else if (r == 1) {
            obj[6] = 5;
        } else {
            obj[6] = 7;
            if (D_1F80004C.bytes[0x92] == 7) {
                obj[6] = 3;
            }
        }
    }
}
