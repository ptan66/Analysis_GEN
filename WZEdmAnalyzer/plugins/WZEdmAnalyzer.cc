#include "WZEdmAnalyzer.h"
#include <memory>
#include <string>
#include <iostream>
#include <iomanip>
#include "math.h"


// user include files
#include "DataFormats/Math/interface/Point3D.h"


#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/Run.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"


#include "DataFormats/GeometryVector/interface/GlobalVector.h"
#include "DataFormats/GeometryVector/interface/GlobalPoint.h"


#include "DataFormats/L1Trigger/interface/L1ParticleMap.h"
#include "DataFormats/L1Trigger/interface/L1EmParticle.h"
#include "DataFormats/L1Trigger/interface/L1JetParticle.h"
#include "DataFormats/L1Trigger/interface/L1MuonParticle.h"
#include "DataFormats/L1Trigger/interface/L1EtMissParticle.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutRecord.h"

#include "DataFormats/JetReco/interface/CaloJetCollection.h"
#include "DataFormats/JetReco/interface/Jet.h"

#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/EgammaCandidates/interface/PhotonFwd.h"


#include "SimDataFormats/Track/interface/SimTrack.h"
#include "SimDataFormats/Track/interface/SimTrackContainer.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "DataFormats/TrackingRecHit/interface/TrackingRecHitFwd.h"
#include "DataFormats/TrackingRecHit/interface/TrackingRecHit.h"

#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackReco/interface/TrackExtraFwd.h"
#include "DataFormats/SiStripDetId/interface/SiStripDetId.h"

#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/JetReco/interface/JetTracksAssociation.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/CaloTowers/interface/CaloTowerCollection.h"
#include "DataFormats/Math/interface/Vector3D.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/METReco/interface/CaloMETCollection.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"


#include "MagneticField/Engine/interface/MagneticField.h"
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"


// Math
#include "Math/GenVector/VectorUtil.h"
#include "Math/GenVector/PxPyPzE4D.h"


// MC truth matching
//#include "RecoBTag/MCTools/interface/JetFlavour.h"
//#include "RecoBTag/MCTools/interface/JetFlavourIdentifier.h"
#include <SimDataFormats/Track/interface/SimTrack.h>
#include <SimDataFormats/Track/interface/SimTrackContainer.h>
#include "HepMC/GenEvent.h"

#include "DataFormats/BTauReco/interface/JetTag.h"
//#include "DataFormats/BTauReco/interface/JetTagFwd.h"


#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"


// luminosity
//#include "DataFormats/Luminosity/interface/LumiSummary.h"



// UserCode
//#include "QGLikelihoodCalculator.h"




// 
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "TTree.h"
#include "TNtuple.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include "TF1.h"
#include "TRandom.h"

//#include "kinematics.h"
#include "AnalysisTools.h"
#include "EdmAnalysisTools.h"
#include "lhapdfcc.h"


using namespace std;

using namespace edm;
using namespace reco;
using namespace l1extra ;
using namespace lhef;

