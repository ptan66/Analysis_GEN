#include "assert.h"
#include "math.h"

#include "kinematics.h"

ClassImp(_gen_ttbar_)
ClassImp(_gen_DrellYan_)
ClassImp(_event_filterBit_)
ClassImp(_gen_eventInfo_)
ClassImp(_mc_process_)
ClassImp(_genwz_)
ClassImp(_vec4_)
ClassImp(_trg_bits_)
ClassImp(_hlt_info_)
ClassImp(_met_)
ClassImp(_mets_)
ClassImp(_dileadingjets_)
ClassImp(_run_info_)
ClassImp(_vertex_)
ClassImp(_l1_obj_)
ClassImp(_supercluster_)
ClassImp(_photon_)
ClassImp(_electron_)
ClassImp(_beam_spot_)
ClassImp(_track_)
ClassImp(_muon_)
ClassImp(_jet_)
ClassImp(_di_jet_)
ClassImp(_gen_jet_)
ClassImp(_W_)
ClassImp(_di_lepton_)
ClassImp(_tri_lepton_)
ClassImp(_quar_lepton_)
ClassImp(_lepton_photon_)
ClassImp(_dilepton_photon_)
ClassImp(_event_)

using namespace std;


_event_filterBit_::_event_filterBit_ (const _event_filterBit_ & orig) : TObject(orig){}
void _event_filterBit_::Initialize() {

  trackingFailureFilter = true;


  EcalDeadCellTriggerPrimitiveFilter =false;
  ecalLaserCorrFilter                =false;
  eeBadScFilter                      =false;

  hcalLaserEventFilter               =false;
  CSCTightHaloFilter                 =false;


  genericFilter0 = false;
  genericFilter1 = false;
  genericFilter2 = false;


}



_gen_eventInfo_::_gen_eventInfo_ (const _gen_eventInfo_ & orig) : TObject(orig){}
void _gen_eventInfo_::Initialize() {

  x1              = DEFAULT_VAL;
  x2              = DEFAULT_VAL;
  flav1           = DEFAULT_VAL;
  flav2           = DEFAULT_VAL;
  xfx1            = DEFAULT_VAL; 
  xfx2            = DEFAULT_VAL;
  scalePDF        = DEFAULT_VAL; // Q valued used in PDF evolution.


  // eventInfo
  weight          = 1.0;
  signalProcessID = DEFAULT_VAL;
  qScale          = DEFAULT_VAL;
  alphaQCD        = DEFAULT_VAL;
  alphaQED        = DEFAULT_VAL;
  hasPDF          = 0;


}





//  copy constructors
_gen_ttbar_::_gen_ttbar_ (const _gen_ttbar_ & orig) : TObject(orig){}
void _gen_ttbar_::Initialize() {

  ttbarPt         =    0;
  ttbarM       =    0;
  ttbarEta   =    0;
  ttbarPhi        =    0;



   mom1Pt= 0; mom1Eta= 0; mom1M= 0; mom1Phi= 0; mom1ID=0;
   mom2Pt= 0; mom2Eta= 0; mom2M= 0; mom2Phi= 0; mom2ID=0;


   
   tPt= 0; tM= 0; tEta= 0; tPhi= 0; tID= 0 ;
  
   
   twPt = 0; twM = 0; twEta = 0; twPhi = 0; twID= 0;
   
   twlPt = 0; twlM = 0; twlEta = 0; twlPhi = 0; twlID= 0;
   
   twvPt = 0; twvM = 0; twvEta = 0; twvPhi = 0; twvID= 0;
   
   tbPt = 0; tbM = 0; tbEta = 0; tbPhi = 0; tbID= 0;
   tjPt = 0; tjM = 0; tjEta = 0; tjPhi = 0; tjID= 0;


   tbarPt = 0; tbarM = 0; tbarEta = 0; tbarPhi = 0; tbarID= 0;

   tbarwPt = 0; tbarwM = 0; tbarwEta = 0; tbarwPhi = 0; tbarwID= 0;
   tbarwlPt = 0; tbarwlM = 0; tbarwlEta = 0; tbarwlPhi = 0; tbarwlID= 0;
   tbarwvPt = 0; tbarwvM = 0; tbarwvEta = 0; tbarwvPhi = 0; tbarwvID= 0;

   tbarbPt = 0; tbarbM = 0; tbarbEta = 0; tbarbPhi = 0; tbarbID= 0;
   tbarjPt = 0; tbarjM = 0; tbarjEta = 0; tbarjPhi = 0; tbarjID= 0;

}



//  copy constructors
_gen_DrellYan_::_gen_DrellYan_ (const _gen_DrellYan_ & orig) : TObject(orig){}
void _gen_DrellYan_::Initialize() {


   mom1Pt= 0; mom1Eta= 0; mom1M= 0; mom1Phi= 0; mom1ID=0;
   mom2Pt= 0; mom2Eta= 0; mom2M= 0; mom2Phi= 0; mom2ID=0;


   bosPt= 0; bosEta= 0; bosM= 0; bosPhi= 0; bosID=0;
   pdaugPt= 0; pdaugEta= 0; pdaugM= 0; pdaugPhi= 0; pdaugID=0;
   pdaugPtFSR= 0; pdaugEtaFSR= 0; pdaugMFSR= 0; pdaugPhiFSR= 0; 
   pdaugPtDress= 0; pdaugEtaDress= 0; pdaugMDress= 0; pdaugPhiDress= 0; 


   mdaugPt= 0; mdaugEta= 0; mdaugM= 0; mdaugPhi= 0; mdaugID=0;
   mdaugPtFSR= 0; mdaugEtaFSR= 0; mdaugMFSR= 0; mdaugPhiFSR= 0; 
   mdaugPtDress= 0; mdaugEtaDress= 0; mdaugMDress= 0; mdaugPhiDress= 0; 

   numberOfJets=0;
   numOfParticles=0; 


   // x1              = DEFAULT_VAL;
   // x2              = DEFAULT_VAL;
   // flav1           = DEFAULT_VAL;
   // flav2           = DEFAULT_VAL;
   // xfx1            = DEFAULT_VAL; 
   // xfx2            = DEFAULT_VAL;
   // scalePDF        = DEFAULT_VAL; // Q valued used in PDF evolution.


   for (int ii =0; ii < EDM_MAX_LENGTH; ii ++) {
     jpid[ii] = 0;
     mepid[ii*2] =0;
     mepid[ii*2+1] =0;
     
     for (int jj = 0; jj < 4; jj ++)   jv4[ii][jj] =0;
     

     for (int kk =0; kk < 5; kk ++)   {
       mev4[ ii*2 ][kk] = 0;
       mev4[ ii*2 + 1][kk] = 0;
     }
     
   }

}



//  copy constructors
_mc_process_::_mc_process_ (const _mc_process_ & orig) : TObject(orig){}
void _mc_process_::Initialize() {

  mpi         = 0;
  processId   = 0;
  eventNumber = 0;
  vtxBarcode  = 0;
  eventScale  = 0;
  alphaQCD    = 0;
  alphaQED    = 0;


  x1       = 0;
  x2       = 0;
  flav1    = 0;
  flav2    = 0;
  xfx1     = 0;
  xfx2     = 0;
  scalePDF = 0; 


  decayType    = 0;
  bosId        = 0;
  bosPt        = 0;
  bosPz        = 0;
  bosMass      = 0;
  bosEta       = -999;
  bosPhi       = -999;
  bosRap       = -999;
  dileptonPt   = 0;
  dileptonPz   = 0;
  dileptonMass = 0;
  dileptonEta  = -999;
  dileptonRap  = -999;
  dileptonPhi  = -999;
  cosTheta     = 0;
  nphotons     = 0;


  muonEnergy   = 0;
  muonPt       = 0;
  muonPz       = 0;
  muonEta      = -999;
  muonPhi      = -999;
  muonId       =0;
  muonBarEnergy= 0;
  muonBarPt    = 0;
  muonBarPz    = 0;
  muonBarEta   = -999;
  muonBarPhi   = -999;
  muonBarId    = 0; 

  nrmuonEnergy   = 0;
  nrmuonPt       = 0;
  nrmuonPz       = 0;
  nrmuonEta      = -999;
  nrmuonPhi      = -999;
  nrmuonId       =0;
  nrmuonBarEnergy= 0;
  nrmuonBarPt    = 0;
  nrmuonBarPz    = 0;
  nrmuonBarEta   = -999;
  nrmuonBarPhi   = -999;
  nrmuonBarId    = 0; 


  photonEnergy = 0;
  photonPhi    = 0; 
  photonEta    = 0;
  photonAngle  = 0;

  cosThetaCS = 0; 
  qqbar      = 0; 
  qbarq      = 0; 
  mistag     = 0;

  metX = 0;
  metY = 0;

  delta = 0;
  fprob = 0;
  bprob = 0;
}

