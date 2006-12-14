#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "ParsedRStore.h"

/**
 * Converts a string to an ATermList of integers (ASCII values). 
 * \param[in] str An ASCII string
 * \return An ATermList containing the ASCII values of #arg as ATermInts
 */
ATerm PRS_stringToChars(const char *str) {
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

/**
 * Converts an ASCII char to an ATermInt. 
 * \param[in] ch an ASCII character
 * \return An ATerm representing the ASCII value of #arg
 */
ATerm PRS_byteToChar(char ch) {
    return (ATerm) ATmakeInt(ch);
}

/**
 * Converts a list of integers (ASCII values) to a C string. 
 * \param[in] arg An ATermList with ATermInts, such as [32,32,10]
 * \return String containing the characters from #arg as characters
 */
char *PRS_charsToString(ATerm arg) {
  ATermList list = (ATermList) arg;
  int len = ATgetLength(list);
  int i;
  char *str;

  str = (char *) malloc(len+1);
  if (str == NULL) {
      return NULL;
  }

  for (i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    str[i] = (char) ATgetInt((ATermInt) ATgetFirst(list));
  }
  str[i] = '\0';

  return str;
}

char PRS_charToByte(ATerm arg) {
    return (char) ATgetInt((ATermInt) arg);
}


typedef struct ATerm _PRS_OptLayout;
typedef struct ATerm _PRS_Layout;
typedef struct ATerm _PRS_LexLayoutList;
typedef struct ATerm _PRS_RElem;
typedef struct ATerm _PRS_RType;
typedef struct ATerm _PRS_RTuple;
typedef struct ATerm _PRS_RStore;
typedef struct ATerm _PRS_Start;
typedef struct ATerm _PRS_RElemElements;
typedef struct ATerm _PRS_RTypeColumnTypes;
typedef struct ATerm _PRS_RTupleRtuples;
typedef struct ATerm _PRS_LexStrChar;
typedef struct ATerm _PRS_StrChar;
typedef struct ATerm _PRS_LexStrCon;
typedef struct ATerm _PRS_StrCon;
typedef struct ATerm _PRS_LexStrCharChars;
typedef struct ATerm _PRS_LexNatCon;
typedef struct ATerm _PRS_NatCon;
typedef struct ATerm _PRS_LexIdCon;
typedef struct ATerm _PRS_IdCon;
typedef struct ATerm _PRS_LexIntCon;
typedef struct ATerm _PRS_IntCon;
typedef struct ATerm _PRS_LexLayout;
typedef struct ATerm _PRS_Location;
typedef struct ATerm _PRS_Area;

/**
 * Initializes the full API. Forgetting to call this function before using the API will lead to strange behaviour. ATinit() needs to be called before this function.
 */
void PRS_initParsedRStoreApi(void) {
  init_ParsedRStore_dict();
}

/**
 * Protect a PRS_OptLayout from the ATerm garbage collector. Every PRS_OptLayout that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_OptLayout
 */
void PRS_protectOptLayout(PRS_OptLayout *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_OptLayout from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_OptLayout
 */
void PRS_unprotectOptLayout(PRS_OptLayout *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_Layout from the ATerm garbage collector. Every PRS_Layout that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_Layout
 */
void PRS_protectLayout(PRS_Layout *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_Layout from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_Layout
 */
void PRS_unprotectLayout(PRS_Layout *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_LexLayoutList from the ATerm garbage collector. Every PRS_LexLayoutList that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_LexLayoutList
 */
void PRS_protectLexLayoutList(PRS_LexLayoutList *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_LexLayoutList from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_LexLayoutList
 */
void PRS_unprotectLexLayoutList(PRS_LexLayoutList *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_RElem from the ATerm garbage collector. Every PRS_RElem that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_RElem
 */
void PRS_protectRElem(PRS_RElem *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_RElem from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_RElem
 */
void PRS_unprotectRElem(PRS_RElem *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_RType from the ATerm garbage collector. Every PRS_RType that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_RType
 */
void PRS_protectRType(PRS_RType *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_RType from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_RType
 */
void PRS_unprotectRType(PRS_RType *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_RTuple from the ATerm garbage collector. Every PRS_RTuple that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_RTuple
 */
void PRS_protectRTuple(PRS_RTuple *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_RTuple from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_RTuple
 */
void PRS_unprotectRTuple(PRS_RTuple *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_RStore from the ATerm garbage collector. Every PRS_RStore that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_RStore
 */
void PRS_protectRStore(PRS_RStore *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_RStore from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_RStore
 */
void PRS_unprotectRStore(PRS_RStore *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_Start from the ATerm garbage collector. Every PRS_Start that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_Start
 */
void PRS_protectStart(PRS_Start *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_Start from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_Start
 */
void PRS_unprotectStart(PRS_Start *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_RElemElements from the ATerm garbage collector. Every PRS_RElemElements that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_RElemElements
 */
void PRS_protectRElemElements(PRS_RElemElements *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_RElemElements from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_RElemElements
 */
void PRS_unprotectRElemElements(PRS_RElemElements *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_RTypeColumnTypes from the ATerm garbage collector. Every PRS_RTypeColumnTypes that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_RTypeColumnTypes
 */
void PRS_protectRTypeColumnTypes(PRS_RTypeColumnTypes *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_RTypeColumnTypes from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_RTypeColumnTypes
 */
void PRS_unprotectRTypeColumnTypes(PRS_RTypeColumnTypes *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_RTupleRtuples from the ATerm garbage collector. Every PRS_RTupleRtuples that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_RTupleRtuples
 */
void PRS_protectRTupleRtuples(PRS_RTupleRtuples *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_RTupleRtuples from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_RTupleRtuples
 */
void PRS_unprotectRTupleRtuples(PRS_RTupleRtuples *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_LexStrChar from the ATerm garbage collector. Every PRS_LexStrChar that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_LexStrChar
 */
void PRS_protectLexStrChar(PRS_LexStrChar *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_LexStrChar from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_LexStrChar
 */
void PRS_unprotectLexStrChar(PRS_LexStrChar *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_StrChar from the ATerm garbage collector. Every PRS_StrChar that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_StrChar
 */
void PRS_protectStrChar(PRS_StrChar *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_StrChar from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_StrChar
 */
void PRS_unprotectStrChar(PRS_StrChar *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_LexStrCon from the ATerm garbage collector. Every PRS_LexStrCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_LexStrCon
 */
void PRS_protectLexStrCon(PRS_LexStrCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_LexStrCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_LexStrCon
 */
void PRS_unprotectLexStrCon(PRS_LexStrCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_StrCon from the ATerm garbage collector. Every PRS_StrCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_StrCon
 */
void PRS_protectStrCon(PRS_StrCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_StrCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_StrCon
 */
void PRS_unprotectStrCon(PRS_StrCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_LexStrCharChars from the ATerm garbage collector. Every PRS_LexStrCharChars that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_LexStrCharChars
 */
void PRS_protectLexStrCharChars(PRS_LexStrCharChars *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_LexStrCharChars from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_LexStrCharChars
 */
void PRS_unprotectLexStrCharChars(PRS_LexStrCharChars *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_LexNatCon from the ATerm garbage collector. Every PRS_LexNatCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_LexNatCon
 */
void PRS_protectLexNatCon(PRS_LexNatCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_LexNatCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_LexNatCon
 */
void PRS_unprotectLexNatCon(PRS_LexNatCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_NatCon from the ATerm garbage collector. Every PRS_NatCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_NatCon
 */
void PRS_protectNatCon(PRS_NatCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_NatCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_NatCon
 */
void PRS_unprotectNatCon(PRS_NatCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_LexIdCon from the ATerm garbage collector. Every PRS_LexIdCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_LexIdCon
 */
void PRS_protectLexIdCon(PRS_LexIdCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_LexIdCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_LexIdCon
 */
void PRS_unprotectLexIdCon(PRS_LexIdCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_IdCon from the ATerm garbage collector. Every PRS_IdCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_IdCon
 */
void PRS_protectIdCon(PRS_IdCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_IdCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_IdCon
 */
void PRS_unprotectIdCon(PRS_IdCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_LexIntCon from the ATerm garbage collector. Every PRS_LexIntCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_LexIntCon
 */
void PRS_protectLexIntCon(PRS_LexIntCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_LexIntCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_LexIntCon
 */
void PRS_unprotectLexIntCon(PRS_LexIntCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_IntCon from the ATerm garbage collector. Every PRS_IntCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_IntCon
 */
void PRS_protectIntCon(PRS_IntCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_IntCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_IntCon
 */
void PRS_unprotectIntCon(PRS_IntCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_LexLayout from the ATerm garbage collector. Every PRS_LexLayout that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_LexLayout
 */
void PRS_protectLexLayout(PRS_LexLayout *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_LexLayout from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_LexLayout
 */
void PRS_unprotectLexLayout(PRS_LexLayout *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_Location from the ATerm garbage collector. Every PRS_Location that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_Location
 */
void PRS_protectLocation(PRS_Location *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_Location from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_Location
 */
void PRS_unprotectLocation(PRS_Location *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PRS_Area from the ATerm garbage collector. Every PRS_Area that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PRS_Area
 */
void PRS_protectArea(PRS_Area *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PRS_Area from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PRS_Area
 */
void PRS_unprotectArea(PRS_Area *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Transforms an ATerm to a PRS_OptLayout. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_OptLayout that was encoded by \arg
 */
PRS_OptLayout PRS_OptLayoutFromTerm(ATerm t) {
  return (PRS_OptLayout)t;
}

/**
 * Transforms a PRS_OptLayoutto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_OptLayout to be converted
 * \return ATerm that represents the PRS_OptLayout
 */
ATerm PRS_OptLayoutToTerm(PRS_OptLayout arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_Layout. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_Layout that was encoded by \arg
 */
PRS_Layout PRS_LayoutFromTerm(ATerm t) {
  return (PRS_Layout)t;
}

/**
 * Transforms a PRS_Layoutto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_Layout to be converted
 * \return ATerm that represents the PRS_Layout
 */
ATerm PRS_LayoutToTerm(PRS_Layout arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_LexLayoutList. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_LexLayoutList that was encoded by \arg
 */
PRS_LexLayoutList PRS_LexLayoutListFromTerm(ATerm t) {
  return (PRS_LexLayoutList)t;
}

/**
 * Transforms a PRS_LexLayoutListto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_LexLayoutList to be converted
 * \return ATerm that represents the PRS_LexLayoutList
 */
ATerm PRS_LexLayoutListToTerm(PRS_LexLayoutList arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_RElem. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_RElem that was encoded by \arg
 */
PRS_RElem PRS_RElemFromTerm(ATerm t) {
  return (PRS_RElem)t;
}

/**
 * Transforms a PRS_RElemto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_RElem to be converted
 * \return ATerm that represents the PRS_RElem
 */
ATerm PRS_RElemToTerm(PRS_RElem arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_RType. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_RType that was encoded by \arg
 */
PRS_RType PRS_RTypeFromTerm(ATerm t) {
  return (PRS_RType)t;
}

/**
 * Transforms a PRS_RTypeto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_RType to be converted
 * \return ATerm that represents the PRS_RType
 */
ATerm PRS_RTypeToTerm(PRS_RType arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_RTuple. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_RTuple that was encoded by \arg
 */
PRS_RTuple PRS_RTupleFromTerm(ATerm t) {
  return (PRS_RTuple)t;
}

/**
 * Transforms a PRS_RTupleto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_RTuple to be converted
 * \return ATerm that represents the PRS_RTuple
 */
ATerm PRS_RTupleToTerm(PRS_RTuple arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_RStore. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_RStore that was encoded by \arg
 */
PRS_RStore PRS_RStoreFromTerm(ATerm t) {
  return (PRS_RStore)t;
}

/**
 * Transforms a PRS_RStoreto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_RStore to be converted
 * \return ATerm that represents the PRS_RStore
 */
ATerm PRS_RStoreToTerm(PRS_RStore arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_Start. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_Start that was encoded by \arg
 */
PRS_Start PRS_StartFromTerm(ATerm t) {
  return (PRS_Start)t;
}

/**
 * Transforms a PRS_Startto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_Start to be converted
 * \return ATerm that represents the PRS_Start
 */
ATerm PRS_StartToTerm(PRS_Start arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_RElemElements. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_RElemElements that was encoded by \arg
 */
PRS_RElemElements PRS_RElemElementsFromTerm(ATerm t) {
  return (PRS_RElemElements)t;
}

/**
 * Transforms a PRS_RElemElementsto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_RElemElements to be converted
 * \return ATerm that represents the PRS_RElemElements
 */
ATerm PRS_RElemElementsToTerm(PRS_RElemElements arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_RTypeColumnTypes. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_RTypeColumnTypes that was encoded by \arg
 */
PRS_RTypeColumnTypes PRS_RTypeColumnTypesFromTerm(ATerm t) {
  return (PRS_RTypeColumnTypes)t;
}

/**
 * Transforms a PRS_RTypeColumnTypesto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_RTypeColumnTypes to be converted
 * \return ATerm that represents the PRS_RTypeColumnTypes
 */
ATerm PRS_RTypeColumnTypesToTerm(PRS_RTypeColumnTypes arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_RTupleRtuples. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_RTupleRtuples that was encoded by \arg
 */
PRS_RTupleRtuples PRS_RTupleRtuplesFromTerm(ATerm t) {
  return (PRS_RTupleRtuples)t;
}

/**
 * Transforms a PRS_RTupleRtuplesto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_RTupleRtuples to be converted
 * \return ATerm that represents the PRS_RTupleRtuples
 */
ATerm PRS_RTupleRtuplesToTerm(PRS_RTupleRtuples arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_LexStrChar. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_LexStrChar that was encoded by \arg
 */
PRS_LexStrChar PRS_LexStrCharFromTerm(ATerm t) {
  return (PRS_LexStrChar)t;
}

/**
 * Transforms a PRS_LexStrCharto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_LexStrChar to be converted
 * \return ATerm that represents the PRS_LexStrChar
 */
ATerm PRS_LexStrCharToTerm(PRS_LexStrChar arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_StrChar. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_StrChar that was encoded by \arg
 */
PRS_StrChar PRS_StrCharFromTerm(ATerm t) {
  return (PRS_StrChar)t;
}

/**
 * Transforms a PRS_StrCharto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_StrChar to be converted
 * \return ATerm that represents the PRS_StrChar
 */
ATerm PRS_StrCharToTerm(PRS_StrChar arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_LexStrCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_LexStrCon that was encoded by \arg
 */
PRS_LexStrCon PRS_LexStrConFromTerm(ATerm t) {
  return (PRS_LexStrCon)t;
}

/**
 * Transforms a PRS_LexStrConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_LexStrCon to be converted
 * \return ATerm that represents the PRS_LexStrCon
 */
ATerm PRS_LexStrConToTerm(PRS_LexStrCon arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_StrCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_StrCon that was encoded by \arg
 */
PRS_StrCon PRS_StrConFromTerm(ATerm t) {
  return (PRS_StrCon)t;
}

/**
 * Transforms a PRS_StrConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_StrCon to be converted
 * \return ATerm that represents the PRS_StrCon
 */
ATerm PRS_StrConToTerm(PRS_StrCon arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_LexStrCharChars. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_LexStrCharChars that was encoded by \arg
 */
PRS_LexStrCharChars PRS_LexStrCharCharsFromTerm(ATerm t) {
  return (PRS_LexStrCharChars)t;
}

/**
 * Transforms a PRS_LexStrCharCharsto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_LexStrCharChars to be converted
 * \return ATerm that represents the PRS_LexStrCharChars
 */
ATerm PRS_LexStrCharCharsToTerm(PRS_LexStrCharChars arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_LexNatCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_LexNatCon that was encoded by \arg
 */
PRS_LexNatCon PRS_LexNatConFromTerm(ATerm t) {
  return (PRS_LexNatCon)t;
}

/**
 * Transforms a PRS_LexNatConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_LexNatCon to be converted
 * \return ATerm that represents the PRS_LexNatCon
 */
ATerm PRS_LexNatConToTerm(PRS_LexNatCon arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_NatCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_NatCon that was encoded by \arg
 */
PRS_NatCon PRS_NatConFromTerm(ATerm t) {
  return (PRS_NatCon)t;
}

/**
 * Transforms a PRS_NatConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_NatCon to be converted
 * \return ATerm that represents the PRS_NatCon
 */
ATerm PRS_NatConToTerm(PRS_NatCon arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_LexIdCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_LexIdCon that was encoded by \arg
 */
PRS_LexIdCon PRS_LexIdConFromTerm(ATerm t) {
  return (PRS_LexIdCon)t;
}

/**
 * Transforms a PRS_LexIdConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_LexIdCon to be converted
 * \return ATerm that represents the PRS_LexIdCon
 */
ATerm PRS_LexIdConToTerm(PRS_LexIdCon arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_IdCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_IdCon that was encoded by \arg
 */
PRS_IdCon PRS_IdConFromTerm(ATerm t) {
  return (PRS_IdCon)t;
}

/**
 * Transforms a PRS_IdConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_IdCon to be converted
 * \return ATerm that represents the PRS_IdCon
 */
ATerm PRS_IdConToTerm(PRS_IdCon arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_LexIntCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_LexIntCon that was encoded by \arg
 */
PRS_LexIntCon PRS_LexIntConFromTerm(ATerm t) {
  return (PRS_LexIntCon)t;
}

/**
 * Transforms a PRS_LexIntConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_LexIntCon to be converted
 * \return ATerm that represents the PRS_LexIntCon
 */
ATerm PRS_LexIntConToTerm(PRS_LexIntCon arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_IntCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_IntCon that was encoded by \arg
 */
PRS_IntCon PRS_IntConFromTerm(ATerm t) {
  return (PRS_IntCon)t;
}

/**
 * Transforms a PRS_IntConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_IntCon to be converted
 * \return ATerm that represents the PRS_IntCon
 */
ATerm PRS_IntConToTerm(PRS_IntCon arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_LexLayout. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_LexLayout that was encoded by \arg
 */
PRS_LexLayout PRS_LexLayoutFromTerm(ATerm t) {
  return (PRS_LexLayout)t;
}

/**
 * Transforms a PRS_LexLayoutto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_LexLayout to be converted
 * \return ATerm that represents the PRS_LexLayout
 */
ATerm PRS_LexLayoutToTerm(PRS_LexLayout arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_Location. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_Location that was encoded by \arg
 */
PRS_Location PRS_LocationFromTerm(ATerm t) {
  return (PRS_Location)t;
}

/**
 * Transforms a PRS_Locationto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_Location to be converted
 * \return ATerm that represents the PRS_Location
 */
ATerm PRS_LocationToTerm(PRS_Location arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PRS_Area. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PRS_Area that was encoded by \arg
 */
PRS_Area PRS_AreaFromTerm(ATerm t) {
  return (PRS_Area)t;
}

/**
 * Transforms a PRS_Areato an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PRS_Area to be converted
 * \return ATerm that represents the PRS_Area
 */
ATerm PRS_AreaToTerm(PRS_Area arg) {
  return (ATerm)arg;
}

/**
 * Retrieve the length of a PRS_LexLayoutList. 
 * \param[in] arg input PRS_LexLayoutList
 * \return The number of elements in the PRS_LexLayoutList
 */
int PRS_getLexLayoutListLength (PRS_LexLayoutList arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a PRS_LexLayoutList. 
 * \param[in] arg PRS_LexLayoutList to be reversed
 * \return a reversed #arg
 */
PRS_LexLayoutList PRS_reverseLexLayoutList(PRS_LexLayoutList arg) {
  return (PRS_LexLayoutList) ATreverse((ATermList) arg);
}

/**
 * Append a PRS_LexLayout to the end of a PRS_LexLayoutList. 
 * \param[in] arg PRS_LexLayoutList to append the PRS_LexLayout to
 * \param[in] elem PRS_LexLayout to be appended
 * \return new PRS_LexLayoutList with #elem appended
 */
PRS_LexLayoutList PRS_appendLexLayoutList(PRS_LexLayoutList arg, PRS_LexLayout elem) {
  return (PRS_LexLayoutList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two PRS_LexLayoutLists. 
 * \param[in] arg0 first PRS_LexLayoutList
 * \param[in] arg1 second PRS_LexLayoutList
 * \return PRS_LexLayoutList with the elements of #arg0 before the elements of #arg1
 */
PRS_LexLayoutList PRS_concatLexLayoutList(PRS_LexLayoutList arg0, PRS_LexLayoutList arg1) {
  return (PRS_LexLayoutList) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a PRS_LexLayoutList. 
 * \param[in] arg PRS_LexLayoutList to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new PRS_LexLayoutList with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
PRS_LexLayoutList PRS_sliceLexLayoutList(PRS_LexLayoutList arg, int start, int end) {
  return (PRS_LexLayoutList) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the PRS_LexLayout at #index from a PRS_LexLayoutList. 
 * \param[in] arg PRS_LexLayoutList to retrieve the PRS_LexLayout from
 * \param[in] index index to use to point in the PRS_LexLayoutList
 * \return PRS_LexLayout at position #index in #arg
 */
PRS_LexLayout PRS_getLexLayoutListLexLayoutAt(PRS_LexLayoutList arg, int index) {
 return (PRS_LexLayout)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the PRS_LexLayout at #index from a PRS_LexLayoutList by a new one. 
 * \param[in] arg PRS_LexLayoutList to retrieve the PRS_LexLayout from
 * \param[in] elem new PRS_LexLayout to replace another
 * \param[in] index index to use to point in the PRS_LexLayoutList
 * \return A new PRS_LexLayoutListwith #elem replaced in #arg at position #index
 */
PRS_LexLayoutList PRS_replaceLexLayoutListLexLayoutAt(PRS_LexLayoutList arg, PRS_LexLayout elem, int index) {
 return (PRS_LexLayoutList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a PRS_LexLayoutList of 2 consecutive elements. 
 * \param[in] elem1 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \param[in] elem2 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \return A new PRS_LexLayoutList consisting of 2 PRS_LexLayouts
 */
PRS_LexLayoutList PRS_makeLexLayoutList2(PRS_LexLayout elem1, PRS_LexLayout elem2) {
  return (PRS_LexLayoutList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a PRS_LexLayoutList of 3 consecutive elements. 
 * \param[in] elem1 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \param[in] elem2 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \param[in] elem3 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \return A new PRS_LexLayoutList consisting of 3 PRS_LexLayouts
 */
PRS_LexLayoutList PRS_makeLexLayoutList3(PRS_LexLayout elem1, PRS_LexLayout elem2, PRS_LexLayout elem3) {
  return (PRS_LexLayoutList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a PRS_LexLayoutList of 4 consecutive elements. 
 * \param[in] elem1 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \param[in] elem2 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \param[in] elem3 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \param[in] elem4 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \return A new PRS_LexLayoutList consisting of 4 PRS_LexLayouts
 */
PRS_LexLayoutList PRS_makeLexLayoutList4(PRS_LexLayout elem1, PRS_LexLayout elem2, PRS_LexLayout elem3, PRS_LexLayout elem4) {
  return (PRS_LexLayoutList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a PRS_LexLayoutList of 5 consecutive elements. 
 * \param[in] elem1 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \param[in] elem2 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \param[in] elem3 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \param[in] elem4 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \param[in] elem5 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \return A new PRS_LexLayoutList consisting of 5 PRS_LexLayouts
 */
PRS_LexLayoutList PRS_makeLexLayoutList5(PRS_LexLayout elem1, PRS_LexLayout elem2, PRS_LexLayout elem3, PRS_LexLayout elem4, PRS_LexLayout elem5) {
  return (PRS_LexLayoutList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a PRS_LexLayoutList of 6 consecutive elements. 
 * \param[in] elem1 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \param[in] elem2 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \param[in] elem3 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \param[in] elem4 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \param[in] elem5 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \param[in] elem6 One PRS_LexLayout element of the new PRS_LexLayoutList
 * \return A new PRS_LexLayoutList consisting of 6 PRS_LexLayouts
 */
PRS_LexLayoutList PRS_makeLexLayoutList6(PRS_LexLayout elem1, PRS_LexLayout elem2, PRS_LexLayout elem3, PRS_LexLayout elem4, PRS_LexLayout elem5, PRS_LexLayout elem6) {
  return (PRS_LexLayoutList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the number of elements in a PRS_RElemElements. 
 * \param[in] arg input PRS_RElemElements
 * \return The number of elements in #arg, excluding any separators
 */
int PRS_getRElemElementsLength (PRS_RElemElements arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}

/**
 * Reverses the elements of a PRS_RElemElements. Note that separators are reversed with the list, but the order in which each set of separators inbetween two elements occurs does not change
 * \param[in] arg PRS_RElemElements to be reversed
 * \return #arg reversed
 */
PRS_RElemElements PRS_reverseRElemElements(PRS_RElemElements arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (PRS_RElemElements) result;
}

/**
 * Append a PRS_RElem to the end of a PRS_RElemElements. 
 * \param[in] arg PRS_RElemElements to append the PRS_RElem to
 * \param[in] elem PRS_RElem to be appended
 * \return new PRS_RElemElements with #elem appended after the separators
 */
PRS_RElemElements PRS_appendRElemElements(PRS_RElemElements arg0, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RElem arg1) {
  return PRS_concatRElemElements(arg0, wsAfterHead, wsAfterSep, PRS_makeRElemElementsSingle(arg1));
}

/**
 * Concatenate two PRS_RElemElementss. 
 * \param[in] arg0 first PRS_RElemElements
 * \param[in] arg1 second PRS_RElemElements
 * \return PRS_RElemElements with the elements of #arg0 before the elements of #arg1, with the separators in between.
 */
PRS_RElemElements PRS_concatRElemElements(PRS_RElemElements arg0, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RElemElements arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = PRS_makeRElemElementsMany((PRS_RElem)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (PRS_RElemElements) ATgetNext((ATermList) arg1);
  return (PRS_RElemElements) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a PRS_RElemElements. 
 * \param[in] arg PRS_RElemElements to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new PRS_RElemElements with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
PRS_RElemElements PRS_sliceRElemElements(PRS_RElemElements arg, int start, int end) {
  return (PRS_RElemElements) ATgetSlice((ATermList) arg, start * 4, end * 4);
}

/**
 * Retrieve the PRS_RElem at #index from a PRS_RElemElements. 
 * \param[in] arg PRS_RElemElements to retrieve the PRS_RElem from
 * \param[in] index index to use to point in the PRS_RElemElements
 * \return PRS_RElem at position #index in #arg
 */
PRS_RElem PRS_getRElemElementsRElemAt(PRS_RElemElements arg, int index) {
 return (PRS_RElem)ATelementAt((ATermList) arg,index * 4);
}

/**
 * Replace the PRS_RElem at #index from a PRS_RElemElements by a new one. 
 * \param[in] arg PRS_RElemElements to retrieve the PRS_RElem from
 * \param[in] elem new PRS_RElem to replace another
 * \param[in] index index to use to point in the PRS_RElemElements
 * \return A new PRS_RElemElementswith #elem replaced in #arg at position #index
 */
PRS_RElemElements PRS_replaceRElemElementsRElemAt(PRS_RElemElements arg, PRS_RElem elem, int index) {
 return (PRS_RElemElements) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}

/**
 * Builds a PRS_RElemElements of 2 consecutive elements. The elements are separated.
 * \param[in] elem1 One PRS_RElem element of the new PRS_RElemElements
 * \param[in] elem2 One PRS_RElem element of the new PRS_RElemElements
 * \return A new PRS_RElemElements consisting of 2 PRS_RElems
 */
PRS_RElemElements PRS_makeRElemElements2(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RElem elem1, PRS_RElem elem2) {
  return PRS_makeRElemElementsMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRElemElementsSingle(elem2));
}

/**
 * Builds a PRS_RElemElements of 3 consecutive elements. The elements are separated.
 * \param[in] elem1 One PRS_RElem element of the new PRS_RElemElements
 * \param[in] elem2 One PRS_RElem element of the new PRS_RElemElements
 * \param[in] elem3 One PRS_RElem element of the new PRS_RElemElements
 * \return A new PRS_RElemElements consisting of 3 PRS_RElems
 */
PRS_RElemElements PRS_makeRElemElements3(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RElem elem1, PRS_RElem elem2, PRS_RElem elem3) {
  return PRS_makeRElemElementsMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRElemElements2(wsAfterHead, wsAfterSep, elem2, elem3));
}

/**
 * Builds a PRS_RElemElements of 4 consecutive elements. The elements are separated.
 * \param[in] elem1 One PRS_RElem element of the new PRS_RElemElements
 * \param[in] elem2 One PRS_RElem element of the new PRS_RElemElements
 * \param[in] elem3 One PRS_RElem element of the new PRS_RElemElements
 * \param[in] elem4 One PRS_RElem element of the new PRS_RElemElements
 * \return A new PRS_RElemElements consisting of 4 PRS_RElems
 */
PRS_RElemElements PRS_makeRElemElements4(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RElem elem1, PRS_RElem elem2, PRS_RElem elem3, PRS_RElem elem4) {
  return PRS_makeRElemElementsMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRElemElements3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}

/**
 * Builds a PRS_RElemElements of 5 consecutive elements. The elements are separated.
 * \param[in] elem1 One PRS_RElem element of the new PRS_RElemElements
 * \param[in] elem2 One PRS_RElem element of the new PRS_RElemElements
 * \param[in] elem3 One PRS_RElem element of the new PRS_RElemElements
 * \param[in] elem4 One PRS_RElem element of the new PRS_RElemElements
 * \param[in] elem5 One PRS_RElem element of the new PRS_RElemElements
 * \return A new PRS_RElemElements consisting of 5 PRS_RElems
 */
PRS_RElemElements PRS_makeRElemElements5(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RElem elem1, PRS_RElem elem2, PRS_RElem elem3, PRS_RElem elem4, PRS_RElem elem5) {
  return PRS_makeRElemElementsMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRElemElements4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}

/**
 * Builds a PRS_RElemElements of 6 consecutive elements. The elements are separated.
 * \param[in] elem1 One PRS_RElem element of the new PRS_RElemElements
 * \param[in] elem2 One PRS_RElem element of the new PRS_RElemElements
 * \param[in] elem3 One PRS_RElem element of the new PRS_RElemElements
 * \param[in] elem4 One PRS_RElem element of the new PRS_RElemElements
 * \param[in] elem5 One PRS_RElem element of the new PRS_RElemElements
 * \param[in] elem6 One PRS_RElem element of the new PRS_RElemElements
 * \return A new PRS_RElemElements consisting of 6 PRS_RElems
 */
PRS_RElemElements PRS_makeRElemElements6(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RElem elem1, PRS_RElem elem2, PRS_RElem elem3, PRS_RElem elem4, PRS_RElem elem5, PRS_RElem elem6) {
  return PRS_makeRElemElementsMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRElemElements5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}

/**
 * Retrieve the number of elements in a PRS_RTypeColumnTypes. 
 * \param[in] arg input PRS_RTypeColumnTypes
 * \return The number of elements in #arg, excluding any separators
 */
int PRS_getRTypeColumnTypesLength (PRS_RTypeColumnTypes arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}

/**
 * Reverses the elements of a PRS_RTypeColumnTypes. Note that separators are reversed with the list, but the order in which each set of separators inbetween two elements occurs does not change
 * \param[in] arg PRS_RTypeColumnTypes to be reversed
 * \return #arg reversed
 */
PRS_RTypeColumnTypes PRS_reverseRTypeColumnTypes(PRS_RTypeColumnTypes arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (PRS_RTypeColumnTypes) result;
}

/**
 * Append a PRS_RType to the end of a PRS_RTypeColumnTypes. 
 * \param[in] arg PRS_RTypeColumnTypes to append the PRS_RType to
 * \param[in] elem PRS_RType to be appended
 * \return new PRS_RTypeColumnTypes with #elem appended after the separators
 */
PRS_RTypeColumnTypes PRS_appendRTypeColumnTypes(PRS_RTypeColumnTypes arg0, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RType arg1) {
  return PRS_concatRTypeColumnTypes(arg0, wsAfterHead, wsAfterSep, PRS_makeRTypeColumnTypesSingle(arg1));
}

/**
 * Concatenate two PRS_RTypeColumnTypess. 
 * \param[in] arg0 first PRS_RTypeColumnTypes
 * \param[in] arg1 second PRS_RTypeColumnTypes
 * \return PRS_RTypeColumnTypes with the elements of #arg0 before the elements of #arg1, with the separators in between.
 */
PRS_RTypeColumnTypes PRS_concatRTypeColumnTypes(PRS_RTypeColumnTypes arg0, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTypeColumnTypes arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = PRS_makeRTypeColumnTypesMany((PRS_RType)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (PRS_RTypeColumnTypes) ATgetNext((ATermList) arg1);
  return (PRS_RTypeColumnTypes) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a PRS_RTypeColumnTypes. 
 * \param[in] arg PRS_RTypeColumnTypes to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new PRS_RTypeColumnTypes with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
PRS_RTypeColumnTypes PRS_sliceRTypeColumnTypes(PRS_RTypeColumnTypes arg, int start, int end) {
  return (PRS_RTypeColumnTypes) ATgetSlice((ATermList) arg, start * 4, end * 4);
}

/**
 * Retrieve the PRS_RType at #index from a PRS_RTypeColumnTypes. 
 * \param[in] arg PRS_RTypeColumnTypes to retrieve the PRS_RType from
 * \param[in] index index to use to point in the PRS_RTypeColumnTypes
 * \return PRS_RType at position #index in #arg
 */
PRS_RType PRS_getRTypeColumnTypesRTypeAt(PRS_RTypeColumnTypes arg, int index) {
 return (PRS_RType)ATelementAt((ATermList) arg,index * 4);
}

/**
 * Replace the PRS_RType at #index from a PRS_RTypeColumnTypes by a new one. 
 * \param[in] arg PRS_RTypeColumnTypes to retrieve the PRS_RType from
 * \param[in] elem new PRS_RType to replace another
 * \param[in] index index to use to point in the PRS_RTypeColumnTypes
 * \return A new PRS_RTypeColumnTypeswith #elem replaced in #arg at position #index
 */
PRS_RTypeColumnTypes PRS_replaceRTypeColumnTypesRTypeAt(PRS_RTypeColumnTypes arg, PRS_RType elem, int index) {
 return (PRS_RTypeColumnTypes) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}

/**
 * Builds a PRS_RTypeColumnTypes of 2 consecutive elements. The elements are separated.
 * \param[in] elem1 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \param[in] elem2 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \return A new PRS_RTypeColumnTypes consisting of 2 PRS_RTypes
 */
PRS_RTypeColumnTypes PRS_makeRTypeColumnTypes2(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RType elem1, PRS_RType elem2) {
  return PRS_makeRTypeColumnTypesMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTypeColumnTypesSingle(elem2));
}

/**
 * Builds a PRS_RTypeColumnTypes of 3 consecutive elements. The elements are separated.
 * \param[in] elem1 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \param[in] elem2 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \param[in] elem3 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \return A new PRS_RTypeColumnTypes consisting of 3 PRS_RTypes
 */
PRS_RTypeColumnTypes PRS_makeRTypeColumnTypes3(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RType elem1, PRS_RType elem2, PRS_RType elem3) {
  return PRS_makeRTypeColumnTypesMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTypeColumnTypes2(wsAfterHead, wsAfterSep, elem2, elem3));
}

/**
 * Builds a PRS_RTypeColumnTypes of 4 consecutive elements. The elements are separated.
 * \param[in] elem1 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \param[in] elem2 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \param[in] elem3 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \param[in] elem4 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \return A new PRS_RTypeColumnTypes consisting of 4 PRS_RTypes
 */
PRS_RTypeColumnTypes PRS_makeRTypeColumnTypes4(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RType elem1, PRS_RType elem2, PRS_RType elem3, PRS_RType elem4) {
  return PRS_makeRTypeColumnTypesMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTypeColumnTypes3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}

/**
 * Builds a PRS_RTypeColumnTypes of 5 consecutive elements. The elements are separated.
 * \param[in] elem1 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \param[in] elem2 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \param[in] elem3 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \param[in] elem4 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \param[in] elem5 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \return A new PRS_RTypeColumnTypes consisting of 5 PRS_RTypes
 */
PRS_RTypeColumnTypes PRS_makeRTypeColumnTypes5(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RType elem1, PRS_RType elem2, PRS_RType elem3, PRS_RType elem4, PRS_RType elem5) {
  return PRS_makeRTypeColumnTypesMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTypeColumnTypes4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}

/**
 * Builds a PRS_RTypeColumnTypes of 6 consecutive elements. The elements are separated.
 * \param[in] elem1 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \param[in] elem2 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \param[in] elem3 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \param[in] elem4 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \param[in] elem5 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \param[in] elem6 One PRS_RType element of the new PRS_RTypeColumnTypes
 * \return A new PRS_RTypeColumnTypes consisting of 6 PRS_RTypes
 */
PRS_RTypeColumnTypes PRS_makeRTypeColumnTypes6(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RType elem1, PRS_RType elem2, PRS_RType elem3, PRS_RType elem4, PRS_RType elem5, PRS_RType elem6) {
  return PRS_makeRTypeColumnTypesMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTypeColumnTypes5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}

/**
 * Retrieve the number of elements in a PRS_RTupleRtuples. 
 * \param[in] arg input PRS_RTupleRtuples
 * \return The number of elements in #arg, excluding any separators
 */
int PRS_getRTupleRtuplesLength (PRS_RTupleRtuples arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}

/**
 * Reverses the elements of a PRS_RTupleRtuples. Note that separators are reversed with the list, but the order in which each set of separators inbetween two elements occurs does not change
 * \param[in] arg PRS_RTupleRtuples to be reversed
 * \return #arg reversed
 */
PRS_RTupleRtuples PRS_reverseRTupleRtuples(PRS_RTupleRtuples arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (PRS_RTupleRtuples) result;
}

/**
 * Append a PRS_RTuple to the end of a PRS_RTupleRtuples. 
 * \param[in] arg PRS_RTupleRtuples to append the PRS_RTuple to
 * \param[in] elem PRS_RTuple to be appended
 * \return new PRS_RTupleRtuples with #elem appended after the separators
 */
PRS_RTupleRtuples PRS_appendRTupleRtuples(PRS_RTupleRtuples arg0, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTuple arg1) {
  return PRS_concatRTupleRtuples(arg0, wsAfterHead, wsAfterSep, PRS_makeRTupleRtuplesSingle(arg1));
}

/**
 * Concatenate two PRS_RTupleRtupless. 
 * \param[in] arg0 first PRS_RTupleRtuples
 * \param[in] arg1 second PRS_RTupleRtuples
 * \return PRS_RTupleRtuples with the elements of #arg0 before the elements of #arg1, with the separators in between.
 */
PRS_RTupleRtuples PRS_concatRTupleRtuples(PRS_RTupleRtuples arg0, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTupleRtuples arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = PRS_makeRTupleRtuplesMany((PRS_RTuple)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (PRS_RTupleRtuples) ATgetNext((ATermList) arg1);
  return (PRS_RTupleRtuples) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a PRS_RTupleRtuples. 
 * \param[in] arg PRS_RTupleRtuples to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new PRS_RTupleRtuples with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
PRS_RTupleRtuples PRS_sliceRTupleRtuples(PRS_RTupleRtuples arg, int start, int end) {
  return (PRS_RTupleRtuples) ATgetSlice((ATermList) arg, start * 4, end * 4);
}

/**
 * Retrieve the PRS_RTuple at #index from a PRS_RTupleRtuples. 
 * \param[in] arg PRS_RTupleRtuples to retrieve the PRS_RTuple from
 * \param[in] index index to use to point in the PRS_RTupleRtuples
 * \return PRS_RTuple at position #index in #arg
 */
PRS_RTuple PRS_getRTupleRtuplesRTupleAt(PRS_RTupleRtuples arg, int index) {
 return (PRS_RTuple)ATelementAt((ATermList) arg,index * 4);
}

/**
 * Replace the PRS_RTuple at #index from a PRS_RTupleRtuples by a new one. 
 * \param[in] arg PRS_RTupleRtuples to retrieve the PRS_RTuple from
 * \param[in] elem new PRS_RTuple to replace another
 * \param[in] index index to use to point in the PRS_RTupleRtuples
 * \return A new PRS_RTupleRtupleswith #elem replaced in #arg at position #index
 */
PRS_RTupleRtuples PRS_replaceRTupleRtuplesRTupleAt(PRS_RTupleRtuples arg, PRS_RTuple elem, int index) {
 return (PRS_RTupleRtuples) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}

/**
 * Builds a PRS_RTupleRtuples of 2 consecutive elements. The elements are separated.
 * \param[in] elem1 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \param[in] elem2 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \return A new PRS_RTupleRtuples consisting of 2 PRS_RTuples
 */
PRS_RTupleRtuples PRS_makeRTupleRtuples2(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTuple elem1, PRS_RTuple elem2) {
  return PRS_makeRTupleRtuplesMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTupleRtuplesSingle(elem2));
}

/**
 * Builds a PRS_RTupleRtuples of 3 consecutive elements. The elements are separated.
 * \param[in] elem1 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \param[in] elem2 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \param[in] elem3 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \return A new PRS_RTupleRtuples consisting of 3 PRS_RTuples
 */
PRS_RTupleRtuples PRS_makeRTupleRtuples3(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTuple elem1, PRS_RTuple elem2, PRS_RTuple elem3) {
  return PRS_makeRTupleRtuplesMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTupleRtuples2(wsAfterHead, wsAfterSep, elem2, elem3));
}

/**
 * Builds a PRS_RTupleRtuples of 4 consecutive elements. The elements are separated.
 * \param[in] elem1 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \param[in] elem2 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \param[in] elem3 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \param[in] elem4 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \return A new PRS_RTupleRtuples consisting of 4 PRS_RTuples
 */
PRS_RTupleRtuples PRS_makeRTupleRtuples4(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTuple elem1, PRS_RTuple elem2, PRS_RTuple elem3, PRS_RTuple elem4) {
  return PRS_makeRTupleRtuplesMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTupleRtuples3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}

/**
 * Builds a PRS_RTupleRtuples of 5 consecutive elements. The elements are separated.
 * \param[in] elem1 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \param[in] elem2 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \param[in] elem3 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \param[in] elem4 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \param[in] elem5 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \return A new PRS_RTupleRtuples consisting of 5 PRS_RTuples
 */
PRS_RTupleRtuples PRS_makeRTupleRtuples5(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTuple elem1, PRS_RTuple elem2, PRS_RTuple elem3, PRS_RTuple elem4, PRS_RTuple elem5) {
  return PRS_makeRTupleRtuplesMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTupleRtuples4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}

/**
 * Builds a PRS_RTupleRtuples of 6 consecutive elements. The elements are separated.
 * \param[in] elem1 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \param[in] elem2 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \param[in] elem3 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \param[in] elem4 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \param[in] elem5 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \param[in] elem6 One PRS_RTuple element of the new PRS_RTupleRtuples
 * \return A new PRS_RTupleRtuples consisting of 6 PRS_RTuples
 */
PRS_RTupleRtuples PRS_makeRTupleRtuples6(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTuple elem1, PRS_RTuple elem2, PRS_RTuple elem3, PRS_RTuple elem4, PRS_RTuple elem5, PRS_RTuple elem6) {
  return PRS_makeRTupleRtuplesMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTupleRtuples5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}

/**
 * Retrieve the length of a PRS_LexStrCharChars. 
 * \param[in] arg input PRS_LexStrCharChars
 * \return The number of elements in the PRS_LexStrCharChars
 */
int PRS_getLexStrCharCharsLength (PRS_LexStrCharChars arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a PRS_LexStrCharChars. 
 * \param[in] arg PRS_LexStrCharChars to be reversed
 * \return a reversed #arg
 */
PRS_LexStrCharChars PRS_reverseLexStrCharChars(PRS_LexStrCharChars arg) {
  return (PRS_LexStrCharChars) ATreverse((ATermList) arg);
}

/**
 * Append a PRS_LexStrChar to the end of a PRS_LexStrCharChars. 
 * \param[in] arg PRS_LexStrCharChars to append the PRS_LexStrChar to
 * \param[in] elem PRS_LexStrChar to be appended
 * \return new PRS_LexStrCharChars with #elem appended
 */
PRS_LexStrCharChars PRS_appendLexStrCharChars(PRS_LexStrCharChars arg, PRS_LexStrChar elem) {
  return (PRS_LexStrCharChars) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two PRS_LexStrCharCharss. 
 * \param[in] arg0 first PRS_LexStrCharChars
 * \param[in] arg1 second PRS_LexStrCharChars
 * \return PRS_LexStrCharChars with the elements of #arg0 before the elements of #arg1
 */
PRS_LexStrCharChars PRS_concatLexStrCharChars(PRS_LexStrCharChars arg0, PRS_LexStrCharChars arg1) {
  return (PRS_LexStrCharChars) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a PRS_LexStrCharChars. 
 * \param[in] arg PRS_LexStrCharChars to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new PRS_LexStrCharChars with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
PRS_LexStrCharChars PRS_sliceLexStrCharChars(PRS_LexStrCharChars arg, int start, int end) {
  return (PRS_LexStrCharChars) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the PRS_LexStrChar at #index from a PRS_LexStrCharChars. 
 * \param[in] arg PRS_LexStrCharChars to retrieve the PRS_LexStrChar from
 * \param[in] index index to use to point in the PRS_LexStrCharChars
 * \return PRS_LexStrChar at position #index in #arg
 */
PRS_LexStrChar PRS_getLexStrCharCharsLexStrCharAt(PRS_LexStrCharChars arg, int index) {
 return (PRS_LexStrChar)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the PRS_LexStrChar at #index from a PRS_LexStrCharChars by a new one. 
 * \param[in] arg PRS_LexStrCharChars to retrieve the PRS_LexStrChar from
 * \param[in] elem new PRS_LexStrChar to replace another
 * \param[in] index index to use to point in the PRS_LexStrCharChars
 * \return A new PRS_LexStrCharCharswith #elem replaced in #arg at position #index
 */
PRS_LexStrCharChars PRS_replaceLexStrCharCharsLexStrCharAt(PRS_LexStrCharChars arg, PRS_LexStrChar elem, int index) {
 return (PRS_LexStrCharChars) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a PRS_LexStrCharChars of 2 consecutive elements. 
 * \param[in] elem1 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \param[in] elem2 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \return A new PRS_LexStrCharChars consisting of 2 PRS_LexStrChars
 */
PRS_LexStrCharChars PRS_makeLexStrCharChars2(PRS_LexStrChar elem1, PRS_LexStrChar elem2) {
  return (PRS_LexStrCharChars) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a PRS_LexStrCharChars of 3 consecutive elements. 
 * \param[in] elem1 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \param[in] elem2 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \param[in] elem3 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \return A new PRS_LexStrCharChars consisting of 3 PRS_LexStrChars
 */
PRS_LexStrCharChars PRS_makeLexStrCharChars3(PRS_LexStrChar elem1, PRS_LexStrChar elem2, PRS_LexStrChar elem3) {
  return (PRS_LexStrCharChars) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a PRS_LexStrCharChars of 4 consecutive elements. 
 * \param[in] elem1 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \param[in] elem2 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \param[in] elem3 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \param[in] elem4 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \return A new PRS_LexStrCharChars consisting of 4 PRS_LexStrChars
 */
PRS_LexStrCharChars PRS_makeLexStrCharChars4(PRS_LexStrChar elem1, PRS_LexStrChar elem2, PRS_LexStrChar elem3, PRS_LexStrChar elem4) {
  return (PRS_LexStrCharChars) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a PRS_LexStrCharChars of 5 consecutive elements. 
 * \param[in] elem1 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \param[in] elem2 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \param[in] elem3 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \param[in] elem4 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \param[in] elem5 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \return A new PRS_LexStrCharChars consisting of 5 PRS_LexStrChars
 */
PRS_LexStrCharChars PRS_makeLexStrCharChars5(PRS_LexStrChar elem1, PRS_LexStrChar elem2, PRS_LexStrChar elem3, PRS_LexStrChar elem4, PRS_LexStrChar elem5) {
  return (PRS_LexStrCharChars) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a PRS_LexStrCharChars of 6 consecutive elements. 
 * \param[in] elem1 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \param[in] elem2 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \param[in] elem3 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \param[in] elem4 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \param[in] elem5 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \param[in] elem6 One PRS_LexStrChar element of the new PRS_LexStrCharChars
 * \return A new PRS_LexStrCharChars consisting of 6 PRS_LexStrChars
 */
PRS_LexStrCharChars PRS_makeLexStrCharChars6(PRS_LexStrChar elem1, PRS_LexStrChar elem2, PRS_LexStrChar elem3, PRS_LexStrChar elem4, PRS_LexStrChar elem5, PRS_LexStrChar elem6) {
  return (PRS_LexStrCharChars) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Constructs a Absent of type PRS_OptLayout. Like all ATerm types, PRS_OptLayouts are maximally shared.
 * \return A pointer to a Absent, either newly constructed or shared
 */
PRS_OptLayout PRS_makeOptLayoutAbsent(void) {
  return (PRS_OptLayout)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4))), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATempty);
}
/**
 * Constructs a Present of type PRS_OptLayout. Like all ATerm types, PRS_OptLayouts are maximally shared.
 * \param[in] layout a child of the new Present
 * \return A pointer to a Present, either newly constructed or shared
 */
PRS_OptLayout PRS_makeOptLayoutPresent(PRS_Layout layout) {
  return (PRS_OptLayout)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl0(PRS_afun4))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4))), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm) layout));
}
/**
 * Constructs a Lex-to-cf of type PRS_Layout. Like all ATerm types, PRS_Layouts are maximally shared.
 * \param[in] list a child of the new Lex-to-cf
 * \return A pointer to a Lex-to-cf, either newly constructed or shared
 */
PRS_Layout PRS_makeLayoutLexToCf(PRS_LexLayoutList list) {
  return (PRS_Layout)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun7, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl0(PRS_afun4)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun7, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm) list)));
}
/**
 * Constructs a empty of type PRS_LexLayoutList. Like all ATerm types, PRS_LexLayoutLists are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
PRS_LexLayoutList PRS_makeLexLayoutListEmpty(void) {
  return (PRS_LexLayoutList)(ATerm)ATempty;
}
/**
 * Constructs a single of type PRS_LexLayoutList. Like all ATerm types, PRS_LexLayoutLists are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
PRS_LexLayoutList PRS_makeLexLayoutListSingle(PRS_LexLayout head) {
  return (PRS_LexLayoutList)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type PRS_LexLayoutList. Like all ATerm types, PRS_LexLayoutLists are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
PRS_LexLayoutList PRS_makeLexLayoutListMany(PRS_LexLayout head, PRS_LexLayoutList tail) {
  return (PRS_LexLayoutList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a integer of type PRS_RElem. Like all ATerm types, PRS_RElems are maximally shared.
 * \param[in] IntCon a child of the new integer
 * \return A pointer to a integer, either newly constructed or shared
 */
PRS_RElem PRS_makeRElemInteger(PRS_IntCon IntCon) {
  return (PRS_RElem)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun11))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun15)))))), (ATerm)ATmakeList1((ATerm) IntCon));
}
/**
 * Constructs a string of type PRS_RElem. Like all ATerm types, PRS_RElems are maximally shared.
 * \param[in] StrCon a child of the new string
 * \return A pointer to a string, either newly constructed or shared
 */
PRS_RElem PRS_makeRElemString(PRS_StrCon StrCon) {
  return (PRS_RElem)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun16)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun11))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun17)))))), (ATerm)ATmakeList1((ATerm) StrCon));
}
/**
 * Constructs a location of type PRS_RElem. Like all ATerm types, PRS_RElems are maximally shared.
 * \param[in] Location a child of the new location
 * \return A pointer to a location, either newly constructed or shared
 */
PRS_RElem PRS_makeRElemLocation(PRS_Location Location) {
  return (PRS_RElem)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun18)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun11))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun19)))))), (ATerm)ATmakeList1((ATerm) Location));
}
/**
 * Constructs a set of type PRS_RElem. Like all ATerm types, PRS_RElems are maximally shared.
 * \param[in] wsAfterBraceOpen a child of the new set
 * \param[in] elements a child of the new set
 * \param[in] wsAfterElements a child of the new set
 * \return A pointer to a set, either newly constructed or shared
 */
PRS_RElem PRS_makeRElemSet(PRS_OptLayout wsAfterBraceOpen, PRS_RElemElements elements, PRS_OptLayout wsAfterElements) {
  return (PRS_RElem)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun21))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun22, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun11)), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun24))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun11))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun25)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(125)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun21)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(125)))), (ATerm) wsAfterElements), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun22, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun11)), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))))), (ATerm) elements)), (ATerm) wsAfterBraceOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(123)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun24)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(123)))));
}
/**
 * Constructs a bag of type PRS_RElem. Like all ATerm types, PRS_RElems are maximally shared.
 * \param[in] wsAfterBraceOpenBar a child of the new bag
 * \param[in] elements a child of the new bag
 * \param[in] wsAfterElements a child of the new bag
 * \return A pointer to a bag, either newly constructed or shared
 */
PRS_RElem PRS_makeRElemBag(PRS_OptLayout wsAfterBraceOpenBar, PRS_RElemElements elements, PRS_OptLayout wsAfterElements) {
  return (PRS_RElem)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun27))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun22, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun11)), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun28))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun11))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun29)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(125)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(124)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun27)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(125)), (ATerm)ATmakeInt(124)))), (ATerm) wsAfterElements), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun22, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun11)), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))))), (ATerm) elements)), (ATerm) wsAfterBraceOpenBar), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(124)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(123)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun28)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(124)), (ATerm)ATmakeInt(123)))));
}
/**
 * Constructs a tuple of type PRS_RElem. Like all ATerm types, PRS_RElems are maximally shared.
 * \param[in] wsAfterLessThan a child of the new tuple
 * \param[in] elements a child of the new tuple
 * \param[in] wsAfterElements a child of the new tuple
 * \return A pointer to a tuple, either newly constructed or shared
 */
PRS_RElem PRS_makeRElemTuple(PRS_OptLayout wsAfterLessThan, PRS_RElemElements elements, PRS_OptLayout wsAfterElements) {
  return (PRS_RElem)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun30))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun31, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun11)), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun32))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun11))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun33)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(62)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun30)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(62)))), (ATerm) wsAfterElements), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun31, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun11)), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))))), (ATerm) elements)), (ATerm) wsAfterLessThan), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(60)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun32)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(60)))));
}
/**
 * Constructs a integer of type PRS_RType. Like all ATerm types, PRS_RTypes are maximally shared.
 * \return A pointer to a integer, either newly constructed or shared
 */
