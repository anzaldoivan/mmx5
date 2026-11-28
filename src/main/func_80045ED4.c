#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern void func_80044F78(void* arg0);
extern void func_80046030(void* arg0);

void func_80045ED4(u8* a0) {
    move_object(a0);
    if (a0[0x70] == 0) {
        ((s32(*)())func_8002F8FC)(a0);
        if (a0[0x70] == 0) {
            return;
        }
    }
    func_80044F78(a0);
    func_80046030(a0);
}
