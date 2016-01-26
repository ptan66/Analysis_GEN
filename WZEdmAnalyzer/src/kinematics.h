#ifndef _kinematics_h_
#define _kinematics_h_

#include "TObject.h"
#include "TLorentzVector.h"
#include "TClonesArray.h"
#include "TVector3.h"

#define L1EMOBJ          0x1
#define L1JETOBJ         0x2
#define L1MUONOBJ        0x4
#define L1OTHEROBJ       0x8
#define MAXL1TRIGGERBITS 256

#define MAX_TRIG_WORD    4
#define MAX_WEIGHTS      1500

#define EDM_MAX_LENGTH   0x6

#define CALOJET 0
#define JPTJET 1
#define PFJET 2

#define PDG_ID_ELECTRON  11
#define PDG_ID_MUON      13
#define ANY_TRACK        -999

#define DEFAULT_VAL      -99999




class _event_filterBit_ : public  TObject {


 public:


  Bool_t trackingFailureFilter;


  Bool_t EcalDeadCellTriggerPrimitiveFilter, ecalLaserCorrFilter, eeBadScFilter, 
    hcalLaserEventFilter, CSCTightHaloFilter;

 

  Bool_t genericFilter0;
  Bool_t genericFilter1;
  Bool_t genericFilter2;



 _event_filterBit_() {}
  _event_filterBit_(const _event_filterBit_ & orig);
  virtual ~_event_filterBit_() {Clear();}
  void Initialize();


  ClassDef(_event_filterBit_, 2)
};





class _gen_eventInfo_ : public  TObject {


 public:



  // PDF information
  Double_t x1, x2;
  Int_t    flav1, flav2;
  Double_t xfx1, xfx2;
  Double_t scalePDF; // Q valued used in PDF evolution.


  // eventInfo
  Double_t weight;
  Int_t    signalProcessID;
  Int_t    qScale;
  Double_t alphaQCD;
  Double_t alphaQED;
  Bool_t   hasPDF;

  _gen_eventInfo_() {}
  _gen_eventInfo_(const _gen_eventInfo_ & orig);
  virtual ~_gen_eventInfo_() {Clear();}
  void Initialize();


  ClassDef(_gen_eventInfo_, 2)
};



class _mc_process_ : public TObject {



 public:

  // event information
  Int_t   mpi, processId, eventNumber;
  Int_t   vtxBarcode;
  Float_t eventScale, alphaQCD, alphaQED;




  // PDF information
  Float_t x1, x2;
  Int_t   flav1, flav2;
  Float_t xfx1, xfx2;
  Float_t scalePDF; // Q valued used in PDF evolution.


  //  vector boson information
  Int_t   decayType, bosId;
  Float_t bosPt, bosPz, bosMass, bosEta, bosPhi, bosRap;

  Float_t dileptonPt, dileptonPz, dileptonMass, dileptonEta, dileptonPhi, dileptonRap;
  Float_t cosTheta; // simple two-body decay angle
  Float_t cosPhi;
  Float_t nphotons;


  // vector boson daughters
  Float_t muonEnergy,    muonPt, muonPz, muonEta, muonPhi, muonId; // particle
  Float_t muonBarEnergy, muonBarPt, muonBarPz, muonBarEta, muonBarPhi, muonBarId; // anti particle

  Float_t nrmuonEnergy,    nrmuonPt, nrmuonPz, nrmuonEta, nrmuonPhi, nrmuonId; // particle
  Float_t nrmuonBarEnergy, nrmuonBarPt, nrmuonBarPz, nrmuonBarEta, nrmuonBarPhi, nrmuonBarId; // anti particle

  Float_t photonEnergy, photonPhi, photonEta, photonAngle;


  // Z/gamma process
  Float_t cosThetaCS, sin2ThetaCS, tanPhiCS;
  Float_t corCosThetaCS, corSin2ThetaCS, corTanPhiCS;
  Int_t   sameSign;
  Float_t qqbar, qbarq, mistag;


  // W production
  Float_t metX, metY, delta, fprob, bprob;

  _mc_process_() {}
  _mc_process_(const _mc_process_ & orig);
  virtual ~_mc_process_() {Clear();}
  void Initialize();


  ClassDef(_mc_process_, 2)
};



class _gen_ttbar_ : public TObject {



 public:


  Double_t ttbarPt, ttbarM, ttbarEta, ttbarPhi;



  Double_t mom1Pt, mom1Eta, mom1M, mom1Phi, mom1ID;
  Double_t mom2Pt, mom2Eta, mom2M, mom2Phi, mom2ID;


  Double_t tPt, tM, tEta, tPhi, tID;

  Double_t twPt, twM, twEta, twPhi, twID;
  Double_t twlPt, twlM, twlEta, twlPhi, twlID;
  Double_t twvPt, twvM, twvEta, twvPhi, twvID;

  Double_t tbPt, tbM, tbEta, tbPhi, tbID;
  Double_t tjPt, tjM, tjEta, tjPhi, tjID;


  Double_t tbarPt, tbarM, tbarEta, tbarPhi, tbarID;

  Double_t tbarwPt, tbarwM, tbarwEta, tbarwPhi, tbarwID;
  Double_t tbarwlPt, tbarwlM, tbarwlEta, tbarwlPhi, tbarwlID;
  Double_t tbarwvPt, tbarwvM, tbarwvEta, tbarwvPhi, tbarwvID;

  Double_t tbarbPt, tbarbM, tbarbEta, tbarbPhi, tbarbID;
  Double_t tbarjPt, tbarjM, tbarjEta, tbarjPhi, tbarjID;



  _gen_ttbar_() {}
  _gen_ttbar_(const _gen_ttbar_ & orig);
  virtual ~_gen_ttbar_() {Clear();}
  void Initialize();


  ClassDef(_gen_ttbar_, 2)
};




// "p*" contains particle information with PID>0
// W+: pdaug is neutrino or u, c quarks. 
// W-: pdaug is negative leptons, u, s quarks. 
// Z : pdaug is negative leptons, neutrinos, or u, d, c, s, b quarks. 
class _gen_DrellYan_ : public TObject {



 public:


  Double_t mom1Pt, mom1Eta, mom1M, mom1Phi, mom1ID;
  Double_t mom2Pt, mom2Eta, mom2M, mom2Phi, mom2ID;