// For WZ signal MC
_genwz_::_genwz_ (const _genwz_ & orig) : TObject(orig){}
void _genwz_::Initialize() {

  Z_decayType    = 0;
  Z_bosId        = 0;
  Z_bosPt        = 0;
  Z_bosPz        = 0;
  Z_bosMass      = 0;
  Z_bosEta       = -999;
  Z_bosPhi       = -999;
  Z_bosRap       = -999;
  Z_dauAEnergy   = 0;
  Z_dauAPt       = 0;
  Z_dauAPz       = 0;
  Z_dauAEta      = -999;
  Z_dauAPhi      = -999;
  Z_dauAId       = 0;
  Z_dauBEnergy   = 0;
  Z_dauBPt       = 0;
  Z_dauBPz       = 0;
  Z_dauBEta      = -999;
  Z_dauBPhi      = -999;
  Z_dauBId       = 0; 
  Z_dileptonPt   = 0;
  Z_dileptonPz   = 0;
  Z_dileptonMass = 0;
  Z_dileptonEta  = -999;
  Z_dileptonRap  = -999;
  Z_dileptonPhi  = -999;
  Z_cosTheta     = 0;
  Z_cosPhi       = 0;
  Z_nphotons     = 0;
  Z_phoEnergy    = 0;
  Z_phoPhi       = 0; 
  Z_phoEta       = 0;
  Z_phoAngle     = 0;

  W_decayType    = 0;
  W_bosId        = 0;
  W_bosPt        = 0;
  W_bosPz        = 0;
  W_bosMass      = 0;
  W_bosEta       = -999;
  W_bosPhi       = -999;
  W_bosRap       = -999;
  W_dauAEnergy   = 0;
  W_dauAPt       = 0;
  W_dauAPz       = 0;
  W_dauAEta      = -999;
  W_dauAPhi      = -999;
  W_dauAId       = 0;
  W_dauBEnergy   = 0;
  W_dauBPt       = 0;
  W_dauBPz       = 0;
  W_dauBEta      = -999;
  W_dauBPhi      = -999;
  W_dauBId       = 0; 
  W_dileptonPt   = 0;
  W_dileptonPz   = 0;
  W_dileptonMass = 0;
  W_dileptonEta  = -999;
  W_dileptonRap  = -999;
  W_dileptonPhi  = -999;
  W_cosTheta     = 0;
  W_cosPhi       = 0;
  W_nphotons     = 0;
  W_phoEnergy    = 0;
  W_phoPhi       = 0; 
  W_phoEta       = 0;
  W_phoAngle     = 0;

  gdWZ           = 0;
  WZ_Pt          = 0;
  WZ_Pz          = 0;
  WZ_Mass        = 0;
  WZ_Eta         = -999;
  WZ_Phi         = -999;
  WZ_Rap         = -999;
  WZ_cosAngZ     = 0;
  WZ_cosAngW     = 0;


}

// data block for run information
_vec4_::_vec4_() {

  id = 0;
  pt = 0; 
  eta = 0;
  phi = 0;
}
_vec4_::_vec4_(const _vec4_ & orig) : TObject(orig) {}
_vec4_::~_vec4_() {Clear();}


// data block for run information
_met_::_met_() {
  e_longitudinal =0;
  sumEt = 0;
  id = 0;
  pt = 0; 
  eta = 0;
  phi = 0;
}




_met_::_met_(const _met_ & orig) {}
_met_::~_met_() {Clear();}
void _met_::init(void) {

  this->pt = -990;
  this->phi = 0;
  this->sumEt = 0;
  this->HadronicEtFraction =0;
  this->EMEtFraction =0;
  this->MuonEtFraction =0;
  this->InvisibleEtFraction =0;
  this->e_longitudinal =0;

}



_trg_bits_::_trg_bits_() {

  for (int ii = 0; ii < MAX_TRIG_WORD; ii ++) {

    l1TrgBits[ii]     = 0; 
    l1tTrgBits[ii]    = 0; 
    hltAccTrgBits[ii] = 0;
    hltRunTrgBits[ii] = 0;
    hltErrTrgBits[ii] = 0;

  }
}
_trg_bits_::_trg_bits_(const _trg_bits_ & orig) : TObject(orig) {}
_trg_bits_::~_trg_bits_() {Clear();}

void _trg_bits_::setL1TrgBits(ULong_t *bits) {
  for (int ii = 0; ii < MAX_TRIG_WORD; ii ++) {

    l1TrgBits[ii] = bits[ii];
   }
}
void _trg_bits_::setL1TTrgBits(ULong_t *bits) {
  for (int ii = 0; ii < MAX_TRIG_WORD; ii ++) {

    l1tTrgBits[ii] = bits[ii];
  }
}
void _trg_bits_::setHLTAccTrgBits(ULong_t *bits) {
  for (int ii = 0; ii < MAX_TRIG_WORD; ii ++) {

    hltAccTrgBits[ii] = bits[ii];
  }
}
void _trg_bits_::setHLTRunTrgBits(ULong_t *bits) {
  for (int ii = 0; ii < MAX_TRIG_WORD; ii ++) {

    hltRunTrgBits[ii] = bits[ii];
  }
}
void _trg_bits_::setHLTErrTrgBits(ULong_t *bits) {
  for (int ii = 0; ii < MAX_TRIG_WORD; ii ++) {

    hltErrTrgBits[ii] = bits[ii];
  }
}




// data block for run information
_hlt_info_::_hlt_info_() {


  HLT_NonIsoMuon     = 0;
  HLT_Muon           = 0;
  HLT_MuonL          = 0;
  HLT_MuonH          = 0;

  HLT_MuonElectron   = 0;
  HLT_ElectronMuon   = 0;

  HLT_NonIsoElectron = 0;
  HLT_Electron       = 0;
  HLT_ElectronL      = 0;
}
_hlt_info_::_hlt_info_(const _hlt_info_ & orig) : TObject(orig) {}
_hlt_info_::~_hlt_info_() {Clear();}


// data block for run information
_mets_::_mets_() {


  caloMET.init();

  tcMET.init();
  pfMET.init();
  muonJESCorSC5MET.init();
  genMET.init();
  rawMET.init();

  pfType1CorrectedMet.init();
  pfType1p2CorrectedMet.init();

  //  corrPfMetType1.init();
  //  correctionTermsPfMetType0PFCandidate.init();
  // correctionTermsPfMetShiftXY.init();
  pfMetT0pc.init();
  pfMetT0pcT1.init();
  pfMetT0pcTxy.init();
  pfMetT0pcT1Txy.init();
  pfMetT1.init();
  pfMetT1Txy.init();
}
_mets_::_mets_(const _mets_ & orig) : TObject(orig) {}
_mets_::~_mets_() {Clear();}


