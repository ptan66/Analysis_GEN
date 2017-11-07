from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

#config.General.requestName = 'testMC'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'

#config.JobType.psetName = 'had_ntuplizer_pythia8.py'
#config.JobType.psetName = 'had_ntuplizer_pythia8_photos.py'
#config.JobType.psetName = 'had_ntuplizer_pythia8_tuneup.py'
config.JobType.psetName = 'had_ntuplizer_pythia8_tunedown.py'




#config.Data.outputPrimaryDataset = 'Z_ee_NNPDF30_8TeV_pythia8'
#config.Data.outputPrimaryDataset = 'Z_ee_NNPDF30_8TeV_pythia8_photos'
#config.Data.outputPrimaryDataset = 'Z_ee_NNPDF30_8TeV_pythia8_tuneup'
config.Data.outputPrimaryDataset = 'Z_ee_NNPDF30_8TeV_pythia8_tunedown'
#config.Data.userInputFiles = open('/uscms_data/d2/ptan/work/generator/generators/PowhegBOXV2/zmumu_powheg_lhes.txt').readlines()
#config.Data.userInputFiles = open('/uscms_data/d2/ptan/work/generator/generators/PowhegBOXV2/powheg_lhe_patch2.txt').readlines()
config.Data.userInputFiles = open('/uscms_data/d2/ptan/work/generator/generators/PowhegBOXV2/powheg_lhes.txt').readlines()
config.Data.splitting = 'FileBased'
#default for zee fast MC
#config.Data.unitsPerJob =20
config.Data.unitsPerJob =4
#config.Data.outLFNDirBase = '/store/group/lpclljj/noreplica/WMA/GEN8TeV/Zmm'
config.Data.outLFNDirBase = '/store/group/lpclljj/noreplica/WMA/GEN8TeV/Zee'
config.Data.publication = False


config.Site.storageSite = 'T3_US_FNALLPC'
#config.Site.whitelist   = ['T3_US_FNALLPC', 'T1_US_FNAL']
#config.Debug.extraJDL = ['+CMS_ALLOW_OVERFLOW=False']
