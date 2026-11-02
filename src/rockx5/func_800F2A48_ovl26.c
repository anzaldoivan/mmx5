#include "types.h"
#include "addr.h"

extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8002D6FC(u8* obj);
extern u8 D_800D1C00[];
extern u8 D_8009A1F8[];

void func_800F2A48_ovl26(u8* obj) {
    u8* child;
    s8* q;
    u8* g;
    u8* h;
    s32 r;

    obj[3] = 0;
    q = *(s8**)(D_1F80004C.bytes + 0x84);
    if (q[0] != 0) {
        if (q[7] == 0) {
            if (--*(s16*)(obj + 0x7E) == -1) {
                *(s16*)(obj + 0x7E) = 5;
                *(u16*)(obj + 0x42) ^= 0x8000;
                child = func_8002D27C();
                if (child != 0) {
                    child[0] = 0x41;
                    child[1] = 0x3D;
                    child[2] = 1;
                    *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
                    *(s16*)(child + 0x40) = *(s16*)(obj + 0x40);
                    *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
                    *(s16*)(child + 0x42) = *(s16*)(obj + 0x42);
                    r = (func_8002DF78() & 3) * 16 - 0x30;
                    *(s16*)(child + 0xA) = *(s16*)(obj + 0xA) + r;
                    r = (func_8002DF78() & 1) * 16 - 0x10;
                    *(s16*)(child + 0xE) = *(s16*)(obj + 0xE) + r;
                    child[0x15] = func_8002DF78() & 0x40;
                    *(u8**)(child + 0x50) = obj;
                }
            }
            func_8002D9EC(obj, 0x60, 0x60);
        }
    } else {
        g = D_800D1C00;
        h = D_8009A1F8;
        g[0xF] = 0x10;
        g[0x24] = 0;
        *(s32*)(g + 0x20) = 0;
        *(u16*)(h + 0x2A) = *(u16*)(h + 0xE);
        func_8002D6FC(obj);
    }
}
