#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_80016490(s32, s32, void*);

void func_800FC7FC_ovl38(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        func_800171E8(obj, 0x16);
        func_80016490(2, 0xA3, obj);
        obj[6]++;
    }
}
