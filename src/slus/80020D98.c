#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"

extern void func_80012BD8(void);
extern void func_800132F8(s8 arg);
extern void func_80022D98(void);
extern void func_800272B4(void);
extern s8 D_8009A0A4;
extern u16 D_800C9320;
extern u8 D_800D51A0[];

void func_80020D98(u8* arg0) {
    u8* p;

    if (((s8*)arg0)[0x1C] == 0) {
        p = D_8009A420;
        if (((s8*)p)[4] == 0 &&
            ((D_800C9320 & 0x800) ||
             (((s8*)p)[6] == 0 && D_800D51A0[0] == 0xFF)) &&
            ((s8*)arg0)[0x10] == 0 && ((s8*)arg0)[0xF] == 0) {
            func_80012BD8();
            arg0[1] = 2;
            func_800272B4();
            return;
        }
    }
    if (D_8009A0A4 == 3) {
        arg0[1]++;
        func_800132F8(8);
    }
    random_byte();
    func_80022D98();
    func_800272B4();
}

extern s8 D_8009A424;
extern u8 D_8009A197;
extern u8 D_800C9310;
extern s32 D_80091D54;
extern u8 D_800D1C00[];

extern void func_80022D98(void);
extern void func_800272B4(void);
extern void func_800205AC(u8*);
extern void silence_sound(s32, s32);
extern void func_80017D88(void);
extern void func_80012BD8(void);

void func_80020E94(u8* arg0) {
    u8* p;

    if (D_8009A424 != 0) {
        func_80022D98();
        func_800272B4();
        return;
    }
    func_800205AC(arg0);
    D_8009A197 = 0;
    D_800C9310 = 1;
    silence_sound(0xFF, 0);
    if (arg0[0x43] == 0) {
        func_80017D88();
    }
    func_80012BD8();
    p = D_800D1C00;
    D_80091D54 = 0;
    p[0x10] = 0;
    p[0x11] = 0;
    p[0x14] = 0;
    p[0x16] = 0;
    p[0x17] = 0;
}
