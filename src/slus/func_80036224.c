#include "types.h"
#include "mmx5/globals.h"

s32 try_enter_ladder(u8* arg0);
s32 func_800437FC(u8* arg0);
s32 func_8003952C(u8* arg0);
s32 func_8004387C(u8* arg0);
s32 func_80041A54(u8* arg0);
s32 func_800395E8(u8* arg0);
void func_8003A7E4(u8* arg0);
void func_8003A670(u8* arg0);

void func_80036224(u8* arg0) {
    func_80043B88(arg0);
    if (func_80039ECC(arg0) != 0) {
        return;
    }
    if (try_enter_ladder(arg0) != 0) {
        return;
    }
    if (func_800437FC(arg0) != 0) {
        return;
    }
    if (func_8003952C(arg0) != 0) {
        return;
    }
    if (func_8004387C(arg0) != 0) {
        return;
    }
    if (func_80041A54(arg0) != 0) {
        return;
    }
    if (func_800395E8(arg0) != 0) {
        func_8003A7E4(arg0);
    } else {
        animate_object(arg0);
        if (((signed char*)arg0)[0x46] < 0) {
            func_8003A670(arg0);
        }
    }
}
