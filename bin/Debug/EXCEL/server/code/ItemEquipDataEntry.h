// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     ItemEquipDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _ITEMEQUIPDATALOADER_H
#define _ITEMEQUIPDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct ItemEquipDataEntry
{
	ItemEquipDataEntry() : ItemID(0), Class(0), Needlevel(0), vlevel(0), AdvanceID(0), PowerUp_Max(0), Extar_Prop_Max(0), PropID_7(0), PropID_8(0), PropID_9(0), PropID_10(0), PropID_11(0), MaxPropID_12(0), MaxPropID_13(0), MaxPropID_14(0), MaxPropID_15(0), MaxPropID_16(0), MaxPropID_17(0), MaxPropID_18(0), PropID_12(0), PropID_13(0), PropID_14(0), PropID_15(0), PropID_16(0), PropID_17(0), PropID_18(0), Decompose(0){}
	virtual ~ItemEquipDataEntry(){ }
	virtual UInt32 GetKey() const { return ItemID; }
	/**
	道具ID
	**/
	UInt32	ItemID;

	/**
	道具名称
	**/
	string	Name;

	/**
	道具职业限制
	**/
	UInt8	Class;

	/**
	装备使用等级
	**/
	UInt16	Needlevel;

	/**
	装备阶数
	**/
	UInt16	vlevel;

	/**
	进阶装备ID
	**/
	UInt32	AdvanceID;

	/**
	道具强化上限
	**/
	UInt8	PowerUp_Max;

	/**
	道具追加上限
	**/
	UInt8	Extar_Prop_Max;

	/**
	属性
	**/
	UInt32	PropID_7;

	/**
	属性
	**/
	UInt32	PropID_8;

	/**
	属性
	**/
	UInt32	PropID_9;

	/**
	属性
	**/
	UInt32	PropID_10;

	/**
	属性
	**/
	UInt32	PropID_11;

	/**
	属性
	**/
	UInt32	MaxPropID_12;

	/**
	属性
	**/
	UInt32	MaxPropID_13;

	/**
	属性
	**/
	UInt32	MaxPropID_14;

	/**
	属性
	**/
	UInt32	MaxPropID_15;

	/**
	属性
	**/
	UInt32	MaxPropID_16;

	/**
	属性
	**/
	UInt32	MaxPropID_17;

	/**
	属性
	**/
	UInt32	MaxPropID_18;

	/**
	属性
	**/
	UInt32	PropID_12;

	/**
	属性
	**/
	UInt32	PropID_13;

	/**
	属性
	**/
	UInt32	PropID_14;

	/**
	属性
	**/
	UInt32	PropID_15;

	/**
	属性
	**/
	UInt32	PropID_16;

	/**
	属性
	**/
	UInt32	PropID_17;

	/**
	属性
	**/
	UInt32	PropID_18;

	/**
	分解玄晶数量
	**/
	UInt32	Decompose;
}; // ItemEquipDataEntry define end

//data visitor for the excel table
template <typename T>
class ItemEquipDataEntryVisitor
{
public:
	ItemEquipDataEntryVisitor(){ static_assert(std::is_base_of<ItemEquipDataEntry, T>::value != 0, "T must be inherited from ItemEquipDataEntry"); }
	virtual ~ItemEquipDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class ItemEquipDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	ItemEquipDataLoader(){ static_assert(std::is_base_of<ItemEquipDataEntry, T>::value != 0, "T must be inherited from ItemEquipDataEntry"); }
	~ItemEquipDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "ItemID", pData->ItemID);
			doc.GetAttribute(pDataElem, "Name", pData->Name);
			doc.GetAttribute(pDataElem, "Class", pData->Class);
			doc.GetAttribute(pDataElem, "Needlevel", pData->Needlevel);
			doc.GetAttribute(pDataElem, "vlevel", pData->vlevel);
			doc.GetAttribute(pDataElem, "AdvanceID", pData->AdvanceID);
			doc.GetAttribute(pDataElem, "PowerUp_Max", pData->PowerUp_Max);
			doc.GetAttribute(pDataElem, "Extar_Prop_Max", pData->Extar_Prop_Max);
			doc.GetAttribute(pDataElem, "PropID_7", pData->PropID_7);
			doc.GetAttribute(pDataElem, "PropID_8", pData->PropID_8);
			doc.GetAttribute(pDataElem, "PropID_9", pData->PropID_9);
			doc.GetAttribute(pDataElem, "PropID_10", pData->PropID_10);
			doc.GetAttribute(pDataElem, "PropID_11", pData->PropID_11);
			doc.GetAttribute(pDataElem, "MaxPropID_12", pData->MaxPropID_12);
			doc.GetAttribute(pDataElem, "MaxPropID_13", pData->MaxPropID_13);
			doc.GetAttribute(pDataElem, "MaxPropID_14", pData->MaxPropID_14);
			doc.GetAttribute(pDataElem, "MaxPropID_15", pData->MaxPropID_15);
			doc.GetAttribute(pDataElem, "MaxPropID_16", pData->MaxPropID_16);
			doc.GetAttribute(pDataElem, "MaxPropID_17", pData->MaxPropID_17);
			doc.GetAttribute(pDataElem, "MaxPropID_18", pData->MaxPropID_18);
			doc.GetAttribute(pDataElem, "PropID_12", pData->PropID_12);
			doc.GetAttribute(pDataElem, "PropID_13", pData->PropID_13);
			doc.GetAttribute(pDataElem, "PropID_14", pData->PropID_14);
			doc.GetAttribute(pDataElem, "PropID_15", pData->PropID_15);
			doc.GetAttribute(pDataElem, "PropID_16", pData->PropID_16);
			doc.GetAttribute(pDataElem, "PropID_17", pData->PropID_17);
			doc.GetAttribute(pDataElem, "PropID_18", pData->PropID_18);
			doc.GetAttribute(pDataElem, "Decompose", pData->Decompose);
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

	void VisitData(ItemEquipDataEntryVisitor<T>& visitor)
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

