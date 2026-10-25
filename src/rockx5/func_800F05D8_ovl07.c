#include "types.h"

extern void func_800EFCE4_ovl07(u8* obj, s32 arg1);
extern void func_800EFC30_ovl07(u8* obj);
extern void func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);

void func_800F05D8_ovl07(u8* obj) {
    u8 flags;

    obj[0x67] = 1;
    func_800EFCE4_ovl07(obj, 3);
    flags = obj[0x70];
    if (!(flags & 4)) {
        func_800EFC30_ovl07(obj);
        if (*(s32*)(obj + 0x24) < 0) {
            obj[6] = 3;
            func_80016490(5, 0x11, 0);
        }
    } else {
        obj[6] = 3;
        *(s32*)(obj + 0x24) = 0;
        if (flags & 1) {
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
        }
    }
    func_80017248(obj);
}
