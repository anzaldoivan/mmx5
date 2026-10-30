#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void func_800F889C_ovl00(u8* obj) {
    func_800171E8(obj, 2);
    obj[6]++;
    func_80017248(obj);
    func_8002DED4(obj);
}
