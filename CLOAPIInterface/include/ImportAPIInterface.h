#pragma once

#include <vector>

#include "DefineDllForWin.h"

#include "CloApiData.h"

using namespace std;

namespace Marvelous
{
	class View3DBase;
	class SceneGraph;
	class PatternEditor;
	class Library;
}

namespace CLOAPI
{
	class MV_CLO_INTERFACE_API ImportAPIInterface {
	public:
		/// @fn ImportFile(const string& filePath)
		/// @brief Load File (zprj, zpac, avt, obj, fbx, zcmr). This function will show up the dialog per the file type.
		/// @param filePath: the input file path to load
		/// @return if it succeeds, return true.
		virtual bool ImportFile(const string& filePath) { return true; }

		/// @fn ImportFileW(const wstring& filePath)
		/// @brief Load File (zprj, zpac, avt, obj, fbx, zcmr). This function will show up the dialog per the file type.
		/// @param filePath: the input file path to load
		/// @return if it succeeds, return true.
		virtual bool ImportFileW(const wstring& filePath) { return true; }

		/// @fn ImportZprj(const string& filePath, const Marvelous::ImportZPRJOption& loadOption)
		/// @brief Load zprj File without the dialog but the loadOption
		/// @param filePath: the input file path to load
		/// @param loadOption: the options to load the file
		/// @return if it succeeds, return true.
		virtual bool ImportZprj(const string& filePath, const Marvelous::ImportZPRJOption& loadOption) { return true; }

		/// @fn ImportZprjW(const wstring& filePath, const Marvelous::ImportZPRJOption& loadOption)
		/// @brief Load zprj File without the dialog but the loadOption
		/// @param filePath: the input file path to load
		/// @param loadOption: the options to load the file
		/// @return if it succeeds, return true.
		virtual bool ImportZprjW(const wstring& filePath, const Marvelous::ImportZPRJOption& loadOption) { return true; }

		/// @fn ImportGarmentInformation(const string& filePath)
		/// @brief Load Garment Information (json)
		/// @param filePath: the input file to load the garment information (.json)
		/// @return if it succeeds, return true.
		virtual bool ImportGarmentInformation(const string& filePath) { return true; }

		/// @fn ImportGarmentInformationW(const wstring& filePath)
		/// @brief Load Garment Information (json)
		/// @param filePath: the input file to load the garment information (.json)
		/// @return if it succeeds, return true.
		virtual bool ImportGarmentInformationW(const wstring& filePath) { return true; }

		/// @fn ImportGarmentInformationConfigData(const string& filePath)
		/// @brief Load Garment Information Configuration (json)		
		/// @param filePath: the input file to load the garment information configuration data(.json)
		/// @return if it succeeds, return true.
		virtual bool ImportGarmentInformationConfigData(const string& filePath) { return true; }

		/// @fn ImportGarmentInformationConfigDataW(const wstring& filePath)
		/// @brief Load Garment Information Configuration (json)		
		/// @param filePath: the input file to load the garment information configuration data(.json)
		/// @return if it succeeds, return true.
		virtual bool ImportGarmentInformationConfigDataW(const wstring& filePath) { return true; }

		///	@fn ImportOBJ(const string& _filePath, const Marvelous::ImportExportOption& _options)
		/// @brief Import OBJ file
		/// @param _filePath: input file path
		/// @param options: If "options" is given, it imports OBJ according to options, not allowing user for selecting options in Import Dialog.
		/// @return if it succeeds, return true.
		virtual bool ImportOBJ(const string& _filePath, const Marvelous::ImportExportOption& _options)
		{
			return false;
		}

		///	@fn ImportOBJW(const wstring& _filePath, const Marvelous::ImportExportOption& _options)
		/// @brief Import OBJ file
		/// @param _filePath: input file path
		/// @param options: If "options" is given, it imports OBJ according to options, not allowing user for selecting options in Import Dialog.
		/// @return if it succeeds, return true.
		virtual bool ImportOBJW(const wstring& _filePath, const Marvelous::ImportExportOption& _options)
		{
			return false;
		}

		///	@fn ImportVMP(const string& _filePath)
		/// @brief Import VMP file
		/// @param _filePath: input file path
		/// @return if it succeeds, return true.
		virtual bool ImportVMP(const string& _filePath)
		{
			return false;
		}

		///	@fn ImportVMP(const wstring& _filePath)
		/// @brief Import VMP file
		/// @param _filePath: input file path
		/// @return if it succeeds, return true.
		virtual bool ImportVMP(const wstring& _filePath)
		{
			return false;
		}

		///	@fn ImportCPT(const string& _filePath)
		/// @brief Import CPT file
		/// @param _filePath: input file path
		/// @return if it succeeds, return true.
		virtual bool ImportCPT(const string& _filePath)
		{
			return false;
		}

		///	@fn ImportCPT(const wstring& _filePath)
		/// @brief Import CPT file
		/// @param _filePath: input file path
		/// @return if it succeeds, return true.
		virtual bool ImportCPT(const wstring& _filePath)
		{
			return false;
		}

		///	@fn ImportVLP(const string& _filePath)
		/// @brief Import VLP file
		/// @param _filePath: input file path
		/// @return if it succeeds, return true.
		virtual bool ImportVLP(const string& _filePath)
		{
			return false;
		}

		///	@fn ImportVLP(const wstring& _filePath)
		/// @brief Import VLP file
		/// @param _filePath: input file path
		/// @return if it succeeds, return true.
		virtual bool ImportVLP(const wstring& _filePath)
		{
			return false;
		}

		///	@fn ImportVRP(const string& _filePath)
		/// @brief Import VRP file
		/// @param _filePath: input file path
		/// @return if it succeeds, return true.
		virtual bool ImportVRP(const string& _filePath)
		{
			return false;
		}

		///	@fn ImportVRP(const wstring& _filePath)
		/// @brief Import VRP file
		/// @param _filePath: input file path
		/// @return if it succeeds, return true.
		virtual bool ImportVRP(const wstring& _filePath)
		{
			return false;
		}

		///	@fn ImportDXF(const string& _filePath)
		/// @brief Import DXF file
		/// @param _filePath: input file path
		/// @param loadOption: the options to load the file
		/// @return if it succeeds, return true.
		virtual bool ImportDXF(const string& _filePath, const Marvelous::ImportDxfOption& loadOption) { return true; }


		///	@fn ImportDXF(const wstring& _filePath)
		/// @brief Import DXF file
		/// @param _filePath: input file path
		/// @param loadOption: the options to load the file
		/// @return if it succeeds, return true.
		virtual bool ImportDXF(const wstring& _filePath, const Marvelous::ImportDxfOption& loadOption) { return true; }
	};
}