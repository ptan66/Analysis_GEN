
/****************************************************************************
 *
 *  May 08, 2017: modify for Drell-Yan generator info from Pythia 6 to 
 *                Pythia 8
 *
 *
 *****************************************************************************/
#include <memory>
#include <string>
#include <iostream>
#include "math.h"

// user include files
#include "DataFormats/Math/interface/Point3D.h"

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/Run.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

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


#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

// 
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
#include "EdmAnalysisTools.h"
#include "lhapdfcc.h"
#include "weightIndex.h"

using namespace std;

using namespace edm;
using namespace reco;


#include "WZEdmAnalyzer.h"


void WZEdmAnalyzer::fillGenEventInfo(edm::Handle<GenEventInfoProduct> &genEvtInfo, _gen_eventInfo_ *myGenEvtInfo) {

  if ( genEvtInfo->hasPDF() ) {
    myGenEvtInfo -> hasPDF        = genEvtInfo->hasPDF();
    myGenEvtInfo -> x1            = genEvtInfo->pdf()->x.first;
    myGenEvtInfo -> x2            = genEvtInfo->pdf()->x.second;
    myGenEvtInfo -> flav1         = genEvtInfo->pdf()->id.first;
    myGenEvtInfo -> flav2         = genEvtInfo->pdf()->id.second;
    myGenEvtInfo -> xfx1          = genEvtInfo->pdf()->xPDF.first; 
    myGenEvtInfo -> xfx2          = genEvtInfo->pdf()->xPDF.second;
    myGenEvtInfo -> scalePDF      = genEvtInfo->pdf()->scalePDF; // Q valued used in PDF evolution.
  }

  // eventInfo
  myGenEvtInfo -> weight          = genEvtInfo->weight();
  myGenEvtInfo -> signalProcessID = genEvtInfo->signalProcessID();
  myGenEvtInfo -> qScale          = genEvtInfo->qScale();
  myGenEvtInfo -> alphaQCD        = genEvtInfo->alphaQCD();
  myGenEvtInfo -> alphaQED        = genEvtInfo->alphaQED();

}


void WZEdmAnalyzer::copyLHEweights(_event_ *myevt,  const LHEEventProduct * LHEevt) {
  if (!LHEevt) return;

  myevt->numOfWeights = LHEevt->weights().size();

  for (unsigned int ii=0; ii< LHEevt->weights().size(); ii ++) {
    myevt->weights[ii] =  LHEevt->weights()[ii].wgt;

    // std::cout << setw(15) <<  myevt->weights[ii] ;
  }

  //  std::cout << LHEevt->weights()[scaleVariationsStartIndex()].id << std::endl;

  //  std::cout << LHEevt->weights()[scaleVariationsStartIndex()].id << std::endl;
  //  std::cout << LHEevt->weights()[nnpdf3VariationsStartIndex()].id << std::endl;
  //  std::cout << LHEevt->weights()[nnpdf3AlphasVariationsStartIndex()].id << std::endl;

  //  std::cout << LHEevt->weights()[ct10VariationsStartIndex()].id << std::endl;
  //  std::cout << LHEevt->weights()[ct10AlphasVariationsStartIndex()].id << std::endl;


  //  std::cout << LHEevt->weights()[mmht2014VariationsStartIndex()].id << std::endl;
  //  std::cout << LHEevt->weights()[mmht2014AlphasVariationsStartIndex()].id << std::endl;


  //  std::cout << LHEevt->weights()[ct14VariationsStartIndex()].id << std::endl;
  //  std::cout << LHEevt->weights()[ct14AlphasVariationsStartIndex()].id << std::endl;


  //  std::cout << LHEevt->weights()[sthw2VariationsStartIndex()].id << std::endl;


  //  std::cout << std::endl;
}

