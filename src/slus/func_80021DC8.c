#include "types.h"

extern void func_80013288(s32);
extern void func_8002002C(s32);
extern void func_8002BBF8(void);
extern u8* func_8002D2DC(void);
extern u8 D_8007113C[];
extern u8 D_80071154[];
extern u8 D_8009A427;

void func_80021DC8(u8* arg0) {
    u8* p;
    u8* s;

    arg0[7] = 1;
    *(s32*)(arg0 + 0x34) = 0;
    func_8002BBF8();
    D_8009A427 = 0;
    for (s = D_8007113C; *s != 0xFF; s += 3) {
        p = func_8002D2DC();
        if (p != 0) {
            p[0] = 1;
            p[1] = 1;
            p[2] = s[0];
            *(s16*)(p + 0xE) = s[1] + 8;
            p[7] = s[2];
        }
    }
    p = func_8002D2DC();
    if (p != 0) {
        p[0] = 1;
        *(s8*)(p + 2) = -1;
        p[1] = 0;
        *(u8**)(p + 0x50) = D_80071154;
        *(s16*)(p + 0xA) = 0x78;
    }
    func_8002002C(0);
    func_80013288(8);
}
