#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/Common/interface/RefToBase.h" 

#include "DataFormats/Math/interface/Vector3D.h"
#include "DataFormats/CaloTowers/interface/CaloTowerCollection.h"

#include "DataFormats/CaloTowers/interface/CaloTower.h"
#include "DataFormats/BTauReco/interface/JetTag.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "DPGAnalysis/SiStripTools/interface/EventShape.h"



#include <DataFormats/VertexReco/interface/Vertex.h>
#include <DataFormats/VertexReco/interface/VertexFwd.h>
#include "RecoVertex/VertexPrimitives/interface/TransientVertex.h"

// Math
#include "Math/GenVector/VectorUtil.h"
#include "Math/GenVector/PxPyPzE4D.h"
#include "TVector3.h"

#include "EdmAnalysisTools.h"


#define TRACK_CHI2 5

using namespace std;
using namespace edm;
using namespace reco;


// jet tagging
float btaggingAssociation(Jet jet, const reco::JetTagCollection *btags, float matching_deltaR) {

  // float taginfo = -9999;

  for (unsigned int i = 0; i != (*btags).size(); ++i) {

    float  delta = ROOT::Math::VectorUtil::DeltaR(  (*btags)[i].first->momentum(), jet.momentum() );

    if (delta < matching_deltaR) return (*btags)[i].second;
  }

  return -9999;
}

// jet MC flavor
float mcflavorAssociation(Jet jet, edm::Handle<reco::JetFlavourMatchingCollection> tagList, float matching_deltaR) {


  for ( JetFlavourMatchingCollection::const_iterator j  = tagList->begin();
	j != tagList->end();
	j ++ ) {


    float  delta = ROOT::Math::VectorUtil::DeltaR(  (*j).first->momentum(), jet.momentum() );
    
    if (delta < matching_deltaR) return (*j).second.getFlavour()
;
 }

  return -9999;
}



// still use the global muons only at this moment
void calPtRel(reco::CaloJetCollection::const_iterator jet, const reco::MuonCollection *recoMuons, _jet_ *myJet, float coneSize, float scale) {

  double delta = 0, muonpt = 0;

  Int_t muonIndex = -1;


  for (reco::MuonCollection::const_iterator muon = (*recoMuons).begin(); muon != (*recoMuons).end(); muon ++) {

    muonIndex ++;
    if (!muon->isGlobalMuon()) {continue;}

    delta = ROOT::Math::VectorUtil::DeltaR( (*(muon->track())).momentum(), jet->momentum() );
    if (delta < coneSize) {

      //      myJet->muonNum ++;
      if ((*(muon->track())).pt() < muonpt) continue;

      muonpt = (*(muon->track())).pt();

      //      myJet->muonIndex = muonIndex;
      // myJet->muonType  = muon->type();
      //myJet->muonPt    = muonpt;
      //myJet->deltaR    = delta;
      //myJet->muonChi2  = (*(muon->track())).normalizedChi2();


      // calculate the ptrel
      TVector3 tmp_muon( (*(muon->track())).momentum().X(),
                         (*(muon->track())).momentum().Y(),
			 (*(muon->track())).momentum().Z()) ;
      TVector3 tt( scale*jet->p4().Vect().X(),
		   scale*jet->p4().Vect().Y(),
		   scale*jet->p4().Vect().Z());


      tt+= tmp_muon;
      //  myJet->ptRel =    tmp_muon.Perp(tt);
    }
  }
}


double calIsolation( const CaloTowerCollection   *caloTowers, reco::MuonCollection::const_iterator muon, double threshold) {

  double isolation = 0;
  if (!caloTowers) return isolation;
  for (CaloTowerCollection::const_iterator atower = (*caloTowers).begin(); atower != (*caloTowers).end(); atower ++) {
  
    double delta  = ROOT::Math::VectorUtil::DeltaR(muon->momentum(), atower->momentum() );

    if (delta < threshold) {

      isolation += (atower->emEt() +  atower->hadEt());
    }
  }

  //  isolation -= (muon->calEnergy().em + muon->calEnergy().had) * sin( muon->theta() );
  return isolation;
}


double calIsolation( const CaloTowerCollection   *caloTowers, reco::GsfElectronCollection::const_iterator electron, double threshold) {

  double isolation = 0;
  if (!caloTowers) return isolation;
  for (CaloTowerCollection::const_iterator atower = (*caloTowers).begin(); atower != (*caloTowers).end(); atower ++) {
  
    double delta  = ROOT::Math::VectorUtil::DeltaR(electron->gsfTrack()->momentum(), atower->momentum() );

    if (delta < threshold) {

      isolation += (atower->emEt() +  atower->hadEt());
    }
  }

  return isolation;
}



