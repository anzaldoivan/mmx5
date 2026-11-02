#include "types.h"

extern u8* func_8002D0E4(void);
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80016490(s32, s32, void*);
extern u32 func_8002DF78(void);

void func_800F3430_ovl28(u8* obj) {
    u8* child;

    child = func_8002D0E4();
    if (child != 0) {
        child[0] = 0x21;
        child[1] = 0xB;
        child[2] = 6;
        child[0x15] = obj[0x15];
        *(s16*)(child + 0xA) = *(s16*)(obj + 0xA);
        *(s16*)(child + 0xE) = *(s16*)(obj + 0xE);
        *(u8**)(child + 0x50) = obj;
    }
    func_80017248(obj);
    if (obj[0x70] & 1) {
        obj[0x15] = 0;
        *(s32*)(obj + 0x20) = -0x42000;
    } else {
        obj[0x15] = 0x40;
        *(s32*)(obj + 0x20) = 0x42000;
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0x5A000;
    *(s32*)(obj + 0x2C) = 0x4200;
    func_800171E8(obj, 6);
    obj[0x67] = 1;
    obj[6]++;
    func_80016490(2, 0x6F, obj);
    switch ((u8)(func_8002DF78() % 3)) {
    case 0:
        func_80016490(2, 0x7B, obj);
        break;
    case 1:
        func_80016490(2, 0x7C, obj);
        break;
    case 2:
        func_80016490(2, 0x7E, obj);
        break;
    }
}
