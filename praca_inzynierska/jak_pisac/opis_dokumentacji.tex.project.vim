" ATP project vim script: czw lis 07, 2013 at 12:31  +0100.

let b:atp_MainFile = 'opis_dokumentacji.tex'
let g:atp_mapNn = 0
let b:atp_autex = 1
let b:atp_TexCompiler = 'pdflatex'
let b:atp_TexOptions = '-synctex=1'
let b:atp_TexFlavor = 'tex'
let b:atp_auruns = '1'
let b:atp_ReloadOnError = '1'
let b:atp_OutDir = '/home/user/Downloads/Opis_dokumentacji'
let b:atp_OpenViewer = '1'
let b:atp_XpdfServer = 'opis_dokumentacji'
let b:atp_Viewer = 'okular'
let b:TreeOfFiles = {}
let b:ListOfFiles = []
let b:TypeDict = {}
let b:LevelDict = {}
let b:atp_BibCompiler = 'bibtex'
let b:atp_StarEnvDefault = ''
let b:atp_StarMathEnvDefault = ''
let b:atp_updatetime_insert = 4000
let b:atp_updatetime_normal = 2000
let b:atp_LocalCommands = ['\dd']
let b:atp_LocalEnvironments = ['uwaga', 'twr']
let b:atp_LocalColors = ['darkgray']
