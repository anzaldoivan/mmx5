#include "types.h"
#include "addr.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002DF78(void);

void func_800FC724_ovl38(u8* obj) {
    if ((s8)obj[0x45] == 2) {
        func_80016490(2, 0xA3, obj);
    } else if ((s8)obj[0x45] == 1) {
        func_800171E8(obj, 0xE);
        *(s16*)(obj + 0x7C) = 0x32;
        *(s16*)(obj + 0x7E) = func_8002DF78() & 3;
        *(s16*)(D_1F80004C.bytes + 0x86) = 0;
        obj[6] = 4;
    }
}
