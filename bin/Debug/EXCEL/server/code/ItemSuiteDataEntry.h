// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     ItemSuiteDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _ITEMSUITEDATALOADER_H
#define _ITEMSUITEDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct ItemSuiteDataEntry
{
	ItemSuiteDataEntry() : SuiteID(0), SuiteStage(0), num(0), SuitNum1(0), PropID1(0), Value1(0), SuitNum2(0), PropID2(0), Value2(0), SuitNum3(0), PropID3(0), Value3(0), SuitNum4(0), PropID4(0), Value4(0), SuitNum5(0), PropID5(0), Value5(0), SuitNum6(0), PropID6(0), Value6(0), SuitNum7(0), PropID7(0), Value7(0), SuitNum8(0), PropID8(0), Value8(0), SuitNum9(0), PropID9(0), Value9(0), SuitNum10(0), PropID10(0), Value10(0){}
	virtual ~ItemSuiteDataEntry(){ }
	virtual UInt32 GetKey() const { return SuiteID; }
	/**
	套装ID
	**/
	UInt16	SuiteID;

	/**
	套装名
	**/
	string	SuiteName;

	/**
	套装阶段
	**/
	UInt8	SuiteStage;

	/**
	套装件数
	**/
	UInt8	num;

	/**
	需要ID,数量
	**/
	string	need1;

	/**
	需要ID,数量
	**/
	string	need2;

	/**
	需要ID,数量
	**/
	string	need3;

	/**
	需要ID,数量
	**/
	string	need4;

	/**
	需要ID,数量
	**/
	string	need5;

	/**
	套装条件1
	**/
	UInt8	SuitNum1;

	/**
	属性1
	**/
	UInt8	PropID1;

	/**
	值1
	**/
	UInt16	Value1;

	/**
	套装条件2
	**/
	UInt8	SuitNum2;

	/**
	属性2
	**/
	UInt8	PropID2;

	/**
	值2
	**/
	UInt16	Value2;

	/**
	套装条件3
	**/
	UInt8	SuitNum3;

	/**
	属性3
	**/
	UInt8	PropID3;

	/**
	值3
	**/
	UInt16	Value3;

	/**
	套装条件4
	**/
	UInt8	SuitNum4;

	/**
	属性4
	**/
	UInt8	PropID4;

	/**
	值4
	**/
	UInt16	Value4;

	/**
	套装条件5
	**/
	UInt8	SuitNum5;

	/**
	属性5
	**/
	UInt8	PropID5;

	/**
	值5
	**/
	UInt16	Value5;

	/**
	套装条件6
	**/
	UInt8	SuitNum6;

	/**
	属性6
	**/
	UInt8	PropID6;

	/**
	值6
	**/
	UInt16	Value6;

	/**
	套装条件7
	**/
	UInt8	SuitNum7;

	/**
	属性7
	**/
	UInt8	PropID7;

	/**
	值7
	**/
	UInt16	Value7;

	/**
	套装条件8
	**/
	UInt8	SuitNum8;

	/**
	属性8
	**/
	UInt8	PropID8;

	/**
	值8
	**/
	UInt16	Value8;

	/**
	套装条件9
	**/
	UInt8	SuitNum9;

	/**
	属性9
	**/
	UInt8	PropID9;

	/**
	值9
	**/
	UInt16	Value9;

	/**
	套装条件10
	**/
	UInt8	SuitNum10;

	/**
	属性10
	**/
	UInt8	PropID10;

	/**
	值10
	**/
	UInt16	Value10;
}; // ItemSuiteDataEntry define end

//data visitor for the excel table
template <typename T>
class ItemSuiteDataEntryVisitor
{
public:
	ItemSuiteDataEntryVisitor(){ static_assert(std::is_base_of<ItemSuiteDataEntry, T>::value != 0, "T must be inherited from ItemSuiteDataEntry"); }
	virtual ~ItemSuiteDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class ItemSuiteDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	ItemSuiteDataLoader(){ static_assert(std::is_base_of<ItemSuiteDataEntry, T>::value != 0, "T must be inherited from ItemSuiteDataEntry"); }
	~ItemSuiteDataLoader(){ ClearData(); }

	virtual bool ParseData(T* pT)
	{
		return true;
	}

	virtual bool AfterLoad()
	{
		return true;
	}

