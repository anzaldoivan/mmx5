#include "types.h"

extern void (*D_800F4FF8_ovl24[])(u8*);
extern void func_80022618(void);
extern void func_8002272C(void);
extern void func_80022E80(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);
extern void func_80024698(void);
extern void func_800176DC(void);

void func_800EFF14_ovl24(u8* arg0) {
    D_800F4FF8_ovl24[*(signed char*)(arg0 + 1)](arg0);
    if (*(signed char*)(arg0 + 1) < 10) {
        func_80022618();
        func_8002272C();
        func_80022E80();
        func_8002C2C0();
        func_8002BD8C();
        func_800272B4();
    } else {
        func_80022618();
        func_80024698();
        func_800176DC();
    }
}
