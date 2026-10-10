#include "types.h"

void func_800FB030_ovl07(u8* obj);
void func_80017248(u8* obj);

void func_800FC7D4_ovl07(u8* arg0) {
    if (((signed char*)arg0)[0x45] == 1) {
        func_800FB030_ovl07(arg0);
    } else {
        func_80017248(arg0);
    }
}
