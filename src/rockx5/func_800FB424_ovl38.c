#include "types.h"
#include "addr.h"

extern void (*D_800FD888_ovl38[])(u8*);
extern s32 func_8002FB58(u8*);

void func_800FB424_ovl38(u8* arg0) {
    D_800FD888_ovl38[((s8*)arg0)[4]](arg0);
    if (((s8*)arg0)[2] == 0 && D_1F80004C.bytes[0x8D] != 0) {
        func_8002FB58(arg0);
    }
}
