// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME ElementStructDict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "ElementStruct.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *ElementStruct_Dictionary();
   static void ElementStruct_TClassManip(TClass*);
   static void *new_ElementStruct(void *p = nullptr);
   static void *newArray_ElementStruct(Long_t size, void *p);
   static void delete_ElementStruct(void *p);
   static void deleteArray_ElementStruct(void *p);
   static void destruct_ElementStruct(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ElementStruct*)
   {
      ::ElementStruct *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ElementStruct));
      static ::ROOT::TGenericClassInfo 
         instance("ElementStruct", "", 8,
                  typeid(::ElementStruct), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ElementStruct_Dictionary, isa_proxy, 4,
                  sizeof(::ElementStruct) );
      instance.SetNew(&new_ElementStruct);
      instance.SetNewArray(&newArray_ElementStruct);
      instance.SetDelete(&delete_ElementStruct);
      instance.SetDeleteArray(&deleteArray_ElementStruct);
      instance.SetDestructor(&destruct_ElementStruct);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ElementStruct*)
   {
      return GenerateInitInstanceLocal(static_cast<::ElementStruct*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::ElementStruct*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ElementStruct_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::ElementStruct*>(nullptr))->GetClass();
      ElementStruct_TClassManip(theClass);
   return theClass;
   }

   static void ElementStruct_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ElementStruct(void *p) {
      return  p ? new(p) ::ElementStruct : new ::ElementStruct;
   }
   static void *newArray_ElementStruct(Long_t nElements, void *p) {
      return p ? new(p) ::ElementStruct[nElements] : new ::ElementStruct[nElements];
   }
   // Wrapper around operator delete
   static void delete_ElementStruct(void *p) {
      delete (static_cast<::ElementStruct*>(p));
   }
   static void deleteArray_ElementStruct(void *p) {
      delete [] (static_cast<::ElementStruct*>(p));
   }
   static void destruct_ElementStruct(void *p) {
      typedef ::ElementStruct current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::ElementStruct

namespace {
  void TriggerDictionaryInitialization_libElementStructDict_Impl() {
    static const char* headers[] = {
"0",
nullptr
    };
    static const char* includePaths[] = {
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libElementStructDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class ElementStruct;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libElementStructDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
/**
 * The ElementStruct has no purpose except to provide
 * inputs to the test cases.
 */

class ElementStruct {
public:
   int    i;
   double *d; //[i]
};

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"ElementStruct", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libElementStructDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libElementStructDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libElementStructDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libElementStructDict() {
  TriggerDictionaryInitialization_libElementStructDict_Impl();
}