void WZEdmAnalyzer::fillGenTTbar(Handle<reco::GenParticleCollection> &genParticles,  _gen_ttbar_ *genttbar) {


  //    std::cout << " a new event " << std::endl;


  const Candidate *mom   =0,    *mom1  =0,     *mom2  = 0;
  const Candidate *t     =0,    *tbar  =0;
  const Candidate *tw    =0,    *tb    =0,     *tj    = 0; 
  const Candidate *tbarw =0,    *tbarb =0,     *tbarj = 0;
  const Candidate *twl   =0,    *twv   =0,     *tbarwl= 0,  *tbarwv = 0;
  
  for(size_t i = 0; i < genParticles->size(); ++ i) {
    
    const GenParticle & p = (*genParticles)[i];
    int id = p.pdgId();
    int st = p.status();  
    
    // only look for hard-interaction particles. 
    if (st != 3) continue;
    if (abs(id) != 6) continue;
    
   
    //    std::cout << "particle " << id << std::endl;    
    if (!mom) mom = p.mother();



    if (p.numberOfMothers() >=1) mom1 = p.mother(); 
    if (p.numberOfMothers() >=2) mom2 = p.mother(1);


    /*
    if (mom) {
      
      std::cout << setw(20) << "mother particle " 
		<< setw(5)  << mom->pdgId()
		<< setw(10) << mom->pt()		
		<< setw(10) << mom->eta()
		<< setw(10) << mom->phi()
		<< setw(10) << mom->mass()
		<< setw(10) << mom->charge()
		<< std::endl;	 
    }
    */

    // 1) t->wb
    const Candidate *ww=0, *bb=0, *qq=0, *wll =0, *wvv =0;    
    for (unsigned int jj =0; jj <  p.numberOfDaughters();jj ++) {
      
      const Candidate * daug = p.daughter(jj);




      /*      
      if (daug) {
		
	std::cout << setw(20) << "daughter particle " 
		  << setw(5)  << daug->pdgId()
		  << setw(5)  << daug->status()
		  << setw(15) << daug->pt()		
		  << setw(15) << daug->rapidity()
		  << setw(15) << daug->phi()
		  << setw(15) << daug->mass()
		  << setw(15) << daug->charge()
		  << std::endl;
	
		  }
      */

      if (abs(daug->pdgId() ) == 24 ) {

	//	std::cout << "W daughters  = " << daug->numberOfDaughters() << std::endl;
	//	if ( abs( ww->daughter(0)->pdgId() ) == 24 ) 
	  ww = daug; // W+/-

	// 2) w->lnv 
	// const Candidate *ww=0, *bb=0, *jj=0, *wll, *wvv;    
	for (unsigned int kk =0; kk <  ww->numberOfDaughters();kk ++) {

	  const Candidate * wdaug = ww->daughter(kk);

	  //	  std::cout << "W daughter ID  = " << wdaug->pdgId() << std::endl;

	  if ( abs( wdaug->pdgId() ) > 16) continue;
	  if   (   (abs(wdaug->pdgId() ) == 11 )
		   || (abs(wdaug->pdgId() ) == 13 )
		   || (abs(wdaug->pdgId() ) == 15 )
		   || (abs(wdaug->pdgId() ) == 2  )
		   || (abs(wdaug->pdgId() ) == 4  ) ) {
	    
	    wll = wdaug;
	  } else {
	    wvv = wdaug;
	  }
	}


      } else if (abs(daug->pdgId()) == 5  ) {
	bb = daug; // b/bbar
      } else if (abs(daug->pdgId()) < 5) {

	if (!qq) {
	  qq = daug;  // leading quarks: u, d, c, s, or g;
	} else {

	  if (daug->pt()>qq->pt() ) qq = daug;
	}

      }


    } // end of daughter loop

    // assign to corresponding particles
    //  const Candidate *t, *tbar;
    // const Candidate *tw, *tb, *tj; 
    //const Candidate *tbarw, *tbarb, *tbarj;
    //const Candidate *twl, *twv, *tbarwl, *tbarwv;
    if (id>0) {

      t      = &p;
      tw     = ww;
      tb     = bb;
      tj     = qq;
      twl    = wll;
      twv    = wvv;
    } else {

      tbar   = &p;
      tbarw  = ww;
      tbarb  = bb;
      tbarj  = qq;
      tbarwl = wll;
      tbarwv = wvv;
    }    
  }// end of looping over gen particles



  // fill in particle information
  TLorentzVector mymom1, mymom2;
  if (mom1) mymom1.SetPtEtaPhiM( mom1->pt(), mom1->eta(), mom1->phi(),  mom1->mass());
  if (mom2) mymom2.SetPtEtaPhiM( mom2->pt(), mom2->eta(), mom2->phi(),  mom2->mass());

  if (mom1 && mom2) {

    genttbar -> ttbarPt         =   (mymom1+mymom2).Pt();
    genttbar -> ttbarEta        =   (mymom1+mymom2).Eta();
    genttbar -> ttbarPhi        =   (mymom1+mymom2).Phi();
    genttbar -> ttbarM          =   (mymom1+mymom2).M();



    genttbar->mom1Pt            =   mom1->pt();
    genttbar->mom1Eta           =   mom1->eta();
    genttbar->mom1Phi           =   mom1->phi();
    genttbar->mom1M             =   mom1->mass();
    genttbar->mom1ID            =   mom1->pdgId();


    genttbar->mom2Pt            =   mom2->pt();
    genttbar->mom2Eta           =   mom2->eta();
    genttbar->mom2Phi           =   mom2->phi();
    genttbar->mom2M             =   mom2->mass();
    genttbar->mom2ID            =   mom2->pdgId();

  }

  if (t) {
    genttbar -> tPt             =   t->pt();
    genttbar -> tEta            =   t->eta();
    genttbar -> tPhi            =   t->phi();
    genttbar -> tM              =   t->mass();
    genttbar -> tID             =   t->pdgId();
  }
  if (tw) {

    genttbar -> twPt            =   tw->pt();
    genttbar -> twEta           =   tw->eta();
    genttbar -> twPhi           =   tw->phi();
    genttbar -> twM             =   tw->mass();
    genttbar -> twID            =   tw->pdgId();
  }

  if (tb) {

    genttbar -> tbPt            =   tb->pt();
    genttbar -> tbEta           =   tb->eta();
    genttbar -> tbPhi           =   tb->phi();
    genttbar -> tbM             =   tb->mass();
    genttbar -> tbID            =   tb->pdgId();
  }
 if (tj) {
    genttbar -> tjPt            =   tj->pt();
    genttbar -> tjEta           =   tj->eta();
    genttbar -> tjPhi           =   tj->phi();
    genttbar -> tjM             =   tj->mass();
    genttbar -> tjID            =   tj->pdgId();
  }


  if (twl) {

    genttbar -> twlPt         =   twl->pt();
    genttbar -> twlEta        =   twl->eta();
    genttbar -> twlPhi        =   twl->phi();
    genttbar -> twlM          =   twl->mass();
    genttbar -> twlID         =   twl->pdgId();


  }


  if (twv) {

    genttbar -> twvPt         =   twv->pt();
    genttbar -> twvEta        =   twv->eta();
    genttbar -> twvPhi        =   twv->phi();
    genttbar -> twvM          =   twv->mass();
    genttbar -> twvID         =   twv->pdgId();
  }



  // tbar
  if (tbar) {
    genttbar -> tbarPt         =   tbar->pt();
    genttbar -> tbarEta        =   tbar->eta();
    genttbar -> tbarPhi        =   tbar->phi();
    genttbar -> tbarM          =   tbar->mass();
    genttbar -> tbarID         =   tbar->pdgId();
  }
  if (tbarw) {

    genttbar -> tbarwPt         =   tbarw->pt();
    genttbar -> tbarwEta        =   tbarw->eta();
    genttbar -> tbarwPhi        =   tbarw->phi();
    genttbar -> tbarwM          =   tbarw->mass();
    genttbar -> tbarwID         =   tbarw->pdgId();
  }

  if (tbarb) {

    genttbar -> tbarbPt         =   tbarb->pt();
    genttbar -> tbarbEta        =   tbarb->eta();
    genttbar -> tbarbPhi        =   tbarb->phi();
    genttbar -> tbarbM          =   tbarb->mass();
    genttbar -> tbarbID         =   tbarb->pdgId();
  }
 if (tbarj) {
    genttbar -> tbarjPt         =   tbarj->pt();
    genttbar -> tbarjEta        =   tbarj->eta();
    genttbar -> tbarjPhi        =   tbarj->phi();
    genttbar -> tbarjM          =   tbarj->mass();
    genttbar -> tbarjID         =   tbarj->pdgId();
  }


  if (tbarwl) {

    genttbar -> tbarwlPt         =   tbarwl->pt();
    genttbar -> tbarwlEta        =   tbarwl->eta();
    genttbar -> tbarwlPhi        =   tbarwl->phi();
    genttbar -> tbarwlM          =   tbarwl->mass();
    genttbar -> tbarwlID         =   tbarwl->pdgId();


  }


  if (tbarwv) {

    genttbar -> tbarwvPt         =   tbarwv->pt();
    genttbar -> tbarwvEta        =   tbarwv->eta();
    genttbar -> tbarwvPhi        =   tbarwv->phi();
    genttbar -> tbarwvM          =   tbarwv->mass();
    genttbar -> tbarwvID         =   tbarwv->pdgId();
  }


}


const Candidate *WZEdmAnalyzer::bornLevelParticle( const Candidate *init_p, bool address_down, bool match_initId, bool isdebug) {

  if (isdebug) {std::cout << " one entry (address down?) " << address_down << std::endl;}
  const Candidate *p = init_p;
  if (address_down ) {

    while ( (p->numberOfDaughters() == 1 ) 
	    && (abs(p->daughter(0)->pdgId()) == abs(init_p->pdgId()) )
	    && (p->daughter(0)->status() !=1) ) {

      p = p->daughter(0);
      if (isdebug) std::cout << setw(10) << p->pdgId() 
			     << setw(10) << p->status()
			     << std::endl;
    }
  } else {

    if (match_initId) {
      while ( (p->numberOfMothers() == 1 ) 
	      && (p->mother(0)->pdgId() == init_p->pdgId() )
	      && (p->mother(0)->status() !=1) ) {
	p = p->mother(0);
	if (isdebug) std::cout << setw(10) << p->pdgId() 
			       << setw(10) << p->status()
			       << std::endl;
	
	
      }
    } else {

      while ( (p->numberOfMothers() == 1 ) 
	      && (p->mother(0)->pdgId() != 2212 ) //init_p->pdgId() )
	      && (p->mother(0)->status() !=1) ) {
	p = p->mother(0);
	if (isdebug) std::cout << setw(10) << p->pdgId() 
			       << setw(10) << p->status()
			       << std::endl;
	

	
      }
    }
  }

  if (isdebug) {std::cout << " end of one entry " << std::endl;}
  return p;
}


