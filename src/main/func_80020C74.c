#include "types.h"
#include "mmx5/globals.h"

extern s32 select_file_load(void);

void func_80020C74(u8* arg0) {
    func_8002C50C();
    select_file_load();
    arg0[0] = 8;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
}
