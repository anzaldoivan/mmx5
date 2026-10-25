#include "types.h"

extern void func_80017248(u8* obj);
extern s8 D_8009A0A2;
extern s16 D_80101030_ovl07[];

void func_800F3008_ovl07(u8* obj) {
    if (obj[0x85] != 0) {
        *(s16*)(obj + 0xA0) = 0;
        obj[0x83] = 0x40;
        obj[5] = 2;
        obj[6] = 0;
        return;
    }
    func_80017248(obj);
    if (obj[0x82] != 0) {
        *(s16*)(obj + 0xA0) += 1;
        if (*(s16*)(obj + 0xA0) >= D_80101030_ovl07[D_8009A0A2]) {
            obj[5] = 3;
            obj[6] = 0;
            *(s16*)(obj + 0xA0) = 0;
        }
    }
}
