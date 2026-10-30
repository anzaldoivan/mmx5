#include "types.h"
#include "addr.h"

extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_800171E8(u8* obj, s32 state);
extern u32 func_8002DF78(void);
extern u8 D_8009A1F8[];
extern s16 D_800FA060_ovl11;

void func_800F6218_ovl11(u8* arg0) {
    D_1F80004C_t* s;
    u32 r;
    s32 b;

    func_8002DF54(arg0);
    func_80017248(arg0);
    func_8002D9EC(arg0, 0x20, 0x40);
    if (((s8*)arg0)[0x3] == 0) {
        arg0[0x9A] = 0;
    } else {
        arg0[0x9A] = 1;
    }
    arg0[0x3] = 1;
    b = (s32)D_8009A1F8;
    if ((s16)(*(u16*)(arg0 + 0xE) -
              *(u16*)(((s8*)arg0)[0x14] * 0x54 + b + 0xE)) < -0x40) {
        *(s32*)(arg0 + 0x54) = 0;
        *(s32*)(arg0 + 0x50) = 0;
        arg0[0x9A] = 0;
        arg0[0x3] = 0;
        if (*(s16*)(arg0 + 0x7E) == 0) {
            func_800171E8(arg0, 1);
            *(s16*)(arg0 + 0xE) = D_800FA060_ovl11;
            r = func_8002DF78();
            s = &D_1F80004C;
            *(s32*)(arg0 + 0x20) = 0;
            *(s32*)(arg0 + 0x24) = 0xFFFE0000;
            arg0[0x6] = 9;
            *(s16*)(arg0 + 0x7C) = (u8)(r % 3) * 8 + 0x40;
            s->bytes[0x93] = 0x3C;
            s->bytes[0x92] = 7;
        } else {
            D_1F80004C.bytes[0x92] = 7;
            arg0[0x6] = 2;
            *(s16*)(arg0 + 0x7C) = 0x1E;
        }
    }
}
