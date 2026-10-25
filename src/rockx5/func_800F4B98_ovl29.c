#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s16 D_800FA650_ovl29;
extern s16 D_800FA64A_ovl29;

void func_800F4B98_ovl29(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if (*(s16*)(obj + 0xE) < D_800FA650_ovl29) {
        *(s16*)(obj + 0xE) = D_800FA650_ovl29;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
    }
    if (obj[0x15] == 0) {
        if (!(*(s16*)(obj + 0xA) < D_800FA64A_ovl29 - 0x10)) {
            return;
        }
    } else {
        if (!(D_800FA64A_ovl29 + 0x10 < *(s16*)(obj + 0xA))) {
            return;
        }
    }
    *(s32*)(obj + 0x2C) = 0x1F00;
    obj[6]++;
}
