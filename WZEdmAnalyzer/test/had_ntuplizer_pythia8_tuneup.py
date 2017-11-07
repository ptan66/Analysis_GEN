# Auto generated configuration file
# using: 
# Revision: 1.381.2.28 
# Source: /local/reps/CMSSW/CMSSW/Configuration/PyReleaseValidation/python/ConfigBuilder.py,v 
# with command line options: Configuration/Powheg/Hadronizer_TuneZ2star_8TeV_generic_LHE_pythia_cff.py -s GEN --datatier GEN --eventcontent RAWSIM --conditions auto:mc --no_exec --filein file:DYToMuMuV0.lhe
import FWCore.ParameterSet.Config as cms

import FWCore.ParameterSet.VarParsing as VarParsing

#options = VarParsing.VarParsing('analysis')
#options.register('output',  '',  VarParsing.VarParsing.multiplicity.singleton, VarParsing.VarParsing.varType.string, '') 
#options.register('infile',   '', VarParsing.VarParsing.multiplicity.singleton, VarParsing.VarParsing.varType.string, '') 
#options.parseArguments()

process = cms.Process('GEN')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.Generator_cff')
process.load('IOMC.EventVertexGenerators.VtxSmearedRealistic8TeVCollision_cfi')
process.load('GeneratorInterface.Core.genFilterSummary_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.RandomNumberGeneratorService.externalLHEProducer.initialSeed = 1234
from IOMC.RandomEngine.RandomServiceHelper import RandomNumberServiceHelper
randSvc = RandomNumberServiceHelper(process.RandomNumberGeneratorService)
randSvc.populate()


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

# Input source
process.source = cms.Source("LHESource",
	fileNames = cms.untracked.vstring("file://eos/uscms/store/user/ptan/LHEfiles/Powheg/DYToEE_M50-8000_Z/lhe_10000_1110.lhe")
)

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.1 $'),
    annotation = cms.untracked.string('runs Z2* Pythia6'),
    name = cms.untracked.string('$Source: /cvs_server/repositories/CMSSW/CMSSW/Configuration/GenProduction/python/EightTeV/Hadronizer_TuneZ2star_8TeV_generic_LHE_pythia_cff.py,v $')
)

# Output definition
process.RAWSIMoutput = cms.OutputModule("PoolOutputModule",
    splitLevel = cms.untracked.int32(0),
    eventAutoFlushCompressedSize = cms.untracked.int32(5242880),
    outputCommands = process.RAWSIMEventContent.outputCommands,
    fileName = cms.untracked.string('had.root'),
    dataset = cms.untracked.PSet(
        filterName = cms.untracked.string(''),
        dataTier = cms.untracked.string('GEN')
    ),
#    SelectEvents = cms.untracked.PSet(
#        SelectEvents = cms.vstring('generation_step')
#    )
)

# Additional output definition

# Other statements
process.genstepfilter.triggerConditions=cms.vstring("generation_step")
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:mc', '')



process.generator = cms.EDFilter("Pythia8HadronizerFilter",
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
	    pythia8CUETP8M1UpVariationSettings = cms.vstring(
		'Tune:pp 14',
		'Tune:ee 7',
		'MultipartonInteractions:pT0Ref=1.8238e+00',
		'MultipartonInteractions:ecmPow=2.5208e-01',
		'MultipartonInteractions:expPow=3.230749e+00',
		'ColourReconnection:range=7.600778e+00',
		),
	    parameterSets = cms.vstring('pythia8_example07', 'pythia8CUETP8M1UpVariationSettings')
	)
    )



#ntuplizer

process.analyzer = cms.EDAnalyzer(
    "WZEdmAnalyzer",
    #parameters
    DEBUG                     = cms.bool(False),
    DATA                      = cms.bool(False),
    GEN_ONLY                  = cms.bool(False),
    MC_SIGNAL                 = cms.bool(True),


    GeneratorLevelTag         = cms.string("generator"),
    LHEEventProductTag        = cms.InputTag("source")
    )


# rename output file
process.TFileService = cms.Service("TFileService",
                                    fileName = 
                                   cms.string('testme.root' ),
                                   closeFileFast = cms.untracked.bool(True)
                                   )






#process.e = cms.EndPath(process.RAWSIMoutput)

process.p = cms.Path(process.generator+process.randomEngineStateProducer+process.VtxSmeared+process.genParticles+process.analyzer)
