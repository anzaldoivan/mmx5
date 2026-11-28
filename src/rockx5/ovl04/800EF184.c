#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void func_800EF584_ovl04(void);

void func_800EF184_ovl04(u8* arg0) {
    s32 flag;
    s16 v;
    s16 w;
    u8* p;
    u8* q;
    u8* r;
    u8* o;

    func_800EF584_ovl04();
    p = g_Player;
    flag = 0;
    if (*(s8*)(p + 0xF3) == 0 || (u32)(p[0xFA] - 2) >= 2) {
        flag = 1;
    }
    if (flag != 0) {
        o = D_8009A1F8.u;
        *(s32*)(o + 0xC) += 0x4000;
    }
    q = D_8009A1F8.u;
    v = *(s16*)(q + 0xE);
    if (v >= 0x3C0) {
        *(s16*)(q + 0x2A) = v;
        *(s16*)(q + 0x28) = v;
        *(s16*)(q + 0x22) = v;
        *(s16*)(q + 0x20) = v;
        r = g_playthrough_state.u;
        w = *(s16*)(q + 0xA);
        r[0x26] |= 2;
        *(s16*)(q + 0x26) = w;
        *(s16*)(q + 0x24) = w;
        *(s16*)(q + 0x1E) = w;
        *(s16*)(q + 0x1C) = w;
        arg0[6]++;
    }
}

extern void func_80028A20(s32, s32, s32, u8*);
extern u8* alloc_class3_slot(void);
extern u8 D_80100DBC_ovl04[];
extern s16 D_80102FD4_ovl04;
extern u8* D_80102FD8_ovl04;

void func_800EF258_ovl04(u8* obj) {
    u8* p;
    u8* g = D_8009A1F8.u;
    u8* q;
    s32 t;

    t = *(u16*)(g + 0x62) - 1;
    *(s16*)(g + 0x62) = t;
    D_80102FD4_ovl04++;
    if ((t << 16) <= 0) {
        play_sound(5, 0x14, 0);
        func_8003D2C4();
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0xE;
            p[2] = 0xD;
            q = g_Player;
            *(s32*)(p + 8) = *(s32*)(q + 8);
            *(s32*)(p + 0xC) = *(s32*)(q + 0xC);
            D_80102FD8_ovl04 = p;
        }
        obj[6]++;
    }
    if (++obj[0x1C] >= 0x18) {
        obj[0x1C] = 0;
    }
    if (obj[0x1C] % 6 == 0) {
        func_80028A20(1, 0x370, 0xF0,
                      D_80100DBC_ovl04 + (u8)(obj[0x1C] / 6) * 8);
    }
}