_di_jet_::_di_jet_() {


  jetType = -1;
  charge=0;
  daughtA=-1;
  daughtB=-1;

  // results from vertex constrainted fit
 isValid =0;
  totalChiSquared=0; 
  chiSquaredProbability =0;


degreesOfFreedom=0;


vx=0; vy=0; vz=0;
vxError=0; vyError=0; vzError=0;

  pt=0;
  eta=0;
  phi=0;
  rapidity=0;
  mass=0;
}

_di_jet_::_di_jet_(const _di_jet_ & orig) : TObject(orig) {}
_di_jet_::~_di_jet_() {Clear();}



_dileadingjets_::_dileadingjets_() {

  charge=0;
  daughtA=-1;
  daughtB=-1;
  daughtAType=0;
  daughtBType=0;

  pt=0;
  eta=0;
  phi=0;
  ptx=0;
  pty=0;
  rapidity=0;
  mass=0;


}





_dileadingjets_::_dileadingjets_(const _dileadingjets_ & orig) : TObject(orig) {}
_dileadingjets_::~_dileadingjets_() {Clear();}
void _dileadingjets_::Initialize() {
  charge=0;
  daughtA=-1;
  daughtB=-1;
  daughtAType=0;
  daughtBType=0;

  pt=0;
  eta=0;
  phi=0;
  ptx=0;
  pty=0;
  rapidity=0;
  mass=0;
}


// data block for run information
_run_info_::_run_info_() {

  autoXSec = 0;
  extXsec  = 0;
  filterEff= 0;
}
_run_info_::_run_info_(const _run_info_ & orig) : TObject(orig) {}
_run_info_::~_run_info_() {Clear();}




_vertex_::_vertex_() {


  isValid = 0; isFake = 0;
  x = 0; y = 0; z = 0;
  xError = 0; yError = 0; zError = 0;


  tracksSize = 0;

  chi2 = 0;
  normalizedChi2 = 0;
  ndof = 0;


  validTracksSize = 0;
  validTracksSize200MeV = 0;
  validTracksSize500MeV = 0;
  validTracksSize1GeV = 0;

  sumPtMin =0;
  sumPtMin200MeV =0;
  sumPtMin500MeV =0;
  sumPtMin1GeV = 0;

  sumPt2Min =0;
  sumPt2Min200MeV =0;
  sumPt2Min500MeV =0;
  sumPt2Min1GeV = 0;


  thrust=0;
  sphericity=0;
  planarity=0;
aplanarity=0;

 muonIndex = -1;
 thrust_x = -999;
 thrust_y =-999;
 thrust_z = -999;
}
_vertex_::_vertex_(const _vertex_ & orig): TObject(orig) {}
_vertex_::~_vertex_() {Clear();}

_l1_obj_::_l1_obj_() {}
_l1_obj_::_l1_obj_(const _l1_obj_ & orig): TObject(orig) {}
_l1_obj_::~_l1_obj_() {Clear();}



_supercluster_::_supercluster_() {

   et=0; eta=0; phi=0;

   hasPixelSeed=0; hasConversionTracks=0;
     fiducialFlags=0;



  // shower shape
     sigmaEtaEta=0; sigmaIetaIeta=0; e1x5=0; e2x5=0; e3x3=0; e5x5=0; maxEnergyXtal=0; hadronicDepth1OverEm=0; hadronicDepth2OverEm=0;hadronicOverEm=0;
   r1x5=0; r2x5=0; r9=0;


   scRawEnergy=0; scPreshowerEnergy=0; scPhiWidth=0; scEtaWidth=0;
   scClustersSize=0; 

   cluster2ndMoments_sMaj = 0;
   cluster2ndMoments_sMin =0; 
   cluster2ndMoments_alpha =0; 


   energy=0; centroidX=0; centroidY=0; centroidZ=0;
   size=0;


}
_supercluster_::_supercluster_(const _supercluster_ & orig): TObject(orig) {}
_supercluster_::~_supercluster_() {Clear();}




_photon_::_photon_() {

   et=0; eta=0; phi=0;

   hasPixelSeed=0; hasConversionTracks=0;
     fiducialFlags=0;



  // shower shape
     sigmaEtaEta=0; sigmaIetaIeta=0; e1x5=0; e2x5=0; e3x3=0; e5x5=0; maxEnergyXtal=0; hadronicDepth1OverEm=0; hadronicDepth2OverEm=0;hadronicOverEm=0;
   r1x5=0; r2x5=0; r9=0;


  // Isolation variables
   ecalRecHitSumEtConeDR04=0; hcalTowerSumEtConeDR04=0; hcalDepth1TowerSumEtConeDR04=0; hcalDepth2TowerSumEtConeDR04=0;  trkSumPtSolidConeDR04=0; trkSumPtHollowConeDR04=0; nTrkSolidConeDR04=0; nTrkHollowConeDR04=0;

   ecalRecHitSumEtConeDR03=0; hcalTowerSumEtConeDR03=0; hcalDepth1TowerSumEtConeDR03=0; hcalDepth2TowerSumEtConeDR03=0;  trkSumPtSolidConeDR03=0; trkSumPtHollowConeDR03=0; nTrkSolidConeDR03=0; nTrkHollowConeDR03=0;


   // superclustr information
   scRawEnergy=0; scPreshowerEnergy=0; scPhiWidth=0; scEtaWidth=0;
   scClustersSize=0; 

   cluster2ndMoments_sMaj = 0;
   cluster2ndMoments_sMin =0; 
   cluster2ndMoments_alpha =0; 


   energy=0; centroidX=0; centroidY=0; centroidZ=0;
   size=0;


}
_photon_::_photon_(const _photon_ & orig): TObject(orig) {}
_photon_::~_photon_() {Clear();}



