#include "types.h"
#include "addr.h"

extern void func_80016490(s32, s32, void*);
extern s32 func_8002DF78(void);
extern u8 D_8009A1F8[];
extern u8 D_800FD6EC_ovl27[];
extern u8 D_800FD6E8_ovl27[];

void func_800F8C90_ovl27(u8* arg0) {
    s8 state;
    u8* p;

    if ((s8)arg0[0x45] == 2) {
        func_80016490(2, 0x6B, arg0);
    }
    state = arg0[0x45];
    if (state == 1) {
        *(s32*)(arg0 + 0x68) = 0;
        *(void**)(arg0 + 0x50) = D_800FD6EC_ovl27;
        *(void**)(arg0 + 0x54) = D_800FD6E8_ovl27;
        if (func_8002DF78() & 1) {
            u8* d = D_8009A1F8;
            *(s16*)(D_1F80004C.bytes + 0x86) = *(u16*)(d + 0xA) + 0x50;
            D_1F80004C.bytes[0x8B] = 0;
        } else {
            u8* d = D_8009A1F8;
            *(s16*)(D_1F80004C.bytes + 0x86) = *(u16*)(d + 0xA) + 0xF0;
            D_1F80004C.bytes[0x8B] = state;
        }
        p = D_1F80004C.bytes;
        if ((*(u8**)(p + 0x80))[0x8A] == 2) {
            u8* d = D_8009A1F8;
            *(s16*)(p + 0x86) = *(u16*)(d + 0xA) + 0xA0;
            if (func_8002DF78() & 1) {
                D_1F80004C.bytes[0x8B] = 0;
            } else {
                D_1F80004C.bytes[0x8B] = 1;
            }
        }
        arg0[6]++;
    }
}
