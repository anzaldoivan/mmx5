#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_80016490(s32, s32, void*);

void func_800F948C_ovl00(u8* obj) {
    func_800171E8(obj, 2);
    func_80016490(2, 0, obj);
    obj[6]++;
}