WZEdmAnalyzer::WZEdmAnalyzer(const edm::ParameterSet& iConfig) :
  _is_debug(                   iConfig.getParameter<bool>("DEBUG")),
  _is_data(                    iConfig.getParameter<bool>("DATA")),
  _gen_only(                   iConfig.getParameter<bool>("GEN_ONLY")),
  _mc_signal(                  iConfig.getParameter<bool>("MC_SIGNAL")),
  GeneratorLevelTag_(          iConfig.getParameter<std::string>("GeneratorLevelTag")),
  LHEEventProductTag_(         iConfig.getParameter<edm::InputTag>("LHEEventProductTag")) {

  //,
  //  out(                         iConfig.getParameter<std::string>("out")),
  //  open(                        iConfig.getParameter<std::string>("open")),
  //  pdf(                         iConfig.getParameter<std::string>("pdf")),
  //  subset(                      iConfig.getParameter<int>("subset")) {


  this->displayConfig();
  totalProcessedEvts = 0;


  TClass::GetClass("_event_filterBit_")->SetCanSplit(true);
  TClass::GetClass("_gen_eventInfo_")->SetCanSplit(true);
  TClass::GetClass("_gen_ttbar_")->SetCanSplit(true);
  TClass::GetClass("_gen_DrellYan_")->SetCanSplit(true);
  TClass::GetClass("_mc_process_")->SetCanSplit(true);
  TClass::GetClass("_genwz_")->SetCanSplit(true);
  TClass::GetClass("_vec4_")->SetCanSplit(true);
  TClass::GetClass("_trg_bits_")->SetCanSplit(true);
  TClass::GetClass("_hlt_info_")->SetCanSplit(true);
  TClass::GetClass("_met_")->SetCanSplit(true);
  TClass::GetClass("_mets_")->SetCanSplit(true);
  TClass::GetClass("_dileadingjets_")->SetCanSplit(true);
  TClass::GetClass("_run_info_")->SetCanSplit(true);
  TClass::GetClass("_vertex_")->SetCanSplit(true);
  TClass::GetClass("_l1_obj_")->SetCanSplit(true);
  TClass::GetClass("_supercluster_")->SetCanSplit(true);
  TClass::GetClass("_photon_")->SetCanSplit(true);
  TClass::GetClass("_electron_")->SetCanSplit(true);
  TClass::GetClass("_beam_spot_")->SetCanSplit(true);
  TClass::GetClass("_track_")->SetCanSplit(true);
  TClass::GetClass("_muon_")->SetCanSplit(true);
  TClass::GetClass("_jet_")->SetCanSplit(true);
  TClass::GetClass("_di_jet_")->SetCanSplit(true);
  TClass::GetClass("_gen_jet_")->SetCanSplit(true);
  TClass::GetClass("_W_")->SetCanSplit(true);
  TClass::GetClass("_di_lepton_")->SetCanSplit(true);
  TClass::GetClass("_tri_lepton_")->SetCanSplit(true);
  TClass::GetClass("_quar_lepton_")->SetCanSplit(true);
  TClass::GetClass("_lepton_photon_")->SetCanSplit(true);
  TClass::GetClass("_dilepton_photon_")->SetCanSplit(true);
  TClass::GetClass("_event_")->SetCanSplit(true);


 

  // use TFile service?
  //  edm::Service< TFileService > fs_;
  ntuple = fs->make<TTree>("ntuple","ntuple");

  myEvent = new _event_();
  ntuple->Branch("ewk_asym", "_event_", &myEvent, 32000, 99); 
  if (_is_debug) std::cout << "check point ... finishing BeginJob() " << std::endl; 
}


WZEdmAnalyzer::~WZEdmAnalyzer()
{
  
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
  
}


/*************************************************************************                                                             
 *                                                                                                                                         
 * main event loop                                                        
 * few levels:
 * 1) gen candidates only
 * 2)                                                                  
 *                                                                                                                                         
 **************************************************************************/                                                               

