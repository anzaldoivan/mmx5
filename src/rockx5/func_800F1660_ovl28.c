#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_8002DED4(u8* obj);

void func_800F1660_ovl28(u8* obj) {
    func_80017248(obj);
    if (*(s16*)(obj + 0x7C) != 0) {
        *(s16*)(obj + 0x7C) -= 1;
    } else {
        func_8002DED4(obj);
        if (*(s32*)(obj + 0x24) > 0x1FFFF) {
            *(s32*)(obj + 0x2C) = 0x1000;
        }
        if (*(s32*)(obj + 0x24) == 0) {
            obj[6] = 0;
        }
    }
}
