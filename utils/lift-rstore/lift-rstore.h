/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'lift-rstore' (prefix='')
 */

#ifndef _LIFT_RSTORE_H
#define _LIFT_RSTORE_H

#include <atb-tool.h>

/* Prototypes for functions called from the event handler */
ATerm lift_rstore(int conn, ATerm);
void rec_terminate(int conn, ATerm);
ATerm lift_rtuple(int conn, ATerm);
extern ATerm lift_rstore_handler(int conn, ATerm term);
extern ATerm lift_rstore_checker(int conn, ATerm sigs);

#endif
