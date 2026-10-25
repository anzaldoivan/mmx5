#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8001296C(s32);
extern void func_80016490(s32, s32, void*);
extern void func_8002A600(s32, s32, s32);
extern void func_800171E8(u8* obj, s32 state);

void func_800F5350_ovl26(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if (obj[0x70] & 8) {
        func_8001296C(5);
        func_80016490(2, 0x63, obj);
        func_8002A600(0x1E, 4, 1);
        if (obj[0x15] != 0) {
            *(s32*)(obj + 0x20) = 0x30000;
        } else {
            *(s32*)(obj + 0x20) = -0x30000;
        }
        obj[6]++;
        func_800171E8(obj, 0x13);
    }
}
