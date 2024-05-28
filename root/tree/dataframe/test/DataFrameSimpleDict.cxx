// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME DataFrameSimpleDict
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
#include "/Users/abhiacherjee/Documents/root_src/tree/dataframe/test/MaxSlotHelper.h"
#include "/Users/abhiacherjee/Documents/root_src/tree/dataframe/test/SimpleFiller.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *MaxSlotHelper_Dictionary();
   static void MaxSlotHelper_TClassManip(TClass*);
   static void delete_MaxSlotHelper(void *p);
   static void deleteArray_MaxSlotHelper(void *p);
   static void destruct_MaxSlotHelper(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MaxSlotHelper*)
   {
      ::MaxSlotHelper *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::MaxSlotHelper));
      static ::ROOT::TGenericClassInfo 
         instance("MaxSlotHelper", "", 7,
                  typeid(::MaxSlotHelper), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &MaxSlotHelper_Dictionary, isa_proxy, 1,
                  sizeof(::MaxSlotHelper) );
      instance.SetDelete(&delete_MaxSlotHelper);
      instance.SetDeleteArray(&deleteArray_MaxSlotHelper);
      instance.SetDestructor(&destruct_MaxSlotHelper);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MaxSlotHelper*)
   {
      return GenerateInitInstanceLocal(static_cast<::MaxSlotHelper*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::MaxSlotHelper*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *MaxSlotHelper_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::MaxSlotHelper*>(nullptr))->GetClass();
      MaxSlotHelper_TClassManip(theClass);
   return theClass;
   }

   static void MaxSlotHelper_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SimpleFiller_Dictionary();
   static void SimpleFiller_TClassManip(TClass*);
   static void *new_SimpleFiller(void *p = nullptr);
   static void *newArray_SimpleFiller(Long_t size, void *p);
   static void delete_SimpleFiller(void *p);
   static void deleteArray_SimpleFiller(void *p);
   static void destruct_SimpleFiller(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SimpleFiller*)
   {
      ::SimpleFiller *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SimpleFiller));
      static ::ROOT::TGenericClassInfo 
         instance("SimpleFiller", "", 34,
                  typeid(::SimpleFiller), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SimpleFiller_Dictionary, isa_proxy, 1,
                  sizeof(::SimpleFiller) );
      instance.SetNew(&new_SimpleFiller);
      instance.SetNewArray(&newArray_SimpleFiller);
      instance.SetDelete(&delete_SimpleFiller);
      instance.SetDeleteArray(&deleteArray_SimpleFiller);
      instance.SetDestructor(&destruct_SimpleFiller);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SimpleFiller*)
   {
      return GenerateInitInstanceLocal(static_cast<::SimpleFiller*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::SimpleFiller*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SimpleFiller_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::SimpleFiller*>(nullptr))->GetClass();
      SimpleFiller_TClassManip(theClass);
   return theClass;
   }

   static void SimpleFiller_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_MaxSlotHelper(void *p) {
      delete (static_cast<::MaxSlotHelper*>(p));
   }
   static void deleteArray_MaxSlotHelper(void *p) {
      delete [] (static_cast<::MaxSlotHelper*>(p));
   }
   static void destruct_MaxSlotHelper(void *p) {
      typedef ::MaxSlotHelper current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::MaxSlotHelper

namespace ROOT {
   // Wrappers around operator new
   static void *new_SimpleFiller(void *p) {
      return  p ? new(p) ::SimpleFiller : new ::SimpleFiller;
   }
   static void *newArray_SimpleFiller(Long_t nElements, void *p) {
      return p ? new(p) ::SimpleFiller[nElements] : new ::SimpleFiller[nElements];
   }
   // Wrapper around operator delete
   static void delete_SimpleFiller(void *p) {
      delete (static_cast<::SimpleFiller*>(p));
   }
   static void deleteArray_SimpleFiller(void *p) {
      delete [] (static_cast<::SimpleFiller*>(p));
   }
   static void destruct_SimpleFiller(void *p) {
      typedef ::SimpleFiller current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::SimpleFiller

namespace {
  void TriggerDictionaryInitialization_libdataframe_simple_Impl() {
    static const char* headers[] = {
nullptr
    };
    static const char* includePaths[] = {
nullptr
    };
    static const char* fwdDeclCode = "";
    static const char* payloadCode = "";
    static const char* classesHeaders[] = {
""
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libdataframe_simple",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libdataframe_simple_Impl, {}, classesHeaders, /*hasCxxModule*/true);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libdataframe_simple_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libdataframe_simple() {
  TriggerDictionaryInitialization_libdataframe_simple_Impl();
}
