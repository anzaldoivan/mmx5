#include "types.h"

extern void func_80016490(s32, s32);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_80017248(u8* obj);
extern u8* func_8002D144(void);
extern void func_8002D6FC(u8* obj);
extern s32 func_8002DF78(void);
extern void func_800F1260_ovl00(u8* p);
extern s8 D_800D1C27;

void func_800F1380_ovl00(u8* p) {
    s8 state;
    u8* s;

    state = *(s8*)(p + 4);
    if (state == 0) {
        func_800F1260_ovl00(p);
    } else if (state == 1) {
        s = func_8002D144();
        if (s != 0) {
            s[0] = state;
            s[1] = 3;
            s[2] = 5;
        }
        func_800171E8(p, 0);
        func_80016490(5, 6);
        {
            s32 r = func_8002DF78();
            p[4]++;
            *(s16*)(p + 0xA) = (r % 20) * 16 + 0x118B;
        }
    } else if (state == 2) {
        func_80017248(p);
        p[3] = p[0x45];
        if (p[0x47] == 0) {
            p[0] |= 0x10;
        } else {
            p[0] &= 0xEF;
        }
        if (*(s8*)(p + 0x46) == 0) {
            p[4]++;
            if (D_800D1C27 != 0) {
                s = func_8002D144();
                if (s != 0) {
                    s[0] = 1;
                    s[1] = 3;
                    s[2] = 6;
                }
                func_8002D6FC(p);
            } else {
                *(u16*)(p + 0x54) = func_8002DF78() % 80 + 30;
            }
        }
    } else if (state == 3) {
        if (--*(s16*)(p + 0x54) == 0) {
            p[4] = 1;
        }
        if (D_800D1C27 != 0) {
            s = func_8002D144();
            if (s != 0) {
                s[0] = 1;
                s[1] = state;
                s[2] = 6;
            }
            func_8002D6FC(p);
        }
    }
}
