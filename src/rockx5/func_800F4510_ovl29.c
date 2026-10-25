#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_80016490(s32, s32, void*);
extern void func_8002DED4(u8* obj);
extern void func_80017248(u8* obj);

void func_800F4510_ovl29(u8* obj) {
    if (*(s16*)(obj + 0x88) - *(s16*)(obj + 0xE) >= 0x61) {
        obj[6]++;
        func_800171E8(obj, 4);
        func_80016490(2, 0xAD, obj);
        obj[0x60] = 5;
        *(s32*)(obj + 0x24) = 0xFFFA0000;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
    }
    func_8002DED4(obj);
    func_80017248(obj);
}
