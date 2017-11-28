# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: Hadronizer_TuneCUETP8M1_13TeV_generic_LHE_pythia8_cff.py --filein file://eos/uscms/store/user/ptan/LHEfiles/Powheg/DYToEE_M50-8000_Z/lhe_10000_1110.lhe --fileout file:had.root --mc --eventcontent RAWSIM --datatier GEN --conditions auto:mc --beamspot Realistic8TeVCollision --step GEN --python_filename had_ntuplizer_pythia8_newtemplate.py --no_exec
import FWCore.ParameterSet.Config as cms

process = cms.Process('GEN')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.Generator_cff')
process.load('IOMC.EventVertexGenerators.VtxSmearedRealistic8TeVCollision_cfi')
process.load('GeneratorInterface.Core.genFilterSummary_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
)

# Input source
process.source = cms.Source("LHESource",
    dropDescendantsOfDroppedBranches = cms.untracked.bool(False),
    fileNames = cms.untracked.vstring('file://eos/uscms/store/user/ptan/LHEfiles/Powheg/DYToEE_M50-8000_Z/lhe_10000_1110.lhe'),
    inputCommands = cms.untracked.vstring('keep *', 
        'drop LHEXMLStringProduct_*_*_*')
)

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('Hadronizer_TuneCUETP8M1_13TeV_generic_LHE_pythia8_cff.py nevts:1'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition

process.RAWSIMoutput = cms.OutputModule("PoolOutputModule",
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('generation_step')
    ),
    compressionAlgorithm = cms.untracked.string('LZMA'),
    compressionLevel = cms.untracked.int32(9),
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('GEN'),
        filterName = cms.untracked.string('')
    ),
    eventAutoFlushCompressedSize = cms.untracked.int32(20971520),
    fileName = cms.untracked.string('file:had.root'),
    outputCommands = process.RAWSIMEventContent.outputCommands,
    splitLevel = cms.untracked.int32(0)
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
		'TimeShower:pTmaxMatch  = 2'
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




process.ProductionFilterSequence = cms.Sequence(process.generator )

# Path and EndPath definitions
process.generation_step = cms.Path(process.pgen)
process.genfiltersummary_step = cms.EndPath(process.genFilterSummary)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.ntuplizer_step = cms.EndPath(process.analyzer)
process.RAWSIMoutput_step = cms.EndPath(process.RAWSIMoutput)

# Schedule definition
process.schedule = cms.Schedule(process.generation_step,process.genfiltersummary_step,process.endjob_step, process.ntuplizer_step)
# process.RAWSIMoutput_step)
# filter all path with the production filter sequence
for path in process.paths:
	getattr(process,path)._seq = process.ProductionFilterSequence * getattr(process,path)._seq 


# Customisation from command line

# Add early deletion of temporary data products to reduce peak memory need
from Configuration.StandardSequences.earlyDeleteSettings_cff import customiseEarlyDelete
process = customiseEarlyDelete(process)
# End adding early deletion
