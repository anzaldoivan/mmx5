#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_800171E8(u8* obj, s32 arg1);
extern void func_80016490(s32 arg0, s32 arg1, u8* obj);

void func_800F699C_ovl28(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if (obj[0x70] & 8) {
        func_800171E8(obj, 0x1B);
        obj[0x67] = 0;
        obj[6]++;
        func_80016490(2, 0x6E, obj);
    }
}
