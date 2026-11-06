#include "types.h"

extern void func_8002DF54(u8* a0);
extern s32 func_8002DF78(void);

void func_800FDA18_ovl39(u8* o) {
    if (*(s16*)(o + 0x82) != 0) {
        *(s16*)(o + 0x82) = *(u16*)(o + 0x82) - 1;
    } else if (*(s8*)(o + 0x85) != 0) {
        o[0x84] = 0x28;
        o[0x85] = o[0x85] - 1;
        *(s16*)(o + 0x82) = ((func_8002DF78() & 7) << 5) + 0x80;
    }
    if ((u16)(*(u16*)(o + 0xA) - 0x11C1) < 0x9F && *(s8*)(o + 0x84) != 0) {
        o[0x84] = o[0x84] - 1;
        return;
    }
    func_8002DF54(o);
    if ((*(s32*)(o + 0x20) > 0 && *(s16*)(o + 0xA) >= 0x1268) ||
        (*(s32*)(o + 0x20) < 0 && *(s16*)(o + 0xA) < 0x11B9)) {
        o[6]++;
    }
}