  Double_t bosPt, bosEta, bosM, bosPhi, bosID;
  Double_t pdaugPt, pdaugEta, pdaugM, pdaugPhi, pdaugID;
  Double_t pdaugPtFSR, pdaugEtaFSR, pdaugMFSR, pdaugPhiFSR;
  Double_t pdaugPtDress, pdaugEtaDress, pdaugMDress, pdaugPhiDress;

  Double_t mdaugPt, mdaugEta, mdaugM, mdaugPhi, mdaugID;
  Double_t mdaugPtFSR, mdaugEtaFSR, mdaugMFSR, mdaugPhiFSR;
  Double_t mdaugPtDress, mdaugEtaDress, mdaugMDress, mdaugPhiDress;


  Int_t    numberOfJets;
  Int_t    jpid[EDM_MAX_LENGTH];
  Double_t jv4[EDM_MAX_LENGTH][4];

  //j1Pt, j1Eta, j1M, j1Phi, j1ID;
  // Double_t j2Pt, j2Eta, j2M, j2Phi, j2ID;
  // Double_t j3Pt, j3Eta, j3M, j3Phi, j3ID;
  // Double_t j4Pt, j4Eta, j4M, j4Phi, j4ID;
  // Double_t j5Pt, j5Eta, j5M, j5Phi, j5ID;

  Int_t    numOfParticles; 
  // Double_t x1, x2;
  // Int_t    flav1, flav2;
  // Double_t xfx1, xfx2;
  // Double_t scalePDF; // Q valued used in PDF evolution.


  Double_t mev4[ EDM_MAX_LENGTH*2 ][5];
  Int_t    mepid[EDM_MAX_LENGTH*2];

  _gen_DrellYan_() {}
  _gen_DrellYan_(const _gen_DrellYan_ & orig);
  virtual ~_gen_DrellYan_() {Clear();}
  void Initialize();


  ClassDef(_gen_DrellYan_, 2)
};




// For WZ signal MC
class _genwz_ : public TObject {


 public:

  // Z Boson Information
  Int_t   Z_decayType, Z_bosId;
  Float_t Z_bosPt, Z_bosPz, Z_bosMass, Z_bosEta, Z_bosPhi, Z_bosRap;
  Float_t Z_dauAEnergy, Z_dauAPt, Z_dauAPz, Z_dauAEta, Z_dauAPhi, Z_dauAId; // particle
  Float_t Z_dauBEnergy, Z_dauBPt, Z_dauBPz, Z_dauBEta, Z_dauBPhi, Z_dauBId; // anti particle
  Float_t Z_dileptonPt, Z_dileptonPz, Z_dileptonMass, Z_dileptonEta, Z_dileptonPhi, Z_dileptonRap;
  Float_t Z_cosTheta; // simple two-body decay angle
  Float_t Z_cosPhi;
  Float_t Z_nphotons,Z_phoEnergy, Z_phoPhi, Z_phoEta,  Z_phoAngle;

  // W Boson Information
  Int_t   W_decayType, W_bosId;
  Float_t W_bosPt, W_bosPz, W_bosMass, W_bosEta, W_bosPhi, W_bosRap;
  Float_t W_dauAEnergy, W_dauAPt, W_dauAPz, W_dauAEta, W_dauAPhi, W_dauAId; // particle
  Float_t W_dauBEnergy, W_dauBPt, W_dauBPz, W_dauBEta, W_dauBPhi, W_dauBId; // anti particle
  Float_t W_dileptonPt, W_dileptonPz, W_dileptonMass, W_dileptonEta, W_dileptonPhi, W_dileptonRap;
  Float_t W_cosTheta; // simple two-body decay angle
  Float_t W_cosPhi;
  Float_t W_nphotons,W_phoEnergy, W_phoPhi, W_phoEta,  W_phoAngle;
  
  // WZ System
  Int_t   gdWZ;
  Float_t WZ_Pt, WZ_Pz, WZ_Mass, WZ_Eta, WZ_Phi, WZ_Rap, WZ_cosAngZ, WZ_cosAngW;

  _genwz_() {}
  _genwz_(const _genwz_ & orig);
  virtual ~_genwz_() {Clear();}
  void Initialize();


  ClassDef(_genwz_, 2)
};


class _vec4_ : public TObject {

 public:

  Float_t id;
  Float_t pt;
  Float_t eta;
  Float_t phi;


  _vec4_();
  _vec4_(const _vec4_ & orig);
  virtual ~_vec4_();


  ClassDef(_vec4_, 2)
};


class _met_ : public _vec4_ {

 public: 


  Float_t sumEt, e_longitudinal;
  Float_t HadronicEtFraction, EMEtFraction;
  Float_t MuonEtFraction, InvisibleEtFraction;




  _met_();
  _met_(const _met_ & orig);

  void init(void); 
  virtual ~_met_();


  ClassDef(_met_, 2)

};

class _track_ : public TObject{

 public:


  Int_t   vertexIndex, associatedVertex;
  Float_t closestVertexDist;


  Float_t chi2, normalizedChi2, charge, ndof;

  Float_t pt, eta, phi;
  Float_t ptError, etaError, phiError;


  Float_t qoverp, qoverpError;
  Float_t lambda, lambdaError;

  Float_t dxy0, dxy0Error;
  Float_t dz0,  dz0Error;
  Float_t dsz0, dsz0Error;

  Float_t dxy; 
  Float_t dz; 
  Float_t dsz;


 // inner track with respecting to closest primary vertex. 
  Float_t   dxyVtx, dzVtx, dszVtx;



  Int_t   recHitsSize, numberOfValidHits, outerOk;
  Int_t   nStereoHits;
  Float_t outerRadius, innerRadius;

  Int_t   numberOfValidPixelHits,  numberOfValidStripHits, numberOfValidPixelBarrelHits;
  Int_t   numberOfValidTrackerLayers, trackerLayersWithMeasurement;
  Int_t   pixelLayersWithMeasurement, pixelBarrelLayersWithMeasurement, pixelEndcapLayersWithMeasurement;

  Int_t   hasValidHitInFirstPixelBarrel;
  Int_t   trackerExpectedHitsInner_numberOfHits;

  Int_t   mcType;
  Float_t mcPt, mcEta, mcPhi;

