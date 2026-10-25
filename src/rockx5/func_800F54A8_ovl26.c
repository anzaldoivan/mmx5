#include "types.h"

extern void func_80017248(u8* obj);
extern void func_80028B18(s32, s32, s32, void*);
extern u8 D_800F9F14_ovl26[];
extern u8 D_8009A244;

void func_800F54A8_ovl26(u8* obj) {
    u8* p;

    func_80017248(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        p = D_800F9F14_ovl26;
        func_80028B18(0, 0x8B0, 0x11D0, p);
        func_80028B18(0, 0xA60, 0x11D0, p + 8);
        D_8009A244 = 1;
        obj[5] = 0xB;
        obj[6] = 0;
        *(s16*)(obj + 0x7E) = 3;
    }
}
