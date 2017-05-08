import FWCore.ParameterSet.Config as cms

generator = cms.EDFilter("Pythia8HadronizerFilter",
	maxEventsToPrint = cms.untracked.int32(1),
	pythiaPylistVerbosity = cms.untracked.int32(1),
	filterEfficiency = cms.untracked.double(1.0),
	pythiaHepMCVerbosity = cms.untracked.bool(False),

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
		'TimeShower:pTmaxMatch  = 2'
		),
	    pythia8CUETP8M1DownVariationSettings = cms.vstring(
		'Tune:pp 14',
		'Tune:ee 7',
		'MultipartonInteractions:pT0Ref=2.60468e+00',
		'MultipartonInteractions:ecmPow=2.5208e-01',
		'MultipartonInteractions:expPow=1.515108e+00',
		'ColourReconnection:range=4.200868e+00',
		),
	    parameterSets = cms.vstring('pythia8_example07', 'pythia8CUETP8M1DownVariationSettings')
	)
    )
