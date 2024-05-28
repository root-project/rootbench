// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME TwoFloatsDict
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
#include "/Users/abhiacherjee/Documents/root_src/tree/dataframe/test/TwoFloats.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_TwoFloats(void *p = nullptr);
   static void *newArray_TwoFloats(Long_t size, void *p);
   static void delete_TwoFloats(void *p);
   static void deleteArray_TwoFloats(void *p);
   static void destruct_TwoFloats(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TwoFloats*)
   {
      ::TwoFloats *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TwoFloats >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TwoFloats", ::TwoFloats::Class_Version(), "", 5,
                  typeid(::TwoFloats), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TwoFloats::Dictionary, isa_proxy, 4,
                  sizeof(::TwoFloats) );
      instance.SetNew(&new_TwoFloats);
      instance.SetNewArray(&newArray_TwoFloats);
      instance.SetDelete(&delete_TwoFloats);
      instance.SetDeleteArray(&deleteArray_TwoFloats);
      instance.SetDestructor(&destruct_TwoFloats);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TwoFloats*)
   {
      return GenerateInitInstanceLocal(static_cast<::TwoFloats*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TwoFloats*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TwoFloats::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TwoFloats::Class_Name()
{
   return "TwoFloats";
}

//______________________________________________________________________________
const char *TwoFloats::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TwoFloats*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TwoFloats::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TwoFloats*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TwoFloats::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TwoFloats*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TwoFloats::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TwoFloats*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TwoFloats::Streamer(TBuffer &R__b)
{
   // Stream an object of class TwoFloats.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TwoFloats::Class(),this);
   } else {
      R__b.WriteClassBuffer(TwoFloats::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TwoFloats(void *p) {
      return  p ? new(p) ::TwoFloats : new ::TwoFloats;
   }
   static void *newArray_TwoFloats(Long_t nElements, void *p) {
      return p ? new(p) ::TwoFloats[nElements] : new ::TwoFloats[nElements];
   }
   // Wrapper around operator delete
   static void delete_TwoFloats(void *p) {
      delete (static_cast<::TwoFloats*>(p));
   }
   static void deleteArray_TwoFloats(void *p) {
      delete [] (static_cast<::TwoFloats*>(p));
   }
   static void destruct_TwoFloats(void *p) {
      typedef ::TwoFloats current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TwoFloats

namespace ROOT {
   static TClass *vectorlETwoFloatsgR_Dictionary();
   static void vectorlETwoFloatsgR_TClassManip(TClass*);
   static void *new_vectorlETwoFloatsgR(void *p = nullptr);
   static void *newArray_vectorlETwoFloatsgR(Long_t size, void *p);
   static void delete_vectorlETwoFloatsgR(void *p);
   static void deleteArray_vectorlETwoFloatsgR(void *p);
   static void destruct_vectorlETwoFloatsgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TwoFloats>*)
   {
      vector<TwoFloats> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TwoFloats>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TwoFloats>", -2, "vector", 348,
                  typeid(vector<TwoFloats>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETwoFloatsgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<TwoFloats>) );
      instance.SetNew(&new_vectorlETwoFloatsgR);
      instance.SetNewArray(&newArray_vectorlETwoFloatsgR);
      instance.SetDelete(&delete_vectorlETwoFloatsgR);
      instance.SetDeleteArray(&deleteArray_vectorlETwoFloatsgR);
      instance.SetDestructor(&destruct_vectorlETwoFloatsgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TwoFloats> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<TwoFloats>","std::__1::vector<TwoFloats, std::__1::allocator<TwoFloats>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<TwoFloats>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETwoFloatsgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<TwoFloats>*>(nullptr))->GetClass();
      vectorlETwoFloatsgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETwoFloatsgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETwoFloatsgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TwoFloats> : new vector<TwoFloats>;
   }
   static void *newArray_vectorlETwoFloatsgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TwoFloats>[nElements] : new vector<TwoFloats>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETwoFloatsgR(void *p) {
      delete (static_cast<vector<TwoFloats>*>(p));
   }
   static void deleteArray_vectorlETwoFloatsgR(void *p) {
      delete [] (static_cast<vector<TwoFloats>*>(p));
   }
   static void destruct_vectorlETwoFloatsgR(void *p) {
      typedef vector<TwoFloats> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<TwoFloats>

namespace {
  void TriggerDictionaryInitialization_libdataframe_splitcoll_arrayview_Impl() {
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
      TROOT::RegisterModule("libdataframe_splitcoll_arrayview",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libdataframe_splitcoll_arrayview_Impl, {}, classesHeaders, /*hasCxxModule*/true);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libdataframe_splitcoll_arrayview_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libdataframe_splitcoll_arrayview() {
  TriggerDictionaryInitialization_libdataframe_splitcoll_arrayview_Impl();
}
