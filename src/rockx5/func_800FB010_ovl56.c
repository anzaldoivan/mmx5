#include "types.h"

/* e: UnkObj (include/types.h): unk1, unk4 */
extern void func_80028B18(s32, s32, s32, void*);
extern void func_8002385C(s32, s32, s32);
extern u8 D_80091C44;
extern u8 D_8009A1F8[];
extern u8 D_800FBE34_ovl56[];

void func_800FB010_ovl56(UnkObj* e) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8;
        p[0x57] = 1;
        p[0xAB] = 0;
        *(s16*)(p + 0x5E) = 0;
        *(s16*)(p + 0x62) = 0x200;
        func_80028B18(1, 0x70, 0x230, D_800FBE34_ovl56);
        p[0xA0] = 1;
        e->unk4 = 0;
        func_8002385C(0x62, 0xFF, 0);
        e->unk1++;
    }
}