void 
WZEdmAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup){


  if (totalProcessedEvts<=10) std::cout << "is real data ? " << iEvent.isRealData()<< std::endl;
  if (_is_debug)  std::cout << "check point ... process event " << std::endl;
  totalProcessedEvts ++;


  myEvent->Clear();  
  _is_save = false;  // default will not save the event
  




  // std::cout << "check point ... process event " << std::endl;

  myEvent->setEventNum(             iEvent.id().event());
  myEvent->setRunNum(               iEvent.id().run());
  myEvent->setLumiBlock(            iEvent.luminosityBlock() );
  myEvent->setBunchCrossing(        iEvent.bunchCrossing());
  myEvent->setOrbitNum(             iEvent.orbitNumber());


  //  std::cout << " average luminosity in ["
  //    << setw( 8) 
  //	    <<  iEvent.luminosityBlock() << "] = " 
  //    << avgInstLumi << std::endl;

  
  const edm::Timestamp timeStamp =  iEvent.time();
  unsigned int high = timeStamp.value() >> 32;       // seconds
  unsigned int low  = 0xffffffff & timeStamp.value(); // microseconds  
  myEvent->setTimeHigh( high );     myEvent->setTimeHigh( low );
  if (_is_debug) {
    std::cout << "Run number: "   << iEvent.id().event() << std::endl;
    std::cout << "Event number: " << iEvent.id().run() << std::endl;
  }
  


  // (++). Process only generator information
  _mc_process_ *myMCTruth =  myEvent->getMCInfo();    
  //  myGenWZ   =  myEvent->getGenWZ(); 

  iEvent.getByLabel( "genParticles",        genParticles );
  bool hasLHE = //iEvent.getByType( lheEventInfo );
    iEvent.getByLabel( LHEEventProductTag_, lheEventInfo );

  if (hasLHE)  copyLHEweights( myEvent, lheEventInfo.product() );

  this->fillMCInfo(genParticles,            myMCTruth);
  //  this->fillGenWZ(genParticles,             myGenWZ);
  this->fillGenTTbar(genParticles,          myEvent->getGenTTbar() );
  //      this->fillGenDrellYan(genParticles,       myEvent->getGenDrellYan() );
  if (hasLHE) {
    this->fillGenDrellYan(genParticles,       lheEventInfo.product() , myEvent->getGenDrellYan() );
  } else {

    this->fillGenDrellYan(genParticles,       0 , myEvent->getGenDrellYan() );

  }

  _is_save = true; // if generator level, all events will be save.
  ntuple->Fill();
  return;
}


void 
WZEdmAnalyzer::beginJob() 
{ 
}

void
WZEdmAnalyzer::beginRun(edm::Run const & iRun, edm::EventSetup const& iSetup)
{

}

void 
WZEdmAnalyzer::endJob() 
{

  //  write results into disk
  std::cout << "MY INFORMATION: total processed events " << totalProcessedEvts << std::endl;
  
  //  hFile ->cd();
  // ntuple->Write();
  // hFile ->Write();
  // hFile ->Close();

  return;
}



// ------------ method called when starting to processes a luminosity block  ------------
void 
WZEdmAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&iLumiBlock, edm::EventSetup const&iSetup)
{


  // access lumi-block averaged 
  avgInstLumi = 0;

}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
WZEdmAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&iLumiBlock, edm::EventSetup const&iSetup)
{
}

/**************************************************************************                                                                
 *                                                                                                                                         
 *                                                                                                                                         
 *                                                                                                                                         
 **************************************************************************/                                                               
void 
WZEdmAnalyzer::displayConfig(void)
{

  std::cout << std::endl;
  std::cout <<setw(12) <<""<< "   configuration settings    "         << std::endl;
  std::cout <<setw(12) <<"*"<< "******************************"         << "*" << std::endl;
  std::cout <<right<< setw(12) <<"*"<<setw(25)<< left<< "  Debug flag ------ "<< setw(5)<< _is_debug    <<"*"<< std::endl;
  std::cout <<right<< setw(12) <<"*"<<setw(25)<< left<< "  Data  flag ------ "<< setw(5)<< _is_data     <<"*"<< std::endl;
  std::cout <<right<< setw(12) <<"*"<<setw(25)<< left<< "  Signal MC flag -- "  << setw(5)<< _mc_signal   <<"*"<< std::endl;
  std::cout <<right<< setw(12) <<"*"<<setw(25)<< left<< "  Gen event flag -- "  << setw(5)<< _gen_only    <<"*"<< std::endl;
  std::cout <<right<< setw(12) <<"*"<< "******************************"         <<"*"<< std::endl;

  return;
}


//define this as a plug-in
DEFINE_FWK_MODULE(WZEdmAnalyzer);
