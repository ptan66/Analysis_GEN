from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

#config.General.requestName = 'testMC'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
#config.JobType.generator  = 'lhe'
config.JobType.psetName = 'had_ntuplizer.py'



config.Data.outputPrimaryDataset = 'Z_ee_NNPDF30_8TeV_testme'
config.Data.userInputFiles = open('/uscms_data/d2/ptan/work/generator/generators/PowhegBOXV2/powheg_lhe_patch2.txt').readlines()
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob =20
config.Data.outLFNDirBase = '/store/user/ptan/Ntuple2015/GEN8TeV/Zee'
config.Data.publication = False


config.Site.storageSite = 'T3_US_FNALLPC'
config.Site.whitelist   = ['T3_US_FNALLPC', 'T1_US_FNAL']
config.Debug.extraJDL = ['+CMS_ALLOW_OVERFLOW=False']
