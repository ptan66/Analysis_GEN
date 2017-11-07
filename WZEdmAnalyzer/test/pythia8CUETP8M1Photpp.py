import FWCore.ParameterSet.Config as cms

generator = cms.EDFilter("Pythia8HadronizerFilter",
	maxEventsToPrint = cms.untracked.int32(0),
	pythiaPylistVerbosity = cms.untracked.int32(1),
	filterEfficiency = cms.untracked.double(1.0),
	pythiaHepMCVerbosity = cms.untracked.bool(False),

	ExternalDecays = cms.PSet(
	    Photospp = cms.untracked.PSet(
		parameterSets = cms.vstring(),
		#suppressAll = cms.bool(True),
		),
	    parameterSets = cms.vstring( "Photospp" )
	    ),

	comEnergy = cms.double(8000.),
	PythiaParameters = cms.PSet(
	    pythia8_example07 = cms.vstring(
		'POWHEG:nFinal = 1',
		'POWHEG:veto = 1',
		'POWHEG:vetoCount = 10000',
		'POWHEG:pThard = 1',
		'POWHEG:pTemt = 0',
		'POWHEG:emitted = 0',
		'POWHEG:pTdef = 1',
		'POWHEG:MPIveto = 0',
		'SpaceShower:pTmaxMatch = 2',
		'TimeShower:pTmaxMatch  = 2',
		'TimeShower:QEDshowerByGamma  = off'
		),
	    pythia8CUEP8M1Settings = cms.vstring(
		'Tune:pp 14',
		'Tune:ee 7',
		'MultipartonInteractions:pT0Ref=2.4024',
		'MultipartonInteractions:ecmPow=0.25208',
		'MultipartonInteractions:expPow=1.6',
		),
	    parameterSets = cms.vstring('pythia8_example07', 'pythia8CUEP8M1Settings')
	)
    )
