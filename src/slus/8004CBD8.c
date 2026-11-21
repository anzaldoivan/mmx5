#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern void (*D_800774D8[])(u8*);
extern void func_80017348(u8* a0, s32 a1, s32 a2);

void func_8004CBD8(u8* arg0) {
    D_800774D8[(signed char)arg0[5]](arg0);
    func_8002FB58(arg0);
    func_80017348(arg0, 0x140, 0x40);
}

void func_8004CC34(u8* obj) {
    if ((s8)g_Player[5] == 0x3B) {
        g_Player[6] = 2;
    }
    clear_object_slot(obj);
}
