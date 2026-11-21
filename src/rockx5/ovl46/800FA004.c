#include "types.h"
#include "mmx5/globals.h"

extern u8 D_8009A1F8[];
extern s8 D_8009A424;
extern u8 D_800D1F3C;

void func_800FA004_ovl46(u8* o) {
    u8* p;
    u8* q;
    s32 i;

    if (--*(s16*)(o + 6) == 0) {
        q = D_8009A1F8;
        *(s16*)(q + 0xB6) += 0x100;
        if (*(s16*)(q + 0xB6) >= 0x300) {
            *(s16*)(q + 0xB6) = 0;
        }
        *(s16*)(o + 6) = 0x3C;
    }
    p = D_8009A1F8;
    p[0xF4] = 1;
    if (D_800D1F3C == 0 && D_8009A424 == 0) {
        func_8001E668();
        p[3] = 0;
        p[0x57] = 0;
        p[0xAB] = 0;
        func_8002C50C();
        for (i = 0; i < 16; i++) {
            o[0x26 + i] = 0;
        }
        if ((o[0x4C] & 0xCA) == 0xCA) {
            o[0x194] = 8;
            o[0x195] = 0xFF;
            o[0x1D] = 8;
            o[0] = 0x13;
            o[1] = 0;
            o[2] = 0;
            o[3] = 0;
            return;
        }
        o[0] = 0x15;
    }
}

extern void (*D_800FABD8_ovl46[])(u8*);
extern void func_800223E4(void);
extern void func_80022618(void);
extern void func_8002272C(void);
extern void run_text_box(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);

void func_800FA118_ovl46(u8* arg0) {
    D_800FABD8_ovl46[*(signed char*)(arg0 + 1)](arg0);
    func_800223E4();
    func_80022618();
    func_8002272C();
    run_text_box();
    func_8002C2C0();
    func_8002BD8C();
    func_800272B4();
}
