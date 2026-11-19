#include "types.h"
#include "mmx5/object.h"

void func_8004A57C(u8* arg0) {
    move_object(arg0);
    if (++*(s16*)(arg0 + 0x8C) >= 11) {
        *(s16*)(arg0 + 0x8C) = 0;
        arg0[5]++;
    }
}
