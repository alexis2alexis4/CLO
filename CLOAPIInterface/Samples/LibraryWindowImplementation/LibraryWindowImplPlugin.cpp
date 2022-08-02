#include "stdafx.h"
#include "LibraryWindowImplPlugin.h"

#include <QFileInfo>
#include <QChar>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QDir>
#include <QDateTime>
#include <QtAlgorithms>

#include "classes/APIDefine.h"
#include "classes/APIStorage.h"
#include "classes/APIUtility.h"

#include "CLOAPIInterface.h"

// CLO API - Qt 4.8.7 dialog samples by Joshua
#include "classes/APISigninDialogSample.h"
#include "classes/APISearchDialogSample.h"
#include "classes/PLMSettingsSample.h"

#include "source/Qt3.h"

// customizing functions
#define USE_LIBRARY_WINDOW_CUSTOM_TAB  1
#define USE_CUSTOM_TAB_AS_DEFAULT	   0
#define USE_PLM_SETTINGS			   0
#define USE_DOFUNCTION				   0
#define USE_STARTUP_DOFUNCTION		   0
#define USE_AFTER_FILE_LOAD_DOFUNCTION 0
#define USE_CUSTOM_TAB_ICON	 1

myzfab* materials = 0;//Список материалов для загрузки

namespace CLOAPI
{
	Qt3* myWindowMaterial;//Окно плагина для загрузки материалов
	Qt4* myWindowColors;//Окно плагина для загрузки цветов
	Qt5* myWindowRender;//Окно плагина для настрйки рендеринга

	LibraryWindowImplPlugin* tempPoint;//Указатель на объект класса плагина

	//Запуск функции добавления материалов
	void LibraryWindowImplPlugin::test()
	{
		DESTROY_API_STORAGE;
		API_STORAGE->GenerateAPIItemListForSample();
	}

	LibraryWindowImplPlugin::LibraryWindowImplPlugin()
	{
		//QMessageBox::information(NULL, "LibraryWindowImplPlugin", "constructor");
		//UTILITY_API->DisplayMessageBox("Step 6");
		// prepare api storage instance
		API_STORAGE->GenerateAPIItemListForSample();
	}

	LibraryWindowImplPlugin::~LibraryWindowImplPlugin()
	{
		QMessageBox::information(NULL, "LibraryWindowImplPlugin", "destructor");
		//myWindowMaterial->close();
		//myWindowColors->close();
		//myWindowRender->close();
		// release api storage instance
		DESTROY_API_STORAGE;
	}

	bool LibraryWindowImplPlugin::EnableCustomUI()
	{
#if USE_LIBRARY_WINDOW_CUSTOM_TAB 
		return true;
#else
		return false;
#endif
	}

	bool LibraryWindowImplPlugin::IsDefaultTab()
	{
#if USE_CUSTOM_TAB_AS_DEFAULT
		return true;
#else
		return false;
#endif
	}

	string LibraryWindowImplPlugin::GetTabName()
	{
		string str = "BeProduct";
		return str;
	}

