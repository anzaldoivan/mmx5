#include "types.h"

extern void func_80012BD8(void);
extern void func_800132F8(s8 arg);
extern void func_80022D98(void);
extern void func_800272B4(void);
extern s32 func_8002DF78(void);
extern s8 D_8009A0A4;
extern u8 D_8009A420[];
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
    func_8002DF78();
    func_80022D98();
    func_800272B4();
}
