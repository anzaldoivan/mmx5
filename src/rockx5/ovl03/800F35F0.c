#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/system.h"
#include "mmx5/ovl03.h"
#include "mmx5/sound.h"

#include "shared/func_800F35F0_ovl03.c"

#include "shared/func_800F45E4_ovl03.c"

#include "shared/func_800F46E0_ovl03.c"

#define func_800F45E4_ovl03 func_800F54D4_ovl03
#include "shared/func_800F45E4_ovl03.c"
#undef func_800F45E4_ovl03

#include "shared/func_800F55D0_ovl03.c"

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

#include "shared/func_800F5940_ovl03.c"
