#include "types.h"

extern void func_80016490(s32, s32, void*);
extern s32 func_80017E54(s32);
extern s32 func_8002DF78(void);
extern u8 D_8009A1F8[];

void func_800FAA38_ovl50(u8* arg0) {
    u8* p;
    u8* q;
    u8* e;
    s32 t;
    s32 r;

    t = *(u16*)(arg0 + 6) + 1;
    *(u16*)(arg0 + 6) = t;
    if (t & 1) {
        r = func_8002DF78();
        p = D_8009A1F8;
        *(s16*)(p + 0xB6) = r % 5 + 0x104;
    } else {
        e = D_8009A1F8;
        *(s16*)(e + 0xB6) = 0x100;
    }
    if (*(s16*)(arg0 + 4) < 0x1E) {
        *(s16*)(arg0 + 4) = *(s16*)(arg0 + 4) + 1;
        return;
    }
    func_80016490(2, 0x6C, 0);
    func_80016490(2, 0x51, 0);
    q = D_8009A1F8;
    *(s32*)(q + 0x5C) = 0x02000000;
    *(s32*)(q + 0x60) = 0x01800000;
    q[0xA0] = 1;
    q[0x57] = 1;
    *(s16*)(arg0 + 4) = 0;
    func_80017E54(3);
    arg0[1]++;
}
