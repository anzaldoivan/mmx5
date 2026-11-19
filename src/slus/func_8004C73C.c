#include "types.h"
#include "mmx5/object.h"

extern signed char D_8009A0A5;
extern void (*D_800774E4[])(signed char*);

void func_8004C73C(signed char* arg0) {
    if (D_8009A0A5 != 0x3B && D_8009A0A5 != 0x11) {
        clear_object_slot();
    } else {
        D_800774E4[arg0[4]](arg0);
    }
}
