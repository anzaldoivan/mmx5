#include "types.h"

extern s32 func_8002D760();
extern s8 D_80093E66;
extern s16 D_80093E68;
extern s8 D_8009A42C;
extern s16 D_8009A42E;
extern u8 D_800C9310;
extern s8 D_800D50DC;
extern s16 D_800D50DE;

void func_800562FC(u8* arg0) {
    u16 c;
    u8 s;
    u8* q;
    u8* p;
    u8* o;
    s32 t;

    t = arg0[0x18] - 1;
    arg0[0x18] = t;
    if ((s8)t == -1) {
        o = *(u8**)(arg0 + 0x14);
        *(u8**)(arg0 + 0x14) = q = o + 4;
        if (*(u16*)(o + 4) == 0x8000) {
            s = q[3];
            if (s == 1) {
                func_8002D760(arg0, q);
                D_800C9310 = s;
                return;
            }
            *(u8**)(arg0 + 0x14) = q + ((s8*)q)[2] * 4;
        }
        p = *(u8**)(arg0 + 0x14);
        c = *(u16*)p;
        arg0[0x18] = p[2];
        D_800D50DE = c & 0x1F;
        D_8009A42E = c & 0x3E0;
        D_80093E68 = c & 0x7C00;
        D_800D50DC = p[3] & 1;
        D_8009A42C = (*(u8**)(arg0 + 0x14))[3] & 2;
        D_80093E66 = (*(u8**)(arg0 + 0x14))[3] & 4;
        D_800C9310 |= 5;
    }
}
