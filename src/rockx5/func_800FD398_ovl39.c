#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800FEC18_ovl39[];
extern u8 D_800FEC14_ovl39[];

void func_800FD398_ovl39(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        *(u8**)(obj + 0x54) = D_800FEC18_ovl39;
        *(s32*)(obj + 0x50) = 0;
        *(u8**)(obj + 0x68) = D_800FEC14_ovl39;
        obj[0x8A] = 0;
        func_800171E8(obj, 3);
        obj[6]++;
    }
}
