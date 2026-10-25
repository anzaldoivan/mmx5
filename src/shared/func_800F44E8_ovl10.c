/* Shared body (DK-5), from the banked draft of func_800F44E8_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

#define S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_80016490(s32, s32, void*);
void func_800F6250_ovl10(void*);
void func_80017248(void*);
void* func_8002D27C(void);
void* func_8002D1A4(void);

void DEDUP_NAME(void* p) {
    void* self = p;
    void* r;
    void* q;

    if (S8(self, 0x45) == 0x20) {
        func_80016490(2, 0x2C, self);
    }
    func_800F6250_ovl10(self);
    func_80017248(self);
    if (S8(self, 0x45) != 1) {
        return;
    }
    r = func_8002D27C();
    if (r != 0) {
        U8(r, 0) = 0x41;
        U8(r, 1) = 0x23;
        U8(r, 2) = 2;
        S32(r, 0x3C) = S32(self, 0x3C);
        U16(r, 0x40) = U16(self, 0x40);
        S32(r, 0x30) = S32(self, 0x30);
        U16(r, 0x42) = U16(self, 0x42) & 0x7FFF;
        U8(r, 0x15) = U8(self, 0x15);
        U8(r, 0x14) = U8(self, 0x14);
        S32(r, 0x8) = S32(self, 0x8);
        S32(r, 0xC) = S32(self, 0xC) - 0x200000;
    }
    q = func_8002D1A4();
    if (q != 0) {
        U8(q, 0) = 0x41;
        U8(q, 1) = 0x27;
        U8(q, 2) = 0;
        U8(q, 4) = 0xA;
        S32(q, 0x24) = 0x40000;
        S32(q, 0x20) = 0;
        U16(q, 0x40) = U16(self, 0x40);
        U16(q, 0x42) = U16(self, 0x42) & 0x7FFF;
        S32(q, 0x30) = S32(self, 0x30);
        S32(q, 0x3C) = S32(self, 0x3C);
        U8(q, 0x14) = U8(self, 0x14);
        p = PTR(self, 0x8);
        PTR(q, 0x8) = p;
        S32(q, 0xC) = S32(self, 0xC) - 0x200000;
        U8(q, 0x15) = U8(self, 0x15);
        PTR(q, 0x7C) = self;
    }
    U8(self, 6) = 2;
}
