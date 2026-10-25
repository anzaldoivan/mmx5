#include "types.h"

extern void func_800F7CB0_ovl29(s32 a0, u8* a1, u8* a2, s32 a3);
extern void func_80017248(u8* obj);
extern u8 D_800F96C0_ovl29[];

void func_800F25C0_ovl29(u8* obj) {
    u8* d = D_800F96C0_ovl29;
    s32 v = 0x30000;

    obj[0x61] = 0;
    *(s32*)(obj + 0x90) = 1;
    if (obj[0x15] == 0) {
        v = -0x30000;
    }
    func_800F7CB0_ovl29(8, d, obj, v);
    func_80017248(obj);
    obj[6] = 2;
}