	string LibraryWindowImplPlugin::GetItemList(const string& itemId, unsigned int pageNo, unsigned int pageSize, CLO_FINDER_SORT sort, bool bAscending, const string& searchText)
	{
		//UTILITY_API->DisplayMessageBox("Step 1");
		//if (CLOAPISample::APISignIn::getInstance()->GetSignIn() == false)
			//return "";

		vector<CLOAPISample::LibraryAPIItem> itemList;
		vector<CLOAPISample::LibraryAPIItem> itemListForThePage;

		// search qvariantmap
		QVariantMap searchKeyValue;
		searchKeyValue[META_DATA_KEY_0_DATA_TYPE] = QString(itemId.c_str());

		if (API_STORAGE)
			itemList = API_STORAGE->GetSearchList("", searchKeyValue);

		// sort item list with ascending / descending 
		// - write code (below is the sample; in general PLM server should return the list as sorted)
		if (sort == NAME)
		{
			if (bAscending)
			{
				// use the list as-is; the sample list is sorted in Acscending in default
			}
			else
			{
				// reverse the list; the sample list is sorted in Acscending in default
				vector<CLOAPISample::LibraryAPIItem> sortedItemList;
				unsigned int listSize = (unsigned int)itemList.size();
				for (unsigned int i = 0; i < listSize; ++i)
					sortedItemList.push_back(itemList.at((listSize - 1) -i));

				itemList.clear();
				itemList = sortedItemList;
			}
		}
		else // DATE_TIME
		{
			unsigned int listSize = (unsigned int)itemList.size();

			if (bAscending)
			{
				for(size_t i=0;i< listSize - 1;++i)
					for (size_t j = i + 1; j < listSize; ++j)
					{
						if (itemList.at(i).dateTime > itemList.at(j).dateTime)
						{
							CLOAPISample::LibraryAPIItem tempItem = itemList[j];
							itemList[j] = itemList[i];
							itemList[i] = tempItem;
						}
					}
			}
			else
			{
				for (size_t i = 0; i < listSize - 1; ++i)
					for (size_t j = i + 1; j < listSize; ++j)
					{
						if (itemList.at(i).dateTime < itemList.at(j).dateTime)
						{
							CLOAPISample::LibraryAPIItem tempItem = itemList[j];
							itemList[j] = itemList[i];
							itemList[i] = tempItem;
						}
					}
			}
		}

		// get item list with pageNo / pageSize considered 
		// - write code (below is the sample)
		if (itemList.size() > 0)
		{
			for (int i = (int)pageNo - 1; i < (int)pageNo; ++i)
				for (int j = 0; j < (int)pageSize; ++j)
				{
					int curIndex = i * (int)pageSize + j;

					if (curIndex >= (int)itemList.size() || curIndex < 0)
						continue;

					itemListForThePage.push_back(itemList.at(curIndex));
				}
		}

		// get/return json string
		QString jsonStr = generateJSONFromLibraryAPIItemList(itemListForThePage);
		string result = jsonStr.toStdString();

		//QMessageBox::information(NULL, "GetItemList", result.data());

		return result;
	}

	string LibraryWindowImplPlugin::GetSearchItemList(unsigned int pageNo, unsigned int pageSize, CLO_FINDER_SORT sort, bool bAscending, const string& searchText)
	{
		//UTILITY_API->DisplayMessageBox("Step 2");
		string result = "";
		return result;
	}

	bool LibraryWindowImplPlugin::GetSearchItemList(const string& itemId, unsigned int pageNo, unsigned int pageSize, CLO_FINDER_SORT sort, bool bAscending, string& resultItemList)
	{
		//UTILITY_API->DisplayMessageBox("Step 3");
		//if (CLOAPISample::APISignIn::getInstance()->GetSignIn() == false)
			//return false;

		//QMessageBox::information(NULL, "GetSearchItemList", "GetSearchItemList");

		string result = "";		

		CLOAPISample::APISearchDialogSample searchDlg;
		searchDlg.SetSearchModeByItemId(itemId);

		if (searchDlg.exec())
		{			
			if (searchDlg.result() == QDialog::Accepted)
			{
				resultItemList = searchDlg.GetSearchResult();
				return true;
			}				
		}

		return false;
	}


	bool LibraryWindowImplPlugin::GetParentFolderID(const string& itemId, string& parentFolderID)
	{
		//UTILITY_API->DisplayMessageBox("Step 4");
		//UTILITY_API->DisplayMessageBox(itemId);
		//QMessageBox::information(NULL, "itemId", itemId.data());
		//QMessageBox::information(NULL, "parentFolderID", parentFolderID.data());
		//Sleep(500);
		if (itemId == "BUTTON1")//Библиотека материалов
		{
			myWindowMaterial->vebview();
			/*if (myWindowMaterial->isHidden())
			{
				//UTILITY_API->DisplayMessageBox("isHidden");
				myWindowMaterial->vebview();
			}
			else
			{
				//UTILITY_API->DisplayMessageBox("focus");
				myWindowMaterial->setVisible(true);
			}*/
		}
		if (itemId == "BUTTON2")//Библиотека цветов
		{
			myWindowColors->vebview();
			//myWindowColors->setFocus();
		}
		if (itemId == "BUTTON3")//Рендеринг
		{
			myWindowRender->vebview();
			//myWindowRender->setFocus();
		}
		return false;	
	}

