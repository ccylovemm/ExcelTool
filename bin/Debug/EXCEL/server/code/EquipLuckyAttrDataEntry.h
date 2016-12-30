// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     EquipLuckyAttrDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _EQUIPLUCKYATTRDATALOADER_H
#define _EQUIPLUCKYATTRDATALOADER_H

#include <string>
#include <vector>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct EquipLuckyAttrDataEntry
{
	EquipLuckyAttrDataEntry() : EquipLevel(0), Model(0), Occu(0), minPropID_7(0), minPropID_8(0), minPropID_9(0), minPropID_10(0), minPropID_11(0), minPropID_12(0), minPropID_13(0), minPropID_14(0), minPropID_15(0), minPropID_16(0), maxPropID_7(0), maxPropID_8(0), maxPropID_9(0), maxPropID_10(0), maxPropID_11(0), maxPropID_12(0), maxPropID_13(0), maxPropID_14(0), maxPropID_15(0), maxPropID_16(0){}
	virtual ~EquipLuckyAttrDataEntry(){ }
	virtual UInt32 GetKey() const { return 0xFFFFFFFF; };
	/**
	等级
	**/
	UInt32	EquipLevel;

	/**
	颜色
	**/
	UInt8	Model;

	/**
	职业
	**/
	UInt8	Occu;

	/**
	物理攻击
	**/
	UInt32	minPropID_7;

	/**
	法术攻击
	**/
	UInt32	minPropID_8;

	/**
	物理防御
	**/
	UInt32	minPropID_9;

	/**
	法术防御
	**/
	UInt32	minPropID_10;

	/**
	最大生命
	**/
	UInt32	minPropID_11;

	/**
	命中
	**/
	UInt32	minPropID_12;

	/**
	闪避
	**/
	UInt32	minPropID_13;

	/**
	暴击
	**/
	UInt32	minPropID_14;

	/**
	抗暴
	**/
	UInt32	minPropID_15;

	/**
	破防
	**/
	UInt32	minPropID_16;

	/**
	物理攻击
	**/
	UInt32	maxPropID_7;

	/**
	法术攻击
	**/
	UInt32	maxPropID_8;

	/**
	物理防御
	**/
	UInt32	maxPropID_9;

	/**
	法术防御
	**/
	UInt32	maxPropID_10;

	/**
	最大生命
	**/
	UInt32	maxPropID_11;

	/**
	命中
	**/
	UInt32	maxPropID_12;

	/**
	闪避
	**/
	UInt32	maxPropID_13;

	/**
	暴击
	**/
	UInt32	maxPropID_14;

	/**
	抗暴
	**/
	UInt32	maxPropID_15;

	/**
	破防
	**/
	UInt32	maxPropID_16;

	/**
	隐藏属性ID
	**/
	string	SpecialPropID;

	/**
	概率
	**/
	string	SpecialPropChance;

	/**
	隐藏属性参数
	**/
	string	SpecialProp;
}; // EquipLuckyAttrDataEntry define end

//data visitor for the excel table
template <typename T>
class EquipLuckyAttrDataEntryVisitor
{
public:
	EquipLuckyAttrDataEntryVisitor(){ static_assert(std::is_base_of<EquipLuckyAttrDataEntry, T>::value != 0, "T must be inherited from EquipLuckyAttrDataEntry"); }
	virtual ~EquipLuckyAttrDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class EquipLuckyAttrDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	EquipLuckyAttrDataLoader(){ static_assert(std::is_base_of<EquipLuckyAttrDataEntry, T>::value != 0, "T must be inherited from EquipLuckyAttrDataEntry"); }
	~EquipLuckyAttrDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "EquipLevel", pData->EquipLevel);
			doc.GetAttribute(pDataElem, "Model", pData->Model);
			doc.GetAttribute(pDataElem, "Occu", pData->Occu);
			doc.GetAttribute(pDataElem, "minPropID_7", pData->minPropID_7);
			doc.GetAttribute(pDataElem, "minPropID_8", pData->minPropID_8);
			doc.GetAttribute(pDataElem, "minPropID_9", pData->minPropID_9);
			doc.GetAttribute(pDataElem, "minPropID_10", pData->minPropID_10);
			doc.GetAttribute(pDataElem, "minPropID_11", pData->minPropID_11);
			doc.GetAttribute(pDataElem, "minPropID_12", pData->minPropID_12);
			doc.GetAttribute(pDataElem, "minPropID_13", pData->minPropID_13);
			doc.GetAttribute(pDataElem, "minPropID_14", pData->minPropID_14);
			doc.GetAttribute(pDataElem, "minPropID_15", pData->minPropID_15);
			doc.GetAttribute(pDataElem, "minPropID_16", pData->minPropID_16);
			doc.GetAttribute(pDataElem, "maxPropID_7", pData->maxPropID_7);
			doc.GetAttribute(pDataElem, "maxPropID_8", pData->maxPropID_8);
			doc.GetAttribute(pDataElem, "maxPropID_9", pData->maxPropID_9);
			doc.GetAttribute(pDataElem, "maxPropID_10", pData->maxPropID_10);
			doc.GetAttribute(pDataElem, "maxPropID_11", pData->maxPropID_11);
			doc.GetAttribute(pDataElem, "maxPropID_12", pData->maxPropID_12);
			doc.GetAttribute(pDataElem, "maxPropID_13", pData->maxPropID_13);
			doc.GetAttribute(pDataElem, "maxPropID_14", pData->maxPropID_14);
			doc.GetAttribute(pDataElem, "maxPropID_15", pData->maxPropID_15);
			doc.GetAttribute(pDataElem, "maxPropID_16", pData->maxPropID_16);
			doc.GetAttribute(pDataElem, "SpecialPropID", pData->SpecialPropID);
			doc.GetAttribute(pDataElem, "SpecialPropChance", pData->SpecialPropChance);
			doc.GetAttribute(pDataElem, "SpecialProp", pData->SpecialProp);
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

	void VisitData(EquipLuckyAttrDataEntryVisitor<T>& visitor)
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

