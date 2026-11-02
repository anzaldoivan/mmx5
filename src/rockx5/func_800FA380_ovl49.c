#include "types.h"

extern X4_BackgroundObj D_8009A24C[3];
extern u8 D_800FBBC4_ovl49[];
extern u8 D_800FB9C4_ovl49[];
extern u8 D_800FBFC4_ovl49[];
extern u8 D_800FBDC4_ovl49[];

void func_8002C3CC(void*, void*, s32, s32, s32);
s32 func_8002C338(s32, void*, s32);
void func_8002385C(s32, s32, s32);

void func_800FA380_ovl49(Ovl45State* arg0) {
    arg0->unk4++;
    func_8002C3CC(D_800FBBC4_ovl49, D_800FB9C4_ovl49, 0x100, arg0->unk4, 0x50);
    func_8002C338(0xA0, D_800FBBC4_ovl49, 0x10);
    func_8002C3CC(D_800FBFC4_ovl49, D_800FBDC4_ovl49, 0x100, 0x50 - arg0->unk4,
                  0x50);
    func_8002C338(0xE0, D_800FBFC4_ovl49, 0x10);
    if (arg0->unk4 >= 0x50) {
        D_8009A24C[0].unk3 = 0;
        func_8002C338(0xA0, D_800FB9C4_ovl49, 0x10);
        func_8002C338(0xE0, D_800FBDC4_ovl49, 0x10);
        func_8002385C(0x34, 0xFF, 0);
        arg0->unk1++;
    }
}