PRS_RType PRS_makeRTypeInteger(void) {
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun34))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun15)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun34)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(105)))));
}
/**
 * Constructs a boolean of type PRS_RType. Like all ATerm types, PRS_RTypes are maximally shared.
 * \return A pointer to a boolean, either newly constructed or shared
 */
PRS_RType PRS_makeRTypeBoolean(void) {
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun36))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun37)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(98)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun36)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(98)))));
}
/**
 * Constructs a string of type PRS_RType. Like all ATerm types, PRS_RTypes are maximally shared.
 * \return A pointer to a string, either newly constructed or shared
 */
PRS_RType PRS_makeRTypeString(void) {
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun38))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun17)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun38)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(115)))));
}
/**
 * Constructs a location of type PRS_RType. Like all ATerm types, PRS_RTypes are maximally shared.
 * \return A pointer to a location, either newly constructed or shared
 */
PRS_RType PRS_makeRTypeLocation(void) {
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun39))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun19)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun39)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(108)))));
}
/**
 * Constructs a tuple of type PRS_RType. Like all ATerm types, PRS_RTypes are maximally shared.
 * \param[in] wsAfterLessThan a child of the new tuple
 * \param[in] columnTypes a child of the new tuple
 * \param[in] wsAfterColumnTypes a child of the new tuple
 * \return A pointer to a tuple, either newly constructed or shared
 */
PRS_RType PRS_makeRTypeTuple(PRS_OptLayout wsAfterLessThan, PRS_RTypeColumnTypes columnTypes, PRS_OptLayout wsAfterColumnTypes) {
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun30))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun31, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun35)), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun32))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun33)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(62)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun30)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(62)))), (ATerm) wsAfterColumnTypes), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun31, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun35)), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))))), (ATerm) columnTypes)), (ATerm) wsAfterLessThan), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(60)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun32)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(60)))));
}
/**
 * Constructs a set of type PRS_RType. Like all ATerm types, PRS_RTypes are maximally shared.
 * \param[in] wsAfterSet a child of the new set
 * \param[in] wsAfterBracketOpen a child of the new set
 * \param[in] elementType a child of the new set
 * \param[in] wsAfterElementType a child of the new set
 * \return A pointer to a set, either newly constructed or shared
 */
PRS_RType PRS_makeRTypeSet(PRS_OptLayout wsAfterSet, PRS_OptLayout wsAfterBracketOpen, PRS_RType elementType, PRS_OptLayout wsAfterElementType) {
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun40))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun35)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun41))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun25))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun25)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun40)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterElementType), (ATerm) elementType), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun41)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterSet), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun25)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(115)))));
}
/**
 * Constructs a bag of type PRS_RType. Like all ATerm types, PRS_RTypes are maximally shared.
 * \param[in] wsAfterBag a child of the new bag
 * \param[in] wsAfterBracketOpen a child of the new bag
 * \param[in] elementType a child of the new bag
 * \param[in] wsAfterElementType a child of the new bag
 * \return A pointer to a bag, either newly constructed or shared
 */
PRS_RType PRS_makeRTypeBag(PRS_OptLayout wsAfterBag, PRS_OptLayout wsAfterBracketOpen, PRS_RType elementType, PRS_OptLayout wsAfterElementType) {
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun40))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun35)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun41))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun29))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun29)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun40)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterElementType), (ATerm) elementType), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun41)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterBag), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(103)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(98)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun29)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(103)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(98)))));
}
/**
 * Constructs a relation of type PRS_RType. Like all ATerm types, PRS_RTypes are maximally shared.
 * \param[in] wsAfterRel a child of the new relation
 * \param[in] wsAfterBracketOpen a child of the new relation
 * \param[in] columnTypes a child of the new relation
 * \param[in] wsAfterColumnTypes a child of the new relation
 * \return A pointer to a relation, either newly constructed or shared
 */
PRS_RType PRS_makeRTypeRelation(PRS_OptLayout wsAfterRel, PRS_OptLayout wsAfterBracketOpen, PRS_RTypeColumnTypes columnTypes, PRS_OptLayout wsAfterColumnTypes) {
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun40))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun31, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun35)), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun41))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun42))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun43)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun40)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterColumnTypes), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun31, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun35)), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))))), (ATerm) columnTypes)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun41)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterRel), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun42)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)))));
}
/**
 * Constructs a user-defined of type PRS_RType. Like all ATerm types, PRS_RTypes are maximally shared.
 * \param[in] name a child of the new user-defined
 * \return A pointer to a user-defined, either newly constructed or shared
 */
PRS_RType PRS_makeRTypeUserDefined(PRS_IdCon name) {
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun44)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun45)))))), (ATerm)ATmakeList1((ATerm) name));
}
/**
 * Constructs a parameter of type PRS_RType. Like all ATerm types, PRS_RTypes are maximally shared.
 * \param[in] wsAfterAmp a child of the new parameter
 * \param[in] name a child of the new parameter
 * \return A pointer to a parameter, either newly constructed or shared
 */
PRS_RType PRS_makeRTypeParameter(PRS_OptLayout wsAfterAmp, PRS_IdCon name) {
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun44)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun46))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun47)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) name), (ATerm) wsAfterAmp), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(38)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun46)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(38)))));
}
/**
 * Constructs a rtuple of type PRS_RTuple. Like all ATerm types, PRS_RTuples are maximally shared.
 * \param[in] wsAfterLessThan a child of the new rtuple
 * \param[in] variable a child of the new rtuple
 * \param[in] wsAfterVariable a child of the new rtuple
 * \param[in] wsAfterComma a child of the new rtuple
 * \param[in] type a child of the new rtuple
 * \param[in] wsAfterType a child of the new rtuple
 * \param[in] wsAfterComma1 a child of the new rtuple
 * \param[in] value a child of the new rtuple
 * \param[in] wsAfterValue a child of the new rtuple
 * \return A pointer to a rtuple, either newly constructed or shared
 */
PRS_RTuple PRS_makeRTupleRtuple(PRS_OptLayout wsAfterLessThan, PRS_IdCon variable, PRS_OptLayout wsAfterVariable, PRS_OptLayout wsAfterComma, PRS_RType type, PRS_OptLayout wsAfterType, PRS_OptLayout wsAfterComma1, PRS_RElem value, PRS_OptLayout wsAfterValue) {
  return (PRS_RTuple)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun30))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun11)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun35)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun44)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun32))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun48))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun49)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(62)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun30)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(62)))), (ATerm) wsAfterValue), (ATerm) value), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterType), (ATerm) type), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterVariable), (ATerm) variable), (ATerm) wsAfterLessThan), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(60)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun32)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(60)))));
}
/**
 * Constructs a rstore of type PRS_RStore. Like all ATerm types, PRS_RStores are maximally shared.
 * \param[in] wsAfterRstore a child of the new rstore
 * \param[in] wsAfterParenOpen a child of the new rstore
 * \param[in] wsAfterBracketOpen a child of the new rstore
 * \param[in] rtuples a child of the new rstore
 * \param[in] wsAfterRtuples a child of the new rstore
 * \param[in] wsAfterBracketClose a child of the new rstore
 * \return A pointer to a rstore, either newly constructed or shared
 */
PRS_RStore PRS_makeRStoreRstore(PRS_OptLayout wsAfterRstore, PRS_OptLayout wsAfterParenOpen, PRS_OptLayout wsAfterBracketOpen, PRS_RTupleRtuples rtuples, PRS_OptLayout wsAfterRtuples, PRS_OptLayout wsAfterBracketClose) {
  return (PRS_RStore)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun50))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun40))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun22, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun48)), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun41))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun51))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun52))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun53))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun52)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun50)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun40)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterRtuples), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun22, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun48)), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))))), (ATerm) rtuples)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun41)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun51)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterRstore), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun52)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(114)))));
}
/**
 * Constructs a RStore of type PRS_Start. Like all ATerm types, PRS_Starts are maximally shared.
 * \param[in] wsBefore a child of the new RStore
 * \param[in] topRStore a child of the new RStore
 * \param[in] wsAfter a child of the new RStore
 * \param[in] ambCnt a child of the new RStore
 * \return A pointer to a RStore, either newly constructed or shared
 */
PRS_Start PRS_makeStartRStore(PRS_OptLayout wsBefore, PRS_RStore topRStore, PRS_OptLayout wsAfter, int ambCnt) {
  return (PRS_Start)(ATerm)ATmakeAppl2(PRS_afun54, (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun53)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun55)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topRStore), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}
/**
 * Constructs a empty of type PRS_RElemElements. Like all ATerm types, PRS_RElemElementss are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
PRS_RElemElements PRS_makeRElemElementsEmpty(void) {
  return (PRS_RElemElements)(ATerm)ATempty;
}
/**
 * Constructs a single of type PRS_RElemElements. Like all ATerm types, PRS_RElemElementss are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
PRS_RElemElements PRS_makeRElemElementsSingle(PRS_RElem head) {
  return (PRS_RElemElements)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type PRS_RElemElements. Like all ATerm types, PRS_RElemElementss are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] wsAfterHead a child of the new many
 * \param[in] wsAfterSep a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
PRS_RElemElements PRS_makeRElemElementsMany(PRS_RElem head, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RElemElements tail) {
  if (PRS_isRElemElementsEmpty(tail)) {
    return PRS_makeRElemElementsSingle(head);
  }
  return (PRS_RElemElements)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}
/**
 * Constructs a empty of type PRS_RTypeColumnTypes. Like all ATerm types, PRS_RTypeColumnTypess are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
PRS_RTypeColumnTypes PRS_makeRTypeColumnTypesEmpty(void) {
  return (PRS_RTypeColumnTypes)(ATerm)ATempty;
}
/**
 * Constructs a single of type PRS_RTypeColumnTypes. Like all ATerm types, PRS_RTypeColumnTypess are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
PRS_RTypeColumnTypes PRS_makeRTypeColumnTypesSingle(PRS_RType head) {
  return (PRS_RTypeColumnTypes)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type PRS_RTypeColumnTypes. Like all ATerm types, PRS_RTypeColumnTypess are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] wsAfterHead a child of the new many
 * \param[in] wsAfterSep a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
PRS_RTypeColumnTypes PRS_makeRTypeColumnTypesMany(PRS_RType head, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTypeColumnTypes tail) {
  if (PRS_isRTypeColumnTypesEmpty(tail)) {
    return PRS_makeRTypeColumnTypesSingle(head);
  }
  return (PRS_RTypeColumnTypes)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}
/**
 * Constructs a empty of type PRS_RTupleRtuples. Like all ATerm types, PRS_RTupleRtupless are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
PRS_RTupleRtuples PRS_makeRTupleRtuplesEmpty(void) {
  return (PRS_RTupleRtuples)(ATerm)ATempty;
}
/**
 * Constructs a single of type PRS_RTupleRtuples. Like all ATerm types, PRS_RTupleRtupless are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
PRS_RTupleRtuples PRS_makeRTupleRtuplesSingle(PRS_RTuple head) {
  return (PRS_RTupleRtuples)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type PRS_RTupleRtuples. Like all ATerm types, PRS_RTupleRtupless are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] wsAfterHead a child of the new many
 * \param[in] wsAfterSep a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
PRS_RTupleRtuples PRS_makeRTupleRtuplesMany(PRS_RTuple head, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTupleRtuples tail) {
  if (PRS_isRTupleRtuplesEmpty(tail)) {
    return PRS_makeRTupleRtuplesSingle(head);
  }
  return (PRS_RTupleRtuples)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}
/**
 * Constructs a newline of type PRS_LexStrChar. Like all ATerm types, PRS_LexStrChars are maximally shared.
 * \return A pointer to a newline, either newly constructed or shared
 */
PRS_LexStrChar PRS_makeLexStrCharNewline(void) {
  return (PRS_LexStrChar)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun56))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun57))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun58)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun56)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(92)))));
}
/**
 * Constructs a tab of type PRS_LexStrChar. Like all ATerm types, PRS_LexStrChars are maximally shared.
 * \return A pointer to a tab, either newly constructed or shared
 */
PRS_LexStrChar PRS_makeLexStrCharTab(void) {
  return (PRS_LexStrChar)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun59))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun57))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun60)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun59)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(92)))));
}
/**
 * Constructs a quote of type PRS_LexStrChar. Like all ATerm types, PRS_LexStrChars are maximally shared.
 * \return A pointer to a quote, either newly constructed or shared
 */
PRS_LexStrChar PRS_makeLexStrCharQuote(void) {
  return (PRS_LexStrChar)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun61))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun57))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun62)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun61)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(34)), (ATerm)ATmakeInt(92)))));
}
/**
 * Constructs a backslash of type PRS_LexStrChar. Like all ATerm types, PRS_LexStrChars are maximally shared.
 * \return A pointer to a backslash, either newly constructed or shared
 */
