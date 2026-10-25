#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_80016490(s32, s32, void*);
extern u8 D_800FECD4_ovl39[];

void func_800FE2FC_ovl39(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        func_80016490(2, 0xA9, obj);
        *(u8**)(obj + 0x50) = D_800FECD4_ovl39;
        *(s16*)(obj + 0x8C) = 50;
        obj[5]++;
    }
}
