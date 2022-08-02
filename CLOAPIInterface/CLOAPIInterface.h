#pragma once

/**
	@mainpage CLO API/SDK Reference Mainpage
	@section intro Introduction
	API calls to access the CLO functionalites
	@section info Download/manual site in English
	https://support.clo3d.com/hc/en-us/articles/360017616633-CLO-API-SDK-Guide	
*/
#include <vector>

#include "include/DefineDllForWin.h"

#include "include/ExportAPIInterface.h"
#include "include/ImportAPIInterface.h"
#include "include/RestAPIInterface.h"
#include "include/UtilityAPIInterface.h"
#include "include/FabricAPIInterface.h"
#include "include/PatternAPIInterface.h"

#ifdef REMOVE_CLOAPI_INTERFACE
#define DUMMY_CLOAPI(...) __VA_ARGS__
#else
#define DUMMY_CLOAPI(...)
#endif

using namespace std;

namespace CLOAPI
{
	class MV_CLO_INTERFACE_API APICommand
	{	
	private:
		APICommand() DUMMY_CLOAPI({});
		virtual ~APICommand();

		static APICommand* _instance;

		ExportAPIInterface* m_ExportAPIInterface;
		ImportAPIInterface* m_ImportAPIInterface;
		RestAPIInterface* m_RestAPIInterface;
		UtilityAPIInterface* m_UtilityAPIInterface;		
		FabricAPIInterface* m_FabricAPIInterface;
		PatternAPIInterface* m_PatternAPIInterface;

	 public:
		static APICommand& getInstance() DUMMY_CLOAPI({ return *(new APICommand()); });
		static void		   destroy() DUMMY_CLOAPI({});

		void				SetExportAPI(ExportAPIInterface* _interface) DUMMY_CLOAPI({});
		ExportAPIInterface* GetExportAPI();

		void				SetImportAPI(ImportAPIInterface* _interface) DUMMY_CLOAPI({});
		ImportAPIInterface* GetImportAPI();

		void			  SetRestAPI(RestAPIInterface* _interface) DUMMY_CLOAPI({});
		RestAPIInterface* GetRestAPI();

		void				 SetUtilityAPI(UtilityAPIInterface* _interface) DUMMY_CLOAPI({});
		UtilityAPIInterface* GetUtilityAPI() DUMMY_CLOAPI({ return nullptr; });

		void				SetFabricAPI(FabricAPIInterface* _interface) DUMMY_CLOAPI({});
		FabricAPIInterface* GetFabricAPI();

		void				 SetPatternAPI(PatternAPIInterface* _interface) DUMMY_CLOAPI({});
		PatternAPIInterface* GetPatternAPI();
	};
}

#define MV_CLOAPI_COMMAND (CLOAPI::APICommand::getInstance())

#define EXPORT_API (MV_CLOAPI_COMMAND.GetExportAPI())
#define IMPORT_API (MV_CLOAPI_COMMAND.GetImportAPI())
#define REST_API (MV_CLOAPI_COMMAND.GetRestAPI())
#define UTILITY_API (MV_CLOAPI_COMMAND.GetUtilityAPI())
#define FABRIC_API (MV_CLOAPI_COMMAND.GetFabricAPI())
#define PATTERN_API (MV_CLOAPI_COMMAND.GetPatternAPI())