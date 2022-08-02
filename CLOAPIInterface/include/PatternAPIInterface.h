#pragma once

#include <vector>

#include "DefineDllForWin.h"

using namespace std;

namespace CLOAPI
{
	class MV_CLO_INTERFACE_API PatternAPIInterface {
	public:

		/// @fn GetPatternSize()
		/// @brief Get the number of patterns
		///	@return return the number of patterns on the pattern editor and avatar window
		virtual int GetPatternSize() { return 0; } // deprecated. please use 'GetPatternCount()' function

		/// @fn GetPatternIndex(const string& patternName)
		/// @brief Get the pattern index which is using the pattern name
		/// @param patternName: the input pattern name to get the pattern index
		/// @return pattern index
		virtual int GetPatternIndex(const string& patternName) { return 0; }

		/// @fn GetPatternIndexW(const wstring& patternName)
		/// @brief Get the pattern index which is using the pattern name
		/// @param patternName: the pattern name to get the pattern index
		/// @return pattern index
		virtual int GetPatternIndexW(const wstring& patternName) { return 0; }
		
		/// @fn GetPatternInformation(int patternIndex)
		/// @brief Get the pattern information which is using for pattern index
		/// @param patternIndex: the pattern index to get the pattern information
		/// @return json string for pattern information
		virtual string GetPatternInformation(int patternIndex) { return ""; }

		/// @fn GetPatternInformationW(int patternIndex)
		/// @brief Get the pattern information which is using for pattern index
		/// @param patternIndex: the pattern index to get the pattern information
		/// @return json string for pattern information
		virtual wstring GetPatternInformationW(int patternIndex) { return L""; }

		/// @fn GetPatternCount()
		/// @brief Get the number of patterns
		///	@return return the number of patterns on the pattern editor and avatar window
		virtual int GetPatternCount() { return 0; }

		/// @fn GetPatternInputInformation(int patternIndex)
		/// @brief Get the pattern input information which is using for pattern index
		/// @param patternIndex: the pattern index to get the pattern input information
		/// @return json string for pattern input information
		virtual string GetPatternInputInformation(int _patternIndex) { return ""; }

		/// @fn GetPatternInputInformationW(int patternIndex)
		/// @brief Get the pattern input information which is using for pattern index
		/// @param patternIndex: the pattern index to get the pattern input information
		/// @return json string for pattern input information
		virtual wstring GetPatternInputInformationW(int _patternIndex) { return L""; }

		/// @fn GetPatternInputInformation()
		/// @brief Get the pattern input information which is using for pattern index
		/// @param patternIndex: the pattern index to get the pattern input information
		/// @return json string for pattern input information
		virtual string GetPatternInputInformation() { return ""; }

		/// @fn GetPatternInputInformationW()
		/// @brief Get the pattern input information which is using for pattern index
		/// @param patternIndex: the pattern index to get the pattern input information
		/// @return json string for pattern input information
		virtual wstring GetPatternInputInformationW() { return L""; }

		/// @fn GetPatternPieceArea()
		/// @brief Get the pattern piece area which is using for pattern index
		///	@return return pattern piece
		virtual float GetPatternPieceArea(int _patternIndex) { return 0.0f; }

		/// @fn GetLineLength()
		/// @brief Get the pattern line length which is using for pattern index and line index
		///	@return return line length
		virtual float GetLineLength(int _patternIndex, int _lineIndex) { return 0.0f; }

		/// @fn GetLineLengthForInnerShape()
		/// @brief Get the pattern line length which is using for pattern index and children shape index and line index
		///	@return return line length
		virtual float GetLineLength(int _patternIndex, int _childrenIndex, int _lineIndex) { return 0.0f; }

		/// @fn GetParticleDistanceOfPattern(int _patternIndex)
		/// @brief Get particle distance which is using pattern index
		/// @param patternIndex: the pattern index to get the pattern particle distance
		/// @return Output particle distance; If an error occurs, return MIN_PARTICLE_DISTANCE, 0.8f.
		virtual float GetParticleDistanceOfPattern(int _patternIndex)
		{
			// MIN_PARTICLE_DISTANCE : 0.8f.
			return 0.8f;
		}