  _track_();
  _track_(const _track_ & orig);
  virtual ~_track_();


  ClassDef(_track_, 2)
};



class _trg_bits_ : public TObject {

 public:

  ULong_t l1TrgBits [MAX_TRIG_WORD];
  ULong_t l1tTrgBits [MAX_TRIG_WORD];
  ULong_t hltAccTrgBits[MAX_TRIG_WORD];
  ULong_t hltRunTrgBits[MAX_TRIG_WORD];
  ULong_t hltErrTrgBits[MAX_TRIG_WORD];

  _trg_bits_();
  _trg_bits_(const _trg_bits_ & orig);
  virtual ~_trg_bits_();


  void setL1TrgBits(ULong_t *bits);
  void setL1TTrgBits(ULong_t *bits);
  void setHLTAccTrgBits(ULong_t *bits);
  void setHLTRunTrgBits(ULong_t *bits);
  void setHLTErrTrgBits(ULong_t *bits);


  ClassDef(_trg_bits_, 2)
};


class _hlt_info_ : public TObject {

 public:


  Bool_t HLT_NonIsoMuon;
  Bool_t HLT_Muon;
  Bool_t HLT_MuonL;
  Bool_t HLT_MuonH;

  Bool_t HLT_MuonElectron;
  Bool_t HLT_ElectronMuon;

  Bool_t HLT_NonIsoElectron;
  Bool_t HLT_Electron;
  Bool_t HLT_ElectronL;



  _hlt_info_();
  _hlt_info_(const _hlt_info_ & orig);
  virtual ~_hlt_info_();

  ClassDef(_hlt_info_, 2)
};


class _mets_ : public TObject {

 public:


  _met_ caloMET, tcMET, pfMET, muonJESCorSC5MET, genMET, rawMET, pfType1CorrectedMet, pfType1p2CorrectedMet;

  // _met_ corrPfMetType1, correctionTermsPfMetType0PFCandidate, correctionTermsPfMetShiftXY;
   _met_  pfMetT0pc, pfMetT0pcT1, pfMetT0pcTxy, pfMetT0pcT1Txy, pfMetT1, pfMetT1Txy;


  _mets_();
  _mets_(const _mets_ & orig);
  virtual ~_mets_();

  ClassDef(_mets_, 2)
};

class _dileadingjets_ : public TObject {

 public:

  Int_t   charge;
  Int_t   daughtA, daughtB;
  Int_t   daughtAType, daughtBType;

  // the composite particle
  //  Float_t px, py, pz, p0; 
  Float_t pt, eta, phi;
  Float_t ptx, pty;
  Float_t rapidity;
  Float_t mass;

  _dileadingjets_();
  _dileadingjets_(const _dileadingjets_ & orig);
  virtual ~_dileadingjets_();
  void Initialize();

  ClassDef(_dileadingjets_, 2)
};




class _run_info_ : public TObject {

 public:

  Float_t autoXSec;
  Float_t extXsec;
  Float_t filterEff;

  _run_info_();
  _run_info_(const _run_info_ & orig);
  virtual ~_run_info_();

  ClassDef(_run_info_, 2)
};

class _vertex_ : public TObject {

 public:

  Int_t   isValid, isFake;
  Float_t x, y, z;
  Float_t xError, yError, zError;
  Float_t chi2, ndof, tracksSize, normalizedChi2;



  Int_t validTracksSize, validTracksSize200MeV, validTracksSize500MeV, validTracksSize1GeV;

  Float_t sumPtMin,  sumPtMin200MeV,  sumPtMin500MeV,  sumPtMin1GeV;
  Float_t sumPt2Min, sumPt2Min200MeV, sumPt2Min500MeV, sumPt2Min1GeV;


  Float_t thrust, sphericity, planarity, aplanarity;

  Int_t muonIndex;
  Float_t thrust_x, thrust_y, thrust_z;

  _vertex_();
  _vertex_(const _vertex_ & orig);
  virtual ~_vertex_();

  ClassDef(_vertex_, 2)

};



class _l1_obj_ : public TObject {

 public:

  Int_t   triggerInfo; // 1/0xxxxyyyy: xxxx trigger bits belonging; yyyy data type

  Float_t et;
  Float_t charge;
  Float_t eta;
  Float_t phi;


  _l1_obj_();
  _l1_obj_(const _l1_obj_ & orig) ;
  virtual ~_l1_obj_();


  ClassDef(_l1_obj_, 2)
};


class _supercluster_ : public TObject {
 public:

  // basic information
  Float_t  et, eta, phi;
  Int_t    hasPixelSeed, hasConversionTracks;
  Int_t   fiducialFlags;

  // shower shape
  Float_t sigmaEtaEta, sigmaIetaIeta, e1x5, e2x5, e3x3, e5x5;
  Float_t maxEnergyXtal;
  Float_t hadronicDepth1OverEm, hadronicDepth2OverEm, hadronicOverEm;
  Float_t r1x5, r2x5, r9;

  // superclustr information
  Float_t scRawEnergy, scPreshowerEnergy, scPhiWidth, scEtaWidth;
  Int_t   scClustersSize; 

  Float_t cluster2ndMoments_sMaj, cluster2ndMoments_sMin;
  Float_t cluster2ndMoments_alpha; 
  Float_t energy, centroidX, centroidY, centroidZ;
  Int_t   size;


  _supercluster_();
  _supercluster_(const _supercluster_ & orig);
  virtual ~_supercluster_();


  ClassDef(_supercluster_, 2)
};



class _photon_ : public TObject {

 public:

  // basic information
  Float_t  et, eta, phi;
  Int_t    hasPixelSeed, hasConversionTracks;


  // photon type
  // bool isEB() const{return  fiducialFlagBlock_.isEB;}
  // bool isEE() const{return fiducialFlagBlock_.isEE;}
  // bool isEBGap() const { return (isEBEtaGap() || isEBPhiGap()); }
  // bool isEBEtaGap() const{return fiducialFlagBlock_.isEBEtaGap;}
  // bool isEBPhiGap() const{return fiducialFlagBlock_.isEBPhiGap;}
  // bool isEEGap() const { return (isEERingGap() || isEEDeeGap()); }
  // bool isEERingGap() const{return fiducialFlagBlock_.isEERingGap;}
  // bool isEEDeeGap() const{return fiducialFlagBlock_.isEEDeeGap;}
  // bool isEBEEGap() const{return fiducialFlagBlock_.isEBEEGap;}
  Int_t   fiducialFlags;

