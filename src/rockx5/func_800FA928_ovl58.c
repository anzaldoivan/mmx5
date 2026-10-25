#include "types.h"

extern u8 D_80091C44;
extern D_8009A1F8_t D_8009A1F8;
extern u8 D_800FB554_ovl58[];
extern void func_80028B18(s32, s32, s32, void*);
extern void func_8002385C(s32, s32, s32);

void func_800FA928_ovl58(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.padA1[0xA] = 0;
        D_8009A1F8.unk5E = 0;
        D_8009A1F8.unk62 = 0x200;
        func_80028B18(1, 0x70, 0x230, D_800FB554_ovl58);
        D_8009A1F8.unkA0 = 1;
        arg0->unk4 = 0;
        func_8002385C(0x62, 0xFF, 0);
        arg0->unk1++;
    }
}
