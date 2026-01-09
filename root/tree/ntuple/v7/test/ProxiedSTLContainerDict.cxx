// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME ProxiedSTLContainerDict
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
#include "/Users/abhiacherjee/Documents/root_src/tree/ntuple/v7/test/ProxiedSTLContainer.hxx"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *vectorlEboolgR_Dictionary();
   static void vectorlEboolgR_TClassManip(TClass*);
   static void *new_vectorlEboolgR(void *p = nullptr);
   static void *newArray_vectorlEboolgR(Long_t size, void *p);
   static void delete_vectorlEboolgR(void *p);
   static void deleteArray_vectorlEboolgR(void *p);
   static void destruct_vectorlEboolgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<bool>*)
   {
      vector<bool> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<bool>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<bool>", -2, "vector", 2040,
                  typeid(vector<bool>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEboolgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<bool>) );
      instance.SetNew(&new_vectorlEboolgR);
      instance.SetNewArray(&newArray_vectorlEboolgR);
      instance.SetDelete(&delete_vectorlEboolgR);
      instance.SetDeleteArray(&deleteArray_vectorlEboolgR);
      instance.SetDestructor(&destruct_vectorlEboolgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<bool> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<bool>","std::__1::vector<bool, std::__1::allocator<bool>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<bool>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEboolgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<bool>*>(nullptr))->GetClass();
      vectorlEboolgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEboolgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEboolgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<bool> : new vector<bool>;
   }
   static void *newArray_vectorlEboolgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<bool>[nElements] : new vector<bool>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEboolgR(void *p) {
      delete (static_cast<vector<bool>*>(p));
   }
   static void deleteArray_vectorlEboolgR(void *p) {
      delete [] (static_cast<vector<bool>*>(p));
   }
   static void destruct_vectorlEboolgR(void *p) {
      typedef vector<bool> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<bool>

namespace ROOT {
   static TClass *vectorlECustomStructgR_Dictionary();
   static void vectorlECustomStructgR_TClassManip(TClass*);
   static void *new_vectorlECustomStructgR(void *p = nullptr);
   static void *newArray_vectorlECustomStructgR(Long_t size, void *p);
   static void delete_vectorlECustomStructgR(void *p);
   static void deleteArray_vectorlECustomStructgR(void *p);
   static void destruct_vectorlECustomStructgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<CustomStruct>*)
   {
      vector<CustomStruct> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<CustomStruct>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<CustomStruct>", -2, "vector", 348,
                  typeid(vector<CustomStruct>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlECustomStructgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<CustomStruct>) );
      instance.SetNew(&new_vectorlECustomStructgR);
      instance.SetNewArray(&newArray_vectorlECustomStructgR);
      instance.SetDelete(&delete_vectorlECustomStructgR);
      instance.SetDeleteArray(&deleteArray_vectorlECustomStructgR);
      instance.SetDestructor(&destruct_vectorlECustomStructgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<CustomStruct> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<CustomStruct>","std::__1::vector<CustomStruct, std::__1::allocator<CustomStruct>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<CustomStruct>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlECustomStructgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<CustomStruct>*>(nullptr))->GetClass();
      vectorlECustomStructgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlECustomStructgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlECustomStructgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CustomStruct> : new vector<CustomStruct>;
   }
   static void *newArray_vectorlECustomStructgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CustomStruct>[nElements] : new vector<CustomStruct>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlECustomStructgR(void *p) {
      delete (static_cast<vector<CustomStruct>*>(p));
   }
   static void deleteArray_vectorlECustomStructgR(void *p) {
      delete [] (static_cast<vector<CustomStruct>*>(p));
   }
   static void destruct_vectorlECustomStructgR(void *p) {
      typedef vector<CustomStruct> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<CustomStruct>

namespace ROOT {
   static TClass *unordered_setlEvectorlEboolgRsPgR_Dictionary();
   static void unordered_setlEvectorlEboolgRsPgR_TClassManip(TClass*);
   static void *new_unordered_setlEvectorlEboolgRsPgR(void *p = nullptr);
   static void *newArray_unordered_setlEvectorlEboolgRsPgR(Long_t size, void *p);
   static void delete_unordered_setlEvectorlEboolgRsPgR(void *p);
   static void deleteArray_unordered_setlEvectorlEboolgRsPgR(void *p);
   static void destruct_unordered_setlEvectorlEboolgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const unordered_set<vector<bool> >*)
   {
      unordered_set<vector<bool> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(unordered_set<vector<bool> >));
      static ::ROOT::TGenericClassInfo 
         instance("unordered_set<vector<bool> >", -2, "unordered_set", 504,
                  typeid(unordered_set<vector<bool> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &unordered_setlEvectorlEboolgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(unordered_set<vector<bool> >) );
      instance.SetNew(&new_unordered_setlEvectorlEboolgRsPgR);
      instance.SetNewArray(&newArray_unordered_setlEvectorlEboolgRsPgR);
      instance.SetDelete(&delete_unordered_setlEvectorlEboolgRsPgR);
      instance.SetDeleteArray(&deleteArray_unordered_setlEvectorlEboolgRsPgR);
      instance.SetDestructor(&destruct_unordered_setlEvectorlEboolgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< unordered_set<vector<bool> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("unordered_set<vector<bool> >","std::__1::unordered_set<std::__1::vector<bool, std::__1::allocator<bool>>, std::__1::hash<std::__1::vector<bool, std::__1::allocator<bool>>>, std::__1::equal_to<std::__1::vector<bool, std::__1::allocator<bool>>>, std::__1::allocator<std::__1::vector<bool, std::__1::allocator<bool>>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const unordered_set<vector<bool> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *unordered_setlEvectorlEboolgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const unordered_set<vector<bool> >*>(nullptr))->GetClass();
      unordered_setlEvectorlEboolgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void unordered_setlEvectorlEboolgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_unordered_setlEvectorlEboolgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_set<vector<bool> > : new unordered_set<vector<bool> >;
   }
   static void *newArray_unordered_setlEvectorlEboolgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_set<vector<bool> >[nElements] : new unordered_set<vector<bool> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_unordered_setlEvectorlEboolgRsPgR(void *p) {
      delete (static_cast<unordered_set<vector<bool> >*>(p));
   }
   static void deleteArray_unordered_setlEvectorlEboolgRsPgR(void *p) {
      delete [] (static_cast<unordered_set<vector<bool> >*>(p));
   }
   static void destruct_unordered_setlEvectorlEboolgRsPgR(void *p) {
      typedef unordered_set<vector<bool> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class unordered_set<vector<bool> >

namespace ROOT {
   static TClass *unordered_setlEstringgR_Dictionary();
   static void unordered_setlEstringgR_TClassManip(TClass*);
   static void *new_unordered_setlEstringgR(void *p = nullptr);
   static void *newArray_unordered_setlEstringgR(Long_t size, void *p);
   static void delete_unordered_setlEstringgR(void *p);
   static void deleteArray_unordered_setlEstringgR(void *p);
   static void destruct_unordered_setlEstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const unordered_set<string>*)
   {
      unordered_set<string> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(unordered_set<string>));
      static ::ROOT::TGenericClassInfo 
         instance("unordered_set<string>", -2, "unordered_set", 504,
                  typeid(unordered_set<string>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &unordered_setlEstringgR_Dictionary, isa_proxy, 4,
                  sizeof(unordered_set<string>) );
      instance.SetNew(&new_unordered_setlEstringgR);
      instance.SetNewArray(&newArray_unordered_setlEstringgR);
      instance.SetDelete(&delete_unordered_setlEstringgR);
      instance.SetDeleteArray(&deleteArray_unordered_setlEstringgR);
      instance.SetDestructor(&destruct_unordered_setlEstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< unordered_set<string> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("unordered_set<string>","std::__1::unordered_set<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>, std::__1::hash<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>>, std::__1::equal_to<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>>, std::__1::allocator<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const unordered_set<string>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *unordered_setlEstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const unordered_set<string>*>(nullptr))->GetClass();
      unordered_setlEstringgR_TClassManip(theClass);
   return theClass;
   }

   static void unordered_setlEstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_unordered_setlEstringgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_set<string> : new unordered_set<string>;
   }
   static void *newArray_unordered_setlEstringgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_set<string>[nElements] : new unordered_set<string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_unordered_setlEstringgR(void *p) {
      delete (static_cast<unordered_set<string>*>(p));
   }
   static void deleteArray_unordered_setlEstringgR(void *p) {
      delete [] (static_cast<unordered_set<string>*>(p));
   }
   static void destruct_unordered_setlEstringgR(void *p) {
      typedef unordered_set<string> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class unordered_set<string>

namespace ROOT {
   static TClass *unordered_setlEfloatgR_Dictionary();
   static void unordered_setlEfloatgR_TClassManip(TClass*);
   static void *new_unordered_setlEfloatgR(void *p = nullptr);
   static void *newArray_unordered_setlEfloatgR(Long_t size, void *p);
   static void delete_unordered_setlEfloatgR(void *p);
   static void deleteArray_unordered_setlEfloatgR(void *p);
   static void destruct_unordered_setlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const unordered_set<float>*)
   {
      unordered_set<float> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(unordered_set<float>));
      static ::ROOT::TGenericClassInfo 
         instance("unordered_set<float>", -2, "unordered_set", 504,
                  typeid(unordered_set<float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &unordered_setlEfloatgR_Dictionary, isa_proxy, 4,
                  sizeof(unordered_set<float>) );
      instance.SetNew(&new_unordered_setlEfloatgR);
      instance.SetNewArray(&newArray_unordered_setlEfloatgR);
      instance.SetDelete(&delete_unordered_setlEfloatgR);
      instance.SetDeleteArray(&deleteArray_unordered_setlEfloatgR);
      instance.SetDestructor(&destruct_unordered_setlEfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< unordered_set<float> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("unordered_set<float>","std::__1::unordered_set<float, std::__1::hash<float>, std::__1::equal_to<float>, std::__1::allocator<float>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const unordered_set<float>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *unordered_setlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const unordered_set<float>*>(nullptr))->GetClass();
      unordered_setlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void unordered_setlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_unordered_setlEfloatgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_set<float> : new unordered_set<float>;
   }
   static void *newArray_unordered_setlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_set<float>[nElements] : new unordered_set<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_unordered_setlEfloatgR(void *p) {
      delete (static_cast<unordered_set<float>*>(p));
   }
   static void deleteArray_unordered_setlEfloatgR(void *p) {
      delete [] (static_cast<unordered_set<float>*>(p));
   }
   static void destruct_unordered_setlEfloatgR(void *p) {
      typedef unordered_set<float> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class unordered_set<float>

namespace ROOT {
   static TClass *unordered_setlELong64_tgR_Dictionary();
   static void unordered_setlELong64_tgR_TClassManip(TClass*);
   static void *new_unordered_setlELong64_tgR(void *p = nullptr);
   static void *newArray_unordered_setlELong64_tgR(Long_t size, void *p);
   static void delete_unordered_setlELong64_tgR(void *p);
   static void deleteArray_unordered_setlELong64_tgR(void *p);
   static void destruct_unordered_setlELong64_tgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const unordered_set<Long64_t>*)
   {
      unordered_set<Long64_t> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(unordered_set<Long64_t>));
      static ::ROOT::TGenericClassInfo 
         instance("unordered_set<Long64_t>", -2, "unordered_set", 504,
                  typeid(unordered_set<Long64_t>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &unordered_setlELong64_tgR_Dictionary, isa_proxy, 4,
                  sizeof(unordered_set<Long64_t>) );
      instance.SetNew(&new_unordered_setlELong64_tgR);
      instance.SetNewArray(&newArray_unordered_setlELong64_tgR);
      instance.SetDelete(&delete_unordered_setlELong64_tgR);
      instance.SetDeleteArray(&deleteArray_unordered_setlELong64_tgR);
      instance.SetDestructor(&destruct_unordered_setlELong64_tgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< unordered_set<Long64_t> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("unordered_set<Long64_t>","std::__1::unordered_set<long long, std::__1::hash<long long>, std::__1::equal_to<long long>, std::__1::allocator<long long>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const unordered_set<Long64_t>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *unordered_setlELong64_tgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const unordered_set<Long64_t>*>(nullptr))->GetClass();
      unordered_setlELong64_tgR_TClassManip(theClass);
   return theClass;
   }

   static void unordered_setlELong64_tgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_unordered_setlELong64_tgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_set<Long64_t> : new unordered_set<Long64_t>;
   }
   static void *newArray_unordered_setlELong64_tgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_set<Long64_t>[nElements] : new unordered_set<Long64_t>[nElements];
   }
   // Wrapper around operator delete
   static void delete_unordered_setlELong64_tgR(void *p) {
      delete (static_cast<unordered_set<Long64_t>*>(p));
   }
   static void deleteArray_unordered_setlELong64_tgR(void *p) {
      delete [] (static_cast<unordered_set<Long64_t>*>(p));
   }
   static void destruct_unordered_setlELong64_tgR(void *p) {
      typedef unordered_set<Long64_t> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class unordered_set<Long64_t>

namespace ROOT {
   static TClass *unordered_setlECustomStructgR_Dictionary();
   static void unordered_setlECustomStructgR_TClassManip(TClass*);
   static void *new_unordered_setlECustomStructgR(void *p = nullptr);
   static void *newArray_unordered_setlECustomStructgR(Long_t size, void *p);
   static void delete_unordered_setlECustomStructgR(void *p);
   static void deleteArray_unordered_setlECustomStructgR(void *p);
   static void destruct_unordered_setlECustomStructgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const unordered_set<CustomStruct>*)
   {
      unordered_set<CustomStruct> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(unordered_set<CustomStruct>));
      static ::ROOT::TGenericClassInfo 
         instance("unordered_set<CustomStruct>", -2, "unordered_set", 504,
                  typeid(unordered_set<CustomStruct>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &unordered_setlECustomStructgR_Dictionary, isa_proxy, 4,
                  sizeof(unordered_set<CustomStruct>) );
      instance.SetNew(&new_unordered_setlECustomStructgR);
      instance.SetNewArray(&newArray_unordered_setlECustomStructgR);
      instance.SetDelete(&delete_unordered_setlECustomStructgR);
      instance.SetDeleteArray(&deleteArray_unordered_setlECustomStructgR);
      instance.SetDestructor(&destruct_unordered_setlECustomStructgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< unordered_set<CustomStruct> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("unordered_set<CustomStruct>","std::__1::unordered_set<CustomStruct, std::__1::hash<CustomStruct>, std::__1::equal_to<CustomStruct>, std::__1::allocator<CustomStruct>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const unordered_set<CustomStruct>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *unordered_setlECustomStructgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const unordered_set<CustomStruct>*>(nullptr))->GetClass();
      unordered_setlECustomStructgR_TClassManip(theClass);
   return theClass;
   }

   static void unordered_setlECustomStructgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_unordered_setlECustomStructgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_set<CustomStruct> : new unordered_set<CustomStruct>;
   }
   static void *newArray_unordered_setlECustomStructgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_set<CustomStruct>[nElements] : new unordered_set<CustomStruct>[nElements];
   }
   // Wrapper around operator delete
   static void delete_unordered_setlECustomStructgR(void *p) {
      delete (static_cast<unordered_set<CustomStruct>*>(p));
   }
   static void deleteArray_unordered_setlECustomStructgR(void *p) {
      delete [] (static_cast<unordered_set<CustomStruct>*>(p));
   }
   static void destruct_unordered_setlECustomStructgR(void *p) {
      typedef unordered_set<CustomStruct> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class unordered_set<CustomStruct>

namespace ROOT {
   static TClass *unordered_maplEintcOCustomStructgR_Dictionary();
   static void unordered_maplEintcOCustomStructgR_TClassManip(TClass*);
   static void *new_unordered_maplEintcOCustomStructgR(void *p = nullptr);
   static void *newArray_unordered_maplEintcOCustomStructgR(Long_t size, void *p);
   static void delete_unordered_maplEintcOCustomStructgR(void *p);
   static void deleteArray_unordered_maplEintcOCustomStructgR(void *p);
   static void destruct_unordered_maplEintcOCustomStructgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const unordered_map<int,CustomStruct>*)
   {
      unordered_map<int,CustomStruct> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(unordered_map<int,CustomStruct>));
      static ::ROOT::TGenericClassInfo 
         instance("unordered_map<int,CustomStruct>", -2, "unordered_map", 1025,
                  typeid(unordered_map<int,CustomStruct>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &unordered_maplEintcOCustomStructgR_Dictionary, isa_proxy, 4,
                  sizeof(unordered_map<int,CustomStruct>) );
      instance.SetNew(&new_unordered_maplEintcOCustomStructgR);
      instance.SetNewArray(&newArray_unordered_maplEintcOCustomStructgR);
      instance.SetDelete(&delete_unordered_maplEintcOCustomStructgR);
      instance.SetDeleteArray(&deleteArray_unordered_maplEintcOCustomStructgR);
      instance.SetDestructor(&destruct_unordered_maplEintcOCustomStructgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< unordered_map<int,CustomStruct> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("unordered_map<int,CustomStruct>","std::__1::unordered_map<int, CustomStruct, std::__1::hash<int>, std::__1::equal_to<int>, std::__1::allocator<std::__1::pair<int const, CustomStruct>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const unordered_map<int,CustomStruct>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *unordered_maplEintcOCustomStructgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const unordered_map<int,CustomStruct>*>(nullptr))->GetClass();
      unordered_maplEintcOCustomStructgR_TClassManip(theClass);
   return theClass;
   }

   static void unordered_maplEintcOCustomStructgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_unordered_maplEintcOCustomStructgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_map<int,CustomStruct> : new unordered_map<int,CustomStruct>;
   }
   static void *newArray_unordered_maplEintcOCustomStructgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_map<int,CustomStruct>[nElements] : new unordered_map<int,CustomStruct>[nElements];
   }
   // Wrapper around operator delete
   static void delete_unordered_maplEintcOCustomStructgR(void *p) {
      delete (static_cast<unordered_map<int,CustomStruct>*>(p));
   }
   static void deleteArray_unordered_maplEintcOCustomStructgR(void *p) {
      delete [] (static_cast<unordered_map<int,CustomStruct>*>(p));
   }
   static void destruct_unordered_maplEintcOCustomStructgR(void *p) {
      typedef unordered_map<int,CustomStruct> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class unordered_map<int,CustomStruct>

namespace ROOT {
   static TClass *unordered_maplEfloatcOvectorlEboolgRsPgR_Dictionary();
   static void unordered_maplEfloatcOvectorlEboolgRsPgR_TClassManip(TClass*);
   static void *new_unordered_maplEfloatcOvectorlEboolgRsPgR(void *p = nullptr);
   static void *newArray_unordered_maplEfloatcOvectorlEboolgRsPgR(Long_t size, void *p);
   static void delete_unordered_maplEfloatcOvectorlEboolgRsPgR(void *p);
   static void deleteArray_unordered_maplEfloatcOvectorlEboolgRsPgR(void *p);
   static void destruct_unordered_maplEfloatcOvectorlEboolgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const unordered_map<float,vector<bool> >*)
   {
      unordered_map<float,vector<bool> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(unordered_map<float,vector<bool> >));
      static ::ROOT::TGenericClassInfo 
         instance("unordered_map<float,vector<bool> >", -2, "unordered_map", 1025,
                  typeid(unordered_map<float,vector<bool> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &unordered_maplEfloatcOvectorlEboolgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(unordered_map<float,vector<bool> >) );
      instance.SetNew(&new_unordered_maplEfloatcOvectorlEboolgRsPgR);
      instance.SetNewArray(&newArray_unordered_maplEfloatcOvectorlEboolgRsPgR);
      instance.SetDelete(&delete_unordered_maplEfloatcOvectorlEboolgRsPgR);
      instance.SetDeleteArray(&deleteArray_unordered_maplEfloatcOvectorlEboolgRsPgR);
      instance.SetDestructor(&destruct_unordered_maplEfloatcOvectorlEboolgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< unordered_map<float,vector<bool> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("unordered_map<float,vector<bool> >","std::__1::unordered_map<float, std::__1::vector<bool, std::__1::allocator<bool>>, std::__1::hash<float>, std::__1::equal_to<float>, std::__1::allocator<std::__1::pair<float const, std::__1::vector<bool, std::__1::allocator<bool>>>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const unordered_map<float,vector<bool> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *unordered_maplEfloatcOvectorlEboolgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const unordered_map<float,vector<bool> >*>(nullptr))->GetClass();
      unordered_maplEfloatcOvectorlEboolgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void unordered_maplEfloatcOvectorlEboolgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_unordered_maplEfloatcOvectorlEboolgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_map<float,vector<bool> > : new unordered_map<float,vector<bool> >;
   }
   static void *newArray_unordered_maplEfloatcOvectorlEboolgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_map<float,vector<bool> >[nElements] : new unordered_map<float,vector<bool> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_unordered_maplEfloatcOvectorlEboolgRsPgR(void *p) {
      delete (static_cast<unordered_map<float,vector<bool> >*>(p));
   }
   static void deleteArray_unordered_maplEfloatcOvectorlEboolgRsPgR(void *p) {
      delete [] (static_cast<unordered_map<float,vector<bool> >*>(p));
   }
   static void destruct_unordered_maplEfloatcOvectorlEboolgRsPgR(void *p) {
      typedef unordered_map<float,vector<bool> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class unordered_map<float,vector<bool> >

namespace ROOT {
   static TClass *unordered_maplEcharcOstringgR_Dictionary();
   static void unordered_maplEcharcOstringgR_TClassManip(TClass*);
   static void *new_unordered_maplEcharcOstringgR(void *p = nullptr);
   static void *newArray_unordered_maplEcharcOstringgR(Long_t size, void *p);
   static void delete_unordered_maplEcharcOstringgR(void *p);
   static void deleteArray_unordered_maplEcharcOstringgR(void *p);
   static void destruct_unordered_maplEcharcOstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const unordered_map<char,string>*)
   {
      unordered_map<char,string> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(unordered_map<char,string>));
      static ::ROOT::TGenericClassInfo 
         instance("unordered_map<char,string>", -2, "unordered_map", 1025,
                  typeid(unordered_map<char,string>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &unordered_maplEcharcOstringgR_Dictionary, isa_proxy, 4,
                  sizeof(unordered_map<char,string>) );
      instance.SetNew(&new_unordered_maplEcharcOstringgR);
      instance.SetNewArray(&newArray_unordered_maplEcharcOstringgR);
      instance.SetDelete(&delete_unordered_maplEcharcOstringgR);
      instance.SetDeleteArray(&deleteArray_unordered_maplEcharcOstringgR);
      instance.SetDestructor(&destruct_unordered_maplEcharcOstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< unordered_map<char,string> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("unordered_map<char,string>","std::__1::unordered_map<char, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>, std::__1::hash<char>, std::__1::equal_to<char>, std::__1::allocator<std::__1::pair<char const, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const unordered_map<char,string>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *unordered_maplEcharcOstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const unordered_map<char,string>*>(nullptr))->GetClass();
      unordered_maplEcharcOstringgR_TClassManip(theClass);
   return theClass;
   }

   static void unordered_maplEcharcOstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_unordered_maplEcharcOstringgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_map<char,string> : new unordered_map<char,string>;
   }
   static void *newArray_unordered_maplEcharcOstringgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_map<char,string>[nElements] : new unordered_map<char,string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_unordered_maplEcharcOstringgR(void *p) {
      delete (static_cast<unordered_map<char,string>*>(p));
   }
   static void deleteArray_unordered_maplEcharcOstringgR(void *p) {
      delete [] (static_cast<unordered_map<char,string>*>(p));
   }
   static void destruct_unordered_maplEcharcOstringgR(void *p) {
      typedef unordered_map<char,string> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class unordered_map<char,string>

namespace ROOT {
   static TClass *unordered_maplEcharcOlonggR_Dictionary();
   static void unordered_maplEcharcOlonggR_TClassManip(TClass*);
   static void *new_unordered_maplEcharcOlonggR(void *p = nullptr);
   static void *newArray_unordered_maplEcharcOlonggR(Long_t size, void *p);
   static void delete_unordered_maplEcharcOlonggR(void *p);
   static void deleteArray_unordered_maplEcharcOlonggR(void *p);
   static void destruct_unordered_maplEcharcOlonggR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const unordered_map<char,long>*)
   {
      unordered_map<char,long> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(unordered_map<char,long>));
      static ::ROOT::TGenericClassInfo 
         instance("unordered_map<char,long>", -2, "unordered_map", 1025,
                  typeid(unordered_map<char,long>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &unordered_maplEcharcOlonggR_Dictionary, isa_proxy, 4,
                  sizeof(unordered_map<char,long>) );
      instance.SetNew(&new_unordered_maplEcharcOlonggR);
      instance.SetNewArray(&newArray_unordered_maplEcharcOlonggR);
      instance.SetDelete(&delete_unordered_maplEcharcOlonggR);
      instance.SetDeleteArray(&deleteArray_unordered_maplEcharcOlonggR);
      instance.SetDestructor(&destruct_unordered_maplEcharcOlonggR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< unordered_map<char,long> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("unordered_map<char,long>","std::__1::unordered_map<char, long, std::__1::hash<char>, std::__1::equal_to<char>, std::__1::allocator<std::__1::pair<char const, long>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const unordered_map<char,long>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *unordered_maplEcharcOlonggR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const unordered_map<char,long>*>(nullptr))->GetClass();
      unordered_maplEcharcOlonggR_TClassManip(theClass);
   return theClass;
   }

   static void unordered_maplEcharcOlonggR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_unordered_maplEcharcOlonggR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_map<char,long> : new unordered_map<char,long>;
   }
   static void *newArray_unordered_maplEcharcOlonggR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_map<char,long>[nElements] : new unordered_map<char,long>[nElements];
   }
   // Wrapper around operator delete
   static void delete_unordered_maplEcharcOlonggR(void *p) {
      delete (static_cast<unordered_map<char,long>*>(p));
   }
   static void deleteArray_unordered_maplEcharcOlonggR(void *p) {
      delete [] (static_cast<unordered_map<char,long>*>(p));
   }
   static void destruct_unordered_maplEcharcOlonggR(void *p) {
      typedef unordered_map<char,long> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class unordered_map<char,long>

namespace ROOT {
   static TClass *unordered_maplEcharcOLong64_tgR_Dictionary();
   static void unordered_maplEcharcOLong64_tgR_TClassManip(TClass*);
   static void *new_unordered_maplEcharcOLong64_tgR(void *p = nullptr);
   static void *newArray_unordered_maplEcharcOLong64_tgR(Long_t size, void *p);
   static void delete_unordered_maplEcharcOLong64_tgR(void *p);
   static void deleteArray_unordered_maplEcharcOLong64_tgR(void *p);
   static void destruct_unordered_maplEcharcOLong64_tgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const unordered_map<char,Long64_t>*)
   {
      unordered_map<char,Long64_t> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(unordered_map<char,Long64_t>));
      static ::ROOT::TGenericClassInfo 
         instance("unordered_map<char,Long64_t>", -2, "unordered_map", 1025,
                  typeid(unordered_map<char,Long64_t>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &unordered_maplEcharcOLong64_tgR_Dictionary, isa_proxy, 4,
                  sizeof(unordered_map<char,Long64_t>) );
      instance.SetNew(&new_unordered_maplEcharcOLong64_tgR);
      instance.SetNewArray(&newArray_unordered_maplEcharcOLong64_tgR);
      instance.SetDelete(&delete_unordered_maplEcharcOLong64_tgR);
      instance.SetDeleteArray(&deleteArray_unordered_maplEcharcOLong64_tgR);
      instance.SetDestructor(&destruct_unordered_maplEcharcOLong64_tgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< unordered_map<char,Long64_t> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("unordered_map<char,Long64_t>","std::__1::unordered_map<char, long long, std::__1::hash<char>, std::__1::equal_to<char>, std::__1::allocator<std::__1::pair<char const, long long>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const unordered_map<char,Long64_t>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *unordered_maplEcharcOLong64_tgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const unordered_map<char,Long64_t>*>(nullptr))->GetClass();
      unordered_maplEcharcOLong64_tgR_TClassManip(theClass);
   return theClass;
   }

   static void unordered_maplEcharcOLong64_tgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_unordered_maplEcharcOLong64_tgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_map<char,Long64_t> : new unordered_map<char,Long64_t>;
   }
   static void *newArray_unordered_maplEcharcOLong64_tgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) unordered_map<char,Long64_t>[nElements] : new unordered_map<char,Long64_t>[nElements];
   }
   // Wrapper around operator delete
   static void delete_unordered_maplEcharcOLong64_tgR(void *p) {
      delete (static_cast<unordered_map<char,Long64_t>*>(p));
   }
   static void deleteArray_unordered_maplEcharcOLong64_tgR(void *p) {
      delete [] (static_cast<unordered_map<char,Long64_t>*>(p));
   }
   static void destruct_unordered_maplEcharcOLong64_tgR(void *p) {
      typedef unordered_map<char,Long64_t> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class unordered_map<char,Long64_t>

namespace ROOT {
   static TClass *setlEtuplelEintcOcharcOCustomStructgRsPgR_Dictionary();
   static void setlEtuplelEintcOcharcOCustomStructgRsPgR_TClassManip(TClass*);
   static void *new_setlEtuplelEintcOcharcOCustomStructgRsPgR(void *p = nullptr);
   static void *newArray_setlEtuplelEintcOcharcOCustomStructgRsPgR(Long_t size, void *p);
   static void delete_setlEtuplelEintcOcharcOCustomStructgRsPgR(void *p);
   static void deleteArray_setlEtuplelEintcOcharcOCustomStructgRsPgR(void *p);
   static void destruct_setlEtuplelEintcOcharcOCustomStructgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const set<tuple<int,char,CustomStruct> >*)
   {
      set<tuple<int,char,CustomStruct> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(set<tuple<int,char,CustomStruct> >));
      static ::ROOT::TGenericClassInfo 
         instance("set<tuple<int,char,CustomStruct> >", -2, "set", 515,
                  typeid(set<tuple<int,char,CustomStruct> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &setlEtuplelEintcOcharcOCustomStructgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(set<tuple<int,char,CustomStruct> >) );
      instance.SetNew(&new_setlEtuplelEintcOcharcOCustomStructgRsPgR);
      instance.SetNewArray(&newArray_setlEtuplelEintcOcharcOCustomStructgRsPgR);
      instance.SetDelete(&delete_setlEtuplelEintcOcharcOCustomStructgRsPgR);
      instance.SetDeleteArray(&deleteArray_setlEtuplelEintcOcharcOCustomStructgRsPgR);
      instance.SetDestructor(&destruct_setlEtuplelEintcOcharcOCustomStructgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< set<tuple<int,char,CustomStruct> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("set<tuple<int,char,CustomStruct> >","std::__1::set<std::__1::tuple<int, char, CustomStruct>, std::__1::less<std::__1::tuple<int, char, CustomStruct>>, std::__1::allocator<std::__1::tuple<int, char, CustomStruct>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const set<tuple<int,char,CustomStruct> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *setlEtuplelEintcOcharcOCustomStructgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const set<tuple<int,char,CustomStruct> >*>(nullptr))->GetClass();
      setlEtuplelEintcOcharcOCustomStructgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void setlEtuplelEintcOcharcOCustomStructgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_setlEtuplelEintcOcharcOCustomStructgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) set<tuple<int,char,CustomStruct> > : new set<tuple<int,char,CustomStruct> >;
   }
   static void *newArray_setlEtuplelEintcOcharcOCustomStructgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) set<tuple<int,char,CustomStruct> >[nElements] : new set<tuple<int,char,CustomStruct> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_setlEtuplelEintcOcharcOCustomStructgRsPgR(void *p) {
      delete (static_cast<set<tuple<int,char,CustomStruct> >*>(p));
   }
   static void deleteArray_setlEtuplelEintcOcharcOCustomStructgRsPgR(void *p) {
      delete [] (static_cast<set<tuple<int,char,CustomStruct> >*>(p));
   }
   static void destruct_setlEtuplelEintcOcharcOCustomStructgRsPgR(void *p) {
      typedef set<tuple<int,char,CustomStruct> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class set<tuple<int,char,CustomStruct> >

namespace ROOT {
   static TClass *setlEstringgR_Dictionary();
   static void setlEstringgR_TClassManip(TClass*);
   static void *new_setlEstringgR(void *p = nullptr);
   static void *newArray_setlEstringgR(Long_t size, void *p);
   static void delete_setlEstringgR(void *p);
   static void deleteArray_setlEstringgR(void *p);
   static void destruct_setlEstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const set<string>*)
   {
      set<string> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(set<string>));
      static ::ROOT::TGenericClassInfo 
         instance("set<string>", -2, "set", 515,
                  typeid(set<string>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &setlEstringgR_Dictionary, isa_proxy, 4,
                  sizeof(set<string>) );
      instance.SetNew(&new_setlEstringgR);
      instance.SetNewArray(&newArray_setlEstringgR);
      instance.SetDelete(&delete_setlEstringgR);
      instance.SetDeleteArray(&deleteArray_setlEstringgR);
      instance.SetDestructor(&destruct_setlEstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< set<string> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("set<string>","std::__1::set<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>, std::__1::less<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>>, std::__1::allocator<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const set<string>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *setlEstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const set<string>*>(nullptr))->GetClass();
      setlEstringgR_TClassManip(theClass);
   return theClass;
   }

   static void setlEstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_setlEstringgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) set<string> : new set<string>;
   }
   static void *newArray_setlEstringgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) set<string>[nElements] : new set<string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_setlEstringgR(void *p) {
      delete (static_cast<set<string>*>(p));
   }
   static void deleteArray_setlEstringgR(void *p) {
      delete [] (static_cast<set<string>*>(p));
   }
   static void destruct_setlEstringgR(void *p) {
      typedef set<string> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class set<string>

namespace ROOT {
   static TClass *setlEsetlEchargRsPgR_Dictionary();
   static void setlEsetlEchargRsPgR_TClassManip(TClass*);
   static void *new_setlEsetlEchargRsPgR(void *p = nullptr);
   static void *newArray_setlEsetlEchargRsPgR(Long_t size, void *p);
   static void delete_setlEsetlEchargRsPgR(void *p);
   static void deleteArray_setlEsetlEchargRsPgR(void *p);
   static void destruct_setlEsetlEchargRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const set<set<char> >*)
   {
      set<set<char> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(set<set<char> >));
      static ::ROOT::TGenericClassInfo 
         instance("set<set<char> >", -2, "set", 515,
                  typeid(set<set<char> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &setlEsetlEchargRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(set<set<char> >) );
      instance.SetNew(&new_setlEsetlEchargRsPgR);
      instance.SetNewArray(&newArray_setlEsetlEchargRsPgR);
      instance.SetDelete(&delete_setlEsetlEchargRsPgR);
      instance.SetDeleteArray(&deleteArray_setlEsetlEchargRsPgR);
      instance.SetDestructor(&destruct_setlEsetlEchargRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< set<set<char> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("set<set<char> >","std::__1::set<std::__1::set<char, std::__1::less<char>, std::__1::allocator<char>>, std::__1::less<std::__1::set<char, std::__1::less<char>, std::__1::allocator<char>>>, std::__1::allocator<std::__1::set<char, std::__1::less<char>, std::__1::allocator<char>>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const set<set<char> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *setlEsetlEchargRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const set<set<char> >*>(nullptr))->GetClass();
      setlEsetlEchargRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void setlEsetlEchargRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_setlEsetlEchargRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) set<set<char> > : new set<set<char> >;
   }
   static void *newArray_setlEsetlEchargRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) set<set<char> >[nElements] : new set<set<char> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_setlEsetlEchargRsPgR(void *p) {
      delete (static_cast<set<set<char> >*>(p));
   }
   static void deleteArray_setlEsetlEchargRsPgR(void *p) {
      delete [] (static_cast<set<set<char> >*>(p));
   }
   static void destruct_setlEsetlEchargRsPgR(void *p) {
      typedef set<set<char> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class set<set<char> >

namespace ROOT {
   static TClass *setlEsetlECustomStructgRsPgR_Dictionary();
   static void setlEsetlECustomStructgRsPgR_TClassManip(TClass*);
   static void *new_setlEsetlECustomStructgRsPgR(void *p = nullptr);
   static void *newArray_setlEsetlECustomStructgRsPgR(Long_t size, void *p);
   static void delete_setlEsetlECustomStructgRsPgR(void *p);
   static void deleteArray_setlEsetlECustomStructgRsPgR(void *p);
   static void destruct_setlEsetlECustomStructgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const set<set<CustomStruct> >*)
   {
      set<set<CustomStruct> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(set<set<CustomStruct> >));
      static ::ROOT::TGenericClassInfo 
         instance("set<set<CustomStruct> >", -2, "set", 515,
                  typeid(set<set<CustomStruct> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &setlEsetlECustomStructgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(set<set<CustomStruct> >) );
      instance.SetNew(&new_setlEsetlECustomStructgRsPgR);
      instance.SetNewArray(&newArray_setlEsetlECustomStructgRsPgR);
      instance.SetDelete(&delete_setlEsetlECustomStructgRsPgR);
      instance.SetDeleteArray(&deleteArray_setlEsetlECustomStructgRsPgR);
      instance.SetDestructor(&destruct_setlEsetlECustomStructgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< set<set<CustomStruct> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("set<set<CustomStruct> >","std::__1::set<std::__1::set<CustomStruct, std::__1::less<CustomStruct>, std::__1::allocator<CustomStruct>>, std::__1::less<std::__1::set<CustomStruct, std::__1::less<CustomStruct>, std::__1::allocator<CustomStruct>>>, std::__1::allocator<std::__1::set<CustomStruct, std::__1::less<CustomStruct>, std::__1::allocator<CustomStruct>>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const set<set<CustomStruct> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *setlEsetlECustomStructgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const set<set<CustomStruct> >*>(nullptr))->GetClass();
      setlEsetlECustomStructgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void setlEsetlECustomStructgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_setlEsetlECustomStructgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) set<set<CustomStruct> > : new set<set<CustomStruct> >;
   }
   static void *newArray_setlEsetlECustomStructgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) set<set<CustomStruct> >[nElements] : new set<set<CustomStruct> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_setlEsetlECustomStructgRsPgR(void *p) {
      delete (static_cast<set<set<CustomStruct> >*>(p));
   }
   static void deleteArray_setlEsetlECustomStructgRsPgR(void *p) {
      delete [] (static_cast<set<set<CustomStruct> >*>(p));
   }
   static void destruct_setlEsetlECustomStructgRsPgR(void *p) {
      typedef set<set<CustomStruct> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class set<set<CustomStruct> >

namespace ROOT {
   static TClass *setlEfloatgR_Dictionary();
   static void setlEfloatgR_TClassManip(TClass*);
   static void *new_setlEfloatgR(void *p = nullptr);
   static void *newArray_setlEfloatgR(Long_t size, void *p);
   static void delete_setlEfloatgR(void *p);
   static void deleteArray_setlEfloatgR(void *p);
   static void destruct_setlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const set<float>*)
   {
      set<float> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(set<float>));
      static ::ROOT::TGenericClassInfo 
         instance("set<float>", -2, "set", 515,
                  typeid(set<float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &setlEfloatgR_Dictionary, isa_proxy, 4,
                  sizeof(set<float>) );
      instance.SetNew(&new_setlEfloatgR);
      instance.SetNewArray(&newArray_setlEfloatgR);
      instance.SetDelete(&delete_setlEfloatgR);
      instance.SetDeleteArray(&deleteArray_setlEfloatgR);
      instance.SetDestructor(&destruct_setlEfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< set<float> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("set<float>","std::__1::set<float, std::__1::less<float>, std::__1::allocator<float>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const set<float>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *setlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const set<float>*>(nullptr))->GetClass();
      setlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void setlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_setlEfloatgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) set<float> : new set<float>;
   }
   static void *newArray_setlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) set<float>[nElements] : new set<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_setlEfloatgR(void *p) {
      delete (static_cast<set<float>*>(p));
   }
   static void deleteArray_setlEfloatgR(void *p) {
      delete [] (static_cast<set<float>*>(p));
   }
   static void destruct_setlEfloatgR(void *p) {
      typedef set<float> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class set<float>

namespace ROOT {
   static TClass *setlEchargR_Dictionary();
   static void setlEchargR_TClassManip(TClass*);
   static void *new_setlEchargR(void *p = nullptr);
   static void *newArray_setlEchargR(Long_t size, void *p);
   static void delete_setlEchargR(void *p);
   static void deleteArray_setlEchargR(void *p);
   static void destruct_setlEchargR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const set<char>*)
   {
      set<char> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(set<char>));
      static ::ROOT::TGenericClassInfo 
         instance("set<char>", -2, "set", 515,
                  typeid(set<char>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &setlEchargR_Dictionary, isa_proxy, 4,
                  sizeof(set<char>) );
      instance.SetNew(&new_setlEchargR);
      instance.SetNewArray(&newArray_setlEchargR);
      instance.SetDelete(&delete_setlEchargR);
      instance.SetDeleteArray(&deleteArray_setlEchargR);
      instance.SetDestructor(&destruct_setlEchargR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< set<char> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("set<char>","std::__1::set<char, std::__1::less<char>, std::__1::allocator<char>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const set<char>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *setlEchargR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const set<char>*>(nullptr))->GetClass();
      setlEchargR_TClassManip(theClass);
   return theClass;
   }

   static void setlEchargR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_setlEchargR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) set<char> : new set<char>;
   }
   static void *newArray_setlEchargR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) set<char>[nElements] : new set<char>[nElements];
   }
   // Wrapper around operator delete
   static void delete_setlEchargR(void *p) {
      delete (static_cast<set<char>*>(p));
   }
   static void deleteArray_setlEchargR(void *p) {
      delete [] (static_cast<set<char>*>(p));
   }
   static void destruct_setlEchargR(void *p) {
      typedef set<char> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class set<char>

namespace ROOT {
   static TClass *setlELong64_tgR_Dictionary();
   static void setlELong64_tgR_TClassManip(TClass*);
   static void *new_setlELong64_tgR(void *p = nullptr);
   static void *newArray_setlELong64_tgR(Long_t size, void *p);
   static void delete_setlELong64_tgR(void *p);
   static void deleteArray_setlELong64_tgR(void *p);
   static void destruct_setlELong64_tgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const set<Long64_t>*)
   {
      set<Long64_t> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(set<Long64_t>));
      static ::ROOT::TGenericClassInfo 
         instance("set<Long64_t>", -2, "set", 515,
                  typeid(set<Long64_t>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &setlELong64_tgR_Dictionary, isa_proxy, 4,
                  sizeof(set<Long64_t>) );
      instance.SetNew(&new_setlELong64_tgR);
      instance.SetNewArray(&newArray_setlELong64_tgR);
      instance.SetDelete(&delete_setlELong64_tgR);
      instance.SetDeleteArray(&deleteArray_setlELong64_tgR);
      instance.SetDestructor(&destruct_setlELong64_tgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< set<Long64_t> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("set<Long64_t>","std::__1::set<long long, std::__1::less<long long>, std::__1::allocator<long long>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const set<Long64_t>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *setlELong64_tgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const set<Long64_t>*>(nullptr))->GetClass();
      setlELong64_tgR_TClassManip(theClass);
   return theClass;
   }

   static void setlELong64_tgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_setlELong64_tgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) set<Long64_t> : new set<Long64_t>;
   }
   static void *newArray_setlELong64_tgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) set<Long64_t>[nElements] : new set<Long64_t>[nElements];
   }
   // Wrapper around operator delete
   static void delete_setlELong64_tgR(void *p) {
      delete (static_cast<set<Long64_t>*>(p));
   }
   static void deleteArray_setlELong64_tgR(void *p) {
      delete [] (static_cast<set<Long64_t>*>(p));
   }
   static void destruct_setlELong64_tgR(void *p) {
      typedef set<Long64_t> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class set<Long64_t>

namespace ROOT {
   static TClass *setlECustomStructgR_Dictionary();
   static void setlECustomStructgR_TClassManip(TClass*);
   static void *new_setlECustomStructgR(void *p = nullptr);
   static void *newArray_setlECustomStructgR(Long_t size, void *p);
   static void delete_setlECustomStructgR(void *p);
   static void deleteArray_setlECustomStructgR(void *p);
   static void destruct_setlECustomStructgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const set<CustomStruct>*)
   {
      set<CustomStruct> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(set<CustomStruct>));
      static ::ROOT::TGenericClassInfo 
         instance("set<CustomStruct>", -2, "set", 515,
                  typeid(set<CustomStruct>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &setlECustomStructgR_Dictionary, isa_proxy, 4,
                  sizeof(set<CustomStruct>) );
      instance.SetNew(&new_setlECustomStructgR);
      instance.SetNewArray(&newArray_setlECustomStructgR);
      instance.SetDelete(&delete_setlECustomStructgR);
      instance.SetDeleteArray(&deleteArray_setlECustomStructgR);
      instance.SetDestructor(&destruct_setlECustomStructgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< set<CustomStruct> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("set<CustomStruct>","std::__1::set<CustomStruct, std::__1::less<CustomStruct>, std::__1::allocator<CustomStruct>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const set<CustomStruct>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *setlECustomStructgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const set<CustomStruct>*>(nullptr))->GetClass();
      setlECustomStructgR_TClassManip(theClass);
   return theClass;
   }

   static void setlECustomStructgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_setlECustomStructgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) set<CustomStruct> : new set<CustomStruct>;
   }
   static void *newArray_setlECustomStructgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) set<CustomStruct>[nElements] : new set<CustomStruct>[nElements];
   }
   // Wrapper around operator delete
   static void delete_setlECustomStructgR(void *p) {
      delete (static_cast<set<CustomStruct>*>(p));
   }
   static void deleteArray_setlECustomStructgR(void *p) {
      delete [] (static_cast<set<CustomStruct>*>(p));
   }
   static void destruct_setlECustomStructgR(void *p) {
      typedef set<CustomStruct> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class set<CustomStruct>

namespace ROOT {
   static TClass *maplEstringcOfloatgR_Dictionary();
   static void maplEstringcOfloatgR_TClassManip(TClass*);
   static void *new_maplEstringcOfloatgR(void *p = nullptr);
   static void *newArray_maplEstringcOfloatgR(Long_t size, void *p);
   static void delete_maplEstringcOfloatgR(void *p);
   static void deleteArray_maplEstringcOfloatgR(void *p);
   static void destruct_maplEstringcOfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,float>*)
   {
      map<string,float> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,float>));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,float>", -2, "map", 969,
                  typeid(map<string,float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEstringcOfloatgR_Dictionary, isa_proxy, 4,
                  sizeof(map<string,float>) );
      instance.SetNew(&new_maplEstringcOfloatgR);
      instance.SetNewArray(&newArray_maplEstringcOfloatgR);
      instance.SetDelete(&delete_maplEstringcOfloatgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOfloatgR);
      instance.SetDestructor(&destruct_maplEstringcOfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,float> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("map<string,float>","std::__1::map<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>, float, std::__1::less<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>>, std::__1::allocator<std::__1::pair<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> const, float>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<string,float>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<string,float>*>(nullptr))->GetClass();
      maplEstringcOfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOfloatgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<string,float> : new map<string,float>;
   }
   static void *newArray_maplEstringcOfloatgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<string,float>[nElements] : new map<string,float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOfloatgR(void *p) {
      delete (static_cast<map<string,float>*>(p));
   }
   static void deleteArray_maplEstringcOfloatgR(void *p) {
      delete [] (static_cast<map<string,float>*>(p));
   }
   static void destruct_maplEstringcOfloatgR(void *p) {
      typedef map<string,float> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<string,float>

namespace ROOT {
   static TClass *maplEintcOvectorlECustomStructgRsPgR_Dictionary();
   static void maplEintcOvectorlECustomStructgRsPgR_TClassManip(TClass*);
   static void *new_maplEintcOvectorlECustomStructgRsPgR(void *p = nullptr);
   static void *newArray_maplEintcOvectorlECustomStructgRsPgR(Long_t size, void *p);
   static void delete_maplEintcOvectorlECustomStructgRsPgR(void *p);
   static void deleteArray_maplEintcOvectorlECustomStructgRsPgR(void *p);
   static void destruct_maplEintcOvectorlECustomStructgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,vector<CustomStruct> >*)
   {
      map<int,vector<CustomStruct> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,vector<CustomStruct> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<int,vector<CustomStruct> >", -2, "map", 969,
                  typeid(map<int,vector<CustomStruct> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEintcOvectorlECustomStructgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(map<int,vector<CustomStruct> >) );
      instance.SetNew(&new_maplEintcOvectorlECustomStructgRsPgR);
      instance.SetNewArray(&newArray_maplEintcOvectorlECustomStructgRsPgR);
      instance.SetDelete(&delete_maplEintcOvectorlECustomStructgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEintcOvectorlECustomStructgRsPgR);
      instance.SetDestructor(&destruct_maplEintcOvectorlECustomStructgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,vector<CustomStruct> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("map<int,vector<CustomStruct> >","std::__1::map<int, std::__1::vector<CustomStruct, std::__1::allocator<CustomStruct>>, std::__1::less<int>, std::__1::allocator<std::__1::pair<int const, std::__1::vector<CustomStruct, std::__1::allocator<CustomStruct>>>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<int,vector<CustomStruct> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOvectorlECustomStructgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<int,vector<CustomStruct> >*>(nullptr))->GetClass();
      maplEintcOvectorlECustomStructgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOvectorlECustomStructgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOvectorlECustomStructgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<int,vector<CustomStruct> > : new map<int,vector<CustomStruct> >;
   }
   static void *newArray_maplEintcOvectorlECustomStructgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<int,vector<CustomStruct> >[nElements] : new map<int,vector<CustomStruct> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOvectorlECustomStructgRsPgR(void *p) {
      delete (static_cast<map<int,vector<CustomStruct> >*>(p));
   }
   static void deleteArray_maplEintcOvectorlECustomStructgRsPgR(void *p) {
      delete [] (static_cast<map<int,vector<CustomStruct> >*>(p));
   }
   static void destruct_maplEintcOvectorlECustomStructgRsPgR(void *p) {
      typedef map<int,vector<CustomStruct> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<int,vector<CustomStruct> >

namespace ROOT {
   static TClass *maplEintcOCustomStructgR_Dictionary();
   static void maplEintcOCustomStructgR_TClassManip(TClass*);
   static void *new_maplEintcOCustomStructgR(void *p = nullptr);
   static void *newArray_maplEintcOCustomStructgR(Long_t size, void *p);
   static void delete_maplEintcOCustomStructgR(void *p);
   static void deleteArray_maplEintcOCustomStructgR(void *p);
   static void destruct_maplEintcOCustomStructgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,CustomStruct>*)
   {
      map<int,CustomStruct> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,CustomStruct>));
      static ::ROOT::TGenericClassInfo 
         instance("map<int,CustomStruct>", -2, "map", 969,
                  typeid(map<int,CustomStruct>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEintcOCustomStructgR_Dictionary, isa_proxy, 4,
                  sizeof(map<int,CustomStruct>) );
      instance.SetNew(&new_maplEintcOCustomStructgR);
      instance.SetNewArray(&newArray_maplEintcOCustomStructgR);
      instance.SetDelete(&delete_maplEintcOCustomStructgR);
      instance.SetDeleteArray(&deleteArray_maplEintcOCustomStructgR);
      instance.SetDestructor(&destruct_maplEintcOCustomStructgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,CustomStruct> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("map<int,CustomStruct>","std::__1::map<int, CustomStruct, std::__1::less<int>, std::__1::allocator<std::__1::pair<int const, CustomStruct>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<int,CustomStruct>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOCustomStructgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<int,CustomStruct>*>(nullptr))->GetClass();
      maplEintcOCustomStructgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOCustomStructgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOCustomStructgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<int,CustomStruct> : new map<int,CustomStruct>;
   }
   static void *newArray_maplEintcOCustomStructgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<int,CustomStruct>[nElements] : new map<int,CustomStruct>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOCustomStructgR(void *p) {
      delete (static_cast<map<int,CustomStruct>*>(p));
   }
   static void deleteArray_maplEintcOCustomStructgR(void *p) {
      delete [] (static_cast<map<int,CustomStruct>*>(p));
   }
   static void destruct_maplEintcOCustomStructgR(void *p) {
      typedef map<int,CustomStruct> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<int,CustomStruct>

namespace ROOT {
   static TClass *maplEfloatcOmaplEcharcOintgRsPgR_Dictionary();
   static void maplEfloatcOmaplEcharcOintgRsPgR_TClassManip(TClass*);
   static void *new_maplEfloatcOmaplEcharcOintgRsPgR(void *p = nullptr);
   static void *newArray_maplEfloatcOmaplEcharcOintgRsPgR(Long_t size, void *p);
   static void delete_maplEfloatcOmaplEcharcOintgRsPgR(void *p);
   static void deleteArray_maplEfloatcOmaplEcharcOintgRsPgR(void *p);
   static void destruct_maplEfloatcOmaplEcharcOintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<float,map<char,int> >*)
   {
      map<float,map<char,int> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<float,map<char,int> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<float,map<char,int> >", -2, "map", 969,
                  typeid(map<float,map<char,int> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEfloatcOmaplEcharcOintgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(map<float,map<char,int> >) );
      instance.SetNew(&new_maplEfloatcOmaplEcharcOintgRsPgR);
      instance.SetNewArray(&newArray_maplEfloatcOmaplEcharcOintgRsPgR);
      instance.SetDelete(&delete_maplEfloatcOmaplEcharcOintgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEfloatcOmaplEcharcOintgRsPgR);
      instance.SetDestructor(&destruct_maplEfloatcOmaplEcharcOintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<float,map<char,int> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("map<float,map<char,int> >","std::__1::map<float, std::__1::map<char, int, std::__1::less<char>, std::__1::allocator<std::__1::pair<char const, int>>>, std::__1::less<float>, std::__1::allocator<std::__1::pair<float const, std::__1::map<char, int, std::__1::less<char>, std::__1::allocator<std::__1::pair<char const, int>>>>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<float,map<char,int> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEfloatcOmaplEcharcOintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<float,map<char,int> >*>(nullptr))->GetClass();
      maplEfloatcOmaplEcharcOintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEfloatcOmaplEcharcOintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEfloatcOmaplEcharcOintgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<float,map<char,int> > : new map<float,map<char,int> >;
   }
   static void *newArray_maplEfloatcOmaplEcharcOintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<float,map<char,int> >[nElements] : new map<float,map<char,int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEfloatcOmaplEcharcOintgRsPgR(void *p) {
      delete (static_cast<map<float,map<char,int> >*>(p));
   }
   static void deleteArray_maplEfloatcOmaplEcharcOintgRsPgR(void *p) {
      delete [] (static_cast<map<float,map<char,int> >*>(p));
   }
   static void destruct_maplEfloatcOmaplEcharcOintgRsPgR(void *p) {
      typedef map<float,map<char,int> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<float,map<char,int> >

namespace ROOT {
   static TClass *maplEcharcOstringgR_Dictionary();
   static void maplEcharcOstringgR_TClassManip(TClass*);
   static void *new_maplEcharcOstringgR(void *p = nullptr);
   static void *newArray_maplEcharcOstringgR(Long_t size, void *p);
   static void delete_maplEcharcOstringgR(void *p);
   static void deleteArray_maplEcharcOstringgR(void *p);
   static void destruct_maplEcharcOstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<char,string>*)
   {
      map<char,string> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<char,string>));
      static ::ROOT::TGenericClassInfo 
         instance("map<char,string>", -2, "map", 969,
                  typeid(map<char,string>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEcharcOstringgR_Dictionary, isa_proxy, 4,
                  sizeof(map<char,string>) );
      instance.SetNew(&new_maplEcharcOstringgR);
      instance.SetNewArray(&newArray_maplEcharcOstringgR);
      instance.SetDelete(&delete_maplEcharcOstringgR);
      instance.SetDeleteArray(&deleteArray_maplEcharcOstringgR);
      instance.SetDestructor(&destruct_maplEcharcOstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<char,string> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("map<char,string>","std::__1::map<char, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>, std::__1::less<char>, std::__1::allocator<std::__1::pair<char const, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<char,string>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEcharcOstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<char,string>*>(nullptr))->GetClass();
      maplEcharcOstringgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEcharcOstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEcharcOstringgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<char,string> : new map<char,string>;
   }
   static void *newArray_maplEcharcOstringgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<char,string>[nElements] : new map<char,string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEcharcOstringgR(void *p) {
      delete (static_cast<map<char,string>*>(p));
   }
   static void deleteArray_maplEcharcOstringgR(void *p) {
      delete [] (static_cast<map<char,string>*>(p));
   }
   static void destruct_maplEcharcOstringgR(void *p) {
      typedef map<char,string> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<char,string>

namespace ROOT {
   static TClass *maplEcharcOmaplEintcOCustomStructgRsPgR_Dictionary();
   static void maplEcharcOmaplEintcOCustomStructgRsPgR_TClassManip(TClass*);
   static void *new_maplEcharcOmaplEintcOCustomStructgRsPgR(void *p = nullptr);
   static void *newArray_maplEcharcOmaplEintcOCustomStructgRsPgR(Long_t size, void *p);
   static void delete_maplEcharcOmaplEintcOCustomStructgRsPgR(void *p);
   static void deleteArray_maplEcharcOmaplEintcOCustomStructgRsPgR(void *p);
   static void destruct_maplEcharcOmaplEintcOCustomStructgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<char,map<int,CustomStruct> >*)
   {
      map<char,map<int,CustomStruct> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<char,map<int,CustomStruct> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<char,map<int,CustomStruct> >", -2, "map", 969,
                  typeid(map<char,map<int,CustomStruct> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEcharcOmaplEintcOCustomStructgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(map<char,map<int,CustomStruct> >) );
      instance.SetNew(&new_maplEcharcOmaplEintcOCustomStructgRsPgR);
      instance.SetNewArray(&newArray_maplEcharcOmaplEintcOCustomStructgRsPgR);
      instance.SetDelete(&delete_maplEcharcOmaplEintcOCustomStructgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEcharcOmaplEintcOCustomStructgRsPgR);
      instance.SetDestructor(&destruct_maplEcharcOmaplEintcOCustomStructgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<char,map<int,CustomStruct> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("map<char,map<int,CustomStruct> >","std::__1::map<char, std::__1::map<int, CustomStruct, std::__1::less<int>, std::__1::allocator<std::__1::pair<int const, CustomStruct>>>, std::__1::less<char>, std::__1::allocator<std::__1::pair<char const, std::__1::map<int, CustomStruct, std::__1::less<int>, std::__1::allocator<std::__1::pair<int const, CustomStruct>>>>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<char,map<int,CustomStruct> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEcharcOmaplEintcOCustomStructgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<char,map<int,CustomStruct> >*>(nullptr))->GetClass();
      maplEcharcOmaplEintcOCustomStructgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEcharcOmaplEintcOCustomStructgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEcharcOmaplEintcOCustomStructgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<char,map<int,CustomStruct> > : new map<char,map<int,CustomStruct> >;
   }
   static void *newArray_maplEcharcOmaplEintcOCustomStructgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<char,map<int,CustomStruct> >[nElements] : new map<char,map<int,CustomStruct> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEcharcOmaplEintcOCustomStructgRsPgR(void *p) {
      delete (static_cast<map<char,map<int,CustomStruct> >*>(p));
   }
   static void deleteArray_maplEcharcOmaplEintcOCustomStructgRsPgR(void *p) {
      delete [] (static_cast<map<char,map<int,CustomStruct> >*>(p));
   }
   static void destruct_maplEcharcOmaplEintcOCustomStructgRsPgR(void *p) {
      typedef map<char,map<int,CustomStruct> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<char,map<int,CustomStruct> >

namespace ROOT {
   static TClass *maplEcharcOlonggR_Dictionary();
   static void maplEcharcOlonggR_TClassManip(TClass*);
   static void *new_maplEcharcOlonggR(void *p = nullptr);
   static void *newArray_maplEcharcOlonggR(Long_t size, void *p);
   static void delete_maplEcharcOlonggR(void *p);
   static void deleteArray_maplEcharcOlonggR(void *p);
   static void destruct_maplEcharcOlonggR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<char,long>*)
   {
      map<char,long> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<char,long>));
      static ::ROOT::TGenericClassInfo 
         instance("map<char,long>", -2, "map", 969,
                  typeid(map<char,long>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEcharcOlonggR_Dictionary, isa_proxy, 4,
                  sizeof(map<char,long>) );
      instance.SetNew(&new_maplEcharcOlonggR);
      instance.SetNewArray(&newArray_maplEcharcOlonggR);
      instance.SetDelete(&delete_maplEcharcOlonggR);
      instance.SetDeleteArray(&deleteArray_maplEcharcOlonggR);
      instance.SetDestructor(&destruct_maplEcharcOlonggR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<char,long> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("map<char,long>","std::__1::map<char, long, std::__1::less<char>, std::__1::allocator<std::__1::pair<char const, long>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<char,long>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEcharcOlonggR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<char,long>*>(nullptr))->GetClass();
      maplEcharcOlonggR_TClassManip(theClass);
   return theClass;
   }

   static void maplEcharcOlonggR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEcharcOlonggR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<char,long> : new map<char,long>;
   }
   static void *newArray_maplEcharcOlonggR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<char,long>[nElements] : new map<char,long>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEcharcOlonggR(void *p) {
      delete (static_cast<map<char,long>*>(p));
   }
   static void deleteArray_maplEcharcOlonggR(void *p) {
      delete [] (static_cast<map<char,long>*>(p));
   }
   static void destruct_maplEcharcOlonggR(void *p) {
      typedef map<char,long> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<char,long>

namespace ROOT {
   static TClass *maplEcharcOintgR_Dictionary();
   static void maplEcharcOintgR_TClassManip(TClass*);
   static void *new_maplEcharcOintgR(void *p = nullptr);
   static void *newArray_maplEcharcOintgR(Long_t size, void *p);
   static void delete_maplEcharcOintgR(void *p);
   static void deleteArray_maplEcharcOintgR(void *p);
   static void destruct_maplEcharcOintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<char,int>*)
   {
      map<char,int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<char,int>));
      static ::ROOT::TGenericClassInfo 
         instance("map<char,int>", -2, "map", 969,
                  typeid(map<char,int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEcharcOintgR_Dictionary, isa_proxy, 4,
                  sizeof(map<char,int>) );
      instance.SetNew(&new_maplEcharcOintgR);
      instance.SetNewArray(&newArray_maplEcharcOintgR);
      instance.SetDelete(&delete_maplEcharcOintgR);
      instance.SetDeleteArray(&deleteArray_maplEcharcOintgR);
      instance.SetDestructor(&destruct_maplEcharcOintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<char,int> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("map<char,int>","std::__1::map<char, int, std::__1::less<char>, std::__1::allocator<std::__1::pair<char const, int>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<char,int>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEcharcOintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<char,int>*>(nullptr))->GetClass();
      maplEcharcOintgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEcharcOintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEcharcOintgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<char,int> : new map<char,int>;
   }
   static void *newArray_maplEcharcOintgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<char,int>[nElements] : new map<char,int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEcharcOintgR(void *p) {
      delete (static_cast<map<char,int>*>(p));
   }
   static void deleteArray_maplEcharcOintgR(void *p) {
      delete [] (static_cast<map<char,int>*>(p));
   }
   static void destruct_maplEcharcOintgR(void *p) {
      typedef map<char,int> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<char,int>

namespace ROOT {
   static TClass *maplEcharcOLong64_tgR_Dictionary();
   static void maplEcharcOLong64_tgR_TClassManip(TClass*);
   static void *new_maplEcharcOLong64_tgR(void *p = nullptr);
   static void *newArray_maplEcharcOLong64_tgR(Long_t size, void *p);
   static void delete_maplEcharcOLong64_tgR(void *p);
   static void deleteArray_maplEcharcOLong64_tgR(void *p);
   static void destruct_maplEcharcOLong64_tgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<char,Long64_t>*)
   {
      map<char,Long64_t> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<char,Long64_t>));
      static ::ROOT::TGenericClassInfo 
         instance("map<char,Long64_t>", -2, "map", 969,
                  typeid(map<char,Long64_t>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEcharcOLong64_tgR_Dictionary, isa_proxy, 4,
                  sizeof(map<char,Long64_t>) );
      instance.SetNew(&new_maplEcharcOLong64_tgR);
      instance.SetNewArray(&newArray_maplEcharcOLong64_tgR);
      instance.SetDelete(&delete_maplEcharcOLong64_tgR);
      instance.SetDeleteArray(&deleteArray_maplEcharcOLong64_tgR);
      instance.SetDestructor(&destruct_maplEcharcOLong64_tgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<char,Long64_t> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("map<char,Long64_t>","std::__1::map<char, long long, std::__1::less<char>, std::__1::allocator<std::__1::pair<char const, long long>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<char,Long64_t>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEcharcOLong64_tgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<char,Long64_t>*>(nullptr))->GetClass();
      maplEcharcOLong64_tgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEcharcOLong64_tgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEcharcOLong64_tgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<char,Long64_t> : new map<char,Long64_t>;
   }
   static void *newArray_maplEcharcOLong64_tgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<char,Long64_t>[nElements] : new map<char,Long64_t>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEcharcOLong64_tgR(void *p) {
      delete (static_cast<map<char,Long64_t>*>(p));
   }
   static void deleteArray_maplEcharcOLong64_tgR(void *p) {
      delete [] (static_cast<map<char,Long64_t>*>(p));
   }
   static void destruct_maplEcharcOLong64_tgR(void *p) {
      typedef map<char,Long64_t> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<char,Long64_t>

namespace {
  void TriggerDictionaryInitialization_libntuple_types_Impl() {
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
      TROOT::RegisterModule("libntuple_types",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libntuple_types_Impl, {}, classesHeaders, /*hasCxxModule*/true);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libntuple_types_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libntuple_types() {
  TriggerDictionaryInitialization_libntuple_types_Impl();
}