PRS_LexStrChar PRS_makeLexStrCharBackslash(void) {
  return (PRS_LexStrChar)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun63))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun57))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun64)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun63)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(92)), (ATerm)ATmakeInt(92)))));
}
/**
 * Constructs a decimal of type PRS_LexStrChar. Like all ATerm types, PRS_LexStrChars are maximally shared.
 * \param[in] a a child of the new decimal
 * \param[in] b a child of the new decimal
 * \param[in] c a child of the new decimal
 * \return A pointer to a decimal, either newly constructed or shared
 */
PRS_LexStrChar PRS_makeLexStrCharDecimal(char a, char b, char c) {
  return (PRS_LexStrChar)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun65, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun65, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun65, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun66))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun57))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun67)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) ((ATerm) PRS_byteToChar(c))), (ATerm) ((ATerm) PRS_byteToChar(b))), (ATerm) ((ATerm) PRS_byteToChar(a))), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun66)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))));
}
/**
 * Constructs a normal of type PRS_LexStrChar. Like all ATerm types, PRS_LexStrChars are maximally shared.
 * \param[in] ch a child of the new normal
 * \return A pointer to a normal, either newly constructed or shared
 */
PRS_LexStrChar PRS_makeLexStrCharNormal(char ch) {
  return (PRS_LexStrChar)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun65, (ATerm)ATmakeInt(93), (ATerm)ATmakeInt(255))), (ATerm)ATmakeAppl2(PRS_afun65, (ATerm)ATmakeInt(35), (ATerm)ATmakeInt(91))), (ATerm)ATmakeAppl2(PRS_afun65, (ATerm)ATmakeInt(32), (ATerm)ATmakeInt(33))))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun57))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun68)))))), (ATerm)ATmakeList1((ATerm) ((ATerm) PRS_byteToChar(ch))));
}
/**
 * Constructs a Lex-to-cf of type PRS_StrChar. Like all ATerm types, PRS_StrChars are maximally shared.
 * \param[in] StrChar a child of the new Lex-to-cf
 * \return A pointer to a Lex-to-cf, either newly constructed or shared
 */
PRS_StrChar PRS_makeStrCharLexToCf(PRS_LexStrChar StrChar) {
  return (PRS_StrChar)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun57)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun57))), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm) StrChar));
}
/**
 * Constructs a default of type PRS_LexStrCon. Like all ATerm types, PRS_LexStrCons are maximally shared.
 * \param[in] chars a child of the new default
 * \return A pointer to a default, either newly constructed or shared
 */
PRS_LexStrCon PRS_makeLexStrConDefault(PRS_LexStrCharChars chars) {
  return (PRS_LexStrCon)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun69, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun57))))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun16))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun70)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(34)), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun69, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun57))))), (ATerm) chars)), (ATerm)ATmakeInt(34)));
}
/**
 * Constructs a Lex-to-cf of type PRS_StrCon. Like all ATerm types, PRS_StrCons are maximally shared.
 * \param[in] StrCon a child of the new Lex-to-cf
 * \return A pointer to a Lex-to-cf, either newly constructed or shared
 */
PRS_StrCon PRS_makeStrConLexToCf(PRS_LexStrCon StrCon) {
  return (PRS_StrCon)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun16)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun16))), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm) StrCon));
}
/**
 * Constructs a empty of type PRS_LexStrCharChars. Like all ATerm types, PRS_LexStrCharCharss are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
PRS_LexStrCharChars PRS_makeLexStrCharCharsEmpty(void) {
  return (PRS_LexStrCharChars)(ATerm)ATempty;
}
/**
 * Constructs a single of type PRS_LexStrCharChars. Like all ATerm types, PRS_LexStrCharCharss are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
PRS_LexStrCharChars PRS_makeLexStrCharCharsSingle(PRS_LexStrChar head) {
  return (PRS_LexStrCharChars)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type PRS_LexStrCharChars. Like all ATerm types, PRS_LexStrCharCharss are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
PRS_LexStrCharChars PRS_makeLexStrCharCharsMany(PRS_LexStrChar head, PRS_LexStrCharChars tail) {
  return (PRS_LexStrCharChars)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a digits of type PRS_LexNatCon. Like all ATerm types, PRS_LexNatCons are maximally shared.
 * \param[in] list a child of the new digits
 * \return A pointer to a digits, either newly constructed or shared
 */
PRS_LexNatCon PRS_makeLexNatConDigits(const char* list) {
  return (PRS_LexNatCon)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun7, (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun65, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun71))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun72)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun7, (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun65, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))))), (ATerm) ((ATerm) PRS_stringToChars(list)))));
}
/**
 * Constructs a Lex-to-cf of type PRS_NatCon. Like all ATerm types, PRS_NatCons are maximally shared.
 * \param[in] NatCon a child of the new Lex-to-cf
 * \return A pointer to a Lex-to-cf, either newly constructed or shared
 */
PRS_NatCon PRS_makeNatConLexToCf(PRS_LexNatCon NatCon) {
  return (PRS_NatCon)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun71)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun71))), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm) NatCon));
}
/**
 * Constructs a default of type PRS_LexIdCon. Like all ATerm types, PRS_LexIdCons are maximally shared.
 * \param[in] head a child of the new default
 * \param[in] tail a child of the new default
 * \return A pointer to a default, either newly constructed or shared
 */
PRS_LexIdCon PRS_makeLexIdConDefault(char head, const char* tail) {
  return (PRS_LexIdCon)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun69, (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun65, (ATerm)ATmakeInt(97), (ATerm)ATmakeInt(122))), (ATerm)ATmakeAppl2(PRS_afun65, (ATerm)ATmakeInt(65), (ATerm)ATmakeInt(90))), (ATerm)ATmakeAppl2(PRS_afun65, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))), (ATerm)ATmakeInt(45)))))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun65, (ATerm)ATmakeInt(97), (ATerm)ATmakeInt(122))), (ATerm)ATmakeAppl2(PRS_afun65, (ATerm)ATmakeInt(65), (ATerm)ATmakeInt(90))))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun44))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun70)))))), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun69, (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun65, (ATerm)ATmakeInt(97), (ATerm)ATmakeInt(122))), (ATerm)ATmakeAppl2(PRS_afun65, (ATerm)ATmakeInt(65), (ATerm)ATmakeInt(90))), (ATerm)ATmakeAppl2(PRS_afun65, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))), (ATerm)ATmakeInt(45)))))), (ATerm) ((ATerm) PRS_stringToChars(tail)))), (ATerm) ((ATerm) PRS_byteToChar(head))));
}
/**
 * Constructs a Lex-to-cf of type PRS_IdCon. Like all ATerm types, PRS_IdCons are maximally shared.
 * \param[in] IdCon a child of the new Lex-to-cf
 * \return A pointer to a Lex-to-cf, either newly constructed or shared
 */
PRS_IdCon PRS_makeIdConLexToCf(PRS_LexIdCon IdCon) {
  return (PRS_IdCon)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun44)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun44))), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm) IdCon));
}
/**
 * Constructs a positive of type PRS_LexIntCon. Like all ATerm types, PRS_LexIntCons are maximally shared.
 * \param[in] digits a child of the new positive
 * \return A pointer to a positive, either newly constructed or shared
 */
PRS_LexIntCon PRS_makeLexIntConPositive(PRS_LexNatCon digits) {
  return (PRS_LexIntCon)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun71)))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun73)))))), (ATerm)ATmakeList1((ATerm) digits));
}
/**
 * Constructs a negative of type PRS_LexIntCon. Like all ATerm types, PRS_LexIntCons are maximally shared.
 * \param[in] digits a child of the new negative
 * \return A pointer to a negative, either newly constructed or shared
 */
PRS_LexIntCon PRS_makeLexIntConNegative(PRS_LexNatCon digits) {
  return (PRS_LexIntCon)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun71)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun74)))))), (ATerm)ATinsert(ATmakeList1((ATerm) digits), (ATerm)ATmakeInt(45)));
}
/**
 * Constructs a Lex-to-cf of type PRS_IntCon. Like all ATerm types, PRS_IntCons are maximally shared.
 * \param[in] IntCon a child of the new Lex-to-cf
 * \return A pointer to a Lex-to-cf, either newly constructed or shared
 */
PRS_IntCon PRS_makeIntConLexToCf(PRS_LexIntCon IntCon) {
  return (PRS_IntCon)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm) IntCon));
}
/**
 * Constructs a whitespace of type PRS_LexLayout. Like all ATerm types, PRS_LexLayouts are maximally shared.
 * \param[in] ch a child of the new whitespace
 * \return A pointer to a whitespace, either newly constructed or shared
 */
PRS_LexLayout PRS_makeLexLayoutWhitespace(char ch) {
  return (PRS_LexLayout)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(32)), (ATerm)ATmakeInt(13)), (ATerm)ATmakeAppl2(PRS_afun65, (ATerm)ATmakeInt(9), (ATerm)ATmakeInt(10))))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl0(PRS_afun4)), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun75)))))), (ATerm)ATmakeList1((ATerm) ((ATerm) PRS_byteToChar(ch))));
}
/**
 * Constructs a file of type PRS_Location. Like all ATerm types, PRS_Locations are maximally shared.
 * \param[in] wsAfterFile a child of the new file
 * \param[in] wsAfterParenOpen a child of the new file
 * \param[in] filename a child of the new file
 * \param[in] wsAfterFilename a child of the new file
 * \return A pointer to a file, either newly constructed or shared
 */
PRS_Location PRS_makeLocationFile(PRS_OptLayout wsAfterFile, PRS_OptLayout wsAfterParenOpen, PRS_StrCon filename, PRS_OptLayout wsAfterFilename) {
  return (PRS_Location)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun50))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun16)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun51))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun76))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun18))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun76)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun50)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterFilename), (ATerm) filename), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun51)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterFile), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun76)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(102)))));
}
/**
 * Constructs a area of type PRS_Location. Like all ATerm types, PRS_Locations are maximally shared.
 * \param[in] wsAfterA a child of the new area
 * \param[in] wsAfterParenOpen a child of the new area
 * \param[in] Area a child of the new area
 * \param[in] wsAfterArea a child of the new area
 * \return A pointer to a area, either newly constructed or shared
 */
PRS_Location PRS_makeLocationArea(PRS_OptLayout wsAfterA, PRS_OptLayout wsAfterParenOpen, PRS_Area Area, PRS_OptLayout wsAfterArea) {
  return (PRS_Location)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun50))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun77)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun51))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun78))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun18))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun78)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun50)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterArea), (ATerm) Area), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun51)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterA), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun78)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)))));
}
/**
 * Constructs a area-in-file of type PRS_Location. Like all ATerm types, PRS_Locations are maximally shared.
 * \param[in] wsAfterAreaInFile a child of the new area-in-file
 * \param[in] wsAfterParenOpen a child of the new area-in-file
 * \param[in] filename a child of the new area-in-file
 * \param[in] wsAfterFilename a child of the new area-in-file
 * \param[in] wsAfterComma a child of the new area-in-file
 * \param[in] Area a child of the new area-in-file
 * \param[in] wsAfterArea a child of the new area-in-file
 * \return A pointer to a area-in-file, either newly constructed or shared
 */
PRS_Location PRS_makeLocationAreaInFile(PRS_OptLayout wsAfterAreaInFile, PRS_OptLayout wsAfterParenOpen, PRS_StrCon filename, PRS_OptLayout wsAfterFilename, PRS_OptLayout wsAfterComma, PRS_Area Area, PRS_OptLayout wsAfterArea) {
  return (PRS_Location)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun50))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun77)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun16)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun51))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun79))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun18))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun79)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun50)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterArea), (ATerm) Area), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterFilename), (ATerm) filename), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun51)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterAreaInFile), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun79)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(102)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)))));
}
/**
 * Constructs a area of type PRS_Area. Like all ATerm types, PRS_Areas are maximally shared.
 * \param[in] wsAfterArea a child of the new area
 * \param[in] wsAfterParenOpen a child of the new area
 * \param[in] beginLine a child of the new area
 * \param[in] wsAfterBeginLine a child of the new area
 * \param[in] wsAfterComma a child of the new area
 * \param[in] beginColumn a child of the new area
 * \param[in] wsAfterBeginColumn a child of the new area
 * \param[in] wsAfterComma1 a child of the new area
 * \param[in] endLine a child of the new area
 * \param[in] wsAfterEndLine a child of the new area
 * \param[in] wsAfterComma2 a child of the new area
 * \param[in] endColumn a child of the new area
 * \param[in] wsAfterEndColumn a child of the new area
 * \param[in] wsAfterComma3 a child of the new area
 * \param[in] offset a child of the new area
 * \param[in] wsAfterOffset a child of the new area
 * \param[in] wsAfterComma4 a child of the new area
 * \param[in] length a child of the new area
 * \param[in] wsAfterLength a child of the new area
 * \return A pointer to a area, either newly constructed or shared
 */
PRS_Area PRS_makeAreaArea(PRS_OptLayout wsAfterArea, PRS_OptLayout wsAfterParenOpen, PRS_NatCon beginLine, PRS_OptLayout wsAfterBeginLine, PRS_OptLayout wsAfterComma, PRS_NatCon beginColumn, PRS_OptLayout wsAfterBeginColumn, PRS_OptLayout wsAfterComma1, PRS_NatCon endLine, PRS_OptLayout wsAfterEndLine, PRS_OptLayout wsAfterComma2, PRS_NatCon endColumn, PRS_OptLayout wsAfterEndColumn, PRS_OptLayout wsAfterComma3, PRS_NatCon offset, PRS_OptLayout wsAfterOffset, PRS_OptLayout wsAfterComma4, PRS_NatCon length, PRS_OptLayout wsAfterLength) {
  return (PRS_Area)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun50))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun71)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun71)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun71)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun71)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun71)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun71)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun51))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun78))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun77))), (ATerm)ATmakeAppl1(PRS_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun13, (ATerm)ATmakeAppl1(PRS_afun14, (ATerm)ATmakeAppl0(PRS_afun78)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun50)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterLength), (ATerm) length), (ATerm) wsAfterComma4), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterOffset), (ATerm) offset), (ATerm) wsAfterComma3), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterEndColumn), (ATerm) endColumn), (ATerm) wsAfterComma2), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterEndLine), (ATerm) endLine), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterBeginColumn), (ATerm) beginColumn), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun23)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterBeginLine), (ATerm) beginLine), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun51)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterArea), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun26, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeAppl0(PRS_afun78)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)))));
}

/**
 * Tests equality of two PRS_OptLayouts. A constant time operation.
 * \param[in] arg0 first PRS_OptLayout to be compared
 * \param[in] arg1 second PRS_OptLayout to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualOptLayout(PRS_OptLayout arg0, PRS_OptLayout arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_Layouts. A constant time operation.
 * \param[in] arg0 first PRS_Layout to be compared
 * \param[in] arg1 second PRS_Layout to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualLayout(PRS_Layout arg0, PRS_Layout arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_LexLayoutLists. A constant time operation.
 * \param[in] arg0 first PRS_LexLayoutList to be compared
 * \param[in] arg1 second PRS_LexLayoutList to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualLexLayoutList(PRS_LexLayoutList arg0, PRS_LexLayoutList arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_RElems. A constant time operation.
 * \param[in] arg0 first PRS_RElem to be compared
 * \param[in] arg1 second PRS_RElem to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualRElem(PRS_RElem arg0, PRS_RElem arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_RTypes. A constant time operation.
 * \param[in] arg0 first PRS_RType to be compared
 * \param[in] arg1 second PRS_RType to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualRType(PRS_RType arg0, PRS_RType arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_RTuples. A constant time operation.
 * \param[in] arg0 first PRS_RTuple to be compared
 * \param[in] arg1 second PRS_RTuple to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualRTuple(PRS_RTuple arg0, PRS_RTuple arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_RStores. A constant time operation.
 * \param[in] arg0 first PRS_RStore to be compared
 * \param[in] arg1 second PRS_RStore to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualRStore(PRS_RStore arg0, PRS_RStore arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_Starts. A constant time operation.
 * \param[in] arg0 first PRS_Start to be compared
 * \param[in] arg1 second PRS_Start to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualStart(PRS_Start arg0, PRS_Start arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_RElemElementss. A constant time operation.
 * \param[in] arg0 first PRS_RElemElements to be compared
 * \param[in] arg1 second PRS_RElemElements to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualRElemElements(PRS_RElemElements arg0, PRS_RElemElements arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_RTypeColumnTypess. A constant time operation.
 * \param[in] arg0 first PRS_RTypeColumnTypes to be compared
 * \param[in] arg1 second PRS_RTypeColumnTypes to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualRTypeColumnTypes(PRS_RTypeColumnTypes arg0, PRS_RTypeColumnTypes arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_RTupleRtupless. A constant time operation.
 * \param[in] arg0 first PRS_RTupleRtuples to be compared
 * \param[in] arg1 second PRS_RTupleRtuples to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualRTupleRtuples(PRS_RTupleRtuples arg0, PRS_RTupleRtuples arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_LexStrChars. A constant time operation.
 * \param[in] arg0 first PRS_LexStrChar to be compared
 * \param[in] arg1 second PRS_LexStrChar to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualLexStrChar(PRS_LexStrChar arg0, PRS_LexStrChar arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_StrChars. A constant time operation.
 * \param[in] arg0 first PRS_StrChar to be compared
 * \param[in] arg1 second PRS_StrChar to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualStrChar(PRS_StrChar arg0, PRS_StrChar arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_LexStrCons. A constant time operation.
 * \param[in] arg0 first PRS_LexStrCon to be compared
 * \param[in] arg1 second PRS_LexStrCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualLexStrCon(PRS_LexStrCon arg0, PRS_LexStrCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_StrCons. A constant time operation.
 * \param[in] arg0 first PRS_StrCon to be compared
 * \param[in] arg1 second PRS_StrCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualStrCon(PRS_StrCon arg0, PRS_StrCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_LexStrCharCharss. A constant time operation.
 * \param[in] arg0 first PRS_LexStrCharChars to be compared
 * \param[in] arg1 second PRS_LexStrCharChars to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualLexStrCharChars(PRS_LexStrCharChars arg0, PRS_LexStrCharChars arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_LexNatCons. A constant time operation.
 * \param[in] arg0 first PRS_LexNatCon to be compared
 * \param[in] arg1 second PRS_LexNatCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualLexNatCon(PRS_LexNatCon arg0, PRS_LexNatCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_NatCons. A constant time operation.
 * \param[in] arg0 first PRS_NatCon to be compared
 * \param[in] arg1 second PRS_NatCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualNatCon(PRS_NatCon arg0, PRS_NatCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_LexIdCons. A constant time operation.
 * \param[in] arg0 first PRS_LexIdCon to be compared
 * \param[in] arg1 second PRS_LexIdCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualLexIdCon(PRS_LexIdCon arg0, PRS_LexIdCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_IdCons. A constant time operation.
 * \param[in] arg0 first PRS_IdCon to be compared
 * \param[in] arg1 second PRS_IdCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualIdCon(PRS_IdCon arg0, PRS_IdCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_LexIntCons. A constant time operation.
 * \param[in] arg0 first PRS_LexIntCon to be compared
 * \param[in] arg1 second PRS_LexIntCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualLexIntCon(PRS_LexIntCon arg0, PRS_LexIntCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_IntCons. A constant time operation.
 * \param[in] arg0 first PRS_IntCon to be compared
 * \param[in] arg1 second PRS_IntCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualIntCon(PRS_IntCon arg0, PRS_IntCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_LexLayouts. A constant time operation.
 * \param[in] arg0 first PRS_LexLayout to be compared
 * \param[in] arg1 second PRS_LexLayout to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualLexLayout(PRS_LexLayout arg0, PRS_LexLayout arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_Locations. A constant time operation.
 * \param[in] arg0 first PRS_Location to be compared
 * \param[in] arg1 second PRS_Location to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualLocation(PRS_Location arg0, PRS_Location arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PRS_Areas. A constant time operation.
 * \param[in] arg0 first PRS_Area to be compared
 * \param[in] arg1 second PRS_Area to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool PRS_isEqualArea(PRS_Area arg0, PRS_Area arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Assert whether a PRS_OptLayout is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_OptLayout
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidOptLayout(PRS_OptLayout arg) {
  if (PRS_isOptLayoutAbsent(arg)) {
    return ATtrue;
  }
  else if (PRS_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_OptLayout is a Absent. . May not be used to assert correctness of the PRS_OptLayout
 * \param[in] arg input PRS_OptLayout
 * \return ATtrue if #arg corresponds to the signature of a Absent, or ATfalse otherwise
 */
