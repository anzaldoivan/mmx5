#include "types.h"

extern u8 D_8009A420[];

void func_8001E6AC(void);
void func_80012EAC(void);

void func_800217CC(u8* arg0) {
    u8* p = D_8009A420;

    if (((signed char*)p)[4] == 0) {
        if (p[7] == 0) {
            func_8001E6AC();
            func_80012EAC();
        } else {
            arg0[1] = 0;
        }
    }
}