  // shower shape
  Float_t sigmaEtaEta, sigmaIetaIeta, e1x5, e2x5, e3x3, e5x5;
  Float_t maxEnergyXtal;
  Float_t hadronicDepth1OverEm, hadronicDepth2OverEm, hadronicOverEm;
  Float_t r1x5, r2x5, r9;


  // Isolation variables
  Float_t ecalRecHitSumEtConeDR04, hcalTowerSumEtConeDR04;
  Float_t hcalDepth1TowerSumEtConeDR04, hcalDepth2TowerSumEtConeDR04;
  Float_t trkSumPtSolidConeDR04, trkSumPtHollowConeDR04; 
  Float_t nTrkSolidConeDR04, nTrkHollowConeDR04;

  Float_t ecalRecHitSumEtConeDR03, hcalTowerSumEtConeDR03; 
  Float_t hcalDepth1TowerSumEtConeDR03, hcalDepth2TowerSumEtConeDR03;
  Float_t trkSumPtSolidConeDR03, trkSumPtHollowConeDR03;
  Float_t nTrkSolidConeDR03, nTrkHollowConeDR03;


  // superclustr information
  Float_t scRawEnergy, scPreshowerEnergy, scPhiWidth, scEtaWidth;
  Int_t   scClustersSize; 

  Float_t cluster2ndMoments_sMaj, cluster2ndMoments_sMin;
  Float_t cluster2ndMoments_alpha; 
  Float_t energy, centroidX, centroidY, centroidZ;
  Int_t   size;


  _photon_();
  _photon_(const _photon_ & orig);
  virtual ~_photon_();


  ClassDef(_photon_, 2)
};


class _electron_ : public _track_ {


 public:

  // basic information
  Int_t   classification;
  Int_t   scPixCharge,isGsfCtfScPixChargeConsistent, isGsfScPixChargeConsistent,  isGsfCtfChargeConsistent;
  Int_t   ecalDrivenSeed, trackerDrivenSeed;


  Bool_t  validKF;

  // Pure tracking variables
  Float_t fMVAVar_fbrem,  fMVAVar_kfchi2, fMVAVar_gsfchi2;
  Int_t fMVAVar_kfhits, fMVAVar_kfhitsall ;

  
  // Geometrical matchings
  Float_t   fMVAVar_deta, fMVAVar_dphi, fMVAVar_detacalo, fMVAVar_dphicalo ;


  // Pure ECAL -> shower shapes
  Float_t   fMVAVar_see, fMVAVar_spp, fMVAVar_sigmaIEtaIPhi ;


 Float_t    fMVAVar_etawidth, fMVAVar_phiwidth , fMVAVar_e1x5e5x5, fMVAVar_R9, fMVAVar_nbrems ;
 
 // Energy matching
 Float_t    fMVAVar_HoE ,    fMVAVar_EoP ,    fMVAVar_IoEmIoP , fMVAVar_eleEoPout,    fMVAVar_PreShowerOverRaw,    fMVAVar_EoPout; 


 // Spectators
 Float_t   fMVAVar_eta  , fMVAVar_pt  ;

 // for triggering electrons get the impact parameteres
 //d0

 Float_t fMVAVar_d0 ,    fMVAVar_ip3d,     fMVAVar_ip3dSig;
 /************ end of MVA variables ***************************/









  // for spike rejection, conversion rejection, etc. 
  Float_t swissCross, dist, dcot, radiusOfConversion;
  Bool_t  vtxFitConversion; 
  Float_t mHits, numberOfLostHits;

  Int_t   isElFromConversion;
  Int_t   numberOfExpectedInnerHits, deltaMissingHits;

  // superclustr information
  Float_t scEt, scEta, scPhi;
  Float_t energy, centroidX, centroidY, centroidZ;
  Int_t   size;
  Float_t scRawEnergy, scPreshowerEnergy, scPhiWidth, scEtaWidth;
  Int_t   scClustersSize; 

  // additional track information
  Int_t   chargeMode;
  Float_t qoverpMode, lambdaMode, ptMode, phiMode, etaMode;
  Float_t qoverpModeError, lambdaModeError, ptModeError, phiModeError, etaModeError;

  // track-cluster matching 
  Float_t eSuperClusterOverP ;        
  Float_t eSeedClusterOverP ;         
  Float_t eSeedClusterOverPout ;      
  Float_t eEleClusterOverPout ;       
  Float_t deltaEtaSuperClusterTrackAtVtx ; 
  Float_t deltaEtaSeedClusterTrackAtCalo ; 
  Float_t deltaEtaEleClusterTrackAtCalo ;  
  Float_t deltaPhiEleClusterTrackAtCalo ;  
  Float_t deltaPhiSuperClusterTrackAtVtx ; 
  Float_t deltaPhiSeedClusterTrackAtCalo ; 

  Int_t   fiducialFlags;


  // isolation variables
  Float_t dr03TkSumPt, dr03EcalRecHitSumEt, dr03HcalDepth1TowerSumEt, dr03HcalDepth2TowerSumEt, dr03HcalTowerSumEt;
  Float_t dr04TkSumPt, dr04EcalRecHitSumEt, dr04HcalDepth1TowerSumEt, dr04HcalDepth2TowerSumEt, dr04HcalTowerSumEt;
  Float_t pfRelIsoR03, effArea, pfIsoCh, pfIsoNeutral, pfIsoPhoton, pfIsoSumPUPt;
  Float_t pfRelIsoR03EA;

  Float_t ecalPFClusterIso,   hcalPFClusterIso;

  // shower shape variables
  Float_t sigmaEtaEta, sigmaIetaIeta, full5x5_sigmaIetaIeta, e1x5, e2x5Max, e5x5, hcalDepth1OverEcal, hcalDepth2OverEcal, hcalOverEcal,  hadronicOverEm;


  // preselection info
  Int_t   ecalDriven, passingCutBasedPreselection, passingMvaPreselection;
  Float_t mva;


  // brem
  Float_t fbrem;
  Int_t   numberOfBrems;


  // 
  Int_t   isMomentumCorrected; 
  Float_t ecalEnergy, correctedEcalEnergy, trackMomentumAtVtx, ecalEnergyError, trackMomentumError, electronMomentumError;
  Float_t ooemoop;


