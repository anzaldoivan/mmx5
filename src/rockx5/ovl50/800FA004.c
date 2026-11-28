#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"

extern s32 D_80093DD0[];
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;

void func_800FA004_ovl50(u8* arg0) {
    u8* p;
    s32* q;
    s32* b;
    s32 i;
    s32 m;

    if (++*(u16*)(arg0 + 6) & 1) {
        u8* p1 = D_8009A1F8.u;
        *(s16*)(p1 + 0xB6) = random_byte() % 5 + 0x104;
    } else {
        u8* p2 = D_8009A1F8.u;
        *(s16*)(p2 + 0xB6) = 0x100;
    }
    p = D_8009A1F8.u;
    *(s32*)(p + 0x60) += 0xFFFBBBBC;
    if (++*(s16*)(arg0 + 4) >= 0x1E) {
        *(s32*)(p + 0x60) = 0x1000000;
        func_8002385C(0x3A, 0xFF, 0);
        m = -1;
        b = D_80093DD0;
        q = b + 2;
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        D_80093E68 = 0;
        D_8009A42E = 0;
        D_800D50DE = 0;
        for (i = 13; i >= 0; i--) {
            *q++ = m;
        }
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}

extern void (*D_800FB3F8_ovl50[])(u8*);
extern void func_800223E4(void);
extern void func_80022618(void);
extern void func_8002272C(void);
extern void run_text_box(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);

void func_800FA14C_ovl50(u8* arg0) {
    D_800FB3F8_ovl50[*(signed char*)(arg0 + 1)](arg0);
    func_800223E4();
    func_80022618();
    func_8002272C();
    run_text_box();
    func_8002C2C0();
    func_8002BD8C();
    func_800272B4();
}