void calMet( const CaloTowerCollection   *caloTowers,   const reco::MuonCollection *muons, double &px, double &py) {


  if (!caloTowers || !muons) return;
  px = 0;
  py = 0;

  for (CaloTowerCollection::const_iterator atower = (*caloTowers).begin(); atower != (*caloTowers).end(); atower ++) {
 
    px += atower->momentum().x();
    py += atower->momentum().y();
  }


  for (reco::MuonCollection::const_iterator amuon = (*muons).begin(); amuon != (*muons).end(); amuon ++) {

    //    emenergy = amuon->getCalEnergy().em + amuon->getCalEnergy().had + amuon->getCalEnergy().ho;
    if (!amuon->isGlobalMuon()) continue;
    if ((*(amuon->track())).normalizedChi2() > TRACK_CHI2 ) continue;
    
    px += amuon->px();
    py += amuon->py();
    
  }

  px = -px;
  py = -py;
}




// track isolation in trackers
// only tracks with chi2 <5 & nhits >=7 are used in the calculation
float trackIsolation(const reco::Track & theTrack,  const reco::TrackCollection &tracks, 
		     double threshold, double larger_th, 
		     int *nTracks, 
		     float *larger_iso, int *larger_nTrks){

  double isolation = 0;
  (*nTracks) = 0;
  (*larger_iso) =0;
  (*larger_nTrks) = 0;


  for (reco::TrackCollection::const_iterator track = tracks.begin(); track != tracks.end(); track ++) {


    if (track->chi2() >=TRACK_CHI2 ) continue;

    double delta  = ROOT::Math::VectorUtil::DeltaR(theTrack.momentum(), track->momentum() );

    if (delta < larger_th && delta >= 1e-4) {

      (*larger_iso)   += track->pt();
      (*larger_nTrks) ++;

      if (delta < threshold) {
	isolation += track->pt();
	(*nTracks) ++;
      }
    }
  }

  return isolation;
}


// track isolation in tracker with Gsf tracks
// only tracks with chi2 < TRACK_CHI2are used in the calculation
float trackIsolation(const reco::GsfTrack & theTrack,  const reco::TrackCollection &tracks, 
		     double threshold, double larger_th, 
		     int *nTracks, 
		     float *larger_iso, int *larger_nTrks){

  double isolation = 0;
  (*nTracks) = 0;
  (*larger_iso) =0;
  (*larger_nTrks) = 0;


  for (reco::TrackCollection::const_iterator track = tracks.begin(); track != tracks.end(); track ++) {


    if (track->chi2() >=TRACK_CHI2) continue;

    double delta  = ROOT::Math::VectorUtil::DeltaR(theTrack.momentum(), track->momentum() );
    
    if (delta < larger_th && delta >= 1e-3) {
      
      (*larger_iso)   += track->pt();
      (*larger_nTrks) ++;
      
      if (delta < threshold) {
	isolation += track->pt();
	(*nTracks) ++;
      }
    }
  }

  return isolation;
}


float jetIsolation(const reco::Jet & jet, const reco::CaloJetCollection & jets, double threshold) {

  double isolation = 10;
  for (CaloJetCollection::const_iterator aJet = jets.begin(); aJet != jets.end(); aJet ++) {


    if (aJet->pt() < threshold) continue;

    double delta  = ROOT::Math::VectorUtil::DeltaR(jet.p4().Vect(), aJet->p4().Vect() );

    if (delta < 0.001) continue; // skip the identical jet. 
    if (delta < isolation) isolation = delta;
  }

  return isolation;
}

// use with caution: ...
// requires the sim track has minimum 5 GeV pt value
const SimTrack *closestSimTrack(const reco::Track &atrack, const edm::SimTrackContainer *simTrkColl) {


  double predelta = +10;
  const SimTrack *matchedOne = 0;
  if (!simTrkColl) return matchedOne;

  for (SimTrackContainer::const_iterator gentrk = (*simTrkColl).begin(); gentrk != (*simTrkColl).end(); gentrk++) {

    //    double delta  = ROOT::Math::VectorUtil::DeltaR( TVector3((*gentrk).momentum().x(),(*gentrk).momentum().y(),(*gentrk).momentum().z())
    double delta  = ROOT::Math::VectorUtil::DeltaR((*gentrk).momentum().Vect()
						   ,atrack.momentum() );
    if (delta < predelta &&(*gentrk).momentum().Pt()>5 ) {
      predelta = delta;
      matchedOne =&(*gentrk);
    }
  }  

  return matchedOne;
}