  Int_t idBitMap, mvaIdBitMap;


  Float_t regressionEnergy, regressionEnergyError;

  Float_t calibratedSCEt, calibratedSCEta, calibratedSCPhi, calibratedEnergy;
  Float_t calibratedPt, calibratedEta, calibratedPhi;
  Float_t mvaTrigV0, mvaNonTrigV0;
  Float_t mvaTrigV0Cat, mvaNonTrigV0Cat;

  _electron_();
  _electron_(const _electron_ & orig);
  virtual ~_electron_();

  ClassDef(_electron_, 2)
};


class _beam_spot_ : public TObject{

 public:


  Float_t x0, y0, z0;
  Float_t x0Error, y0Error, z0Error;
  Float_t sigmaZ, sigmaZError;
  Float_t BeamWidthXError, BeamWidthYError;


  _beam_spot_();
  _beam_spot_(const _beam_spot_ & orig);
  virtual ~_beam_spot_();


  ClassDef(_beam_spot_, 2)
};




class _muon_ : public _track_ {

 public:

  Int_t muonType;

  // global track parameters
   // TeV Muon Refit
   Int_t     refitCharge;
   Float_t   refitPt, refitEta, refitPhi;
   Float_t   refitPtError, refitEtaError, refitPhiError;
   Float_t   refitDxy, refitDz;
   Int_t     isHighPtMuon;

  Float_t   globalDxy0, globalDz0, globalDsz0;
  Float_t   globalDxy0Error, globalDz0Error, globalDsz0Error;
  Float_t   globalDxy, globalDz, globalDsz;
  Float_t   globalDxyVtx, globalDzVtx, globalDszVtx;

  Int_t     globalRecHitsSize, globalNumberOfValidHits, globalCharge;
  Float_t   globalPt, globalEta, globalPhi;
  Float_t   globalPtError, globalEtaError, globalPhiError;
  Float_t   globalNormalizedChi2;
  Int_t     globalNumberOfValidMuonHits;

 
  // outer track information
  Float_t   outerPt, outerEta, outerPhi;
  Float_t   outerPtError, outerEtaError, outerPhiError;
  Int_t     outerRecHitsSize, outerNumberOfValidHits, outerCharge, outerInnerOk;

  // additional muon selector information: implemented Nov. 25, 2013
  Float_t improvedMuonBestTrackPt,  improvedMuonBestTrackPtError ;
  Float_t improvedMuonBestTrackEta;
  Float_t improvedMuonBestTrackPhi;
  Float_t improvedMuonBestTrackCharge;
  //  Int_t isHighPtMuon;


  Int_t   isSoftMuon, isTightMuon, isGlobalMuon;
  Int_t   isPFMuon;
  Float_t bestMuonBestTrackDxy;
  Float_t bestMuonBestTrackDz;
  Float_t bestMuonBestTrackPt,  bestMuonBestTrackPtError ;
  Float_t bestMuonBestTrackEta;
  Float_t bestMuonBestTrackPhi;
  Float_t bestMuonBestTrackCharge;

  Float_t pfIsolationR04;
  Float_t pfIsolationR04beta;

  Float_t pfIsolationWeighted;
  Float_t pfIsolationPUPPI;



  //  Global variables
  Int_t     numberOfChambers, stationGapMaskPull, numberOfMatches;
  Int_t     stationMask;
  Int_t     numberOfMatchedStations; 
  // timing information
  Int_t     timenDof, isTimeValid;
  Float_t   timeAtIPInOut, timeAtIPInOutErr;
  Float_t   timeAtIPOutIn, timeAtIPOutInErr;

  // compatibility
  Int_t     isCaloCompatibilityValid;
  Float_t   caloCompatibility;

  // isolation
  Int_t     isIsolationValid;
  Float_t   isolationR03hadEt, isolationR03emEt, isolationR03sumPt, isolationR03nTracks, isolationR03nJets, isolationR03hoEt;
  Float_t   isolationR05hadEt, isolationR05emEt, isolationR05sumPt, isolationR05nTracks, isolationR05nJets, isolationR05hoEt;



  Float_t   isolationR03emVetoEt, isolationR03hadVetoEt, isolationR03hoVetoEt; 
  Float_t   isolationR05emVetoEt, isolationR05hadVetoEt, isolationR05hoVetoEt; 


  // muon energy
  Int_t     isEnergyValid;
  Float_t   calEnergy, calEnergyem, calEnergyhad, calEnergyho;
  Float_t   calEnergyecal_time, calEnergyhcal_time;
  Float_t   calEnergyecal_timeError, calEnergyhcal_timeError;

  _muon_();
  _muon_(const _muon_ & orig);
  virtual ~_muon_(); 

  ClassDef(_muon_, 2)
};

class _gen_jet_ : public TObject {

 public:

  Float_t pt, eta, phi, energy, mass;
  Int_t   mc_flavor, mc_partonFlavor, nConstituent ;

  //Float_t 

  _gen_jet_();
  _gen_jet_(const _gen_jet_ & orig);
  virtual ~_gen_jet_();


  ClassDef(_gen_jet_, 2)
};


class _jet_ : public TObject {

 public:

  Float_t pt, eta, phi, mass, energy;
  Float_t physicsEta, physicsPt, physicsPhi;

  Int_t   nConstituent;
  Float_t L2L3pt, L2L3scale, L4scale, L5scale, L6scale, L7scale, L8scale;
  Float_t scaleUnc;
  Float_t pileup, area, L;


  Float_t fHPD, fRBX;

  // calo jets
  Float_t n60, n90;
  Float_t emEnergyInEE, emEnergyInHF, emEnergyInEB;
  Float_t hadEnergyInHB, hadEnergyInHO, hadEnergyInHF, hadEnergyInHE;
  Float_t emEnergyFraction, energyFractionHadronic;
  Float_t maxEInEmTowers, maxEInHadTowers;


  // common between JPT and PF jet
  // for JPT jet the electronMultiplicity is (elecMultiplicity)
  Int_t   muonMultiplicity,    chargedMultiplicity,      electronMultiplicity;
  Float_t chargedHadronEnergy, chargedHadronEnergyFraction;
  Float_t neutralHadronEnergy, neutralHadronEnergyFraction;
  Float_t chargedEmEnergy,     chargedEmEnergyFraction;
  Float_t neutralEmEnergy,     neutralEmEnergyFraction;


