#ifndef _WZEdmAnalyzer_
#define _WZEdmAnalyzer_


#include <memory>
#include <string>
#include <iostream>
#include "math.h"
#include <map>


// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/CaloTowers/interface/CaloTowerCollection.h"



#include <SimDataFormats/GeneratorProducts/interface/HepMCProduct.h>
#include "SimDataFormats/GeneratorProducts/interface/GenRunInfoProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "SimDataFormats/Track/interface/SimTrack.h"
#include "SimDataFormats/Track/interface/SimTrackContainer.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"




#include "HepMC/GenEvent.h"
#include "HepMC/SimpleVector.h"


#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/Math/interface/Vector3D.h"


#include "Math/GenVector/VectorUtil.h"
#include "Math/GenVector/PxPyPzE4D.h"



// luminosity
#include "DataFormats/Luminosity/interface/LumiSummary.h"





// ROOT libraries and user defined
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "CommonTools/Utils/interface/TFileDirectory.h"

#include "TTree.h"
#include "TNtuple.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include "TF1.h"
#include "TRandom.h"

#include "kinematics.h"
#include "AnalysisTools.h"
#include "lhapdfcc.h"

using namespace edm;
using namespace reco;
using namespace std;


  


class WZEdmAnalyzer : public edm::EDAnalyzer {



 protected:

  void   setDebugPoint(  void) {  _is_debug = true;}
  void   clearDebugPoint(void){ _is_debug = false;}

 public:



  
  explicit WZEdmAnalyzer(const edm::ParameterSet&);
  ~WZEdmAnalyzer();


 private:


  virtual void beginJob() ;
  virtual void beginRun(edm::Run const &, edm::EventSetup const&);
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  virtual void beginLuminosityBlock(edm::LuminosityBlock const&iLumiBlock, edm::EventSetup const&iSetup);
  virtual void endLuminosityBlock(edm::LuminosityBlock const&iLumiBlock, edm::EventSetup const&iSetup);

  

  void   displayConfig(void);


  void   fillGenEventInfo(edm::Handle<GenEventInfoProduct> &genEvtInfo, _gen_eventInfo_ *myGenEvtInfo);

  void   copyLHEweights(_event_ *myevt,  const LHEEventProduct * LHEevt);

  void   fillMCInfo(Handle<edm::HepMCProduct>  &mcTruth,   _mc_process_ *mc);
  void   fillMCInfo(Handle<reco::GenParticleCollection> &genParticles,  _mc_process_ *mc);
  void   fillGenTTbar(Handle<reco::GenParticleCollection> &genParticles,  _gen_ttbar_ *genttbar);
  void   fillGenDrellYan(Handle<reco::GenParticleCollection> &genParticles, const LHEEventProduct * evt,  _gen_DrellYan_ *gendrellyan);

  const Candidate *genLevelLeptons(       const Candidate *born_level, math::PtEtaPhiMLorentzVector &dressed);

  // for FSR photos produced with PHOTOS
  const Candidate *genLevelLeptonsPhotos( const Candidate *alevel, math::PtEtaPhiMLorentzVector &dressed);



  //void   fillRunInfo(  void);



 protected:

  // control flags from the configuration files
  bool              _is_debug;  // output debug information
  bool              _is_data;   // data or MC
  bool              _gen_only;  // dealing with gen events only
  bool              _mc_signal; // determine if it is signal MC


  float              avgInstLumi;

  edm::InputTag      GeneratorLevelTag_;
  edm::InputTag      LHEEventProductTag_;


  Handle<edm::HepMCProduct>                       mcTruth;
  Handle<reco::GenParticleCollection>             genParticles;
  edm::Handle<GenEventInfoProduct>                genEventInfo;

  Handle<LHEEventProduct>                         lheEventInfo;

  Handle< int >                        genProcessID;
  Handle< double >                     genEventScale;
  Handle< GenRunInfoProduct >          runInfo;
  Handle< double >                     evtWeight;

  const HepMC::GenEvent                *genEvt;



  edm::Service< TFileService > fs;
  //  TFile                    *hFile;
  TTree                    *ntuple;
  _event_                  *myEvent;        // event setup
  


  Int_t                     evtNum, runNum;
  Int_t                     totalProcessedEvts;


  bool _is_save;
};

#endif