inline ATbool PRS_isOptLayoutAbsent(PRS_OptLayout arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternOptLayoutAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_OptLayout is a Present. . May not be used to assert correctness of the PRS_OptLayout
 * \param[in] arg input PRS_OptLayout
 * \return ATtrue if #arg corresponds to the signature of a Present, or ATfalse otherwise
 */
inline ATbool PRS_isOptLayoutPresent(PRS_OptLayout arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternOptLayoutPresent, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_OptLayout has a layout. 
 * \param[in] arg input PRS_OptLayout
 * \return ATtrue if the PRS_OptLayout had a layout, or ATfalse otherwise
 */
ATbool PRS_hasOptLayoutLayout(PRS_OptLayout arg) {
  if (PRS_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the layout PRS_Layout of a PRS_OptLayout. Note that the precondition is that this PRS_OptLayout actually has a layout
 * \param[in] arg input PRS_OptLayout
 * \return the layout of #arg, if it exist or an undefined value if it does not
 */
PRS_Layout PRS_getOptLayoutLayout(PRS_OptLayout arg) {
  
    return (PRS_Layout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Set the layout of a PRS_OptLayout. The precondition being that this PRS_OptLayout actually has a layout
 * \param[in] arg input PRS_OptLayout
 * \param[in] layout new PRS_Layout to set in #arg
 * \return A new PRS_OptLayout with layout at the right place, or a core dump if #arg did not have a layout
 */
PRS_OptLayout PRS_setOptLayoutLayout(PRS_OptLayout arg, PRS_Layout layout) {
  if (PRS_isOptLayoutPresent(arg)) {
    return (PRS_OptLayout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) layout), 0), 1);
  }

  ATabort("OptLayout has no Layout: %t\n", arg);
  return (PRS_OptLayout)NULL;
}

/**
 * Assert whether a PRS_Layout is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_Layout
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidLayout(PRS_Layout arg) {
  if (PRS_isLayoutLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Layout is a Lex-to-cf. Always returns ATtrue
 * \param[in] arg input PRS_Layout
 * \return ATtrue if #arg corresponds to the signature of a Lex-to-cf, or ATfalse otherwise
 */
inline ATbool PRS_isLayoutLexToCf(PRS_Layout arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternLayoutLexToCf, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_Layout has a list. 
 * \param[in] arg input PRS_Layout
 * \return ATtrue if the PRS_Layout had a list, or ATfalse otherwise
 */
ATbool PRS_hasLayoutList(PRS_Layout arg) {
  if (PRS_isLayoutLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the list PRS_LexLayoutList of a PRS_Layout. Note that the precondition is that this PRS_Layout actually has a list
 * \param[in] arg input PRS_Layout
 * \return the list of #arg, if it exist or an undefined value if it does not
 */
PRS_LexLayoutList PRS_getLayoutList(PRS_Layout arg) {
  
    return (PRS_LexLayoutList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/**
 * Set the list of a PRS_Layout. The precondition being that this PRS_Layout actually has a list
 * \param[in] arg input PRS_Layout
 * \param[in] list new PRS_LexLayoutList to set in #arg
 * \return A new PRS_Layout with list at the right place, or a core dump if #arg did not have a list
 */
PRS_Layout PRS_setLayoutList(PRS_Layout arg, PRS_LexLayoutList list) {
  if (PRS_isLayoutLexToCf(arg)) {
    return (PRS_Layout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) list), 1), 0), 1);
  }

  ATabort("Layout has no List: %t\n", arg);
  return (PRS_Layout)NULL;
}

/**
 * Assert whether a PRS_LexLayoutList is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_LexLayoutList
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidLexLayoutList(PRS_LexLayoutList arg) {
  if (PRS_isLexLayoutListEmpty(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexLayoutListSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_LexLayoutList is a empty. . May not be used to assert correctness of the PRS_LexLayoutList
 * \param[in] arg input PRS_LexLayoutList
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool PRS_isLexLayoutListEmpty(PRS_LexLayoutList arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternLexLayoutListEmpty));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_LexLayoutList is a single. . May not be used to assert correctness of the PRS_LexLayoutList
 * \param[in] arg input PRS_LexLayoutList
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool PRS_isLexLayoutListSingle(PRS_LexLayoutList arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexLayoutListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_LexLayoutList is a many. . May not be used to assert correctness of the PRS_LexLayoutList
 * \param[in] arg input PRS_LexLayoutList
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool PRS_isLexLayoutListMany(PRS_LexLayoutList arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexLayoutListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_LexLayoutList has a head. 
 * \param[in] arg input PRS_LexLayoutList
 * \return ATtrue if the PRS_LexLayoutList had a head, or ATfalse otherwise
 */
ATbool PRS_hasLexLayoutListHead(PRS_LexLayoutList arg) {
  if (PRS_isLexLayoutListSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_LexLayoutList has a tail. 
 * \param[in] arg input PRS_LexLayoutList
 * \return ATtrue if the PRS_LexLayoutList had a tail, or ATfalse otherwise
 */
ATbool PRS_hasLexLayoutListTail(PRS_LexLayoutList arg) {
  if (PRS_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head PRS_LexLayout of a PRS_LexLayoutList. Note that the precondition is that this PRS_LexLayoutList actually has a head
 * \param[in] arg input PRS_LexLayoutList
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
PRS_LexLayout PRS_getLexLayoutListHead(PRS_LexLayoutList arg) {
  if (PRS_isLexLayoutListSingle(arg)) {
    return (PRS_LexLayout)ATgetFirst((ATermList)arg);
  }
  else 
    return (PRS_LexLayout)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail PRS_LexLayoutList of a PRS_LexLayoutList. Note that the precondition is that this PRS_LexLayoutList actually has a tail
 * \param[in] arg input PRS_LexLayoutList
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
PRS_LexLayoutList PRS_getLexLayoutListTail(PRS_LexLayoutList arg) {
  
    return (PRS_LexLayoutList)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a PRS_LexLayoutList. The precondition being that this PRS_LexLayoutList actually has a head
 * \param[in] arg input PRS_LexLayoutList
 * \param[in] head new PRS_LexLayout to set in #arg
 * \return A new PRS_LexLayoutList with head at the right place, or a core dump if #arg did not have a head
 */
PRS_LexLayoutList PRS_setLexLayoutListHead(PRS_LexLayoutList arg, PRS_LexLayout head) {
  if (PRS_isLexLayoutListSingle(arg)) {
    return (PRS_LexLayoutList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PRS_isLexLayoutListMany(arg)) {
    return (PRS_LexLayoutList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("LexLayoutList has no Head: %t\n", arg);
  return (PRS_LexLayoutList)NULL;
}

/**
 * Set the tail of a PRS_LexLayoutList. The precondition being that this PRS_LexLayoutList actually has a tail
 * \param[in] arg input PRS_LexLayoutList
 * \param[in] tail new PRS_LexLayoutList to set in #arg
 * \return A new PRS_LexLayoutList with tail at the right place, or a core dump if #arg did not have a tail
 */
PRS_LexLayoutList PRS_setLexLayoutListTail(PRS_LexLayoutList arg, PRS_LexLayoutList tail) {
  if (PRS_isLexLayoutListMany(arg)) {
    return (PRS_LexLayoutList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("LexLayoutList has no Tail: %t\n", arg);
  return (PRS_LexLayoutList)NULL;
}

/**
 * Assert whether a PRS_RElem is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_RElem
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidRElem(PRS_RElem arg) {
  if (PRS_isRElemInteger(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemString(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemLocation(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemSet(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemBag(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RElem is a integer. . May not be used to assert correctness of the PRS_RElem
 * \param[in] arg input PRS_RElem
 * \return ATtrue if #arg corresponds to the signature of a integer, or ATfalse otherwise
 */
inline ATbool PRS_isRElemInteger(PRS_RElem arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRElemInteger, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RElem is a string. . May not be used to assert correctness of the PRS_RElem
 * \param[in] arg input PRS_RElem
 * \return ATtrue if #arg corresponds to the signature of a string, or ATfalse otherwise
 */
inline ATbool PRS_isRElemString(PRS_RElem arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRElemString, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RElem is a location. . May not be used to assert correctness of the PRS_RElem
 * \param[in] arg input PRS_RElem
 * \return ATtrue if #arg corresponds to the signature of a location, or ATfalse otherwise
 */
inline ATbool PRS_isRElemLocation(PRS_RElem arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRElemLocation, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RElem is a set. . May not be used to assert correctness of the PRS_RElem
 * \param[in] arg input PRS_RElem
 * \return ATtrue if #arg corresponds to the signature of a set, or ATfalse otherwise
 */
inline ATbool PRS_isRElemSet(PRS_RElem arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRElemSet, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RElem is a bag. . May not be used to assert correctness of the PRS_RElem
 * \param[in] arg input PRS_RElem
 * \return ATtrue if #arg corresponds to the signature of a bag, or ATfalse otherwise
 */
inline ATbool PRS_isRElemBag(PRS_RElem arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRElemBag, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RElem is a tuple. . May not be used to assert correctness of the PRS_RElem
 * \param[in] arg input PRS_RElem
 * \return ATtrue if #arg corresponds to the signature of a tuple, or ATfalse otherwise
 */
inline ATbool PRS_isRElemTuple(PRS_RElem arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRElemTuple, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RElem has a IntCon. 
 * \param[in] arg input PRS_RElem
 * \return ATtrue if the PRS_RElem had a IntCon, or ATfalse otherwise
 */
ATbool PRS_hasRElemIntCon(PRS_RElem arg) {
  if (PRS_isRElemInteger(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RElem has a StrCon. 
 * \param[in] arg input PRS_RElem
 * \return ATtrue if the PRS_RElem had a StrCon, or ATfalse otherwise
 */
ATbool PRS_hasRElemStrCon(PRS_RElem arg) {
  if (PRS_isRElemString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RElem has a Location. 
 * \param[in] arg input PRS_RElem
 * \return ATtrue if the PRS_RElem had a Location, or ATfalse otherwise
 */
ATbool PRS_hasRElemLocation(PRS_RElem arg) {
  if (PRS_isRElemLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RElem has a ws-after-{. 
 * \param[in] arg input PRS_RElem
 * \return ATtrue if the PRS_RElem had a ws-after-{, or ATfalse otherwise
 */
ATbool PRS_hasRElemWsAfterBraceOpen(PRS_RElem arg) {
  if (PRS_isRElemSet(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RElem has a elements. 
 * \param[in] arg input PRS_RElem
 * \return ATtrue if the PRS_RElem had a elements, or ATfalse otherwise
 */
ATbool PRS_hasRElemElements(PRS_RElem arg) {
  if (PRS_isRElemSet(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemBag(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RElem has a ws-after-elements. 
 * \param[in] arg input PRS_RElem
 * \return ATtrue if the PRS_RElem had a ws-after-elements, or ATfalse otherwise
 */
ATbool PRS_hasRElemWsAfterElements(PRS_RElem arg) {
  if (PRS_isRElemSet(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemBag(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RElem has a ws-after-{|. 
 * \param[in] arg input PRS_RElem
 * \return ATtrue if the PRS_RElem had a ws-after-{|, or ATfalse otherwise
 */
ATbool PRS_hasRElemWsAfterBraceOpenBar(PRS_RElem arg) {
  if (PRS_isRElemBag(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RElem has a ws-after-<. 
 * \param[in] arg input PRS_RElem
 * \return ATtrue if the PRS_RElem had a ws-after-<, or ATfalse otherwise
 */
ATbool PRS_hasRElemWsAfterLessThan(PRS_RElem arg) {
  if (PRS_isRElemTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the IntCon PRS_IntCon of a PRS_RElem. Note that the precondition is that this PRS_RElem actually has a IntCon
 * \param[in] arg input PRS_RElem
 * \return the IntCon of #arg, if it exist or an undefined value if it does not
 */
PRS_IntCon PRS_getRElemIntCon(PRS_RElem arg) {
  
    return (PRS_IntCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Get the StrCon PRS_StrCon of a PRS_RElem. Note that the precondition is that this PRS_RElem actually has a StrCon
 * \param[in] arg input PRS_RElem
 * \return the StrCon of #arg, if it exist or an undefined value if it does not
 */
PRS_StrCon PRS_getRElemStrCon(PRS_RElem arg) {
  
    return (PRS_StrCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Get the Location PRS_Location of a PRS_RElem. Note that the precondition is that this PRS_RElem actually has a Location
 * \param[in] arg input PRS_RElem
 * \return the Location of #arg, if it exist or an undefined value if it does not
 */
PRS_Location PRS_getRElemLocation(PRS_RElem arg) {
  
    return (PRS_Location)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Get the ws-after-{ PRS_OptLayout of a PRS_RElem. Note that the precondition is that this PRS_RElem actually has a ws-after-{
 * \param[in] arg input PRS_RElem
 * \return the ws-after-{ of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRElemWsAfterBraceOpen(PRS_RElem arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the elements PRS_RElemElements of a PRS_RElem. Note that the precondition is that this PRS_RElem actually has a elements
 * \param[in] arg input PRS_RElem
 * \return the elements of #arg, if it exist or an undefined value if it does not
 */
PRS_RElemElements PRS_getRElemElements(PRS_RElem arg) {
  if (PRS_isRElemSet(arg)) {
    return (PRS_RElemElements)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
  }
  else if (PRS_isRElemBag(arg)) {
    return (PRS_RElemElements)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
  }
  else 
    return (PRS_RElemElements)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/**
 * Get the ws-after-elements PRS_OptLayout of a PRS_RElem. Note that the precondition is that this PRS_RElem actually has a ws-after-elements
 * \param[in] arg input PRS_RElem
 * \return the ws-after-elements of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRElemWsAfterElements(PRS_RElem arg) {
  if (PRS_isRElemSet(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PRS_isRElemBag(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/**
 * Get the ws-after-{| PRS_OptLayout of a PRS_RElem. Note that the precondition is that this PRS_RElem actually has a ws-after-{|
 * \param[in] arg input PRS_RElem
 * \return the ws-after-{| of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRElemWsAfterBraceOpenBar(PRS_RElem arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-< PRS_OptLayout of a PRS_RElem. Note that the precondition is that this PRS_RElem actually has a ws-after-<
 * \param[in] arg input PRS_RElem
 * \return the ws-after-< of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRElemWsAfterLessThan(PRS_RElem arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Set the IntCon of a PRS_RElem. The precondition being that this PRS_RElem actually has a IntCon
 * \param[in] arg input PRS_RElem
 * \param[in] IntCon new PRS_IntCon to set in #arg
 * \return A new PRS_RElem with IntCon at the right place, or a core dump if #arg did not have a IntCon
 */
PRS_RElem PRS_setRElemIntCon(PRS_RElem arg, PRS_IntCon IntCon) {
  if (PRS_isRElemInteger(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) IntCon), 0), 1);
  }

  ATabort("RElem has no IntCon: %t\n", arg);
  return (PRS_RElem)NULL;
}

/**
 * Set the StrCon of a PRS_RElem. The precondition being that this PRS_RElem actually has a StrCon
 * \param[in] arg input PRS_RElem
 * \param[in] StrCon new PRS_StrCon to set in #arg
 * \return A new PRS_RElem with StrCon at the right place, or a core dump if #arg did not have a StrCon
 */
PRS_RElem PRS_setRElemStrCon(PRS_RElem arg, PRS_StrCon StrCon) {
  if (PRS_isRElemString(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrCon), 0), 1);
  }

  ATabort("RElem has no StrCon: %t\n", arg);
  return (PRS_RElem)NULL;
}

/**
 * Set the Location of a PRS_RElem. The precondition being that this PRS_RElem actually has a Location
 * \param[in] arg input PRS_RElem
 * \param[in] Location new PRS_Location to set in #arg
 * \return A new PRS_RElem with Location at the right place, or a core dump if #arg did not have a Location
 */
PRS_RElem PRS_setRElemLocation(PRS_RElem arg, PRS_Location Location) {
  if (PRS_isRElemLocation(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Location), 0), 1);
  }

  ATabort("RElem has no Location: %t\n", arg);
  return (PRS_RElem)NULL;
}

/**
 * Set the ws-after-{ of a PRS_RElem. The precondition being that this PRS_RElem actually has a ws-after-{
 * \param[in] arg input PRS_RElem
 * \param[in] wsAfterBraceOpen new PRS_OptLayout to set in #arg
 * \return A new PRS_RElem with wsAfterBraceOpen at the right place, or a core dump if #arg did not have a wsAfterBraceOpen
 */
PRS_RElem PRS_setRElemWsAfterBraceOpen(PRS_RElem arg, PRS_OptLayout wsAfterBraceOpen) {
  if (PRS_isRElemSet(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBraceOpen), 1), 1);
  }

  ATabort("RElem has no WsAfterBraceOpen: %t\n", arg);
  return (PRS_RElem)NULL;
}

/**
 * Set the elements of a PRS_RElem. The precondition being that this PRS_RElem actually has a elements
 * \param[in] arg input PRS_RElem
 * \param[in] elements new PRS_RElemElements to set in #arg
 * \return A new PRS_RElem with elements at the right place, or a core dump if #arg did not have a elements
 */
PRS_RElem PRS_setRElemElements(PRS_RElem arg, PRS_RElemElements elements) {
  if (PRS_isRElemSet(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) elements), 1), 2), 1);
  }
  else if (PRS_isRElemBag(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) elements), 1), 2), 1);
  }
  else if (PRS_isRElemTuple(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) elements), 1), 2), 1);
  }

  ATabort("RElem has no Elements: %t\n", arg);
  return (PRS_RElem)NULL;
}

/**
 * Set the ws-after-elements of a PRS_RElem. The precondition being that this PRS_RElem actually has a ws-after-elements
 * \param[in] arg input PRS_RElem
 * \param[in] wsAfterElements new PRS_OptLayout to set in #arg
 * \return A new PRS_RElem with wsAfterElements at the right place, or a core dump if #arg did not have a wsAfterElements
 */
PRS_RElem PRS_setRElemWsAfterElements(PRS_RElem arg, PRS_OptLayout wsAfterElements) {
  if (PRS_isRElemSet(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterElements), 3), 1);
  }
  else if (PRS_isRElemBag(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterElements), 3), 1);
  }
  else if (PRS_isRElemTuple(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterElements), 3), 1);
  }

  ATabort("RElem has no WsAfterElements: %t\n", arg);
  return (PRS_RElem)NULL;
}

/**
 * Set the ws-after-{| of a PRS_RElem. The precondition being that this PRS_RElem actually has a ws-after-{|
 * \param[in] arg input PRS_RElem
 * \param[in] wsAfterBraceOpenBar new PRS_OptLayout to set in #arg
 * \return A new PRS_RElem with wsAfterBraceOpenBar at the right place, or a core dump if #arg did not have a wsAfterBraceOpenBar
 */
PRS_RElem PRS_setRElemWsAfterBraceOpenBar(PRS_RElem arg, PRS_OptLayout wsAfterBraceOpenBar) {
  if (PRS_isRElemBag(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBraceOpenBar), 1), 1);
  }

  ATabort("RElem has no WsAfterBraceOpenBar: %t\n", arg);
  return (PRS_RElem)NULL;
}

/**
 * Set the ws-after-< of a PRS_RElem. The precondition being that this PRS_RElem actually has a ws-after-<
 * \param[in] arg input PRS_RElem
 * \param[in] wsAfterLessThan new PRS_OptLayout to set in #arg
 * \return A new PRS_RElem with wsAfterLessThan at the right place, or a core dump if #arg did not have a wsAfterLessThan
 */
PRS_RElem PRS_setRElemWsAfterLessThan(PRS_RElem arg, PRS_OptLayout wsAfterLessThan) {
  if (PRS_isRElemTuple(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLessThan), 1), 1);
  }

  ATabort("RElem has no WsAfterLessThan: %t\n", arg);
  return (PRS_RElem)NULL;
}

/**
 * Assert whether a PRS_RType is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_RType
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidRType(PRS_RType arg) {
  if (PRS_isRTypeInteger(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeBoolean(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeString(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeLocation(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeTuple(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeSet(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeBag(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeRelation(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeUserDefined(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeParameter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RType is a integer. . May not be used to assert correctness of the PRS_RType
 * \param[in] arg input PRS_RType
 * \return ATtrue if #arg corresponds to the signature of a integer, or ATfalse otherwise
 */
inline ATbool PRS_isRTypeInteger(PRS_RType arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeInteger);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RType is a boolean. . May not be used to assert correctness of the PRS_RType
 * \param[in] arg input PRS_RType
 * \return ATtrue if #arg corresponds to the signature of a boolean, or ATfalse otherwise
 */
inline ATbool PRS_isRTypeBoolean(PRS_RType arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeBoolean);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RType is a string. . May not be used to assert correctness of the PRS_RType
 * \param[in] arg input PRS_RType
 * \return ATtrue if #arg corresponds to the signature of a string, or ATfalse otherwise
 */
inline ATbool PRS_isRTypeString(PRS_RType arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeString);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RType is a location. . May not be used to assert correctness of the PRS_RType
 * \param[in] arg input PRS_RType
 * \return ATtrue if #arg corresponds to the signature of a location, or ATfalse otherwise
 */
inline ATbool PRS_isRTypeLocation(PRS_RType arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeLocation);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RType is a tuple. . May not be used to assert correctness of the PRS_RType
 * \param[in] arg input PRS_RType
 * \return ATtrue if #arg corresponds to the signature of a tuple, or ATfalse otherwise
 */
inline ATbool PRS_isRTypeTuple(PRS_RType arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeTuple, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RType is a set. . May not be used to assert correctness of the PRS_RType
 * \param[in] arg input PRS_RType
 * \return ATtrue if #arg corresponds to the signature of a set, or ATfalse otherwise
 */
inline ATbool PRS_isRTypeSet(PRS_RType arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeSet, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RType is a bag. . May not be used to assert correctness of the PRS_RType
 * \param[in] arg input PRS_RType
 * \return ATtrue if #arg corresponds to the signature of a bag, or ATfalse otherwise
 */
inline ATbool PRS_isRTypeBag(PRS_RType arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeBag, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RType is a relation. . May not be used to assert correctness of the PRS_RType
 * \param[in] arg input PRS_RType
 * \return ATtrue if #arg corresponds to the signature of a relation, or ATfalse otherwise
 */
inline ATbool PRS_isRTypeRelation(PRS_RType arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeRelation, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RType is a user-defined. . May not be used to assert correctness of the PRS_RType
 * \param[in] arg input PRS_RType
 * \return ATtrue if #arg corresponds to the signature of a user-defined, or ATfalse otherwise
 */
inline ATbool PRS_isRTypeUserDefined(PRS_RType arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeUserDefined, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RType is a parameter. . May not be used to assert correctness of the PRS_RType
 * \param[in] arg input PRS_RType
 * \return ATtrue if #arg corresponds to the signature of a parameter, or ATfalse otherwise
 */
inline ATbool PRS_isRTypeParameter(PRS_RType arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeParameter, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RType has a ws-after-<. 
 * \param[in] arg input PRS_RType
 * \return ATtrue if the PRS_RType had a ws-after-<, or ATfalse otherwise
 */
ATbool PRS_hasRTypeWsAfterLessThan(PRS_RType arg) {
  if (PRS_isRTypeTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RType has a column-types. 
 * \param[in] arg input PRS_RType
 * \return ATtrue if the PRS_RType had a column-types, or ATfalse otherwise
 */
ATbool PRS_hasRTypeColumnTypes(PRS_RType arg) {
  if (PRS_isRTypeTuple(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeRelation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RType has a ws-after-column-types. 
 * \param[in] arg input PRS_RType
 * \return ATtrue if the PRS_RType had a ws-after-column-types, or ATfalse otherwise
 */
ATbool PRS_hasRTypeWsAfterColumnTypes(PRS_RType arg) {
  if (PRS_isRTypeTuple(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeRelation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RType has a ws-after-set. 
 * \param[in] arg input PRS_RType
 * \return ATtrue if the PRS_RType had a ws-after-set, or ATfalse otherwise
 */
ATbool PRS_hasRTypeWsAfterSet(PRS_RType arg) {
  if (PRS_isRTypeSet(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RType has a ws-after-[. 
 * \param[in] arg input PRS_RType
 * \return ATtrue if the PRS_RType had a ws-after-[, or ATfalse otherwise
 */
ATbool PRS_hasRTypeWsAfterBracketOpen(PRS_RType arg) {
  if (PRS_isRTypeSet(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeBag(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeRelation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RType has a element-type. 
 * \param[in] arg input PRS_RType
 * \return ATtrue if the PRS_RType had a element-type, or ATfalse otherwise
 */
ATbool PRS_hasRTypeElementType(PRS_RType arg) {
  if (PRS_isRTypeSet(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeBag(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RType has a ws-after-element-type. 
 * \param[in] arg input PRS_RType
 * \return ATtrue if the PRS_RType had a ws-after-element-type, or ATfalse otherwise
 */
ATbool PRS_hasRTypeWsAfterElementType(PRS_RType arg) {
  if (PRS_isRTypeSet(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeBag(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RType has a ws-after-bag. 
 * \param[in] arg input PRS_RType
 * \return ATtrue if the PRS_RType had a ws-after-bag, or ATfalse otherwise
 */
ATbool PRS_hasRTypeWsAfterBag(PRS_RType arg) {
  if (PRS_isRTypeBag(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RType has a ws-after-rel. 
 * \param[in] arg input PRS_RType
 * \return ATtrue if the PRS_RType had a ws-after-rel, or ATfalse otherwise
 */
ATbool PRS_hasRTypeWsAfterRel(PRS_RType arg) {
  if (PRS_isRTypeRelation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RType has a name. 
 * \param[in] arg input PRS_RType
 * \return ATtrue if the PRS_RType had a name, or ATfalse otherwise
 */
ATbool PRS_hasRTypeName(PRS_RType arg) {
  if (PRS_isRTypeUserDefined(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeParameter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RType has a ws-after-&. 
 * \param[in] arg input PRS_RType
 * \return ATtrue if the PRS_RType had a ws-after-&, or ATfalse otherwise
 */
ATbool PRS_hasRTypeWsAfterAmp(PRS_RType arg) {
  if (PRS_isRTypeParameter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ws-after-< PRS_OptLayout of a PRS_RType. Note that the precondition is that this PRS_RType actually has a ws-after-<
 * \param[in] arg input PRS_RType
 * \return the ws-after-< of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRTypeWsAfterLessThan(PRS_RType arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the column-types PRS_RTypeColumnTypes of a PRS_RType. Note that the precondition is that this PRS_RType actually has a column-types
 * \param[in] arg input PRS_RType
 * \return the column-types of #arg, if it exist or an undefined value if it does not
 */
PRS_RTypeColumnTypes PRS_getRTypeColumnTypes(PRS_RType arg) {
  if (PRS_isRTypeTuple(arg)) {
    return (PRS_RTypeColumnTypes)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
  }
  else 
    return (PRS_RTypeColumnTypes)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/**
 * Get the ws-after-column-types PRS_OptLayout of a PRS_RType. Note that the precondition is that this PRS_RType actually has a ws-after-column-types
 * \param[in] arg input PRS_RType
 * \return the ws-after-column-types of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRTypeWsAfterColumnTypes(PRS_RType arg) {
  if (PRS_isRTypeTuple(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/**
 * Get the ws-after-set PRS_OptLayout of a PRS_RType. Note that the precondition is that this PRS_RType actually has a ws-after-set
 * \param[in] arg input PRS_RType
 * \return the ws-after-set of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRTypeWsAfterSet(PRS_RType arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-[ PRS_OptLayout of a PRS_RType. Note that the precondition is that this PRS_RType actually has a ws-after-[
 * \param[in] arg input PRS_RType
 * \return the ws-after-[ of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRTypeWsAfterBracketOpen(PRS_RType arg) {
  if (PRS_isRTypeSet(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PRS_isRTypeBag(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/**
 * Get the element-type PRS_RType of a PRS_RType. Note that the precondition is that this PRS_RType actually has a element-type
 * \param[in] arg input PRS_RType
 * \return the element-type of #arg, if it exist or an undefined value if it does not
 */
PRS_RType PRS_getRTypeElementType(PRS_RType arg) {
  if (PRS_isRTypeSet(arg)) {
    return (PRS_RType)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (PRS_RType)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/**
 * Get the ws-after-element-type PRS_OptLayout of a PRS_RType. Note that the precondition is that this PRS_RType actually has a ws-after-element-type
 * \param[in] arg input PRS_RType
 * \return the ws-after-element-type of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRTypeWsAfterElementType(PRS_RType arg) {
  if (PRS_isRTypeSet(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/**
 * Get the ws-after-bag PRS_OptLayout of a PRS_RType. Note that the precondition is that this PRS_RType actually has a ws-after-bag
 * \param[in] arg input PRS_RType
 * \return the ws-after-bag of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRTypeWsAfterBag(PRS_RType arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-rel PRS_OptLayout of a PRS_RType. Note that the precondition is that this PRS_RType actually has a ws-after-rel
 * \param[in] arg input PRS_RType
 * \return the ws-after-rel of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRTypeWsAfterRel(PRS_RType arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the name PRS_IdCon of a PRS_RType. Note that the precondition is that this PRS_RType actually has a name
 * \param[in] arg input PRS_RType
 * \return the name of #arg, if it exist or an undefined value if it does not
 */
PRS_IdCon PRS_getRTypeName(PRS_RType arg) {
  if (PRS_isRTypeUserDefined(arg)) {
    return (PRS_IdCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (PRS_IdCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/**
 * Get the ws-after-& PRS_OptLayout of a PRS_RType. Note that the precondition is that this PRS_RType actually has a ws-after-&
 * \param[in] arg input PRS_RType
 * \return the ws-after-& of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRTypeWsAfterAmp(PRS_RType arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Set the ws-after-< of a PRS_RType. The precondition being that this PRS_RType actually has a ws-after-<
 * \param[in] arg input PRS_RType
 * \param[in] wsAfterLessThan new PRS_OptLayout to set in #arg
 * \return A new PRS_RType with wsAfterLessThan at the right place, or a core dump if #arg did not have a wsAfterLessThan
 */
PRS_RType PRS_setRTypeWsAfterLessThan(PRS_RType arg, PRS_OptLayout wsAfterLessThan) {
  if (PRS_isRTypeTuple(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLessThan), 1), 1);
  }

  ATabort("RType has no WsAfterLessThan: %t\n", arg);
  return (PRS_RType)NULL;
}

/**
 * Set the column-types of a PRS_RType. The precondition being that this PRS_RType actually has a column-types
 * \param[in] arg input PRS_RType
 * \param[in] columnTypes new PRS_RTypeColumnTypes to set in #arg
 * \return A new PRS_RType with columnTypes at the right place, or a core dump if #arg did not have a columnTypes
 */
PRS_RType PRS_setRTypeColumnTypes(PRS_RType arg, PRS_RTypeColumnTypes columnTypes) {
  if (PRS_isRTypeTuple(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) columnTypes), 1), 2), 1);
  }
  else if (PRS_isRTypeRelation(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)((ATerm) columnTypes), 1), 4), 1);
  }

  ATabort("RType has no ColumnTypes: %t\n", arg);
  return (PRS_RType)NULL;
}

/**
 * Set the ws-after-column-types of a PRS_RType. The precondition being that this PRS_RType actually has a ws-after-column-types
 * \param[in] arg input PRS_RType
 * \param[in] wsAfterColumnTypes new PRS_OptLayout to set in #arg
 * \return A new PRS_RType with wsAfterColumnTypes at the right place, or a core dump if #arg did not have a wsAfterColumnTypes
 */
PRS_RType PRS_setRTypeWsAfterColumnTypes(PRS_RType arg, PRS_OptLayout wsAfterColumnTypes) {
  if (PRS_isRTypeTuple(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterColumnTypes), 3), 1);
  }
  else if (PRS_isRTypeRelation(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterColumnTypes), 5), 1);
  }

  ATabort("RType has no WsAfterColumnTypes: %t\n", arg);
  return (PRS_RType)NULL;
}

/**
 * Set the ws-after-set of a PRS_RType. The precondition being that this PRS_RType actually has a ws-after-set
 * \param[in] arg input PRS_RType
 * \param[in] wsAfterSet new PRS_OptLayout to set in #arg
 * \return A new PRS_RType with wsAfterSet at the right place, or a core dump if #arg did not have a wsAfterSet
 */
PRS_RType PRS_setRTypeWsAfterSet(PRS_RType arg, PRS_OptLayout wsAfterSet) {
  if (PRS_isRTypeSet(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSet), 1), 1);
  }

  ATabort("RType has no WsAfterSet: %t\n", arg);
  return (PRS_RType)NULL;
}

/**
 * Set the ws-after-[ of a PRS_RType. The precondition being that this PRS_RType actually has a ws-after-[
 * \param[in] arg input PRS_RType
 * \param[in] wsAfterBracketOpen new PRS_OptLayout to set in #arg
 * \return A new PRS_RType with wsAfterBracketOpen at the right place, or a core dump if #arg did not have a wsAfterBracketOpen
 */
PRS_RType PRS_setRTypeWsAfterBracketOpen(PRS_RType arg, PRS_OptLayout wsAfterBracketOpen) {
  if (PRS_isRTypeSet(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 3), 1);
  }
  else if (PRS_isRTypeBag(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 3), 1);
  }
  else if (PRS_isRTypeRelation(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 3), 1);
  }

  ATabort("RType has no WsAfterBracketOpen: %t\n", arg);
  return (PRS_RType)NULL;
}

/**
 * Set the element-type of a PRS_RType. The precondition being that this PRS_RType actually has a element-type
 * \param[in] arg input PRS_RType
 * \param[in] elementType new PRS_RType to set in #arg
 * \return A new PRS_RType with elementType at the right place, or a core dump if #arg did not have a elementType
 */
PRS_RType PRS_setRTypeElementType(PRS_RType arg, PRS_RType elementType) {
  if (PRS_isRTypeSet(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) elementType), 4), 1);
  }
  else if (PRS_isRTypeBag(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) elementType), 4), 1);
  }

  ATabort("RType has no ElementType: %t\n", arg);
  return (PRS_RType)NULL;
}

/**
 * Set the ws-after-element-type of a PRS_RType. The precondition being that this PRS_RType actually has a ws-after-element-type
 * \param[in] arg input PRS_RType
 * \param[in] wsAfterElementType new PRS_OptLayout to set in #arg
 * \return A new PRS_RType with wsAfterElementType at the right place, or a core dump if #arg did not have a wsAfterElementType
 */
PRS_RType PRS_setRTypeWsAfterElementType(PRS_RType arg, PRS_OptLayout wsAfterElementType) {
  if (PRS_isRTypeSet(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterElementType), 5), 1);
  }
  else if (PRS_isRTypeBag(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterElementType), 5), 1);
  }

  ATabort("RType has no WsAfterElementType: %t\n", arg);
  return (PRS_RType)NULL;
}

/**
 * Set the ws-after-bag of a PRS_RType. The precondition being that this PRS_RType actually has a ws-after-bag
 * \param[in] arg input PRS_RType
 * \param[in] wsAfterBag new PRS_OptLayout to set in #arg
 * \return A new PRS_RType with wsAfterBag at the right place, or a core dump if #arg did not have a wsAfterBag
 */
PRS_RType PRS_setRTypeWsAfterBag(PRS_RType arg, PRS_OptLayout wsAfterBag) {
  if (PRS_isRTypeBag(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBag), 1), 1);
  }

  ATabort("RType has no WsAfterBag: %t\n", arg);
  return (PRS_RType)NULL;
}

/**
 * Set the ws-after-rel of a PRS_RType. The precondition being that this PRS_RType actually has a ws-after-rel
 * \param[in] arg input PRS_RType
 * \param[in] wsAfterRel new PRS_OptLayout to set in #arg
 * \return A new PRS_RType with wsAfterRel at the right place, or a core dump if #arg did not have a wsAfterRel
 */
PRS_RType PRS_setRTypeWsAfterRel(PRS_RType arg, PRS_OptLayout wsAfterRel) {
  if (PRS_isRTypeRelation(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRel), 1), 1);
  }

  ATabort("RType has no WsAfterRel: %t\n", arg);
  return (PRS_RType)NULL;
}

/**
 * Set the name of a PRS_RType. The precondition being that this PRS_RType actually has a name
 * \param[in] arg input PRS_RType
 * \param[in] name new PRS_IdCon to set in #arg
 * \return A new PRS_RType with name at the right place, or a core dump if #arg did not have a name
 */
PRS_RType PRS_setRTypeName(PRS_RType arg, PRS_IdCon name) {
  if (PRS_isRTypeUserDefined(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) name), 0), 1);
  }
  else if (PRS_isRTypeParameter(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) name), 2), 1);
  }

  ATabort("RType has no Name: %t\n", arg);
  return (PRS_RType)NULL;
}

/**
 * Set the ws-after-& of a PRS_RType. The precondition being that this PRS_RType actually has a ws-after-&
 * \param[in] arg input PRS_RType
 * \param[in] wsAfterAmp new PRS_OptLayout to set in #arg
 * \return A new PRS_RType with wsAfterAmp at the right place, or a core dump if #arg did not have a wsAfterAmp
 */
PRS_RType PRS_setRTypeWsAfterAmp(PRS_RType arg, PRS_OptLayout wsAfterAmp) {
  if (PRS_isRTypeParameter(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAmp), 1), 1);
  }

  ATabort("RType has no WsAfterAmp: %t\n", arg);
  return (PRS_RType)NULL;
}

/**
 * Assert whether a PRS_RTuple is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_RTuple
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidRTuple(PRS_RTuple arg) {
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RTuple is a rtuple. Always returns ATtrue
 * \param[in] arg input PRS_RTuple
 * \return ATtrue if #arg corresponds to the signature of a rtuple, or ATfalse otherwise
 */
inline ATbool PRS_isRTupleRtuple(PRS_RTuple arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternRTupleRtuple, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_RTuple has a ws-after-<. 
 * \param[in] arg input PRS_RTuple
 * \return ATtrue if the PRS_RTuple had a ws-after-<, or ATfalse otherwise
 */
ATbool PRS_hasRTupleWsAfterLessThan(PRS_RTuple arg) {
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RTuple has a variable. 
 * \param[in] arg input PRS_RTuple
 * \return ATtrue if the PRS_RTuple had a variable, or ATfalse otherwise
 */
ATbool PRS_hasRTupleVariable(PRS_RTuple arg) {
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RTuple has a ws-after-variable. 
 * \param[in] arg input PRS_RTuple
 * \return ATtrue if the PRS_RTuple had a ws-after-variable, or ATfalse otherwise
 */
ATbool PRS_hasRTupleWsAfterVariable(PRS_RTuple arg) {
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RTuple has a ws-after-,. 
 * \param[in] arg input PRS_RTuple
 * \return ATtrue if the PRS_RTuple had a ws-after-,, or ATfalse otherwise
 */
ATbool PRS_hasRTupleWsAfterComma(PRS_RTuple arg) {
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RTuple has a type. 
 * \param[in] arg input PRS_RTuple
 * \return ATtrue if the PRS_RTuple had a type, or ATfalse otherwise
 */
ATbool PRS_hasRTupleType(PRS_RTuple arg) {
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RTuple has a ws-after-type. 
 * \param[in] arg input PRS_RTuple
 * \return ATtrue if the PRS_RTuple had a ws-after-type, or ATfalse otherwise
 */
ATbool PRS_hasRTupleWsAfterType(PRS_RTuple arg) {
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RTuple has a ws-after-,-1. 
 * \param[in] arg input PRS_RTuple
 * \return ATtrue if the PRS_RTuple had a ws-after-,-1, or ATfalse otherwise
 */
ATbool PRS_hasRTupleWsAfterComma1(PRS_RTuple arg) {
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RTuple has a value. 
 * \param[in] arg input PRS_RTuple
 * \return ATtrue if the PRS_RTuple had a value, or ATfalse otherwise
 */
ATbool PRS_hasRTupleValue(PRS_RTuple arg) {
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RTuple has a ws-after-value. 
 * \param[in] arg input PRS_RTuple
 * \return ATtrue if the PRS_RTuple had a ws-after-value, or ATfalse otherwise
 */
ATbool PRS_hasRTupleWsAfterValue(PRS_RTuple arg) {
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ws-after-< PRS_OptLayout of a PRS_RTuple. Note that the precondition is that this PRS_RTuple actually has a ws-after-<
 * \param[in] arg input PRS_RTuple
 * \return the ws-after-< of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRTupleWsAfterLessThan(PRS_RTuple arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the variable PRS_IdCon of a PRS_RTuple. Note that the precondition is that this PRS_RTuple actually has a variable
 * \param[in] arg input PRS_RTuple
 * \return the variable of #arg, if it exist or an undefined value if it does not
 */
PRS_IdCon PRS_getRTupleVariable(PRS_RTuple arg) {
  
    return (PRS_IdCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/**
 * Get the ws-after-variable PRS_OptLayout of a PRS_RTuple. Note that the precondition is that this PRS_RTuple actually has a ws-after-variable
 * \param[in] arg input PRS_RTuple
 * \return the ws-after-variable of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRTupleWsAfterVariable(PRS_RTuple arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/**
 * Get the ws-after-, PRS_OptLayout of a PRS_RTuple. Note that the precondition is that this PRS_RTuple actually has a ws-after-,
 * \param[in] arg input PRS_RTuple
 * \return the ws-after-, of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRTupleWsAfterComma(PRS_RTuple arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/**
 * Get the type PRS_RType of a PRS_RTuple. Note that the precondition is that this PRS_RTuple actually has a type
 * \param[in] arg input PRS_RTuple
 * \return the type of #arg, if it exist or an undefined value if it does not
 */
PRS_RType PRS_getRTupleType(PRS_RTuple arg) {
  
    return (PRS_RType)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/**
 * Get the ws-after-type PRS_OptLayout of a PRS_RTuple. Note that the precondition is that this PRS_RTuple actually has a ws-after-type
 * \param[in] arg input PRS_RTuple
 * \return the ws-after-type of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRTupleWsAfterType(PRS_RTuple arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/**
 * Get the ws-after-,-1 PRS_OptLayout of a PRS_RTuple. Note that the precondition is that this PRS_RTuple actually has a ws-after-,-1
 * \param[in] arg input PRS_RTuple
 * \return the ws-after-,-1 of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRTupleWsAfterComma1(PRS_RTuple arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/**
 * Get the value PRS_RElem of a PRS_RTuple. Note that the precondition is that this PRS_RTuple actually has a value
 * \param[in] arg input PRS_RTuple
 * \return the value of #arg, if it exist or an undefined value if it does not
 */
PRS_RElem PRS_getRTupleValue(PRS_RTuple arg) {
  
    return (PRS_RElem)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10);
}

/**
 * Get the ws-after-value PRS_OptLayout of a PRS_RTuple. Note that the precondition is that this PRS_RTuple actually has a ws-after-value
 * \param[in] arg input PRS_RTuple
 * \return the ws-after-value of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRTupleWsAfterValue(PRS_RTuple arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/**
 * Set the ws-after-< of a PRS_RTuple. The precondition being that this PRS_RTuple actually has a ws-after-<
 * \param[in] arg input PRS_RTuple
 * \param[in] wsAfterLessThan new PRS_OptLayout to set in #arg
 * \return A new PRS_RTuple with wsAfterLessThan at the right place, or a core dump if #arg did not have a wsAfterLessThan
 */
PRS_RTuple PRS_setRTupleWsAfterLessThan(PRS_RTuple arg, PRS_OptLayout wsAfterLessThan) {
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLessThan), 1), 1);
  }

  ATabort("RTuple has no WsAfterLessThan: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/**
 * Set the variable of a PRS_RTuple. The precondition being that this PRS_RTuple actually has a variable
 * \param[in] arg input PRS_RTuple
 * \param[in] variable new PRS_IdCon to set in #arg
 * \return A new PRS_RTuple with variable at the right place, or a core dump if #arg did not have a variable
 */
PRS_RTuple PRS_setRTupleVariable(PRS_RTuple arg, PRS_IdCon variable) {
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) variable), 2), 1);
  }

  ATabort("RTuple has no Variable: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/**
 * Set the ws-after-variable of a PRS_RTuple. The precondition being that this PRS_RTuple actually has a ws-after-variable
 * \param[in] arg input PRS_RTuple
 * \param[in] wsAfterVariable new PRS_OptLayout to set in #arg
 * \return A new PRS_RTuple with wsAfterVariable at the right place, or a core dump if #arg did not have a wsAfterVariable
 */
PRS_RTuple PRS_setRTupleWsAfterVariable(PRS_RTuple arg, PRS_OptLayout wsAfterVariable) {
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterVariable), 3), 1);
  }

  ATabort("RTuple has no WsAfterVariable: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/**
 * Set the ws-after-, of a PRS_RTuple. The precondition being that this PRS_RTuple actually has a ws-after-,
 * \param[in] arg input PRS_RTuple
 * \param[in] wsAfterComma new PRS_OptLayout to set in #arg
 * \return A new PRS_RTuple with wsAfterComma at the right place, or a core dump if #arg did not have a wsAfterComma
 */
PRS_RTuple PRS_setRTupleWsAfterComma(PRS_RTuple arg, PRS_OptLayout wsAfterComma) {
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 5), 1);
  }

  ATabort("RTuple has no WsAfterComma: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/**
 * Set the type of a PRS_RTuple. The precondition being that this PRS_RTuple actually has a type
 * \param[in] arg input PRS_RTuple
 * \param[in] type new PRS_RType to set in #arg
 * \return A new PRS_RTuple with type at the right place, or a core dump if #arg did not have a type
 */
PRS_RTuple PRS_setRTupleType(PRS_RTuple arg, PRS_RType type) {
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) type), 6), 1);
  }

  ATabort("RTuple has no Type: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/**
 * Set the ws-after-type of a PRS_RTuple. The precondition being that this PRS_RTuple actually has a ws-after-type
 * \param[in] arg input PRS_RTuple
 * \param[in] wsAfterType new PRS_OptLayout to set in #arg
 * \return A new PRS_RTuple with wsAfterType at the right place, or a core dump if #arg did not have a wsAfterType
 */
PRS_RTuple PRS_setRTupleWsAfterType(PRS_RTuple arg, PRS_OptLayout wsAfterType) {
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterType), 7), 1);
  }

  ATabort("RTuple has no WsAfterType: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/**
 * Set the ws-after-,-1 of a PRS_RTuple. The precondition being that this PRS_RTuple actually has a ws-after-,-1
 * \param[in] arg input PRS_RTuple
 * \param[in] wsAfterComma1 new PRS_OptLayout to set in #arg
 * \return A new PRS_RTuple with wsAfterComma1 at the right place, or a core dump if #arg did not have a wsAfterComma1
 */
PRS_RTuple PRS_setRTupleWsAfterComma1(PRS_RTuple arg, PRS_OptLayout wsAfterComma1) {
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 9), 1);
  }

  ATabort("RTuple has no WsAfterComma1: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/**
 * Set the value of a PRS_RTuple. The precondition being that this PRS_RTuple actually has a value
 * \param[in] arg input PRS_RTuple
 * \param[in] value new PRS_RElem to set in #arg
 * \return A new PRS_RTuple with value at the right place, or a core dump if #arg did not have a value
 */
PRS_RTuple PRS_setRTupleValue(PRS_RTuple arg, PRS_RElem value) {
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) value), 10), 1);
  }

  ATabort("RTuple has no Value: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/**
 * Set the ws-after-value of a PRS_RTuple. The precondition being that this PRS_RTuple actually has a ws-after-value
 * \param[in] arg input PRS_RTuple
 * \param[in] wsAfterValue new PRS_OptLayout to set in #arg
 * \return A new PRS_RTuple with wsAfterValue at the right place, or a core dump if #arg did not have a wsAfterValue
 */
PRS_RTuple PRS_setRTupleWsAfterValue(PRS_RTuple arg, PRS_OptLayout wsAfterValue) {
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterValue), 11), 1);
  }

  ATabort("RTuple has no WsAfterValue: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/**
 * Assert whether a PRS_RStore is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_RStore
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidRStore(PRS_RStore arg) {
  if (PRS_isRStoreRstore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RStore is a rstore. Always returns ATtrue
 * \param[in] arg input PRS_RStore
 * \return ATtrue if #arg corresponds to the signature of a rstore, or ATfalse otherwise
 */
inline ATbool PRS_isRStoreRstore(PRS_RStore arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternRStoreRstore, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_RStore has a ws-after-rstore. 
 * \param[in] arg input PRS_RStore
 * \return ATtrue if the PRS_RStore had a ws-after-rstore, or ATfalse otherwise
 */
ATbool PRS_hasRStoreWsAfterRstore(PRS_RStore arg) {
  if (PRS_isRStoreRstore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RStore has a ws-after-(. 
 * \param[in] arg input PRS_RStore
 * \return ATtrue if the PRS_RStore had a ws-after-(, or ATfalse otherwise
 */
ATbool PRS_hasRStoreWsAfterParenOpen(PRS_RStore arg) {
  if (PRS_isRStoreRstore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RStore has a ws-after-[. 
 * \param[in] arg input PRS_RStore
 * \return ATtrue if the PRS_RStore had a ws-after-[, or ATfalse otherwise
 */
ATbool PRS_hasRStoreWsAfterBracketOpen(PRS_RStore arg) {
  if (PRS_isRStoreRstore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RStore has a rtuples. 
 * \param[in] arg input PRS_RStore
 * \return ATtrue if the PRS_RStore had a rtuples, or ATfalse otherwise
 */
ATbool PRS_hasRStoreRtuples(PRS_RStore arg) {
  if (PRS_isRStoreRstore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RStore has a ws-after-rtuples. 
 * \param[in] arg input PRS_RStore
 * \return ATtrue if the PRS_RStore had a ws-after-rtuples, or ATfalse otherwise
 */
ATbool PRS_hasRStoreWsAfterRtuples(PRS_RStore arg) {
  if (PRS_isRStoreRstore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RStore has a ws-after-]. 
 * \param[in] arg input PRS_RStore
 * \return ATtrue if the PRS_RStore had a ws-after-], or ATfalse otherwise
 */
ATbool PRS_hasRStoreWsAfterBracketClose(PRS_RStore arg) {
  if (PRS_isRStoreRstore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ws-after-rstore PRS_OptLayout of a PRS_RStore. Note that the precondition is that this PRS_RStore actually has a ws-after-rstore
 * \param[in] arg input PRS_RStore
 * \return the ws-after-rstore of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRStoreWsAfterRstore(PRS_RStore arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-( PRS_OptLayout of a PRS_RStore. Note that the precondition is that this PRS_RStore actually has a ws-after-(
 * \param[in] arg input PRS_RStore
 * \return the ws-after-( of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRStoreWsAfterParenOpen(PRS_RStore arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/**
 * Get the ws-after-[ PRS_OptLayout of a PRS_RStore. Note that the precondition is that this PRS_RStore actually has a ws-after-[
 * \param[in] arg input PRS_RStore
 * \return the ws-after-[ of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRStoreWsAfterBracketOpen(PRS_RStore arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/**
 * Get the rtuples PRS_RTupleRtuples of a PRS_RStore. Note that the precondition is that this PRS_RStore actually has a rtuples
 * \param[in] arg input PRS_RStore
 * \return the rtuples of #arg, if it exist or an undefined value if it does not
 */
PRS_RTupleRtuples PRS_getRStoreRtuples(PRS_RStore arg) {
  
    return (PRS_RTupleRtuples)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), 1);
}

/**
 * Get the ws-after-rtuples PRS_OptLayout of a PRS_RStore. Note that the precondition is that this PRS_RStore actually has a ws-after-rtuples
 * \param[in] arg input PRS_RStore
 * \return the ws-after-rtuples of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRStoreWsAfterRtuples(PRS_RStore arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/**
 * Get the ws-after-] PRS_OptLayout of a PRS_RStore. Note that the precondition is that this PRS_RStore actually has a ws-after-]
 * \param[in] arg input PRS_RStore
 * \return the ws-after-] of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRStoreWsAfterBracketClose(PRS_RStore arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/**
 * Set the ws-after-rstore of a PRS_RStore. The precondition being that this PRS_RStore actually has a ws-after-rstore
 * \param[in] arg input PRS_RStore
 * \param[in] wsAfterRstore new PRS_OptLayout to set in #arg
 * \return A new PRS_RStore with wsAfterRstore at the right place, or a core dump if #arg did not have a wsAfterRstore
 */
PRS_RStore PRS_setRStoreWsAfterRstore(PRS_RStore arg, PRS_OptLayout wsAfterRstore) {
  if (PRS_isRStoreRstore(arg)) {
    return (PRS_RStore)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRstore), 1), 1);
  }

  ATabort("RStore has no WsAfterRstore: %t\n", arg);
  return (PRS_RStore)NULL;
}

/**
 * Set the ws-after-( of a PRS_RStore. The precondition being that this PRS_RStore actually has a ws-after-(
 * \param[in] arg input PRS_RStore
 * \param[in] wsAfterParenOpen new PRS_OptLayout to set in #arg
 * \return A new PRS_RStore with wsAfterParenOpen at the right place, or a core dump if #arg did not have a wsAfterParenOpen
 */
PRS_RStore PRS_setRStoreWsAfterParenOpen(PRS_RStore arg, PRS_OptLayout wsAfterParenOpen) {
  if (PRS_isRStoreRstore(arg)) {
    return (PRS_RStore)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("RStore has no WsAfterParenOpen: %t\n", arg);
  return (PRS_RStore)NULL;
}

/**
 * Set the ws-after-[ of a PRS_RStore. The precondition being that this PRS_RStore actually has a ws-after-[
 * \param[in] arg input PRS_RStore
 * \param[in] wsAfterBracketOpen new PRS_OptLayout to set in #arg
 * \return A new PRS_RStore with wsAfterBracketOpen at the right place, or a core dump if #arg did not have a wsAfterBracketOpen
 */
PRS_RStore PRS_setRStoreWsAfterBracketOpen(PRS_RStore arg, PRS_OptLayout wsAfterBracketOpen) {
  if (PRS_isRStoreRstore(arg)) {
    return (PRS_RStore)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 5), 1);
  }

  ATabort("RStore has no WsAfterBracketOpen: %t\n", arg);
  return (PRS_RStore)NULL;
}

/**
 * Set the rtuples of a PRS_RStore. The precondition being that this PRS_RStore actually has a rtuples
 * \param[in] arg input PRS_RStore
 * \param[in] rtuples new PRS_RTupleRtuples to set in #arg
 * \return A new PRS_RStore with rtuples at the right place, or a core dump if #arg did not have a rtuples
 */
PRS_RStore PRS_setRStoreRtuples(PRS_RStore arg, PRS_RTupleRtuples rtuples) {
  if (PRS_isRStoreRstore(arg)) {
    return (PRS_RStore)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), (ATerm)((ATerm) rtuples), 1), 6), 1);
  }

  ATabort("RStore has no Rtuples: %t\n", arg);
  return (PRS_RStore)NULL;
}

/**
 * Set the ws-after-rtuples of a PRS_RStore. The precondition being that this PRS_RStore actually has a ws-after-rtuples
 * \param[in] arg input PRS_RStore
 * \param[in] wsAfterRtuples new PRS_OptLayout to set in #arg
 * \return A new PRS_RStore with wsAfterRtuples at the right place, or a core dump if #arg did not have a wsAfterRtuples
 */
PRS_RStore PRS_setRStoreWsAfterRtuples(PRS_RStore arg, PRS_OptLayout wsAfterRtuples) {
  if (PRS_isRStoreRstore(arg)) {
    return (PRS_RStore)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRtuples), 7), 1);
  }

  ATabort("RStore has no WsAfterRtuples: %t\n", arg);
  return (PRS_RStore)NULL;
}

/**
 * Set the ws-after-] of a PRS_RStore. The precondition being that this PRS_RStore actually has a ws-after-]
 * \param[in] arg input PRS_RStore
 * \param[in] wsAfterBracketClose new PRS_OptLayout to set in #arg
 * \return A new PRS_RStore with wsAfterBracketClose at the right place, or a core dump if #arg did not have a wsAfterBracketClose
 */
PRS_RStore PRS_setRStoreWsAfterBracketClose(PRS_RStore arg, PRS_OptLayout wsAfterBracketClose) {
  if (PRS_isRStoreRstore(arg)) {
    return (PRS_RStore)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 9), 1);
  }

  ATabort("RStore has no WsAfterBracketClose: %t\n", arg);
  return (PRS_RStore)NULL;
}

/**
 * Assert whether a PRS_Start is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_Start
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidStart(PRS_Start arg) {
  if (PRS_isStartRStore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Start is a RStore. Always returns ATtrue
 * \param[in] arg input PRS_Start
 * \return ATtrue if #arg corresponds to the signature of a RStore, or ATfalse otherwise
 */
inline ATbool PRS_isStartRStore(PRS_Start arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternStartRStore, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_Start has a ws-before. 
 * \param[in] arg input PRS_Start
 * \return ATtrue if the PRS_Start had a ws-before, or ATfalse otherwise
 */
ATbool PRS_hasStartWsBefore(PRS_Start arg) {
  if (PRS_isStartRStore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Start has a top-RStore. 
 * \param[in] arg input PRS_Start
 * \return ATtrue if the PRS_Start had a top-RStore, or ATfalse otherwise
 */
ATbool PRS_hasStartTopRStore(PRS_Start arg) {
  if (PRS_isStartRStore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Start has a ws-after. 
 * \param[in] arg input PRS_Start
 * \return ATtrue if the PRS_Start had a ws-after, or ATfalse otherwise
 */
ATbool PRS_hasStartWsAfter(PRS_Start arg) {
  if (PRS_isStartRStore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Start has a amb-cnt. 
 * \param[in] arg input PRS_Start
 * \return ATtrue if the PRS_Start had a amb-cnt, or ATfalse otherwise
 */
ATbool PRS_hasStartAmbCnt(PRS_Start arg) {
  if (PRS_isStartRStore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ws-before PRS_OptLayout of a PRS_Start. Note that the precondition is that this PRS_Start actually has a ws-before
 * \param[in] arg input PRS_Start
 * \return the ws-before of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getStartWsBefore(PRS_Start arg) {
  
    return (PRS_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
}

/**
 * Get the top-RStore PRS_RStore of a PRS_Start. Note that the precondition is that this PRS_Start actually has a top-RStore
 * \param[in] arg input PRS_Start
 * \return the top-RStore of #arg, if it exist or an undefined value if it does not
 */
PRS_RStore PRS_getStartTopRStore(PRS_Start arg) {
  
    return (PRS_RStore)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/**
 * Get the ws-after PRS_OptLayout of a PRS_Start. Note that the precondition is that this PRS_Start actually has a ws-after
 * \param[in] arg input PRS_Start
 * \return the ws-after of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getStartWsAfter(PRS_Start arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
}

/**
 * Get the amb-cnt int of a PRS_Start. Note that the precondition is that this PRS_Start actually has a amb-cnt
 * \param[in] arg input PRS_Start
 * \return the amb-cnt of #arg, if it exist or an undefined value if it does not
 */
int PRS_getStartAmbCnt(PRS_Start arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Set the ws-before of a PRS_Start. The precondition being that this PRS_Start actually has a ws-before
 * \param[in] arg input PRS_Start
 * \param[in] wsBefore new PRS_OptLayout to set in #arg
 * \return A new PRS_Start with wsBefore at the right place, or a core dump if #arg did not have a wsBefore
 */
PRS_Start PRS_setStartWsBefore(PRS_Start arg, PRS_OptLayout wsBefore) {
  if (PRS_isStartRStore(arg)) {
    return (PRS_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }

  ATabort("Start has no WsBefore: %t\n", arg);
  return (PRS_Start)NULL;
}

/**
 * Set the top-RStore of a PRS_Start. The precondition being that this PRS_Start actually has a top-RStore
 * \param[in] arg input PRS_Start
 * \param[in] topRStore new PRS_RStore to set in #arg
 * \return A new PRS_Start with topRStore at the right place, or a core dump if #arg did not have a topRStore
 */
PRS_Start PRS_setStartTopRStore(PRS_Start arg, PRS_RStore topRStore) {
  if (PRS_isStartRStore(arg)) {
    return (PRS_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topRStore), 1), 1), 0);
  }

  ATabort("Start has no TopRStore: %t\n", arg);
  return (PRS_Start)NULL;
}

/**
 * Set the ws-after of a PRS_Start. The precondition being that this PRS_Start actually has a ws-after
 * \param[in] arg input PRS_Start
 * \param[in] wsAfter new PRS_OptLayout to set in #arg
 * \return A new PRS_Start with wsAfter at the right place, or a core dump if #arg did not have a wsAfter
 */
PRS_Start PRS_setStartWsAfter(PRS_Start arg, PRS_OptLayout wsAfter) {
  if (PRS_isStartRStore(arg)) {
    return (PRS_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }

  ATabort("Start has no WsAfter: %t\n", arg);
  return (PRS_Start)NULL;
}

/**
 * Set the amb-cnt of a PRS_Start. The precondition being that this PRS_Start actually has a amb-cnt
 * \param[in] arg input PRS_Start
 * \param[in] ambCnt new int to set in #arg
 * \return A new PRS_Start with ambCnt at the right place, or a core dump if #arg did not have a ambCnt
 */
PRS_Start PRS_setStartAmbCnt(PRS_Start arg, int ambCnt) {
  if (PRS_isStartRStore(arg)) {
    return (PRS_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }

  ATabort("Start has no AmbCnt: %t\n", arg);
  return (PRS_Start)NULL;
}

/**
 * Assert whether a PRS_RElemElements is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_RElemElements
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidRElemElements(PRS_RElemElements arg) {
  if (PRS_isRElemElementsEmpty(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemElementsSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemElementsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RElemElements is a empty. . May not be used to assert correctness of the PRS_RElemElements
 * \param[in] arg input PRS_RElemElements
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool PRS_isRElemElementsEmpty(PRS_RElemElements arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternRElemElementsEmpty));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_RElemElements is a single. . May not be used to assert correctness of the PRS_RElemElements
 * \param[in] arg input PRS_RElemElements
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool PRS_isRElemElementsSingle(PRS_RElemElements arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRElemElementsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RElemElements is a many. . May not be used to assert correctness of the PRS_RElemElements
 * \param[in] arg input PRS_RElemElements
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool PRS_isRElemElementsMany(PRS_RElemElements arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRElemElementsMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RElemElements has a head. 
 * \param[in] arg input PRS_RElemElements
 * \return ATtrue if the PRS_RElemElements had a head, or ATfalse otherwise
 */
ATbool PRS_hasRElemElementsHead(PRS_RElemElements arg) {
  if (PRS_isRElemElementsSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemElementsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RElemElements has a ws-after-head. 
 * \param[in] arg input PRS_RElemElements
 * \return ATtrue if the PRS_RElemElements had a ws-after-head, or ATfalse otherwise
 */
ATbool PRS_hasRElemElementsWsAfterHead(PRS_RElemElements arg) {
  if (PRS_isRElemElementsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RElemElements has a ws-after-sep. 
 * \param[in] arg input PRS_RElemElements
 * \return ATtrue if the PRS_RElemElements had a ws-after-sep, or ATfalse otherwise
 */
ATbool PRS_hasRElemElementsWsAfterSep(PRS_RElemElements arg) {
  if (PRS_isRElemElementsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RElemElements has a tail. 
 * \param[in] arg input PRS_RElemElements
 * \return ATtrue if the PRS_RElemElements had a tail, or ATfalse otherwise
 */
ATbool PRS_hasRElemElementsTail(PRS_RElemElements arg) {
  if (PRS_isRElemElementsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Returns a list of all but the first element of a PRS_RElemElements. 
 * \param[in] arg input PRS_RElemElements
 * \return A new PRS_RElemElements, without the first element and the separator(s) just after it.)
 */
PRS_RElemElements PRS_getRElemElementsTail(PRS_RElemElements arg) {
  assert(!PRS_isRElemElementsEmpty(arg) && "getTail on an empty list");
  if (PRS_isRElemElementsSingle(arg)) {
    return (PRS_RElemElements) PRS_makeRElemElementsEmpty();
  }
  else {
  
    return (PRS_RElemElements)ATgetTail((ATermList)arg, 4);
  }
}

/**
 * Get the head PRS_RElem of a PRS_RElemElements. Note that the precondition is that this PRS_RElemElements actually has a head
 * \param[in] arg input PRS_RElemElements
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
PRS_RElem PRS_getRElemElementsHead(PRS_RElemElements arg) {
  if (PRS_isRElemElementsSingle(arg)) {
    return (PRS_RElem)ATgetFirst((ATermList)arg);
  }
  else 
    return (PRS_RElem)ATgetFirst((ATermList)arg);
}

/**
 * Get the ws-after-head PRS_OptLayout of a PRS_RElemElements. Note that the precondition is that this PRS_RElemElements actually has a ws-after-head
 * \param[in] arg input PRS_RElemElements
 * \return the ws-after-head of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRElemElementsWsAfterHead(PRS_RElemElements arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)arg, 1);
}

/**
 * Get the ws-after-sep PRS_OptLayout of a PRS_RElemElements. Note that the precondition is that this PRS_RElemElements actually has a ws-after-sep
 * \param[in] arg input PRS_RElemElements
 * \return the ws-after-sep of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRElemElementsWsAfterSep(PRS_RElemElements arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)arg, 3);
}

/**
 * Set the head of a PRS_RElemElements. The precondition being that this PRS_RElemElements actually has a head
 * \param[in] arg input PRS_RElemElements
 * \param[in] head new PRS_RElem to set in #arg
 * \return A new PRS_RElemElements with head at the right place, or a core dump if #arg did not have a head
 */
PRS_RElemElements PRS_setRElemElementsHead(PRS_RElemElements arg, PRS_RElem head) {
  if (PRS_isRElemElementsSingle(arg)) {
    return (PRS_RElemElements)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PRS_isRElemElementsMany(arg)) {
    return (PRS_RElemElements)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("RElemElements has no Head: %t\n", arg);
  return (PRS_RElemElements)NULL;
}

/**
 * Set the ws-after-head of a PRS_RElemElements. The precondition being that this PRS_RElemElements actually has a ws-after-head
 * \param[in] arg input PRS_RElemElements
 * \param[in] wsAfterHead new PRS_OptLayout to set in #arg
 * \return A new PRS_RElemElements with wsAfterHead at the right place, or a core dump if #arg did not have a wsAfterHead
 */
PRS_RElemElements PRS_setRElemElementsWsAfterHead(PRS_RElemElements arg, PRS_OptLayout wsAfterHead) {
  if (PRS_isRElemElementsMany(arg)) {
    return (PRS_RElemElements)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("RElemElements has no WsAfterHead: %t\n", arg);
  return (PRS_RElemElements)NULL;
}

/**
 * Set the ws-after-sep of a PRS_RElemElements. The precondition being that this PRS_RElemElements actually has a ws-after-sep
 * \param[in] arg input PRS_RElemElements
 * \param[in] wsAfterSep new PRS_OptLayout to set in #arg
 * \return A new PRS_RElemElements with wsAfterSep at the right place, or a core dump if #arg did not have a wsAfterSep
 */
PRS_RElemElements PRS_setRElemElementsWsAfterSep(PRS_RElemElements arg, PRS_OptLayout wsAfterSep) {
  if (PRS_isRElemElementsMany(arg)) {
    return (PRS_RElemElements)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("RElemElements has no WsAfterSep: %t\n", arg);
  return (PRS_RElemElements)NULL;
}

/**
 * Set the tail of a PRS_RElemElements. The precondition being that this PRS_RElemElements actually has a tail
 * \param[in] arg input PRS_RElemElements
 * \param[in] tail new PRS_RElemElements to set in #arg
 * \return A new PRS_RElemElements with tail at the right place, or a core dump if #arg did not have a tail
 */
PRS_RElemElements PRS_setRElemElementsTail(PRS_RElemElements arg, PRS_RElemElements tail) {
  if (PRS_isRElemElementsMany(arg)) {
    return (PRS_RElemElements)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("RElemElements has no Tail: %t\n", arg);
  return (PRS_RElemElements)NULL;
}

/**
 * Assert whether a PRS_RTypeColumnTypes is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_RTypeColumnTypes
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidRTypeColumnTypes(PRS_RTypeColumnTypes arg) {
  if (PRS_isRTypeColumnTypesEmpty(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeColumnTypesSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeColumnTypesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RTypeColumnTypes is a empty. . May not be used to assert correctness of the PRS_RTypeColumnTypes
 * \param[in] arg input PRS_RTypeColumnTypes
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool PRS_isRTypeColumnTypesEmpty(PRS_RTypeColumnTypes arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternRTypeColumnTypesEmpty));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_RTypeColumnTypes is a single. . May not be used to assert correctness of the PRS_RTypeColumnTypes
 * \param[in] arg input PRS_RTypeColumnTypes
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool PRS_isRTypeColumnTypesSingle(PRS_RTypeColumnTypes arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeColumnTypesSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RTypeColumnTypes is a many. . May not be used to assert correctness of the PRS_RTypeColumnTypes
 * \param[in] arg input PRS_RTypeColumnTypes
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool PRS_isRTypeColumnTypesMany(PRS_RTypeColumnTypes arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeColumnTypesMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RTypeColumnTypes has a head. 
 * \param[in] arg input PRS_RTypeColumnTypes
 * \return ATtrue if the PRS_RTypeColumnTypes had a head, or ATfalse otherwise
 */
ATbool PRS_hasRTypeColumnTypesHead(PRS_RTypeColumnTypes arg) {
  if (PRS_isRTypeColumnTypesSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeColumnTypesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RTypeColumnTypes has a ws-after-head. 
 * \param[in] arg input PRS_RTypeColumnTypes
 * \return ATtrue if the PRS_RTypeColumnTypes had a ws-after-head, or ATfalse otherwise
 */
ATbool PRS_hasRTypeColumnTypesWsAfterHead(PRS_RTypeColumnTypes arg) {
  if (PRS_isRTypeColumnTypesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RTypeColumnTypes has a ws-after-sep. 
 * \param[in] arg input PRS_RTypeColumnTypes
 * \return ATtrue if the PRS_RTypeColumnTypes had a ws-after-sep, or ATfalse otherwise
 */
ATbool PRS_hasRTypeColumnTypesWsAfterSep(PRS_RTypeColumnTypes arg) {
  if (PRS_isRTypeColumnTypesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RTypeColumnTypes has a tail. 
 * \param[in] arg input PRS_RTypeColumnTypes
 * \return ATtrue if the PRS_RTypeColumnTypes had a tail, or ATfalse otherwise
 */
ATbool PRS_hasRTypeColumnTypesTail(PRS_RTypeColumnTypes arg) {
  if (PRS_isRTypeColumnTypesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Returns a list of all but the first element of a PRS_RTypeColumnTypes. 
 * \param[in] arg input PRS_RTypeColumnTypes
 * \return A new PRS_RTypeColumnTypes, without the first element and the separator(s) just after it.)
 */
PRS_RTypeColumnTypes PRS_getRTypeColumnTypesTail(PRS_RTypeColumnTypes arg) {
  assert(!PRS_isRTypeColumnTypesEmpty(arg) && "getTail on an empty list");
  if (PRS_isRTypeColumnTypesSingle(arg)) {
    return (PRS_RTypeColumnTypes) PRS_makeRTypeColumnTypesEmpty();
  }
  else {
  
    return (PRS_RTypeColumnTypes)ATgetTail((ATermList)arg, 4);
  }
}

/**
 * Get the head PRS_RType of a PRS_RTypeColumnTypes. Note that the precondition is that this PRS_RTypeColumnTypes actually has a head
 * \param[in] arg input PRS_RTypeColumnTypes
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
PRS_RType PRS_getRTypeColumnTypesHead(PRS_RTypeColumnTypes arg) {
  if (PRS_isRTypeColumnTypesSingle(arg)) {
    return (PRS_RType)ATgetFirst((ATermList)arg);
  }
  else 
    return (PRS_RType)ATgetFirst((ATermList)arg);
}

/**
 * Get the ws-after-head PRS_OptLayout of a PRS_RTypeColumnTypes. Note that the precondition is that this PRS_RTypeColumnTypes actually has a ws-after-head
 * \param[in] arg input PRS_RTypeColumnTypes
 * \return the ws-after-head of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRTypeColumnTypesWsAfterHead(PRS_RTypeColumnTypes arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)arg, 1);
}

/**
 * Get the ws-after-sep PRS_OptLayout of a PRS_RTypeColumnTypes. Note that the precondition is that this PRS_RTypeColumnTypes actually has a ws-after-sep
 * \param[in] arg input PRS_RTypeColumnTypes
 * \return the ws-after-sep of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRTypeColumnTypesWsAfterSep(PRS_RTypeColumnTypes arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)arg, 3);
}

/**
 * Set the head of a PRS_RTypeColumnTypes. The precondition being that this PRS_RTypeColumnTypes actually has a head
 * \param[in] arg input PRS_RTypeColumnTypes
 * \param[in] head new PRS_RType to set in #arg
 * \return A new PRS_RTypeColumnTypes with head at the right place, or a core dump if #arg did not have a head
 */
PRS_RTypeColumnTypes PRS_setRTypeColumnTypesHead(PRS_RTypeColumnTypes arg, PRS_RType head) {
  if (PRS_isRTypeColumnTypesSingle(arg)) {
    return (PRS_RTypeColumnTypes)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PRS_isRTypeColumnTypesMany(arg)) {
    return (PRS_RTypeColumnTypes)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("RTypeColumnTypes has no Head: %t\n", arg);
  return (PRS_RTypeColumnTypes)NULL;
}

/**
 * Set the ws-after-head of a PRS_RTypeColumnTypes. The precondition being that this PRS_RTypeColumnTypes actually has a ws-after-head
 * \param[in] arg input PRS_RTypeColumnTypes
 * \param[in] wsAfterHead new PRS_OptLayout to set in #arg
 * \return A new PRS_RTypeColumnTypes with wsAfterHead at the right place, or a core dump if #arg did not have a wsAfterHead
 */
PRS_RTypeColumnTypes PRS_setRTypeColumnTypesWsAfterHead(PRS_RTypeColumnTypes arg, PRS_OptLayout wsAfterHead) {
  if (PRS_isRTypeColumnTypesMany(arg)) {
    return (PRS_RTypeColumnTypes)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("RTypeColumnTypes has no WsAfterHead: %t\n", arg);
  return (PRS_RTypeColumnTypes)NULL;
}

/**
 * Set the ws-after-sep of a PRS_RTypeColumnTypes. The precondition being that this PRS_RTypeColumnTypes actually has a ws-after-sep
 * \param[in] arg input PRS_RTypeColumnTypes
 * \param[in] wsAfterSep new PRS_OptLayout to set in #arg
 * \return A new PRS_RTypeColumnTypes with wsAfterSep at the right place, or a core dump if #arg did not have a wsAfterSep
 */
PRS_RTypeColumnTypes PRS_setRTypeColumnTypesWsAfterSep(PRS_RTypeColumnTypes arg, PRS_OptLayout wsAfterSep) {
  if (PRS_isRTypeColumnTypesMany(arg)) {
    return (PRS_RTypeColumnTypes)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("RTypeColumnTypes has no WsAfterSep: %t\n", arg);
  return (PRS_RTypeColumnTypes)NULL;
}

/**
 * Set the tail of a PRS_RTypeColumnTypes. The precondition being that this PRS_RTypeColumnTypes actually has a tail
 * \param[in] arg input PRS_RTypeColumnTypes
 * \param[in] tail new PRS_RTypeColumnTypes to set in #arg
 * \return A new PRS_RTypeColumnTypes with tail at the right place, or a core dump if #arg did not have a tail
 */
PRS_RTypeColumnTypes PRS_setRTypeColumnTypesTail(PRS_RTypeColumnTypes arg, PRS_RTypeColumnTypes tail) {
  if (PRS_isRTypeColumnTypesMany(arg)) {
    return (PRS_RTypeColumnTypes)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("RTypeColumnTypes has no Tail: %t\n", arg);
  return (PRS_RTypeColumnTypes)NULL;
}

/**
 * Assert whether a PRS_RTupleRtuples is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_RTupleRtuples
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidRTupleRtuples(PRS_RTupleRtuples arg) {
  if (PRS_isRTupleRtuplesEmpty(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTupleRtuplesSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTupleRtuplesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RTupleRtuples is a empty. . May not be used to assert correctness of the PRS_RTupleRtuples
 * \param[in] arg input PRS_RTupleRtuples
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool PRS_isRTupleRtuplesEmpty(PRS_RTupleRtuples arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternRTupleRtuplesEmpty));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_RTupleRtuples is a single. . May not be used to assert correctness of the PRS_RTupleRtuples
 * \param[in] arg input PRS_RTupleRtuples
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool PRS_isRTupleRtuplesSingle(PRS_RTupleRtuples arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTupleRtuplesSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RTupleRtuples is a many. . May not be used to assert correctness of the PRS_RTupleRtuples
 * \param[in] arg input PRS_RTupleRtuples
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool PRS_isRTupleRtuplesMany(PRS_RTupleRtuples arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTupleRtuplesMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_RTupleRtuples has a head. 
 * \param[in] arg input PRS_RTupleRtuples
 * \return ATtrue if the PRS_RTupleRtuples had a head, or ATfalse otherwise
 */
ATbool PRS_hasRTupleRtuplesHead(PRS_RTupleRtuples arg) {
  if (PRS_isRTupleRtuplesSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTupleRtuplesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RTupleRtuples has a ws-after-head. 
 * \param[in] arg input PRS_RTupleRtuples
 * \return ATtrue if the PRS_RTupleRtuples had a ws-after-head, or ATfalse otherwise
 */
ATbool PRS_hasRTupleRtuplesWsAfterHead(PRS_RTupleRtuples arg) {
  if (PRS_isRTupleRtuplesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RTupleRtuples has a ws-after-sep. 
 * \param[in] arg input PRS_RTupleRtuples
 * \return ATtrue if the PRS_RTupleRtuples had a ws-after-sep, or ATfalse otherwise
 */
ATbool PRS_hasRTupleRtuplesWsAfterSep(PRS_RTupleRtuples arg) {
  if (PRS_isRTupleRtuplesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_RTupleRtuples has a tail. 
 * \param[in] arg input PRS_RTupleRtuples
 * \return ATtrue if the PRS_RTupleRtuples had a tail, or ATfalse otherwise
 */
ATbool PRS_hasRTupleRtuplesTail(PRS_RTupleRtuples arg) {
  if (PRS_isRTupleRtuplesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Returns a list of all but the first element of a PRS_RTupleRtuples. 
 * \param[in] arg input PRS_RTupleRtuples
 * \return A new PRS_RTupleRtuples, without the first element and the separator(s) just after it.)
 */
PRS_RTupleRtuples PRS_getRTupleRtuplesTail(PRS_RTupleRtuples arg) {
  assert(!PRS_isRTupleRtuplesEmpty(arg) && "getTail on an empty list");
  if (PRS_isRTupleRtuplesSingle(arg)) {
    return (PRS_RTupleRtuples) PRS_makeRTupleRtuplesEmpty();
  }
  else {
  
    return (PRS_RTupleRtuples)ATgetTail((ATermList)arg, 4);
  }
}

/**
 * Get the head PRS_RTuple of a PRS_RTupleRtuples. Note that the precondition is that this PRS_RTupleRtuples actually has a head
 * \param[in] arg input PRS_RTupleRtuples
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
PRS_RTuple PRS_getRTupleRtuplesHead(PRS_RTupleRtuples arg) {
  if (PRS_isRTupleRtuplesSingle(arg)) {
    return (PRS_RTuple)ATgetFirst((ATermList)arg);
  }
  else 
    return (PRS_RTuple)ATgetFirst((ATermList)arg);
}

/**
 * Get the ws-after-head PRS_OptLayout of a PRS_RTupleRtuples. Note that the precondition is that this PRS_RTupleRtuples actually has a ws-after-head
 * \param[in] arg input PRS_RTupleRtuples
 * \return the ws-after-head of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRTupleRtuplesWsAfterHead(PRS_RTupleRtuples arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)arg, 1);
}

/**
 * Get the ws-after-sep PRS_OptLayout of a PRS_RTupleRtuples. Note that the precondition is that this PRS_RTupleRtuples actually has a ws-after-sep
 * \param[in] arg input PRS_RTupleRtuples
 * \return the ws-after-sep of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getRTupleRtuplesWsAfterSep(PRS_RTupleRtuples arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)arg, 3);
}

/**
 * Set the head of a PRS_RTupleRtuples. The precondition being that this PRS_RTupleRtuples actually has a head
 * \param[in] arg input PRS_RTupleRtuples
 * \param[in] head new PRS_RTuple to set in #arg
 * \return A new PRS_RTupleRtuples with head at the right place, or a core dump if #arg did not have a head
 */
PRS_RTupleRtuples PRS_setRTupleRtuplesHead(PRS_RTupleRtuples arg, PRS_RTuple head) {
  if (PRS_isRTupleRtuplesSingle(arg)) {
    return (PRS_RTupleRtuples)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PRS_isRTupleRtuplesMany(arg)) {
    return (PRS_RTupleRtuples)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("RTupleRtuples has no Head: %t\n", arg);
  return (PRS_RTupleRtuples)NULL;
}

/**
 * Set the ws-after-head of a PRS_RTupleRtuples. The precondition being that this PRS_RTupleRtuples actually has a ws-after-head
 * \param[in] arg input PRS_RTupleRtuples
 * \param[in] wsAfterHead new PRS_OptLayout to set in #arg
 * \return A new PRS_RTupleRtuples with wsAfterHead at the right place, or a core dump if #arg did not have a wsAfterHead
 */
PRS_RTupleRtuples PRS_setRTupleRtuplesWsAfterHead(PRS_RTupleRtuples arg, PRS_OptLayout wsAfterHead) {
  if (PRS_isRTupleRtuplesMany(arg)) {
    return (PRS_RTupleRtuples)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("RTupleRtuples has no WsAfterHead: %t\n", arg);
  return (PRS_RTupleRtuples)NULL;
}

/**
 * Set the ws-after-sep of a PRS_RTupleRtuples. The precondition being that this PRS_RTupleRtuples actually has a ws-after-sep
 * \param[in] arg input PRS_RTupleRtuples
 * \param[in] wsAfterSep new PRS_OptLayout to set in #arg
 * \return A new PRS_RTupleRtuples with wsAfterSep at the right place, or a core dump if #arg did not have a wsAfterSep
 */
PRS_RTupleRtuples PRS_setRTupleRtuplesWsAfterSep(PRS_RTupleRtuples arg, PRS_OptLayout wsAfterSep) {
  if (PRS_isRTupleRtuplesMany(arg)) {
    return (PRS_RTupleRtuples)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("RTupleRtuples has no WsAfterSep: %t\n", arg);
  return (PRS_RTupleRtuples)NULL;
}

/**
 * Set the tail of a PRS_RTupleRtuples. The precondition being that this PRS_RTupleRtuples actually has a tail
 * \param[in] arg input PRS_RTupleRtuples
 * \param[in] tail new PRS_RTupleRtuples to set in #arg
 * \return A new PRS_RTupleRtuples with tail at the right place, or a core dump if #arg did not have a tail
 */
PRS_RTupleRtuples PRS_setRTupleRtuplesTail(PRS_RTupleRtuples arg, PRS_RTupleRtuples tail) {
  if (PRS_isRTupleRtuplesMany(arg)) {
    return (PRS_RTupleRtuples)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("RTupleRtuples has no Tail: %t\n", arg);
  return (PRS_RTupleRtuples)NULL;
}

/**
 * Assert whether a PRS_LexStrChar is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_LexStrChar
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidLexStrChar(PRS_LexStrChar arg) {
  if (PRS_isLexStrCharNewline(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexStrCharTab(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexStrCharQuote(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexStrCharBackslash(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexStrCharNormal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_LexStrChar is a newline. . May not be used to assert correctness of the PRS_LexStrChar
 * \param[in] arg input PRS_LexStrChar
 * \return ATtrue if #arg corresponds to the signature of a newline, or ATfalse otherwise
 */
inline ATbool PRS_isLexStrCharNewline(PRS_LexStrChar arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexStrCharNewline);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_LexStrChar is a tab. . May not be used to assert correctness of the PRS_LexStrChar
 * \param[in] arg input PRS_LexStrChar
 * \return ATtrue if #arg corresponds to the signature of a tab, or ATfalse otherwise
 */
inline ATbool PRS_isLexStrCharTab(PRS_LexStrChar arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexStrCharTab);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_LexStrChar is a quote. . May not be used to assert correctness of the PRS_LexStrChar
 * \param[in] arg input PRS_LexStrChar
 * \return ATtrue if #arg corresponds to the signature of a quote, or ATfalse otherwise
 */
inline ATbool PRS_isLexStrCharQuote(PRS_LexStrChar arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexStrCharQuote);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_LexStrChar is a backslash. . May not be used to assert correctness of the PRS_LexStrChar
 * \param[in] arg input PRS_LexStrChar
 * \return ATtrue if #arg corresponds to the signature of a backslash, or ATfalse otherwise
 */
inline ATbool PRS_isLexStrCharBackslash(PRS_LexStrChar arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexStrCharBackslash);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_LexStrChar is a decimal. . May not be used to assert correctness of the PRS_LexStrChar
 * \param[in] arg input PRS_LexStrChar
 * \return ATtrue if #arg corresponds to the signature of a decimal, or ATfalse otherwise
 */
inline ATbool PRS_isLexStrCharDecimal(PRS_LexStrChar arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexStrCharDecimal, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_LexStrChar is a normal. . May not be used to assert correctness of the PRS_LexStrChar
 * \param[in] arg input PRS_LexStrChar
 * \return ATtrue if #arg corresponds to the signature of a normal, or ATfalse otherwise
 */
inline ATbool PRS_isLexStrCharNormal(PRS_LexStrChar arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexStrCharNormal, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_LexStrChar has a a. 
 * \param[in] arg input PRS_LexStrChar
 * \return ATtrue if the PRS_LexStrChar had a a, or ATfalse otherwise
 */
ATbool PRS_hasLexStrCharA(PRS_LexStrChar arg) {
  if (PRS_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_LexStrChar has a b. 
 * \param[in] arg input PRS_LexStrChar
 * \return ATtrue if the PRS_LexStrChar had a b, or ATfalse otherwise
 */
ATbool PRS_hasLexStrCharB(PRS_LexStrChar arg) {
  if (PRS_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_LexStrChar has a c. 
 * \param[in] arg input PRS_LexStrChar
 * \return ATtrue if the PRS_LexStrChar had a c, or ATfalse otherwise
 */
ATbool PRS_hasLexStrCharC(PRS_LexStrChar arg) {
  if (PRS_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_LexStrChar has a ch. 
 * \param[in] arg input PRS_LexStrChar
 * \return ATtrue if the PRS_LexStrChar had a ch, or ATfalse otherwise
 */
ATbool PRS_hasLexStrCharCh(PRS_LexStrChar arg) {
  if (PRS_isLexStrCharNormal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the a char of a PRS_LexStrChar. Note that the precondition is that this PRS_LexStrChar actually has a a
 * \param[in] arg input PRS_LexStrChar
 * \return the a of #arg, if it exist or an undefined value if it does not
 */
char PRS_getLexStrCharA(PRS_LexStrChar arg) {
  
    return (char)PRS_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1));
}

/**
 * Get the b char of a PRS_LexStrChar. Note that the precondition is that this PRS_LexStrChar actually has a b
 * \param[in] arg input PRS_LexStrChar
 * \return the b of #arg, if it exist or an undefined value if it does not
 */
char PRS_getLexStrCharB(PRS_LexStrChar arg) {
  
    return (char)PRS_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2));
}

/**
 * Get the c char of a PRS_LexStrChar. Note that the precondition is that this PRS_LexStrChar actually has a c
 * \param[in] arg input PRS_LexStrChar
 * \return the c of #arg, if it exist or an undefined value if it does not
 */
char PRS_getLexStrCharC(PRS_LexStrChar arg) {
  
    return (char)PRS_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3));
}

/**
 * Get the ch char of a PRS_LexStrChar. Note that the precondition is that this PRS_LexStrChar actually has a ch
 * \param[in] arg input PRS_LexStrChar
 * \return the ch of #arg, if it exist or an undefined value if it does not
 */
char PRS_getLexStrCharCh(PRS_LexStrChar arg) {
  
    return (char)PRS_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/**
 * Set the a of a PRS_LexStrChar. The precondition being that this PRS_LexStrChar actually has a a
 * \param[in] arg input PRS_LexStrChar
 * \param[in] a new char to set in #arg
 * \return A new PRS_LexStrChar with a at the right place, or a core dump if #arg did not have a a
 */
PRS_LexStrChar PRS_setLexStrCharA(PRS_LexStrChar arg, char a) {
  if (PRS_isLexStrCharDecimal(arg)) {
    return (PRS_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) PRS_byteToChar(a))), 1), 1);
  }

  ATabort("LexStrChar has no A: %t\n", arg);
  return (PRS_LexStrChar)NULL;
}

/**
 * Set the b of a PRS_LexStrChar. The precondition being that this PRS_LexStrChar actually has a b
 * \param[in] arg input PRS_LexStrChar
 * \param[in] b new char to set in #arg
 * \return A new PRS_LexStrChar with b at the right place, or a core dump if #arg did not have a b
 */
PRS_LexStrChar PRS_setLexStrCharB(PRS_LexStrChar arg, char b) {
  if (PRS_isLexStrCharDecimal(arg)) {
    return (PRS_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) PRS_byteToChar(b))), 2), 1);
  }

  ATabort("LexStrChar has no B: %t\n", arg);
  return (PRS_LexStrChar)NULL;
}

/**
 * Set the c of a PRS_LexStrChar. The precondition being that this PRS_LexStrChar actually has a c
 * \param[in] arg input PRS_LexStrChar
 * \param[in] c new char to set in #arg
 * \return A new PRS_LexStrChar with c at the right place, or a core dump if #arg did not have a c
 */
PRS_LexStrChar PRS_setLexStrCharC(PRS_LexStrChar arg, char c) {
  if (PRS_isLexStrCharDecimal(arg)) {
    return (PRS_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) PRS_byteToChar(c))), 3), 1);
  }

  ATabort("LexStrChar has no C: %t\n", arg);
  return (PRS_LexStrChar)NULL;
}

/**
 * Set the ch of a PRS_LexStrChar. The precondition being that this PRS_LexStrChar actually has a ch
 * \param[in] arg input PRS_LexStrChar
 * \param[in] ch new char to set in #arg
 * \return A new PRS_LexStrChar with ch at the right place, or a core dump if #arg did not have a ch
 */
PRS_LexStrChar PRS_setLexStrCharCh(PRS_LexStrChar arg, char ch) {
  if (PRS_isLexStrCharNormal(arg)) {
    return (PRS_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) PRS_byteToChar(ch))), 0), 1);
  }

  ATabort("LexStrChar has no Ch: %t\n", arg);
  return (PRS_LexStrChar)NULL;
}

/**
 * Assert whether a PRS_StrChar is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_StrChar
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidStrChar(PRS_StrChar arg) {
  if (PRS_isStrCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_StrChar is a Lex-to-cf. Always returns ATtrue
 * \param[in] arg input PRS_StrChar
 * \return ATtrue if #arg corresponds to the signature of a Lex-to-cf, or ATfalse otherwise
 */
inline ATbool PRS_isStrCharLexToCf(PRS_StrChar arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternStrCharLexToCf, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_StrChar has a StrChar. 
 * \param[in] arg input PRS_StrChar
 * \return ATtrue if the PRS_StrChar had a StrChar, or ATfalse otherwise
 */
ATbool PRS_hasStrCharStrChar(PRS_StrChar arg) {
  if (PRS_isStrCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the StrChar PRS_LexStrChar of a PRS_StrChar. Note that the precondition is that this PRS_StrChar actually has a StrChar
 * \param[in] arg input PRS_StrChar
 * \return the StrChar of #arg, if it exist or an undefined value if it does not
 */
PRS_LexStrChar PRS_getStrCharStrChar(PRS_StrChar arg) {
  
    return (PRS_LexStrChar)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Set the StrChar of a PRS_StrChar. The precondition being that this PRS_StrChar actually has a StrChar
 * \param[in] arg input PRS_StrChar
 * \param[in] StrChar new PRS_LexStrChar to set in #arg
 * \return A new PRS_StrChar with StrChar at the right place, or a core dump if #arg did not have a StrChar
 */
PRS_StrChar PRS_setStrCharStrChar(PRS_StrChar arg, PRS_LexStrChar StrChar) {
  if (PRS_isStrCharLexToCf(arg)) {
    return (PRS_StrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrChar), 0), 1);
  }

  ATabort("StrChar has no StrChar: %t\n", arg);
  return (PRS_StrChar)NULL;
}

/**
 * Assert whether a PRS_LexStrCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_LexStrCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidLexStrCon(PRS_LexStrCon arg) {
  if (PRS_isLexStrConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_LexStrCon is a default. Always returns ATtrue
 * \param[in] arg input PRS_LexStrCon
 * \return ATtrue if #arg corresponds to the signature of a default, or ATfalse otherwise
 */
inline ATbool PRS_isLexStrConDefault(PRS_LexStrCon arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternLexStrConDefault, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_LexStrCon has a chars. 
 * \param[in] arg input PRS_LexStrCon
 * \return ATtrue if the PRS_LexStrCon had a chars, or ATfalse otherwise
 */
ATbool PRS_hasLexStrConChars(PRS_LexStrCon arg) {
  if (PRS_isLexStrConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the chars PRS_LexStrCharChars of a PRS_LexStrCon. Note that the precondition is that this PRS_LexStrCon actually has a chars
 * \param[in] arg input PRS_LexStrCon
 * \return the chars of #arg, if it exist or an undefined value if it does not
 */
PRS_LexStrCharChars PRS_getLexStrConChars(PRS_LexStrCon arg) {
  
    return (PRS_LexStrCharChars)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), 1);
}

/**
 * Set the chars of a PRS_LexStrCon. The precondition being that this PRS_LexStrCon actually has a chars
 * \param[in] arg input PRS_LexStrCon
 * \param[in] chars new PRS_LexStrCharChars to set in #arg
 * \return A new PRS_LexStrCon with chars at the right place, or a core dump if #arg did not have a chars
 */
PRS_LexStrCon PRS_setLexStrConChars(PRS_LexStrCon arg, PRS_LexStrCharChars chars) {
  if (PRS_isLexStrConDefault(arg)) {
    return (PRS_LexStrCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), (ATerm)((ATerm) chars), 1), 1), 1);
  }

  ATabort("LexStrCon has no Chars: %t\n", arg);
  return (PRS_LexStrCon)NULL;
}

/**
 * Assert whether a PRS_StrCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_StrCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidStrCon(PRS_StrCon arg) {
  if (PRS_isStrConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_StrCon is a Lex-to-cf. Always returns ATtrue
 * \param[in] arg input PRS_StrCon
 * \return ATtrue if #arg corresponds to the signature of a Lex-to-cf, or ATfalse otherwise
 */
inline ATbool PRS_isStrConLexToCf(PRS_StrCon arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternStrConLexToCf, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_StrCon has a StrCon. 
 * \param[in] arg input PRS_StrCon
 * \return ATtrue if the PRS_StrCon had a StrCon, or ATfalse otherwise
 */
ATbool PRS_hasStrConStrCon(PRS_StrCon arg) {
  if (PRS_isStrConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the StrCon PRS_LexStrCon of a PRS_StrCon. Note that the precondition is that this PRS_StrCon actually has a StrCon
 * \param[in] arg input PRS_StrCon
 * \return the StrCon of #arg, if it exist or an undefined value if it does not
 */
PRS_LexStrCon PRS_getStrConStrCon(PRS_StrCon arg) {
  
    return (PRS_LexStrCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Set the StrCon of a PRS_StrCon. The precondition being that this PRS_StrCon actually has a StrCon
 * \param[in] arg input PRS_StrCon
 * \param[in] StrCon new PRS_LexStrCon to set in #arg
 * \return A new PRS_StrCon with StrCon at the right place, or a core dump if #arg did not have a StrCon
 */
PRS_StrCon PRS_setStrConStrCon(PRS_StrCon arg, PRS_LexStrCon StrCon) {
  if (PRS_isStrConLexToCf(arg)) {
    return (PRS_StrCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrCon), 0), 1);
  }

  ATabort("StrCon has no StrCon: %t\n", arg);
  return (PRS_StrCon)NULL;
}

/**
 * Assert whether a PRS_LexStrCharChars is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_LexStrCharChars
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidLexStrCharChars(PRS_LexStrCharChars arg) {
  if (PRS_isLexStrCharCharsEmpty(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexStrCharCharsSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexStrCharCharsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_LexStrCharChars is a empty. . May not be used to assert correctness of the PRS_LexStrCharChars
 * \param[in] arg input PRS_LexStrCharChars
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool PRS_isLexStrCharCharsEmpty(PRS_LexStrCharChars arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternLexStrCharCharsEmpty));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_LexStrCharChars is a single. . May not be used to assert correctness of the PRS_LexStrCharChars
 * \param[in] arg input PRS_LexStrCharChars
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool PRS_isLexStrCharCharsSingle(PRS_LexStrCharChars arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexStrCharCharsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_LexStrCharChars is a many. . May not be used to assert correctness of the PRS_LexStrCharChars
 * \param[in] arg input PRS_LexStrCharChars
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool PRS_isLexStrCharCharsMany(PRS_LexStrCharChars arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexStrCharCharsMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_LexStrCharChars has a head. 
 * \param[in] arg input PRS_LexStrCharChars
 * \return ATtrue if the PRS_LexStrCharChars had a head, or ATfalse otherwise
 */
ATbool PRS_hasLexStrCharCharsHead(PRS_LexStrCharChars arg) {
  if (PRS_isLexStrCharCharsSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexStrCharCharsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_LexStrCharChars has a tail. 
 * \param[in] arg input PRS_LexStrCharChars
 * \return ATtrue if the PRS_LexStrCharChars had a tail, or ATfalse otherwise
 */
ATbool PRS_hasLexStrCharCharsTail(PRS_LexStrCharChars arg) {
  if (PRS_isLexStrCharCharsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head PRS_LexStrChar of a PRS_LexStrCharChars. Note that the precondition is that this PRS_LexStrCharChars actually has a head
 * \param[in] arg input PRS_LexStrCharChars
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
PRS_LexStrChar PRS_getLexStrCharCharsHead(PRS_LexStrCharChars arg) {
  if (PRS_isLexStrCharCharsSingle(arg)) {
    return (PRS_LexStrChar)ATgetFirst((ATermList)arg);
  }
  else 
    return (PRS_LexStrChar)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail PRS_LexStrCharChars of a PRS_LexStrCharChars. Note that the precondition is that this PRS_LexStrCharChars actually has a tail
 * \param[in] arg input PRS_LexStrCharChars
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
PRS_LexStrCharChars PRS_getLexStrCharCharsTail(PRS_LexStrCharChars arg) {
  
    return (PRS_LexStrCharChars)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a PRS_LexStrCharChars. The precondition being that this PRS_LexStrCharChars actually has a head
 * \param[in] arg input PRS_LexStrCharChars
 * \param[in] head new PRS_LexStrChar to set in #arg
 * \return A new PRS_LexStrCharChars with head at the right place, or a core dump if #arg did not have a head
 */
PRS_LexStrCharChars PRS_setLexStrCharCharsHead(PRS_LexStrCharChars arg, PRS_LexStrChar head) {
  if (PRS_isLexStrCharCharsSingle(arg)) {
    return (PRS_LexStrCharChars)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PRS_isLexStrCharCharsMany(arg)) {
    return (PRS_LexStrCharChars)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("LexStrCharChars has no Head: %t\n", arg);
  return (PRS_LexStrCharChars)NULL;
}

/**
 * Set the tail of a PRS_LexStrCharChars. The precondition being that this PRS_LexStrCharChars actually has a tail
 * \param[in] arg input PRS_LexStrCharChars
 * \param[in] tail new PRS_LexStrCharChars to set in #arg
 * \return A new PRS_LexStrCharChars with tail at the right place, or a core dump if #arg did not have a tail
 */
PRS_LexStrCharChars PRS_setLexStrCharCharsTail(PRS_LexStrCharChars arg, PRS_LexStrCharChars tail) {
  if (PRS_isLexStrCharCharsMany(arg)) {
    return (PRS_LexStrCharChars)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("LexStrCharChars has no Tail: %t\n", arg);
  return (PRS_LexStrCharChars)NULL;
}

/**
 * Assert whether a PRS_LexNatCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_LexNatCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidLexNatCon(PRS_LexNatCon arg) {
  if (PRS_isLexNatConDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_LexNatCon is a digits. Always returns ATtrue
 * \param[in] arg input PRS_LexNatCon
 * \return ATtrue if #arg corresponds to the signature of a digits, or ATfalse otherwise
 */
inline ATbool PRS_isLexNatConDigits(PRS_LexNatCon arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternLexNatConDigits, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_LexNatCon has a list. 
 * \param[in] arg input PRS_LexNatCon
 * \return ATtrue if the PRS_LexNatCon had a list, or ATfalse otherwise
 */
ATbool PRS_hasLexNatConList(PRS_LexNatCon arg) {
  if (PRS_isLexNatConDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the list char* of a PRS_LexNatCon. Note that the precondition is that this PRS_LexNatCon actually has a list
 * \param[in] arg input PRS_LexNatCon
 * \return the list of #arg, if it exist or an undefined value if it does not
 */
char* PRS_getLexNatConList(PRS_LexNatCon arg) {
  
    return (char*)PRS_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/**
 * Set the list of a PRS_LexNatCon. The precondition being that this PRS_LexNatCon actually has a list
 * \param[in] arg input PRS_LexNatCon
 * \param[in] list new const char* to set in #arg
 * \return A new PRS_LexNatCon with list at the right place, or a core dump if #arg did not have a list
 */
PRS_LexNatCon PRS_setLexNatConList(PRS_LexNatCon arg, const char* list) {
  if (PRS_isLexNatConDigits(arg)) {
    return (PRS_LexNatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) PRS_stringToChars(list))), 1), 0), 1);
  }

  ATabort("LexNatCon has no List: %t\n", arg);
  return (PRS_LexNatCon)NULL;
}

/**
 * Assert whether a PRS_NatCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_NatCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidNatCon(PRS_NatCon arg) {
  if (PRS_isNatConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_NatCon is a Lex-to-cf. Always returns ATtrue
 * \param[in] arg input PRS_NatCon
 * \return ATtrue if #arg corresponds to the signature of a Lex-to-cf, or ATfalse otherwise
 */
inline ATbool PRS_isNatConLexToCf(PRS_NatCon arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternNatConLexToCf, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_NatCon has a NatCon. 
 * \param[in] arg input PRS_NatCon
 * \return ATtrue if the PRS_NatCon had a NatCon, or ATfalse otherwise
 */
ATbool PRS_hasNatConNatCon(PRS_NatCon arg) {
  if (PRS_isNatConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the NatCon PRS_LexNatCon of a PRS_NatCon. Note that the precondition is that this PRS_NatCon actually has a NatCon
 * \param[in] arg input PRS_NatCon
 * \return the NatCon of #arg, if it exist or an undefined value if it does not
 */
PRS_LexNatCon PRS_getNatConNatCon(PRS_NatCon arg) {
  
    return (PRS_LexNatCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Set the NatCon of a PRS_NatCon. The precondition being that this PRS_NatCon actually has a NatCon
 * \param[in] arg input PRS_NatCon
 * \param[in] NatCon new PRS_LexNatCon to set in #arg
 * \return A new PRS_NatCon with NatCon at the right place, or a core dump if #arg did not have a NatCon
 */
PRS_NatCon PRS_setNatConNatCon(PRS_NatCon arg, PRS_LexNatCon NatCon) {
  if (PRS_isNatConLexToCf(arg)) {
    return (PRS_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) NatCon), 0), 1);
  }

  ATabort("NatCon has no NatCon: %t\n", arg);
  return (PRS_NatCon)NULL;
}

/**
 * Assert whether a PRS_LexIdCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_LexIdCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidLexIdCon(PRS_LexIdCon arg) {
  if (PRS_isLexIdConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_LexIdCon is a default. Always returns ATtrue
 * \param[in] arg input PRS_LexIdCon
 * \return ATtrue if #arg corresponds to the signature of a default, or ATfalse otherwise
 */
inline ATbool PRS_isLexIdConDefault(PRS_LexIdCon arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternLexIdConDefault, NULL, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_LexIdCon has a head. 
 * \param[in] arg input PRS_LexIdCon
 * \return ATtrue if the PRS_LexIdCon had a head, or ATfalse otherwise
 */
ATbool PRS_hasLexIdConHead(PRS_LexIdCon arg) {
  if (PRS_isLexIdConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_LexIdCon has a tail. 
 * \param[in] arg input PRS_LexIdCon
 * \return ATtrue if the PRS_LexIdCon had a tail, or ATfalse otherwise
 */
ATbool PRS_hasLexIdConTail(PRS_LexIdCon arg) {
  if (PRS_isLexIdConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head char of a PRS_LexIdCon. Note that the precondition is that this PRS_LexIdCon actually has a head
 * \param[in] arg input PRS_LexIdCon
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
char PRS_getLexIdConHead(PRS_LexIdCon arg) {
  
    return (char)PRS_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/**
 * Get the tail char* of a PRS_LexIdCon. Note that the precondition is that this PRS_LexIdCon actually has a tail
 * \param[in] arg input PRS_LexIdCon
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
char* PRS_getLexIdConTail(PRS_LexIdCon arg) {
  
    return (char*)PRS_charsToString((ATerm)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), 1));
}

/**
 * Set the head of a PRS_LexIdCon. The precondition being that this PRS_LexIdCon actually has a head
 * \param[in] arg input PRS_LexIdCon
 * \param[in] head new char to set in #arg
 * \return A new PRS_LexIdCon with head at the right place, or a core dump if #arg did not have a head
 */
PRS_LexIdCon PRS_setLexIdConHead(PRS_LexIdCon arg, char head) {
  if (PRS_isLexIdConDefault(arg)) {
    return (PRS_LexIdCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) PRS_byteToChar(head))), 0), 1);
  }

  ATabort("LexIdCon has no Head: %t\n", arg);
  return (PRS_LexIdCon)NULL;
}

/**
 * Set the tail of a PRS_LexIdCon. The precondition being that this PRS_LexIdCon actually has a tail
 * \param[in] arg input PRS_LexIdCon
 * \param[in] tail new const char* to set in #arg
 * \return A new PRS_LexIdCon with tail at the right place, or a core dump if #arg did not have a tail
 */
PRS_LexIdCon PRS_setLexIdConTail(PRS_LexIdCon arg, const char* tail) {
  if (PRS_isLexIdConDefault(arg)) {
    return (PRS_LexIdCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), (ATerm)((ATerm) ((ATerm) PRS_stringToChars(tail))), 1), 1), 1);
  }

  ATabort("LexIdCon has no Tail: %t\n", arg);
  return (PRS_LexIdCon)NULL;
}

/**
 * Assert whether a PRS_IdCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_IdCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidIdCon(PRS_IdCon arg) {
  if (PRS_isIdConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_IdCon is a Lex-to-cf. Always returns ATtrue
 * \param[in] arg input PRS_IdCon
 * \return ATtrue if #arg corresponds to the signature of a Lex-to-cf, or ATfalse otherwise
 */
inline ATbool PRS_isIdConLexToCf(PRS_IdCon arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternIdConLexToCf, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_IdCon has a IdCon. 
 * \param[in] arg input PRS_IdCon
 * \return ATtrue if the PRS_IdCon had a IdCon, or ATfalse otherwise
 */
ATbool PRS_hasIdConIdCon(PRS_IdCon arg) {
  if (PRS_isIdConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the IdCon PRS_LexIdCon of a PRS_IdCon. Note that the precondition is that this PRS_IdCon actually has a IdCon
 * \param[in] arg input PRS_IdCon
 * \return the IdCon of #arg, if it exist or an undefined value if it does not
 */
PRS_LexIdCon PRS_getIdConIdCon(PRS_IdCon arg) {
  
    return (PRS_LexIdCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Set the IdCon of a PRS_IdCon. The precondition being that this PRS_IdCon actually has a IdCon
 * \param[in] arg input PRS_IdCon
 * \param[in] IdCon new PRS_LexIdCon to set in #arg
 * \return A new PRS_IdCon with IdCon at the right place, or a core dump if #arg did not have a IdCon
 */
PRS_IdCon PRS_setIdConIdCon(PRS_IdCon arg, PRS_LexIdCon IdCon) {
  if (PRS_isIdConLexToCf(arg)) {
    return (PRS_IdCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) IdCon), 0), 1);
  }

  ATabort("IdCon has no IdCon: %t\n", arg);
  return (PRS_IdCon)NULL;
}

/**
 * Assert whether a PRS_LexIntCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_LexIntCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidLexIntCon(PRS_LexIntCon arg) {
  if (PRS_isLexIntConPositive(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexIntConNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_LexIntCon is a positive. . May not be used to assert correctness of the PRS_LexIntCon
 * \param[in] arg input PRS_LexIntCon
 * \return ATtrue if #arg corresponds to the signature of a positive, or ATfalse otherwise
 */
inline ATbool PRS_isLexIntConPositive(PRS_LexIntCon arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexIntConPositive, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_LexIntCon is a negative. . May not be used to assert correctness of the PRS_LexIntCon
 * \param[in] arg input PRS_LexIntCon
 * \return ATtrue if #arg corresponds to the signature of a negative, or ATfalse otherwise
 */
inline ATbool PRS_isLexIntConNegative(PRS_LexIntCon arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexIntConNegative, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_LexIntCon has a digits. 
 * \param[in] arg input PRS_LexIntCon
 * \return ATtrue if the PRS_LexIntCon had a digits, or ATfalse otherwise
 */
ATbool PRS_hasLexIntConDigits(PRS_LexIntCon arg) {
  if (PRS_isLexIntConPositive(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexIntConNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the digits PRS_LexNatCon of a PRS_LexIntCon. Note that the precondition is that this PRS_LexIntCon actually has a digits
 * \param[in] arg input PRS_LexIntCon
 * \return the digits of #arg, if it exist or an undefined value if it does not
 */
PRS_LexNatCon PRS_getLexIntConDigits(PRS_LexIntCon arg) {
  if (PRS_isLexIntConPositive(arg)) {
    return (PRS_LexNatCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (PRS_LexNatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Set the digits of a PRS_LexIntCon. The precondition being that this PRS_LexIntCon actually has a digits
 * \param[in] arg input PRS_LexIntCon
 * \param[in] digits new PRS_LexNatCon to set in #arg
 * \return A new PRS_LexIntCon with digits at the right place, or a core dump if #arg did not have a digits
 */
PRS_LexIntCon PRS_setLexIntConDigits(PRS_LexIntCon arg, PRS_LexNatCon digits) {
  if (PRS_isLexIntConPositive(arg)) {
    return (PRS_LexIntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) digits), 0), 1);
  }
  else if (PRS_isLexIntConNegative(arg)) {
    return (PRS_LexIntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) digits), 1), 1);
  }

  ATabort("LexIntCon has no Digits: %t\n", arg);
  return (PRS_LexIntCon)NULL;
}

/**
 * Assert whether a PRS_IntCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_IntCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidIntCon(PRS_IntCon arg) {
  if (PRS_isIntConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_IntCon is a Lex-to-cf. Always returns ATtrue
 * \param[in] arg input PRS_IntCon
 * \return ATtrue if #arg corresponds to the signature of a Lex-to-cf, or ATfalse otherwise
 */
inline ATbool PRS_isIntConLexToCf(PRS_IntCon arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternIntConLexToCf, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_IntCon has a IntCon. 
 * \param[in] arg input PRS_IntCon
 * \return ATtrue if the PRS_IntCon had a IntCon, or ATfalse otherwise
 */
ATbool PRS_hasIntConIntCon(PRS_IntCon arg) {
  if (PRS_isIntConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the IntCon PRS_LexIntCon of a PRS_IntCon. Note that the precondition is that this PRS_IntCon actually has a IntCon
 * \param[in] arg input PRS_IntCon
 * \return the IntCon of #arg, if it exist or an undefined value if it does not
 */
PRS_LexIntCon PRS_getIntConIntCon(PRS_IntCon arg) {
  
    return (PRS_LexIntCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Set the IntCon of a PRS_IntCon. The precondition being that this PRS_IntCon actually has a IntCon
 * \param[in] arg input PRS_IntCon
 * \param[in] IntCon new PRS_LexIntCon to set in #arg
 * \return A new PRS_IntCon with IntCon at the right place, or a core dump if #arg did not have a IntCon
 */
PRS_IntCon PRS_setIntConIntCon(PRS_IntCon arg, PRS_LexIntCon IntCon) {
  if (PRS_isIntConLexToCf(arg)) {
    return (PRS_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) IntCon), 0), 1);
  }

  ATabort("IntCon has no IntCon: %t\n", arg);
  return (PRS_IntCon)NULL;
}

/**
 * Assert whether a PRS_LexLayout is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_LexLayout
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidLexLayout(PRS_LexLayout arg) {
  if (PRS_isLexLayoutWhitespace(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_LexLayout is a whitespace. Always returns ATtrue
 * \param[in] arg input PRS_LexLayout
 * \return ATtrue if #arg corresponds to the signature of a whitespace, or ATfalse otherwise
 */
inline ATbool PRS_isLexLayoutWhitespace(PRS_LexLayout arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternLexLayoutWhitespace, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_LexLayout has a ch. 
 * \param[in] arg input PRS_LexLayout
 * \return ATtrue if the PRS_LexLayout had a ch, or ATfalse otherwise
 */
ATbool PRS_hasLexLayoutCh(PRS_LexLayout arg) {
  if (PRS_isLexLayoutWhitespace(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ch char of a PRS_LexLayout. Note that the precondition is that this PRS_LexLayout actually has a ch
 * \param[in] arg input PRS_LexLayout
 * \return the ch of #arg, if it exist or an undefined value if it does not
 */
char PRS_getLexLayoutCh(PRS_LexLayout arg) {
  
    return (char)PRS_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/**
 * Set the ch of a PRS_LexLayout. The precondition being that this PRS_LexLayout actually has a ch
 * \param[in] arg input PRS_LexLayout
 * \param[in] ch new char to set in #arg
 * \return A new PRS_LexLayout with ch at the right place, or a core dump if #arg did not have a ch
 */
PRS_LexLayout PRS_setLexLayoutCh(PRS_LexLayout arg, char ch) {
  if (PRS_isLexLayoutWhitespace(arg)) {
    return (PRS_LexLayout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) PRS_byteToChar(ch))), 0), 1);
  }

  ATabort("LexLayout has no Ch: %t\n", arg);
  return (PRS_LexLayout)NULL;
}

/**
 * Assert whether a PRS_Location is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_Location
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidLocation(PRS_Location arg) {
  if (PRS_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (PRS_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Location is a file. . May not be used to assert correctness of the PRS_Location
 * \param[in] arg input PRS_Location
 * \return ATtrue if #arg corresponds to the signature of a file, or ATfalse otherwise
 */
inline ATbool PRS_isLocationFile(PRS_Location arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLocationFile, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_Location is a area. . May not be used to assert correctness of the PRS_Location
 * \param[in] arg input PRS_Location
 * \return ATtrue if #arg corresponds to the signature of a area, or ATfalse otherwise
 */
inline ATbool PRS_isLocationArea(PRS_Location arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLocationArea, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_Location is a area-in-file. . May not be used to assert correctness of the PRS_Location
 * \param[in] arg input PRS_Location
 * \return ATtrue if #arg corresponds to the signature of a area-in-file, or ATfalse otherwise
 */
inline ATbool PRS_isLocationAreaInFile(PRS_Location arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLocationAreaInFile, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a PRS_Location has a ws-after-file. 
 * \param[in] arg input PRS_Location
 * \return ATtrue if the PRS_Location had a ws-after-file, or ATfalse otherwise
 */
ATbool PRS_hasLocationWsAfterFile(PRS_Location arg) {
  if (PRS_isLocationFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Location has a ws-after-(. 
 * \param[in] arg input PRS_Location
 * \return ATtrue if the PRS_Location had a ws-after-(, or ATfalse otherwise
 */
ATbool PRS_hasLocationWsAfterParenOpen(PRS_Location arg) {
  if (PRS_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (PRS_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Location has a filename. 
 * \param[in] arg input PRS_Location
 * \return ATtrue if the PRS_Location had a filename, or ATfalse otherwise
 */
ATbool PRS_hasLocationFilename(PRS_Location arg) {
  if (PRS_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Location has a ws-after-filename. 
 * \param[in] arg input PRS_Location
 * \return ATtrue if the PRS_Location had a ws-after-filename, or ATfalse otherwise
 */
ATbool PRS_hasLocationWsAfterFilename(PRS_Location arg) {
  if (PRS_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Location has a ws-after-a. 
 * \param[in] arg input PRS_Location
 * \return ATtrue if the PRS_Location had a ws-after-a, or ATfalse otherwise
 */
ATbool PRS_hasLocationWsAfterA(PRS_Location arg) {
  if (PRS_isLocationArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Location has a Area. 
 * \param[in] arg input PRS_Location
 * \return ATtrue if the PRS_Location had a Area, or ATfalse otherwise
 */
ATbool PRS_hasLocationArea(PRS_Location arg) {
  if (PRS_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Location has a ws-after-Area. 
 * \param[in] arg input PRS_Location
 * \return ATtrue if the PRS_Location had a ws-after-Area, or ATfalse otherwise
 */
ATbool PRS_hasLocationWsAfterArea(PRS_Location arg) {
  if (PRS_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Location has a ws-after-area-in-file. 
 * \param[in] arg input PRS_Location
 * \return ATtrue if the PRS_Location had a ws-after-area-in-file, or ATfalse otherwise
 */
ATbool PRS_hasLocationWsAfterAreaInFile(PRS_Location arg) {
  if (PRS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Location has a ws-after-,. 
 * \param[in] arg input PRS_Location
 * \return ATtrue if the PRS_Location had a ws-after-,, or ATfalse otherwise
 */
ATbool PRS_hasLocationWsAfterComma(PRS_Location arg) {
  if (PRS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ws-after-file PRS_OptLayout of a PRS_Location. Note that the precondition is that this PRS_Location actually has a ws-after-file
 * \param[in] arg input PRS_Location
 * \return the ws-after-file of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getLocationWsAfterFile(PRS_Location arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-( PRS_OptLayout of a PRS_Location. Note that the precondition is that this PRS_Location actually has a ws-after-(
 * \param[in] arg input PRS_Location
 * \return the ws-after-( of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getLocationWsAfterParenOpen(PRS_Location arg) {
  if (PRS_isLocationFile(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PRS_isLocationArea(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/**
 * Get the filename PRS_StrCon of a PRS_Location. Note that the precondition is that this PRS_Location actually has a filename
 * \param[in] arg input PRS_Location
 * \return the filename of #arg, if it exist or an undefined value if it does not
 */
PRS_StrCon PRS_getLocationFilename(PRS_Location arg) {
  if (PRS_isLocationFile(arg)) {
    return (PRS_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (PRS_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/**
 * Get the ws-after-filename PRS_OptLayout of a PRS_Location. Note that the precondition is that this PRS_Location actually has a ws-after-filename
 * \param[in] arg input PRS_Location
 * \return the ws-after-filename of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getLocationWsAfterFilename(PRS_Location arg) {
  if (PRS_isLocationFile(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/**
 * Get the ws-after-a PRS_OptLayout of a PRS_Location. Note that the precondition is that this PRS_Location actually has a ws-after-a
 * \param[in] arg input PRS_Location
 * \return the ws-after-a of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getLocationWsAfterA(PRS_Location arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the Area PRS_Area of a PRS_Location. Note that the precondition is that this PRS_Location actually has a Area
 * \param[in] arg input PRS_Location
 * \return the Area of #arg, if it exist or an undefined value if it does not
 */
PRS_Area PRS_getLocationArea(PRS_Location arg) {
  if (PRS_isLocationArea(arg)) {
    return (PRS_Area)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (PRS_Area)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/**
 * Get the ws-after-Area PRS_OptLayout of a PRS_Location. Note that the precondition is that this PRS_Location actually has a ws-after-Area
 * \param[in] arg input PRS_Location
 * \return the ws-after-Area of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getLocationWsAfterArea(PRS_Location arg) {
  if (PRS_isLocationArea(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/**
 * Get the ws-after-area-in-file PRS_OptLayout of a PRS_Location. Note that the precondition is that this PRS_Location actually has a ws-after-area-in-file
 * \param[in] arg input PRS_Location
 * \return the ws-after-area-in-file of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getLocationWsAfterAreaInFile(PRS_Location arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-, PRS_OptLayout of a PRS_Location. Note that the precondition is that this PRS_Location actually has a ws-after-,
 * \param[in] arg input PRS_Location
 * \return the ws-after-, of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getLocationWsAfterComma(PRS_Location arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/**
 * Set the ws-after-file of a PRS_Location. The precondition being that this PRS_Location actually has a ws-after-file
 * \param[in] arg input PRS_Location
 * \param[in] wsAfterFile new PRS_OptLayout to set in #arg
 * \return A new PRS_Location with wsAfterFile at the right place, or a core dump if #arg did not have a wsAfterFile
 */
PRS_Location PRS_setLocationWsAfterFile(PRS_Location arg, PRS_OptLayout wsAfterFile) {
  if (PRS_isLocationFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFile), 1), 1);
  }

  ATabort("Location has no WsAfterFile: %t\n", arg);
  return (PRS_Location)NULL;
}

/**
 * Set the ws-after-( of a PRS_Location. The precondition being that this PRS_Location actually has a ws-after-(
 * \param[in] arg input PRS_Location
 * \param[in] wsAfterParenOpen new PRS_OptLayout to set in #arg
 * \return A new PRS_Location with wsAfterParenOpen at the right place, or a core dump if #arg did not have a wsAfterParenOpen
 */
PRS_Location PRS_setLocationWsAfterParenOpen(PRS_Location arg, PRS_OptLayout wsAfterParenOpen) {
  if (PRS_isLocationFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PRS_isLocationArea(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Location has no WsAfterParenOpen: %t\n", arg);
  return (PRS_Location)NULL;
}

/**
 * Set the filename of a PRS_Location. The precondition being that this PRS_Location actually has a filename
 * \param[in] arg input PRS_Location
 * \param[in] filename new PRS_StrCon to set in #arg
 * \return A new PRS_Location with filename at the right place, or a core dump if #arg did not have a filename
 */
PRS_Location PRS_setLocationFilename(PRS_Location arg, PRS_StrCon filename) {
  if (PRS_isLocationFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) filename), 4), 1);
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) filename), 4), 1);
  }

  ATabort("Location has no Filename: %t\n", arg);
  return (PRS_Location)NULL;
}

/**
 * Set the ws-after-filename of a PRS_Location. The precondition being that this PRS_Location actually has a ws-after-filename
 * \param[in] arg input PRS_Location
 * \param[in] wsAfterFilename new PRS_OptLayout to set in #arg
 * \return A new PRS_Location with wsAfterFilename at the right place, or a core dump if #arg did not have a wsAfterFilename
 */
PRS_Location PRS_setLocationWsAfterFilename(PRS_Location arg, PRS_OptLayout wsAfterFilename) {
  if (PRS_isLocationFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFilename), 5), 1);
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFilename), 5), 1);
  }

  ATabort("Location has no WsAfterFilename: %t\n", arg);
  return (PRS_Location)NULL;
}

/**
 * Set the ws-after-a of a PRS_Location. The precondition being that this PRS_Location actually has a ws-after-a
 * \param[in] arg input PRS_Location
 * \param[in] wsAfterA new PRS_OptLayout to set in #arg
 * \return A new PRS_Location with wsAfterA at the right place, or a core dump if #arg did not have a wsAfterA
 */
PRS_Location PRS_setLocationWsAfterA(PRS_Location arg, PRS_OptLayout wsAfterA) {
  if (PRS_isLocationArea(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterA), 1), 1);
  }

  ATabort("Location has no WsAfterA: %t\n", arg);
  return (PRS_Location)NULL;
}

/**
 * Set the Area of a PRS_Location. The precondition being that this PRS_Location actually has a Area
 * \param[in] arg input PRS_Location
 * \param[in] Area new PRS_Area to set in #arg
 * \return A new PRS_Location with Area at the right place, or a core dump if #arg did not have a Area
 */
PRS_Location PRS_setLocationArea(PRS_Location arg, PRS_Area Area) {
  if (PRS_isLocationArea(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Area), 4), 1);
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Area), 8), 1);
  }

  ATabort("Location has no Area: %t\n", arg);
  return (PRS_Location)NULL;
}

/**
 * Set the ws-after-Area of a PRS_Location. The precondition being that this PRS_Location actually has a ws-after-Area
 * \param[in] arg input PRS_Location
 * \param[in] wsAfterArea new PRS_OptLayout to set in #arg
 * \return A new PRS_Location with wsAfterArea at the right place, or a core dump if #arg did not have a wsAfterArea
 */
PRS_Location PRS_setLocationWsAfterArea(PRS_Location arg, PRS_OptLayout wsAfterArea) {
  if (PRS_isLocationArea(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArea), 5), 1);
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArea), 9), 1);
  }

  ATabort("Location has no WsAfterArea: %t\n", arg);
  return (PRS_Location)NULL;
}

/**
 * Set the ws-after-area-in-file of a PRS_Location. The precondition being that this PRS_Location actually has a ws-after-area-in-file
 * \param[in] arg input PRS_Location
 * \param[in] wsAfterAreaInFile new PRS_OptLayout to set in #arg
 * \return A new PRS_Location with wsAfterAreaInFile at the right place, or a core dump if #arg did not have a wsAfterAreaInFile
 */
PRS_Location PRS_setLocationWsAfterAreaInFile(PRS_Location arg, PRS_OptLayout wsAfterAreaInFile) {
  if (PRS_isLocationAreaInFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAreaInFile), 1), 1);
  }

  ATabort("Location has no WsAfterAreaInFile: %t\n", arg);
  return (PRS_Location)NULL;
}

/**
 * Set the ws-after-, of a PRS_Location. The precondition being that this PRS_Location actually has a ws-after-,
 * \param[in] arg input PRS_Location
 * \param[in] wsAfterComma new PRS_OptLayout to set in #arg
 * \return A new PRS_Location with wsAfterComma at the right place, or a core dump if #arg did not have a wsAfterComma
 */
PRS_Location PRS_setLocationWsAfterComma(PRS_Location arg, PRS_OptLayout wsAfterComma) {
  if (PRS_isLocationAreaInFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Location has no WsAfterComma: %t\n", arg);
  return (PRS_Location)NULL;
}

/**
 * Assert whether a PRS_Area is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PRS_Area
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PRS_isValidArea(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area is a area. Always returns ATtrue
 * \param[in] arg input PRS_Area
 * \return ATtrue if #arg corresponds to the signature of a area, or ATfalse otherwise
 */
inline ATbool PRS_isAreaArea(PRS_Area arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternAreaArea, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a PRS_Area has a ws-after-area. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a ws-after-area, or ATfalse otherwise
 */
ATbool PRS_hasAreaWsAfterArea(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area has a ws-after-(. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a ws-after-(, or ATfalse otherwise
 */
ATbool PRS_hasAreaWsAfterParenOpen(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area has a begin-line. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a begin-line, or ATfalse otherwise
 */
ATbool PRS_hasAreaBeginLine(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area has a ws-after-begin-line. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a ws-after-begin-line, or ATfalse otherwise
 */
ATbool PRS_hasAreaWsAfterBeginLine(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area has a ws-after-,. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a ws-after-,, or ATfalse otherwise
 */
ATbool PRS_hasAreaWsAfterComma(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area has a begin-column. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a begin-column, or ATfalse otherwise
 */
ATbool PRS_hasAreaBeginColumn(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area has a ws-after-begin-column. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a ws-after-begin-column, or ATfalse otherwise
 */
ATbool PRS_hasAreaWsAfterBeginColumn(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area has a ws-after-,-1. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a ws-after-,-1, or ATfalse otherwise
 */
ATbool PRS_hasAreaWsAfterComma1(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area has a end-line. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a end-line, or ATfalse otherwise
 */
ATbool PRS_hasAreaEndLine(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area has a ws-after-end-line. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a ws-after-end-line, or ATfalse otherwise
 */
ATbool PRS_hasAreaWsAfterEndLine(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area has a ws-after-,-2. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a ws-after-,-2, or ATfalse otherwise
 */
ATbool PRS_hasAreaWsAfterComma2(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area has a end-column. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a end-column, or ATfalse otherwise
 */
ATbool PRS_hasAreaEndColumn(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area has a ws-after-end-column. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a ws-after-end-column, or ATfalse otherwise
 */
ATbool PRS_hasAreaWsAfterEndColumn(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area has a ws-after-,-3. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a ws-after-,-3, or ATfalse otherwise
 */
ATbool PRS_hasAreaWsAfterComma3(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area has a offset. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a offset, or ATfalse otherwise
 */
ATbool PRS_hasAreaOffset(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area has a ws-after-offset. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a ws-after-offset, or ATfalse otherwise
 */
ATbool PRS_hasAreaWsAfterOffset(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area has a ws-after-,-4. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a ws-after-,-4, or ATfalse otherwise
 */
ATbool PRS_hasAreaWsAfterComma4(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area has a length. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a length, or ATfalse otherwise
 */
ATbool PRS_hasAreaLength(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PRS_Area has a ws-after-length. 
 * \param[in] arg input PRS_Area
 * \return ATtrue if the PRS_Area had a ws-after-length, or ATfalse otherwise
 */
ATbool PRS_hasAreaWsAfterLength(PRS_Area arg) {
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ws-after-area PRS_OptLayout of a PRS_Area. Note that the precondition is that this PRS_Area actually has a ws-after-area
 * \param[in] arg input PRS_Area
 * \return the ws-after-area of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getAreaWsAfterArea(PRS_Area arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-( PRS_OptLayout of a PRS_Area. Note that the precondition is that this PRS_Area actually has a ws-after-(
 * \param[in] arg input PRS_Area
 * \return the ws-after-( of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getAreaWsAfterParenOpen(PRS_Area arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/**
 * Get the begin-line PRS_NatCon of a PRS_Area. Note that the precondition is that this PRS_Area actually has a begin-line
 * \param[in] arg input PRS_Area
 * \return the begin-line of #arg, if it exist or an undefined value if it does not
 */
PRS_NatCon PRS_getAreaBeginLine(PRS_Area arg) {
  
    return (PRS_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/**
 * Get the ws-after-begin-line PRS_OptLayout of a PRS_Area. Note that the precondition is that this PRS_Area actually has a ws-after-begin-line
 * \param[in] arg input PRS_Area
 * \return the ws-after-begin-line of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getAreaWsAfterBeginLine(PRS_Area arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/**
 * Get the ws-after-, PRS_OptLayout of a PRS_Area. Note that the precondition is that this PRS_Area actually has a ws-after-,
 * \param[in] arg input PRS_Area
 * \return the ws-after-, of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getAreaWsAfterComma(PRS_Area arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/**
 * Get the begin-column PRS_NatCon of a PRS_Area. Note that the precondition is that this PRS_Area actually has a begin-column
 * \param[in] arg input PRS_Area
 * \return the begin-column of #arg, if it exist or an undefined value if it does not
 */
PRS_NatCon PRS_getAreaBeginColumn(PRS_Area arg) {
  
    return (PRS_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/**
 * Get the ws-after-begin-column PRS_OptLayout of a PRS_Area. Note that the precondition is that this PRS_Area actually has a ws-after-begin-column
 * \param[in] arg input PRS_Area
 * \return the ws-after-begin-column of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getAreaWsAfterBeginColumn(PRS_Area arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/**
 * Get the ws-after-,-1 PRS_OptLayout of a PRS_Area. Note that the precondition is that this PRS_Area actually has a ws-after-,-1
 * \param[in] arg input PRS_Area
 * \return the ws-after-,-1 of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getAreaWsAfterComma1(PRS_Area arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/**
 * Get the end-line PRS_NatCon of a PRS_Area. Note that the precondition is that this PRS_Area actually has a end-line
 * \param[in] arg input PRS_Area
 * \return the end-line of #arg, if it exist or an undefined value if it does not
 */
PRS_NatCon PRS_getAreaEndLine(PRS_Area arg) {
  
    return (PRS_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/**
 * Get the ws-after-end-line PRS_OptLayout of a PRS_Area. Note that the precondition is that this PRS_Area actually has a ws-after-end-line
 * \param[in] arg input PRS_Area
 * \return the ws-after-end-line of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getAreaWsAfterEndLine(PRS_Area arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/**
 * Get the ws-after-,-2 PRS_OptLayout of a PRS_Area. Note that the precondition is that this PRS_Area actually has a ws-after-,-2
 * \param[in] arg input PRS_Area
 * \return the ws-after-,-2 of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getAreaWsAfterComma2(PRS_Area arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/**
 * Get the end-column PRS_NatCon of a PRS_Area. Note that the precondition is that this PRS_Area actually has a end-column
 * \param[in] arg input PRS_Area
 * \return the end-column of #arg, if it exist or an undefined value if it does not
 */
PRS_NatCon PRS_getAreaEndColumn(PRS_Area arg) {
  
    return (PRS_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
}

/**
 * Get the ws-after-end-column PRS_OptLayout of a PRS_Area. Note that the precondition is that this PRS_Area actually has a ws-after-end-column
 * \param[in] arg input PRS_Area
 * \return the ws-after-end-column of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getAreaWsAfterEndColumn(PRS_Area arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
}

/**
 * Get the ws-after-,-3 PRS_OptLayout of a PRS_Area. Note that the precondition is that this PRS_Area actually has a ws-after-,-3
 * \param[in] arg input PRS_Area
 * \return the ws-after-,-3 of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getAreaWsAfterComma3(PRS_Area arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 19);
}

/**
 * Get the offset PRS_NatCon of a PRS_Area. Note that the precondition is that this PRS_Area actually has a offset
 * \param[in] arg input PRS_Area
 * \return the offset of #arg, if it exist or an undefined value if it does not
 */
PRS_NatCon PRS_getAreaOffset(PRS_Area arg) {
  
    return (PRS_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 20);
}

/**
 * Get the ws-after-offset PRS_OptLayout of a PRS_Area. Note that the precondition is that this PRS_Area actually has a ws-after-offset
 * \param[in] arg input PRS_Area
 * \return the ws-after-offset of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getAreaWsAfterOffset(PRS_Area arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 21);
}

/**
 * Get the ws-after-,-4 PRS_OptLayout of a PRS_Area. Note that the precondition is that this PRS_Area actually has a ws-after-,-4
 * \param[in] arg input PRS_Area
 * \return the ws-after-,-4 of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getAreaWsAfterComma4(PRS_Area arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 23);
}

/**
 * Get the length PRS_NatCon of a PRS_Area. Note that the precondition is that this PRS_Area actually has a length
 * \param[in] arg input PRS_Area
 * \return the length of #arg, if it exist or an undefined value if it does not
 */
PRS_NatCon PRS_getAreaLength(PRS_Area arg) {
  
    return (PRS_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 24);
}

/**
 * Get the ws-after-length PRS_OptLayout of a PRS_Area. Note that the precondition is that this PRS_Area actually has a ws-after-length
 * \param[in] arg input PRS_Area
 * \return the ws-after-length of #arg, if it exist or an undefined value if it does not
 */
PRS_OptLayout PRS_getAreaWsAfterLength(PRS_Area arg) {
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 25);
}

/**
 * Set the ws-after-area of a PRS_Area. The precondition being that this PRS_Area actually has a ws-after-area
 * \param[in] arg input PRS_Area
 * \param[in] wsAfterArea new PRS_OptLayout to set in #arg
 * \return A new PRS_Area with wsAfterArea at the right place, or a core dump if #arg did not have a wsAfterArea
 */
PRS_Area PRS_setAreaWsAfterArea(PRS_Area arg, PRS_OptLayout wsAfterArea) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArea), 1), 1);
  }

  ATabort("Area has no WsAfterArea: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Set the ws-after-( of a PRS_Area. The precondition being that this PRS_Area actually has a ws-after-(
 * \param[in] arg input PRS_Area
 * \param[in] wsAfterParenOpen new PRS_OptLayout to set in #arg
 * \return A new PRS_Area with wsAfterParenOpen at the right place, or a core dump if #arg did not have a wsAfterParenOpen
 */
PRS_Area PRS_setAreaWsAfterParenOpen(PRS_Area arg, PRS_OptLayout wsAfterParenOpen) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Area has no WsAfterParenOpen: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Set the begin-line of a PRS_Area. The precondition being that this PRS_Area actually has a begin-line
 * \param[in] arg input PRS_Area
 * \param[in] beginLine new PRS_NatCon to set in #arg
 * \return A new PRS_Area with beginLine at the right place, or a core dump if #arg did not have a beginLine
 */
PRS_Area PRS_setAreaBeginLine(PRS_Area arg, PRS_NatCon beginLine) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) beginLine), 4), 1);
  }

  ATabort("Area has no BeginLine: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Set the ws-after-begin-line of a PRS_Area. The precondition being that this PRS_Area actually has a ws-after-begin-line
 * \param[in] arg input PRS_Area
 * \param[in] wsAfterBeginLine new PRS_OptLayout to set in #arg
 * \return A new PRS_Area with wsAfterBeginLine at the right place, or a core dump if #arg did not have a wsAfterBeginLine
 */
PRS_Area PRS_setAreaWsAfterBeginLine(PRS_Area arg, PRS_OptLayout wsAfterBeginLine) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBeginLine), 5), 1);
  }

  ATabort("Area has no WsAfterBeginLine: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Set the ws-after-, of a PRS_Area. The precondition being that this PRS_Area actually has a ws-after-,
 * \param[in] arg input PRS_Area
 * \param[in] wsAfterComma new PRS_OptLayout to set in #arg
 * \return A new PRS_Area with wsAfterComma at the right place, or a core dump if #arg did not have a wsAfterComma
 */
PRS_Area PRS_setAreaWsAfterComma(PRS_Area arg, PRS_OptLayout wsAfterComma) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Area has no WsAfterComma: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Set the begin-column of a PRS_Area. The precondition being that this PRS_Area actually has a begin-column
 * \param[in] arg input PRS_Area
 * \param[in] beginColumn new PRS_NatCon to set in #arg
 * \return A new PRS_Area with beginColumn at the right place, or a core dump if #arg did not have a beginColumn
 */
PRS_Area PRS_setAreaBeginColumn(PRS_Area arg, PRS_NatCon beginColumn) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) beginColumn), 8), 1);
  }

  ATabort("Area has no BeginColumn: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Set the ws-after-begin-column of a PRS_Area. The precondition being that this PRS_Area actually has a ws-after-begin-column
 * \param[in] arg input PRS_Area
 * \param[in] wsAfterBeginColumn new PRS_OptLayout to set in #arg
 * \return A new PRS_Area with wsAfterBeginColumn at the right place, or a core dump if #arg did not have a wsAfterBeginColumn
 */
PRS_Area PRS_setAreaWsAfterBeginColumn(PRS_Area arg, PRS_OptLayout wsAfterBeginColumn) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBeginColumn), 9), 1);
  }

  ATabort("Area has no WsAfterBeginColumn: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Set the ws-after-,-1 of a PRS_Area. The precondition being that this PRS_Area actually has a ws-after-,-1
 * \param[in] arg input PRS_Area
 * \param[in] wsAfterComma1 new PRS_OptLayout to set in #arg
 * \return A new PRS_Area with wsAfterComma1 at the right place, or a core dump if #arg did not have a wsAfterComma1
 */
PRS_Area PRS_setAreaWsAfterComma1(PRS_Area arg, PRS_OptLayout wsAfterComma1) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }

  ATabort("Area has no WsAfterComma1: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Set the end-line of a PRS_Area. The precondition being that this PRS_Area actually has a end-line
 * \param[in] arg input PRS_Area
 * \param[in] endLine new PRS_NatCon to set in #arg
 * \return A new PRS_Area with endLine at the right place, or a core dump if #arg did not have a endLine
 */
PRS_Area PRS_setAreaEndLine(PRS_Area arg, PRS_NatCon endLine) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) endLine), 12), 1);
  }

  ATabort("Area has no EndLine: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Set the ws-after-end-line of a PRS_Area. The precondition being that this PRS_Area actually has a ws-after-end-line
 * \param[in] arg input PRS_Area
 * \param[in] wsAfterEndLine new PRS_OptLayout to set in #arg
 * \return A new PRS_Area with wsAfterEndLine at the right place, or a core dump if #arg did not have a wsAfterEndLine
 */
PRS_Area PRS_setAreaWsAfterEndLine(PRS_Area arg, PRS_OptLayout wsAfterEndLine) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEndLine), 13), 1);
  }

  ATabort("Area has no WsAfterEndLine: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Set the ws-after-,-2 of a PRS_Area. The precondition being that this PRS_Area actually has a ws-after-,-2
 * \param[in] arg input PRS_Area
 * \param[in] wsAfterComma2 new PRS_OptLayout to set in #arg
 * \return A new PRS_Area with wsAfterComma2 at the right place, or a core dump if #arg did not have a wsAfterComma2
 */
PRS_Area PRS_setAreaWsAfterComma2(PRS_Area arg, PRS_OptLayout wsAfterComma2) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma2), 15), 1);
  }

  ATabort("Area has no WsAfterComma2: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Set the end-column of a PRS_Area. The precondition being that this PRS_Area actually has a end-column
 * \param[in] arg input PRS_Area
 * \param[in] endColumn new PRS_NatCon to set in #arg
 * \return A new PRS_Area with endColumn at the right place, or a core dump if #arg did not have a endColumn
 */
PRS_Area PRS_setAreaEndColumn(PRS_Area arg, PRS_NatCon endColumn) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) endColumn), 16), 1);
  }

  ATabort("Area has no EndColumn: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Set the ws-after-end-column of a PRS_Area. The precondition being that this PRS_Area actually has a ws-after-end-column
 * \param[in] arg input PRS_Area
 * \param[in] wsAfterEndColumn new PRS_OptLayout to set in #arg
 * \return A new PRS_Area with wsAfterEndColumn at the right place, or a core dump if #arg did not have a wsAfterEndColumn
 */
PRS_Area PRS_setAreaWsAfterEndColumn(PRS_Area arg, PRS_OptLayout wsAfterEndColumn) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEndColumn), 17), 1);
  }

  ATabort("Area has no WsAfterEndColumn: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Set the ws-after-,-3 of a PRS_Area. The precondition being that this PRS_Area actually has a ws-after-,-3
 * \param[in] arg input PRS_Area
 * \param[in] wsAfterComma3 new PRS_OptLayout to set in #arg
 * \return A new PRS_Area with wsAfterComma3 at the right place, or a core dump if #arg did not have a wsAfterComma3
 */
PRS_Area PRS_setAreaWsAfterComma3(PRS_Area arg, PRS_OptLayout wsAfterComma3) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma3), 19), 1);
  }

  ATabort("Area has no WsAfterComma3: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Set the offset of a PRS_Area. The precondition being that this PRS_Area actually has a offset
 * \param[in] arg input PRS_Area
 * \param[in] offset new PRS_NatCon to set in #arg
 * \return A new PRS_Area with offset at the right place, or a core dump if #arg did not have a offset
 */
PRS_Area PRS_setAreaOffset(PRS_Area arg, PRS_NatCon offset) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) offset), 20), 1);
  }

  ATabort("Area has no Offset: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Set the ws-after-offset of a PRS_Area. The precondition being that this PRS_Area actually has a ws-after-offset
 * \param[in] arg input PRS_Area
 * \param[in] wsAfterOffset new PRS_OptLayout to set in #arg
 * \return A new PRS_Area with wsAfterOffset at the right place, or a core dump if #arg did not have a wsAfterOffset
 */
PRS_Area PRS_setAreaWsAfterOffset(PRS_Area arg, PRS_OptLayout wsAfterOffset) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterOffset), 21), 1);
  }

  ATabort("Area has no WsAfterOffset: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Set the ws-after-,-4 of a PRS_Area. The precondition being that this PRS_Area actually has a ws-after-,-4
 * \param[in] arg input PRS_Area
 * \param[in] wsAfterComma4 new PRS_OptLayout to set in #arg
 * \return A new PRS_Area with wsAfterComma4 at the right place, or a core dump if #arg did not have a wsAfterComma4
 */
PRS_Area PRS_setAreaWsAfterComma4(PRS_Area arg, PRS_OptLayout wsAfterComma4) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma4), 23), 1);
  }

  ATabort("Area has no WsAfterComma4: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Set the length of a PRS_Area. The precondition being that this PRS_Area actually has a length
 * \param[in] arg input PRS_Area
 * \param[in] length new PRS_NatCon to set in #arg
 * \return A new PRS_Area with length at the right place, or a core dump if #arg did not have a length
 */
PRS_Area PRS_setAreaLength(PRS_Area arg, PRS_NatCon length) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) length), 24), 1);
  }

  ATabort("Area has no Length: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Set the ws-after-length of a PRS_Area. The precondition being that this PRS_Area actually has a ws-after-length
 * \param[in] arg input PRS_Area
 * \param[in] wsAfterLength new PRS_OptLayout to set in #arg
 * \return A new PRS_Area with wsAfterLength at the right place, or a core dump if #arg did not have a wsAfterLength
 */
PRS_Area PRS_setAreaWsAfterLength(PRS_Area arg, PRS_OptLayout wsAfterLength) {
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLength), 25), 1);
  }

  ATabort("Area has no WsAfterLength: %t\n", arg);
  return (PRS_Area)NULL;
}

/**
 * Apply functions to the children of a PRS_OptLayout. 
 * \return A new PRS_OptLayout with new children where the argument functions might have applied
 */
PRS_OptLayout PRS_visitOptLayout(PRS_OptLayout arg, PRS_Layout (*acceptLayout)(PRS_Layout)) {
  if (PRS_isOptLayoutAbsent(arg)) {
    return PRS_makeOptLayoutAbsent();
  }
  if (PRS_isOptLayoutPresent(arg)) {
    return PRS_makeOptLayoutPresent(
        acceptLayout ? acceptLayout(PRS_getOptLayoutLayout(arg)) : PRS_getOptLayoutLayout(arg));
  }
  ATabort("not a OptLayout: %t\n", arg);
  return (PRS_OptLayout)NULL;
}
/**
 * Apply functions to the children of a PRS_Layout. 
 * \return A new PRS_Layout with new children where the argument functions might have applied
 */
PRS_Layout PRS_visitLayout(PRS_Layout arg, PRS_LexLayoutList (*acceptList)(PRS_LexLayoutList)) {
  if (PRS_isLayoutLexToCf(arg)) {
    return PRS_makeLayoutLexToCf(
        acceptList ? acceptList(PRS_getLayoutList(arg)) : PRS_getLayoutList(arg));
  }
  ATabort("not a Layout: %t\n", arg);
  return (PRS_Layout)NULL;
}
/**
 * Apply functions to the children of a PRS_LexLayoutList. 
 * \return A new PRS_LexLayoutList with new children where the argument functions might have applied
 */
PRS_LexLayoutList PRS_visitLexLayoutList(PRS_LexLayoutList arg, PRS_LexLayout (*acceptHead)(PRS_LexLayout)) {
  if (PRS_isLexLayoutListEmpty(arg)) {
    return PRS_makeLexLayoutListEmpty();
  }
  if (PRS_isLexLayoutListSingle(arg)) {
    return PRS_makeLexLayoutListSingle(
        acceptHead ? acceptHead(PRS_getLexLayoutListHead(arg)) : PRS_getLexLayoutListHead(arg));
  }
  if (PRS_isLexLayoutListMany(arg)) {
    return PRS_makeLexLayoutListMany(
        acceptHead ? acceptHead(PRS_getLexLayoutListHead(arg)) : PRS_getLexLayoutListHead(arg),
        PRS_visitLexLayoutList(PRS_getLexLayoutListTail(arg), acceptHead));
  }
  ATabort("not a LexLayoutList: %t\n", arg);
  return (PRS_LexLayoutList)NULL;
}
/**
 * Apply functions to the children of a PRS_RElem. 
 * \return A new PRS_RElem with new children where the argument functions might have applied
 */
PRS_RElem PRS_visitRElem(PRS_RElem arg, PRS_IntCon (*acceptIntCon)(PRS_IntCon), PRS_StrCon (*acceptStrCon)(PRS_StrCon), PRS_Location (*acceptLocation)(PRS_Location), PRS_OptLayout (*acceptWsAfterBraceOpen)(PRS_OptLayout), PRS_RElemElements (*acceptElements)(PRS_RElemElements), PRS_OptLayout (*acceptWsAfterElements)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBraceOpenBar)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterLessThan)(PRS_OptLayout)) {
  if (PRS_isRElemInteger(arg)) {
    return PRS_makeRElemInteger(
        acceptIntCon ? acceptIntCon(PRS_getRElemIntCon(arg)) : PRS_getRElemIntCon(arg));
  }
  if (PRS_isRElemString(arg)) {
    return PRS_makeRElemString(
        acceptStrCon ? acceptStrCon(PRS_getRElemStrCon(arg)) : PRS_getRElemStrCon(arg));
  }
  if (PRS_isRElemLocation(arg)) {
    return PRS_makeRElemLocation(
        acceptLocation ? acceptLocation(PRS_getRElemLocation(arg)) : PRS_getRElemLocation(arg));
  }
  if (PRS_isRElemSet(arg)) {
    return PRS_makeRElemSet(
        acceptWsAfterBraceOpen ? acceptWsAfterBraceOpen(PRS_getRElemWsAfterBraceOpen(arg)) : PRS_getRElemWsAfterBraceOpen(arg),
        acceptElements ? acceptElements(PRS_getRElemElements(arg)) : PRS_getRElemElements(arg),
        acceptWsAfterElements ? acceptWsAfterElements(PRS_getRElemWsAfterElements(arg)) : PRS_getRElemWsAfterElements(arg));
  }
  if (PRS_isRElemBag(arg)) {
    return PRS_makeRElemBag(
        acceptWsAfterBraceOpenBar ? acceptWsAfterBraceOpenBar(PRS_getRElemWsAfterBraceOpenBar(arg)) : PRS_getRElemWsAfterBraceOpenBar(arg),
        acceptElements ? acceptElements(PRS_getRElemElements(arg)) : PRS_getRElemElements(arg),
        acceptWsAfterElements ? acceptWsAfterElements(PRS_getRElemWsAfterElements(arg)) : PRS_getRElemWsAfterElements(arg));
  }
  if (PRS_isRElemTuple(arg)) {
    return PRS_makeRElemTuple(
        acceptWsAfterLessThan ? acceptWsAfterLessThan(PRS_getRElemWsAfterLessThan(arg)) : PRS_getRElemWsAfterLessThan(arg),
        acceptElements ? acceptElements(PRS_getRElemElements(arg)) : PRS_getRElemElements(arg),
        acceptWsAfterElements ? acceptWsAfterElements(PRS_getRElemWsAfterElements(arg)) : PRS_getRElemWsAfterElements(arg));
  }
  ATabort("not a RElem: %t\n", arg);
  return (PRS_RElem)NULL;
}
/**
 * Apply functions to the children of a PRS_RType. 
 * \return A new PRS_RType with new children where the argument functions might have applied
 */
PRS_RType PRS_visitRType(PRS_RType arg, PRS_OptLayout (*acceptWsAfterLessThan)(PRS_OptLayout), PRS_RTypeColumnTypes (*acceptColumnTypes)(PRS_RTypeColumnTypes), PRS_OptLayout (*acceptWsAfterColumnTypes)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterSet)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBracketOpen)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterElementType)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBag)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterRel)(PRS_OptLayout), PRS_IdCon (*acceptName)(PRS_IdCon), PRS_OptLayout (*acceptWsAfterAmp)(PRS_OptLayout)) {
  if (PRS_isRTypeInteger(arg)) {
    return PRS_makeRTypeInteger();
  }
  if (PRS_isRTypeBoolean(arg)) {
    return PRS_makeRTypeBoolean();
  }
  if (PRS_isRTypeString(arg)) {
    return PRS_makeRTypeString();
  }
  if (PRS_isRTypeLocation(arg)) {
    return PRS_makeRTypeLocation();
  }
  if (PRS_isRTypeTuple(arg)) {
    return PRS_makeRTypeTuple(
        acceptWsAfterLessThan ? acceptWsAfterLessThan(PRS_getRTypeWsAfterLessThan(arg)) : PRS_getRTypeWsAfterLessThan(arg),
        acceptColumnTypes ? acceptColumnTypes(PRS_getRTypeColumnTypes(arg)) : PRS_getRTypeColumnTypes(arg),
        acceptWsAfterColumnTypes ? acceptWsAfterColumnTypes(PRS_getRTypeWsAfterColumnTypes(arg)) : PRS_getRTypeWsAfterColumnTypes(arg));
  }
  if (PRS_isRTypeSet(arg)) {
    return PRS_makeRTypeSet(
        acceptWsAfterSet ? acceptWsAfterSet(PRS_getRTypeWsAfterSet(arg)) : PRS_getRTypeWsAfterSet(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PRS_getRTypeWsAfterBracketOpen(arg)) : PRS_getRTypeWsAfterBracketOpen(arg),
        PRS_visitRType(PRS_getRTypeElementType(arg), acceptWsAfterLessThan, acceptColumnTypes, acceptWsAfterColumnTypes, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterElementType, acceptWsAfterBag, acceptWsAfterRel, acceptName, acceptWsAfterAmp),
        acceptWsAfterElementType ? acceptWsAfterElementType(PRS_getRTypeWsAfterElementType(arg)) : PRS_getRTypeWsAfterElementType(arg));
  }
  if (PRS_isRTypeBag(arg)) {
    return PRS_makeRTypeBag(
        acceptWsAfterBag ? acceptWsAfterBag(PRS_getRTypeWsAfterBag(arg)) : PRS_getRTypeWsAfterBag(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PRS_getRTypeWsAfterBracketOpen(arg)) : PRS_getRTypeWsAfterBracketOpen(arg),
        PRS_visitRType(PRS_getRTypeElementType(arg), acceptWsAfterLessThan, acceptColumnTypes, acceptWsAfterColumnTypes, acceptWsAfterSet, acceptWsAfterBracketOpen, acceptWsAfterElementType, acceptWsAfterBag, acceptWsAfterRel, acceptName, acceptWsAfterAmp),
        acceptWsAfterElementType ? acceptWsAfterElementType(PRS_getRTypeWsAfterElementType(arg)) : PRS_getRTypeWsAfterElementType(arg));
  }
  if (PRS_isRTypeRelation(arg)) {
    return PRS_makeRTypeRelation(
        acceptWsAfterRel ? acceptWsAfterRel(PRS_getRTypeWsAfterRel(arg)) : PRS_getRTypeWsAfterRel(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PRS_getRTypeWsAfterBracketOpen(arg)) : PRS_getRTypeWsAfterBracketOpen(arg),
        acceptColumnTypes ? acceptColumnTypes(PRS_getRTypeColumnTypes(arg)) : PRS_getRTypeColumnTypes(arg),
        acceptWsAfterColumnTypes ? acceptWsAfterColumnTypes(PRS_getRTypeWsAfterColumnTypes(arg)) : PRS_getRTypeWsAfterColumnTypes(arg));
  }
  if (PRS_isRTypeUserDefined(arg)) {
    return PRS_makeRTypeUserDefined(
        acceptName ? acceptName(PRS_getRTypeName(arg)) : PRS_getRTypeName(arg));
  }
  if (PRS_isRTypeParameter(arg)) {
    return PRS_makeRTypeParameter(
        acceptWsAfterAmp ? acceptWsAfterAmp(PRS_getRTypeWsAfterAmp(arg)) : PRS_getRTypeWsAfterAmp(arg),
        acceptName ? acceptName(PRS_getRTypeName(arg)) : PRS_getRTypeName(arg));
  }
  ATabort("not a RType: %t\n", arg);
  return (PRS_RType)NULL;
}
/**
 * Apply functions to the children of a PRS_RTuple. 
 * \return A new PRS_RTuple with new children where the argument functions might have applied
 */
PRS_RTuple PRS_visitRTuple(PRS_RTuple arg, PRS_OptLayout (*acceptWsAfterLessThan)(PRS_OptLayout), PRS_IdCon (*acceptVariable)(PRS_IdCon), PRS_OptLayout (*acceptWsAfterVariable)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma)(PRS_OptLayout), PRS_RType (*acceptType)(PRS_RType), PRS_OptLayout (*acceptWsAfterType)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma1)(PRS_OptLayout), PRS_RElem (*acceptValue)(PRS_RElem), PRS_OptLayout (*acceptWsAfterValue)(PRS_OptLayout)) {
  if (PRS_isRTupleRtuple(arg)) {
    return PRS_makeRTupleRtuple(
        acceptWsAfterLessThan ? acceptWsAfterLessThan(PRS_getRTupleWsAfterLessThan(arg)) : PRS_getRTupleWsAfterLessThan(arg),
        acceptVariable ? acceptVariable(PRS_getRTupleVariable(arg)) : PRS_getRTupleVariable(arg),
        acceptWsAfterVariable ? acceptWsAfterVariable(PRS_getRTupleWsAfterVariable(arg)) : PRS_getRTupleWsAfterVariable(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PRS_getRTupleWsAfterComma(arg)) : PRS_getRTupleWsAfterComma(arg),
        acceptType ? acceptType(PRS_getRTupleType(arg)) : PRS_getRTupleType(arg),
        acceptWsAfterType ? acceptWsAfterType(PRS_getRTupleWsAfterType(arg)) : PRS_getRTupleWsAfterType(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(PRS_getRTupleWsAfterComma1(arg)) : PRS_getRTupleWsAfterComma1(arg),
        acceptValue ? acceptValue(PRS_getRTupleValue(arg)) : PRS_getRTupleValue(arg),
        acceptWsAfterValue ? acceptWsAfterValue(PRS_getRTupleWsAfterValue(arg)) : PRS_getRTupleWsAfterValue(arg));
  }
  ATabort("not a RTuple: %t\n", arg);
  return (PRS_RTuple)NULL;
}
/**
 * Apply functions to the children of a PRS_RStore. 
 * \return A new PRS_RStore with new children where the argument functions might have applied
 */
PRS_RStore PRS_visitRStore(PRS_RStore arg, PRS_OptLayout (*acceptWsAfterRstore)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterParenOpen)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBracketOpen)(PRS_OptLayout), PRS_RTupleRtuples (*acceptRtuples)(PRS_RTupleRtuples), PRS_OptLayout (*acceptWsAfterRtuples)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBracketClose)(PRS_OptLayout)) {
  if (PRS_isRStoreRstore(arg)) {
    return PRS_makeRStoreRstore(
        acceptWsAfterRstore ? acceptWsAfterRstore(PRS_getRStoreWsAfterRstore(arg)) : PRS_getRStoreWsAfterRstore(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getRStoreWsAfterParenOpen(arg)) : PRS_getRStoreWsAfterParenOpen(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PRS_getRStoreWsAfterBracketOpen(arg)) : PRS_getRStoreWsAfterBracketOpen(arg),
        acceptRtuples ? acceptRtuples(PRS_getRStoreRtuples(arg)) : PRS_getRStoreRtuples(arg),
        acceptWsAfterRtuples ? acceptWsAfterRtuples(PRS_getRStoreWsAfterRtuples(arg)) : PRS_getRStoreWsAfterRtuples(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(PRS_getRStoreWsAfterBracketClose(arg)) : PRS_getRStoreWsAfterBracketClose(arg));
  }
  ATabort("not a RStore: %t\n", arg);
  return (PRS_RStore)NULL;
}
/**
 * Apply functions to the children of a PRS_Start. 
 * \return A new PRS_Start with new children where the argument functions might have applied
 */
PRS_Start PRS_visitStart(PRS_Start arg, PRS_OptLayout (*acceptWsBefore)(PRS_OptLayout), PRS_RStore (*acceptTopRStore)(PRS_RStore), PRS_OptLayout (*acceptWsAfter)(PRS_OptLayout), int (*acceptAmbCnt)(int)) {
  if (PRS_isStartRStore(arg)) {
    return PRS_makeStartRStore(
        acceptWsBefore ? acceptWsBefore(PRS_getStartWsBefore(arg)) : PRS_getStartWsBefore(arg),
        acceptTopRStore ? acceptTopRStore(PRS_getStartTopRStore(arg)) : PRS_getStartTopRStore(arg),
        acceptWsAfter ? acceptWsAfter(PRS_getStartWsAfter(arg)) : PRS_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PRS_getStartAmbCnt(arg)) : PRS_getStartAmbCnt(arg));
  }
  ATabort("not a Start: %t\n", arg);
  return (PRS_Start)NULL;
}
/**
 * Apply functions to the children of a PRS_RElemElements. 
 * \return A new PRS_RElemElements with new children where the argument functions might have applied
 */
PRS_RElemElements PRS_visitRElemElements(PRS_RElemElements arg, PRS_RElem (*acceptHead)(PRS_RElem), PRS_OptLayout (*acceptWsAfterHead)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterSep)(PRS_OptLayout)) {
  if (PRS_isRElemElementsEmpty(arg)) {
    return PRS_makeRElemElementsEmpty();
  }
  if (PRS_isRElemElementsSingle(arg)) {
    return PRS_makeRElemElementsSingle(
        acceptHead ? acceptHead(PRS_getRElemElementsHead(arg)) : PRS_getRElemElementsHead(arg));
  }
  if (PRS_isRElemElementsMany(arg)) {
    return PRS_makeRElemElementsMany(
        acceptHead ? acceptHead(PRS_getRElemElementsHead(arg)) : PRS_getRElemElementsHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(PRS_getRElemElementsWsAfterHead(arg)) : PRS_getRElemElementsWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(PRS_getRElemElementsWsAfterSep(arg)) : PRS_getRElemElementsWsAfterSep(arg),
        PRS_visitRElemElements(PRS_getRElemElementsTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a RElemElements: %t\n", arg);
  return (PRS_RElemElements)NULL;
}
/**
 * Apply functions to the children of a PRS_RTypeColumnTypes. 
 * \return A new PRS_RTypeColumnTypes with new children where the argument functions might have applied
 */
PRS_RTypeColumnTypes PRS_visitRTypeColumnTypes(PRS_RTypeColumnTypes arg, PRS_RType (*acceptHead)(PRS_RType), PRS_OptLayout (*acceptWsAfterHead)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterSep)(PRS_OptLayout)) {
  if (PRS_isRTypeColumnTypesEmpty(arg)) {
    return PRS_makeRTypeColumnTypesEmpty();
  }
  if (PRS_isRTypeColumnTypesSingle(arg)) {
    return PRS_makeRTypeColumnTypesSingle(
        acceptHead ? acceptHead(PRS_getRTypeColumnTypesHead(arg)) : PRS_getRTypeColumnTypesHead(arg));
  }
  if (PRS_isRTypeColumnTypesMany(arg)) {
    return PRS_makeRTypeColumnTypesMany(
        acceptHead ? acceptHead(PRS_getRTypeColumnTypesHead(arg)) : PRS_getRTypeColumnTypesHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(PRS_getRTypeColumnTypesWsAfterHead(arg)) : PRS_getRTypeColumnTypesWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(PRS_getRTypeColumnTypesWsAfterSep(arg)) : PRS_getRTypeColumnTypesWsAfterSep(arg),
        PRS_visitRTypeColumnTypes(PRS_getRTypeColumnTypesTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a RTypeColumnTypes: %t\n", arg);
  return (PRS_RTypeColumnTypes)NULL;
}
/**
 * Apply functions to the children of a PRS_RTupleRtuples. 
 * \return A new PRS_RTupleRtuples with new children where the argument functions might have applied
 */
PRS_RTupleRtuples PRS_visitRTupleRtuples(PRS_RTupleRtuples arg, PRS_RTuple (*acceptHead)(PRS_RTuple), PRS_OptLayout (*acceptWsAfterHead)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterSep)(PRS_OptLayout)) {
  if (PRS_isRTupleRtuplesEmpty(arg)) {
    return PRS_makeRTupleRtuplesEmpty();
  }
  if (PRS_isRTupleRtuplesSingle(arg)) {
    return PRS_makeRTupleRtuplesSingle(
        acceptHead ? acceptHead(PRS_getRTupleRtuplesHead(arg)) : PRS_getRTupleRtuplesHead(arg));
  }
  if (PRS_isRTupleRtuplesMany(arg)) {
    return PRS_makeRTupleRtuplesMany(
        acceptHead ? acceptHead(PRS_getRTupleRtuplesHead(arg)) : PRS_getRTupleRtuplesHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(PRS_getRTupleRtuplesWsAfterHead(arg)) : PRS_getRTupleRtuplesWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(PRS_getRTupleRtuplesWsAfterSep(arg)) : PRS_getRTupleRtuplesWsAfterSep(arg),
        PRS_visitRTupleRtuples(PRS_getRTupleRtuplesTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a RTupleRtuples: %t\n", arg);
  return (PRS_RTupleRtuples)NULL;
}
/**
 * Apply functions to the children of a PRS_LexStrChar. 
 * \return A new PRS_LexStrChar with new children where the argument functions might have applied
 */
PRS_LexStrChar PRS_visitLexStrChar(PRS_LexStrChar arg, char (*acceptA)(char), char (*acceptB)(char), char (*acceptC)(char), char (*acceptCh)(char)) {
  if (PRS_isLexStrCharNewline(arg)) {
    return PRS_makeLexStrCharNewline();
  }
  if (PRS_isLexStrCharTab(arg)) {
    return PRS_makeLexStrCharTab();
  }
  if (PRS_isLexStrCharQuote(arg)) {
    return PRS_makeLexStrCharQuote();
  }
  if (PRS_isLexStrCharBackslash(arg)) {
    return PRS_makeLexStrCharBackslash();
  }
  if (PRS_isLexStrCharDecimal(arg)) {
    return PRS_makeLexStrCharDecimal(
        acceptA ? acceptA(PRS_getLexStrCharA(arg)) : PRS_getLexStrCharA(arg),
        acceptB ? acceptB(PRS_getLexStrCharB(arg)) : PRS_getLexStrCharB(arg),
        acceptC ? acceptC(PRS_getLexStrCharC(arg)) : PRS_getLexStrCharC(arg));
  }
  if (PRS_isLexStrCharNormal(arg)) {
    return PRS_makeLexStrCharNormal(
        acceptCh ? acceptCh(PRS_getLexStrCharCh(arg)) : PRS_getLexStrCharCh(arg));
  }
  ATabort("not a LexStrChar: %t\n", arg);
  return (PRS_LexStrChar)NULL;
}
/**
 * Apply functions to the children of a PRS_StrChar. 
 * \return A new PRS_StrChar with new children where the argument functions might have applied
 */
PRS_StrChar PRS_visitStrChar(PRS_StrChar arg, PRS_LexStrChar (*acceptStrChar)(PRS_LexStrChar)) {
  if (PRS_isStrCharLexToCf(arg)) {
    return PRS_makeStrCharLexToCf(
        acceptStrChar ? acceptStrChar(PRS_getStrCharStrChar(arg)) : PRS_getStrCharStrChar(arg));
  }
  ATabort("not a StrChar: %t\n", arg);
  return (PRS_StrChar)NULL;
}
/**
 * Apply functions to the children of a PRS_LexStrCon. 
 * \return A new PRS_LexStrCon with new children where the argument functions might have applied
 */
PRS_LexStrCon PRS_visitLexStrCon(PRS_LexStrCon arg, PRS_LexStrCharChars (*acceptChars)(PRS_LexStrCharChars)) {
  if (PRS_isLexStrConDefault(arg)) {
    return PRS_makeLexStrConDefault(
        acceptChars ? acceptChars(PRS_getLexStrConChars(arg)) : PRS_getLexStrConChars(arg));
  }
  ATabort("not a LexStrCon: %t\n", arg);
  return (PRS_LexStrCon)NULL;
}
/**
 * Apply functions to the children of a PRS_StrCon. 
 * \return A new PRS_StrCon with new children where the argument functions might have applied
 */
PRS_StrCon PRS_visitStrCon(PRS_StrCon arg, PRS_LexStrCon (*acceptStrCon)(PRS_LexStrCon)) {
  if (PRS_isStrConLexToCf(arg)) {
    return PRS_makeStrConLexToCf(
        acceptStrCon ? acceptStrCon(PRS_getStrConStrCon(arg)) : PRS_getStrConStrCon(arg));
  }
  ATabort("not a StrCon: %t\n", arg);
  return (PRS_StrCon)NULL;
}
/**
 * Apply functions to the children of a PRS_LexStrCharChars. 
 * \return A new PRS_LexStrCharChars with new children where the argument functions might have applied
 */
PRS_LexStrCharChars PRS_visitLexStrCharChars(PRS_LexStrCharChars arg, PRS_LexStrChar (*acceptHead)(PRS_LexStrChar)) {
  if (PRS_isLexStrCharCharsEmpty(arg)) {
    return PRS_makeLexStrCharCharsEmpty();
  }
  if (PRS_isLexStrCharCharsSingle(arg)) {
    return PRS_makeLexStrCharCharsSingle(
        acceptHead ? acceptHead(PRS_getLexStrCharCharsHead(arg)) : PRS_getLexStrCharCharsHead(arg));
  }
  if (PRS_isLexStrCharCharsMany(arg)) {
    return PRS_makeLexStrCharCharsMany(
        acceptHead ? acceptHead(PRS_getLexStrCharCharsHead(arg)) : PRS_getLexStrCharCharsHead(arg),
        PRS_visitLexStrCharChars(PRS_getLexStrCharCharsTail(arg), acceptHead));
  }
  ATabort("not a LexStrCharChars: %t\n", arg);
  return (PRS_LexStrCharChars)NULL;
}
/**
 * Apply functions to the children of a PRS_LexNatCon. 
 * \return A new PRS_LexNatCon with new children where the argument functions might have applied
 */
PRS_LexNatCon PRS_visitLexNatCon(PRS_LexNatCon arg, char* (*acceptList)(char*)) {
  if (PRS_isLexNatConDigits(arg)) {
    return PRS_makeLexNatConDigits(
        acceptList ? acceptList(PRS_getLexNatConList(arg)) : PRS_getLexNatConList(arg));
  }
  ATabort("not a LexNatCon: %t\n", arg);
  return (PRS_LexNatCon)NULL;
}
/**
 * Apply functions to the children of a PRS_NatCon. 
 * \return A new PRS_NatCon with new children where the argument functions might have applied
 */
PRS_NatCon PRS_visitNatCon(PRS_NatCon arg, PRS_LexNatCon (*acceptNatCon)(PRS_LexNatCon)) {
  if (PRS_isNatConLexToCf(arg)) {
    return PRS_makeNatConLexToCf(
        acceptNatCon ? acceptNatCon(PRS_getNatConNatCon(arg)) : PRS_getNatConNatCon(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (PRS_NatCon)NULL;
}
/**
 * Apply functions to the children of a PRS_LexIdCon. 
 * \return A new PRS_LexIdCon with new children where the argument functions might have applied
 */
PRS_LexIdCon PRS_visitLexIdCon(PRS_LexIdCon arg, char (*acceptHead)(char), char* (*acceptTail)(char*)) {
  if (PRS_isLexIdConDefault(arg)) {
    return PRS_makeLexIdConDefault(
        acceptHead ? acceptHead(PRS_getLexIdConHead(arg)) : PRS_getLexIdConHead(arg),
        acceptTail ? acceptTail(PRS_getLexIdConTail(arg)) : PRS_getLexIdConTail(arg));
  }
  ATabort("not a LexIdCon: %t\n", arg);
  return (PRS_LexIdCon)NULL;
}
/**
 * Apply functions to the children of a PRS_IdCon. 
 * \return A new PRS_IdCon with new children where the argument functions might have applied
 */
PRS_IdCon PRS_visitIdCon(PRS_IdCon arg, PRS_LexIdCon (*acceptIdCon)(PRS_LexIdCon)) {
  if (PRS_isIdConLexToCf(arg)) {
    return PRS_makeIdConLexToCf(
        acceptIdCon ? acceptIdCon(PRS_getIdConIdCon(arg)) : PRS_getIdConIdCon(arg));
  }
  ATabort("not a IdCon: %t\n", arg);
  return (PRS_IdCon)NULL;
}
/**
 * Apply functions to the children of a PRS_LexIntCon. 
 * \return A new PRS_LexIntCon with new children where the argument functions might have applied
 */
PRS_LexIntCon PRS_visitLexIntCon(PRS_LexIntCon arg, PRS_LexNatCon (*acceptDigits)(PRS_LexNatCon)) {
  if (PRS_isLexIntConPositive(arg)) {
    return PRS_makeLexIntConPositive(
        acceptDigits ? acceptDigits(PRS_getLexIntConDigits(arg)) : PRS_getLexIntConDigits(arg));
  }
  if (PRS_isLexIntConNegative(arg)) {
    return PRS_makeLexIntConNegative(
        acceptDigits ? acceptDigits(PRS_getLexIntConDigits(arg)) : PRS_getLexIntConDigits(arg));
  }
  ATabort("not a LexIntCon: %t\n", arg);
  return (PRS_LexIntCon)NULL;
}
/**
 * Apply functions to the children of a PRS_IntCon. 
 * \return A new PRS_IntCon with new children where the argument functions might have applied
 */
PRS_IntCon PRS_visitIntCon(PRS_IntCon arg, PRS_LexIntCon (*acceptIntCon)(PRS_LexIntCon)) {
  if (PRS_isIntConLexToCf(arg)) {
    return PRS_makeIntConLexToCf(
        acceptIntCon ? acceptIntCon(PRS_getIntConIntCon(arg)) : PRS_getIntConIntCon(arg));
  }
  ATabort("not a IntCon: %t\n", arg);
  return (PRS_IntCon)NULL;
}
/**
 * Apply functions to the children of a PRS_LexLayout. 
 * \return A new PRS_LexLayout with new children where the argument functions might have applied
 */
PRS_LexLayout PRS_visitLexLayout(PRS_LexLayout arg, char (*acceptCh)(char)) {
  if (PRS_isLexLayoutWhitespace(arg)) {
    return PRS_makeLexLayoutWhitespace(
        acceptCh ? acceptCh(PRS_getLexLayoutCh(arg)) : PRS_getLexLayoutCh(arg));
  }
  ATabort("not a LexLayout: %t\n", arg);
  return (PRS_LexLayout)NULL;
}
/**
 * Apply functions to the children of a PRS_Location. 
 * \return A new PRS_Location with new children where the argument functions might have applied
 */
PRS_Location PRS_visitLocation(PRS_Location arg, PRS_OptLayout (*acceptWsAfterFile)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterParenOpen)(PRS_OptLayout), PRS_StrCon (*acceptFilename)(PRS_StrCon), PRS_OptLayout (*acceptWsAfterFilename)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterA)(PRS_OptLayout), PRS_Area (*acceptArea)(PRS_Area), PRS_OptLayout (*acceptWsAfterArea)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterAreaInFile)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma)(PRS_OptLayout)) {
  if (PRS_isLocationFile(arg)) {
    return PRS_makeLocationFile(
        acceptWsAfterFile ? acceptWsAfterFile(PRS_getLocationWsAfterFile(arg)) : PRS_getLocationWsAfterFile(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getLocationWsAfterParenOpen(arg)) : PRS_getLocationWsAfterParenOpen(arg),
        acceptFilename ? acceptFilename(PRS_getLocationFilename(arg)) : PRS_getLocationFilename(arg),
        acceptWsAfterFilename ? acceptWsAfterFilename(PRS_getLocationWsAfterFilename(arg)) : PRS_getLocationWsAfterFilename(arg));
  }
  if (PRS_isLocationArea(arg)) {
    return PRS_makeLocationArea(
        acceptWsAfterA ? acceptWsAfterA(PRS_getLocationWsAfterA(arg)) : PRS_getLocationWsAfterA(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getLocationWsAfterParenOpen(arg)) : PRS_getLocationWsAfterParenOpen(arg),
        acceptArea ? acceptArea(PRS_getLocationArea(arg)) : PRS_getLocationArea(arg),
        acceptWsAfterArea ? acceptWsAfterArea(PRS_getLocationWsAfterArea(arg)) : PRS_getLocationWsAfterArea(arg));
  }
  if (PRS_isLocationAreaInFile(arg)) {
    return PRS_makeLocationAreaInFile(
        acceptWsAfterAreaInFile ? acceptWsAfterAreaInFile(PRS_getLocationWsAfterAreaInFile(arg)) : PRS_getLocationWsAfterAreaInFile(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getLocationWsAfterParenOpen(arg)) : PRS_getLocationWsAfterParenOpen(arg),
        acceptFilename ? acceptFilename(PRS_getLocationFilename(arg)) : PRS_getLocationFilename(arg),
        acceptWsAfterFilename ? acceptWsAfterFilename(PRS_getLocationWsAfterFilename(arg)) : PRS_getLocationWsAfterFilename(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PRS_getLocationWsAfterComma(arg)) : PRS_getLocationWsAfterComma(arg),
        acceptArea ? acceptArea(PRS_getLocationArea(arg)) : PRS_getLocationArea(arg),
        acceptWsAfterArea ? acceptWsAfterArea(PRS_getLocationWsAfterArea(arg)) : PRS_getLocationWsAfterArea(arg));
  }
  ATabort("not a Location: %t\n", arg);
  return (PRS_Location)NULL;
}
/**
 * Apply functions to the children of a PRS_Area. 
 * \return A new PRS_Area with new children where the argument functions might have applied
 */
PRS_Area PRS_visitArea(PRS_Area arg, PRS_OptLayout (*acceptWsAfterArea)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterParenOpen)(PRS_OptLayout), PRS_NatCon (*acceptBeginLine)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterBeginLine)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma)(PRS_OptLayout), PRS_NatCon (*acceptBeginColumn)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterBeginColumn)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma1)(PRS_OptLayout), PRS_NatCon (*acceptEndLine)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterEndLine)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma2)(PRS_OptLayout), PRS_NatCon (*acceptEndColumn)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterEndColumn)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma3)(PRS_OptLayout), PRS_NatCon (*acceptOffset)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterOffset)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma4)(PRS_OptLayout), PRS_NatCon (*acceptLength)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterLength)(PRS_OptLayout)) {
  if (PRS_isAreaArea(arg)) {
    return PRS_makeAreaArea(
        acceptWsAfterArea ? acceptWsAfterArea(PRS_getAreaWsAfterArea(arg)) : PRS_getAreaWsAfterArea(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getAreaWsAfterParenOpen(arg)) : PRS_getAreaWsAfterParenOpen(arg),
        acceptBeginLine ? acceptBeginLine(PRS_getAreaBeginLine(arg)) : PRS_getAreaBeginLine(arg),
        acceptWsAfterBeginLine ? acceptWsAfterBeginLine(PRS_getAreaWsAfterBeginLine(arg)) : PRS_getAreaWsAfterBeginLine(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PRS_getAreaWsAfterComma(arg)) : PRS_getAreaWsAfterComma(arg),
        acceptBeginColumn ? acceptBeginColumn(PRS_getAreaBeginColumn(arg)) : PRS_getAreaBeginColumn(arg),
        acceptWsAfterBeginColumn ? acceptWsAfterBeginColumn(PRS_getAreaWsAfterBeginColumn(arg)) : PRS_getAreaWsAfterBeginColumn(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(PRS_getAreaWsAfterComma1(arg)) : PRS_getAreaWsAfterComma1(arg),
        acceptEndLine ? acceptEndLine(PRS_getAreaEndLine(arg)) : PRS_getAreaEndLine(arg),
        acceptWsAfterEndLine ? acceptWsAfterEndLine(PRS_getAreaWsAfterEndLine(arg)) : PRS_getAreaWsAfterEndLine(arg),
        acceptWsAfterComma2 ? acceptWsAfterComma2(PRS_getAreaWsAfterComma2(arg)) : PRS_getAreaWsAfterComma2(arg),
        acceptEndColumn ? acceptEndColumn(PRS_getAreaEndColumn(arg)) : PRS_getAreaEndColumn(arg),
        acceptWsAfterEndColumn ? acceptWsAfterEndColumn(PRS_getAreaWsAfterEndColumn(arg)) : PRS_getAreaWsAfterEndColumn(arg),
        acceptWsAfterComma3 ? acceptWsAfterComma3(PRS_getAreaWsAfterComma3(arg)) : PRS_getAreaWsAfterComma3(arg),
        acceptOffset ? acceptOffset(PRS_getAreaOffset(arg)) : PRS_getAreaOffset(arg),
        acceptWsAfterOffset ? acceptWsAfterOffset(PRS_getAreaWsAfterOffset(arg)) : PRS_getAreaWsAfterOffset(arg),
        acceptWsAfterComma4 ? acceptWsAfterComma4(PRS_getAreaWsAfterComma4(arg)) : PRS_getAreaWsAfterComma4(arg),
        acceptLength ? acceptLength(PRS_getAreaLength(arg)) : PRS_getAreaLength(arg),
        acceptWsAfterLength ? acceptWsAfterLength(PRS_getAreaWsAfterLength(arg)) : PRS_getAreaWsAfterLength(arg));
  }
  ATabort("not a Area: %t\n", arg);
  return (PRS_Area)NULL;
}

