#include "types.h"

extern Buf800EF2B8 D_800EE988_ovl21;
extern void func_8002DF54(u8* a0);

void func_800EF2B8_ovl21(u8* obj) {
    Buf800EF2B8 buf;
    u8* p;
    u16 t;

    buf = D_800EE988_ovl21;
    p = *(u8**)(obj + 0x50);
    t = ++*(u16*)(obj + 0x54);
    if (t < 40) {
        func_8002DF54(obj);
    } else {
        *(s16*)(obj + 0xA) = 0xA0;
        *(s16*)(obj + 0xE) = 0x78;
        if (t >= 53) {
            *(s16*)(p + 4) = 0;
            obj[4] = 2;
        }
    }
    if (*(s8*)(obj + 2) == 4 && *(s16*)(obj + 0xA) >= 0xA0) {
        *(s16*)(obj + 0xA) = 0xA0;
        obj[4] = 2;
    }
}
