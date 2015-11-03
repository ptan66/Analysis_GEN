import FWCore.ParameterSet.Config as cms
import string



process = cms.Process("asym")
process.load("FWCore.MessageLogger.MessageLogger_cfi")
#process.MessageLogger.destinations = cms.untracked.vstring("./mymessage.log")
process.MessageLogger.suppressInfo = cms.untracked.vstring("ERROR")
process.MessageLogger.cerr.FwkReport = cms.untracked.PSet(
             reportEvery = cms.untracked.int32(1000),
             limit       = cms.untracked.int32(10000000) )

#------------------------------------------
# Load standard sequences.
#------------------------------------------
process.load('Configuration/StandardSequences/MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.GeometryDB_cff')
process.load("Configuration/StandardSequences/RawToDigi_Data_cff")
process.load("Configuration/StandardSequences/Reconstruction_cff")
process.load('Configuration/EventContent/EventContent_cff')
process.load('Configuration.StandardSequences.Services_cff')



## global tag for MC
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = 'START53_V27::All'



process.maxEvents = cms.untracked.PSet(  input = cms.untracked.int32(-1) )
process.source = cms.Source("PoolSource", 
       	fileNames = cms.untracked.vstring(
        'file:/uscms_data/d2/ptan/work/sl6/development/CMSSW_5_3_30/src/had.root'
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
    LHEEventProductTag        = cms.InputTag("externalLHEProducer")
    )


# rename output file
process.TFileService = cms.Service("TFileService",
                                    fileName = 
                                   cms.string('testme.root' ),
                                   closeFileFast = cms.untracked.bool(True)
                                   )



process.p = cms.Path(                     process.analyzer)






process.options = cms.untracked.PSet(
 wantSummary = cms.untracked.bool(True)
)