	CLO_BYTE* LibraryWindowImplPlugin::GetPNGThumbnail(const string& itemId, unsigned int& sizeInByte)
	{
		//if (CLOAPISample::APISignIn::getInstance()->GetSignIn() == false)
			//return nullptr;

		//UTILITY_API->DisplayMessageBox("Step 5");

		CLOAPISample::LibraryAPIItem item;
		
		if (API_STORAGE)
		{
			QString filePath;
			if (API_STORAGE->GetIconThumbnailPathWithID(itemId.c_str(), filePath))
			{
				//UTILITY_API->DisplayMessageBox(filePath.toStdString());
				if (UTILITY_API->IsCLOFileFormatWithThumbnail(filePath.toStdString()))						// for CLO file format which contains thumbnails
				{
					return UTILITY_API->GetAssetIconInCLOFile(filePath.toStdString(), sizeInByte);	
				}
				else if (UTILITY_API->IsReadableImageFormat(filePath.toStdString()))						// for common type of images which can be displayed in Library Windows, CLO software
				{
					return FileLoadViaString(filePath, sizeInByte);
				}					
			}
		}

		return NULL;
	}

	string LibraryWindowImplPlugin::GetMetaData(const string& itemId)
	{
		//UTILITY_API->DisplayMessageBox("Step 6");
		//UTILITY_API->DisplayMessageBox(itemId.data());
		string result = "";
		//string result = "{\"BeProductId\":123098}";
		return result;
	}

	vector<string> LibraryWindowImplPlugin::GetMetaDataKeyListForUI(const string & itemId)
	{
		//UTILITY_API->DisplayMessageBox("Step 7");
		//UTILITY_API->DisplayMessageBox(itemId.data());
		vector<string> strList;
		
		//strList.push_back(META_DATA_KEY_0_DATA_TYPE.toStdString()); // do not show in list view
		//strList.push_back(META_DATA_KEY_1_SERVICE_DIVISION.toStdString()); // do not show in list view
		//strList.push_back(META_DATA_KEY_2_BRAND.toStdString()); // show brand in list view
		//strList.push_back(META_DATA_KEY_3_PRODUCT_TYPE.toStdString()); // show product type in list view
		//strList.push_back(META_DATA_KEY_4_SEASON_CREATED.toStdString()); // do not show in list view
		//strList.push_back("BeProductId");

		return strList;
	}

	CLO_BYTE* LibraryWindowImplPlugin::GetPreviewImage(const string& itemId, unsigned int& sizeInByte)
	{
		//if (CLOAPISample::APISignIn::getInstance()->GetSignIn() == false)
			//return nullptr;

		//UTILITY_API->DisplayMessageBox("Step 8");

		CLOAPISample::LibraryAPIItem item;

		if (API_STORAGE)
		{
			QString filePath;
			if (API_STORAGE->GetPreviewThumbnailPathWithID(itemId.c_str(), filePath))
			{				
				if (UTILITY_API->IsCLOFileFormatWithThumbnail(filePath.toStdString()))						// for CLO file format which contains thumbnails
				{
					if (UTILITY_API->IsCLOFileFormatWithTripleThumbnail(filePath.toStdString()))			// for CLO file format which contains 3 preview images (index: 0 = front thumbnail, 1 = back thumbnail)
					{
						return UTILITY_API->GetThumbnailInCLOFile(filePath.toStdString(), 0, sizeInByte);	// index: 0 = front thumbnail, 1 = back thumbnail
					}
					else
					{
						// zfab and sst files are unusual case
						if (UTILITY_API && filePath.contains(".zfab", Qt::CaseInsensitive))
							return UTILITY_API->GetThumbnailInCLOFile(filePath.toStdString(), 0, sizeInByte);
						else if (UTILITY_API && filePath.contains(".sst", Qt::CaseInsensitive))
							return UTILITY_API->GetThumbnailInCLOFile(filePath.toStdString(), 0, sizeInByte); // index: 0 = front thumbnail, 1 = back thumbnail
						else
							return UTILITY_API->GetThumbnailInCLOFile(filePath.toStdString(), 0, sizeInByte); // for CLO file format which contains only one thumnail 
					}
				}
				else if (UTILITY_API->IsReadableImageFormat(filePath.toStdString()))							// for common type of images which can be displayed in Library Windows, CLO software
				{
					return FileLoadViaString(filePath, sizeInByte);
				}
			}				
		}

		return NULL;
	}

