#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern s16 D_800FA244_ovl03;
extern s16 D_800FA248_ovl03;
extern s16 D_800FA24C_ovl03;
extern s16 D_800FA250_ovl03;
extern s16 D_800FA252_ovl03;

void func_800F5814_ovl03(u8* obj) {
    u8* p = g_Player;
    u8* q;
    s16 a;

    if (*(s16*)(p + 0xA) < D_800FA248_ovl03) {
        D_800FA250_ovl03 = *(s16*)(p + 0xA) + 0x40;
    } else {
        D_800FA250_ovl03 = *(s16*)(p + 0xA) - 0x40;
    }
    q = g_Player;
    D_800FA252_ovl03 = *(s16*)(q + 0xE);
    if (D_800FA252_ovl03 < D_800FA244_ovl03) {
        D_800FA252_ovl03 = D_800FA244_ovl03;
    }
    if (D_800FA252_ovl03 > D_800FA24C_ovl03) {
        D_800FA252_ovl03 = D_800FA24C_ovl03;
    }
    a = ratan2(D_800FA252_ovl03 - *(s16*)(obj + 0xE),
               D_800FA250_ovl03 - *(s16*)(obj + 0xA));
    *(s32*)(obj + 0x20) = rcos(a) * 0x60;
    *(s32*)(obj + 0x24) = -rsin(a) * 0x60;
    obj[6]++;
    animate_object(obj);
    apply_object_motion(obj);
}
