#include "types.h"

extern void func_80017248(u8* obj);
extern void func_80028B18(s32, s32, s32, void*);
extern u8 D_8009A1F8[];
extern s16 D_800D1C04;
extern s16 D_800F1F48_ovl16[];
extern s16 D_800F1F64_ovl16[][2];
extern u8 D_800F1F98_ovl16[][8];

void func_800EEE20_ovl16(u8* arg0) {
    s16* p;
    s32 i;

    func_80017248(arg0);
    if (*(s8*)(arg0 + 0x46) == 0) {
        if (*(s8*)(arg0 + 2) == 0) {
            i = *(s8*)(arg0 + 0x54);
            p = &D_800F1F48_ovl16[i];
            func_80028B18(*p, D_800F1F64_ovl16[i][0], D_800F1F64_ovl16[i][1],
                          D_800F1F98_ovl16[i]);
            D_8009A1F8[*p * 0x54 + 0x4C] = 1;
            arg0[3] = 0;
        }
        D_800D1C04 = 0;
        arg0[4]++;
    }
}