	CLO_BYTE* LibraryWindowImplPlugin::GetFile(const string& itemId, unsigned int& sizeInByte)
	{
		//UTILITY_API->DisplayMessageBox("Step 9");
		//if (CLOAPISample::APISignIn::getInstance()->GetSignIn() == false)
			//return nullptr;

		CLOAPISample::LibraryAPIItem item;

		if (API_STORAGE)
		{
			QString filePath;
			if (API_STORAGE->GetFilePathWithID(itemId.c_str(), filePath))
				return FileLoadViaString(filePath, sizeInByte);
		}

		return NULL;
	}

	bool LibraryWindowImplPlugin::IsSigninEnabled()
	{
		//return true; // show sigin-in dialog when the user clicks 'API' tab in the Library Window
		return false;
	}

	bool LibraryWindowImplPlugin::Signin()
	{
		//if (CLOAPISample::APISignIn::getInstance()->GetSignIn())
			return true;

		CLOAPISample::APISigninDialogSample* dlg = new CLOAPISample::APISigninDialogSample();
		dlg->exec();

		if (dlg->result() == QDialog::Accepted)
		{
			QString id;
			QString passwd;

			id = dlg->GetID();
			passwd = dlg->GetPasswd();

			CLOAPISample::APISignIn::getInstance()->SetSignIn(true);
		}
		else
		{
			CLOAPISample::APISignIn::getInstance()->SetSignIn(false);
		}

		return CLOAPISample::APISignIn::getInstance()->GetSignIn();
	}

	bool LibraryWindowImplPlugin::Signin(const string& id, const string& pw, string& token)
	{
		return false;
	}