  // JPT jets
  Float_t zspCor;


  // PF jets
  Float_t photonEnergy, photonEnergyFraction;
  Float_t electronEnergy, electronEnergyFraction;
  Float_t muonEnergy, muonEnergyFraction;
  Float_t HFHadronEnergy, HFHadronEnergyFraction;
  Float_t HFEMEnergy, HFEMEnergyFraction;

  Int_t   chargedHadronMultiplicity, neutralHadronMultiplicity;
  Int_t   photonMultiplicity, HFHadronMultiplicity, HFEMMultiplicity;
  Float_t chargedMuEnergy, chargedMuEnergyFraction;
  Int_t   neutralMultiplicity; 

  Float_t quarkGluonLikelihood, quarkGluonMLP; 
  Float_t puIDFlag, puIDMva;
  Bool_t  puIDLoose, puIDMedium, puIDTight;


  // MC information
  Int_t    mc_flavor, mc_partonFlavor;
  Float_t  mc_pt, mc_eta, mc_phi;

  // btagging variables
  Float_t tag[EDM_MAX_LENGTH];
  Float_t flavor[EDM_MAX_LENGTH];


  Int_t   jetVertexIndex;
  Float_t jetVertexFrac;
  Int_t   jetVertexnlIndex;
  Float_t jetVertexnlFrac;

  Int_t   jetVertexIndexNum;
  Float_t jetVertexFracNum;
  Int_t   jetVertexnlIndexNum;
  Float_t jetVertexnlFracNum;



  Int_t   jetVertexIndexSum;
  Float_t jetVertexFracSum;
  Int_t   jetVertexnlIndexSum;
  Float_t jetVertexnlFracSum;


  Float_t sum,    sumS,    sumN;
  Float_t totsum, totsumS, totsumN;
  Float_t dissum5,  dissum5S,  dissum5N;
  Float_t dissum10, dissum10S, dissum10N;

  _jet_();
  _jet_(const _jet_ & orig);
  virtual ~_jet_();

  ClassDef(_jet_, 2)
};



class _di_jet_ : public TObject {

 public: 

  Int_t     jetType, charge, daughtA, daughtB; 
  Float_t   pt, eta, phi, rapidity, mass;


  // results from vertex constrainted fit
  Bool_t  isValid;
  Float_t totalChiSquared, chiSquaredProbability;
  Float_t degreesOfFreedom;
  Float_t vx, vy, vz;
  Float_t vxError, vyError, vzError;

  _di_jet_();
  _di_jet_(const _di_jet_ & orig);
  virtual ~_di_jet_();


  ClassDef(_di_jet_, 2)
};


/**************************************************************************
 *
 * composition of candidates
 *
 **************************************************************************/
class _W_ : public TObject{

 public:

  Int_t leptonIndex, leptonType;

  // with assumption of muons from W decays.
  // calculate the Rapidity distribution.
  Float_t recoWy1;
  Float_t recoWy2;
  Float_t delta;

  _W_();
  _W_(const _W_ & orig);
  virtual ~_W_();

  ClassDef(_W_, 2)
};



class _di_lepton_ : public TObject{

 public:


  Float_t x1, x2;
  Float_t xfx1, xfx2;
  Float_t mistag;
  Float_t qqbar, qbarq; // 


  Int_t   charge;
  Int_t   daughtA, daughtB;
  Int_t   daughtAType, daughtBType;

  // the composite particle
  //  Float_t px, py, pz, p0; 
  Float_t pt, eta, phi;
  Float_t rapidity;
  Float_t mass;



  // results from vertex constrainted fit
  Bool_t  isValid;
  Float_t totalChiSquared, chiSquaredProbability;
  Float_t degreesOfFreedom;
  Float_t fittedMass;
  Float_t vx, vy, vz;
  Float_t vxError, vyError, vzError;

  Float_t e1, e2, cosPhiFit; // after refit
  
  // angles in rest frame of di-lepton pair following Collins-Soper convention
  Float_t cosPhi; // angle between the two muons. 
  Float_t cosTheta;
  Float_t cosThetaCS;
  Float_t sin2Theta;
  Float_t tanPhi;



  _di_lepton_();
  _di_lepton_(const _di_lepton_ & orig);
  virtual ~_di_lepton_();

  ClassDef(_di_lepton_, 2)
};


class _tri_lepton_ : public TObject{

 public:


  Int_t dileptonIndex;
  Int_t leptonIndex;
  Int_t leptonType;

  Int_t charge;
  Float_t m12, eta12, pt12, phi12, mt3, rapidity12;
  Float_t m23, eta23, pt23, phi23, mt1, rapidity23;

  Float_t mass, eta, rapidity, pt, phi, theta12, theta23, mt;


  _tri_lepton_();
  _tri_lepton_(const _tri_lepton_ & orig);
  virtual ~_tri_lepton_();

  ClassDef(_tri_lepton_, 2)
};


class _quar_lepton_ : public TObject{

 public:

  Int_t charge;
  Int_t dileptonIndex;
  Int_t leptonType, leptonIndex1, leptonIndex2;


  Float_t m12, pt12, eta12, rapidity12, phi12;
  Float_t m34, pt34, eta34, rapidity34, phi34;

  Float_t thetaStar;

  Float_t mass, pt, eta, phi, rapidity;

  _quar_lepton_();
  _quar_lepton_(const _quar_lepton_ & orig);
  virtual ~_quar_lepton_();

  ClassDef(_quar_lepton_, 2)
};


class _lepton_photon_ : public TObject{

 public:

  Int_t   charge;
  Int_t   leptonIndex, photonIndex;
  Int_t   leptonType;

  Float_t pt, eta, phi;
  Float_t rapidity;
  Float_t mass;

  Float_t cosPhi;


  _lepton_photon_();
  _lepton_photon_(const _lepton_photon_ & orig);
  virtual ~_lepton_photon_();

  ClassDef(_lepton_photon_, 2)
};



class _dilepton_photon_ : public TObject{

 public:

  Int_t   charge;
  Int_t   dileptonIndex, photonIndex;

  Float_t pt, eta, phi;
  Float_t rapidity;

