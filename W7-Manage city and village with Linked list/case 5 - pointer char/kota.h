#ifndef KOTA_H
#define KOTA_H
#include "linked.h"
#include "convention.h"

typedef struct
{
    infotype info;
    address knama; //pointer ke telmt list
}kt;

boolean isEmptykt (kt *p);
boolean isCityInitialized(kt p);

void Initkt (kt *p);

#endif