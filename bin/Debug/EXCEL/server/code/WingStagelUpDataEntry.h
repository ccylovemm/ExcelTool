// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     WingStagelUpDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _WINGSTAGELUPDATALOADER_H
#define _WINGSTAGELUPDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct WingStagelUpDataEntry
{
	WingStagelUpDataEntry() : id(0), rat(0), needmat1(0), num1(0), progress(0), needgold(0), PropID1(0), Value1(0), PropID2(0), Value2(0), PropID3(0), Value3(0), PropID4(0), Value4(0), PropID5(0), Value5(0), PropID6(0), Value6(0){}
	virtual ~WingStagelUpDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	翅膀进阶id
	**/
	UInt8	id;

	/**
	成功概率
	**/
	UInt16	rat;

	/**
	需要材料ID
	**/
	UInt32	needmat1;

	/**
	需要材料的数量
	**/
	UInt16	num1;

	/**
	进度总量
	**/
	UInt8	progress;

	/**
	需要的银币
	**/
	UInt16	needgold;

	/**
	属性1
	**/
	UInt32	PropID1;

	/**
	属性值1
	**/
	UInt32	Value1;

	/**
	属性2
	**/
	UInt32	PropID2;

	/**
	属性值2
	**/
	UInt32	Value2;

	/**
	属性3
	**/
	UInt32	PropID3;

	/**
	属性值3
	**/
	UInt32	Value3;

	/**
	属性4
	**/
	UInt32	PropID4;

	/**
	属性值4
	**/
	UInt32	Value4;

	/**
	属性5
	**/
	UInt32	PropID5;

	/**
	属性值5
	**/
	UInt32	Value5;

	/**
	属性6
	**/
	UInt32	PropID6;

	/**
	属性值6
	**/
	UInt32	Value6;
}; // WingStagelUpDataEntry define end

//data visitor for the excel table
template <typename T>
class WingStagelUpDataEntryVisitor
{
public:
	WingStagelUpDataEntryVisitor(){ static_assert(std::is_base_of<WingStagelUpDataEntry, T>::value != 0, "T must be inherited from WingStagelUpDataEntry"); }
	virtual ~WingStagelUpDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class WingStagelUpDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	WingStagelUpDataLoader(){ static_assert(std::is_base_of<WingStagelUpDataEntry, T>::value != 0, "T must be inherited from WingStagelUpDataEntry"); }
	~WingStagelUpDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "id", pData->id);
			doc.GetAttribute(pDataElem, "rat", pData->rat);
			doc.GetAttribute(pDataElem, "needmat1", pData->needmat1);
			doc.GetAttribute(pDataElem, "num1", pData->num1);
			doc.GetAttribute(pDataElem, "progress", pData->progress);
			doc.GetAttribute(pDataElem, "needgold", pData->needgold);
			doc.GetAttribute(pDataElem, "PropID1", pData->PropID1);
			doc.GetAttribute(pDataElem, "Value1", pData->Value1);
			doc.GetAttribute(pDataElem, "PropID2", pData->PropID2);
			doc.GetAttribute(pDataElem, "Value2", pData->Value2);
			doc.GetAttribute(pDataElem, "PropID3", pData->PropID3);
			doc.GetAttribute(pDataElem, "Value3", pData->Value3);
			doc.GetAttribute(pDataElem, "PropID4", pData->PropID4);
			doc.GetAttribute(pDataElem, "Value4", pData->Value4);
			doc.GetAttribute(pDataElem, "PropID5", pData->PropID5);
			doc.GetAttribute(pDataElem, "Value5", pData->Value5);
			doc.GetAttribute(pDataElem, "PropID6", pData->PropID6);
			doc.GetAttribute(pDataElem, "Value6", pData->Value6);
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

	void VisitData(WingStagelUpDataEntryVisitor<T>& visitor)
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