_electron_::_electron_():_track_() {


  // basic information
  classification=0;
  scPixCharge=0;isGsfCtfScPixChargeConsistent=0; isGsfScPixChargeConsistent=0;  isGsfCtfChargeConsistent=0;
  ecalDrivenSeed=0; trackerDrivenSeed=0;


  validKF = false;

  // Pure tracking variables
  fMVAVar_fbrem             =0;
  fMVAVar_kfchi2            =0;
  fMVAVar_gsfchi2           =0;
  fMVAVar_kfhits            =0;
  fMVAVar_kfhitsall         =0;

  
  // Geometrical matchings
  fMVAVar_deta              =-999;
  fMVAVar_dphi              =-999;
  fMVAVar_detacalo          =-999;
  fMVAVar_dphicalo          =-999;


  // Pure ECAL -> shower shapes
  fMVAVar_see               =0;
  fMVAVar_spp               =0;
  fMVAVar_sigmaIEtaIPhi     =0;


  fMVAVar_etawidth          =0; 
  fMVAVar_phiwidth          =0;
  fMVAVar_e1x5e5x5          =0;
  fMVAVar_R9                =0;
  fMVAVar_nbrems            =0;
 
  // Energy matching
  fMVAVar_HoE               =0;
  fMVAVar_EoP               =0;
  fMVAVar_IoEmIoP           =0;
  fMVAVar_eleEoPout         =0;
  fMVAVar_PreShowerOverRaw  =0;
  fMVAVar_EoPout            =0; 


 // Spectators
  fMVAVar_eta               =0;
  fMVAVar_pt                =0;

 // for triggering electrons get the impact parameteres
 //d0

  fMVAVar_d0                =0;
  fMVAVar_ip3d              =0;
  fMVAVar_ip3dSig           =0;
 /************ end of MVA variables ***************************/



  vtxFitConversion = 0;
  mHits = -1;

  numberOfLostHits = -1;

  swissCross=0, dist = 0, dcot = 0;
  isElFromConversion =0;
  numberOfExpectedInnerHits = 0;
  radiusOfConversion=0;
  deltaMissingHits =0;

  // superclustr information
  scEt=0; scEta=0; scPhi=0;

  energy=0; centroidX=0; centroidY=0; centroidZ=0;
  size=0;
  scRawEnergy=0; scPreshowerEnergy=0; scPhiWidth=0; scEtaWidth=0;
  scClustersSize=0; 

  // additional track information
  chargeMode=0;
  qoverpMode=0; lambdaMode=0; ptMode=0; phiMode=0; etaMode=0;
  qoverpModeError=0; lambdaModeError=0; ptModeError=0; phiModeError=0; etaModeError=0;

  // track-cluster matching 
   eSuperClusterOverP =0;        
   eSeedClusterOverP =0;         
   eSeedClusterOverPout =0;      
   eEleClusterOverPout =0;       
   deltaEtaSuperClusterTrackAtVtx =0; 
   deltaEtaSeedClusterTrackAtCalo =0; 
   deltaEtaEleClusterTrackAtCalo =0;  
   deltaPhiEleClusterTrackAtCalo =0;  
   deltaPhiSuperClusterTrackAtVtx =0; 
   deltaPhiSeedClusterTrackAtCalo =0; 

   fiducialFlags=0;


  // isolation variables
   dr03TkSumPt=0; dr03EcalRecHitSumEt=0; dr03HcalDepth1TowerSumEt=0; dr03HcalDepth2TowerSumEt=0; dr03HcalTowerSumEt=0;
   dr04TkSumPt=0; dr04EcalRecHitSumEt=0; dr04HcalDepth1TowerSumEt=0; dr04HcalDepth2TowerSumEt=0; dr04HcalTowerSumEt=0;


   pfRelIsoR03                  =0;
   effArea                      =0;
   pfIsoCh                      =0; 
   pfIsoNeutral                 =0;
   pfIsoPhoton                  =0;
   pfIsoSumPUPt                 =0;

   pfRelIsoR03EA                =0;


   ecalPFClusterIso             =0;
   hcalPFClusterIso             =0;


  // shower shape variables
   sigmaEtaEta                  =0; 
   sigmaIetaIeta                =0; 
   full5x5_sigmaIetaIeta        =0;
   e1x5                         =0; 
   e2x5Max                      =0; 
   e5x5                         =0; 
   hcalDepth1OverEcal           =0; 
   hcalDepth2OverEcal           =0; 
   hcalOverEcal                 =0;
   hadronicOverEm               =0;




   // preselection info
   ecalDriven                   =0; 
   passingCutBasedPreselection  =0; 
   passingMvaPreselection       =0;
   mva                          =0;


  // brem
   fbrem                           =0;
   numberOfBrems                   =0;


  // 
   isMomentumCorrected             =0; 
   ecalEnergy                      =0; 
   correctedEcalEnergy             =0; 
   trackMomentumAtVtx              =0;
   ecalEnergyError                 =0; 
   trackMomentumError              =0; 
   electronMomentumError           =0;
   ooemoop                         =0;

   idBitMap                        =0;
   mvaIdBitMap                     =0;

   calibratedSCEt    = 0;
   calibratedSCEta   = 0;
   calibratedSCPhi   = 0;
   calibratedEnergy  = 0;


   regressionEnergy                =0;
   regressionEnergyError           =0;
   calibratedPt                    =0;
   calibratedEta                   =0;
   calibratedPhi                   =0;
   mvaTrigV0                       = -999;
   mvaNonTrigV0                    = -999;
   mvaTrigV0Cat                    = -999;
   mvaNonTrigV0Cat                 = -999;



}
_electron_::_electron_(const _electron_ & orig){}
_electron_::~_electron_() {Clear();}


_beam_spot_::_beam_spot_() {
  x0                               =0;
  y0                               =0;
  z0                               =0;
  x0Error                          =0;
  y0Error                          =0;
  z0Error                          =0;
  sigmaZ                           =0;
  sigmaZError                      =0;
  BeamWidthXError                  =0;
  BeamWidthYError                  =0;
}
_beam_spot_::_beam_spot_(const _beam_spot_ & orig){}
_beam_spot_::~_beam_spot_() {Clear();}


_track_::_track_() {


  vertexIndex                      = -1;
  associatedVertex                 = -1;
  closestVertexDist                = 9999;

  chi2                             = 0;
  normalizedChi2                   = 0;
  charge                           = 0;
  ndof                             = 0;
  
  pt                               = 0;
  eta                              = 0;
  phi                              = 0;
  ptError                          = 0;
  etaError                         = 0;
  phiError                         = 0;


  qoverp                           = 0;
  qoverpError                      = 0;
  lambda                           = 0;
  lambdaError                      = 0;
  
  dxy0                             = 0;
  dxy0Error                        = 0;
  dz0                              = 0;
  dz0Error                         = 0;
  dsz0                             = 0;
  dsz0Error                        = 0;
  
  dxy                              = 0; 
  dz                               = 0; 
  dsz                              = 0;
  

  // inner track with respecting to closest primary vertex. 
  dxyVtx                           =0; 
  dzVtx                            =0; 
  dszVtx                           =0;


  recHitsSize                      = 0;
  numberOfValidHits                = 0;
  nStereoHits                      = 0;
  outerRadius                      = 0;
  innerRadius                      = 0;
  
  numberOfValidPixelHits           = 0;
  numberOfValidStripHits           = 0;
  numberOfValidPixelBarrelHits     = 0;
  numberOfValidTrackerLayers       = 0;
  trackerLayersWithMeasurement     = 0;

  pixelLayersWithMeasurement       = 0;
  pixelBarrelLayersWithMeasurement = 0;
  pixelEndcapLayersWithMeasurement = 0;


  hasValidHitInFirstPixelBarrel    = 0;
  trackerExpectedHitsInner_numberOfHits = 0 ;


  mcType                           = 0;
  mcPt                             = 0;
  mcEta                            = 0;
  mcPhi                            = 0;
}
_track_::_track_ (const _track_ & orig) : TObject(orig){}
_track_::~_track_() {Clear();}



