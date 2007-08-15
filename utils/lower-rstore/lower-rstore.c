/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'lower-rstore' (prefix='')
 */

#include "lower-rstore.h"

#define NR_SIG_ENTRIES	2

static char *signature[NR_SIG_ENTRIES] = {
  "rec-eval(<lower-rstore>,lower-rstore(<term>))",
  "rec-terminate(<lower-rstore>,<term>)",
};

/* Event handler for tool 'lower-rstore' */
ATerm lower_rstore_handler(int conn, ATerm term)
{
  ATerm in, out;
  /* We need some temporary variables during matching */
  ATerm t0;

  if(ATmatch(term, "rec-eval(lower-rstore(<term>))", &t0)) {
    return lower_rstore(conn, t0);
  }
  if(ATmatch(term, "rec-terminate(<term>)", &t0)) {
    rec_terminate(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-do(signature(<term>,<term>))", &in, &out)) {
    ATerm result = lower_rstore_checker(conn, in);
    if(!ATmatch(result, "[]"))
      ATfprintf(stderr, "warning: not in input signature:\n\t%\n\tl\n", result);
    return NULL;
  }

  ATerror("tool lower-rstore cannot handle term %t", term);
  return NULL; /* Silence the compiler */
}

/* Check the signature of the tool 'lower-rstore' */
ATerm lower_rstore_checker(int conn, ATerm siglist)
{
  return ATBcheckSignature(siglist, signature, NR_SIG_ENTRIES);
}
