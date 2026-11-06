#include "types.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D0E4(void);
extern u8 D_800FEC1C_ovl39[];
extern u8 D_800FEC20_ovl39[];

void func_800FD1D4_ovl39(u8* obj) {
    s8 state;
    u8* child;

    func_80017248(obj);
    state = *(s8*)(obj + 0x45);
    if (state == 1) {
        *(u8**)(obj + 0x54) = D_800FEC20_ovl39;
        *(s32*)(obj + 0x50) = 0;
        *(u8**)(obj + 0x68) = D_800FEC1C_ovl39;
        *(s8*)(obj + 0x8A) = state;
        child = func_8002D0E4();
        if (child != 0) {
            child[0] = 0x61;
            child[1] = 0x15;
            child[2] = 2;
            *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            child[0x15] = obj[0x15];
            *(u16*)(child + 0xA) = *(u16*)(obj + 0xA);
            *(u16*)(child + 0xE) = *(u16*)(obj + 0xE) - 0x28;
            *(u8**)(child + 0x50) = obj;
        }
        obj[6]++;
    }
}