const Candidate *WZEdmAnalyzer::showeredParticle( const Candidate *particle, const Candidate *leading_jet, const Candidate *leading_photon) {


  leading_jet    = 0;
  leading_photon = 0;
  if (!particle) return 0;


  const  Candidate *showered_particle = 0;
  std::list< const Candidate * > alist;
  std::list< const Candidate * > photons;
  std::list< const Candidate * > jets;

  alist.resize(0); photons.resize(0);
  jets.resize(0);
  alist.push_back( particle );
  while (alist.size() ) {

    const Candidate *cand = alist.front();

    bool showering = false;
    for (unsigned int ss =0; ss <  cand->numberOfDaughters();ss ++) {
      
      const Candidate * daug = cand->daughter(ss);
      if (daug->pdgId() == particle->pdgId()) {
	    
	showering = true;
	alist.push_back( daug );
      }
    }

    if (showering) {

      for (unsigned int ss =0; ss <  cand->numberOfDaughters();ss ++) {
	const Candidate * daug = cand->daughter(ss);
	if (daug->pdgId() == particle->pdgId()) continue;
	
	if ( std::abs(daug->pdgId())  == 22 ) photons.push_back( daug );
	if ( std::abs(daug->pdgId())  == 21 ) jets.push_back( daug );
      }
    }
    alist.pop_front();
    showered_particle = cand;
  }

  while (photons.size()) {

    const Candidate *cand = photons.front();
    if (leading_photon == 0) leading_photon = cand;
    else {
      if (leading_photon->pt()<cand->pt()) leading_photon = cand;
    }
    photons.pop_front();
    
  }

  while (jets.size()) {

    const Candidate *cand = jets.front();
    if (leading_jet == 0) leading_jet = cand;
    else {
      if (leading_jet->pt()<cand->pt()) leading_jet = cand;
    }
    jets.pop_front();
    
  }



  return showered_particle;
}




const Candidate *WZEdmAnalyzer::genLevelLeptonsPhotos( const Candidate *alevel, math::PtEtaPhiMLorentzVector &dressed, math::PtEtaPhiMLorentzVector &hardest_photon, double & ratio_dR01_04) {

  dressed = math::PtEtaPhiMLorentzVector(0, 0, 0, 0);

  // math::PtEtaPhiMLorentzVector 
  hardest_photon 
    =  math::PtEtaPhiMLorentzVector(0, 
  				    0, 
  				    0, 
  				    0 );
  //  double ratio_dR01_04 = 0;
  ratio_dR01_04 = 0;


  const  Candidate *bare_level =0;
  std::list< const Candidate * > alist;

  if (!alevel) return bare_level;

  bare_level = alevel;
  alist.resize(0); 
  alist.push_back( bare_level );

  while (alist.size() ) {

    const Candidate *cand = alist.front();


    for (unsigned int ss =0; ss <  cand->numberOfDaughters();ss ++) {
      
      const Candidate * daug = cand->daughter(ss);


      /*
      std::cout << setw(20) << "daughter particle " << setw(5) << ss 
		<< setw(5)  << daug->pdgId()
		<< setw(5)  << daug->status()
		<< setw(15) << daug->pt()		
		<< setw(15) << daug->eta()
		<< setw(15) << daug->phi()
		<< setw(15) << daug->mass()
		<< setw(15) << daug->charge()
		<< std::endl;

      */


      if (daug->pdgId() == alevel->pdgId()) {
	    
	if (daug->status() == 1)  { 
	  bare_level = daug;
	  
	} else {
	  
	  alist.push_back( daug );
	}
      } // search for dressed lepton


    }
    alist.pop_front();
  }


 
  if (!bare_level) return bare_level;

  dressed = math::PtEtaPhiMLorentzVector(bare_level->pt(), 
					 bare_level->eta(), 
					 bare_level->phi(), 
					 bare_level->mass() );

  if (alevel->numberOfMothers() ==0) return bare_level;

  // find FSR photons
  const Candidate *mom = alevel->mother( 0) ;

  if ( ( abs(mom->pdgId()) != 22)
       && ( abs(mom->pdgId()) != 23)
       && ( abs(mom->pdgId()) != 24) ) return bare_level;


  std::list< const Candidate * > photons;
  photons.resize(0);

  //  std::cout << "new entry: search for FSR photons" << std::endl;
  for (unsigned int ss =0; ss <  mom->numberOfDaughters();ss ++) {

    const Candidate *daug = mom->daughter(ss);
    
    if ( abs(daug->pdgId())  != 22) continue;
    if ( abs(daug->status()) != 1) {

      std::cout << "warning: photon status code is not 1 " << std::endl;
    }

    photons.push_back( daug );

    /*	 
	 std::cout << setw(20) << "daughter particle " 
	 << setw(5) << ss 
	 << setw(5)  << daug->pdgId()
	 << setw(5)  << daug->status()
	 << setw(15) << daug->pt()		
	 << setw(15) << daug->eta()
	 << setw(15) << daug->phi()
	 << setw(15) << daug->mass()
	 << setw(15) << daug->charge()
	 << std::endl;
    */
    
  }

  //  std::cout << "number of photons = " << photons.size() << std::endl;
    

  while (photons.size()) {
      
    const Candidate *cand = photons.front();

    if (cand->energy() > hardest_photon.energy()) {
      hardest_photon =  math::PtEtaPhiMLorentzVector(cand->pt(), 
						     cand->eta(), 
						     cand->phi(), 
						     0 );
    }
    

      
    if ( ROOT::Math::VectorUtil::DeltaR(  cand->momentum(), bare_level->momentum() ) < 0.1 ) {
      
      dressed += math::PtEtaPhiMLorentzVector(cand->pt(), 
					      cand->eta(), 
					      cand->phi(), 
					      0 );
      
    }  else if ( (ROOT::Math::VectorUtil::DeltaR(  cand->momentum(), bare_level->momentum() ) >=0.1) && ( ROOT::Math::VectorUtil::DeltaR(  cand->momentum(), bare_level->momentum() ) < 0.4) ) {

      if ( cand->energy()/bare_level->energy() >= ratio_dR01_04 ) {

	ratio_dR01_04 =  cand->energy()/bare_level->energy();
      }
    }
    
    
    photons.pop_front();
  }



  return bare_level;
}




const Candidate *WZEdmAnalyzer::genLevelLeptons( const Candidate *born_level, math::PtEtaPhiMLorentzVector &dressed,  math::PtEtaPhiMLorentzVector &hardest_photon, double & ratio_dR01_04) {

  // math::PtEtaPhiMLorentzVector 
  hardest_photon 
    =  math::PtEtaPhiMLorentzVector(0, 
  				    0, 
  				    0, 
  				    0 );
  //  double ratio_dR01_04 = 0;
  ratio_dR01_04 = 0;
  
  dressed = math::PtEtaPhiMLorentzVector(0, 0, 0, 0);

  if (!born_level) return 0;

  const  Candidate *bare_level =born_level;
  std::list< const Candidate * > alist;
  std::list< const Candidate * > photons;

  alist.resize(0); photons.resize(0);
  alist.push_back( born_level );

  //  std::cout << "... " << setw(10) << born_level->numberOfDaughters() 
  //	    << setw(20) << born_level->status() 
  //	    << std::endl;

  

  while (alist.size() ) {

    const Candidate *cand = alist.front();


    for (unsigned int ss =0; ss <  cand->numberOfDaughters();ss ++) {
      
      const Candidate * daug = cand->daughter(ss);


      /*
      std::cout << setw(20) << "daughter particle " << setw(5) << ss 
		<< setw(5)  << daug->pdgId()
		<< setw(5)  << daug->status()
		<< setw(15) << daug->pt()		
		<< setw(15) << daug->eta()
		<< setw(15) << daug->phi()
		<< setw(15) << daug->mass()
		<< setw(15) << daug->charge()
		<< std::endl;

      */


      if (daug->pdgId() == born_level->pdgId()) {
	    
	if (daug->status() == 1)  { 
	  bare_level = daug;
	  
	} else {
	  
	  alist.push_back( daug );
	}
      } // search for dressed lepton

      if ( daug->pdgId()  == 22 
	   && daug->status() == 1 ) photons.push_back( daug );
    }

    //    if (cand->numberOfDaughters() ==0)  bare_level = cand;

    alist.pop_front();
  }


  if (bare_level) {

    dressed += math::PtEtaPhiMLorentzVector(bare_level->pt(), 
					    bare_level->eta(), 
					    bare_level->phi(), 
					    0 );
    
    if (photons.size()>2) {std::cout << "more than 2 photos are emitted" << std::endl; }

    while (photons.size()) {

      const Candidate *cand = photons.front();

      if (cand->energy() > hardest_photon.energy()) {
	hardest_photon =  math::PtEtaPhiMLorentzVector(cand->pt(), 
						       cand->eta(), 
						       cand->phi(), 
						       0 );
      }

      if ( ROOT::Math::VectorUtil::DeltaR(  cand->momentum(), bare_level->momentum() ) < 0.1 ) {

	dressed += math::PtEtaPhiMLorentzVector(cand->pt(), 
						cand->eta(), 
						cand->phi(), 
						0 );

      } else if ( (ROOT::Math::VectorUtil::DeltaR(  cand->momentum(), bare_level->momentum() ) >=0.1) && ( ROOT::Math::VectorUtil::DeltaR(  cand->momentum(), bare_level->momentum() ) < 0.4) ) {

	if ( cand->energy()/bare_level->energy() >= ratio_dR01_04 ) {

	  ratio_dR01_04 =  cand->energy()/bare_level->energy();
	}
      }

      photons.pop_front();
    }

  }

  /*
  std::cout << setw(20) << "born level "  
	    << setw(5)  << born_level->pdgId()
	    << setw(5)  << born_level->status()
	    << setw(15) << born_level->pt()		
	    << setw(15) << born_level->eta()
	    << setw(15) << born_level->phi()
	    << setw(15) << born_level->mass()
	    << setw(15) << born_level->charge()
	    << std::endl;
  
 std::cout << setw(20) << "bare level " 
	    << setw(5)  << bare_level->pdgId()
	    << setw(5)  << bare_level->status()
	    << setw(15) << bare_level->pt()		
	    << setw(15) << bare_level->eta()
	    << setw(15) << bare_level->phi()
	    << setw(15) << bare_level->mass()
	    << setw(15) << bare_level->charge()
	    << std::endl;

 
 std::cout << setw(20) << "dress level " 
	    << setw(5)  << 0
	    << setw(5)  << 0
	    << setw(15) << dressed.Pt()		
	    << setw(15) << dressed.Eta()		
	    << setw(15) << dressed.Phi()		
	    << setw(15) << dressed.M()
	    << std::endl;
  */

  return bare_level;
}

