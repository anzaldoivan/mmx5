#include "types.h"
#include "mmx5/object.h"

void func_8004849C(u8* a0) {
    move_object(a0);
    if (((s8*)a0)[0x98] != 0 || --a0[0x8D] == 0) {
        a0[4] = 2;
    }
}