		/// @fn GetParticleDistanceOfPattern(const string& _patternName)
		/// @brief Get particle distance which is using the pattern name
		/// @param patternName: the pattern name to get the pattern particle distance
		/// @return Output particle distance; If an error occurs, return MIN_PARTICLE_DISTANCE, 0.8f.
		virtual float GetParticleDistanceOfPattern(const string& _patternName)
		{
			// MIN_PARTICLE_DISTANCE : 0.8f.
			return 0.8f;
		}

		/// @fn GetParticleDistanceOfPatternW(const wstring& _patternName)
		/// @brief Get particle distance which is using the pattern name
		/// @param patternName: the pattern name to get the pattern particle distance
		/// @return Output particle distance; If an error occurs, return MIN_PARTICLE_DISTANCE, 0.8f.
		virtual float GetParticleDistanceOfPatternW(const wstring& _patternName)
		{
			// MIN_PARTICLE_DISTANCE : 0.8f.
			return 0.8f;
		}

		/// @fn GetMeshCountByType(int _patternIndex)
		/// @brief Get mesh face, vertex count by mesh type which is using pattern index
		/// @param patternIndex: the pattern index to get the pattern mesh face, vertex count
		/// @return Output map string mesh face,vertex count, mesh type; If an error occurs, return infoMap
		virtual map<string, string> GetMeshCountByType(int _patternIndex)
		{
			std::map<string, string> infoMap;
			return infoMap;
		}

		/// @fn GetMeshCountByType(const string& _patternName)
		/// @brief Get mesh face, vertex count by mesh type which is using the pattern name
		/// @param patternName: the pattern name to get the pattern mesh face, vertex count
		/// @return Output map string mesh face,vertex count, mesh type; If an error occurs, return infoMap
		virtual map<string, string> GetMeshCountByType(const string& _patternName)
		{
			std::map<string, string> infoMap;
			return infoMap;
		}

		/// @fn GetMeshCountByTypeW(const wstring& _patternName)
		/// @brief Get mesh face, vertex count by mesh type which is using the pattern name
		/// @param patternName: the pattern name to get the pattern mesh face, vertex count
		/// @return Output map string mesh face,vertex count, mesh type; If an error occurs, return infoMap

		virtual map<string, string> GetMeshCountByTypeW(const wstring& _patternName)
		{
			std::map<string, string> infoMap;
			return infoMap;
		}
		
		/// @fn GetShrinkagePercentage(int _patternIndex)
		/// @brief Get ShrinkagePercentage each width, height which is using pattern index
		/// @param patternIndex: the pattern index to get the pattern shrinkagePercentage each width, height
		/// @return Output map string shrinkagePercentage width, height; If an error occurs, return infoMap

		virtual map<string, string> GetShrinkagePercentage(int _patternIndex)
		{
			std::map<string, string> infoMap;
			return infoMap;
		}

		/// @fn GetShrinkagePercentage(const string& _patternName)
		/// @brief Get ShrinkagePercentage each width, height which is using the pattern name
		/// @param patternName: the pattern name to get the pattern shrinkagePercentage each width, height
		/// @return Output map string shrinkagePercentage width, height; If an error occurs, return infoMap

		virtual map<string, string> GetShrinkagePercentage(const string& _patternName)
		{
			std::map<string, string> infoMap;
			return infoMap;
		}

		/// @fn GetShrinkagePercentageW(const wstring& _patternName)
		/// @brief Get ShrinkagePercentage each width, height which is using the pattern name
		/// @param patternName: the pattern name to get the pattern shrinkagePercentage each width, height
		/// @return Output map string shrinkagePercentage width, height; If an error occurs, return infoMap

		virtual map<string, string> GetShrinkagePercentageW(const wstring& _patternName)
		{
			std::map<string, string> infoMap;
			return infoMap;
		}
		
		/// @fn GetBoundingBoxOfPattern()
		/// @brief Get patterns BoundingBox Size each width, height
		/// @param none
		/// @return Output vector map string patterns BoundingBox Size width, height, pattern index, pattern count; If an error occurs, return infoMap