_muon_::_muon_ ():_track_() {

  muonType                         =0;

  // global track parameters
  // TeV Muon Refit
  refitCharge                      =0;
  refitPt                          =0;
  refitEta                         =0;
  refitPhi                         =0;

  refitPtError                          =0;
  refitEtaError                         =0;
  refitPhiError                         =0;

  refitDxy = 0;
  refitDz  = 0;
  isHighPtMuon = 0;


  globalDxy0                       =0; 
  globalDz0                        =0; 
  globalDsz0                       =0;
  
  globalDxy0Error                  =0; 
  globalDz0Error                   =0; 
  globalDsz0Error                  =0;
  globalDxy                        =0; 
  globalDz                         =0; 
  globalDsz                        =0;

  globalDxyVtx                     =0; 
  globalDzVtx                      =0; 
  globalDszVtx                     =0;
  
  globalRecHitsSize                =0; 
  globalNumberOfValidHits          =0; 
  globalCharge                     =0;
  globalPt                         =0; 
  globalEta                        =0; 
  globalPhi                        =0;
  globalPtError                    =0; 
  globalEtaError                   =0; 
  globalPhiError                   =0;
  globalNormalizedChi2             =0;
  globalNumberOfValidMuonHits      =0;  

   

  // outer track information
  outerPt                          =0; 
  outerEta                         =0; 
  outerPhi                         =0;
  outerPtError                     =0; 
  outerEtaError                    =0; 
  outerPhiError                    =0;
  outerRecHitsSize                 =0; 
  outerNumberOfValidHits           =0; 
  outerCharge                      =0; 
  outerInnerOk                     =0;
  

  //  Global variables
  numberOfChambers                 =0; 
  stationGapMaskPull               =0; 
  numberOfMatches                  =0;
  stationMask                      =0;
  numberOfMatchedStations          =0;

  // timing information
  timenDof                         =0; 
  isTimeValid                      =0;
  timeAtIPInOut                    =0; 
  timeAtIPInOutErr                 =0;
  timeAtIPOutIn                    =0; 
  timeAtIPOutInErr                 =0;
  
  // compatibility
  isCaloCompatibilityValid         =0;
  caloCompatibility                =0;
  
  // isolation
  isIsolationValid                 =0;
  isolationR03hadEt                = 0;
  isolationR03emEt                 = 0;
  isolationR03sumPt                = 0;
  isolationR03nTracks              = 0;
  isolationR05hadEt                = 0;
  isolationR05emEt                 = 0;
  isolationR05sumPt                = 0;
  isolationR05nTracks              = 0;


  isolationR03emVetoEt             =0; 
  isolationR03hadVetoEt            =0; 
  isolationR03hoVetoEt             =0; 
  isolationR05emVetoEt             =0; 
  isolationR05hadVetoEt            =0; 
  isolationR05hoVetoEt             =0; 
  

  // muon energy
  isEnergyValid                    =0;
  calEnergy                        =0; 
  calEnergyem                      =0; 
  calEnergyhad                     =0; 
  calEnergyho                      =0;
  calEnergyecal_time               =0; 
  calEnergyhcal_time               =0;
  calEnergyecal_timeError          =0; 
  calEnergyhcal_timeError          =0;
  


  // additional muon selector information: implemented Nov. 25, 2013
  improvedMuonBestTrackPt= 0;
  improvedMuonBestTrackPtError =0;
  improvedMuonBestTrackEta =0;
  improvedMuonBestTrackPhi =0;
  improvedMuonBestTrackCharge =0;
  //isHighPtMuon =0;


  isSoftMuon              = 0;
  isTightMuon              = 0;
  isGlobalMuon              = 0;
  isPFMuon                 = 0;
  bestMuonBestTrackDxy     = 9999;
  bestMuonBestTrackDz      = 9999;
  bestMuonBestTrackPt      = 0;
  bestMuonBestTrackPtError = 0;
  bestMuonBestTrackEta     = 0;
  bestMuonBestTrackPhi     = 0;
  bestMuonBestTrackCharge  = 0;

  pfIsolationR04           = 0;
  pfIsolationR04beta       = 0;


  pfIsolationWeighted      = 0;
  pfIsolationPUPPI         = 0;



}
_muon_::_muon_ (const _muon_ & orig) {}
_muon_::~_muon_() {Clear();}


_gen_jet_::_gen_jet_() {


  energy        = DEFAULT_VAL;
  pt            = DEFAULT_VAL;
  eta           = DEFAULT_VAL;
  phi           = DEFAULT_VAL;
  mass          = DEFAULT_VAL;
  mc_flavor     = DEFAULT_VAL;
  mc_partonFlavor = DEFAULT_VAL;
  nConstituent  = DEFAULT_VAL;
}
_gen_jet_::_gen_jet_ (const _gen_jet_ & orig) : TObject(orig){}
_gen_jet_::~_gen_jet_() {Clear();}



_jet_::_jet_() {


   pt=0;eta=0;phi=0;mass=0;
   energy = 0;
   physicsEta=0;physicsPt=0;physicsPhi=0;

     nConstituent=0;
   L2L3pt=0;L2L3scale=0;L4scale=0;L5scale=0;L6scale=0;L7scale=0;L8scale=0;
   pileup=0;
   area=0;
   L = 0;

   scaleUnc = 0;

   fHPD=0;
   fRBX=0;


  // calo jets
   n60=0;n90=0;emEnergyInEE=0;emEnergyInHF=0;emEnergyInEB=0;hadEnergyInHB=0;hadEnergyInHO=0;hadEnergyInHF=0;hadEnergyInHE=0;emEnergyFraction=0;energyFractionHadronic=0;maxEInEmTowers=0;maxEInHadTowers=0;



  // common between JPT and PF jet
  // for JPT jet the electronMultiplicity is (elecMultiplicity)
   muonMultiplicity=0;chargedMultiplicity=0;electronMultiplicity=0;
   chargedHadronEnergy=0;chargedHadronEnergyFraction=0;neutralHadronEnergy=0;neutralHadronEnergyFraction=0;
   chargedEmEnergy=0;chargedEmEnergyFraction=0;neutralEmEnergy=0;neutralEmEnergyFraction=0;


  // JPT jets
   zspCor=0;


  // PF jets
    photonEnergy=0;photonEnergyFraction=0;electronEnergy=0;electronEnergyFraction=0;muonEnergy=0;muonEnergyFraction=0;HFHadronEnergy=0;HFHadronEnergyFraction=0;HFEMEnergy=0;HFEMEnergyFraction=0;

   chargedHadronMultiplicity=0;neutralHadronMultiplicity=0;photonMultiplicity=0;HFHadronMultiplicity=0;HFEMMultiplicity=0;
   chargedMuEnergy=0;chargedMuEnergyFraction=0;
   neutralMultiplicity=0; 

   quarkGluonLikelihood = -9999;
   quarkGluonMLP = -9999;

   puIDFlag = 0; puIDMva= -9999;
   puIDLoose = false;
   puIDMedium= false;
   puIDTight = false;



  // MC information
   mc_flavor=DEFAULT_VAL;
   mc_partonFlavor = DEFAULT_VAL;
   mc_pt=0;mc_eta=0;mc_phi=0;


   for (int ii = 0; ii < EDM_MAX_LENGTH; ii ++) {

     tag[ii]    = -9999;
     flavor[ii] = -9999;

   }

   jetVertexnlIndex     = -1;
   jetVertexnlFrac      = -1;
   
   jetVertexIndex       = -1;
   jetVertexFrac        = -1;

   jetVertexnlIndexNum  = -1;
   jetVertexnlFracNum   = -1;
   
   jetVertexIndexNum    = -1;
   jetVertexFracNum     = -1;



   jetVertexIndexSum    = -1;
   jetVertexFracSum     = -1;
   jetVertexnlIndexSum  = -1;
   jetVertexnlFracSum   = -1;



   sum = 0;
   sumS = 0;
   sumN = 0;

   totsum = 0;
   totsumS = 0;
   totsumN = 0;


   dissum5     =0;
   dissum5S    =0;
   dissum5N    =0;
   dissum10    =0;
   dissum10S   =0;
   dissum10N   =0;
}


_jet_::_jet_ (const _jet_ & orig) : TObject(orig){}
_jet_::~_jet_() {Clear();}


/**************************************************************************
 *
 *   compositions of candidates.
 *
 **************************************************************************/
_W_::_W_() {

  leptonIndex=0;
  leptonType =0;


  recoWy1 =0;
  recoWy2 =0;
  delta =0;
}
_W_::_W_ (const _W_ & orig) : TObject(orig){}
_W_::~_W_() {Clear();}



_di_lepton_:: _di_lepton_() {


  x1=0;
  x2 =0;
  xfx1=0;
  xfx2=0;
  mistag=0;
  qqbar=0;
  qbarq=0; 


  charge=0;
  daughtA=-1;
  daughtB=-1;
  daughtAType=0;
  daughtBType=0;


  pt=0;
  eta=0;
  phi=0;
  rapidity=0;
  mass=0;

  // results from vertex constrainted fit
 isValid =0;
  totalChiSquared=0; 
  chiSquaredProbability =0;


degreesOfFreedom=0;

fittedMass=0;
vx=0; vy=0; vz=0;
vxError=0; vyError=0; vzError=0;

   e1=0;
   e2=0;
   cosPhiFit=0; // after refit
  
  // angles in rest frame of di-lepton pair following Collins-Soper convention
   cosPhi=0; // angle between the two muons. 
   cosTheta=0;
   cosThetaCS=0;
   sin2Theta=0;
   tanPhi=0;
}
_di_lepton_::_di_lepton_ (const _di_lepton_ & orig) : TObject(orig){}
_di_lepton_::~_di_lepton_() {Clear();}




