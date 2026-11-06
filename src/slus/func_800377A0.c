#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8003A418(u8* a0);
extern void func_8003A874(u8* obj);
extern void func_8003B1A8(u8* a0);
extern void func_8003B33C(u8*, s32);
extern void func_8003CD08(u8* obj);
extern s8 D_800D1C00[];

void func_800377A0(u8* obj) {
    if (D_800D1C00[0xF] != 0) {
        func_8003B1A8(obj);
        return;
    }
    if (*(s8*)(obj + 0xD0) > 0 && *(s8*)(obj + 0xD1) == 0x17) {
        func_8003A418(obj);
        return;
    }
    if (*(s8*)(obj + 0xD5) == 0) {
        func_8003CD08(obj);
        func_8003A874(obj);
        obj[0x86] = 1;
        D_800D1C00[0x1C] = 0;
        return;
    }
    if (*(s8*)(obj + 6) == 0) {
        func_8003B33C(obj, obj[0xD8]);
        obj[6]++;
    }
    func_80017248(obj);
}