  // lepton pairs are ordered as:
  // mumu
  // mue
  // ee
  // the order sequence within a group is charge first then pt. 
  Float_t mll, m1g, m2g, mass;

  Float_t cosPhi;


  _dilepton_photon_();
  _dilepton_photon_(const _dilepton_photon_ & orig);
  virtual ~_dilepton_photon_();

  ClassDef(_dilepton_photon_, 2)
};



/**************************************************************************
 *
 *  event definition
 *
 **************************************************************************/
class _event_ : public TObject{

 public:


 //  Float_t x1, x2;
  Long_t              eventNum,        runNum,         lumiBlock;
  Int_t               bunchCrossing,   orbitNum;
  Long_t              timeLow,         timeHigh;

  Float_t             eventWeight,     BField;

  Int_t               numOfWeights;
  Double_t            weights[MAX_WEIGHTS];

  Float_t             rho,   rhoIso,   rhoCh,   rhoCh2p4;
  Float_t             sigma, sigmaIso, sigmaCh, sigmaCh2p4;


  Float_t             rhoCHS,   rhoCalo,   rhoTrack;
  Float_t             sigmaCHS, sigmaCalo, sigmaTrack;

  Int_t               simTrackNum;

  Int_t               vertexNum;
  Float_t             vtxPosX, vtxPosY, vtxPosZ;
  Float_t             vtxPosXError, vtxPosYError, vtxPosZError;

  Int_t               mcVertexNumTruth;
  Int_t               mcVertexNum;
  Int_t               mcVertexNump1;
  Int_t               mcVertexNumm1;

  Int_t               photonNum;
  Int_t               superclusterNum;
  Int_t               electronNum;
  Int_t               trackNum;
  Int_t               jetNum,          genJetNum,         akGenJetNum;
  Int_t               caloJetNum;
  Int_t               jptJetNum;
  Int_t               pfJetNum;
  Int_t               muonNum;

  Int_t               WNum;
  Int_t               quarleptonNum,   trileptonNum,   dileptonNum;
  Int_t               dijetNum;
  Int_t               leptonTrkPairNum,leptonPhotonNum,dileptonPhotonNum;

  // trigger information
  Int_t               l1ObjNum;
  Int_t               hltObjNum;


  _trg_bits_          trgBits;



  // high level trigger information. 
  Int_t               hltNonIsoElectronNum;  
  TClonesArray       *hltNonIsoElectrons; 
  Int_t               hltElectronNum;   
  TClonesArray       *hltElectrons; 
  Int_t               hltElectronLNum;  
  TClonesArray       *hltElectronLs; 

  Int_t               hltElectronLleg1Num;  
  TClonesArray       *hltElectronLleg1s; 

  Int_t               hltElectronLleg2Num;  
  TClonesArray       *hltElectronLleg2s; 


  Int_t               hltMuonElectronNum;      
  TClonesArray       *hltMuonElectrons; 
  Int_t               hltElectronMuonNum;      
  TClonesArray       *hltElectronMuons; 


  Int_t               hltNonIsoMuonNum;      
  TClonesArray       *hltNonIsoMuons; 
  Int_t               hltMuonNum;      
  TClonesArray       *hltMuons; 

  Int_t               hltMuonLNum;      
  TClonesArray       *hltMuonLs; 
  Int_t               hltMuonLleg1Num;      
  TClonesArray       *hltMuonLleg1s; 
  Int_t               hltMuonLleg2Num;      
  TClonesArray       *hltMuonLleg2s; 


  
  Int_t               hltMuonHNum;      
  TClonesArray       *hltMuonHs; 
  Int_t               hltMuonHleg1Num;      
  TClonesArray       *hltMuonHleg1s; 
  Int_t               hltMuonHleg2Num;      
  TClonesArray       *hltMuonHleg2s; 





  TClonesArray       *vertices;
  TClonesArray       *superclusters;
  TClonesArray       *photons;
  TClonesArray       *electrons;
  TClonesArray       *l1Objs;
  TClonesArray       *tracks;
  TClonesArray       *jets,            *genJets,         *akGenJets;
  TClonesArray       *caloJets;
  TClonesArray       *jptJets;
  TClonesArray       *pfJets;
  TClonesArray       *simTracks;
  TClonesArray       *muons;


  TClonesArray       *Ws;
  TClonesArray       *dileptons;
  TClonesArray       *dijets;
  TClonesArray       *trileptons;
  TClonesArray       *quarleptons;
  TClonesArray       *leptonphotons;
  TClonesArray       *dileptonphotons;
  TClonesArray       *leptonTrkPairs;


  _beam_spot_         beamSpot;
  _mc_process_        mc;
  _event_filterBit_   eventFilterBit;
  _gen_eventInfo_     genEventInfo;
  _gen_ttbar_         genTTbar;
  _gen_DrellYan_      genDrellYan;
  _genwz_             genwz;
  _run_info_          runInfo;
  _hlt_info_          hltInfo;
  _mets_              mets;
  _dileadingjets_     dileadingjets;



  // member functions
  _event_();
  virtual    ~_event_();
  

  void       setEventNum(Long_t num)       {eventNum      = num;}
  void       setRunNum(Long_t num)         {runNum        = num;} 
  void       setLumiBlock(Long_t num)      {lumiBlock     = num;} 

  void       setBunchCrossing(Int_t num)   {bunchCrossing = num;}
  void       setOrbitNum(Int_t  num)       {orbitNum      = num;}
  void       setTimeLow(Long_t  num)       {timeLow       = num;}
  void       setTimeHigh(Long_t num)       {timeHigh      = num;}

  void       setEventWeight(Float_t f)     {eventWeight   = f; }
  void       setBField(Float_t f)          {BField        = f; }


  TClonesArray       *getHLTNonIsoElectrons() {return hltNonIsoElectrons;}
  TClonesArray       *getHLTElectrons()       {return hltElectrons;}
  TClonesArray       *getHLTElectronLs()      {return hltElectronLs;}
  TClonesArray       *getHLTElectronLleg1s()  {return hltElectronLleg1s;}
  TClonesArray       *getHLTElectronLleg2s()  {return hltElectronLleg2s;}

  TClonesArray       *getHLTMuonElectrons()   {return hltMuonElectrons;}
  TClonesArray       *getHLTElectronMuons()   {return hltElectronMuons;}


