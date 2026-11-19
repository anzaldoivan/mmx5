#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/title.h"

void func_80055DEC(u8* arg0) {
    if (is_off_screen(arg0, 0x88, 0x88) == 1) {
        func_8002D720(arg0);
    }
}
