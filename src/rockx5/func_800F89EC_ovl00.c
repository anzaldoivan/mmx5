#include "types.h"

extern s16 D_8009A0AA;
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void func_800F89EC_ovl00(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        if (*(s16*)(obj + 0xA) - D_8009A0AA < 0) {
            func_800171E8(obj, 3);
            obj[6] += 3;
        } else {
            *(s16*)(obj + 0x7C) = 10;
            obj[6]++;
        }
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