_tri_lepton_::_tri_lepton_() {

  m12 = 0;
  eta12=0;
  pt12=0;
  phi12=0;
  mt3=0;

  m23=0;
  eta23=0;
  pt23=0;
  phi23=0;
  mt1=0;

  mass=0;
  eta=0;
  pt=0;
  phi=0;
  theta12=0;
  theta23=0;
  mt=0;
}
_tri_lepton_::_tri_lepton_ (const _tri_lepton_ & orig) : TObject(orig){}
_tri_lepton_::~_tri_lepton_() {Clear();}


_quar_lepton_::_quar_lepton_() {
  mass=0;
  pt=0;
  eta=0;
  phi=0;
}
_quar_lepton_::_quar_lepton_ (const _quar_lepton_ & orig) : TObject(orig){}
_quar_lepton_::~_quar_lepton_() {Clear();}




_lepton_photon_::_lepton_photon_() {
  charge=0;
  leptonIndex=0;
  photonIndex=0;
  leptonType=0;

  pt=0;
  eta=0;
  phi=0;
  rapidity=0;
  mass=0;

  cosPhi=0;
}
_lepton_photon_::_lepton_photon_ (const _lepton_photon_ & orig) : TObject(orig){}
_lepton_photon_::~_lepton_photon_() {Clear();}


_dilepton_photon_::_dilepton_photon_() {  //Int_t   charge;
  dileptonIndex=0;
  photonIndex=0;

  pt=0;
  eta=0;
  phi=0;
  rapidity=0;
  mll=0;
  m1g=0;
  m2g=0;
  mass=0;

  cosPhi=0;
}
_dilepton_photon_::_dilepton_photon_ (const _dilepton_photon_ & orig) : TObject(orig){}
_dilepton_photon_::~_dilepton_photon_() {Clear();}






/**************************************************************************
 *  
 * definition of the event class
 *
 **************************************************************************/
_event_::_event_() {

  hltNonIsoMuons    = new TClonesArray("_vec4_", 10);
  hltMuons          = new TClonesArray("_vec4_", 10);
  hltMuonLs         = new TClonesArray("_vec4_", 10);
  hltMuonLleg1s     = new TClonesArray("_vec4_", 10);
  hltMuonLleg2s     = new TClonesArray("_vec4_", 10);

  hltMuonHs         = new TClonesArray("_vec4_", 10);
  hltMuonHleg1s     = new TClonesArray("_vec4_", 10);
  hltMuonHleg2s     = new TClonesArray("_vec4_", 10);



  hltMuonElectrons  = new TClonesArray("_vec4_", 10);
  hltElectronMuons  = new TClonesArray("_vec4_", 10);

  hltNonIsoElectrons= new TClonesArray("_vec4_", 10);
  hltElectrons      = new TClonesArray("_vec4_", 10);
  hltElectronLs     = new TClonesArray("_vec4_", 10);
  hltElectronLleg1s = new TClonesArray("_vec4_", 10);
  hltElectronLleg2s = new TClonesArray("_vec4_", 10);


  vertices          = new TClonesArray("_vertex_", 25);
  superclusters     = new TClonesArray("_supercluster_", 50);
  photons           = new TClonesArray("_photon_", 50);
  electrons         = new TClonesArray("_electron_", 10);
  l1Objs            = new TClonesArray("_l1_obj_", 100);
  simTracks         = new TClonesArray("_track_", 500);
  tracks            = new TClonesArray("_track_", 500);
  jets              = new TClonesArray("_jet_", 50);
  genJets           = new TClonesArray("_gen_jet_", 100);
  akGenJets         = new TClonesArray("_gen_jet_", 100);
  caloJets          = new TClonesArray("_jet_", 50);
  jptJets           = new TClonesArray("_jet_", 50);
  pfJets            = new TClonesArray("_jet_", 50);
  muons             = new TClonesArray("_muon_", 10);

  Ws                = new TClonesArray("_W_", 1);
  dileptons         = new TClonesArray("_di_lepton_", 1);
  dijets            = new TClonesArray("_di_jet_", 1);
  trileptons        = new TClonesArray("_tri_lepton_", 1);
  quarleptons       = new TClonesArray("_quar_lepton_", 1);
  leptonphotons     = new TClonesArray("_lepton_photon_", 1);
  dileptonphotons   = new TClonesArray("_dilepton_photon_", 1);
  leptonTrkPairs    = new TClonesArray("_di_lepton_", 1);
}


_event_::~_event_() {

  Clear();
}


// hlt objects
// muons 
_vec4_ *_event_::addHLTNonIsoMuon() {

   TClonesArray &my_hltNonIsoMuons = *hltNonIsoMuons;

   _vec4_ *hltNonIsoMuon = new(my_hltNonIsoMuons[hltNonIsoMuonNum++]) _vec4_();
   return hltNonIsoMuon;
}


_vec4_ *_event_::addHLTMuon() {

   TClonesArray &my_hltMuons = *hltMuons;

   _vec4_ *hltMuon = new(my_hltMuons[hltMuonNum++]) _vec4_();
   return hltMuon;
}


_vec4_ *_event_::addHLTMuonL() {

   TClonesArray &my_hltMuonLs = *hltMuonLs;

   _vec4_ *hltMuonL = new(my_hltMuonLs[hltMuonLNum++]) _vec4_();
   return hltMuonL;
}


_vec4_ *_event_::addHLTMuonLleg1() {

   TClonesArray &my_hltMuonLleg1s = *hltMuonLleg1s;

   _vec4_ *hltMuonLleg1 = new(my_hltMuonLleg1s[hltMuonLleg1Num++]) _vec4_();
   return hltMuonLleg1;
}


_vec4_ *_event_::addHLTMuonLleg2() {

   TClonesArray &my_hltMuonLleg2s = *hltMuonLleg2s;

   _vec4_ *hltMuonLleg2 = new(my_hltMuonLleg2s[hltMuonLleg2Num++]) _vec4_();
   return hltMuonLleg2;
}




_vec4_ *_event_::addHLTMuonH() {

   TClonesArray &my_hltMuonHs = *hltMuonHs;

   _vec4_ *hltMuonH = new(my_hltMuonHs[hltMuonHNum++]) _vec4_();
   return hltMuonH;
}


_vec4_ *_event_::addHLTMuonHleg1() {

   TClonesArray &my_hltMuonHleg1s = *hltMuonHleg1s;

   _vec4_ *hltMuonHleg1 = new(my_hltMuonHleg1s[hltMuonHleg1Num++]) _vec4_();
   return hltMuonHleg1;
}


_vec4_ *_event_::addHLTMuonHleg2() {

   TClonesArray &my_hltMuonHleg2s = *hltMuonHleg2s;

   _vec4_ *hltMuonHleg2 = new(my_hltMuonHleg2s[hltMuonHleg2Num++]) _vec4_();
   return hltMuonHleg2;
}





// mu-e
_vec4_ *_event_::addHLTMuonElectron() {

   TClonesArray &my_hltMuonElectrons = *hltMuonElectrons;

   _vec4_ *hltMuonElectron = new(my_hltMuonElectrons[hltMuonElectronNum++]) _vec4_();
   return hltMuonElectron;
}

_vec4_ *_event_::addHLTElectronMuon() {

   TClonesArray &my_hltElectronMuons = *hltElectronMuons;

   _vec4_ *hltElectronMuon = new(my_hltElectronMuons[hltElectronMuonNum++]) _vec4_();
   return hltElectronMuon;
}


// electrons
_vec4_ *_event_::addHLTNonIsoElectron() {

   TClonesArray &my_hltNonIsoElectrons = *hltNonIsoElectrons;

   _vec4_ *hltNonIsoElectron = new(my_hltNonIsoElectrons[hltNonIsoElectronNum++]) _vec4_();
   return hltNonIsoElectron;
}

