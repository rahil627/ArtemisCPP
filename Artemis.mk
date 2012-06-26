##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Artemis
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "C:\Users\Sidar\Documents\Sidar\C++\ST"
ProjectPath            := "C:\Users\Sidar\Documents\Sidar\C++\ST\Artemis"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Sidar
Date                   :=26-6-2012
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
CompilerName           :=g++
C_CompilerName         :=gcc
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)_ARTEMIS_DEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="C:\Users\Sidar\Documents\Sidar\C++\ST\Artemis\Artemis.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
CmpOptions             := -g -O0 -Wall -std=c++0x  $(Preprocessors)
C_CmpOptions           := -g -O0 -Wall  $(Preprocessors)
LinkOptions            :=  -static-libstdc++ 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)src 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
LibPath                := $(LibraryPathSwitch). 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
Objects=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/src_Component$(ObjectSuffix) $(IntermediateDirectory)/src_EntitySystem$(ObjectSuffix) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects) > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "C:/Users/Sidar/Documents/Sidar/C++/ST/Artemis/main.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "C:/Users/Sidar/Documents/Sidar/C++/ST/Artemis/main.cpp"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "C:/Users/Sidar/Documents/Sidar/C++/ST/Artemis/main.cpp"

$(IntermediateDirectory)/src_Component$(ObjectSuffix): src/Component.cpp $(IntermediateDirectory)/src_Component$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "C:/Users/Sidar/Documents/Sidar/C++/ST/Artemis/src/Component.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_Component$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Component$(DependSuffix): src/Component.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Component$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Component$(DependSuffix) -MM "C:/Users/Sidar/Documents/Sidar/C++/ST/Artemis/src/Component.cpp"

$(IntermediateDirectory)/src_Component$(PreprocessSuffix): src/Component.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Component$(PreprocessSuffix) "C:/Users/Sidar/Documents/Sidar/C++/ST/Artemis/src/Component.cpp"

$(IntermediateDirectory)/src_EntitySystem$(ObjectSuffix): src/EntitySystem.cpp $(IntermediateDirectory)/src_EntitySystem$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "C:/Users/Sidar/Documents/Sidar/C++/ST/Artemis/src/EntitySystem.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_EntitySystem$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_EntitySystem$(DependSuffix): src/EntitySystem.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_EntitySystem$(ObjectSuffix) -MF$(IntermediateDirectory)/src_EntitySystem$(DependSuffix) -MM "C:/Users/Sidar/Documents/Sidar/C++/ST/Artemis/src/EntitySystem.cpp"

$(IntermediateDirectory)/src_EntitySystem$(PreprocessSuffix): src/EntitySystem.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_EntitySystem$(PreprocessSuffix) "C:/Users/Sidar/Documents/Sidar/C++/ST/Artemis/src/EntitySystem.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_Component$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_Component$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_Component$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_EntitySystem$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_EntitySystem$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_EntitySystem$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "C:\Users\Sidar\Documents\Sidar\C++\ST\.build-debug\Artemis"