// "p*" contains particle information with PID>0
// W+: pdaug is neutrino or u, c quarks. 
// W-: pdaug is negative leptons, u, s quarks. 
// Z : pdaug is negative leptons, neutrinos, or u, d, c, s, b quarks. 
void WZEdmAnalyzer::fillGenDrellYan(Handle<reco::GenParticleCollection> &genParticles, const LHEEventProduct * evt,  _gen_DrellYan_ *gendrellyan) {


  //  std::cout << " a new event " << std::endl;
  const Candidate *mom1   =0, *mom2=0;

  std::vector< const Candidate *  > jets;

  const Candidate *bos=0, *pdaug=0, *pdaugFSR = 0, *mdaug =0, *mdaugFSR = 0; 
  // bool countingjet = false;



  // calculate the dressed leptons
  math::PtEtaPhiMLorentzVector dressed_pdaug(0, 0, 0, 0);
  math::PtEtaPhiMLorentzVector dressed_mdaug(0, 0, 0, 0);

  math::PtEtaPhiMLorentzVector photon_pdaug(0, 0, 0, 0);
  math::PtEtaPhiMLorentzVector photon_mdaug(0, 0, 0, 0);

  double pratio_dR01_04 =0, mratio_dR01_04 = 0;


  math::PtEtaPhiMLorentzVector dressed_pdaug_photos(0, 0, 0, 0);
  math::PtEtaPhiMLorentzVector dressed_mdaug_photos(0, 0, 0, 0);

  math::PtEtaPhiMLorentzVector photon_pdaug_photos(0, 0, 0, 0);
  math::PtEtaPhiMLorentzVector photon_mdaug_photos(0, 0, 0, 0);

  double pratio_dR01_04_photos =0, mratio_dR01_04_photos = 0;

  //  bool sherpa_like = false;
  //  std::cout << "a new event " << std::endl;
  for(size_t i = 0; i < genParticles->size(); ++ i) {
    
    const GenParticle & p = (*genParticles)[i];
    int id = p.pdgId();
    int st = p.status();  
    




    // only look for hard-interaction particles. 
    if ( (std::abs(st) <21) 
	 || (std::abs(st)>29)   ) continue;


    //   std::cout << setw(10) << p.pdgId() 
    //      << setw(10) << p.status()
    //      << std::endl;


    /*      
	std::cout << setw(20) << " particle " 
	<< setw(5)  << p.pdgId()
	<< setw(5)  << p.status()
	<< setw(10) << p.pt()		
	<< setw(10) << p.eta()
	<< setw(10) << p.phi()
	<< setw(10) << p.mass()
	<< setw(10) << p.charge()
	<< std::endl;
    */


    if (abs(id) == 22
	|| abs(id) == 23
	|| abs(id) == 24) {
    
      bool debugme = false;
      bos = bornLevelParticle(&p, true, true, debugme);
      const Candidate *bos_up = bornLevelParticle(&p, false, true, debugme);


      //   countingjet = true;
      /*
	std::cout << setw(20) << " particle " 
	<< setw(5)  << p.pdgId()
	<< setw(5)  << p.status()
	<< setw(10) << p.pt()		
	<< setw(10) << p.eta()
	<< setw(10) << p.phi()
	<< setw(10) << p.mass()
	<< setw(10) << p.charge()
	<< std::endl;	 
     
      */


      if (bos_up->numberOfMothers() >=1) mom1 = bornLevelParticle( bos_up->mother(),  false, false, debugme); 
      if (bos_up->numberOfMothers() >=2) mom2 = bornLevelParticle( bos_up->mother(1), false, false, debugme);
 
      /*
      if (mom1) {
      
           std::cout << setw(20) << "mother particle " 
		     << setw(5)  << mom1->pdgId()
      	<< setw(10) << mom1->pt()		
      	<< setw(10) << mom1->eta()
      	<< setw(10) << mom1->phi()
      	<< setw(10) << mom1->mass()
      	<< setw(10) << mom1->charge()
      	<< std::endl;	 
      }
   
      if (mom2) {
      
           std::cout << setw(20) << "mother particle " 
		     << setw(5)  << mom2->pdgId()
      	<< setw(10) << mom2->pt()		
      	<< setw(10) << mom2->eta()
      	<< setw(10) << mom2->phi()
      	<< setw(10) << mom2->mass()
      	<< setw(10) << mom2->charge()
      	<< std::endl;	 
      }
    
      */

     for (unsigned int jj =0; jj <  bos->numberOfDaughters();jj ++) {
      
	const Candidate * daug = bos->daughter(jj);
	/*    
	      if (daug) {
	      
	      std::cout << setw(20) << "daughter particle " 
	      << setw(5)  << daug->pdgId()
	      << setw(5)  << daug->status()
	      << setw(15) << daug->pt()		
	      << setw(15) << daug->eta()
	      << setw(15) << daug->phi()
	      << setw(15) << daug->mass()
	      << setw(15) << daug->charge()
	      << std::endl;
	      
	      }*/
	

	if ( daug->pdgId() > 0 && abs(daug->pdgId()) <=16 ) {
	  
	  pdaug    = daug;
	  //	  pdaugFSR = genLevelLeptons( pdaug, dressed_pdaug);


	} else if ( daug->pdgId() < 0 && abs(daug->pdgId()) <=16 ) {
	  
	  mdaug    = daug;
	  //  mdaugFSR = genLevelLeptons( mdaug, dressed_mdaug);

	} else {

	}

      } // end of daughter loops



      //break; // no more boson look up    
    } else {  // sherpa

    }

  }// end of loos over all gen aprticles. 



  // check sherpa-like event content
  int sherpa_like_npartons = 0;
  if (bos == 0) {

    //    sherpa_like = true;
    for(size_t i = 0; i < genParticles->size(); ++ i) {
      
      const GenParticle & p = (*genParticles)[i];
      int id = p.pdgId();
      int st = p.status();  
      


      // only look for hard-interaction particles. 
      if ( (abs(st) <21) 
	   || (abs(st) >29) ) continue;

      sherpa_like_npartons ++;


      if (id>0 && std::abs(id)<=16 && std::abs(id)>=11) {
	
	pdaug = bornLevelParticle(&p, true, true);
	
      } else if ( id<0  && std::abs(id)<=16 && std::abs(id)>=11) {
	mdaug = bornLevelParticle(&p, true, true);

      }

    }

  }


  if (pdaug) {
    pdaugFSR = genLevelLeptons( pdaug, dressed_pdaug, photon_pdaug, pratio_dR01_04);
    genLevelLeptonsPhotos(    pdaug, dressed_pdaug_photos,  photon_pdaug_photos, pratio_dR01_04_photos);
  }

  if (mdaug)  {
    mdaugFSR = genLevelLeptons( mdaug, dressed_mdaug, photon_mdaug, mratio_dR01_04 );
    genLevelLeptonsPhotos(    mdaug, dressed_mdaug_photos,  photon_mdaug_photos, mratio_dR01_04_photos );
  }



  if (mom1) {
    for (size_t ii =0; ii < mom1->numberOfDaughters(); ii ++) {


      const Candidate * daug = mom1->daughter(ii);

      int st = daug->status();
      bool parton_level = ( abs(st)>=21 && abs(st)<=29 )
	|| ( abs(st)>=61 && abs(st)<=69 );

      if ( !parton_level  ) continue;
      if (bos->pdgId() == daug->pdgId() ) continue;
      jets.push_back( daug );


      /*
      std::cout << setw(20) << "daughter particle " 
		<< setw(5)  << daug->pdgId()
		<< setw(5)  << daug->status()
		<< setw(15) << daug->pt()		
		<< setw(15) << daug->eta()
		<< setw(15) << daug->phi()
		<< setw(15) << daug->mass()
		<< setw(15) << daug->charge()
		<< std::endl;
      */  
    }
  } 


  /*
 if (mom2) {
    for (size_t ii =0; ii < mom2->numberOfDaughters(); ii ++) {


      const Candidate * daug = mom2->daughter(ii);

      if (daug->status() != 3) continue;
      if (bos->pdgId() == daug->pdgId() ) continue;
      jets.push_back( daug );



      std::cout << setw(20) << "daughter particle " 
		<< setw(5)  << daug->pdgId()
		<< setw(5)  << daug->status()
		<< setw(15) << daug->pt()		
		<< setw(15) << daug->eta()
		<< setw(15) << daug->phi()
		<< setw(15) << daug->mass()
		<< setw(15) << daug->charge()
		<< std::endl;
    }
  }
  */


  // fill in FSR related information
  gendrellyan->pdaugPhotonPt = photon_pdaug.pt();
  gendrellyan->pdaugPhotonEta = photon_pdaug.eta();
  gendrellyan->pdaugPhotonPhi = photon_pdaug.phi();
  gendrellyan->pdaugPhoton_rdR01_04 = pratio_dR01_04;
 

  gendrellyan->pdaugPhotonPtPhotos = photon_pdaug_photos.pt();
  gendrellyan->pdaugPhotonEtaPhotos = photon_pdaug_photos.eta();
  gendrellyan->pdaugPhotonPhiPhotos = photon_pdaug_photos.phi();
  gendrellyan->pdaugPhotonPhotos_rdR01_04 = pratio_dR01_04_photos;
 

  gendrellyan->mdaugPhotonPt = photon_mdaug.pt();
  gendrellyan->mdaugPhotonEta = photon_mdaug.eta();
  gendrellyan->mdaugPhotonPhi = photon_mdaug.phi();
  gendrellyan->mdaugPhoton_rdR01_04 = mratio_dR01_04;
 

  gendrellyan->mdaugPhotonPtPhotos = photon_mdaug_photos.pt();
  gendrellyan->mdaugPhotonEtaPhotos = photon_mdaug_photos.eta();
  gendrellyan->mdaugPhotonPhiPhotos = photon_mdaug_photos.phi();
  gendrellyan->mdaugPhotonPhotos_rdR01_04 = mratio_dR01_04_photos;
 
 

  if (mom1) {

    gendrellyan->mom1Pt    =   mom1->pt();
    gendrellyan->mom1Eta    =   mom1->eta();
    gendrellyan->mom1Phi    =   mom1->phi();
    gendrellyan->mom1M    =   mom1->mass();
    gendrellyan->mom1ID    =   mom1->pdgId();

  }


 if (mom2) {

    gendrellyan->mom2Pt    =   mom2->pt();
    gendrellyan->mom2Eta    =   mom2->eta();
    gendrellyan->mom2Phi    =   mom2->phi();
    gendrellyan->mom2M    =   mom2->mass();
    gendrellyan->mom2ID    =   mom2->pdgId();

  }

 if (bos) {

    gendrellyan->bosPt    =   bos->pt();
    gendrellyan->bosEta    =   bos->eta();
    gendrellyan->bosPhi    =   bos->phi();
    gendrellyan->bosM    =   bos->mass();
    gendrellyan->bosID    =   bos->pdgId();

 } else {

   if (pdaug && mdaug) {


     math::PtEtaPhiMLorentzVector bos_v4(0, 0, 0, 0);
     bos_v4 += math::PtEtaPhiMLorentzVector( pdaug->pt(), pdaug->eta(), pdaug->phi(), pdaug->mass() );
     bos_v4 += math::PtEtaPhiMLorentzVector( mdaug->pt(), mdaug->eta(), mdaug->phi(), mdaug->mass() );
     
     gendrellyan->bosPt  = bos_v4.Pt();
     gendrellyan->bosEta = bos_v4.Eta();
     gendrellyan->bosPhi = bos_v4.Phi();
     gendrellyan->bosM   = bos_v4.M();

   }
   
 }


 if (pdaug) {

   gendrellyan->pdaugPt     =   pdaug->pt();
   gendrellyan->pdaugEta    =   pdaug->eta();
   gendrellyan->pdaugPhi    =   pdaug->phi();
   gendrellyan->pdaugM      =   pdaug->mass();
   gendrellyan->pdaugID     =   pdaug->pdgId();

 }



 gendrellyan->pdaugPtDressPhotos  = dressed_pdaug_photos.Pt();
 gendrellyan->pdaugEtaDressPhotos = dressed_pdaug_photos.Eta();
 gendrellyan->pdaugPhiDressPhotos = dressed_pdaug_photos.Phi();
 gendrellyan->pdaugMDressPhotos   = dressed_pdaug_photos.M();
 


 gendrellyan->pdaugPtDress  = dressed_pdaug.Pt();
 gendrellyan->pdaugEtaDress = dressed_pdaug.Eta();
 gendrellyan->pdaugPhiDress = dressed_pdaug.Phi();
 gendrellyan->pdaugMDress   = dressed_pdaug.M();
 

 if (pdaugFSR) {

  gendrellyan->pdaugPtFSR    =   pdaugFSR->pt();
  gendrellyan->pdaugEtaFSR    =   pdaugFSR->eta();
  gendrellyan->pdaugPhiFSR    =   pdaugFSR->phi();
  gendrellyan->pdaugMFSR    =   pdaugFSR->mass();


  }

 /*
 std::cout << setw(20) << gendrellyan->pdaugPt
	   << setw(20) << gendrellyan->pdaugEta
	   << setw(20) << gendrellyan->pdaugPhi
	   << setw(20) << gendrellyan->pdaugM
	   << std::endl;
 

 std::cout << setw(20) << gendrellyan->pdaugPtFSR
	   << setw(20) << gendrellyan->pdaugEtaFSR
	   << setw(20) << gendrellyan->pdaugPhiFSR
	   << setw(20) << gendrellyan->pdaugMFSR
	   << std::endl;
 
 
 std::cout << setw(20) << gendrellyan->pdaugPtDress
	   << setw(20) << gendrellyan->pdaugEtaDress
	   << setw(20) << gendrellyan->pdaugPhiDress
	   << setw(20) << gendrellyan->pdaugMDress
	   << std::endl;
 
 */

 if (mdaug) {
   
   gendrellyan->mdaugPt    =   mdaug->pt();
   gendrellyan->mdaugEta    =   mdaug->eta();
   gendrellyan->mdaugPhi    =   mdaug->phi();
   gendrellyan->mdaugM    =   mdaug->mass();
   gendrellyan->mdaugID    =   mdaug->pdgId();
   
   }



 gendrellyan->mdaugPtDressPhotos = dressed_mdaug_photos.Pt();
 gendrellyan->mdaugEtaDressPhotos = dressed_mdaug_photos.Eta();
 gendrellyan->mdaugPhiDressPhotos = dressed_mdaug_photos.Phi();
 gendrellyan->mdaugMDressPhotos = dressed_mdaug_photos.M();

 gendrellyan->mdaugPtDress = dressed_mdaug.Pt();
 gendrellyan->mdaugEtaDress = dressed_mdaug.Eta();
 gendrellyan->mdaugPhiDress = dressed_mdaug.Phi();
 gendrellyan->mdaugMDress = dressed_mdaug.M();
 

 if (mdaugFSR) {

  gendrellyan->mdaugPtFSR    =   mdaugFSR->pt();
  gendrellyan->mdaugEtaFSR    =   mdaugFSR->eta();
  gendrellyan->mdaugPhiFSR    =   mdaugFSR->phi();
  gendrellyan->mdaugMFSR    =   mdaugFSR->mass();


  }

 /*
 std::cout << setw(20) << gendrellyan->mdaugPt
	   << setw(20) << gendrellyan->mdaugEta
	   << setw(20) << gendrellyan->mdaugPhi
	   << setw(20) << gendrellyan->mdaugM
	   << std::endl;
 
 
 std::cout << setw(20) << gendrellyan->mdaugPtFSR
	   << setw(20) << gendrellyan->mdaugEtaFSR
	   << setw(20) << gendrellyan->mdaugPhiFSR
	   << setw(20) << gendrellyan->mdaugMFSR
	   << std::endl;
 
 
 std::cout << setw(20) << gendrellyan->mdaugPtDress
	   << setw(20) << gendrellyan->mdaugEtaDress
	   << setw(20) << gendrellyan->mdaugPhiDress
	   << setw(20) << gendrellyan->mdaugMDress
	   << std::endl;
 
 */

  //  std::cout << " number of jets " << jets.size() << std::endl;

   gendrellyan->numberOfJets  = sherpa_like_npartons;



  std::list< int > indexs;
  indexs.resize(0);
  for (size_t ii = 0; ii < jets.size(); ii ++) {

    if (indexs.size() == 0) {

      indexs.push_back( ii );

    } else {

      size_t nsize = indexs.size();
      for (std::list< int > ::iterator jj = indexs.begin(); jj !=indexs.end(); ++jj) {

	if (  jets[ii]->pt() > jets[ *jj ]->pt() ) {

	  indexs.insert(jj, ii); break;
	}

      }

      // in case failing inserting 
      if (nsize == indexs.size() ) indexs.push_back( ii );
    }
  }


  int mycounter = 0;
  //  std::cout << "one event " << std::endl;
  for (std::list< int > ::iterator  ii = indexs.begin(); ii != indexs.end() ; ii ++) {


    if (mycounter < EDM_MAX_LENGTH ) {


      gendrellyan->jv4[mycounter][0]  = jets[ *ii ]->pt();
      gendrellyan->jv4[mycounter][1]  = jets[ *ii ]->eta();
      gendrellyan->jv4[mycounter][2]  = jets[ *ii ]->phi();
      gendrellyan->jv4[mycounter][3]  = jets[ *ii ]->mass();
      gendrellyan->jpid[mycounter]    = jets[ *ii ]->pdgId();

      //      std::cout <<  jets[ *ii ]->pt() << std::endl;
    }

    mycounter ++;
  }


  if (evt) {

  // fill the necessary matrix element information
  //  if (evt->pdf() ) {
  //
  //  gendrellyan ->  x1            = evt->pdf()->x.first;
  //  gendrellyan ->  x2            = evt->pdf()->x.second;
  //  gendrellyan ->  flav1         = evt->pdf()->id.first;
  //  gendrellyan ->  flav2         = evt->pdf()->id.second;
  //  gendrellyan ->  xfx1          = evt->pdf()->xPDF.first; 
  //  gendrellyan ->  xfx2          = evt->pdf()->xPDF.second;
  //  gendrellyan ->  scalePDF      = evt->pdf()->scalePDF; // Q valued used in PDF evolution.
  // }



  const lhef::HEPEUP hepeup_ = evt->hepeup();
      
  const int nup_ = hepeup_.NUP; 
  const std::vector<int> idup_ = hepeup_.IDUP;
  const std::vector<lhef::HEPEUP::FiveVector> pup_ = hepeup_.PUP;




      
  if (nup_ > EDM_MAX_LENGTH*2 ) {


    gendrellyan->numOfParticles =  EDM_MAX_LENGTH*2;
  } else {

    gendrellyan->numOfParticles = nup_;
  }
  //  std::cout << "Number of particles = " << nup_ << std::endl;
      
  for ( unsigned int icount = 0 ; icount < (unsigned int)nup_; icount++ ) {
	
    //  Double_t px, py, pz, e;

    //    px =  (pup_[icount])[0];
    // py =  (pup_[icount])[1];
    // pz =  (pup_[icount])[2];
    // e  =  (pup_[icount])[3];
    

    if (icount < EDM_MAX_LENGTH*2) {

      gendrellyan->mepid[icount]   =  idup_[icount] ;
      gendrellyan->mev4[icount][0] =  (pup_[icount])[0] ;
      gendrellyan->mev4[icount][1] =  (pup_[icount])[1] ;
      gendrellyan->mev4[icount][2] =  (pup_[icount])[2] ;
      gendrellyan->mev4[icount][3] =  (pup_[icount])[3] ;
      gendrellyan->mev4[icount][4] =  (pup_[icount])[4] ;
    }

    /*
    TLorentzVector test; test.SetPxPyPzE(px, py, pz, e);

    std::cout << "# " << std::setw(14) << std::fixed << icount 
	      << std::setw(14) << std::fixed << idup_[icount] 
	      << std::setw(14) << std::fixed << (pup_[icount])[0] 
	      << std::setw(14) << std::fixed << (pup_[icount])[1] 
	      << std::setw(14) << std::fixed << (pup_[icount])[2] 
	      << std::setw(14) << std::fixed << (pup_[icount])[3] 
	      << std::setw(14) << std::fixed << (pup_[icount])[4] 
	      << std::endl;
    if (test.Pt()>0) 
    std::cout << test.Pt() << ", " << test.Eta() << ", " << test.Phi() << ", " << test.Mag() << std::endl;

    */

  }


  }

}