		virtual vector<map<string, string>> GetBoundingBoxOfPattern()
		{
			vector<std::map<string, string>> vMap;
			return vMap;
		}

		/// @fn GetBoundingBoxOfPattern(int _patternIndex)
		/// @brief Get BoundingBox Size each width, height which is using pattern index
		/// @param patternIndex: the pattern index to get the pattern BoundingBox Size each width, height
		/// @return Output map string BoundingBox Size width, height; If an error occurs, return infoMap

		virtual map<string, string> GetBoundingBoxOfPattern(int _patternIndex)
		{
			std::map<string, string> infoMap;
			return infoMap;
		}

		/// @fn GetBoundingBoxOfPattern(const string& _patternName)
		/// @brief Get BoundingBox Size each width, height which is using the pattern name
		/// @param patternName: the pattern name to get the pattern BoundingBox Size each width, height
		/// @return Output map string BoundingBox Size width, height, pattern index; If an error occurs, return infoMap

		virtual map<string, string> GetBoundingBoxOfPattern(const string& _patternName)
		{
			std::map<string, string> infoMap;
			return infoMap;
		}

		/// @fn GetBoundingBoxOfPatternW(const wstring& _patternName)
		/// @brief Get BoundingBox Size each width, height which is using the pattern name
		/// @param patternName: the pattern name to get the pattern BoundingBox Size each width, height
		/// @return Output map string BoundingBox Size width, height, pattern index; If an error occurs, return infoMap

		virtual map<string, string> GetBoundingBoxOfPatternW(const wstring& _patternName)
		{
			std::map<string, string> infoMap;
			return infoMap;
		}

		/// @fn SetParticleDistanceOfPattern(int _patternIndex, float _length)
		/// @brief Set particle distance using pattern index, length
		/// @param	patternIndex: the pattern index to set the pattern particle distance,
		///			length: the length value to determine particle distance
	
		virtual void SetParticleDistanceOfPattern(int _patternIndex, float _length) {}

		/// @fn SetParticleDistanceOfPatterns()
		/// @brief Set patterns particle distance using length
		/// @param length: the length value to determine particle distance
	
		virtual void SetParticleDistanceOfPatterns(float _length) {}


		/// @fn SetMeshType(int _patternIndex, const string& _meshType)
		/// @brief Set mesh type to get mesh count information
		/// @param	patternIndex: the pattern index to set the pattern mesh type,
		///			meshType: the mesh type to set the pattern mesh type "Triangle", "Quad" Other types not allowed
	
		virtual void SetMeshType(int _patternIndex, const string& _meshType) {}

		/// @fn SetMeshType(int _patternIndex, const wstring& _meshType)
		/// @brief Set mesh type to get mesh count information
		/// @param	patternIndex: the pattern index to set the pattern mesh type,
		///			meshType: the mesh type to set the pattern mesh type "Triangle", "Quad" Other types not allowed
	
		virtual void SetMeshTypeW(int _patternIndex, const wstring& _meshType) {}

		/// @fn SetWidthShrinkagePercentage (int _patternIndex, float _width)
		/// @brief Set Width Shrinkage Percentage using pattern index, width
		/// @param	patternIndex: the pattern index to set the pattern width shrinkage percentage,
		///			width: the width value to determine width shrinkage percentage
		
		virtual void SetWidthShrinkagePercentage(int _patternIndex, float _width) {}

		/// @fn SetHeightShrinkagePercentage (int _patternIndex, float _height)
		/// @brief Set Height Shrinkage Percentage using pattern index, height
		/// @param	patternIndex: the pattern index to set the pattern height shrinkage percentage,
		///			height: the height value to determine width shrinkage percentage
	
		virtual void SetHeightShrinkagePercentage(int _patternIndex, float _height) {}

		/// @fn GetArrangementList()
		/// @brief Get all ArrangementList
		/// @param	none
		/// @return Output vector map string Arrangement information of avatar arrangementlist (Arrangement Name,Type, Offset x,y,z, Orientation); If an error occurs, return vector infoMap
	
		virtual vector<map<string, string>> GetArrangementList()
		{
			vector<std::map<string, string>> vMap;
			return vMap;
		}

