#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_8002D720(u8* arg0) {
    u8* p;

    p = *(u8**)(arg0 + 0x10);
    if (p != 0) {
        *p |= 0x80;
    }
    clear_object_slot(arg0);
}
