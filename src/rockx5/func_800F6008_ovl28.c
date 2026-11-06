#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern s32 func_8002DF78(void);
extern s32 func_80016490(s32, s32, void*);
extern s32 D_8009A0A8;

void func_800F6008_ovl28(u8* obj) {
    func_800171E8(obj, 4);
    func_80017248(obj);
    obj[0x67] = 1;
    if (D_8009A0A8 > *(s32*)(obj + 8)) {
        *(s32*)(obj + 0x20) = -0x20000;
        obj[0x15] = 0;
    } else {
        *(s32*)(obj + 0x20) = 0x20000;
        obj[0x15] = 0x40;
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0x5D000;
    *(s32*)(obj + 0x2C) = 0x4200;
    switch (func_8002DF78() & 1) {
    case 0:
        func_80016490(2, 0x7B, obj);
        break;
    case 1:
        func_80016490(2, 0x7C, obj);
        break;
    case 2:
        func_80016490(2, 0x7D, obj);
        break;
    }
    func_80016490(2, 0x6D, obj);
    obj[6]++;
}
