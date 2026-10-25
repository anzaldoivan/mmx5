#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_80016490(s32, s32, void*);

void func_800F6364_ovl26(u8* obj) {
    func_80017248(obj);
    if (*(s16*)(obj + 0x90) != 0) {
        (*(s16*)(obj + 0x90))--;
    } else {
        func_800171E8(obj, 1);
        func_80016490(2, 0x5E, obj);
        obj[6]++;
    }
}
