#include "types.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D0E4(void);

void func_800EFB4C_ovl18(u8* obj) {
    u8* child;

    func_80017248(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        child = func_8002D0E4();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x18;
            child[2] = 3;
            child[0x16] = 0;
            child[0x15] = 0;
            child[0x14] = obj[0x14];
            *(s16*)(child + 0xA) = *(s16*)(obj + 0xA);
            *(s16*)(child + 0xE) = *(s16*)(obj + 0xE);
            *(s16*)(child + 0x42) = *(s16*)(obj + 0x42);
            *(s16*)(child + 0x40) = *(s16*)(obj + 0x40);
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
        }
        obj[5]++;
    }
}
