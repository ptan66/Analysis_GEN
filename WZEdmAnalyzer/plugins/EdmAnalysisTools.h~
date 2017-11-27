#ifndef _EdmAnalysisTools_h_
#define _EdmAnalysisTools_h_

#include "DataFormats/JetReco/interface/CaloJetCollection.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "SimDataFormats/Track/interface/SimTrack.h"
#include "SimDataFormats/Track/interface/SimTrackContainer.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrack.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrackFwd.h"

#include "DataFormats/CaloTowers/interface/CaloTowerCollection.h"

#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"


#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"


#include "TLorentzVector.h"
#include "TVector3.h"

#include <DataFormats/VertexReco/interface/VertexFwd.h>

#include "RecoVertex/VertexPrimitives/interface/TransientVertex.h"


// MC jet flavor truth matching
#include "SimDataFormats/JetMatching/interface/JetFlavour.h"
#include "SimDataFormats/JetMatching/interface/JetFlavourMatching.h"
#include "SimDataFormats/JetMatching/interface/MatchedPartons.h"
#include "SimDataFormats/JetMatching/interface/JetMatchedPartons.h"


#include "math.h"
#include "kinematics.h"

using namespace reco;
using namespace edm;
using namespace std;

float btaggingAssociation(Jet jet, const reco::JetTagCollection *btags, float matching_deltaR=0.3);

float mcflavorAssociation(Jet jet, edm::Handle<reco::JetFlavourMatchingCollection> tagList, float matching_deltaR=0.3);


void calPtRel(reco::CaloJetCollection::const_iterator jet, const reco::MuonCollection *recoMuons, _jet_ *myJet, float coneSize=0.3, float scale = 1.0);


float trackIsolation(const reco::Track & theTrack,  const reco::TrackCollection &tracks, 
		     double threshold, double larger_th, 
		     int *nTracks, 
		     float *arger_iso, int *larger_nTrks);


float trackIsolation(const reco::GsfTrack & theTrack,  const reco::TrackCollection &tracks, 
		     double threshold, double larger_th, 
		     int *nTracks, 
		     float *larger_iso, int *larger_nTrks);

float jetIsolation(const reco::Jet & jet, const reco::CaloJetCollection & jets, double threshold);

const SimTrack *closestSimTrack(const reco::Track &atrack, const edm::SimTrackContainer *simTrkColl);


// with calotowers and global muons only
void calMet(const CaloTowerCollection *caloTowers, const reco::MuonCollection  *muons, double &px, double &py);

double calIsolation( const CaloTowerCollection   *caloTowers, reco::MuonCollection::const_iterator muon, double threshold = 0.3);
double calIsolation( const CaloTowerCollection   *caloTowers, reco::GsfElectronCollection::const_iterator electron, double threshold = 0.3);



// check if a muon candidate is associated with any primary vertex
const reco::Vertex  *vertexAssociation(const TrackBaseRef &track, Handle<reco::VertexCollection> recVtxs);


void vertexActivites(reco::VertexCollection::const_iterator v, const reco::Muon *muon, float threshold, int & num, float  & sumpt, float  & sumpt2, float &thrust, float &sphericity, float &planarity, float &aplanarity);

int trackVertexAssociation(const TrackBaseRef &track, Handle<reco::VertexCollection> recVtxs);


int whichVertex(const TrackBaseRef &track, Handle<reco::VertexCollection> recVtxs, float &distance);



#endif
