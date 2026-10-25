#include "types.h"

extern void func_8002DF54(u8* a0);
extern s32 func_8002F8FC(u8* a0);
extern void func_80044F78(void* arg0);
extern void func_80046030(void* arg0);

void func_80045ED4(u8* a0) {
    func_8002DF54(a0);
    if (a0[0x70] == 0) {
        func_8002F8FC(a0);
        if (a0[0x70] == 0) {
            return;
        }
    }
    func_80044F78(a0);
    func_80046030(a0);
}
