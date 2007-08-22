/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'lift-rstore' (prefix='')
 */

#include "lift-rstore.h"

#define NR_SIG_ENTRIES	3

static char *signature[NR_SIG_ENTRIES] = {
  "rec-eval(<lift-rstore>,lift-rstore(<term>))",
  "rec-eval(<lift-rstore>,lift-rtuple(<term>))",
  "rec-terminate(<lift-rstore>,<term>)",
};

/* Event handler for tool 'lift-rstore' */
ATerm lift_rstore_handler(int conn, ATerm term)
{
  ATerm in, out;
  /* We need some temporary variables during matching */
  ATerm t0;

  if(ATmatch(term, "rec-eval(lift-rstore(<term>))", &t0)) {
    return lift_rstore(conn, t0);
  }
  if(ATmatch(term, "rec-eval(lift-rtuple(<term>))", &t0)) {
    return lift_rtuple(conn, t0);
  }
  if(ATmatch(term, "rec-terminate(<term>)", &t0)) {
    rec_terminate(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-do(signature(<term>,<term>))", &in, &out)) {
    ATerm result = lift_rstore_checker(conn, in);
    if(!ATmatch(result, "[]"))
      ATfprintf(stderr, "warning: not in input signature:\n\t%\n\tl\n", result);
    return NULL;
  }

  ATerror("tool lift-rstore cannot handle term %t", term);
  return NULL; /* Silence the compiler */
}

/* Check the signature of the tool 'lift-rstore' */
ATerm lift_rstore_checker(int conn, ATerm siglist)
{
  return ATBcheckSignature(siglist, signature, NR_SIG_ENTRIES);
}

