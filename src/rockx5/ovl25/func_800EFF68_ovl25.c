#include "types.h"

extern s16 D_800F0CE4_ovl25;
extern void (*D_800F0770_ovl25[])(u8*);
extern void func_80022618(void);
extern void func_800272B4(void);

void func_800EFF68_ovl25(u8* arg0) {
    D_800F0CE4_ovl25 = 1;
    D_800F0770_ovl25[*(signed char*)(arg0 + 1)](arg0);
    func_80022618();
    func_800272B4();
}
