from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

#config.General.requestName = 'testMC'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'test_mc.py'

config.Data.inputDataset = '/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v3/AODSIM'
config.Data.inputDBS = 'global'
config.Data.splitting = 'FileBased'
config.Data.totalUnits  =4
config.Data.unitsPerJob =2
config.Data.outLFNDirBase = '/store/user/ptan/test'
config.Data.publication = False


config.Site.storageSite = 'T3_US_FNALLPC'
#config.Site.whitelist   = T3_US_FNALLPC, T1_US_FNAL_Disk, T1_US_FNAL_MSS
