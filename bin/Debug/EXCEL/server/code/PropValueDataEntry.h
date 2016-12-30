// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     PropValueDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _PROPVALUEDATALOADER_H
#define _PROPVALUEDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct PropValueDataEntry
{
	PropValueDataEntry() : PropID(0), PropType(0), PropParam(0), Value1(0), Value2(0), EquipValue(0){}
	virtual ~PropValueDataEntry(){ }
	virtual UInt32 GetKey() const { return PropID; }
	/**
	属性ID
	**/
	UInt16	PropID;

	/**
	属性的类型
	**/
	UInt8	PropType;

	/**
	属性的参数
	**/
	UInt8	PropParam;

	/**
	物理职业战斗力
	**/
	UInt32	Value1;

	/**
	法术职业战斗力
	**/
	UInt32	Value2;

	/**
	装备评分
	**/
	UInt32	EquipValue;
}; // PropValueDataEntry define end

//data visitor for the excel table
template <typename T>
class PropValueDataEntryVisitor
{
public:
	PropValueDataEntryVisitor(){ static_assert(std::is_base_of<PropValueDataEntry, T>::value != 0, "T must be inherited from PropValueDataEntry"); }
	virtual ~PropValueDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class PropValueDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	PropValueDataLoader(){ static_assert(std::is_base_of<PropValueDataEntry, T>::value != 0, "T must be inherited from PropValueDataEntry"); }
	~PropValueDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "PropID", pData->PropID);
			doc.GetAttribute(pDataElem, "PropType", pData->PropType);
			doc.GetAttribute(pDataElem, "PropParam", pData->PropParam);
			doc.GetAttribute(pDataElem, "Value1", pData->Value1);
			doc.GetAttribute(pDataElem, "Value2", pData->Value2);
			doc.GetAttribute(pDataElem, "EquipValue", pData->EquipValue);
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

	void VisitData(PropValueDataEntryVisitor<T>& visitor)
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