		/// @fn GetArrangementOfPattern()
		/// @brief Get Arrangement of patterns
		/// @param	none
		/// @return Output vector map string Arrangement information of patterns (Arrangement Name,Type, Offset x,y,z, Orientation); If an error occurs, return vector infoMap
	
		virtual vector<map<string, string>> GetArrangementOfPattern()
		{
			vector<std::map<string, string>> vMap;
			return vMap;
		}

		/// @fn GetArrangementOfPattern(int _patternIndex)
		/// @brief Get Arrangement of pattern which is using pattern index
		/// @param patternIndex: the pattern index to get the pattern arrangement information
		/// @return Output map string Arrangement information of pattern (Arrangement Name,Type, Offset x,y,z, Orientation); If an error occurs, return infoMap
	
		virtual map<string, string> GetArrangementOfPattern(int _patternIndex)
		{
			std::map<string, string> infoMap;
			return infoMap;
		}

		/// @fn GetArrangementOfPattern(const string& _patternName)
		/// @brief Get Arrangement of pattern which is using the pattern name
		/// @param patternName: the pattern name to get the pattern arrangement information
		/// @return Output map string Arrangement information of pattern (Arrangement Name,Type, Offset x,y,z, Orientation); If an error occurs, return infoMap
	
		virtual map<string, string> GetArrangementOfPattern(const string& _patternName)
		{
			std::map<string, string> infoMap;
			return infoMap;
		}

		/// @fn GetArrangementOfPatternW(const wstring& _patternName)
		/// @brief Get Arrangement of pattern which is using the pattern name
		/// @param patternName: the pattern name to get the pattern arrangement information
		/// @return Output map string Arrangement information of pattern (Arrangement Name,Type, Offset x,y,z, Orientation); If an error occurs, return infoMap
	
		virtual map<string, string> GetArrangementOfPatternW(const wstring& _patternName)
		{
			std::map<string, string> infoMap;
			return infoMap;
		}

		/// @fn SetArrangementShapeStyle(int _patternIndex, const string& _shapeStyle)
		/// @brief Set Arrangement ShapeStyle to set Arrangement ShapeStyle
		/// @param	patternIndex: the pattern index to set the pattern Arrangement shapeStyle,
		///			shapeStyle: the shapeStyle to set the pattern shapeStyle "Flat", "Curved" Other types not allowed

		virtual void SetArrangementShapeStyle(int _patternIndex, const string& _shapeStyle) {}

		/// @fn SetArrangementShapeStyleW(int _patternIndex, const wstring& _shapeStyle)
		/// @brief Set Arrangement ShapeStyle to set Arrangement ShapeStyle
		/// @param	patternIndex: the pattern index to set the pattern arrangement ShapeStyle,
		///			shapeStyle: the shapeStyle to set the pattern shapeStyle "Flat", "Curved" Other types not allowed

		virtual void SetArrangementShapeStyleW(int _patternIndex, const wstring& _shapeStyle) {}

		/// @fn SetArrangementPosition(int _patternIndex, int _positionX, int _positionY, int _offset)
		/// @brief Set Arrangement Position using positionX, positionY, offset
		/// @param	patternIndex: the pattern index to set the pattern arrangement position,
		///			positionX, positionY, offset : the value to determine pattern arrangement positionX, positionY, offset

		virtual void SetArrangementPosition(int _patternIndex, int _positionX, int _positionY, int _offset) {}

		/// @fn SetArrangementOrientation(int _patternIndex, int _orientation)
		/// @brief Set Arrangement Orientation using pattern arrangement Orientation
		/// @param	patternIndex: the pattern index to set the pattern arrangement orientation,
		///			Orientation: the value to determine pattern arrangement orientation

		virtual void SetArrangementOrientation(int _patternIndex, int _orientation) {}

		/// @fn SetArrangement(int _patternIndex, int _arrangementIndex)
		/// @brief Set Arrangement using arrangementlist Index
		/// @param	patternIndex: the pattern index to set the arrangement
		///			ArrangementIndex: the value to determine arrangement information

		virtual void SetArrangement(int _patternIndex, int _arrangementIndex) {}


	};
}