_vec4_ *_event_::addHLTElectron() {

   TClonesArray &my_hltElectrons = *hltElectrons;

   _vec4_ *hltElectron = new(my_hltElectrons[hltElectronNum++]) _vec4_();
   return hltElectron;
}

_vec4_ *_event_::addHLTElectronL() {

   TClonesArray &my_hltElectronLs = *hltElectronLs;

   _vec4_ *hltElectronL = new(my_hltElectronLs[hltElectronLNum++]) _vec4_();
   return hltElectronL;
}



_vec4_ *_event_::addHLTElectronLleg1() {

   TClonesArray &my_hltElectronLleg1s = *hltElectronLleg1s;

   _vec4_ *hltElectronLleg1 = new(my_hltElectronLleg1s[hltElectronLleg1Num++]) _vec4_();
   return hltElectronLleg1;
}

_vec4_ *_event_::addHLTElectronLleg2() {

   TClonesArray &my_hltElectronLleg2s = *hltElectronLleg2s;

   _vec4_ *hltElectronLleg2 = new(my_hltElectronLleg2s[hltElectronLleg2Num++]) _vec4_();
   return hltElectronLleg2;
}


// others
_vertex_ *_event_::addVertex() {

   TClonesArray &my_vertices = *vertices;

   _vertex_ *vertex = new(my_vertices[vertexNum++]) _vertex_();
   return vertex;
}


_l1_obj_ *_event_::addL1Obj() {

   TClonesArray &my_l1Objs = *l1Objs;

   _l1_obj_ *l1Obj = new(my_l1Objs[l1ObjNum++]) _l1_obj_();
   return l1Obj;
}
_supercluster_ *_event_::addSupercluster() {

   TClonesArray &my_superclusters = *superclusters;

   _supercluster_ *supercluster = new(my_superclusters[superclusterNum++]) _supercluster_();
   return supercluster;
}


_photon_ *_event_::addPhoton() {

   TClonesArray &my_photons = *photons;

   _photon_ *photon = new(my_photons[photonNum++]) _photon_();
   return photon;
}


_electron_ *_event_::addElectron() {

   TClonesArray &my_electrons = *electrons;

   _electron_ *electron = new(my_electrons[electronNum++]) _electron_();
   return electron;
}

_track_ *_event_::addTrack() {

   TClonesArray &my_trks = *tracks;

   _track_ *track = new(my_trks[trackNum++]) _track_();
   return track;
}

_track_ *_event_::addSimTrack() {

   TClonesArray &my_trks = *simTracks;

   _track_ *track = new(my_trks[simTrackNum++]) _track_();
   return track;
}

_jet_ *_event_::addJet() {

   TClonesArray &my_jets = *jets;

   _jet_ *jet = new(my_jets[jetNum++]) _jet_();
   return jet;
}

_gen_jet_ *_event_::addGenJet() {

   TClonesArray &my_jets = *genJets;

   _gen_jet_ *jet = new(my_jets[genJetNum++]) _gen_jet_();
   return jet;
}

_gen_jet_ *_event_::addAKGenJet() {

   TClonesArray &my_jets = *akGenJets;

   _gen_jet_ *jet = new(my_jets[akGenJetNum++]) _gen_jet_();
   return jet;
}




_jet_ *_event_::addCaloJet() {

   TClonesArray &my_jets = *caloJets;

   _jet_ *jet = new(my_jets[caloJetNum++]) _jet_();
   return jet;
}

_jet_ *_event_::addJPTJet() {

   TClonesArray &my_jets = *jptJets;

   _jet_ *jet = new(my_jets[jptJetNum++]) _jet_();
   return jet;
}


_jet_ *_event_::addPFJet() {

   TClonesArray &my_jets = *pfJets;

   _jet_ *jet = new(my_jets[pfJetNum++]) _jet_();
   return jet;
}

_muon_ *_event_::addMuon() {

   TClonesArray &my_muons = *muons;

   _muon_ *muon = new(my_muons[muonNum++]) _muon_();
   return muon;
}


// access of composited candidates
_W_ *_event_::addW() {

   TClonesArray &my_Ws = *Ws;

   _W_ *aW = new(my_Ws[WNum++]) _W_();
   return aW;
}

_di_lepton_ *_event_::addDilepton() {

   TClonesArray &my_dileptons = *dileptons;

   _di_lepton_ *dilepton = new(my_dileptons[dileptonNum++]) _di_lepton_();
   return dilepton;
}


_di_jet_ *_event_::addDijet() {

   TClonesArray &my_dijets = *dijets;

   _di_jet_ *dijet = new(my_dijets[dijetNum++]) _di_jet_();
   return dijet;
}




_tri_lepton_ *_event_::addTrilepton() {

   TClonesArray &my_trileptons = *trileptons;

   _tri_lepton_ *trilepton = new(my_trileptons[trileptonNum++]) _tri_lepton_();
   return trilepton;
}


_quar_lepton_ *_event_::addQuarlepton() {

   TClonesArray &my_quarleptons = *quarleptons;

   _quar_lepton_ *quarlepton = new(my_quarleptons[quarleptonNum++]) _quar_lepton_();
   return quarlepton;
}



_lepton_photon_ *_event_::addLeptonPhoton() {

   TClonesArray &my_leptonphotons = *leptonphotons;

   _lepton_photon_ *leptonphoton = new(my_leptonphotons[leptonPhotonNum++]) _lepton_photon_();
   return leptonphoton;
}


_dilepton_photon_ *_event_::addDileptonPhoton() {

   TClonesArray &my_dileptonphotons = *dileptonphotons;

   _dilepton_photon_ *dileptonphoton = new(my_dileptonphotons[dileptonPhotonNum++]) _dilepton_photon_();
   return dileptonphoton;
}


_di_lepton_ *_event_::addLeptonTrkPair() {

  TClonesArray &my_dileptons = *leptonTrkPairs;
  _di_lepton_ *dilepton = new(my_dileptons[leptonTrkPairNum++]) _di_lepton_();
   return dilepton;
}

void _event_::reset() {


  // 
  eventFilterBit.Initialize();
  genEventInfo.Initialize();
  mc.Initialize();
  genTTbar.Initialize();
  genDrellYan.Initialize();




  eventNum          = -1;
  runNum            = -1;
  lumiBlock         = -1;
  bunchCrossing     = -1;
  orbitNum          = -1;
  timeLow           = -1;
  timeHigh          = -1;

  eventWeight       = 1.0;
  numOfWeights      = 0;
  for (unsigned jj =0; jj < MAX_WEIGHTS; jj ++) weights[jj] = 0;


  BField            = -1;
  rho = 0;
  rhoIso = 0;

  rhoIso            = 0; sigmaIso     = 0;
  rhoCh             = 0; sigmaCh      = 0;
  rhoCh2p4          = 0; sigmaCh2p4   = 0;

  rhoCHS            = 0; rhoCalo      = 0; rhoTrack         = 0;
  sigmaCHS          = 0; sigmaCalo    = 0; sigmaTrack       = 0;


  mcVertexNumTruth  = 0;
  mcVertexNum       = 0;
  mcVertexNump1     = 0;
  mcVertexNumm1     = 0;

  l1ObjNum          = 0;
  hltObjNum         = 0;


  hltNonIsoMuonNum     = 0;
  hltMuonNum           = 0;
  hltMuonLNum          = 0;
  hltMuonLleg1Num      = 0;
  hltMuonLleg2Num      = 0;


  hltMuonHNum          = 0;
  hltMuonHleg1Num      = 0;
  hltMuonHleg2Num      = 0;




  hltMuonElectronNum   = 0;
  hltElectronMuonNum   = 0;


  hltNonIsoElectronNum = 0;
  hltElectronNum       = 0;
  hltElectronLNum      = 0;
  hltElectronLleg1Num  = 0;
  hltElectronLleg2Num  = 0;

  vertexNum         = 0;
  vtxPosX           = -99;
  vtxPosY           = -99;
  vtxPosZ           = -99;
  vtxPosXError      = 0;
  vtxPosYError      = 0;
  vtxPosZError      = 0;



  simTrackNum       = 0;
  superclusterNum   = 0;
  photonNum         = 0;
  electronNum       = 0;
  trackNum          = 0;
  jetNum            = 0;
  genJetNum         = 0;
  akGenJetNum       = 0;
  caloJetNum        = 0;
  jptJetNum         = 0;
  pfJetNum          = 0;

  muonNum           = 0;

  WNum              = 0;
  dileptonNum       = 0;
  dijetNum          = 0;
  trileptonNum      = 0;
  quarleptonNum     = 0;
  leptonPhotonNum   = 0;
  dileptonPhotonNum = 0;
  leptonTrkPairNum  = 0;
}