  TClonesArray       *getHLTNonIsoMuons()     {return hltNonIsoMuons;}
  TClonesArray       *getHLTMuons()           {return hltMuons;}
  TClonesArray       *getHLTMuonLs()          {return hltMuonLs;}
  TClonesArray       *getHLTMuonLleg1s()      {return hltMuonLleg1s;}
  TClonesArray       *getHLTMuonLleg2s()      {return hltMuonLleg2s;}


  TClonesArray       *getHLTMuonHs()          {return hltMuonHs;}
  TClonesArray       *getHLTMuonHleg1s()      {return hltMuonHleg1s;}
  TClonesArray       *getHLTMuonHleg2s()      {return hltMuonHleg2s;}



  TClonesArray       *getVertices()        {return vertices;}
  TClonesArray       *getSuperclusters()   {return superclusters;}
  TClonesArray       *getPhotons()         {return photons;}
  TClonesArray       *getElectrons()       {return electrons;}
  TClonesArray       *getL1Objs()          {return l1Objs;}
  TClonesArray       *getTracks()          {return tracks;}
  TClonesArray       *getJets()            {return jets;}
  TClonesArray       *getGenJets()         {return genJets;}
  TClonesArray       *getAKGenJets()       {return akGenJets;}

  TClonesArray       *getCaloJets()        {return caloJets;}
  TClonesArray       *getJPTJets()         {return jptJets;}
  TClonesArray       *getPFJets()          {return pfJets;}


  TClonesArray       *getMuons()           {return muons;}
  TClonesArray       *getSimTracks()       {return simTracks;}

  TClonesArray       *getWs()              {return Ws;}
  TClonesArray       *getDileptons()       {return dileptons;}
  TClonesArray       *getDijets()          {return dijets;}
  TClonesArray       *getTrileptons()      {return trileptons;}
  TClonesArray       *getQuarleptons()     {return quarleptons;}
  TClonesArray       *getLeptonPhotons()   {return leptonphotons;}
  TClonesArray       *getDileptonPhotons() {return dileptonphotons;}
  TClonesArray       *getLeptonTrkPairs()  {return leptonTrkPairs;}

  _trg_bits_         *getTrgBits()         {return &trgBits;}
  _beam_spot_        *getBeamSpot()        {return &beamSpot;}
  

  _event_filterBit_  *getEventFilterBit()  {return &eventFilterBit;}
  _gen_eventInfo_    *getGenEventInfo()    {return &genEventInfo;}
  _gen_ttbar_        *getGenTTbar()        {return &genTTbar;}
  _gen_DrellYan_     *getGenDrellYan()     {return &genDrellYan;}
  _mc_process_       *getMCInfo()          {return &mc;}
  _genwz_            *getGenWZ()           {return &genwz;}
  _run_info_         *getRunInfo()         {return &runInfo;}
  _hlt_info_         *getHLTInfo()         {return &hltInfo;}
  _mets_             *getMETs()            {return &mets;}
  _dileadingjets_    *getDiLeadingJets()   {return &dileadingjets;}

  _vec4_             *addHLTNonIsoMuon();
  _vec4_             *addHLTMuon();
  _vec4_             *addHLTMuonL();
  _vec4_             *addHLTMuonLleg1();
  _vec4_             *addHLTMuonLleg2();

  _vec4_             *addHLTMuonH();
  _vec4_             *addHLTMuonHleg1();
  _vec4_             *addHLTMuonHleg2();



  _vec4_             *addHLTMuonElectron();
  _vec4_             *addHLTElectronMuon();


  _vec4_             *addHLTNonIsoElectron();
  _vec4_             *addHLTElectron();
  _vec4_             *addHLTElectronL();
  _vec4_             *addHLTElectronLleg1();
  _vec4_             *addHLTElectronLleg2();



  _vertex_           *addVertex();
  _supercluster_     *addSupercluster();
  _photon_           *addPhoton();
  _electron_         *addElectron();
  _l1_obj_           *addL1Obj();
  _track_            *addSimTrack();
  _track_            *addTrack();

  _gen_jet_          *addGenJet();
  _gen_jet_          *addAKGenJet();
  _jet_              *addJet();

  _jet_              *addCaloJet();
  _jet_              *addJPTJet();
  _jet_              *addPFJet();

  _muon_             *addMuon();

  _W_                *addW();
  _di_lepton_        *addDilepton();
  _di_jet_           *addDijet();
  _tri_lepton_       *addTrilepton();


  _quar_lepton_      *addQuarlepton();
  _lepton_photon_    *addLeptonPhoton();
  _dilepton_photon_  *addDileptonPhoton();
  _di_lepton_        *addLeptonTrkPair();
  

  void                reset();
  void                Clear();

  ClassDef(_event_, 1)
};

bool    isEB(Int_t flag);
bool    isEE(Int_t flag);
bool    isGap(Int_t flag);
bool    isEBEEGap(Int_t flag);
bool    isEBGap(Int_t flag);
bool    isEBEtaGap(Int_t flag);
bool    isEBPhiGap(Int_t flag);
bool    isEEGap(Int_t flag);
bool    isEEDeeGap(Int_t flag);
bool    isEERingGap(Int_t flag);

_vec4_ *addHLTNonIsoMuon(_event_ *aEvent);
_vec4_ *addHLTMuon(_event_ *aEvent);
_vec4_ *addHLTMuonL(_event_ *aEvent);
_vec4_ *addHLTMuonLleg1(_event_ *aEvent);
_vec4_ *addHLTMuonLleg2(_event_ *aEvent);

_vec4_ *addHLTMuonH(_event_ *aEvent);
_vec4_ *addHLTMuonHleg1(_event_ *aEvent);
_vec4_ *addHLTMuonHleg2(_event_ *aEvent);


_vec4_ *addHLTMuonElectron(_event_ *aEvent);
_vec4_ *addHLTElectronMuon(_event_ *aEvent);

_vec4_ *addHLTNonIsoElectron(_event_ *aEvent);
_vec4_ *addHLTElectron(_event_ *aEvent);
_vec4_ *addHLTElectronL(_event_ *aEvent);
_vec4_ *addHLTElectronLleg1(_event_ *aEvent);
_vec4_ *addHLTElectronLleg2(_event_ *aEvent);



#endif
