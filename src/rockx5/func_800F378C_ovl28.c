#include "types.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D1A4();
extern void func_80016490(s32, s32, void*);
extern u32 func_8002DF78(void);
extern s32 func_8002B5B4(s32);

void func_800F378C_ovl28(u8* obj) {
    s32 i;
    u8* p;
    s16 t;
    u8 r;
    s32 a;
    s32 b;

    func_80017248(obj);
    if (*(s16*)(obj + 0x7C) != 0) {
        *(s16*)(obj + 0x7C) = *(s16*)(obj + 0x7C) - 1;
        return;
    }
    if (*(s8*)(obj + 0x45) == 1) {
        obj[7] = 3;
        *(u16*)(obj + 0x7E) = *(u16*)(obj + 0x7E) - 1;
        for (i = 0; i < 2; i++) {
            p = func_8002D1A4();
            if (p != 0) {
                t = *(s16*)(obj + 0x7E);
                if (t == 0) {
                    p[2] = 0x10;
                    if (i == 1) {
                        func_80016490(2, 0x6C, obj);
                        func_80016490(2, 0x76, obj);
                        t = obj[6];
                        t++;
                        obj[6] = t;
                    }
                } else {
                    if (t == 4 && i == 1) {
                        r = func_8002DF78() % 3;
                        switch (r) {
                        case 1:
                            func_80016490(2, 0x7F, obj);
                            break;
                        case 2:
                            func_80016490(2, 0x80, obj);
                            break;
                        }
                    }
                    p[2] = 0;
                    *(s16*)(obj + 0x7C) = 3;
                }
                p[0] = 0x61;
                p[1] = 0x23;
                p[2] |= i + 2;
                a = func_8002B5B4(0x40);
                b = func_8002B5B4(0x40);
                *(s16*)(p + 0x42) =
                    ((a * 4 + 0x1A) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
                *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
                *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
                *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
                *(u8**)(p + 0x7C) = obj;
            }
        }
    }
}
