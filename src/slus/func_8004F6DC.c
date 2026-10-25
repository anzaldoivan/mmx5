#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8004F874(u8* obj);
extern void func_8004F730(u8* obj);
extern void func_8004F824(u8* obj);

void func_8004F6DC(u8* obj) {
    func_80017248(obj);
    func_8004F874(obj);
    if (((s8*)obj)[5] == 0) {
        func_8004F730(obj);
    } else {
        func_8004F824(obj);
    }
}
