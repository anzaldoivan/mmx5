#include "types.h"

void func_800EF5A0_ovl11(u8* arg0);
extern u8 D_8009A1F8[];
extern void* D_800F96B0_ovl11[];

void func_800EF9F8_ovl11(u8* o) {
    u8* p;
    u8* b;

    if (o[0x1F] != 0) {
        p = o + 0x14;
        ((void (*)(u8*))D_800F96B0_ovl11[o[0x1E]])(o);
    } else {
        u8* q = o + 0x14;
        q[4] = o[0x18] - 1;
        p = q;
        if (q[4] == 0) {
            o[0x1F] = 1;
        }
    }
    b = D_8009A1F8;
    *(s16*)(o + 0xA) = *(u16*)(b + 0xA) + 0xA0;
    *(s16*)(o + 0xE) = *(u16*)(b + 0xE) + 0x80;
    p[6] = o[0x1A] - 1;
    if (p[6] == 0) {
        func_800EF5A0_ovl11(o);
        o[0x1A] = 7;
    }
    if (*(s8*)(o + 7) == 0) {
        o[7] = 10;
    }
    o[7] = o[7] - 1;
    p[7] = o[0x1B] - 1;
    if (p[7] == 0) {
        o[4]++;
    }
}
