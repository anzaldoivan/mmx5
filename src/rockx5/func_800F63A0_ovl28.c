#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80016490(s32, s32, void*);

void func_800F63A0_ovl28(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if (obj[0x70] & 8) {
        ((s8*)obj)[0x9A] = -1;
        func_800171E8(obj, 0x1B);
        obj[0x67] = 0;
        obj[6]++;
        func_80016490(2, 0x6E, obj);
    }
}
