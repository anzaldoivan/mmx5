#include "types.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern u8 D_8009A0A0[];
extern s16 D_800FFC34_ovl31;
extern s16 D_800FFC38_ovl31;
extern s16 D_800FFC3C_ovl31;
extern s16 D_800FFC40_ovl31;
extern s16 D_800FFC42_ovl31;

void func_800FC800_ovl31(u8* obj) {
    u8* p = D_8009A0A0;
    u8* q;
    s16 a;

    if (*(s16*)(p + 0xA) < D_800FFC38_ovl31) {
        D_800FFC40_ovl31 = *(s16*)(p + 0xA) + 0x40;
    } else {
        D_800FFC40_ovl31 = *(s16*)(p + 0xA) - 0x40;
    }
    q = D_8009A0A0;
    D_800FFC42_ovl31 = *(s16*)(q + 0xE);
    if (D_800FFC42_ovl31 < D_800FFC34_ovl31) {
        D_800FFC42_ovl31 = D_800FFC34_ovl31;
    }
    if (D_800FFC42_ovl31 > D_800FFC3C_ovl31) {
        D_800FFC42_ovl31 = D_800FFC3C_ovl31;
    }
    a = ratan2(D_800FFC42_ovl31 - *(s16*)(obj + 0xE),
               D_800FFC40_ovl31 - *(s16*)(obj + 0xA));
    *(s32*)(obj + 0x20) = rcos(a) * 0x60;
    *(s32*)(obj + 0x24) = -rsin(a) * 0x60;
    obj[6]++;
    func_80017248(obj);
    func_8002DED4(obj);
}
