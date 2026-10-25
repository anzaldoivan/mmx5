#include "types.h"
#include "addr.h"

extern int func_8002D7A0();
extern int func_8002D760();
extern void func_8002D720(u8* arg0);

void func_800F26EC_ovl11(u8* arg0) {
    if (D_1F80004C.bytes[0x86] == 0) {
        if (((s8*)arg0)[4] == 4) {
            func_8002D7A0(arg0);
        } else {
            func_8002D760(arg0);
        }
    } else if (((s8*)arg0)[2] == 9) {
        if (((s8*)arg0)[4] == 4) {
            func_8002D7A0(arg0);
        } else {
            func_8002D760(arg0);
        }
    } else {
        func_8002D720(arg0);
    }
}