// temperary solution to access Z/gamma* -> mumu
void WZEdmAnalyzer::fillMCInfo(Handle<reco::GenParticleCollection> &genParticles,  _mc_process_ *mc) {


 for(size_t i = 0; i < genParticles->size(); ++ i) {

     const GenParticle & p = (*genParticles)[i];
     int id = p.pdgId();
     //     int st = p.status();  

     //  if (st == 1) continue;
     if (abs(id) != 23 
	 && abs(id) != 22) continue; // 



     //     const Candidate * mom = p.mother();
     //     double pt = p.pt(), eta = p.eta(), phi = p.phi(), mass = p.mass();
     // double vx = p.vx(), vy = p.vy(), vz = p.vz();
     //int charge = p.charge();


     unsigned int n = p.numberOfDaughters();
     if (n< 2) continue;  

     //std::cout << "display of daughters ... " << std::endl;
     const Candidate *muminus=0, *muplus=0;
     for(size_t j = 0; j < n; ++ j) {
       const Candidate * d = p.daughter( j );
       //       int dauId = d->pdgId();


       //  std::cout << dauId << ", status = " << d->status() << std::endl;
       if (d->pdgId() == 13) muminus = d;
       if (d->pdgId() == -13) muplus = d;
       
       // . . . 
     }

     if (muminus && muplus) {

       mc->bosPt   = p.pt();
       mc->bosPz   = p.pz();
       mc->bosPhi  = p.phi();
       mc->bosMass = p.mass();
       mc->bosRap  = p.rapidity();
       mc->bosId   = p.pdgId();


       mc->muonPt        = muminus->pt();
       mc->muonPz        = muminus->pz();
       mc->muonEta       = muminus->eta();
       mc->muonPhi       = muminus->phi();
       mc->muonEnergy    = muminus->energy();
       mc->muonBarPt     = muplus->pt();
       mc->muonBarPz     = muplus->pz();
       mc->muonBarEta    = muplus->eta();
       mc->muonBarPhi    = muplus->phi();
       mc->muonBarEnergy = muplus->energy();

       return;

     }


     // . . . 
   }

}


