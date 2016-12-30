// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     MirRandomDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _MIRRANDOMDATALOADER_H
#define _MIRRANDOMDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct MirRandomDataEntry
{
	MirRandomDataEntry() : proid(0), value(0), index(0), phy_weapon1(0), phy_weapon2(0), phy_weapon3(0), mag_weapon1(0), mag_weapon2(0), mag_weapon3(0), against1(0), against2(0), against3(0), ring1(0), ring2(0), ring3(0), necklace1(0), necklace2(0), necklace3(0){}
	virtual ~MirRandomDataEntry(){ }
	virtual UInt32 GetKey() const { return proid; }
	/**
	属性ID
	**/
	UInt16	proid;

	/**
	属性名称
	**/
	string	name;

	/**
	属性的值
	**/
	UInt16	value;

	/**
	排序
	**/
	UInt16	index;

	/**
	物理武器1
	**/
	UInt16	phy_weapon1;

	/**
	物理武器2
	**/
	UInt16	phy_weapon2;

	/**
	物理武器3
	**/
	UInt16	phy_weapon3;

	/**
	魔法武器1
	**/
	UInt16	mag_weapon1;

	/**
	魔法武器2
	**/
	UInt16	mag_weapon2;

	/**
	魔法武器3
	**/
	UInt16	mag_weapon3;

	/**
	防具1
	**/
	UInt16	against1;

	/**
	防具2
	**/
	UInt16	against2;

	/**
	防具3
	**/
	UInt16	against3;

	/**
	戒指1
	**/
	UInt16	ring1;

	/**
	戒指2
	**/
	UInt16	ring2;

	/**
	戒指3
	**/
	UInt16	ring3;

	/**
	项链1
	**/
	UInt16	necklace1;

	/**
	项链2
	**/
	UInt16	necklace2;

	/**
	项链2
	**/
	UInt16	necklace3;
}; // MirRandomDataEntry define end

//data visitor for the excel table
template <typename T>
class MirRandomDataEntryVisitor
{
public:
	MirRandomDataEntryVisitor(){ static_assert(std::is_base_of<MirRandomDataEntry, T>::value != 0, "T must be inherited from MirRandomDataEntry"); }
	virtual ~MirRandomDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class MirRandomDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	MirRandomDataLoader(){ static_assert(std::is_base_of<MirRandomDataEntry, T>::value != 0, "T must be inherited from MirRandomDataEntry"); }
	~MirRandomDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "proid", pData->proid);
			doc.GetAttribute(pDataElem, "name", pData->name);
			doc.GetAttribute(pDataElem, "value", pData->value);
			doc.GetAttribute(pDataElem, "index", pData->index);
			doc.GetAttribute(pDataElem, "phy_weapon1", pData->phy_weapon1);
			doc.GetAttribute(pDataElem, "phy_weapon2", pData->phy_weapon2);
			doc.GetAttribute(pDataElem, "phy_weapon3", pData->phy_weapon3);
			doc.GetAttribute(pDataElem, "mag_weapon1", pData->mag_weapon1);
			doc.GetAttribute(pDataElem, "mag_weapon2", pData->mag_weapon2);
			doc.GetAttribute(pDataElem, "mag_weapon3", pData->mag_weapon3);
			doc.GetAttribute(pDataElem, "against1", pData->against1);
			doc.GetAttribute(pDataElem, "against2", pData->against2);
			doc.GetAttribute(pDataElem, "against3", pData->against3);
			doc.GetAttribute(pDataElem, "ring1", pData->ring1);
			doc.GetAttribute(pDataElem, "ring2", pData->ring2);
			doc.GetAttribute(pDataElem, "ring3", pData->ring3);
			doc.GetAttribute(pDataElem, "necklace1", pData->necklace1);
			doc.GetAttribute(pDataElem, "necklace2", pData->necklace2);
			doc.GetAttribute(pDataElem, "necklace3", pData->necklace3);
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

	void VisitData(MirRandomDataEntryVisitor<T>& visitor)
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