	bool LoadData(const std::string& strPath)
	{
		ClearData();
		Avalon::XmlDocument doc(strPath);
		if(!doc.LoadFile()) return false;
		Avalon::XmlElement* pElemRoot = doc.RootElement();
		if(pElemRoot == NULL)
		{
			return false;
		}
		TiXmlElement* pDataElem = doc.FirstChildElement(pElemRoot, "Row");
		UInt32 autoIncKey = 0;
		while(pDataElem != NULL)
		{
			T* pData = new T;
			doc.GetAttribute(pDataElem, "SuiteID", pData->SuiteID);
			doc.GetAttribute(pDataElem, "SuiteName", pData->SuiteName);
			doc.GetAttribute(pDataElem, "SuiteStage", pData->SuiteStage);
			doc.GetAttribute(pDataElem, "num", pData->num);
			doc.GetAttribute(pDataElem, "need1", pData->need1);
			doc.GetAttribute(pDataElem, "need2", pData->need2);
			doc.GetAttribute(pDataElem, "need3", pData->need3);
			doc.GetAttribute(pDataElem, "need4", pData->need4);
			doc.GetAttribute(pDataElem, "need5", pData->need5);
			doc.GetAttribute(pDataElem, "SuitNum1", pData->SuitNum1);
			doc.GetAttribute(pDataElem, "PropID1", pData->PropID1);
			doc.GetAttribute(pDataElem, "Value1", pData->Value1);
			doc.GetAttribute(pDataElem, "SuitNum2", pData->SuitNum2);
			doc.GetAttribute(pDataElem, "PropID2", pData->PropID2);
			doc.GetAttribute(pDataElem, "Value2", pData->Value2);
			doc.GetAttribute(pDataElem, "SuitNum3", pData->SuitNum3);
			doc.GetAttribute(pDataElem, "PropID3", pData->PropID3);
			doc.GetAttribute(pDataElem, "Value3", pData->Value3);
			doc.GetAttribute(pDataElem, "SuitNum4", pData->SuitNum4);
			doc.GetAttribute(pDataElem, "PropID4", pData->PropID4);
			doc.GetAttribute(pDataElem, "Value4", pData->Value4);
			doc.GetAttribute(pDataElem, "SuitNum5", pData->SuitNum5);
			doc.GetAttribute(pDataElem, "PropID5", pData->PropID5);
			doc.GetAttribute(pDataElem, "Value5", pData->Value5);
			doc.GetAttribute(pDataElem, "SuitNum6", pData->SuitNum6);
			doc.GetAttribute(pDataElem, "PropID6", pData->PropID6);
			doc.GetAttribute(pDataElem, "Value6", pData->Value6);
			doc.GetAttribute(pDataElem, "SuitNum7", pData->SuitNum7);
			doc.GetAttribute(pDataElem, "PropID7", pData->PropID7);
			doc.GetAttribute(pDataElem, "Value7", pData->Value7);
			doc.GetAttribute(pDataElem, "SuitNum8", pData->SuitNum8);
			doc.GetAttribute(pDataElem, "PropID8", pData->PropID8);
			doc.GetAttribute(pDataElem, "Value8", pData->Value8);
			doc.GetAttribute(pDataElem, "SuitNum9", pData->SuitNum9);
			doc.GetAttribute(pDataElem, "PropID9", pData->PropID9);
			doc.GetAttribute(pDataElem, "Value9", pData->Value9);
			doc.GetAttribute(pDataElem, "SuitNum10", pData->SuitNum10);
			doc.GetAttribute(pDataElem, "PropID10", pData->PropID10);
			doc.GetAttribute(pDataElem, "Value10", pData->Value10);
			if(!ParseData(pData)) return false;
			if(pData->GetKey() != 0xFFFFFFFF)
			{
				if(!_mapData.insert(std::make_pair(pData->GetKey(), pData)).second)
				{
					delete pData;
					ClearData();
					return false;
				}
			}
			else
			{
				if(!_mapData.insert(std::make_pair(++autoIncKey, pData)).second)
					delete pData;
			}
			pDataElem = doc.NextElement(pDataElem);
		}
		return AfterLoad();
	}

	void VisitData(ItemSuiteDataEntryVisitor<T>& visitor)
	{
		for(auto itr = _mapData.begin(); itr != _mapData.end(); ++itr)
		{
			if(!visitor(itr->second))
				return;
		}
	}

	T* FindEntry(UInt32 key)
	{
		auto itr = _mapData.find(key);
		if(itr != _mapData.end())
			return itr->second;
		return NULL;
	}

	void ClearData()
	{
		for(auto itr = _mapData.begin(); itr != _mapData.end();++itr)
		{
			const T *p = itr->second;
			delete p;
		}
		_mapData.clear();
	}
};

#endif

