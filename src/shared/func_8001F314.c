#include "types.h"

extern void (*D_80070F2C[])(u8*);
extern void func_800223E4(void);
extern void func_80022618(void);
extern void func_8002272C(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);

void func_8001F314(u8* arg0) {
    D_80070F2C[*(signed char*)(arg0 + 1)](arg0);
    func_800223E4();
    func_80022618();
    func_8002272C();
    func_8002BD8C();
    func_800272B4();
}