const reco::Vertex  *vertexAssociation(const TrackBaseRef &track, Handle<reco::VertexCollection> recVtxs) {



  for (reco::VertexCollection::const_iterator v=recVtxs->begin(); 
       v!=recVtxs->end(); 
       ++v){


    //    if ( v->refittedTracks().empty() ) continue;

    std::vector<TrackBaseRef >::const_iterator it = find(v->tracks_begin(), v->tracks_end(), track);
    if (it!=v->tracks_end()) return &(*v);
  }

  return 0;
}


void vertexActivites(reco::VertexCollection::const_iterator v, const reco::Muon *muon, float threshold, int & num, float  & sumpt,  float  & sumpt2, float &thrust, float &sphericity, float &planarity, float &aplanarity) {


  reco::TrackCollection associatedTracks;

  thrust =0;
  sphericity = 0;
  planarity  = 0;
  aplanarity = 0;
  num =0; sumpt = 0; sumpt2 = 0;


  //  if (!muon) return;

  TVector3 muon_v3, track_v3;
  muon_v3.SetPtEtaPhi(6500, 0, 0);
  if (muon)   muon_v3.SetPtEtaPhi( muon->innerTrack()->pt(),muon->innerTrack()->eta(),muon->innerTrack()->phi()); 

  for (std::vector<TrackBaseRef >::const_iterator  it = v->tracks_begin(); it != v->tracks_end(); ++ it) { 
     

    if ( (*it)->numberOfValidHits() >=6 && (*it)->normalizedChi2()< 10 && (*it)->pt()> threshold ) {

      num ++;
      sumpt += (*it)->pt();
      sumpt2 += pow((*it)->pt(), 2);
    

      // build up track collections
      track_v3.SetPtEtaPhi( (*it)->pt(), (*it)->eta(), (*it)->phi());
      if ( fabs( track_v3.Pt()-muon_v3.Pt())<0.01 && track_v3.DeltaR( muon_v3) < 0.01) {

	//	continue;
      } else {

	associatedTracks.push_back( *(*it) );

      }
   
    }
    

  }


  // note. don't calculate shape vairables, issues in 525
    return;
  //event shape variables. 
  EventShape shape( associatedTracks );

  std::cout << "reach here " << std::endl;

  thrust=shape.thrust().t();
  sphericity = shape.sphericity();
  planarity=shape.planarity();
  aplanarity=shape.aplanarity();

  return;
}


int trackVertexAssociation(const TrackBaseRef &track, Handle<reco::VertexCollection> recVtxs) {


  int vertexIndex = 0;


  TVector3 track_v3, vtxtrack_v3;
  track_v3.SetPtEtaPhi( track->pt(), track->eta(), track->phi() );



  for (reco::VertexCollection::const_iterator v=recVtxs->begin(); 
       v!=recVtxs->end(); 
       ++v){


    //    if ( v->refittedTracks().empty() ) continue;
    for (std::vector<TrackBaseRef >::const_iterator  it = v->tracks_begin(); it != v->tracks_end(); ++ it) { 

      vtxtrack_v3.SetPtEtaPhi( (*it)->pt(), (*it)->eta(), (*it)->phi() );

      if ( fabs( track_v3.Pt()-vtxtrack_v3.Pt())<0.01 && track_v3.DeltaR( vtxtrack_v3) < 0.01) {

	//	std::cout << "track is included in vertex " << vertexIndex << std::endl;
	return vertexIndex;
      }
    }


    vertexIndex ++;

  }

  return -1;
}


// !!!!!!!!!!! WARNING: filter is hard-coded here !!!!!!!!!!!!!
int  whichVertex(const TrackBaseRef &track, Handle<reco::VertexCollection> recVtxs, float & distance) {


  int index = -1, associated = -1;
  distance = 99999;
  for (reco::VertexCollection::const_iterator v=recVtxs->begin(); 
       v!=recVtxs->end(); 
       ++v){


    index ++;

    if (  fabs( v->position().z() ) > 15 || 
	  v->position().rho() >2 ||
	  v->isFake() ||
	  v->ndof() <=4 ) continue;
    //    if ( v->refittedTracks().empty() ) continue;

    //    if (distance > track->dz(v->position()) ) {

    //      distance = track->dz(v->position());
    // associated = index;

    //    }
    if (fabs( v->position().z() - track->vz() ) < distance) {

      distance = fabs( v->position().z() - track->vz() );
      associated = index;
    }
    //    if (fabs( v->position().z() - track->vz() ) < distance) {
    //      distance = fabs( v->position().z() - track->vz() );
    // associated = index;
    //}
    //    std::vector<TrackBaseRef >::const_iterator it = find(v->tracks_begin(), v->tracks_end(), track);
    //  if (it!=v->tracks_end()) return index;
  }

  return associated;
}
