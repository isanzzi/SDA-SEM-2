#include "kota.h"

boolean isEmptykt (kt *p){
    return (p->info == nil && p->knama == nil);
}

boolean isCityInitialized(kt p) {
    return (p.info != nil);
}

void Initkt (kt *p){
    p->info=nil;
    p->knama=nil;
}