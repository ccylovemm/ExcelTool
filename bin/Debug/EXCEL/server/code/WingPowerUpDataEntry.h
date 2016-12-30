// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     WingPowerUpDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _WINGPOWERUPDATALOADER_H
#define _WINGPOWERUPDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct WingPowerUpDataEntry
{
	WingPowerUpDataEntry() : id(0), rat(0), PropID1(0), Value1(0), PropID2(0), Value2(0), PropID3(0), Value3(0), PropID4(0), Value4(0), PropID5(0), Value5(0), PropID6(0), Value6(0), PropID7(0), Value7(0), needmat1(0), num1(0), needgold(0){}
	virtual ~WingPowerUpDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	翅膀强化id
	**/
	UInt16	id;

	/**
	成功概率
	**/
	UInt16	rat;

	/**
	属性
	**/
	UInt32	PropID1;

	/**
	属性值
	**/
	UInt32	Value1;

	/**
	属性
	**/
	UInt32	PropID2;

	/**
	属性值
	**/
	UInt32	Value2;

	/**
	属性
	**/
	UInt32	PropID3;

	/**
	属性值
	**/
	UInt32	Value3;

	/**
	属性
	**/
	UInt32	PropID4;

	/**
	属性值
	**/
	UInt32	Value4;

	/**
	属性
	**/
	UInt32	PropID5;

	/**
	属性值
	**/
	UInt32	Value5;

	/**
	属性
	**/
	UInt32	PropID6;

	/**
	属性值
	**/
	UInt32	Value6;

	/**
	属性
	**/
	UInt32	PropID7;

	/**
	属性值
	**/
	UInt32	Value7;

	/**
	需要材料ID
	**/
	UInt32	needmat1;

	/**
	需要材料的数量
	**/
	UInt16	num1;

	/**
	需要的银币
	**/
	UInt16	needgold;
}; // WingPowerUpDataEntry define end

//data visitor for the excel table
template <typename T>
class WingPowerUpDataEntryVisitor
{
public:
	WingPowerUpDataEntryVisitor(){ static_assert(std::is_base_of<WingPowerUpDataEntry, T>::value != 0, "T must be inherited from WingPowerUpDataEntry"); }
	virtual ~WingPowerUpDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class WingPowerUpDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	WingPowerUpDataLoader(){ static_assert(std::is_base_of<WingPowerUpDataEntry, T>::value != 0, "T must be inherited from WingPowerUpDataEntry"); }
	~WingPowerUpDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "PropID7", pData->PropID7);
			doc.GetAttribute(pDataElem, "Value7", pData->Value7);
			doc.GetAttribute(pDataElem, "needmat1", pData->needmat1);
			doc.GetAttribute(pDataElem, "num1", pData->num1);
			doc.GetAttribute(pDataElem, "needgold", pData->needgold);
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

	void VisitData(WingPowerUpDataEntryVisitor<T>& visitor)
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