void _event_::Clear() {

  // 
  eventFilterBit.Initialize();
  genEventInfo.Initialize();
  mc.Initialize();
  genTTbar.Initialize();
  genDrellYan.Initialize();


 

  eventNum        = -1;
  runNum          = -1;
  lumiBlock       = -1;
  bunchCrossing   = -1;
  orbitNum        = -1;
  timeLow         = -1;
  timeHigh        = -1;

  eventWeight     = 1.0;
  numOfWeights      = 0;
  for (unsigned jj =0; jj < MAX_WEIGHTS; jj ++) weights[jj] = 0;

  BField          = -1;

  rho             = 0; sigma    = 0;
  rhoIso          = 0; sigmaIso = 0;
  rhoCh           = 0; sigmaCh  = 0;
  rhoCh2p4        = 0; sigmaCh2p4  = 0;

  rhoCHS            = 0; rhoCalo      = 0; rhoTrack         = 0;
  sigmaCHS          = 0; sigmaCalo    = 0; sigmaTrack       = 0;


  mcVertexNumTruth= 0;
  mcVertexNum     = 0;
  mcVertexNump1   = 0;
  mcVertexNumm1   = 0;

  hltObjNum       = 0;
  l1ObjNum        = 0;  l1Objs           ->Clear();


  hltNonIsoMuonNum     = 0;  hltNonIsoMuons    ->Clear();
  hltMuonNum           = 0;  hltMuons          ->Clear();
  hltMuonLNum          = 0;  hltMuonLs         ->Clear();
  hltMuonLleg1Num      = 0;  hltMuonLleg1s     ->Clear();
  hltMuonLleg2Num      = 0;  hltMuonLleg2s     ->Clear();


  hltMuonHNum          = 0;  hltMuonHs         ->Clear();
  hltMuonHleg1Num      = 0;  hltMuonHleg1s     ->Clear();
  hltMuonHleg2Num      = 0;  hltMuonHleg2s     ->Clear();


  hltMuonElectronNum   = 0;  hltMuonElectrons  ->Clear();
  hltElectronMuonNum   = 0;  hltElectronMuons  ->Clear();


  hltNonIsoElectronNum = 0;  hltNonIsoElectrons->Clear();
  hltElectronNum       = 0;  hltElectrons      ->Clear();
  hltElectronLNum      = 0;  hltElectronLs     ->Clear();
  hltElectronLleg1Num  = 0;  hltElectronLleg1s ->Clear();
  hltElectronLleg2Num  = 0;  hltElectronLleg2s ->Clear();




  vertexNum       = 0;  vertices         ->Clear();
  vtxPosX           = -99;
  vtxPosY           = -99;
  vtxPosZ           = -99;
  vtxPosXError      = 0;
  vtxPosYError      = 0;
  vtxPosZError      = 0;



  superclusterNum = 0;  superclusters    ->Clear();
  photonNum       = 0;  photons          ->Clear();
  electronNum     = 0;  electrons        ->Clear();
  trackNum        = 0;  tracks           ->Clear(); 
  jetNum          = 0;  jets             ->Clear(); 
  genJetNum       = 0;  genJets          ->Clear();
  akGenJetNum     = 0;  akGenJets        ->Clear();

  caloJetNum      = 0;  caloJets       ->Clear();    
  jptJetNum       = 0;  jptJets        ->Clear();   
  pfJetNum        = 0;  pfJets         ->Clear();    

  muonNum         = 0;  muons            ->Clear(); 
  simTrackNum     = 0;  simTracks        ->Clear();




  WNum              = 0; 
  dileptonNum       = 0; 
  dijetNum          = 0; 
  trileptonNum      = 0; 
  quarleptonNum     = 0; 
  leptonPhotonNum   = 0; 
  dileptonPhotonNum = 0; 
  leptonTrkPairNum  = 0;


 
  Ws              ->Clear();
  dileptons       ->Clear();
  dijets          ->Clear();
  trileptons      ->Clear();
  quarleptons     ->Clear();
  leptonphotons   ->Clear();
  dileptonphotons ->Clear();
  leptonTrkPairs  ->Clear(); 
}

bool isEB(Int_t flag)                    {return (bool)(flag&0x1);}
bool isEE(Int_t flag)                    {return (bool)(flag&0x2);}
bool isGap(Int_t flag)                   {return (bool)(flag&0x4);}
bool isEBEEGap(Int_t flag)               {return (bool)(flag&0x8);}
bool isEBGap(Int_t flag)                 {return (bool)(flag&0x10);}
bool isEBEtaGap(Int_t flag)              {return (bool)(flag&0x20);}
bool isEBPhiGap(Int_t flag)              {return (bool)(flag&0x40);}
bool isEEGap(Int_t flag)                 {return (bool)(flag&0x80);}
bool isEEDeeGap(Int_t flag)              {return (bool)(flag&0x100);}
bool isEERingGap(Int_t flag)             {return (bool)(flag&0x200);}


// accessors
_vec4_ *addHLTNonIsoMuon(_event_ *aEvent) {return aEvent->addHLTNonIsoMuon();}
_vec4_ *addHLTMuon(_event_ *aEvent)       {return aEvent->addHLTMuon();}
_vec4_ *addHLTMuonL(_event_ *aEvent)      {return aEvent->addHLTMuonL();}
_vec4_ *addHLTMuonLleg1(_event_ *aEvent)  {return aEvent->addHLTMuonLleg1();}
_vec4_ *addHLTMuonLleg2(_event_ *aEvent)  {return aEvent->addHLTMuonLleg2();}


_vec4_ *addHLTMuonH(_event_ *aEvent)      {return aEvent->addHLTMuonH();}
_vec4_ *addHLTMuonHleg1(_event_ *aEvent)  {return aEvent->addHLTMuonHleg1();}
_vec4_ *addHLTMuonHleg2(_event_ *aEvent)  {return aEvent->addHLTMuonHleg2();}


_vec4_ *addHLTMuonElectron(_event_ *aEvent){return aEvent->addHLTMuonElectron();}
_vec4_ *addHLTElectronMuon(_event_ *aEvent){return aEvent->addHLTElectronMuon();}



_vec4_ *addHLTNonIsoElectron(_event_ *aEvent){return aEvent->addHLTNonIsoElectron();}
_vec4_ *addHLTElectron(_event_ *aEvent)      {return aEvent->addHLTElectron();}
_vec4_ *addHLTElectronL(_event_ *aEvent)     {return aEvent->addHLTElectronL();}
_vec4_ *addHLTElectronLleg1(_event_ *aEvent) {return aEvent->addHLTElectronLleg1();}
_vec4_ *addHLTElectronLleg2(_event_ *aEvent) {return aEvent->addHLTElectronLleg2();}
