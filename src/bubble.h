//! @file

#ifndef _MMB_BUBBLE_H
#define _MMB_BUBBLE_H

#include "defs.h"
#include "vector.h"
#include "world.h"

extern Bubble * bubbleGen(World *world, Chunk *chunk);
extern void bubbleUpdate(World *world, Bubble *bubble);

#endif /* _MMB_BUBBLE_H */