	string LibraryWindowImplPlugin::GetFavoriteList()
	{
		//UTILITY_API->DisplayMessageBox("Step 14");
		vector<CLOAPISample::LibraryAPIItem> itemList;

		// pattern item
		/*CLOAPISample::LibraryAPIItem pattern;
		pattern.itemID = "PATTERN";
		pattern.itemType = "FOLDER";
		pattern.itemName = "Patterns";
		itemList.push_back(pattern);

		// trim item
		CLOAPISample::LibraryAPIItem trim;
		trim.itemID = "TRIM";
		trim.itemType = "FOLDER";
		trim.itemName = "Trims";
		itemList.push_back(trim);

		// fabric
		CLOAPISample::LibraryAPIItem fabric;
		fabric.itemID = "FABRIC";
		fabric.itemType = "FOLDER";
		fabric.itemName = "Fabrics";
		itemList.push_back(fabric);

		// project
		CLOAPISample::LibraryAPIItem project;
		project.itemID = "PROJECT";
		project.itemType = "FOLDER";
		project.itemName = "Projects";
		itemList.push_back(project);

		// avatar
		CLOAPISample::LibraryAPIItem avatar;
		avatar.itemID = "AVATAR";
		avatar.itemType = "FOLDER";
		avatar.itemName = "Avatars";
		itemList.push_back(avatar);

		// garment
		CLOAPISample::LibraryAPIItem garment;
		garment.itemID = "GARMENT";
		garment.itemType = "FOLDER";
		garment.itemName = "Garments";
		itemList.push_back(garment);

		// sst
		CLOAPISample::LibraryAPIItem topstitch;
		topstitch.itemID = "TOPSTITCH";
		topstitch.itemType = "FOLDER";
		topstitch.itemName = "Topstitches";
		itemList.push_back(topstitch);

		// buttonhead
		CLOAPISample::LibraryAPIItem btnHead;
		btnHead.itemID = "BUTTONHEAD";
		btnHead.itemType = "FOLDER";
		btnHead.itemName = "Buttonheads";
		itemList.push_back(btnHead);

		// buttonhole
		CLOAPISample::LibraryAPIItem btnHole;
		btnHole.itemID = "BUTTONHOLE";
		btnHole.itemType = "FOLDER";
		btnHole.itemName = "Buttonholes";
		itemList.push_back(btnHole);

		// zipper puller
		CLOAPISample::LibraryAPIItem zipperPuller;
		zipperPuller.itemID = "ZIPPER_PULLER";
		zipperPuller.itemType = "FOLDER";
		zipperPuller.itemName = "Zipper_Pullers";
		itemList.push_back(zipperPuller);
		
		// zipper slider
		CLOAPISample::LibraryAPIItem zipperSlider;
		zipperSlider.itemID = "ZIPPER_SLIDER";
		zipperSlider.itemType = "FOLDER";
		zipperSlider.itemName = "Zipper_Sliders";
		itemList.push_back(zipperSlider);
		
		// zipper top stopper
		CLOAPISample::LibraryAPIItem zipperTopStopper;
		zipperTopStopper.itemID = "ZIPPER_TOP_STOPPER";
		zipperTopStopper.itemType = "FOLDER";
		zipperTopStopper.itemName = "Zipper_Top_Stoppers";
		itemList.push_back(zipperTopStopper);
		
		// zipper bottom stopper
		CLOAPISample::LibraryAPIItem zipperBottomStopper;
		zipperBottomStopper.itemID = "ZIPPER_BOTTOM_STOPPER";
		zipperBottomStopper.itemType = "FOLDER";
		zipperBottomStopper.itemName = "Zipper_Bottom_Stoppers";
		itemList.push_back(zipperBottomStopper);*/

		/*if (materials != 0)
		{
			zfab* a = materials->first;
			for (int i = 0; i < materials->count; i++)
			{
				if (a->isActive == 1)
				{
					CLOAPISample::LibraryAPIItem myFabric;
					//myModel.itemID = "MY_MODEL1234";
					if(i == 0)myFabric.itemID = "FABRIC";
					else myFabric.itemID = "FABRIC1";
					myFabric.itemType = "FOLDER";
					myFabric.itemName = a->name;
					itemList.push_back(myFabric);
				}
				a = a->next;
			}
		}*/

		//Папка с загружеными материалами
		CLOAPISample::LibraryAPIItem myFabric;
		myFabric.itemID = "FABRIC";
		myFabric.itemType = "FOLDER";
		myFabric.itemName = "Materials";
		itemList.push_back(myFabric);

		//Material Library
		CLOAPISample::LibraryAPIItem Button1;
		Button1.itemID = "BUTTON1";
		Button1.itemType = "FILE";
		Button1.itemName = "Material Library";
		itemList.push_back(Button1);

		//Color Library
		CLOAPISample::LibraryAPIItem Button2;
		Button2.itemID = "BUTTON2";
		Button2.itemType = "FILE";
		Button2.itemName = "Color Library";
		itemList.push_back(Button2);

		//Sink To Cloud
		CLOAPISample::LibraryAPIItem Button3;
		Button3.itemID = "BUTTON3";
		Button3.itemType = "FILE";
		Button3.itemName = "Sync To Cloud";
		itemList.push_back(Button3);


				

		/*if (viewMode == -1)
		{
			//My Model
			CLOAPISample::LibraryAPIItem myModel;
			myModel.itemID = "MY_MODEL1234";
			myModel.itemType = "FOLDER";
			myModel.itemName = "My Model";
			itemList.push_back(myModel);
		}

		if (viewMode == 1)
		{
			//Test 1
			CLOAPISample::LibraryAPIItem myTest1;
			myTest1.itemID = "MY_TEST1";
			myTest1.itemType = "FOLDER";
			myTest1.itemName = "Material test1";
			itemList.push_back(myTest1);
		}*/

		QString jsonStr = generateJSONFromLibraryAPIItemList(itemList);		
		string str = jsonStr.toStdString();

		return str;
	}

	CLOAPISample::PLMSettingsSample* currentSettingsWidget = nullptr;

	bool LibraryWindowImplPlugin::IsPLMSettingsEnabled()
	{
#if USE_PLM_SETTINGS
		return true;
#else
		return false;
#endif
	}

	void* LibraryWindowImplPlugin::GetPLMSettingsWidget()
	{		
		//UTILITY_API->DisplayMessageBox("Step 3");
		if (currentSettingsWidget)
			ReleasePLMSettingsWidget();

		currentSettingsWidget = new CLOAPISample::PLMSettingsSample();
		return  static_cast<void*>(currentSettingsWidget);
	}

