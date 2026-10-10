#include "types.h"

extern s32 D_8009A1F8[];
extern void (*D_800EFA28_ovl21[])(u8*);
extern void func_800223E4(void);
extern void func_800222D0(void);
extern void func_80022618(void);
extern void func_8002272C(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);

void func_800EEBB8_ovl21(u8* arg0) {
    D_8009A1F8[5] = D_8009A1F8[2];
    D_8009A1F8[6] = D_8009A1F8[3];
    D_800EFA28_ovl21[*(signed char*)(arg0 + 1)](arg0);
    func_800223E4();
    func_800222D0();
    func_80022618();
    func_8002272C();
    func_8002C2C0();
    func_8002BD8C();
    func_800272B4();
}
