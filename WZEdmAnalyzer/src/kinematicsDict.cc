// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME kinematicsDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
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

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "kinematics.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new__event_filterBit_(void *p = 0);
   static void *newArray__event_filterBit_(Long_t size, void *p);
   static void delete__event_filterBit_(void *p);
   static void deleteArray__event_filterBit_(void *p);
   static void destruct__event_filterBit_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_event_filterBit_*)
   {
      ::_event_filterBit_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_event_filterBit_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_event_filterBit_", ::_event_filterBit_::Class_Version(), "kinematics.h", 33,
                  typeid(::_event_filterBit_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_event_filterBit_::Dictionary, isa_proxy, 4,
                  sizeof(::_event_filterBit_) );
      instance.SetNew(&new__event_filterBit_);
      instance.SetNewArray(&newArray__event_filterBit_);
      instance.SetDelete(&delete__event_filterBit_);
      instance.SetDeleteArray(&deleteArray__event_filterBit_);
      instance.SetDestructor(&destruct__event_filterBit_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_event_filterBit_*)
   {
      return GenerateInitInstanceLocal((::_event_filterBit_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_event_filterBit_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__gen_eventInfo_(void *p = 0);
   static void *newArray__gen_eventInfo_(Long_t size, void *p);
   static void delete__gen_eventInfo_(void *p);
   static void deleteArray__gen_eventInfo_(void *p);
   static void destruct__gen_eventInfo_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_gen_eventInfo_*)
   {
      ::_gen_eventInfo_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_gen_eventInfo_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_gen_eventInfo_", ::_gen_eventInfo_::Class_Version(), "kinematics.h", 66,
                  typeid(::_gen_eventInfo_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_gen_eventInfo_::Dictionary, isa_proxy, 4,
                  sizeof(::_gen_eventInfo_) );
      instance.SetNew(&new__gen_eventInfo_);
      instance.SetNewArray(&newArray__gen_eventInfo_);
      instance.SetDelete(&delete__gen_eventInfo_);
      instance.SetDeleteArray(&deleteArray__gen_eventInfo_);
      instance.SetDestructor(&destruct__gen_eventInfo_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_gen_eventInfo_*)
   {
      return GenerateInitInstanceLocal((::_gen_eventInfo_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_gen_eventInfo_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__mc_process_(void *p = 0);
   static void *newArray__mc_process_(Long_t size, void *p);
   static void delete__mc_process_(void *p);
   static void deleteArray__mc_process_(void *p);
   static void destruct__mc_process_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_mc_process_*)
   {
      ::_mc_process_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_mc_process_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_mc_process_", ::_mc_process_::Class_Version(), "kinematics.h", 99,
                  typeid(::_mc_process_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_mc_process_::Dictionary, isa_proxy, 4,
                  sizeof(::_mc_process_) );
      instance.SetNew(&new__mc_process_);
      instance.SetNewArray(&newArray__mc_process_);
      instance.SetDelete(&delete__mc_process_);
      instance.SetDeleteArray(&deleteArray__mc_process_);
      instance.SetDestructor(&destruct__mc_process_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_mc_process_*)
   {
      return GenerateInitInstanceLocal((::_mc_process_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_mc_process_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__gen_ttbar_(void *p = 0);
   static void *newArray__gen_ttbar_(Long_t size, void *p);
   static void delete__gen_ttbar_(void *p);
   static void deleteArray__gen_ttbar_(void *p);
   static void destruct__gen_ttbar_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_gen_ttbar_*)
   {
      ::_gen_ttbar_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_gen_ttbar_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_gen_ttbar_", ::_gen_ttbar_::Class_Version(), "kinematics.h", 161,
                  typeid(::_gen_ttbar_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_gen_ttbar_::Dictionary, isa_proxy, 4,
                  sizeof(::_gen_ttbar_) );
      instance.SetNew(&new__gen_ttbar_);
      instance.SetNewArray(&newArray__gen_ttbar_);
      instance.SetDelete(&delete__gen_ttbar_);
      instance.SetDeleteArray(&deleteArray__gen_ttbar_);
      instance.SetDestructor(&destruct__gen_ttbar_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_gen_ttbar_*)
   {
      return GenerateInitInstanceLocal((::_gen_ttbar_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_gen_ttbar_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__gen_DrellYan_(void *p = 0);
   static void *newArray__gen_DrellYan_(Long_t size, void *p);
   static void delete__gen_DrellYan_(void *p);
   static void deleteArray__gen_DrellYan_(void *p);
   static void destruct__gen_DrellYan_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_gen_DrellYan_*)
   {
      ::_gen_DrellYan_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_gen_DrellYan_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_gen_DrellYan_", ::_gen_DrellYan_::Class_Version(), "kinematics.h", 213,
                  typeid(::_gen_DrellYan_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_gen_DrellYan_::Dictionary, isa_proxy, 4,
                  sizeof(::_gen_DrellYan_) );
      instance.SetNew(&new__gen_DrellYan_);
      instance.SetNewArray(&newArray__gen_DrellYan_);
      instance.SetDelete(&delete__gen_DrellYan_);
      instance.SetDeleteArray(&deleteArray__gen_DrellYan_);
      instance.SetDestructor(&destruct__gen_DrellYan_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_gen_DrellYan_*)
   {
      return GenerateInitInstanceLocal((::_gen_DrellYan_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_gen_DrellYan_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__genwz_(void *p = 0);
   static void *newArray__genwz_(Long_t size, void *p);
   static void delete__genwz_(void *p);
   static void deleteArray__genwz_(void *p);
   static void destruct__genwz_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_genwz_*)
   {
      ::_genwz_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_genwz_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_genwz_", ::_genwz_::Class_Version(), "kinematics.h", 275,
                  typeid(::_genwz_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_genwz_::Dictionary, isa_proxy, 4,
                  sizeof(::_genwz_) );
      instance.SetNew(&new__genwz_);
      instance.SetNewArray(&newArray__genwz_);
      instance.SetDelete(&delete__genwz_);
      instance.SetDeleteArray(&deleteArray__genwz_);
      instance.SetDestructor(&destruct__genwz_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_genwz_*)
   {
      return GenerateInitInstanceLocal((::_genwz_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_genwz_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__vec4_(void *p = 0);
   static void *newArray__vec4_(Long_t size, void *p);
   static void delete__vec4_(void *p);
   static void deleteArray__vec4_(void *p);
   static void destruct__vec4_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_vec4_*)
   {
      ::_vec4_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_vec4_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_vec4_", ::_vec4_::Class_Version(), "kinematics.h", 314,
                  typeid(::_vec4_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_vec4_::Dictionary, isa_proxy, 4,
                  sizeof(::_vec4_) );
      instance.SetNew(&new__vec4_);
      instance.SetNewArray(&newArray__vec4_);
      instance.SetDelete(&delete__vec4_);
      instance.SetDeleteArray(&deleteArray__vec4_);
      instance.SetDestructor(&destruct__vec4_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_vec4_*)
   {
      return GenerateInitInstanceLocal((::_vec4_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_vec4_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__met_(void *p = 0);
   static void *newArray__met_(Long_t size, void *p);
   static void delete__met_(void *p);
   static void deleteArray__met_(void *p);
   static void destruct__met_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_met_*)
   {
      ::_met_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_met_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_met_", ::_met_::Class_Version(), "kinematics.h", 333,
                  typeid(::_met_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_met_::Dictionary, isa_proxy, 4,
                  sizeof(::_met_) );
      instance.SetNew(&new__met_);
      instance.SetNewArray(&newArray__met_);
      instance.SetDelete(&delete__met_);
      instance.SetDeleteArray(&deleteArray__met_);
      instance.SetDestructor(&destruct__met_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_met_*)
   {
      return GenerateInitInstanceLocal((::_met_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_met_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__track_(void *p = 0);
   static void *newArray__track_(Long_t size, void *p);
   static void delete__track_(void *p);
   static void deleteArray__track_(void *p);
   static void destruct__track_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_track_*)
   {
      ::_track_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_track_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_track_", ::_track_::Class_Version(), "kinematics.h", 356,
                  typeid(::_track_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_track_::Dictionary, isa_proxy, 4,
                  sizeof(::_track_) );
      instance.SetNew(&new__track_);
      instance.SetNewArray(&newArray__track_);
      instance.SetDelete(&delete__track_);
      instance.SetDeleteArray(&deleteArray__track_);
      instance.SetDestructor(&destruct__track_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_track_*)
   {
      return GenerateInitInstanceLocal((::_track_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_track_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__trg_bits_(void *p = 0);
   static void *newArray__trg_bits_(Long_t size, void *p);
   static void delete__trg_bits_(void *p);
   static void deleteArray__trg_bits_(void *p);
   static void destruct__trg_bits_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_trg_bits_*)
   {
      ::_trg_bits_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_trg_bits_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_trg_bits_", ::_trg_bits_::Class_Version(), "kinematics.h", 412,
                  typeid(::_trg_bits_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_trg_bits_::Dictionary, isa_proxy, 4,
                  sizeof(::_trg_bits_) );
      instance.SetNew(&new__trg_bits_);
      instance.SetNewArray(&newArray__trg_bits_);
      instance.SetDelete(&delete__trg_bits_);
      instance.SetDeleteArray(&deleteArray__trg_bits_);
      instance.SetDestructor(&destruct__trg_bits_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_trg_bits_*)
   {
      return GenerateInitInstanceLocal((::_trg_bits_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_trg_bits_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__hlt_info_(void *p = 0);
   static void *newArray__hlt_info_(Long_t size, void *p);
   static void delete__hlt_info_(void *p);
   static void deleteArray__hlt_info_(void *p);
   static void destruct__hlt_info_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_hlt_info_*)
   {
      ::_hlt_info_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_hlt_info_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_hlt_info_", ::_hlt_info_::Class_Version(), "kinematics.h", 438,
                  typeid(::_hlt_info_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_hlt_info_::Dictionary, isa_proxy, 4,
                  sizeof(::_hlt_info_) );
      instance.SetNew(&new__hlt_info_);
      instance.SetNewArray(&newArray__hlt_info_);
      instance.SetDelete(&delete__hlt_info_);
      instance.SetDeleteArray(&deleteArray__hlt_info_);
      instance.SetDestructor(&destruct__hlt_info_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_hlt_info_*)
   {
      return GenerateInitInstanceLocal((::_hlt_info_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_hlt_info_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__mets_(void *p = 0);
   static void *newArray__mets_(Long_t size, void *p);
   static void delete__mets_(void *p);
   static void deleteArray__mets_(void *p);
   static void destruct__mets_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_mets_*)
   {
      ::_mets_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_mets_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_mets_", ::_mets_::Class_Version(), "kinematics.h", 465,
                  typeid(::_mets_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_mets_::Dictionary, isa_proxy, 4,
                  sizeof(::_mets_) );
      instance.SetNew(&new__mets_);
      instance.SetNewArray(&newArray__mets_);
      instance.SetDelete(&delete__mets_);
      instance.SetDeleteArray(&deleteArray__mets_);
      instance.SetDestructor(&destruct__mets_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_mets_*)
   {
      return GenerateInitInstanceLocal((::_mets_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_mets_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__dileadingjets_(void *p = 0);
   static void *newArray__dileadingjets_(Long_t size, void *p);
   static void delete__dileadingjets_(void *p);
   static void deleteArray__dileadingjets_(void *p);
   static void destruct__dileadingjets_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_dileadingjets_*)
   {
      ::_dileadingjets_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_dileadingjets_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_dileadingjets_", ::_dileadingjets_::Class_Version(), "kinematics.h", 483,
                  typeid(::_dileadingjets_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_dileadingjets_::Dictionary, isa_proxy, 4,
                  sizeof(::_dileadingjets_) );
      instance.SetNew(&new__dileadingjets_);
      instance.SetNewArray(&newArray__dileadingjets_);
      instance.SetDelete(&delete__dileadingjets_);
      instance.SetDeleteArray(&deleteArray__dileadingjets_);
      instance.SetDestructor(&destruct__dileadingjets_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_dileadingjets_*)
   {
      return GenerateInitInstanceLocal((::_dileadingjets_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_dileadingjets_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__run_info_(void *p = 0);
   static void *newArray__run_info_(Long_t size, void *p);
   static void delete__run_info_(void *p);
   static void deleteArray__run_info_(void *p);
   static void destruct__run_info_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_run_info_*)
   {
      ::_run_info_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_run_info_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_run_info_", ::_run_info_::Class_Version(), "kinematics.h", 509,
                  typeid(::_run_info_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_run_info_::Dictionary, isa_proxy, 4,
                  sizeof(::_run_info_) );
      instance.SetNew(&new__run_info_);
      instance.SetNewArray(&newArray__run_info_);
      instance.SetDelete(&delete__run_info_);
      instance.SetDeleteArray(&deleteArray__run_info_);
      instance.SetDestructor(&destruct__run_info_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_run_info_*)
   {
      return GenerateInitInstanceLocal((::_run_info_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_run_info_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__vertex_(void *p = 0);
   static void *newArray__vertex_(Long_t size, void *p);
   static void delete__vertex_(void *p);
   static void deleteArray__vertex_(void *p);
   static void destruct__vertex_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_vertex_*)
   {
      ::_vertex_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_vertex_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_vertex_", ::_vertex_::Class_Version(), "kinematics.h", 524,
                  typeid(::_vertex_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_vertex_::Dictionary, isa_proxy, 4,
                  sizeof(::_vertex_) );
      instance.SetNew(&new__vertex_);
      instance.SetNewArray(&newArray__vertex_);
      instance.SetDelete(&delete__vertex_);
      instance.SetDeleteArray(&deleteArray__vertex_);
      instance.SetDestructor(&destruct__vertex_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_vertex_*)
   {
      return GenerateInitInstanceLocal((::_vertex_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_vertex_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__l1_obj_(void *p = 0);
   static void *newArray__l1_obj_(Long_t size, void *p);
   static void delete__l1_obj_(void *p);
   static void deleteArray__l1_obj_(void *p);
   static void destruct__l1_obj_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_l1_obj_*)
   {
      ::_l1_obj_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_l1_obj_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_l1_obj_", ::_l1_obj_::Class_Version(), "kinematics.h", 556,
                  typeid(::_l1_obj_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_l1_obj_::Dictionary, isa_proxy, 4,
                  sizeof(::_l1_obj_) );
      instance.SetNew(&new__l1_obj_);
      instance.SetNewArray(&newArray__l1_obj_);
      instance.SetDelete(&delete__l1_obj_);
      instance.SetDeleteArray(&deleteArray__l1_obj_);
      instance.SetDestructor(&destruct__l1_obj_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_l1_obj_*)
   {
      return GenerateInitInstanceLocal((::_l1_obj_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_l1_obj_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__supercluster_(void *p = 0);
   static void *newArray__supercluster_(Long_t size, void *p);
   static void delete__supercluster_(void *p);
   static void deleteArray__supercluster_(void *p);
   static void destruct__supercluster_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_supercluster_*)
   {
      ::_supercluster_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_supercluster_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_supercluster_", ::_supercluster_::Class_Version(), "kinematics.h", 577,
                  typeid(::_supercluster_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_supercluster_::Dictionary, isa_proxy, 4,
                  sizeof(::_supercluster_) );
      instance.SetNew(&new__supercluster_);
      instance.SetNewArray(&newArray__supercluster_);
      instance.SetDelete(&delete__supercluster_);
      instance.SetDeleteArray(&deleteArray__supercluster_);
      instance.SetDestructor(&destruct__supercluster_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_supercluster_*)
   {
      return GenerateInitInstanceLocal((::_supercluster_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_supercluster_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__photon_(void *p = 0);
   static void *newArray__photon_(Long_t size, void *p);
   static void delete__photon_(void *p);
   static void deleteArray__photon_(void *p);
   static void destruct__photon_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_photon_*)
   {
      ::_photon_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_photon_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_photon_", ::_photon_::Class_Version(), "kinematics.h", 611,
                  typeid(::_photon_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_photon_::Dictionary, isa_proxy, 4,
                  sizeof(::_photon_) );
      instance.SetNew(&new__photon_);
      instance.SetNewArray(&newArray__photon_);
      instance.SetDelete(&delete__photon_);
      instance.SetDeleteArray(&deleteArray__photon_);
      instance.SetDestructor(&destruct__photon_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_photon_*)
   {
      return GenerateInitInstanceLocal((::_photon_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_photon_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__electron_(void *p = 0);
   static void *newArray__electron_(Long_t size, void *p);
   static void delete__electron_(void *p);
   static void deleteArray__electron_(void *p);
   static void destruct__electron_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_electron_*)
   {
      ::_electron_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_electron_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_electron_", ::_electron_::Class_Version(), "kinematics.h", 670,
                  typeid(::_electron_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_electron_::Dictionary, isa_proxy, 4,
                  sizeof(::_electron_) );
      instance.SetNew(&new__electron_);
      instance.SetNewArray(&newArray__electron_);
      instance.SetDelete(&delete__electron_);
      instance.SetDeleteArray(&deleteArray__electron_);
      instance.SetDestructor(&destruct__electron_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_electron_*)
   {
      return GenerateInitInstanceLocal((::_electron_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_electron_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__beam_spot_(void *p = 0);
   static void *newArray__beam_spot_(Long_t size, void *p);
   static void delete__beam_spot_(void *p);
   static void deleteArray__beam_spot_(void *p);
   static void destruct__beam_spot_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_beam_spot_*)
   {
      ::_beam_spot_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_beam_spot_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_beam_spot_", ::_beam_spot_::Class_Version(), "kinematics.h", 800,
                  typeid(::_beam_spot_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_beam_spot_::Dictionary, isa_proxy, 4,
                  sizeof(::_beam_spot_) );
      instance.SetNew(&new__beam_spot_);
      instance.SetNewArray(&newArray__beam_spot_);
      instance.SetDelete(&delete__beam_spot_);
      instance.SetDeleteArray(&deleteArray__beam_spot_);
      instance.SetDestructor(&destruct__beam_spot_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_beam_spot_*)
   {
      return GenerateInitInstanceLocal((::_beam_spot_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_beam_spot_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__muon_(void *p = 0);
   static void *newArray__muon_(Long_t size, void *p);
   static void delete__muon_(void *p);
   static void deleteArray__muon_(void *p);
   static void destruct__muon_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_muon_*)
   {
      ::_muon_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_muon_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_muon_", ::_muon_::Class_Version(), "kinematics.h", 822,
                  typeid(::_muon_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_muon_::Dictionary, isa_proxy, 4,
                  sizeof(::_muon_) );
      instance.SetNew(&new__muon_);
      instance.SetNewArray(&newArray__muon_);
      instance.SetDelete(&delete__muon_);
      instance.SetDeleteArray(&deleteArray__muon_);
      instance.SetDestructor(&destruct__muon_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_muon_*)
   {
      return GenerateInitInstanceLocal((::_muon_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_muon_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__gen_jet_(void *p = 0);
   static void *newArray__gen_jet_(Long_t size, void *p);
   static void delete__gen_jet_(void *p);
   static void deleteArray__gen_jet_(void *p);
   static void destruct__gen_jet_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_gen_jet_*)
   {
      ::_gen_jet_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_gen_jet_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_gen_jet_", ::_gen_jet_::Class_Version(), "kinematics.h", 915,
                  typeid(::_gen_jet_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_gen_jet_::Dictionary, isa_proxy, 4,
                  sizeof(::_gen_jet_) );
      instance.SetNew(&new__gen_jet_);
      instance.SetNewArray(&newArray__gen_jet_);
      instance.SetDelete(&delete__gen_jet_);
      instance.SetDeleteArray(&deleteArray__gen_jet_);
      instance.SetDestructor(&destruct__gen_jet_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_gen_jet_*)
   {
      return GenerateInitInstanceLocal((::_gen_jet_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_gen_jet_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__jet_(void *p = 0);
   static void *newArray__jet_(Long_t size, void *p);
   static void delete__jet_(void *p);
   static void deleteArray__jet_(void *p);
   static void destruct__jet_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_jet_*)
   {
      ::_jet_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_jet_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_jet_", ::_jet_::Class_Version(), "kinematics.h", 933,
                  typeid(::_jet_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_jet_::Dictionary, isa_proxy, 4,
                  sizeof(::_jet_) );
      instance.SetNew(&new__jet_);
      instance.SetNewArray(&newArray__jet_);
      instance.SetDelete(&delete__jet_);
      instance.SetDeleteArray(&deleteArray__jet_);
      instance.SetDestructor(&destruct__jet_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_jet_*)
   {
      return GenerateInitInstanceLocal((::_jet_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_jet_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__di_jet_(void *p = 0);
   static void *newArray__di_jet_(Long_t size, void *p);
   static void delete__di_jet_(void *p);
   static void deleteArray__di_jet_(void *p);
   static void destruct__di_jet_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_di_jet_*)
   {
      ::_di_jet_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_di_jet_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_di_jet_", ::_di_jet_::Class_Version(), "kinematics.h", 1027,
                  typeid(::_di_jet_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_di_jet_::Dictionary, isa_proxy, 4,
                  sizeof(::_di_jet_) );
      instance.SetNew(&new__di_jet_);
      instance.SetNewArray(&newArray__di_jet_);
      instance.SetDelete(&delete__di_jet_);
      instance.SetDeleteArray(&deleteArray__di_jet_);
      instance.SetDestructor(&destruct__di_jet_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_di_jet_*)
   {
      return GenerateInitInstanceLocal((::_di_jet_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_di_jet_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__W_(void *p = 0);
   static void *newArray__W_(Long_t size, void *p);
   static void delete__W_(void *p);
   static void deleteArray__W_(void *p);
   static void destruct__W_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_W_*)
   {
      ::_W_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_W_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_W_", ::_W_::Class_Version(), "kinematics.h", 1056,
                  typeid(::_W_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_W_::Dictionary, isa_proxy, 4,
                  sizeof(::_W_) );
      instance.SetNew(&new__W_);
      instance.SetNewArray(&newArray__W_);
      instance.SetDelete(&delete__W_);
      instance.SetDeleteArray(&deleteArray__W_);
      instance.SetDestructor(&destruct__W_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_W_*)
   {
      return GenerateInitInstanceLocal((::_W_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_W_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__di_lepton_(void *p = 0);
   static void *newArray__di_lepton_(Long_t size, void *p);
   static void delete__di_lepton_(void *p);
   static void deleteArray__di_lepton_(void *p);
   static void destruct__di_lepton_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_di_lepton_*)
   {
      ::_di_lepton_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_di_lepton_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_di_lepton_", ::_di_lepton_::Class_Version(), "kinematics.h", 1077,
                  typeid(::_di_lepton_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_di_lepton_::Dictionary, isa_proxy, 4,
                  sizeof(::_di_lepton_) );
      instance.SetNew(&new__di_lepton_);
      instance.SetNewArray(&newArray__di_lepton_);
      instance.SetDelete(&delete__di_lepton_);
      instance.SetDeleteArray(&deleteArray__di_lepton_);
      instance.SetDestructor(&destruct__di_lepton_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_di_lepton_*)
   {
      return GenerateInitInstanceLocal((::_di_lepton_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_di_lepton_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__tri_lepton_(void *p = 0);
   static void *newArray__tri_lepton_(Long_t size, void *p);
   static void delete__tri_lepton_(void *p);
   static void deleteArray__tri_lepton_(void *p);
   static void destruct__tri_lepton_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_tri_lepton_*)
   {
      ::_tri_lepton_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_tri_lepton_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_tri_lepton_", ::_tri_lepton_::Class_Version(), "kinematics.h", 1127,
                  typeid(::_tri_lepton_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_tri_lepton_::Dictionary, isa_proxy, 4,
                  sizeof(::_tri_lepton_) );
      instance.SetNew(&new__tri_lepton_);
      instance.SetNewArray(&newArray__tri_lepton_);
      instance.SetDelete(&delete__tri_lepton_);
      instance.SetDeleteArray(&deleteArray__tri_lepton_);
      instance.SetDestructor(&destruct__tri_lepton_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_tri_lepton_*)
   {
      return GenerateInitInstanceLocal((::_tri_lepton_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_tri_lepton_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__quar_lepton_(void *p = 0);
   static void *newArray__quar_lepton_(Long_t size, void *p);
   static void delete__quar_lepton_(void *p);
   static void deleteArray__quar_lepton_(void *p);
   static void destruct__quar_lepton_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_quar_lepton_*)
   {
      ::_quar_lepton_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_quar_lepton_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_quar_lepton_", ::_quar_lepton_::Class_Version(), "kinematics.h", 1151,
                  typeid(::_quar_lepton_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_quar_lepton_::Dictionary, isa_proxy, 4,
                  sizeof(::_quar_lepton_) );
      instance.SetNew(&new__quar_lepton_);
      instance.SetNewArray(&newArray__quar_lepton_);
      instance.SetDelete(&delete__quar_lepton_);
      instance.SetDeleteArray(&deleteArray__quar_lepton_);
      instance.SetDestructor(&destruct__quar_lepton_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_quar_lepton_*)
   {
      return GenerateInitInstanceLocal((::_quar_lepton_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_quar_lepton_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__lepton_photon_(void *p = 0);
   static void *newArray__lepton_photon_(Long_t size, void *p);
   static void delete__lepton_photon_(void *p);
   static void deleteArray__lepton_photon_(void *p);
   static void destruct__lepton_photon_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_lepton_photon_*)
   {
      ::_lepton_photon_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_lepton_photon_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_lepton_photon_", ::_lepton_photon_::Class_Version(), "kinematics.h", 1175,
                  typeid(::_lepton_photon_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_lepton_photon_::Dictionary, isa_proxy, 4,
                  sizeof(::_lepton_photon_) );
      instance.SetNew(&new__lepton_photon_);
      instance.SetNewArray(&newArray__lepton_photon_);
      instance.SetDelete(&delete__lepton_photon_);
      instance.SetDeleteArray(&deleteArray__lepton_photon_);
      instance.SetDestructor(&destruct__lepton_photon_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_lepton_photon_*)
   {
      return GenerateInitInstanceLocal((::_lepton_photon_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_lepton_photon_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__dilepton_photon_(void *p = 0);
   static void *newArray__dilepton_photon_(Long_t size, void *p);
   static void delete__dilepton_photon_(void *p);
   static void deleteArray__dilepton_photon_(void *p);
   static void destruct__dilepton_photon_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_dilepton_photon_*)
   {
      ::_dilepton_photon_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_dilepton_photon_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_dilepton_photon_", ::_dilepton_photon_::Class_Version(), "kinematics.h", 1199,
                  typeid(::_dilepton_photon_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_dilepton_photon_::Dictionary, isa_proxy, 4,
                  sizeof(::_dilepton_photon_) );
      instance.SetNew(&new__dilepton_photon_);
      instance.SetNewArray(&newArray__dilepton_photon_);
      instance.SetDelete(&delete__dilepton_photon_);
      instance.SetDeleteArray(&deleteArray__dilepton_photon_);
      instance.SetDestructor(&destruct__dilepton_photon_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_dilepton_photon_*)
   {
      return GenerateInitInstanceLocal((::_dilepton_photon_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_dilepton_photon_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new__event_(void *p = 0);
   static void *newArray__event_(Long_t size, void *p);
   static void delete__event_(void *p);
   static void deleteArray__event_(void *p);
   static void destruct__event_(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_event_*)
   {
      ::_event_ *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::_event_ >(0);
      static ::ROOT::TGenericClassInfo 
         instance("_event_", ::_event_::Class_Version(), "kinematics.h", 1233,
                  typeid(::_event_), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::_event_::Dictionary, isa_proxy, 4,
                  sizeof(::_event_) );
      instance.SetNew(&new__event_);
      instance.SetNewArray(&newArray__event_);
      instance.SetDelete(&delete__event_);
      instance.SetDeleteArray(&deleteArray__event_);
      instance.SetDestructor(&destruct__event_);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::_event_*)
   {
      return GenerateInitInstanceLocal((::_event_*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_event_*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr _event_filterBit_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_event_filterBit_::Class_Name()
{
   return "_event_filterBit_";
}

//______________________________________________________________________________
const char *_event_filterBit_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_event_filterBit_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _event_filterBit_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_event_filterBit_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_event_filterBit_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_event_filterBit_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_event_filterBit_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_event_filterBit_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _gen_eventInfo_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_gen_eventInfo_::Class_Name()
{
   return "_gen_eventInfo_";
}

//______________________________________________________________________________
const char *_gen_eventInfo_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_gen_eventInfo_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _gen_eventInfo_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_gen_eventInfo_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_gen_eventInfo_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_gen_eventInfo_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_gen_eventInfo_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_gen_eventInfo_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _mc_process_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_mc_process_::Class_Name()
{
   return "_mc_process_";
}

//______________________________________________________________________________
const char *_mc_process_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_mc_process_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _mc_process_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_mc_process_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_mc_process_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_mc_process_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_mc_process_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_mc_process_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _gen_ttbar_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_gen_ttbar_::Class_Name()
{
   return "_gen_ttbar_";
}

//______________________________________________________________________________
const char *_gen_ttbar_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_gen_ttbar_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _gen_ttbar_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_gen_ttbar_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_gen_ttbar_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_gen_ttbar_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_gen_ttbar_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_gen_ttbar_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _gen_DrellYan_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_gen_DrellYan_::Class_Name()
{
   return "_gen_DrellYan_";
}

//______________________________________________________________________________
const char *_gen_DrellYan_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_gen_DrellYan_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _gen_DrellYan_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_gen_DrellYan_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_gen_DrellYan_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_gen_DrellYan_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_gen_DrellYan_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_gen_DrellYan_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _genwz_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_genwz_::Class_Name()
{
   return "_genwz_";
}

//______________________________________________________________________________
const char *_genwz_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_genwz_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _genwz_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_genwz_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_genwz_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_genwz_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_genwz_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_genwz_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _vec4_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_vec4_::Class_Name()
{
   return "_vec4_";
}

//______________________________________________________________________________
const char *_vec4_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_vec4_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _vec4_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_vec4_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_vec4_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_vec4_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_vec4_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_vec4_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _met_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_met_::Class_Name()
{
   return "_met_";
}

//______________________________________________________________________________
const char *_met_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_met_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _met_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_met_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_met_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_met_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_met_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_met_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _track_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_track_::Class_Name()
{
   return "_track_";
}

//______________________________________________________________________________
const char *_track_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_track_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _track_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_track_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_track_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_track_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_track_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_track_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _trg_bits_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_trg_bits_::Class_Name()
{
   return "_trg_bits_";
}

//______________________________________________________________________________
const char *_trg_bits_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_trg_bits_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _trg_bits_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_trg_bits_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_trg_bits_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_trg_bits_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_trg_bits_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_trg_bits_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _hlt_info_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_hlt_info_::Class_Name()
{
   return "_hlt_info_";
}

//______________________________________________________________________________
const char *_hlt_info_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_hlt_info_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _hlt_info_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_hlt_info_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_hlt_info_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_hlt_info_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_hlt_info_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_hlt_info_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _mets_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_mets_::Class_Name()
{
   return "_mets_";
}

//______________________________________________________________________________
const char *_mets_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_mets_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _mets_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_mets_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_mets_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_mets_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_mets_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_mets_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _dileadingjets_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_dileadingjets_::Class_Name()
{
   return "_dileadingjets_";
}

//______________________________________________________________________________
const char *_dileadingjets_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_dileadingjets_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _dileadingjets_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_dileadingjets_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_dileadingjets_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_dileadingjets_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_dileadingjets_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_dileadingjets_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _run_info_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_run_info_::Class_Name()
{
   return "_run_info_";
}

//______________________________________________________________________________
const char *_run_info_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_run_info_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _run_info_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_run_info_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_run_info_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_run_info_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_run_info_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_run_info_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _vertex_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_vertex_::Class_Name()
{
   return "_vertex_";
}

//______________________________________________________________________________
const char *_vertex_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_vertex_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _vertex_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_vertex_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_vertex_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_vertex_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_vertex_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_vertex_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _l1_obj_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_l1_obj_::Class_Name()
{
   return "_l1_obj_";
}

//______________________________________________________________________________
const char *_l1_obj_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_l1_obj_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _l1_obj_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_l1_obj_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_l1_obj_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_l1_obj_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_l1_obj_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_l1_obj_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _supercluster_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_supercluster_::Class_Name()
{
   return "_supercluster_";
}

//______________________________________________________________________________
const char *_supercluster_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_supercluster_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _supercluster_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_supercluster_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_supercluster_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_supercluster_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_supercluster_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_supercluster_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _photon_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_photon_::Class_Name()
{
   return "_photon_";
}

//______________________________________________________________________________
const char *_photon_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_photon_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _photon_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_photon_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_photon_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_photon_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_photon_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_photon_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _electron_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_electron_::Class_Name()
{
   return "_electron_";
}

//______________________________________________________________________________
const char *_electron_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_electron_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _electron_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_electron_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_electron_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_electron_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_electron_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_electron_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _beam_spot_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_beam_spot_::Class_Name()
{
   return "_beam_spot_";
}

//______________________________________________________________________________
const char *_beam_spot_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_beam_spot_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _beam_spot_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_beam_spot_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_beam_spot_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_beam_spot_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_beam_spot_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_beam_spot_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _muon_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_muon_::Class_Name()
{
   return "_muon_";
}

//______________________________________________________________________________
const char *_muon_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_muon_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _muon_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_muon_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_muon_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_muon_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_muon_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_muon_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _gen_jet_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_gen_jet_::Class_Name()
{
   return "_gen_jet_";
}

//______________________________________________________________________________
const char *_gen_jet_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_gen_jet_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _gen_jet_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_gen_jet_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_gen_jet_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_gen_jet_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_gen_jet_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_gen_jet_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _jet_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_jet_::Class_Name()
{
   return "_jet_";
}

//______________________________________________________________________________
const char *_jet_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_jet_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _jet_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_jet_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_jet_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_jet_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_jet_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_jet_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _di_jet_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_di_jet_::Class_Name()
{
   return "_di_jet_";
}

//______________________________________________________________________________
const char *_di_jet_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_di_jet_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _di_jet_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_di_jet_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_di_jet_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_di_jet_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_di_jet_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_di_jet_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _W_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_W_::Class_Name()
{
   return "_W_";
}

//______________________________________________________________________________
const char *_W_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_W_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _W_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_W_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_W_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_W_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_W_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_W_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _di_lepton_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_di_lepton_::Class_Name()
{
   return "_di_lepton_";
}

//______________________________________________________________________________
const char *_di_lepton_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_di_lepton_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _di_lepton_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_di_lepton_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_di_lepton_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_di_lepton_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_di_lepton_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_di_lepton_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _tri_lepton_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_tri_lepton_::Class_Name()
{
   return "_tri_lepton_";
}

//______________________________________________________________________________
const char *_tri_lepton_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_tri_lepton_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _tri_lepton_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_tri_lepton_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_tri_lepton_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_tri_lepton_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_tri_lepton_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_tri_lepton_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _quar_lepton_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_quar_lepton_::Class_Name()
{
   return "_quar_lepton_";
}

//______________________________________________________________________________
const char *_quar_lepton_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_quar_lepton_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _quar_lepton_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_quar_lepton_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_quar_lepton_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_quar_lepton_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_quar_lepton_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_quar_lepton_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _lepton_photon_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_lepton_photon_::Class_Name()
{
   return "_lepton_photon_";
}

//______________________________________________________________________________
const char *_lepton_photon_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_lepton_photon_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _lepton_photon_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_lepton_photon_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_lepton_photon_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_lepton_photon_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_lepton_photon_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_lepton_photon_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _dilepton_photon_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_dilepton_photon_::Class_Name()
{
   return "_dilepton_photon_";
}

//______________________________________________________________________________
const char *_dilepton_photon_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_dilepton_photon_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _dilepton_photon_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_dilepton_photon_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_dilepton_photon_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_dilepton_photon_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_dilepton_photon_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_dilepton_photon_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr _event_::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *_event_::Class_Name()
{
   return "_event_";
}

//______________________________________________________________________________
const char *_event_::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_event_*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int _event_::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::_event_*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *_event_::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_event_*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *_event_::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::_event_*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void _event_filterBit_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _event_filterBit_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_event_filterBit_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_event_filterBit_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__event_filterBit_(void *p) {
      return  p ? new(p) ::_event_filterBit_ : new ::_event_filterBit_;
   }
   static void *newArray__event_filterBit_(Long_t nElements, void *p) {
      return p ? new(p) ::_event_filterBit_[nElements] : new ::_event_filterBit_[nElements];
   }
   // Wrapper around operator delete
   static void delete__event_filterBit_(void *p) {
      delete ((::_event_filterBit_*)p);
   }
   static void deleteArray__event_filterBit_(void *p) {
      delete [] ((::_event_filterBit_*)p);
   }
   static void destruct__event_filterBit_(void *p) {
      typedef ::_event_filterBit_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_event_filterBit_

//______________________________________________________________________________
void _gen_eventInfo_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _gen_eventInfo_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_gen_eventInfo_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_gen_eventInfo_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__gen_eventInfo_(void *p) {
      return  p ? new(p) ::_gen_eventInfo_ : new ::_gen_eventInfo_;
   }
   static void *newArray__gen_eventInfo_(Long_t nElements, void *p) {
      return p ? new(p) ::_gen_eventInfo_[nElements] : new ::_gen_eventInfo_[nElements];
   }
   // Wrapper around operator delete
   static void delete__gen_eventInfo_(void *p) {
      delete ((::_gen_eventInfo_*)p);
   }
   static void deleteArray__gen_eventInfo_(void *p) {
      delete [] ((::_gen_eventInfo_*)p);
   }
   static void destruct__gen_eventInfo_(void *p) {
      typedef ::_gen_eventInfo_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_gen_eventInfo_

//______________________________________________________________________________
void _mc_process_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _mc_process_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_mc_process_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_mc_process_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__mc_process_(void *p) {
      return  p ? new(p) ::_mc_process_ : new ::_mc_process_;
   }
   static void *newArray__mc_process_(Long_t nElements, void *p) {
      return p ? new(p) ::_mc_process_[nElements] : new ::_mc_process_[nElements];
   }
   // Wrapper around operator delete
   static void delete__mc_process_(void *p) {
      delete ((::_mc_process_*)p);
   }
   static void deleteArray__mc_process_(void *p) {
      delete [] ((::_mc_process_*)p);
   }
   static void destruct__mc_process_(void *p) {
      typedef ::_mc_process_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_mc_process_

//______________________________________________________________________________
void _gen_ttbar_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _gen_ttbar_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_gen_ttbar_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_gen_ttbar_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__gen_ttbar_(void *p) {
      return  p ? new(p) ::_gen_ttbar_ : new ::_gen_ttbar_;
   }
   static void *newArray__gen_ttbar_(Long_t nElements, void *p) {
      return p ? new(p) ::_gen_ttbar_[nElements] : new ::_gen_ttbar_[nElements];
   }
   // Wrapper around operator delete
   static void delete__gen_ttbar_(void *p) {
      delete ((::_gen_ttbar_*)p);
   }
   static void deleteArray__gen_ttbar_(void *p) {
      delete [] ((::_gen_ttbar_*)p);
   }
   static void destruct__gen_ttbar_(void *p) {
      typedef ::_gen_ttbar_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_gen_ttbar_

//______________________________________________________________________________
void _gen_DrellYan_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _gen_DrellYan_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_gen_DrellYan_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_gen_DrellYan_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__gen_DrellYan_(void *p) {
      return  p ? new(p) ::_gen_DrellYan_ : new ::_gen_DrellYan_;
   }
   static void *newArray__gen_DrellYan_(Long_t nElements, void *p) {
      return p ? new(p) ::_gen_DrellYan_[nElements] : new ::_gen_DrellYan_[nElements];
   }
   // Wrapper around operator delete
   static void delete__gen_DrellYan_(void *p) {
      delete ((::_gen_DrellYan_*)p);
   }
   static void deleteArray__gen_DrellYan_(void *p) {
      delete [] ((::_gen_DrellYan_*)p);
   }
   static void destruct__gen_DrellYan_(void *p) {
      typedef ::_gen_DrellYan_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_gen_DrellYan_

//______________________________________________________________________________
void _genwz_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _genwz_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_genwz_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_genwz_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__genwz_(void *p) {
      return  p ? new(p) ::_genwz_ : new ::_genwz_;
   }
   static void *newArray__genwz_(Long_t nElements, void *p) {
      return p ? new(p) ::_genwz_[nElements] : new ::_genwz_[nElements];
   }
   // Wrapper around operator delete
   static void delete__genwz_(void *p) {
      delete ((::_genwz_*)p);
   }
   static void deleteArray__genwz_(void *p) {
      delete [] ((::_genwz_*)p);
   }
   static void destruct__genwz_(void *p) {
      typedef ::_genwz_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_genwz_

//______________________________________________________________________________
void _vec4_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _vec4_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_vec4_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_vec4_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__vec4_(void *p) {
      return  p ? new(p) ::_vec4_ : new ::_vec4_;
   }
   static void *newArray__vec4_(Long_t nElements, void *p) {
      return p ? new(p) ::_vec4_[nElements] : new ::_vec4_[nElements];
   }
   // Wrapper around operator delete
   static void delete__vec4_(void *p) {
      delete ((::_vec4_*)p);
   }
   static void deleteArray__vec4_(void *p) {
      delete [] ((::_vec4_*)p);
   }
   static void destruct__vec4_(void *p) {
      typedef ::_vec4_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_vec4_

//______________________________________________________________________________
void _met_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _met_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_met_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_met_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__met_(void *p) {
      return  p ? new(p) ::_met_ : new ::_met_;
   }
   static void *newArray__met_(Long_t nElements, void *p) {
      return p ? new(p) ::_met_[nElements] : new ::_met_[nElements];
   }
   // Wrapper around operator delete
   static void delete__met_(void *p) {
      delete ((::_met_*)p);
   }
   static void deleteArray__met_(void *p) {
      delete [] ((::_met_*)p);
   }
   static void destruct__met_(void *p) {
      typedef ::_met_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_met_

//______________________________________________________________________________
void _track_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _track_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_track_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_track_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__track_(void *p) {
      return  p ? new(p) ::_track_ : new ::_track_;
   }
   static void *newArray__track_(Long_t nElements, void *p) {
      return p ? new(p) ::_track_[nElements] : new ::_track_[nElements];
   }
   // Wrapper around operator delete
   static void delete__track_(void *p) {
      delete ((::_track_*)p);
   }
   static void deleteArray__track_(void *p) {
      delete [] ((::_track_*)p);
   }
   static void destruct__track_(void *p) {
      typedef ::_track_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_track_

//______________________________________________________________________________
void _trg_bits_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _trg_bits_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_trg_bits_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_trg_bits_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__trg_bits_(void *p) {
      return  p ? new(p) ::_trg_bits_ : new ::_trg_bits_;
   }
   static void *newArray__trg_bits_(Long_t nElements, void *p) {
      return p ? new(p) ::_trg_bits_[nElements] : new ::_trg_bits_[nElements];
   }
   // Wrapper around operator delete
   static void delete__trg_bits_(void *p) {
      delete ((::_trg_bits_*)p);
   }
   static void deleteArray__trg_bits_(void *p) {
      delete [] ((::_trg_bits_*)p);
   }
   static void destruct__trg_bits_(void *p) {
      typedef ::_trg_bits_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_trg_bits_

//______________________________________________________________________________
void _hlt_info_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _hlt_info_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_hlt_info_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_hlt_info_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__hlt_info_(void *p) {
      return  p ? new(p) ::_hlt_info_ : new ::_hlt_info_;
   }
   static void *newArray__hlt_info_(Long_t nElements, void *p) {
      return p ? new(p) ::_hlt_info_[nElements] : new ::_hlt_info_[nElements];
   }
   // Wrapper around operator delete
   static void delete__hlt_info_(void *p) {
      delete ((::_hlt_info_*)p);
   }
   static void deleteArray__hlt_info_(void *p) {
      delete [] ((::_hlt_info_*)p);
   }
   static void destruct__hlt_info_(void *p) {
      typedef ::_hlt_info_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_hlt_info_

//______________________________________________________________________________
void _mets_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _mets_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_mets_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_mets_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__mets_(void *p) {
      return  p ? new(p) ::_mets_ : new ::_mets_;
   }
   static void *newArray__mets_(Long_t nElements, void *p) {
      return p ? new(p) ::_mets_[nElements] : new ::_mets_[nElements];
   }
   // Wrapper around operator delete
   static void delete__mets_(void *p) {
      delete ((::_mets_*)p);
   }
   static void deleteArray__mets_(void *p) {
      delete [] ((::_mets_*)p);
   }
   static void destruct__mets_(void *p) {
      typedef ::_mets_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_mets_

//______________________________________________________________________________
void _dileadingjets_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _dileadingjets_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_dileadingjets_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_dileadingjets_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__dileadingjets_(void *p) {
      return  p ? new(p) ::_dileadingjets_ : new ::_dileadingjets_;
   }
   static void *newArray__dileadingjets_(Long_t nElements, void *p) {
      return p ? new(p) ::_dileadingjets_[nElements] : new ::_dileadingjets_[nElements];
   }
   // Wrapper around operator delete
   static void delete__dileadingjets_(void *p) {
      delete ((::_dileadingjets_*)p);
   }
   static void deleteArray__dileadingjets_(void *p) {
      delete [] ((::_dileadingjets_*)p);
   }
   static void destruct__dileadingjets_(void *p) {
      typedef ::_dileadingjets_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_dileadingjets_

//______________________________________________________________________________
void _run_info_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _run_info_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_run_info_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_run_info_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__run_info_(void *p) {
      return  p ? new(p) ::_run_info_ : new ::_run_info_;
   }
   static void *newArray__run_info_(Long_t nElements, void *p) {
      return p ? new(p) ::_run_info_[nElements] : new ::_run_info_[nElements];
   }
   // Wrapper around operator delete
   static void delete__run_info_(void *p) {
      delete ((::_run_info_*)p);
   }
   static void deleteArray__run_info_(void *p) {
      delete [] ((::_run_info_*)p);
   }
   static void destruct__run_info_(void *p) {
      typedef ::_run_info_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_run_info_

//______________________________________________________________________________
void _vertex_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _vertex_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_vertex_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_vertex_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__vertex_(void *p) {
      return  p ? new(p) ::_vertex_ : new ::_vertex_;
   }
   static void *newArray__vertex_(Long_t nElements, void *p) {
      return p ? new(p) ::_vertex_[nElements] : new ::_vertex_[nElements];
   }
   // Wrapper around operator delete
   static void delete__vertex_(void *p) {
      delete ((::_vertex_*)p);
   }
   static void deleteArray__vertex_(void *p) {
      delete [] ((::_vertex_*)p);
   }
   static void destruct__vertex_(void *p) {
      typedef ::_vertex_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_vertex_

//______________________________________________________________________________
void _l1_obj_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _l1_obj_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_l1_obj_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_l1_obj_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__l1_obj_(void *p) {
      return  p ? new(p) ::_l1_obj_ : new ::_l1_obj_;
   }
   static void *newArray__l1_obj_(Long_t nElements, void *p) {
      return p ? new(p) ::_l1_obj_[nElements] : new ::_l1_obj_[nElements];
   }
   // Wrapper around operator delete
   static void delete__l1_obj_(void *p) {
      delete ((::_l1_obj_*)p);
   }
   static void deleteArray__l1_obj_(void *p) {
      delete [] ((::_l1_obj_*)p);
   }
   static void destruct__l1_obj_(void *p) {
      typedef ::_l1_obj_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_l1_obj_

//______________________________________________________________________________
void _supercluster_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _supercluster_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_supercluster_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_supercluster_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__supercluster_(void *p) {
      return  p ? new(p) ::_supercluster_ : new ::_supercluster_;
   }
   static void *newArray__supercluster_(Long_t nElements, void *p) {
      return p ? new(p) ::_supercluster_[nElements] : new ::_supercluster_[nElements];
   }
   // Wrapper around operator delete
   static void delete__supercluster_(void *p) {
      delete ((::_supercluster_*)p);
   }
   static void deleteArray__supercluster_(void *p) {
      delete [] ((::_supercluster_*)p);
   }
   static void destruct__supercluster_(void *p) {
      typedef ::_supercluster_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_supercluster_

//______________________________________________________________________________
void _photon_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _photon_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_photon_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_photon_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__photon_(void *p) {
      return  p ? new(p) ::_photon_ : new ::_photon_;
   }
   static void *newArray__photon_(Long_t nElements, void *p) {
      return p ? new(p) ::_photon_[nElements] : new ::_photon_[nElements];
   }
   // Wrapper around operator delete
   static void delete__photon_(void *p) {
      delete ((::_photon_*)p);
   }
   static void deleteArray__photon_(void *p) {
      delete [] ((::_photon_*)p);
   }
   static void destruct__photon_(void *p) {
      typedef ::_photon_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_photon_

//______________________________________________________________________________
void _electron_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _electron_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_electron_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_electron_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__electron_(void *p) {
      return  p ? new(p) ::_electron_ : new ::_electron_;
   }
   static void *newArray__electron_(Long_t nElements, void *p) {
      return p ? new(p) ::_electron_[nElements] : new ::_electron_[nElements];
   }
   // Wrapper around operator delete
   static void delete__electron_(void *p) {
      delete ((::_electron_*)p);
   }
   static void deleteArray__electron_(void *p) {
      delete [] ((::_electron_*)p);
   }
   static void destruct__electron_(void *p) {
      typedef ::_electron_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_electron_

//______________________________________________________________________________
void _beam_spot_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _beam_spot_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_beam_spot_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_beam_spot_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__beam_spot_(void *p) {
      return  p ? new(p) ::_beam_spot_ : new ::_beam_spot_;
   }
   static void *newArray__beam_spot_(Long_t nElements, void *p) {
      return p ? new(p) ::_beam_spot_[nElements] : new ::_beam_spot_[nElements];
   }
   // Wrapper around operator delete
   static void delete__beam_spot_(void *p) {
      delete ((::_beam_spot_*)p);
   }
   static void deleteArray__beam_spot_(void *p) {
      delete [] ((::_beam_spot_*)p);
   }
   static void destruct__beam_spot_(void *p) {
      typedef ::_beam_spot_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_beam_spot_

//______________________________________________________________________________
void _muon_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _muon_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_muon_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_muon_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__muon_(void *p) {
      return  p ? new(p) ::_muon_ : new ::_muon_;
   }
   static void *newArray__muon_(Long_t nElements, void *p) {
      return p ? new(p) ::_muon_[nElements] : new ::_muon_[nElements];
   }
   // Wrapper around operator delete
   static void delete__muon_(void *p) {
      delete ((::_muon_*)p);
   }
   static void deleteArray__muon_(void *p) {
      delete [] ((::_muon_*)p);
   }
   static void destruct__muon_(void *p) {
      typedef ::_muon_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_muon_

//______________________________________________________________________________
void _gen_jet_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _gen_jet_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_gen_jet_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_gen_jet_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__gen_jet_(void *p) {
      return  p ? new(p) ::_gen_jet_ : new ::_gen_jet_;
   }
   static void *newArray__gen_jet_(Long_t nElements, void *p) {
      return p ? new(p) ::_gen_jet_[nElements] : new ::_gen_jet_[nElements];
   }
   // Wrapper around operator delete
   static void delete__gen_jet_(void *p) {
      delete ((::_gen_jet_*)p);
   }
   static void deleteArray__gen_jet_(void *p) {
      delete [] ((::_gen_jet_*)p);
   }
   static void destruct__gen_jet_(void *p) {
      typedef ::_gen_jet_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_gen_jet_

//______________________________________________________________________________
void _jet_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _jet_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_jet_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_jet_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__jet_(void *p) {
      return  p ? new(p) ::_jet_ : new ::_jet_;
   }
   static void *newArray__jet_(Long_t nElements, void *p) {
      return p ? new(p) ::_jet_[nElements] : new ::_jet_[nElements];
   }
   // Wrapper around operator delete
   static void delete__jet_(void *p) {
      delete ((::_jet_*)p);
   }
   static void deleteArray__jet_(void *p) {
      delete [] ((::_jet_*)p);
   }
   static void destruct__jet_(void *p) {
      typedef ::_jet_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_jet_

//______________________________________________________________________________
void _di_jet_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _di_jet_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_di_jet_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_di_jet_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__di_jet_(void *p) {
      return  p ? new(p) ::_di_jet_ : new ::_di_jet_;
   }
   static void *newArray__di_jet_(Long_t nElements, void *p) {
      return p ? new(p) ::_di_jet_[nElements] : new ::_di_jet_[nElements];
   }
   // Wrapper around operator delete
   static void delete__di_jet_(void *p) {
      delete ((::_di_jet_*)p);
   }
   static void deleteArray__di_jet_(void *p) {
      delete [] ((::_di_jet_*)p);
   }
   static void destruct__di_jet_(void *p) {
      typedef ::_di_jet_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_di_jet_

//______________________________________________________________________________
void _W_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _W_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_W_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_W_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__W_(void *p) {
      return  p ? new(p) ::_W_ : new ::_W_;
   }
   static void *newArray__W_(Long_t nElements, void *p) {
      return p ? new(p) ::_W_[nElements] : new ::_W_[nElements];
   }
   // Wrapper around operator delete
   static void delete__W_(void *p) {
      delete ((::_W_*)p);
   }
   static void deleteArray__W_(void *p) {
      delete [] ((::_W_*)p);
   }
   static void destruct__W_(void *p) {
      typedef ::_W_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_W_

//______________________________________________________________________________
void _di_lepton_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _di_lepton_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_di_lepton_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_di_lepton_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__di_lepton_(void *p) {
      return  p ? new(p) ::_di_lepton_ : new ::_di_lepton_;
   }
   static void *newArray__di_lepton_(Long_t nElements, void *p) {
      return p ? new(p) ::_di_lepton_[nElements] : new ::_di_lepton_[nElements];
   }
   // Wrapper around operator delete
   static void delete__di_lepton_(void *p) {
      delete ((::_di_lepton_*)p);
   }
   static void deleteArray__di_lepton_(void *p) {
      delete [] ((::_di_lepton_*)p);
   }
   static void destruct__di_lepton_(void *p) {
      typedef ::_di_lepton_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_di_lepton_

//______________________________________________________________________________
void _tri_lepton_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _tri_lepton_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_tri_lepton_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_tri_lepton_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__tri_lepton_(void *p) {
      return  p ? new(p) ::_tri_lepton_ : new ::_tri_lepton_;
   }
   static void *newArray__tri_lepton_(Long_t nElements, void *p) {
      return p ? new(p) ::_tri_lepton_[nElements] : new ::_tri_lepton_[nElements];
   }
   // Wrapper around operator delete
   static void delete__tri_lepton_(void *p) {
      delete ((::_tri_lepton_*)p);
   }
   static void deleteArray__tri_lepton_(void *p) {
      delete [] ((::_tri_lepton_*)p);
   }
   static void destruct__tri_lepton_(void *p) {
      typedef ::_tri_lepton_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_tri_lepton_

//______________________________________________________________________________
void _quar_lepton_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _quar_lepton_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_quar_lepton_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_quar_lepton_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__quar_lepton_(void *p) {
      return  p ? new(p) ::_quar_lepton_ : new ::_quar_lepton_;
   }
   static void *newArray__quar_lepton_(Long_t nElements, void *p) {
      return p ? new(p) ::_quar_lepton_[nElements] : new ::_quar_lepton_[nElements];
   }
   // Wrapper around operator delete
   static void delete__quar_lepton_(void *p) {
      delete ((::_quar_lepton_*)p);
   }
   static void deleteArray__quar_lepton_(void *p) {
      delete [] ((::_quar_lepton_*)p);
   }
   static void destruct__quar_lepton_(void *p) {
      typedef ::_quar_lepton_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_quar_lepton_

//______________________________________________________________________________
void _lepton_photon_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _lepton_photon_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_lepton_photon_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_lepton_photon_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__lepton_photon_(void *p) {
      return  p ? new(p) ::_lepton_photon_ : new ::_lepton_photon_;
   }
   static void *newArray__lepton_photon_(Long_t nElements, void *p) {
      return p ? new(p) ::_lepton_photon_[nElements] : new ::_lepton_photon_[nElements];
   }
   // Wrapper around operator delete
   static void delete__lepton_photon_(void *p) {
      delete ((::_lepton_photon_*)p);
   }
   static void deleteArray__lepton_photon_(void *p) {
      delete [] ((::_lepton_photon_*)p);
   }
   static void destruct__lepton_photon_(void *p) {
      typedef ::_lepton_photon_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_lepton_photon_

//______________________________________________________________________________
void _dilepton_photon_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _dilepton_photon_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_dilepton_photon_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_dilepton_photon_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__dilepton_photon_(void *p) {
      return  p ? new(p) ::_dilepton_photon_ : new ::_dilepton_photon_;
   }
   static void *newArray__dilepton_photon_(Long_t nElements, void *p) {
      return p ? new(p) ::_dilepton_photon_[nElements] : new ::_dilepton_photon_[nElements];
   }
   // Wrapper around operator delete
   static void delete__dilepton_photon_(void *p) {
      delete ((::_dilepton_photon_*)p);
   }
   static void deleteArray__dilepton_photon_(void *p) {
      delete [] ((::_dilepton_photon_*)p);
   }
   static void destruct__dilepton_photon_(void *p) {
      typedef ::_dilepton_photon_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_dilepton_photon_

//______________________________________________________________________________
void _event_::Streamer(TBuffer &R__b)
{
   // Stream an object of class _event_.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(_event_::Class(),this);
   } else {
      R__b.WriteClassBuffer(_event_::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new__event_(void *p) {
      return  p ? new(p) ::_event_ : new ::_event_;
   }
   static void *newArray__event_(Long_t nElements, void *p) {
      return p ? new(p) ::_event_[nElements] : new ::_event_[nElements];
   }
   // Wrapper around operator delete
   static void delete__event_(void *p) {
      delete ((::_event_*)p);
   }
   static void deleteArray__event_(void *p) {
      delete [] ((::_event_*)p);
   }
   static void destruct__event_(void *p) {
      typedef ::_event_ current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_event_

namespace {
  void TriggerDictionaryInitialization_kinematicsDict_Impl() {
    static const char* headers[] = {
"kinematics.h",
0
    };
    static const char* includePaths[] = {
"/cvmfs/cms.cern.ch/slc6_amd64_gcc530/lcg/root/6.08.04/include",
"/uscms_data/d2/ptan/work/sl6/production/CMSSW_8_4_0/src/Analysis_GEN/WZEdmAnalyzer/src/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "kinematicsDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _event_filterBit_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _gen_eventInfo_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _mc_process_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _gen_ttbar_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _gen_DrellYan_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _genwz_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _vec4_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _met_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _track_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _trg_bits_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _hlt_info_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _mets_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _dileadingjets_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _run_info_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _vertex_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _l1_obj_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _supercluster_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _photon_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _electron_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _beam_spot_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _muon_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _gen_jet_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _jet_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _di_jet_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _W_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _di_lepton_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _tri_lepton_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _quar_lepton_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _lepton_photon_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _dilepton_photon_;
class __attribute__((annotate("$clingAutoload$kinematics.h")))  _event_;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "kinematicsDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "kinematics.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"_W_", payloadCode, "@",
"_beam_spot_", payloadCode, "@",
"_di_jet_", payloadCode, "@",
"_di_lepton_", payloadCode, "@",
"_dileadingjets_", payloadCode, "@",
"_dilepton_photon_", payloadCode, "@",
"_electron_", payloadCode, "@",
"_event_", payloadCode, "@",
"_event_filterBit_", payloadCode, "@",
"_gen_DrellYan_", payloadCode, "@",
"_gen_eventInfo_", payloadCode, "@",
"_gen_jet_", payloadCode, "@",
"_gen_ttbar_", payloadCode, "@",
"_genwz_", payloadCode, "@",
"_hlt_info_", payloadCode, "@",
"_jet_", payloadCode, "@",
"_l1_obj_", payloadCode, "@",
"_lepton_photon_", payloadCode, "@",
"_mc_process_", payloadCode, "@",
"_met_", payloadCode, "@",
"_mets_", payloadCode, "@",
"_muon_", payloadCode, "@",
"_photon_", payloadCode, "@",
"_quar_lepton_", payloadCode, "@",
"_run_info_", payloadCode, "@",
"_supercluster_", payloadCode, "@",
"_track_", payloadCode, "@",
"_trg_bits_", payloadCode, "@",
"_tri_lepton_", payloadCode, "@",
"_vec4_", payloadCode, "@",
"_vertex_", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("kinematicsDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_kinematicsDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_kinematicsDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_kinematicsDict() {
  TriggerDictionaryInitialization_kinematicsDict_Impl();
}