	void LibraryWindowImplPlugin::ReleasePLMSettingsWidget()
	{
		//UTILITY_API->DisplayMessageBox("Step 4");
		if (currentSettingsWidget)
		{
			delete currentSettingsWidget;
			currentSettingsWidget = nullptr;
		}
	}

	void LibraryWindowImplPlugin::SetNullptrPLMSettingsWidget()
	{
		currentSettingsWidget = nullptr;
	}
	
	void LibraryWindowImplPlugin::ResetPLMSettingsWidget()
	{
		//UTILITY_API->DisplayMessageBox("Step 5");
		if (currentSettingsWidget)
		{
			currentSettingsWidget->Reset();
			//currentSettingsWidget->update();
		}
	}

	/// plug-in related functions
	bool LibraryWindowImplPlugin::IsPluginEnabled()//!!!! Проверить в каких случаях запускается функция
	{
		//
		//QMessageBox::information(NULL, "IsPluginEnabled", "IsPluginEnabled");
		tempPoint = this;
		if (materials == 0)
		{
			myWindowMaterial = new Qt3();
			//myWindowMaterial->setParent(this); 

			myWindowColors = new Qt4();

			myWindowRender = new Qt5();

			materials = new myzfab;
			//Временное статичное занесение данных
			/*materials->add("Cotton_14_Wale_Corduroy");
			materials->add("Denim_Lightweight");
			materials->add("Denim_Raw");
			materials->add("Denim_Stretch");
			materials->add("Fur_Angora");
			materials->add("Fur_Fox");
			materials->add("Fur_Mink_Skin");
			materials->add("Fur_Rabbit");*/
		}
		//if (viewMode == 0)viewMode = new int;
#if USE_DOFUNCTION
		return true;
#else
		return false;
#endif
	}

	void LibraryWindowImplPlugin::DoFunction()
	{
		//UTILITY_API->DisplayMessageBox("Step 10");
#if USE_DOFUNCTION
		//UTILITY_API->DisplayMessageBox("Library windows sample plug-in 1212");
		//UTILITY_API->DisplayMessageBox("Step 1");
		//myWindow->vebview();
		//UTILITY_API->DisplayMessageBox("Step 2");
#endif
	}

	void LibraryWindowImplPlugin::DoFunctionStartUp()
	{
		//UTILITY_API->DisplayMessageBox("Step 11");
#if USE_STARTUP_DOFUNCTION
		UTILITY_API->DisplayMessageBox("Library windows sample startup plug-in");
#endif
	}

	void LibraryWindowImplPlugin::DoFunctionAfterLoadingCLOFile(const char* fileExtenstion)
	{
#if USE_AFTER_FILE_LOAD_DOFUNCTION
		UTILITY_API->DisplayMessageBox("Library windows sample plug-in after loading clo file");
#endif
	}

	const char* LibraryWindowImplPlugin::GetActionName()
	{
		//return "Library Windows Sample Plug-in";
		return "Material Library";
	}

	const char* LibraryWindowImplPlugin::GetObjectNameTreeToAddAction()
	{
		const char* objetNameTree = "menu_Setting / menuPlug_In";

		return objetNameTree;
	}

	int LibraryWindowImplPlugin::GetPositionIndexToAddAction()
	{
		return 1; // 0: Above, 1: below (default = 0)
	}

	string LibraryWindowImplPlugin::GetIconOnFilePathForTab()
	{
		string filePath = "";

#if USE_CUSTOM_TAB_ICON
		if (UTILITY_API != nullptr)
			//filePath = UTILITY_API->GetCLOExecutableFolderPath() + "library_tab_api_on.svg";	
			filePath = "C:/Users/Public/Documents/CLO/Assets/BeProduct/beproduct-sync-black.svg";
#endif

		return filePath;
	}

	string LibraryWindowImplPlugin::GetIconOffFilePathForTab()
	{
		string filePath = "";

#if USE_CUSTOM_TAB_ICON
		if (UTILITY_API != nullptr)
			//filePath = UTILITY_API->GetCLOExecutableFolderPath() + "library_tab_api_off.svg";
			filePath = "C:/Users/Public/Documents/CLO/Assets/BeProduct/beproduct-sync-black.svg";
#endif

		return filePath;
	}
}