void  
WZEdmAnalyzer::fillMCInfo( Handle<edm::HepMCProduct> &mcTruth, _mc_process_ *mc)
{

  if (_is_debug) {
    std::cout << "check point ...  fillMCInfo() " << std::endl;
    // genEvt->print(); 
  }

  mc->Initialize(); // clean the object

  const HepMC::GenEvent  *genEvt           =  mcTruth->GetEvent();

  //  mc->mpi = genEvt->mpi();
  mc->processId   = genEvt->signal_process_id();
  mc->eventNumber = genEvt->event_number();
  if (genEvt->signal_process_vertex()) {
    mc->vtxBarcode = genEvt->signal_process_vertex()->barcode();
  }

  mc->eventScale = genEvt->event_scale();
  mc->alphaQCD   = genEvt->alphaQCD();
  mc->alphaQED   = genEvt->alphaQED();
  if (genEvt->pdf_info()) {  // correct information

    mc->x1       = genEvt->pdf_info()->x1();
    mc->x2       = genEvt->pdf_info()->x2();
    mc->flav1    = genEvt->pdf_info()->id1();
    mc->flav2    = genEvt->pdf_info()->id2();
    mc->scalePDF = genEvt->pdf_info()->scalePDF();
    mc->xfx1     = genEvt->pdf_info()->pdf1();
    mc->xfx2     = genEvt->pdf_info()->pdf2();
  }


  HepMC::GenParticle *q1=0, *q2=0;
  HepMC::GenParticle *daug1= 0, *daug2= 0, *daug3= 0;
  HepMC::GenParticle *dd1= 0, *dd2= 0;//direct daughters of the hard interaction
  for ( HepMC::GenEvent::particle_const_iterator p = genEvt->particles_begin();
	p != genEvt->particles_end(); ++p ) {

    q1 = 0;
    q2 = 0;
    daug1 = 0;
    daug2 = 0;
    daug3 = 0;
    dd1 = 0;
    dd2 = 0;


    // concentrate on s-channel vector boson process
    if ( abs((*p)->pdg_id()) != 22 
	 && abs((*p)->pdg_id()) != 23
	 && abs((*p)->pdg_id()) != 24
	 && abs((*p)->pdg_id()) != 32
	 && abs( (*p)->pdg_id()) != 34 ) continue;
 
    if (_is_debug) {
      
      std::cout << "check point ...  interesting vector boson existing " << std::endl;
      (*p)->print();
    }

    if ( !(*p)->production_vertex()  || !(*p)->end_vertex() ) continue;



    // 1) access the interacting quark information
    for ( HepMC::GenVertex::particle_iterator mother = (*p)->production_vertex()->particles_begin(HepMC::parents);
	  mother != (*p)->production_vertex()->particles_end(HepMC::parents); 
	  ++mother ) {
      // note the temporary change to deal with Wprime. 
      //     if ((*mother)->status() != 3) continue;

      if (!q1) q1 = *mother;
      if (q1)  q2 = *mother;

      if (_is_debug) {
	std::cout << endl;
	(*mother)->print();
      }
    }

    // something special for wprime
    //    if (abs( (*p)->pdg_id()) == 34) {
    //     if (!q1 || !q2) continue;
    // } else {
      if (!q1 || !q2 || q1 == q2) continue;
      //}


    // 2) access daughter informations
    //    this might only work for leptonic decays
    int nphotons = 0;
    for ( HepMC::GenVertex::particle_iterator des =(*p)->end_vertex()->particles_begin(HepMC::descendants);
	  des != (*p)->end_vertex()->particles_end(HepMC::descendants);
	  ++ des ) {

      // be careful about this
      // try to access the intermediate daughter quarks to calculate 
      // the decay angles. 
      if ( (*des)->status() == 3  
	   && abs( (*des)->pdg_id() )< 22 ) {

	if (!dd1) dd1 = *des; 
	if (dd1)  dd2 = *des;
      }

      if  ((*des)->status() != 1) continue; // skip decayed ones or documentation entries
      if ( abs( (*des)->pdg_id() ) == 16 ) continue; // skip tau neutrino
      if ( abs( (*des)->pdg_id() ) < 22 && !daug1) daug1 = (*des);
      if ( abs( (*des)->pdg_id() ) < 22 && daug1) daug2 = (*des);

      // most energetic radiated photon
      if (  abs( (*des)->pdg_id() ) == 22 ) {

	nphotons ++;
	if ( !daug3) daug3 = (*des);
	else if ( (*des)->momentum().e() > daug3->momentum().e() ) {

	  daug3 = (*des);
	}
      }

      if (_is_debug) {
	std::cout << endl;
	(*des)->print();
      }
    }

    if (dd1 && dd2 && (daug1 == daug2) ) { // Only one of 1-1 pair found, or none of 1-1 pair was found
      if ( !daug1) {daug1 = dd1; daug2 = dd2;}
      else {
	if ( dd1->pdg_id() == daug1->pdg_id() ) {daug2 = dd2;}
	else {daug2 = dd1;}
      }
    }
    if ( !daug1 || !daug2 || daug1 == daug2)  continue;
    if (_is_debug) std::cout << "check point ... " << " getMCInfo() -- dauther/parents information " << std::endl;






    // 3) now record some quantities;
    // a) vector boson information
    TLorentzVector vecbos((*p)->momentum().x(), 
			  (*p)->momentum().y(), 
			  (*p)->momentum().z(), 
			  (*p)->momentum().t()); 

    if (dd1)    mc->decayType = abs( dd1->pdg_id() );
    mc->bosPt   = vecbos.Pt();
    mc->bosPz   = vecbos.Pz();
    mc->bosPhi  = vecbos.Phi();
    mc->bosMass = vecbos.M();
    if ( vecbos.Pt() )      mc->bosEta  = vecbos.PseudoRapidity();
    mc->bosRap  = vecbos.Rapidity();
    mc->bosId   = (*p)->pdg_id();


    // b) access daughter information. 
    if (_is_debug) std::cout << "check point ... " << " getMCInfo() (b)" << std::endl;
    TLorentzVector muon, muonplus;
    if (daug1->pdg_id() > 0) {
      muon.SetXYZT(daug1->momentum().x(),
		   daug1->momentum().y(),
		   daug1->momentum().z(),
		   daug1->momentum().t() );
      mc->muonId = daug1->pdg_id();

      muonplus.SetXYZT(daug2->momentum().x(),
		       daug2->momentum().y(),
		       daug2->momentum().z(),
		       daug2->momentum().t() );
      mc->muonBarId = daug2->pdg_id();

    } else {

      muon.SetXYZT(daug2->momentum().x(),
		   daug2->momentum().y(),
		   daug2->momentum().z(),
		   daug2->momentum().t() );
      mc->muonId = daug2->pdg_id();

      muonplus.SetXYZT(daug1->momentum().x(),
		       daug1->momentum().y(),
		       daug1->momentum().z(),
		       daug1->momentum().t() );
      mc->muonBarId = daug1->pdg_id();
    }
    mc->muonPt        = muon.Pt();
    mc->muonPz        = muon.Pz();
    mc->muonEta       = muon.PseudoRapidity();
    mc->muonPhi       = muon.Phi();
    mc->muonEnergy    = muon.E();
    mc->muonBarPt     = muonplus.Pt();
    mc->muonBarPz     = muonplus.Pz();
    mc->muonBarEta    = muonplus.PseudoRapidity();
    mc->muonBarPhi    = muonplus.Phi();
    mc->muonBarEnergy = muonplus.E();

    // c) calculate the decay angles. 
    // tmp1 is for the particle and tmp2 is for anti-particle. 
    if (_is_debug) std::cout << "check point ... " << " getMCInfo() (c)" << std::endl;
    TLorentzVector tmp1, tmp2, quark;
    if (dd1 && dd2 && (dd1 !=dd2) ) {

      if (dd1->pdg_id() > 0) {
	tmp1.SetXYZT(dd1->momentum().x(), dd1->momentum().y(), dd1->momentum().z(), dd1->momentum().t() );
	tmp2.SetXYZT(dd2->momentum().x(), dd2->momentum().y(), dd2->momentum().z(), dd2->momentum().t() );
	mc->nrmuonId = dd1->pdg_id();       mc->nrmuonBarId = dd2->pdg_id();
      } else {
	tmp1.SetXYZT(dd2->momentum().x(), dd2->momentum().y(), dd2->momentum().z(), dd2->momentum().t() );
	tmp2.SetXYZT(dd1->momentum().x(), dd1->momentum().y(), dd1->momentum().z(), dd1->momentum().t() );
	mc->nrmuonId = dd2->pdg_id();       mc->nrmuonBarId = dd1->pdg_id();
      }
      // Save the daughter muon information before radiation
      mc->nrmuonPt        = tmp1.Pt();
      mc->nrmuonPz        = tmp1.Pz();
      mc->nrmuonEta       = tmp1.PseudoRapidity();
      mc->nrmuonPhi       = tmp1.Phi();
      mc->nrmuonEnergy    = tmp1.E();
      mc->nrmuonBarPt     = tmp2.Pt();
      mc->nrmuonBarPz     = tmp2.Pz();
      mc->nrmuonBarEta    = tmp2.PseudoRapidity();
      mc->nrmuonBarPhi    = tmp2.Phi();
      mc->nrmuonBarEnergy = tmp2.E();
 
      if (q1->pdg_id() > 0) {

      quark.SetXYZT(q1->momentum().x(), q1->momentum().y(), q1->momentum().z(), q1->momentum().t() );
      } else {
	quark.SetXYZT(q2->momentum().x(), q2->momentum().y(), q2->momentum().z(), q2->momentum().t() );
      }
      mc->cosTheta = calCosTheta(quark, tmp1, tmp2);
    }


    // d) dilepton information
    if (_is_debug) std::cout << "check point ... " << " getMCInfo() (d)" << std::endl;
    TLorentzVector dilepton( muon + muonplus );
    mc->dileptonPt   = dilepton.Pt();
    mc->dileptonPz   = dilepton.Pz();
    mc->dileptonMass = dilepton.M();
    mc->dileptonEta  = dilepton.PseudoRapidity();
    mc->dileptonRap  = dilepton.Rapidity();
    mc->dileptonPhi  = dilepton.Phi();
    mc->cosPhi      = cos(muon.Vect().Angle( muonplus.Vect() ));
    mc->nphotons     = nphotons;

    // e) radiated photon information
    if (_is_debug) std::cout << "check point ... " << " getMCInfo() (e)" << std::endl;
    if (daug3) {

      mc->photonEnergy = daug3->momentum().e();
      mc->photonEta    = daug3->momentum().eta();
      mc->photonPhi    = daug3->momentum().phi();

      TVector3 photonVec(daug3->momentum().x(), daug3->momentum().y(),daug3->momentum().z() );
      mc->photonAngle = photonVec.Angle( dilepton.Vect() );
    }


    /**********************************************************************
     *
     * some specific information for each process
     *
     *********************************************************************/
    // f.1) angular distributions. 
    if (_is_debug) std::cout << "check point ...  getMCInfo() (f.1)" << std::endl;
    double result[3];
    calCSVariables(muon, muonplus, result, ( dilepton.Pz()<0 ));
    mc->cosThetaCS  = result[0];
    mc->sin2ThetaCS = result[1];
    mc->tanPhiCS    = result[2];

    // calculate the mistag-corrected angular distributions
    bool swap_quark = false;
    if (genEvt->pdf_info()) {
      
      if ( genEvt->pdf_info()->id1() < 0 ) swap_quark = true;

    } else {
      if ( (q1->pdg_id() > 0 && q1->momentum().pz() < 0)
	   || (q2->pdg_id() > 0 && q2->momentum().pz() < 0)) swap_quark = true;
    }
    calCSVariables(muon, muonplus, result, swap_quark);
    mc->corCosThetaCS  = result[0];
    mc->corSin2ThetaCS = result[1];
    mc->corTanPhiCS    = result[2];

    if ( (swap_quark == 0 && dilepton.Pz() >0 ) 
	 || (swap_quark == 1 && dilepton.Pz() <0 ) ) {
      mc->sameSign = 1; 
    }   else {
      mc->sameSign = -1; 
    }


    // calculate the mistag rate for Z/gamma process
    // NOTE74 comment this out
    /*
    if (_is_debug) std::cout << "check point ...  getMCInfo() (mistag Z/gamma*)" << std::endl;
    double wx1 = 0, wx2 = 0;
    wx1 = pdf_x1( mc->dileptonMass, mc->dileptonRap);
    wx2 = pdf_x2( mc->dileptonMass, mc->dileptonRap);

    if ((wx1 < xmax && wx1 >xmin) 
	&& (wx2 < xmax && wx2 >xmin) ) {

      if ( abs( (*p)->pdg_id() ) != 24 ) {

	mc->qqbar = qqbar(wx1, wx2, mc->dileptonMass );
	mc->qbarq = qqbar(wx2, wx1, mc->dileptonMass );

	// the mistag probability
	if (wx1 > wx2) {

	  mc->mistag = mc->qbarq/(mc->qqbar + mc->qbarq); 
	} else {
	  
	  mc->mistag = mc->qqbar/(mc->qqbar + mc->qbarq); 
	}
 
      } else {
      
	if ( (*p)->pdg_id() > 0) { // W+
	  
	  mc->qqbar   = qqbar(wx1, wx2, +1);
	  mc->qbarq   = qqbar(wx2, wx1, +1);

	} else { // W-
	    
	  mc->qbarq   = qqbar(wx1, wx2, -1);
	  mc->qqbar   = qqbar(wx2, wx1, -1);	
	}
      
	mc->fprob =  (mc->qqbar * 0.875 + 0.125 * mc->qbarq)/(mc->qqbar + mc->qbarq);						  
	mc->bprob =  1 - mc->fprob;
      }
    }
  
    */


    break;
  }  // end of the loop

  if (_is_debug) std::cout << "check point ...  finishing getMCInfo() " << std::endl;

}


