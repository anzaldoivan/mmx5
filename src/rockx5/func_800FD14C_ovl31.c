#include "types.h"

extern Tbl6160A D_800FA0A8_ovl31;
extern Tbl6160B D_800FA0DC_ovl31;

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern s32 func_8002DF78(void);
extern void func_8002E0F8(s32* a0, s32* a1, u8 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void func_800FD14C_ovl31(u8* obj) {
    Tbl6160A a = D_800FA0A8_ovl31;
    Tbl6160B b = D_800FA0DC_ovl31;
    s32 i;
    s32 x;
    s32 y;
    s16 ang;
    u8* t;

    switch ((s8)obj[5]) {
    case 0:
        if (--*(s16*)(obj + 0x7C) == -1) {
            i = a.v[(s8)obj[7]];
            t = *(u8**)(obj + 0x80);
            x = *(s16*)(t + 0xA) + b.p[i].lo;
            *(s32*)(obj + 0x84) = x;
            y = *(s16*)(t + 0xE) + b.p[i].hi;
            *(s32*)(obj + 0x88) = y;
            ang = ratan2(y - *(s16*)(obj + 0xE), x - *(s16*)(obj + 0xA));
            *(s32*)(obj + 0x20) = rcos(ang) << 5;
            *(s32*)(obj + 0x24) = -rsin(ang) << 5;
            obj[5]++;
        }
        break;
    case 1:
        if ((u32)(*(s16*)(obj + 0xA) - *(s32*)(obj + 0x84)) < 3) {
            *(s32*)(obj + 0x20) = 0;
        }
        if ((u32)(*(s16*)(obj + 0xE) - *(s32*)(obj + 0x88)) < 3) {
            *(s32*)(obj + 0x24) = 0;
        }
        if (*(s16*)(*(u8**)(obj + 0x80) + 0x7C) == 0x15E) {
            s32 vx;
            s32 vy;
            func_8002E0F8((s32*)(obj + 0x20), (s32*)(obj + 0x24),
                          func_8002DF78() & 0x1F);
            vx = *(s32*)(obj + 0x20);
            vy = *(s32*)(obj + 0x24);
            *(s16*)(obj + 0x7C) = 0;
            vx <<= 2;
            *(s32*)(obj + 0x20) = vx;
            vx = obj[5];
            vy <<= 2;
            *(s32*)(obj + 0x24) = vy;
            vx++;
            obj[5] = vx;
        }
        break;
    case 2:
        if (++*(s16*)(obj + 0x7C) == 300) {
            obj[4] = 2;
        }
        break;
    }
    func_8002D9EC(obj, 0x10, 0x10);
    func_80017248(obj);
    func_8002DED4(obj);
}
